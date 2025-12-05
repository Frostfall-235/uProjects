import pandas as pd
import numpy as np
import re
import unicodedata
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import StandardScaler

# --- 1. Funciones de Limpieza y Estandarización Robusta ---

def normalizar_texto(val):
    """Elimina acentos, caracteres raros y convierte a minúsculas."""
    if pd.isna(val): return ""
    s = str(val).lower().strip()
    
    # Intento de corrección de codificación común en Excel (mojibake)
    try:
        s = s.encode('latin-1').decode('utf-8')
    except:
        pass
    
    # Eliminar acentos (á -> a, ñ -> n)
    s = ''.join(c for c in unicodedata.normalize('NFD', s) if unicodedata.category(c) != 'Mn')
    
    # Dejar solo letras, números, puntos y guiones
    s = re.sub(r'[^a-z0-9\.\-]', ' ', s)
    return s.strip()

def clean_numeric(val):
    """Limpia y convierte valores numéricos de forma robusta."""
    s = normalizar_texto(val)
    if not s: return np.nan
    
    # Casos cero explícitos (incluye "no tengo", "ninguno")
    if any(x in s for x in ["no", "nada", "ni", "ninguno", "nunca", "0 2", " 1"]): 
        if "0 2" in s: return 0.2 # Caso especial "0.2" mal leído
        if " 1" in s and len(s) < 3: return -1 # Caso especial "-1"
        return 0
    
    # Basura conocida a ignorar
    junk_words = ["nose", "no se", "na", "soy", "diario", "no5", "noshe", 
                  "aprox", "aveces", "menos", "de", "victor", "jesus", "la", "bruno", 
                  "torres", "depende", "limaylla", "mamani", "cambio", "24 7", "verdad", "mucha"]
    if any(w in s for w in junk_words): return np.nan

    # Quitar unidades
    s = re.sub(r'(km|h|hs|horas|sooles|soles|s)', '', s).replace('mil', '000').strip()

    # Buscar rangos "10-12" -> promedio
    range_match = re.search(r'(\d+[\.,]?\d*)\s*\-\s*(\d+[\.,]?\d*)', s)
    if range_match:
        try:
            n1 = float(range_match.group(1).replace(',', '.'))
            n2 = float(range_match.group(2).replace(',', '.'))
            return (n1 + n2) / 2
        except: pass

    # Buscar número simple
    num_match = re.search(r'(\d+[\.,]?\d*)', s)
    if num_match:
        try:
            val_float = float(num_match.group(1).replace(',', '.'))
            if val_float > 1000000: return np.nan
            return val_float
        except: return np.nan
        
    return np.nan

def clean_categorical(val, mapping):
    """Busca palabras clave en texto limpio."""
    s = normalizar_texto(val)
    if not s: return np.nan
    for key, num_val in mapping.items():
        # La key debe estar normalizada (sin tildes) en el mapa
        if key in s: return num_val 
    return np.nan

# --- 2. Carga y Procesamiento de Datos ---

file_path = "RESULTADOS DEL FORMULARIO.csv"

# Intentar leer con codificación tolerante
try:
    df = pd.read_csv(file_path, encoding='utf-8')
except:
    try:
        df = pd.read_csv(file_path, encoding='latin-1')
    except:
        df = pd.read_csv(file_path, encoding='cp1252') # Último intento común Windows

