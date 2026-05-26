#include<stdio.h>
#include<unistd.h>


int main()
{
    fork();
    fork();
    fork();
    printf("start of main function\n");
    return 0;
}