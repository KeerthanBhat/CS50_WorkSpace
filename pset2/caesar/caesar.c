#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main( int argc, string argv[] )
{
    
    //checks if the command line argument is correct
    if( argc != 2 )
    {
        printf("Usage: ./caesar k\n");
        exit( 1 );
    }
    
    //converting string into integer using atoi()
    int k = atoi( argv[1] ); 
    k = k % 26;
    
    //input of message to be ciphered
    printf("plaintext:  ");
    string s = get_string();
    
    //printing ciphered message
    printf("ciphertext: ");
    
    for( int i = 0, n = strlen(s); i < n; i++ )
    {
        
        //checks if string charater is an alphabet
        if( isalpha( s[i] ) )
        {
            
            //checks if alphabet is in upper case
            if( isupper( s[ i ] ) )
            {
              
              //when overflowed
              if( ( s[ i ] + k ) > 90 )
              {
                int t = s[ i ] + k - 90;
                printf( "%c", toupper( t + 64 ) );
              }
              else
                printf( "%c", toupper( ( s[ i ] + k ) ) );
            }
            
            //for lower case alphabets
            else
            {
              
              //when overflowed
              if( ( s[ i ] + k ) > 122 )
              {
                int t = s[ i ] + k - 122;
                printf( "%c", tolower( t + 96 ) );
              }
              else 
              printf( "%c", tolower( ( s[ i ] + k ) ) );
            }
        }
        
        //printing characters other than alphabets as it is
        else
        printf("%c", s[ i ] );
    }
    printf("\n");
}