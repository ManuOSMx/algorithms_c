#!/bin/bash

gcc BusquedaLinealHilo.c tiempo.c -o busquedalinealhilo -pthread


./busquedalinealhilo 4 1000000 < 10millones.txt > busquedalinealH1M.txt
./busquedalinealhilo 4 2000000 < 10millones.txt > busquedalinealH2M.txt
./busquedalinealhilo 4 3000000 < 10millones.txt > busquedalinealH3M.txt
./busquedalinealhilo 4 4000000 < 10millones.txt > busquedalinealH4M.txt
./busquedalinealhilo 4 5000000 < 10millones.txt > busquedalinealH5M.txt
./busquedalinealhilo 4 6000000 < 10millones.txt > busquedalinealH6M.txt
./busquedalinealhilo 4 7000000 < 10millones.txt > busquedalinealH7M.txt
./busquedalinealhilo 4 8000000 < 10millones.txt > busquedalinealH8M.txt
./busquedalinealhilo 4 9000000 < 10millones.txt > busquedalinealH9M.txt
./busquedalinealhilo 4 10000000 < 10millones.txt > busquedalinealH10M.txt
