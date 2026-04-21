"""
    GRUPO 7: Implementaciones en Python
"""

print("Ejemplo 2: Lógica de inferencia")
print("------------------------\n")

numero = 8

# Proposiciones
p = (numero % 2 == 0)  # "8 es par" VERDADERO
q = (numero % 2 == 0)  # "8 es divisible entre 2" VERDADERO

# Implicación: p → q  ≡  ¬p ∨ q
implicacion = (not p) or q

"""Hasta este momento, ya tenemos afirmado p"""

# Aplicación del modus ponens
if implicacion and p:
    conclusion = q
else:
    conclusion = False

print("Número:", numero)
print("p (es par):", p)
print("q (divisible entre 2):", q)
print("p → q:", implicacion)
print("Conclusión (q):", conclusion)

print("\n------------------------\n")
input("Presione un tecla para cerrar el programa...")