#!/bin/bash

# Verifica si el directorio de mapas fue proporcionado como argumento
if [ -z "$1" ]; then
 echo "Uso: $0 <directorio_de_mapas>"
 exit 1
fi

# Recorre cada archivo que tenga un nombre con algo antes del punto en el directorio proporcionado
for map in "$1"/*.*; do
 # Verifica si el nombre del archivo tiene algo antes del punto
 filename=$(basename -- "$map")
 if [[ "$filename" =~ ^[^.]+\..* ]]; then
 echo "Ejecutando ./so_long con el archivo $map"
 ./so_long "$map"

 # Captura el código de salida de ./so_long
 result=$?

 # Muestra un mensaje según el resultado del comando
 if [ $result -eq 0 ]; then
 echo "Archivo $map ejecutado correctamente."
 else
 echo "Error al ejecutar el archivo $map. Código de salida: $result"
 fi
 fi
done
