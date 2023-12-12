import csv
import datetime

# Obtener la patente existente del usuario
patente = input("Ingrese la patente: ")

# Obtener la fecha y hora actual
fecha_actual = datetime.datetime.now()
fecha_formateada = fecha_actual.strftime('%d/%m/%y')
hora_formateada = fecha_actual.strftime('%I:%M %p')

# Abrir el archivo CSV y leer los datos
nombre_archivo = 'datos.csv'
with open(nombre_archivo, 'r') as archivo_csv:
    lector_csv = csv.reader(archivo_csv)

    # Crear una lista para almacenar los datos actualizados
    datos_actualizados = []

    # Variable para verificar si se encontró una fila existente con los mismos valores
    fila_existente = False

    # Iterar sobre las filas del archivo CSV
    for fila in lector_csv:
        # Verificar si la fila coincide con la patente, fecha y hora de ingreso
        if fila[0] == patente and fila[1] == fecha_formateada and fila[2] == hora_formateada:
            fila_existente = True
            # Actualizar los valores de fecha y hora de salida si aún no están llenos
            if fila[3] == '' and fila[4] == '':
                fila[3] = fecha_formateada 
                fila[4] = hora_formateada 
        datos_actualizados.append(fila)

    # Si no se encontró una fila existente, agregar una nueva fila al archivo CSV
    if not fila_existente:
        nueva_fila = [patente, fecha_formateada, hora_formateada, '', '']
        datos_actualizados.append(nueva_fila)

# Escribir los datos actualizados en el archivo CSV
with open(nombre_archivo, 'w', newline='') as archivo_csv:
    escritor_csv = csv.writer(archivo_csv)
    for fila in datos_actualizados:
        escritor_csv.writerow(fila)

print(f"Los datos han sido actualizados en el archivo '{nombre_archivo}'")
