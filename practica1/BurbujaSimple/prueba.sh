#!/bin/bash
clear
gcc bursimple.c tiempo.c -o simple
./simple 100< numeros.txt >>salida.txt 
./simple 1000 < numeros.txt >>salida.txt 
./simple 5000 < numeros.txt >>salida.txt 
./simple 10000 < numeros.txt >>salida.txt 
./simple 50000 < numeros.txt >>salida.txt 
./simple 100000 < numeros.txt >>salida.txt 
./simple 200000 < numeros.txt >>salida.txt 
./simple 400000 < numeros.txt >>salida.txt 
./simple 600000 < numeros.txt >>salida.txt 
./simple 800000 < numeros.txt >>salida.txt 
./simple 1000000 < numeros.txt >>salida.txt 
./simple 2000000 < numeros.txt >>salida.txt 

