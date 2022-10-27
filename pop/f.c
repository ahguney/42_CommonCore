#include <unistd.h>
#include <stdio.h>
int main()
{
    char **argv;
    char *argv1;
    argv = &argv1;
    argv[0] = "fprkan";
    *argv++;
    printf("%c", **argv);
}

#include <unistd.h>
#include <stdio.h>
int main()
{
    int *p;
    int w;
    int t = 87;
    p = &w;
    p[0] = 55;
    /*p[2]*/ p[3] = 99;
    write(1, p, 1);
    write(1, &p[0], 1);
    write(1, &p[3], 1);
}

#include <unistd.h>
#include <stdio.h>
int main()
{
    char *p;
    char w;
    p = &w;
    p[0] = 'f';
    /*p[2]*/ p[9] = 88;
    write(1, p, 1);
    write(1, &p[0], 1);
    write(1, &p[9], 1);
}

#include <unistd.h>
#include <stdio.h>
int main()
{
    char *p; // *olunca calısmıyor
    char w;
    //p = &w;
    /*p[2]*/ p[9] = 88; p[8] = 77;
    //write(1, p, 1);
    printf("%c", p[9]);
    printf("%c", p[8]);
}

int main()
{
    char p[10];
    char a[10];
    p[0] = 55;
    a[1] = p[0];
    a[9] = a[1];
    printf("%c", a[9]);
}

char p[10] dizimiz var peki 10 uncu diziye bişey atabilirmiyiz ? 

#include <unistd.h>
#include <stdio.h>

int main()
{
    char *furkan = "f0rkan" - 48;
    furkan++;
    write(1, furkan, 1);
}

#include <unistd.h>
#include <stdio.h>

int main()
{
    int a = 100;
    char furkan[10];
    furkan[0] = (char)a;
    write(1, furkan, 1);
}

int main()
{
    char furkan[100];
    furkan[0] = 'a';
    write(1, &furkan, 1);
}

int main()
{
    char furkan[100];
    furkan[0] = 'a';
    write(1, furkan, 1);
}

int main()
{
    char *furkan;

    furkan = "ahmet";

    if (furkan = "furkan")
    {
        printf("%s", furkan);
    }
}

int main()
{
    char **dizi;
    char *f;
    dizi[0] = f = "furkan";
    write(1, dizi, 1);
}

int main()
{
    char **dizi;
    char *dizi1;
    dizi1 = "furkan";
    dizi = &dizi1;
    write(1, dizi, 1);
}

#include <unistd.h>
#include <stdio.h>

int main()
{
    float furkan = 55.00000;
    double furkan1 = 55.000;
    printf("%.2f", furkan);
    printf("%2.g", furkan1);
}

#include <unistd.h>
#include <stdio.h>

int main()
{
    char *furkan;
    furkan[0] = 55;
    furkan[2] = '7';
    printf("%c%c", furkan[0]+1, furkan[1+1]);
}

#include <stdio.h>

int main(void)
{
  float id;
 
  id = 7452.000;

  printf("%7d\n%5d", id, id);
}

int main(void)
{

  for (int id=0; id<10; id++) {
       printf("%d", id);
       if((id = 5))
       {
        ;
       }
  }
}
