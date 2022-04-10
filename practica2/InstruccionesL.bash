#!/bin/bash

gcc BusquedaLineal.c tiempo.c -o busquedalineal 

./busquedalineal 1000000 < 10millones.txt > busquedalineal1M.txt
./busquedalineal 2000000 < 10millones.txt > busquedalineal2M.txt
./busquedalineal 3000000 < 10millones.txt > busquedalineal3M.txt
./busquedalineal 4000000 < 10millones.txt > busquedalineal4M.txt
./busquedalineal 5000000 < 10millones.txt > busquedalineal5M.txt
./busquedalineal 6000000 < 10millones.txt > busquedalineal6M.txt
./busquedalineal 7000000 < 10millones.txt > busquedalineal7M.txt
./busquedalineal 8000000 < 10millones.txt > busquedalineal8M.txt
./busquedalineal 9000000 < 10millones.txt > busquedalineal9M.txt
./busquedalineal 10000000 < 10millones.txt > busquedalineal10M.txt
