#!/bin/bash
clear
gcc seleccion.c tiempo.c -o selec
./selec 2000000 < numeros.txt >>salida2M.txt 
./selec 3000000 < numeros.txt >>salida3M.txt
