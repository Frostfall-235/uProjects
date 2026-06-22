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

# Una lista ordenada para que funcione la búsqueda binaria
elementos = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

while True:
    numero_buscado = int(input("Ingrese el número que desea buscar: ") or 0)

    if (numero_buscado and numero_buscado != 0):
        break

resultado = busqueda_binaria(elementos, numero_buscado)

if resultado != None:
    print(f"El número {numero_buscado} se encuentra en el índice {resultado}.")
else:
    print(f"El número {numero_buscado} no se encuentra en la lista.")