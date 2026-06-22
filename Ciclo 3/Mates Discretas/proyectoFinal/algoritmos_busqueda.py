def busqueda_lineal(lista, objetivo):
    
    for i in range(len(lista)): # O(n)
        if lista[i] == objetivo:
            return i # Retorna el índice si lo encuentra
    return None # No retorna nada si el elemento no está

def busqueda_binaria(lista, objetivo):
    inicio = 0
    fin = len(lista) - 1

    while inicio <= fin: # O(logn)
        # Encontramos el punto medio
        medio = (inicio + fin) // 2

        # Verificamos si el objetivo está en medio
        if lista[medio] == objetivo:
            return medio
        
        # Si el objetivo es mayor, ignoramos la mitad izquierda
        elif lista[medio] < objetivo:
            inicio = medio + 1

        # Si el objetivo es menor, ignoramos la mitad derecha
        else:
            fin = medio - 1
    
    return None

# Seleccionamos una lista ordenada para que funcione la búsqueda binaria
elementos = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

print("--------------------------------------")
print(" Selecciona el algoritmo de búsqueda")
print(" 1. Búsqueda Lineal")
print(" 2. Búsqueda Binaria")
print("--------------------------------------")

# Diccionario de opciones de búsqueda
switcher = {
    1: busqueda_lineal,
    2: busqueda_binaria
}

while True:
    numero_buscado = int(input("Ingrese el número que desea buscar: ") or 0)

    if (numero_buscado and numero_buscado != 0):
        break

while True:
    opcion = int(input("Seleccione el algoritmo de búsqueda (1/2): ") or 0)

    try:
        resultado = switcher.get(opcion)(elementos, numero_buscado)
        break
    except:
        print("Esa opción no existe o es inválida...!")

if resultado != None:
    print(f"El número {numero_buscado} se encuentra en el índice {resultado}.")
else:
    print(f"El número {numero_buscado} no se encuentra en la lista.")

input("Presione Enter para salir...")