#!/bin/bash


gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c main.c
if ( ./a.out | grep "sadasdas1231" -q f.txt)
then
sleep 1
echo "OK"
else
echo "KO"
exit
fi
