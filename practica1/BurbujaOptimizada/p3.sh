#!/bin/bash
clear
gcc buroptimi.c tiempo.c -o optimizada

./optimizada 1500000 < numeros.txt >>salida1M5.txt
