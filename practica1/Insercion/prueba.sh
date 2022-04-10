#!/bin/bash
clear
gcc insercion.c tiempo.c -o insercion
./insercion 100 < numeros.txt >>salida100.txt 
./insercion 1000 < numeros.txt >>salida1k.txt 
./insercion 5000 < numeros.txt >>salida.txt 
./insercion 10000 < numeros.txt >>salida.txt 
./insercion 50000 < numeros.txt >>salida.txt 
./insercion 100000 < numeros.txt >>salida.txt 
./insercion 200000 < numeros.txt >>salida.txt 
./insercion 400000 < numeros.txt >>salida.txt 
./insercion 600000 < numeros.txt >>salida.txt 
./insercion 800000 < numeros.txt >>salida.txt 
./insercion 1000000 < numeros.txt >>salida.txt 
./insercion 2000000 < numeros.txt >>salida.txt 
./insercion 3000000 < numeros.txt >>salida.txt 
./insercion 4000000 < numeros.txt >>salida.txt  
./insercion 5000000 < numeros.txt >>salida.txt 
./insercion 6000000 < numeros.txt >>salida.txt 
./insercion 7000000 < numeros.txt >>salida.txt 
./insercion 8000000 < numeros.txt >>salida.txt 
./insercion 9000000 < numeros.txt >>salida.txt 
./insercion 10000000 < numeros.txt >>salida.txt 
