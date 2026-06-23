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