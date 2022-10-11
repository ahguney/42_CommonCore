#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

typedef struct veriyapisi
{
    int iplikNO;
    int sayi1;
    int sayi2;

}   t_struct; 

void *islem(void *data)
{
    int *sonuc;
    sonuc = malloc(sizeof(int)*1);

    if(((t_struct *)data)->iplikNO == 1)
    {
        *sonuc = (int)((t_struct *)data)->sayi1;
    }
    else if(((t_struct *)data)->iplikNO == 2)
    {
        *sonuc = (int)((t_struct *)data)->sayi2;
    }
    pthread_exit((void *)sonuc);
}

int main()
{
    pthread_t th1,th2;
    t_struct struct1,struct2;

    int a,b;

    printf("Bir sayi gir = ");
    scanf("%d",&a);

    printf("Bir sayi gir = ");
    scanf("%d",&b);

    struct1.iplikNO = 1;
    struct1.sayi1 = a;

    struct2.iplikNO = 2;
    struct2.sayi2 = b;

    pthread_create(&th1,NULL,islem,(void *)&struct1);
    pthread_create(&th2,NULL,islem,(void *)&struct2);

    void *bilgi1;
    void *bilgi2;

    pthread_join(th1,&bilgi1);
    pthread_join(th2,&bilgi2);

    printf("thread 1 = %d\n",*(int*)bilgi1);
    printf("thread 2 = %d\n",*(int*)bilgi2);
}