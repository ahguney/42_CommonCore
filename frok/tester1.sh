#!/bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 get_next_line.c main.c
if ( ./a.out | grep "sadasdas1231" -q f.txt)
then
echo "GNL OK"
else
echo "KO"
exit
fi

gcc -Wall -Wextra -Werror ft_printf.c main2.c
if [ "$(./a.out | grep 'furkan')" == "furkan" ]
then
echo TEST 1 OK
else
echo KO
fi
gcc -Wall -Wextra -Werror ft_printf.c main3.c
if [ "$(./a.out | grep '55')" == "55" ]
then
echo TEST 2 OK
gcc -Wall -Wextra -Werror ft_printf.c main4.c
fi
if [ "$(./a.out | grep 'c')" == "c" ]
then
echo TEST 3 OK Printf Completed
fi

gcc -Wall -Wextra -Werror ft_printf.c mainreturn.c
if [ "$(./a.out | grep "552c1furkan6")" == "552c1furkan6" ]
then
echo OK PRINTF
else
echo KO
fi


