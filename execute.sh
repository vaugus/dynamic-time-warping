#!/bin/bash

if [ $1 -eq 1 ] 
then
    ./main 1 -1 > output/no_band/1.txt
    ./main 1 -1 > output/no_band/2.txt
    ./main 1 -1 > output/no_band/3.txt
    ./main 1 -1 > output/no_band/4.txt
    ./main 1 -1 > output/no_band/5.txt
    ./main 1 -1 > output/no_band/6.txt
    ./main 1 -1 > output/no_band/7.txt
    ./main 1 -1 > output/no_band/8.txt
    ./main 1 -1 > output/no_band/9.txt
    ./main 1 -1 > output/no_band/10.txt
fi

if [ $1 -eq 2 ] 
then
    ./main 3 -1 > output/tridimensional/1.txt
    ./main 3 -1 > output/tridimensional/2.txt
    ./main 3 -1 > output/tridimensional/3.txt
    ./main 3 -1 > output/tridimensional/4.txt
    ./main 3 -1 > output/tridimensional/5.txt
    ./main 3 -1 > output/tridimensional/6.txt
    ./main 3 -1 > output/tridimensional/7.txt
    ./main 3 -1 > output/tridimensional/8.txt
    ./main 3 -1 > output/tridimensional/9.txt
    ./main 3 -1 > output/tridimensional/10.txt
fi

if [ $1 -eq 3 ] 
then
    ./main 1 0 > output/sakoe_chiba/zero_percent/1.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/2.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/3.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/4.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/5.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/6.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/7.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/8.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/9.txt
    ./main 1 0 > output/sakoe_chiba/zero_percent/10.txt

    ./main 1 0.01 > output/sakoe_chiba/one_percent/1.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/2.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/3.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/4.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/5.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/6.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/7.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/8.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/9.txt
    ./main 1 0.01 > output/sakoe_chiba/one_percent/10.txt

    ./main 1 0.05 > output/sakoe_chiba/five_percent/1.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/2.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/3.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/4.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/5.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/6.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/7.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/8.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/9.txt
    ./main 1 0.05 > output/sakoe_chiba/five_percent/10.txt

    ./main 1 0.1 > output/sakoe_chiba/ten_percent/1.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/2.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/3.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/4.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/5.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/6.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/7.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/8.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/9.txt
    ./main 1 0.1 > output/sakoe_chiba/ten_percent/10.txt

    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/1.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/2.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/3.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/4.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/5.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/6.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/7.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/8.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/9.txt
    ./main 1 0.2 > output/sakoe_chiba/twenty_percent/10.txt

    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/1.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/2.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/3.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/4.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/5.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/6.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/7.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/8.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/9.txt
    ./main 1 0.5 > output/sakoe_chiba/fifty_percent/10.txt

    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/1.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/2.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/3.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/4.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/5.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/6.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/7.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/8.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/9.txt
    ./main 1 1 > output/sakoe_chiba/one_hundred_percent/10.txt
fi

echo 'Done!'