"""
    GRUPO 7: Implementaciones en Python
"""

print("Ejemplo 1: Lógica Booleana")
print("------------------------\n")

p = True # 1 o Verdadero
q = True # 1 o Verdadero
r = False # 0 o Falso

# Forma original: (p ∧ q) → r
# Forma reducida: ¬(p ∧ q) ∨ r
resultado = (not (p and q)) or r

print("p (estudio):", p)
print("q (tareas):", q)
print("r (apruebo):", r)
print("Resultado:", resultado)

print("\n------------------------\n")
input("Presione un tecla para cerrar el programa...")