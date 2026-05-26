// Vowel consonant or not alphabet.
#include<stdio.h>
int main()
{
    char y;
    scanf("%c",&y);
    switch(y)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("%c is a vowel\n\n",y);
        break;
    default:
        if(y>='a'&&y<='z'||y>='A'&&y<='Z')
        {
            printf("%c is a consonant\n",y);
        }
        else
        {
            printf("It is not an alphabet\n");
        }
    }
}