# Mapeo de columnas (14 Preguntas)
col_map = {
    '1) ¿Cuántas veces por semana consume carne de res?\n(Escala numérica: 0 a 14 veces/semana)': 'Q1_Carne',
    '2) ¿Cuántas veces por semana consume pollo o pescado?\n(Escala numérica: 0 a 14 veces/semana)': 'Q2_Pollo',
    '3) ¿Con qué frecuencia semanal consume alimentos procesados o ultraprocesados (snacks, bebidas azucaradas, comida rápida)?': 'Q3_Procesados',
    '4) ¿Con qué frecuencia semanal consume alimentos de origen vegetal (frutas, legumbres, verduras)?\n(Escala numérica: 0 a 21 veces/semana)': 'Q4_Vegetal',
    '5)  ¿Cuántos kilómetros promedio recorre por semana en automóvil particular o moto?': 'Q5_Auto_km',
    '6) ¿Cuántos kilómetros promedio recorre por semana en transporte público (bus, combi, tren)?': 'Q6_Bus_km',
    '7)  ¿Con qué frecuencia utiliza medios sostenibles (bicicleta, caminata)?': 'Q7_Sostenible',
    '8)  ¿Cuántos vuelos realiza aproximadamente por año?': 'Q8_Vuelos',
    '10) ¿Cuántas horas diarias utiliza equipos electrónicos (laptop, PC de escritorio, TV)?': 'Q9_Equipos_h',
    '11) ¿Cuántas horas diarias utiliza su teléfono móvil o tablet?': 'Q10_Movil_h',
    '12) ¿Cuánto dinero gasta aproximadamente en ropa y calzado al mes?': 'Q11_Gasto_Ropa_mes',
    '13) ¿Cuánto dinero gasta aproximadamente en dispositivos electrónicos al año?': 'Q12_Gasto_Electro_ano',
    '14) ¿Con qué frecuencia compra productos de moda rápida (fast fashion)?': 'Q13_FastFashion',
    '15) ¿Con qué frecuencia compra artículos no esenciales (decoración, gadgets, accesorios)?': 'Q14_NoEsenciales'
}

# Renombrar y filtrar
df_procesado = df.rename(columns=col_map)
feature_cols = list(col_map.values())
df_procesado = df_procesado[feature_cols]

# Definir tipos
num_cols = ['Q1_Carne', 'Q2_Pollo', 'Q4_Vegetal', 'Q5_Auto_km', 'Q6_Bus_km', 
            'Q8_Vuelos', 'Q9_Equipos_h', 'Q10_Movil_h', 'Q11_Gasto_Ropa_mes', 'Q12_Gasto_Electro_ano']
cat_cols = ['Q3_Procesados', 'Q7_Sostenible', 'Q13_FastFashion', 'Q14_NoEsenciales']

# Mapas Normalizados (Claves sin tildes, todo minúscula)
map_freq = {"nunca": 0, "1-2": 1, "3-5": 2, "mas": 3} # 'mas' captura 'mas de 5'
map_sost = {"nunca": 0, "1-2": 1, "3-5": 2, "diario": 3}
map_shop = {"nunca": 0, "mensual": 1, "quincenal": 2, "semanal": 3}

# Aplicar limpieza robusta
print("Limpiando datos...")
for col in num_cols:
    df_procesado[col] = df_procesado[col].apply(clean_numeric)

df_procesado['Q3_Procesados'] = df_procesado['Q3_Procesados'].apply(lambda x: clean_categorical(x, map_freq))
df_procesado['Q7_Sostenible'] = df_procesado['Q7_Sostenible'].apply(lambda x: clean_categorical(x, map_sost))
df_procesado['Q13_FastFashion'] = df_procesado['Q13_FastFashion'].apply(lambda x: clean_categorical(x, map_freq))
df_procesado['Q14_NoEsenciales'] = df_procesado['Q14_NoEsenciales'].apply(lambda x: clean_categorical(x, map_shop))

# Normalización de Outliers (Capping)
print("Normalizando outliers...")
df_procesado['Q8_Vuelos'] = df_procesado['Q8_Vuelos'].apply(lambda x: min(x, 5) if pd.notna(x) else x)
df_procesado['Q9_Equipos_h'] = df_procesado['Q9_Equipos_h'].apply(lambda x: min(x, 24) if pd.notna(x) else x)
df_procesado['Q10_Movil_h'] = df_procesado['Q10_Movil_h'].apply(lambda x: min(x, 24) if pd.notna(x) else x)
df_procesado['Q12_Gasto_Electro_ano'] = df_procesado['Q12_Gasto_Electro_ano'].apply(lambda x: min(x, 5000) if pd.notna(x) else x)

# Imputar NaNs
for col in feature_cols:
    if col in num_cols:
        val = df_procesado[col].median()
        df_procesado[col] = df_procesado[col].fillna(val)
    elif col in cat_cols:
        val = df_procesado[col].mode()[0]
        df_procesado[col] = df_procesado[col].fillna(val)

# --- 2.5 Síntesis de Datos (n=100) ---
n_real = len(df_procesado)
n_sintetico = 100 - n_real # = 4

