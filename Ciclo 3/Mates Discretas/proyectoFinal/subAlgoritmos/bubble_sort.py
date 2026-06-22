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

elementos = [1, 3, 5, 12, 2, 4, 8, 9, 10, 7, 11, 13, 14, 15, 6]
resultado = bubble_sort(elementos)

print(f"Lista original: {elementos}")
print(f"Lista ordenada: {resultado}.")

fin = t.perf_counter()

print(f"Tiempo de ejecución: {fin - inicio:.6f} segundos.")
input("Presione Enter para salir...")