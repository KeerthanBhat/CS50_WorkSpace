#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main( void )
{
    char t[20];
    
    //to get the full name
    string s = get_string();
    int j = 0;
    
    //for cases when first letter in the string is not space
    if( s[ 0 ] != 32 )
    {
        t[0] = toupper( s[0] );
        j++;
    }
    
    //to copy intitials to string t
    for(int i = 0, n = strlen( s ); i < n; i++ )
    {
        
        //checks for space
        if( s[i] == 32 )
        {
            
            //cases when first letter in the string is space
            if( i == 0 )
            {
                while( s[i] == 32 )
                {
                    i++;
                }
            
                i--;
            }
            
            abc:
            //checks for consecutive spaces in the string
            if( s[i + 1] != 32 )
            {
              t[j] = toupper( s[i + 1] );
              j++;
            }
            
            else
            {
                i++;
                goto abc;
            }
            
        }
       
    }
    
    t[j]='\0';
    printf("%s\n", t);

}