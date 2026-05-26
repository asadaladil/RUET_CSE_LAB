// Character Analysis
#include<stdio.h>
#include<string.h>
int main()
{
    printf("Address: ");
    char s[10000]="221B Baker Street, London.";
    printf("%s\n",s);
    int a=0,w=0,b=0,c=0,d=0,e=0,f=0;
    for(int i=0;s[i]!='\0';i++)
    {
        w++;
    }
    printf("Number of character in the string is : %d\n",w);
    for(int i=0;i<w;i++)
    {
        if(s[i]==' '||s[i]=='.')
        {
            a++;
        }
        if(s[i]>='a'&&s[i]<='z')
        {
            b++;
        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            c++;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            e++;
        }
        else if(s[i]==' ')
        {
            f++;
        }
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            d++;
        }
        else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
            d++;
        }
    }
    printf("Words: %d\n",a);
    printf("Letters: %d\n",b+c);
    printf("Uppercase: %d\n",c);
    printf("lowercase: %d\n",b);
    printf("vowels: %d\n",d);
    printf("consonant: %d\n",b+c-d);
    printf("spaces: %d\n",f);
    printf("Special Character: %d\n",w-b-c-f-e);
    printf("Digits: %d\n",e);

}
