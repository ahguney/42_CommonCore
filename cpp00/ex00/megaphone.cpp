#include <iostream>

int main(int argc,char **argv)
{
    int i = 1;
    int a = 0;
    if (argc > 1)
    {
        while (argv[i])
        {
            a = 0;
            while (argv[i][a])
            {
                if (argv[i][a] >= 'a' && argv[i][a] <= 'z')
                argv[i][a] -=32;
                a++;
            }
            std::cout << argv[i] << " ";
            i++;
        }
        std::cout << "\n" << "";
        return (0);
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0); 
    }
    
}