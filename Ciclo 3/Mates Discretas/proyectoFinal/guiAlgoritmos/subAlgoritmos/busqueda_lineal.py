
def busqueda_lineal(lista, objetivo):

    for i in range(len(lista)): # O(n)
        if lista[i] == objetivo:
            return i # Retorna el índice si lo encuentra
        
    return None # No retorna nada si el elemento no está