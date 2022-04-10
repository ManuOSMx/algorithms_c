#!/bin/bash

gcc BusquedaFiboHilos.c tiempo.c -o busquedafibohilo -lpthread


./busquedafibohilo 4 1000000 < 10milloneso.txt > busquedafiboH1M.txt
./busquedafibohilo 4 2000000 < 10milloneso.txt > busquedafiboH2M.txt
./busquedafibohilo 4 3000000 < 10milloneso.txt > busquedafiboH3M.txt
./busquedafibohilo 4 4000000 < 10milloneso.txt > busquedafiboH4M.txt
./busquedafibohilo 4 5000000 < 10milloneso.txt > busquedafiboH5M.txt
./busquedafibohilo 4 6000000 < 10milloneso.txt > busquedafiboH6M.txt
./busquedafibohilo 4 7000000 < 10milloneso.txt > busquedafiboH7M.txt
./busquedafibohilo 4 8000000 < 10milloneso.txt > busquedafiboH8M.txt
./busquedafibohilo 4 9000000 < 10milloneso.txt > busquedafiboH9M.txt
./busquedafibohilo 4 10000000 < 10milloneso.txt > busquedafiboH10M.txt
