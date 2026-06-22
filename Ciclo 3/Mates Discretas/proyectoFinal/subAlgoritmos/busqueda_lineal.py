def busqueda_lineal(lista, objetivo):
    
    for i in range(len(lista)): # O(n)
        if lista[i] == objetivo:
            return i # Retorna el índice si lo encuentra
    return None # No retorna nada si el elemento no está

# Una lista ordenada para que funcione la búsqueda binaria
elementos = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

while True:
    numero_buscado = int(input("Ingrese el número que desea buscar: ") or 0)

    if (numero_buscado and numero_buscado != 0):
        break

resultado = busqueda_lineal(elementos, numero_buscado)

if resultado != None:
    print(f"El número {numero_buscado} se encuentra en el índice {resultado}.")
else:
    print(f"El número {numero_buscado} no se encuentra en la lista.")