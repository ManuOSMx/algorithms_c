#!/bin/bash

gcc BusquedaBinariaHilo.c tiempo.c -o busquedabinariahilo -pthread

./busquedabinariahilo 4 1000000 < 10milloneso.txt > busquedabinariaH1M.txt
./busquedabinariahilo 4 2000000 < 10milloneso.txt > busquedabinariaH2M.txt
./busquedabinariahilo 4 3000000 < 10milloneso.txt > busquedabinariaH3M.txt
./busquedabinariahilo 4 4000000 < 10milloneso.txt > busquedabinariaH4M.txt
./busquedabinariahilo 4 5000000 < 10milloneso.txt > busquedabinariaH5M.txt
./busquedabinariahilo 4 6000000 < 10milloneso.txt > busquedabinariaH6M.txt
./busquedabinariahilo 4 7000000 < 10milloneso.txt > busquedabinariaH7M.txt
./busquedabinariahilo 4 8000000 < 10milloneso.txt > busquedabinariaH8M.txt
./busquedabinariahilo 4 9000000 < 10milloneso.txt > busquedabinariaH9M.txt
./busquedabinariahilo 4 10000000 < 10milloneso.txt > busquedabinariaH10M.txt
