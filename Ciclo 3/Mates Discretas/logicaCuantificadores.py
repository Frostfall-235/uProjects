"""
    GRUPO 7: Implementaciones en Python
"""

print("Ejemplo 3: Lógica de cuantificadores")
print("------------------------\n")

notas_estudiantes = [15, 18, 12, 20]

# Funciones Proposicionales
def P(x):
    return x >= 11  # aprueba

def Q(x):
    return x > 18   # destacado

""" Inspeccionamos si todos aprueban usando
    P(x) y all() para cada x en notas_estudiantes [∀x P(x)]
    y si existe al menos uno destacado usando
    Q(x) y any() para cada x en notas_estudiantes [∃x Q(x)]
"""
todos_aprueban = all(P(x) for x in notas_estudiantes)
existe_destacado = any(Q(x) for x in notas_estudiantes)

print("Notas:", notas_estudiantes)
print("∀x P(x) (todos aprueban):", todos_aprueban)
print("∃x Q(x) (alguien destacado):", existe_destacado)

print("\n------------------------\n")
input("Presione un tecla para cerrar el programa...")