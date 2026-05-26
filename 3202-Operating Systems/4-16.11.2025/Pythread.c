#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* thread_func(void* arg)
{
    int *iarg=(int*) arg;

    printf("Thread %d : Inside thread function\n", *iarg);
}

void* multiplier(void* arg)
{
    int *iarg=(int*) arg;
    int *res=(int*) malloc(sizeof(int));
    *res=*res*2;

    return res;

}

int main()
{
    printf("start of main function\n");

    pthread_t t1,t2;

    int a=10,b=2;

    // pthread_create(&t1,NULL,thread_func,&a);
    // pthread_create(&t2,NULL,thread_func,&b);

    pthread_create(t1,NULL,multiplier,&a);

    printf("end of main function\n");

    // int t=10000000;

    // while (t--)
    // {
    //     /* code */
    // }
    int *res=10;
    pthread_join(t1,res);
    printf("%d",*res);

    // pthread_join(t1,NULL);
    return 0;
}