def bubble_sort(arr):
    comparaciones = 0

    for i in range(len(arr)):
        # Flag que indica si hubo algún intercambio
        swapped = False

        """
        En cada pasada, el elemento más grande
        'burbujea' hacia su posición final
        """
        for j in range(0, len(arr) - i - 1):
            # Comparación relevante: decide si estos dos elementos se intercambian
            comparaciones += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # Si no hubo cambios, la lista ya está ordenada
        if not swapped:
            break

    # Devuelve la lista ya ordenada junto al contador
    return arr, comparaciones

