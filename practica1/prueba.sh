#!/bin/bash
clear
gcc arbolbin.c tiempo.c -o arbol
./arbol 100 < numeros.txt >>salida.txt 
./arbol 1000 < numeros.txt >>salida.txt 
./arbol 5000 < numeros.txt >>salida.txt 
./arbol 10000 < numeros.txt >>salida.txt 
./arbol 50000 < numeros.txt >>salida.txt 
./arbol 100000 < numeros.txt >>salida.txt 
./arbol 200000 < numeros.txt >>salida.txt
./arbol 400000 < numeros.txt >>salida.txt
./arbol 600000 < numeros.txt >>salida.txt
./arbol 800000 < numeros.txt >>salida.txt
./arbol 1000000 < numeros.txt >>salida.txt
./arbol 2000000 < numeros.txt >>salida.txt
./arbol 3000000 < numeros.txt >>salida.txt
./arbol 4000000 < numeros.txt >>salida.txt
./arbol 5000000 < numeros.txt >>salida.txt 
./arbol 6000000 < numeros.txt >>salida.txt
./arbol 7000000 < numeros.txt >>salida.txt
./arbol 8000000 < numeros.txt >>salida.txt
./arbol 9000000 < numeros.txt >>salida.txt
./arbol 10000000 < numeros.txt >>salida.txt

