
def busqueda_lineal(lista, objetivo):
    comparaciones = 0

    for i in range(len(lista)):  # O(n)
        # Comparación relevante: decide si el elemento es el objetivo
        comparaciones += 1
        if lista[i] == objetivo:
            return i, comparaciones  # Retorna el índice y el contador

    return None, comparaciones  # No retorna nada si el elemento no está

