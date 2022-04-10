#!/bin/bash
clear
gcc seleccion.c tiempo.c -o selec
./selec 100 < numeros.txt >>salida100.txt 
./selec 500 < numeros.txt >>salida500.txt
./selec 800 < numeros.txt >>salida800.txt
./selec 1000 < numeros.txt >>salida1k.txt 
./selec 5000 < numeros.txt >>salida5k.txt
./selec 6000 < numeros.txt >>salida6k.txt
./selec 8000 < numeros.txt >>salida8k.txt
./selec 10000 < numeros.txt >>salida10k.txt 
./selec 50000 < numeros.txt >>salida50k.txt 
./selec 60000 < numeros.txt >>salida60k.txt
./selec 80000 < numeros.txt >>salida80k.txt
./selec 100000 < numeros.txt >>salida100k.txt 
./selec 200000 < numeros.txt >>salida200k.txt 
./selec 400000 < numeros.txt >>salida400k.txt
./selec 600000 < numeros.txt >>salida600k.txt 
./selec 800000 < numeros.txt >>salida800k.txt 
./selec 1000000 < numeros.txt >>salida1M.txt
./selec 1500000 < numeros.txt >>salida1M5.txt
