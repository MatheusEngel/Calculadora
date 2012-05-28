#include "TratamentodeDados.h"

float soma(float x, float y)
{
 float a, b, c;
 a=x;
 b=y;
 c=a+b;
 return c;
}

float mult(float x, float y)
{
 float a, b, c;
 a=x;
 b=y;
 c=a*b;
 return c;
}

float sub(float x, float y)
{
 float a, b, c;
 a=x;
 b=y;
 c=a-b;
 return c;
}

float div(float x, float y)
{
 float a, b, c;
 a=x;
 b=y;
 if (b==0)
    {
    cout<<"Divisão : Math Error"<< endl;
    return 0;
    }
 else
    {
    c=a/b;
    return c;
    }
}
