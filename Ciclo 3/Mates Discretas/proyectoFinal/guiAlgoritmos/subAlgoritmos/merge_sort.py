def merge_sort(arr):
    """
    Caso base, una lista vacía o de
    un solo elemento ya está ordenada
    """
    if len(arr) <= 1:
        return arr, 0

    comparaciones = 0

    medio = len(arr) // 2  # Punto medio

    izquierda = arr[:medio]  # Sublista inferior
    derecha = arr[medio:]  # Sublista superior

    # Llamadas recursivas para ordenar ambas mitades
    izquierda_ordenada, c1 = merge_sort(izquierda)
    derecha_ordenada, c2 = merge_sort(derecha)

    # Fusionar (Merge) las dos mitades ordenadas
    mezclada, c3 = merge(izquierda_ordenada, derecha_ordenada)
    return mezclada, comparaciones + c1 + c2 + c3


def merge(izquierda, derecha):
    res = []  # Lista final ordenada
    i = j = 0
    comparaciones = 0

    """
    Comparar elementos de ambas listas mientras
    queden elementos sin procesar en las dos
    """
    while i < len(izquierda) and j < len(derecha):
        # Comparación relevante: decide cuál elemento va primero en el merge
        comparaciones += 1
        if izquierda[i] < derecha[j]:
            res.append(izquierda[i])
            i += 1
        else:
            res.append(derecha[j])
            j += 1

    res.extend(izquierda[i:])
    res.extend(derecha[j:])

    return res, comparaciones

