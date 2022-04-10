#!/bin/bash


gcc fibonacci.c tiempo.c -o fibo
./fibo 1000000 < 10milloneso.txt > FiboNormal1M.txt
./fibo 2000000 < 10milloneso.txt > FiboNormal2M.txt
./fibo 3000000 < 10milloneso.txt > FiboNormal3M.txt
./fibo 4000000 < 10milloneso.txt > FiboNormal4M.txt
./fibo 5000000 < 10milloneso.txt > FiboNormal5M.txt
./fibo 6000000 < 10milloneso.txt > FiboNormal6M.txt
./fibo 7000000 < 10milloneso.txt > FiboNormal7M.txt
./fibo 8000000 < 10milloneso.txt > FiboNormal8M.txt
./fibo 9000000 < 10milloneso.txt > FiboNormal9M.txt
./fibo 10000000 < 10milloneso.txt > FiboNormal10M.txt

