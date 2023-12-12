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

    # Iterar sobre las filas del archivo CSV
    for fila in lector_csv:
        if fila[0] == "":
            datos = [
                patente, fecha_formateada, hora_formateada, '', '',
            ]
            datos_actualizados.append(datos)
        else:
            # Verificar la longitud de la lista fila antes de intentar asignar un valor a un índice específico
            if len(fila) < 4:
                fila.append('')
            if len(fila) < 5:
                fila.append('')

            # Si la patente coincide con la patente existente, actualizar los valores de fecha y hora
            if fila[0] == patente:
                fila[3] = fecha_formateada + ','
                fila[4] = hora_formateada + ','
            # Agregar la fila a la lista de datos actualizados

            datos_actualizados.append(fila)
            print(fila)
        if fila[0] != patente:
            datos = [
                patente, fecha_formateada, hora_formateada, '', '',
            ]
            datos_actualizados.append(datos)
    # Si la patente no coincide con la patente existente, agregar una nueva fila al archivo CSV
    
print(datos_actualizados)
# Escribir los datos actualizados en el archivo CSV
with open(nombre_archivo, 'w', newline='') as archivo_csv:
    escritor_csv = csv.writer(archivo_csv)
    for fila in datos_actualizados:
        escritor_csv.writerow(fila)

print(f"Los datos han sido actualizados en el archivo '{nombre_archivo}'")
