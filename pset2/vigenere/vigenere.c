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
    
    //checks if the keyword has only letters
    for(int i = 0, n = strlen( argv[1] ); i < n; i++ )
        {
          if( !isalpha( argv[1][i] ) )
          {
            printf("Usage: ./vigenere k\n");
            exit( 1 );
          }
        }
    
    
    //input of message to be ciphered
    printf("plaintext: ");
    string s = get_string();
    
    //printing ciphered message
    printf("ciphertext: ");
    
    for( int i = 0, k = 0, temp , n = strlen(s); i < n; i++ )
    {
        
        //checks for overflow in the keyword
        if( argv[1][k] == '\0' )
        {
          k = 0;
        }
        
        //checks the case of the keyword letters and assigns temp 
        if( isupper( argv[1][k] ) )
        {
          temp = 65;
        }
        else
          temp = 97;
        
        
        //checks if string charater is an alphabet
        if( isalpha( s[i] ) )
        {
            
            //checks if alphabet is in upper case
            if( isupper( s[ i ] ) )
            {
              
              //when overflowed
              if( ( s[ i ] + argv[1][k] - temp  ) > 90 )
              {
                int t = s[ i ] + argv[1][k] - temp - 90;
                printf( "%c", toupper( t + 64 ) );
                k++;
              }
              else
                {
                  printf( "%c", toupper( ( s[ i ] + argv[1][k] - temp ) ) );
                  k++;
                }
            }
            
            //for lower case alphabets
            else
            {
              
              //when overflowed
              if( ( s[ i ] + argv[1][k] - temp) > 122 )
              {
                int t = s[ i ] + argv[1][k] - temp - 122;
                printf( "%c", tolower( t + 96 ) );
                k++;
              }
              else 
              {
                printf( "%c", tolower( ( s[ i ] + argv[1][k] - temp ) ) );
                k++;
              }
            }
        }
        
        //printing characters other than alphabets as it is
        else
        printf("%c", s[ i ] );
    }
    printf("\n");
}