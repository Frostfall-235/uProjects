def merge_sort(arr):
    
    """
    Caso base, una lista vacía o de 
    un solo elemento ya está ordenada
    """
    if len(arr) <= 1:
        return arr
    
    medio = len(arr) // 2 # Punto medio

    izquierda = arr[:medio] # Sublista inferior
    derecha = arr[medio:] # Sublista superior

    # Llamadas recursivas para ordenar ambas mitades
    izquierda_ordenada = merge_sort(izquierda)
    derecha_ordenada = merge_sort(derecha)

    # Fusionar (Merge) las dos mitades ordenadas
    return merge(izquierda_ordenada, derecha_ordenada)

def merge(izquierda, derecha):
    res = [] # Lista final ordenada
    i = j = 0

    """
    Comparar elementos de ambas listas mientras
    queden elementos sin procesar en las dos
    """
    while i < len(izquierda) and j < len(derecha):

        if izquierda[i] < derecha[j]:
            res.append(izquierda[i])
            i += 1
        else:
            res.append(derecha[j])
            j += 1
    
    res.extend(izquierda[i:])
    res.extend(derecha[j:])

    return res