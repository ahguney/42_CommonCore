#include <unistd.h>
 
 int    main(int argc,char **argv)
 {
    if(argc > 1)
    {
    int i = 1;
    int a = 0;

    while(argv[i])
    {
        a = 0;
        while(argv[i][a])
        {
            if(argv[i][a] >='A' && argv[i][a] <= 'Z')
            {
                argv[i][a] +=32;
            }
            if(argv[i][a+1] == ' ' && argv[i][a] >='a' && argv[i][a] <= 'z')
            {
                argv[i][a] -= 32;
            }
            if(argv[i][a+1] == '\t' && argv[i][a] >='a' && argv[i][a] <= 'z')
            {
                argv[i][a] -= 32;
            }
            if(argv[i][a+1] == '\0' && argv[i][a] >='a' && argv[i][a] <= 'z')
            {
                argv[i][a] -= 32;
            }
            write(1,&argv[i][a],1);
            a++;
        }
        i++;
    }
    }
    write(1,"\n",1);
 }