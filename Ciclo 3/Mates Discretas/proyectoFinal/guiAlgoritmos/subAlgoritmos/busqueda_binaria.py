def busqueda_binaria(lista, objetivo):

    comparaciones = 0

    inicio = 0
    fin = len(lista) - 1

    while inicio <= fin:  # O(logn)
        # Encontramos el punto medio
        medio = (inicio + fin) // 2

        # Comparación relevante: decide si es el objetivo
        comparaciones += 1
        if lista[medio] == objetivo:
            return medio, comparaciones

        # Comparación relevante: decide hacia qué mitad avanzar
        comparaciones += 1
        if lista[medio] < objetivo:
            inicio = medio + 1
        else:
            fin = medio - 1

    return None, comparaciones

