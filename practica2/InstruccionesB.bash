#!/bin/bash

gcc BusquedaBin.c tiempo.c -o busquedabinaria 

./busquedabinaria 1000000 < 10milloneso.txt > busquedabinaria1M.txt
./busquedabinaria 2000000 < 10milloneso.txt > busquedabinaria2M.txt
./busquedabinaria 3000000 < 10milloneso.txt > busquedabinaria3M.txt
./busquedabinaria 4000000 < 10milloneso.txt > busquedabinaria4M.txt
./busquedabinaria 5000000 < 10milloneso.txt > busquedabinaria5M.txt
./busquedabinaria 6000000 < 10milloneso.txt > busquedabinaria6M.txt
./busquedabinaria 7000000 < 10milloneso.txt > busquedabinaria7M.txt
./busquedabinaria 8000000 < 10milloneso.txt > busquedabinaria8M.txt
./busquedabinaria 9000000 < 10milloneso.txt > busquedabinaria9M.txt
./busquedabinaria 10000000 < 10milloneso.txt > busquedabinaria10M.txt

