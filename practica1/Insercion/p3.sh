#!/bin/bash
clear
gcc insercion.c tiempo.c -o insercion
./insercion 100 < numeros.txt >>salida100.txt 
./insercion 500 < numeros.txt >>salida500.txt 
./insercion 800 < numeros.txt >>salida800.txt 
./insercion 1000 < numeros.txt >>salida1k.txt 
./insercion 5000 < numeros.txt >>salida5k.txt 
./insercion 6000 < numeros.txt >>salida6k.txt 
./insercion 8000 < numeros.txt >>salida8k.txt 
./insercion 10000 < numeros.txt >>salida10k.txt 
./insercion 50000 < numeros.txt >>salida50k.txt 
./insercion 60000 < numeros.txt >>salida60k.txt 
./insercion 80000 < numeros.txt >>salida80k.txt 
./insercion 100000 < numeros.txt >>salida100k.txt 
./insercion 200000 < numeros.txt >>salida200k.txt 
./insercion 400000 < numeros.txt >>salida400k.txt 
./insercion 500000 < numeros.txt >>salida500k.txt 
./insercion 600000 < numeros.txt >>salida600k.txt 
./insercion 800000 < numeros.txt >>salida800k.txt 
./insercion 1000000 < numeros.txt >>salida1M.txt 
./insercion 1500000 < numeros.txt >>salida1M5.txt 
./insercion 2000000 < numeros.txt >>salida2M.txt 
