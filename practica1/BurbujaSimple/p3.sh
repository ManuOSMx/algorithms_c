#!/bin/bash
clear
gcc bursimple.c tiempo.c -o simple
./simple 500 < numeros.txt >>salida500.txt
./simple 800 < numeros.txt >>salida800.txt
./simple 6000 < numeros.txt >>salida6k.txt 
./simple 8000 < numeros.txt >>salida8k.txt
./simple 60000 < numeros.txt >>salida60k.txt 
./simple 80000 < numeros.txt >>salida80k.txt
./simple 1500000 <numeros.txt >>salida1M5.txt
