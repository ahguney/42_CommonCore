#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
        int i;
        int j;
        int array[255];
        i = 0;
        while(i<255)
        {
                array[i] = 0;
                i++;
        }
        if(argc == 3)
        {
                i = 1;
                while(argv[i])
                {
                        j = 0;
                        while(argv[i][j])
                        {
                                if(array[(unsigned char)argv[i][j]] == 0)
                                {
                                        array[(unsigned char)argv[i][j]] = 1;
                                        write(1,&argv[i][j],1);
                                }
                                j++;
                        }
                        i++;
                }
        }
        write(1,"\n",1);
}