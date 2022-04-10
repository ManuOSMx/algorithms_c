#!/bin/bash
clear
gcc buroptimi.c tiempo.c -o optimizada
./optimizada 100 < numeros.txt >>salida.txt 
./optimizada 1000 < numeros.txt >>salida.txt 
./optimizada 5000 < numeros.txt >>salida.txt 
./optimizada 10000 < numeros.txt >>salida.txt 
./optimizada 50000 < numeros.txt >>salida.txt 
./optimizada 100000 < numeros.txt >>salida.txt 
./optimizada 200000 < numeros.txt >>salida.txt 
./optimizada 400000 < numeros.txt >>salida.txt 
./optimizada 600000 < numeros.txt >>salida.txt 
./optimizada 800000 < numeros.txt >>salida.txt 
./optimizada 1000000 < numeros.txt >>salida.txt 
./optimizada 2000000 < numeros.txt >>salida.txt 
./optimizada 3000000 < numeros.txt >>salida.txt 
./optimizada 4000000 < numeros.txt >>salida.txt 
./optimizada 5000000 < numeros.txt >>salida.txt 
./optimizada 6000000 < numeros.txt >>salida.txt 
./optimizada 7000000 < numeros.txt >>salida.txt 
./optimizada 8000000 < numeros.txt >>salida.txt 
./optimizada 9000000 < numeros.txt >>salida.txt 
./optimizada 10000000 < numeros.txt >>salida.txt 

