#include<stdio.h>
#include<cs50.h>

int main(void)
{
    xy:
    printf("Height: ");
    int h = get_int();
    if ( h>=0 && h<=23 )
   {    
    for( int i = 1; i <= h; i++ )
    {
        for( int j = h-i; j > 0; j-- )
         {
             printf(" ");
         }
        for( int k = 0; k < i; k++ )
        {
            printf("#");
        }
        printf("  ");
        for( int k = 0; k < i; k++ )
        {
            printf("#");
        }
        printf("\n");
    }
   }
   else goto xy;
}