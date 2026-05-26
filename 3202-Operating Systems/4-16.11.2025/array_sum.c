#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct new_struct{
    int start;
    int arr[10];
    int end;
};

void* sum(struct new_struct* arg)
{
    int *res=(int*) malloc(sizeof(int));
    
    *res=0;

    for (int i=arg->start; i<=arg->end;i++)
    {
        *res+=arg->arr[i];
    }

    return res;
}
int main()
{
    // printf("start of main function\n");

    pthread_t t1,t2;

    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    struct new_struct s1,s2;

    for (int i = 0; i < 10; i++) 
    {
        s1.arr[i] = arr[i];
        s2.arr[i] = arr[i];
    }
    s1.start=0;
    s2.end=4;
    s2.start=5;
    s2.end=9;

    pthread_create(&t1,NULL,sum,&s1);
    pthread_create(&t2,NULL,sum,&s2);

    int *res1,*res2;
    pthread_join(t1,&res1);
    pthread_join(t2,&res2);

    printf("Sum=%d",*res1+*res2);
    

    // pthread_join(t1,NULL);
    return 0;
}