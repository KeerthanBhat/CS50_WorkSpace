#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    printf("Number: ");
    long long l = get_long_long(), t1;
    t1 = l;
    int sum = 0, d, n = 0;
    while( t1 != 0 )
    {
        n++;
        t1 = t1 / 10;
    }
    t1 = l;
    for( int i = 1; l != 0; i++ )
    {
        d = l % 10;
        if( i % 2 != 0 )
        {
            sum = sum + d;
        }
        else
        {
            d = d * 2;
            while( d != 0 )
            {
                int t2 = d % 10;
                sum = sum + t2;
                d = d / 10;
            }
        }
        l = l / 10;
    }

    if( sum % 10 == 0 )
    {
        if( n == 15 )
        t1 = t1 / 100000000000000;
        if( n == 16 )
        t1 = t1 / 1000000000000000;
        switch(t1)
        {
            case 3: printf("AMEX\n");
                    break;
            case 4: printf("VISA\n");
                    break;
            case 5: printf("MASTERCARD\n");
                    break;
            default: printf("INVALID\n");
        }
    }
    else
    printf("INVALID\n");
}