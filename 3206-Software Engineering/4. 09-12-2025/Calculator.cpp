#include<bits/stdc++.h>
using namespace std;

class Calculator 
{
   public:
   float add(float a, float b)   
   {return a+b;}

   float sub(float a, float b)
   {return b-a;}

   float mult(float a, float b)
   {return a*b;}

   float div(float a, float b)
   {
      if(b==0)
      {
         throw string("Zero division not possible");
      }
      return a/b;
   }
   int modulus(int a,int b)
   {return a%b;}
};