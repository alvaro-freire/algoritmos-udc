#!/bin/bash
# Imprime las líneas que se pasan de 80 caracteres.
cat ./*.{c,h} |grep '.{80}'

# Compila el código en ./p4
gcc -Wall *.c -lm -o p4

# Ejecuta ./p4
./p4