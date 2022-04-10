#!/bin/bash

g++ Arbol.cpp tiempo.c -o arbol 

./arbol 1000000 < 10millones.txt > arbol1M.txt
./arbol 2000000 < 10millones.txt > arbol2M.txt
./arbol 3000000 < 10millones.txt > arbol3M.txt
./arbol 4000000 < 10millones.txt > arbol4M.txt
./arbol 5000000 < 10millones.txt > arbol5M.txt
./arbol 6000000 < 10millones.txt > arbol6M.txt
./arbol 7000000 < 10millones.txt > arbol7M.txt
./arbol 8000000 < 10millones.txt > arbol8M.txt
./arbol 9000000 < 10millones.txt > arbol9M.txt
./arbol 10000000 < 10millones.txt > arbol10M.txt
