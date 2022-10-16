int main()
{
   int a[3] = {1, 2, 3};
   int *p = (int *)&a;   
   for (int i = 0; i < 3; i++)
   {
      printf("%d", *p);
      p++;
   }
}

int main()
{
    int **p;
    int a = 1;
    *p = *(int *)&a;
    printf("%d",p[0]);
}

int main()
{
    int *p;
    int a = 10;
    p = (int *)&a;
    printf("%d",a);
}

int main()
{
    char *p = "ahmet";
    //p++; (*p)++ *p++ *(p)++ *(p++) (*p++)
    printf("%p",p);
}

int main()
{
    int x;
    int *ptr;
    int y;
    x = 8;
    ptr = &x;
    y = *ptr;
    
    printf("%d",y);
}

int main()
{
    int *ptr;
    int a = 65;
    ptr = &a;
    ptr = 65;
    printf("%d",*ptr);
}

int main()
{
    int *ptr;
    int y;
    int a = 65;
    ptr = &a;
    y = *ptr + 5;
    y = 0;
    y = *(ptr + 5);
    printf("%d",y);
}

int main()
{
    int *ptr;
    int y;
    int a = 65;
    ptr = &a;
    (*ptr)++; // 66
    ptr++;
    printf("%d",*ptr);
}

int main()
{
    int *ptr;
    int y;
    int a = 65;
    ptr = &a;
    *ptr = 10;
    printf("%d",*ptr);
}

int main()
{
    int a = 10;
    int *ptr = &a;
    *ptr = *(int *)&a;
    printf("%d",*ptr);
}

#include <unistd.h>
#include <stdio.h>

int ft_c(int a)
{
    write(1,&a,1);
    return(1);
}

static int ft_a(int a)
{
   unsigned int n = 'c' % 46;

    if(a > 0)
    {
        a = a + ft_c(a);
    }

    return(55);
}


int main()
{
    printf("%d",ft_a(15));
}

#include <unistd.h>
#include <stdio.h>
#include <libc.h>
int main()
{
    int a = 10;
    int *pa = &a;
    int **p = &pa;
    while(a++<12)
        printf("%d",*p[0]);
}

int main()
{
    char *v;
    v =(char *)malloc(1000);
    char *p;
    p =(char *)malloc(1000);
    p = "ahmet";
    v = &p; 
    p++;
    //(*p)++; 
    //*p++; 
    //*(p)++;
    //*(p++);
    //(*p++);
    printf("%c",v[0]);
}

int main()
{
    char *a = "ahmet";
    char *c = "furkan";
    char **b = &a;
    *b[1] = &c; 
    b++;
    printf("%c",**b);
}

int main()
{
    void *a = "a"; // void * her var tutar...

    printf("%c",*(char *)a);
}

int main()
{
    int c = 15;
    int *a;
    a = &c;
    *a = 10;
    a = (int *)a;
    printf("%d",a);
}

int main()
{
    int a;
    int *p;
    a = 10;
    p = &a;
    int b = 20;
    *p = b;
    printf("%d",a);
}

int main()
{
    int a;
    int *p;
    a = 2;
    p = &a;
    char *b;
    b = (char *)p;
    printf("%p%d",*(p+1));
}

#include <unistd.h>
#include <stdio.h>
#include <libc.h>

int main()
{
    char b[] = "ahmet";
    char *c = b;
    int A[] = {2,4,5,8};
    int *i = A;
    printf("%d",*i);

}

int main()
{
    int c = 'b';
    char b = 'a';
    char *p;
    p = &b;
    *p = c;
    printf("%d",*p);
}

int main()
{
    char a[] = "ahmet";
    char *b = a;
    b[0] = 'b';
    printf("%d",a[0]);
}

int main()
{
    
    char *a = "ahmet";
    a[0] = 'b';
    printf("%d",a[0]);
}

int main()
{
    char c = 10;
    char *b = &c; 
    int a = open("../ft_strcpy.c",O_RDWR,0);
    read(a,b,3);
     printf("%s",b);
}

int main()
{
   char *m = "ahmet";
   char *p = &m[1];
   p++;    
   for (int i = 0; i < 3; i++)
   {
      printf("%c", *p);
      p--;
   }
    
}

int main()
{
   int a[3] = {1, 2, 3};
   int *p = &a[1];    
   for (int i = 0; i < 3; i++)
   {
      printf("%d", *p);
      p--;
   }
    
}

int main()
{
   int c = 10;
   int *a = &c;
   int **p = (int **)&a;
   printf("%d",**p);
    
}

 int main()
{
   char ı;
   char l = 50;
   char *k;
    char *b = &l;
   char *p = "../ft_strcpy.c";
   int a = open("../ft_strcpy.c",O_RDONLY,0);
   read(a,b,3);
      read(a,k,3);
   printf("%c",*k);
}

int main()
{
   char c = 50;
   char *a= &c;
    int v = open("../ft_strcpy.c",O_RDWR,0);
   read(v,a,5);
   printf("%c",c);
}

int main()
{
   int a = 10;
   char *p = "ahmet";
   char c[] = "ahmetss";
   int *d = &a;
   int e[5] = {1,2,3,4};
   int *o = e;
   printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",(int)sizeof(*p),(int)sizeof(p),(int)sizeof(c),(int)sizeof(*c),(int)sizeof(*d),(int)sizeof(d),(int)sizeof(&a),(int)sizeof(e),(int)sizeof(*e),(int)sizeof(o));
}

int main()
{
   char *c;
   char **p = (char **)&c;
   p[0] = "ahmets";
   p[1] = "furkan";
   printf("%s%s",p[0],p[1]);

}

int main()
{
   char a = 50;
   char *c = &a;
   char **p = (char **)&c;
   p[0] = "ahmets";
   p[1] = "furkan";
   *c = 50; 
   printf("%s%s",p[0],p[1]);

}

int main()
{
	int ar[2][10] = {{1,2},{1,3}};
	printf("%d",ar[1][1]);

	char av[2][10] = {"ahmet","furkan"};
	printf("%s",av[1]);
}

int main()
{
    char *a = "ahmet";
    char *c = "furkan";
    char **b = &a;
    (*b)++;
    printf("%s",*b);
}