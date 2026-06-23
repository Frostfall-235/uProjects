import customtkinter as ctk

# -----------------------------
# INTERFAZ
# -----------------------------

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

def crear_interfaz(on_ejecutar):
    app = ctk.CTk()

    app.title("Analizador de Algoritmos")
    app.geometry("900x600")

    titulo = ctk.CTkLabel(
        app,
        text="ANALIZADOR DE ALGORITMOS",
        font=("Arial", 28, "bold"),
    )
    titulo.pack(pady=20)

    frame = ctk.CTkFrame(app)
    frame.pack(fill="both", expand=True, padx=20, pady=20)

    # Panel izquierdo
    panel_izq = ctk.CTkFrame(frame)
    panel_izq.pack(side="left", fill="y", padx=10, pady=10)

    ctk.CTkLabel(panel_izq, text="Seleccionar algoritmo").pack(pady=10)

    combo_algoritmo = ctk.CTkComboBox(
        panel_izq,
        values=[
            "Bubble Sort",
            "Merge Sort",
            "Búsqueda Lineal",
            "Búsqueda Binaria",
        ],
    )
    combo_algoritmo.pack(pady=10)

    ctk.CTkLabel(panel_izq, text="Lista de números").pack(pady=(20, 5))
    entrada_datos = ctk.CTkEntry(
        panel_izq,
        width=300,
        placeholder_text="8,3,5,1,9",
    )
    entrada_datos.pack()

    label_valor_buscar = ctk.CTkLabel(panel_izq, text="Valor a buscar")
    label_valor_buscar.pack(pady=(20, 5))

    entrada_busqueda = ctk.CTkEntry(
        panel_izq,
        width=300,
        placeholder_text="5",
    )
    entrada_busqueda.pack()

    # Controlar visibilidad del campo de búsqueda según el algoritmo
    def _actualizar_campo(*_):
        algoritmo = combo_algoritmo.get()
        mostrar = algoritmo in ("Búsqueda Lineal", "Búsqueda Binaria")
        if mostrar:
            # Re-pack para asegurar visibilidad
            label_valor_buscar.pack()
            entrada_busqueda.pack()
        else:
            label_valor_buscar.pack_forget()
            entrada_busqueda.pack_forget()

    try:
        combo_algoritmo.configure(command=_actualizar_campo)
    except Exception:
        try:
            combo_algoritmo.bind("<<ComboboxSelected>>", _actualizar_campo)
        except Exception:
            pass

    _actualizar_campo()

    ctk.CTkButton(

        panel_izq,
        text="Ejecutar",
        command=on_ejecutar,
        height=40,
    ).pack(pady=30)

    # Panel derecho
    panel_der = ctk.CTkFrame(frame)
    panel_der.pack(
        side="right",
        fill="both",
        expand=True,
        padx=10,
        pady=10,
    )

    # Usar un scroll para poder mostrar listas grandes completas.
    resultado = ctk.CTkTextbox(
        panel_der,
        wrap="word",
        font=("Consolas", 13),
        state="disabled",
    )
    resultado.pack(fill="both", expand=True, padx=20, pady=20)

    # Texto inicial
    resultado.configure(state="normal")
    resultado.delete("1.0", "end")
    resultado.insert("end", "Los resultados aparecerán aquí")
    resultado.configure(state="disabled")

    return app, entrada_datos, resultado, combo_algoritmo, entrada_busqueda



