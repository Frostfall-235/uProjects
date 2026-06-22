import time as t

inicio = t.perf_counter()

def bubble_sort(arr):
    for i in range(len(arr)):
        
        # Flag que indica si hubo algún intercambio
        swapped = False

        """
        En cada pasada, el elemento más grande
        'burbujea' hacia su posición final
        """
        for j in range(0, len(arr) - i - 1):
            # Dos elementos están desordenados, intercambiarlos
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # Si no hubo cambios, la lista ya está ordenada
        if not swapped:
            break
    
    # Devuelve la lista ya ordenada
    return arr

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

elementos = [1, 3, 5, 20, 12, 2, 4, 8, 9, 10, 11, 13, 14, 15]

print("--------------------------------------")
print(" Selecciona el algoritmo de ordenamiento")
print(" 1. Bubble Sort (Ordenamiento Burbuja)")
print(" 2. Merge Sort (Ordenamiento por Fusión)")
print("--------------------------------------")

# Diccionario de opciones de búsqueda
switcher = {
    1: bubble_sort,
    2: merge_sort
}

while True:
    opcion = int(input("Seleccione el algoritmo de ordenamiento (1/2): ") or 0)

    try:
        resultado = switcher.get(opcion)(elementos)
        break
    except:
        print("Esa opción no existe o es inválida...!")

print(f"Lista original: {elementos}")
print(f"Lista ordenada: {resultado}.")

fin = t.perf_counter()

print(f"Tiempo de ejecución: {fin - inicio:.6f} segundos.")
input("Presione Enter para salir...")