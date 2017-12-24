#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    xyz:
    printf("O hai! How much change is owed?\n");
    double f = get_double();
    if(f > 0.00)
    {
    f = f * 100;
    f = round( f );
    f = (int) f;
    int count = 0;
    count = (int) ( f / 100 ) * 4;
    f = (int) f % 100;
    while( f - 25 >= 0 )
    { 
        count++;
        f = f - 25;
    }
    while( f - 10 >= 0 )
    { 
        count++;
        f = f - 10;
    }
    while( f - 5 >= 0 )
    {
        count++;
        f = f - 5;
    }
    while( f - 1 >= 0 )
    {
        count++;
        f = f - 1;
    }
    printf("%i\n",count);
    }
    else 
    goto xyz;
}