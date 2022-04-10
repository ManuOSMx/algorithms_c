#!/bin/bash

gcc BusquedaExpoHilos.c tiempo.c -o BExpoHilos -lpthread


./BExpoHilos 4 1000000 < 10milloneso.txt > BExpoHilos1M.txt
./BExpoHilos 4 2000000 < 10milloneso.txt > BExpoHilos2M.txt
./BExpoHilos 4 3000000 < 10milloneso.txt > BExpoHilos3M.txt
./BExpoHilos 4 4000000 < 10milloneso.txt > BExpoHilos4M.txt
./BExpoHilos 4 5000000 < 10milloneso.txt > BExpoHilos5M.txt
./BExpoHilos 4 6000000 < 10milloneso.txt > BExpoHilos6M.txt
./BExpoHilos 4 7000000 < 10milloneso.txt > BExpoHilos7M.txt
./BExpoHilos 4 8000000 < 10milloneso.txt > BExpoHilos8M.txt
./BExpoHilos 4 9000000 < 10milloneso.txt > BExpoHilos9M.txt
./BExpoHilos 4 10000000 < 10milloneso.txt > BExpoHilos10M.txt
