from interfaz import crear_interfaz

from subAlgoritmos.bubble_sort import bubble_sort
from subAlgoritmos.merge_sort import merge_sort
from subAlgoritmos.busqueda_lineal import busqueda_lineal
from subAlgoritmos.busqueda_binaria import busqueda_binaria

import time as t
import re as regex
import random as rd

COMPLEJIDADES = {
    "Bubble Sort": ("O(n²)", "O(1)"),
    "Merge Sort": ("O(n log n)", "O(n)"),
    "Búsqueda Lineal": ("O(n)", "O(1)"),
    "Búsqueda Binaria": ("O(log n)", "O(1)"),
}


# Función para escribir en el panel derecho
def _set_resultado_text(resultado, texto: str) -> None:
    try:
        resultado.configure(state="normal")
        resultado.delete("1.0", "end")
        resultado.insert("end", texto)
        resultado.configure(state="disabled")
    except Exception:
        resultado.configure(text=texto)


# Función para el botón de ejecutar algoritmos
def ejecutar(entrada_datos, resultado, combo_algoritmo, entrada_busqueda):
    try:
        patron = r"^\s*random\[(\d+)\]\s*$"
        datos = entrada_datos.get()
        match = regex.match(patron, datos)

        if match:
            tamanho = int(match.group(1))
            # Tomamos n números distintos entre 1 y n
            datos = rd.sample(range(1, tamanho + 1), tamanho)
        else:
            datos = [int(x.strip()) for x in entrada_datos.get().split(",")]
    except Exception:
        _set_resultado_text(resultado, "Error: ingrese números separados por comas.")
        return

    algoritmo = combo_algoritmo.get()

    texto_resultado = ""
    comparaciones = 0
    inicio = t.perf_counter()  # Inicio de la ejecución

    # Ejecutamos el algoritmo seleccionado
    try:
        if algoritmo == "Bubble Sort":
            res, comparaciones = bubble_sort(datos)
            texto_resultado = f"Lista ordenada:\n{res}"

        elif algoritmo == "Merge Sort":
            res, comparaciones = merge_sort(datos)
            texto_resultado = f"Lista ordenada:\n{res}"

        elif algoritmo == "Búsqueda Lineal":
            objetivo = int(entrada_busqueda.get())
            res, comparaciones = busqueda_lineal(datos, objetivo)
            texto_resultado = (
                f"Lista:\n{datos}\n\n"
                f"Posición encontrada: {res}"
                if res is not None
                else "Elemento no encontrado"
            )

        elif algoritmo == "Búsqueda Binaria":
            objetivo = int(entrada_busqueda.get())
            datos.sort()  # Ordenamos la lista
            res, comparaciones = busqueda_binaria(datos, objetivo)
            texto_resultado = (
                f"Lista ordenada:\n{datos}\n\nPosición encontrada: {res}"
                if res is not None and res != -1
                else "Elemento no encontrado"
            )

        else:
            _set_resultado_text(resultado, "Seleccione un algoritmo válido.")
            return

    except Exception as e:
        _set_resultado_text(resultado, f"Error: {e}")
        return

    fin = t.perf_counter()  # Fin de ejecución
    tiempo = fin - inicio
    temporal, espacial = COMPLEJIDADES[algoritmo]  # Imprimimos complejidad

    salida = (
        f"{texto_resultado}\n\n"
        f"Comparaciones realizadas: {comparaciones}\n\n"
        f"Tiempo de ejecución:\n{tiempo:.8f} segundos\n\n"
        f"Complejidad temporal: {temporal}\n"
        f"Complejidad espacial: {espacial}"
    )

    _set_resultado_text(resultado, salida)


def main():
    app, entrada_datos, resultado, combo_algoritmo, entrada_busqueda = crear_interfaz(
        on_ejecutar=lambda: ejecutar(
            entrada_datos,
            resultado,
            combo_algoritmo,
            entrada_busqueda,
        )
    )

    app.mainloop()


if __name__ == "__main__":
    main()

