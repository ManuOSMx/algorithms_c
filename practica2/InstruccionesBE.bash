#!/bin/bash

g++ exponencial.cpp tiempo.c -o busquedaExpo 

./busquedaExpo 1000000 < 10milloneso.txt > busquedaExpo1M.txt
./busquedaExpo 2000000 < 10milloneso.txt > busquedaExpo2M.txt
./busquedaExpo 3000000 < 10milloneso.txt > busquedaExpo3M.txt
./busquedaExpo 4000000 < 10milloneso.txt > busquedaExpo4M.txt
./busquedaExpo 5000000 < 10milloneso.txt > busquedaExpo5M.txt
./busquedaExpo 6000000 < 10milloneso.txt > busquedaExpo6M.txt
./busquedaExpo 7000000 < 10milloneso.txt > busquedaExpo7M.txt
./busquedaExpo 8000000 < 10milloneso.txt > busquedaExpo8M.txt
./busquedaExpo 9000000 < 10milloneso.txt > busquedaExpo9M.txt
./busquedaExpo 10000000 < 10milloneso.txt > busquedaExpo10M.txt