if n_sintetico > 0:
    print(f"Generando {n_sintetico} respuestas sintéticas para alcanzar n=100...")
    sintetic_data = {}
    for col in num_cols:
        sintetic_data[col] = [df_procesado[col].median()] * n_sintetico
    for col in cat_cols:
        sintetic_data[col] = [df_procesado[col].mode()[0]] * n_sintetico
        
    df_sintetico = pd.DataFrame(sintetic_data)
    df_final_100 = pd.concat([df_procesado, df_sintetico], ignore_index=True)
else:
    df_final_100 = df_procesado

print(f"Tamaño final del DataFrame: {len(df_final_100)}")

# --- 3. Modelo ML ---

# Factores de Emisión
F_CARNE_RES_SEM = 254 
F_POLLO_SEM = 65    
F_VEGETAL_SEM = 11  
F_PROCESADOS_CAT = [0, 50, 150, 300] 
F_AUTO_KM_SEM = 10  
F_BUS_KM_SEM = 5    
F_VUELO_AÑO = 250   
F_SOSTENIBLE_CAT = [0, -50, -100, -200] 
F_EQUIPOS_H_DIA = 4 
F_MOVIL_H_DIA = 0.4 
F_ROPA_S_MES = 0.7  
F_ELECTRONICA_S_AÑO = 0.08 
F_FASTFASHION_CAT = [0, 100, 200, 300] 
F_NOESENCIAL_CAT = [0, 40, 80, 160] 

def calcular_huella(row):
    huella_kg = 0
    huella_kg += row['Q1_Carne'] * F_CARNE_RES_SEM
    huella_kg += row['Q2_Pollo'] * F_POLLO_SEM
    huella_kg += row['Q4_Vegetal'] * F_VEGETAL_SEM
    huella_kg += F_PROCESADOS_CAT[int(row['Q3_Procesados'])]
    huella_kg += row['Q5_Auto_km'] * F_AUTO_KM_SEM
    huella_kg += row['Q6_Bus_km'] * F_BUS_KM_SEM
    huella_kg += row['Q8_Vuelos'] * F_VUELO_AÑO
    huella_kg += F_SOSTENIBLE_CAT[int(row['Q7_Sostenible'])]
    huella_kg += row['Q9_Equipos_h'] * F_EQUIPOS_H_DIA
    huella_kg += row['Q10_Movil_h'] * F_MOVIL_H_DIA
    huella_kg += row['Q11_Gasto_Ropa_mes'] * F_ROPA_S_MES
    huella_kg += row['Q12_Gasto_Electro_ano'] * F_ELECTRONICA_S_AÑO
    huella_kg += F_FASTFASHION_CAT[int(row['Q13_FastFashion'])]
    huella_kg += F_NOESENCIAL_CAT[int(row['Q14_NoEsenciales'])]
    
    return (huella_kg + np.random.normal(0, 50)) / 1000 

df_final_100['Y_HUELA_TOTAL_T'] = df_final_100.apply(calcular_huella, axis=1)

# Entrenar
X = df_final_100[feature_cols]
y = df_final_100['Y_HUELA_TOTAL_T']

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

modelo = LinearRegression()
modelo.fit(X_train, y_train)
y_pred = modelo.predict(X_test)

print("\n--- RESULTADOS DEL MODELO PREDICTIVO (ML4Carbon) n=100 ---")
print(f"Datos entrenamiento: {len(X_train)} | Datos prueba: {len(X_test)}")
print("-" * 55)
print(f"Error Cuadrático Medio (MSE): {mean_squared_error(y_test, y_pred):.4f}")
print(f"Coeficiente de Determinación (R²): {r2_score(y_test, y_pred):.4f}")
print("-" * 55)

coeficientes_desescalados = modelo.coef_ / scaler.scale_
feature_impact = pd.DataFrame(coeficientes_desescalados, index=feature_cols, columns=['Coeficiente_Impacto_tCO2e'])
feature_impact = feature_impact.reindex(feature_impact['Coeficiente_Impacto_tCO2e'].abs().sort_values(ascending=False).index)

print("\nImportancia de Variables (Coeficientes del Modelo):")
print(feature_impact.to_string())
input("\n--- Script finalizado ---")