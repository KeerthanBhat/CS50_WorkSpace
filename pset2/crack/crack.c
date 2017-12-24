#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

//header files and macro for crypt() function
#include<crypt.h>
#define _XOPEN_SOURCE
#include <unistd.h>


int main( int argc, string argv[] )
{
    
    //checks whether the input is correct
    if( argc != 2 )
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    char salt[2], key[5];
    int count = 0;
    
    //copying first two elements of hashed password to salt
    strncpy( salt, argv[1], 2 );
    
    
    //checking all different 1 letter combination
    //Brute Force technique
    for( int i = 65; i <= 122; i++ )
    {
        
        //transition from upper to lower case
        if( i == 91 )
        {
            i = 97;
        }
        
        //assigning through typecasting
        key[0] = (char) i;
        key[1] = '\0';
        count++;
                    
        //crypting the combination and comparing wih the password crypt
        if( !strcmp( crypt( key, salt ), argv[1] ) )
        {
            printf("%s is the required password!\n",key);
            printf("%d number of comparisons made.\n", count);
            return 0;
        }
    }

        
    //checking all different 2 letter combination
    //Brute Force technique
    for( int i = 65; i <= 122; i++ )
    {
        
        //transition from upper to lower case
        if( i == 91 )
        {
            i = 97;
        }
        
        //assigning through typecasting
        key[0] = (char) i;
        
        for( int j = 65; j <= 122; j++ )
        {
            
            if( j == 91 )
            {
                j = 97;
            }
            
            key[1] = (char) j;
            key[2] = '\0';
            count++;
                    
            //crypting the combination and comparing wih the password crypt
            if( !strcmp( crypt( key, salt ), argv[1] ) )
            {
                printf("%s is the required password!\n",key);
                printf("%d number of comparisons made.\n", count);
                return 0;
            }
        }
    }
    
    
    //checking all different 3 letter combination
    //Brute Force technique
    for( int i = 65; i <= 122; i++ )
    {
        
        //transition from upper to lower case
        if( i == 91 )
        {
            i = 97;
        }
        
        //assigning through typecasting
        key[0] = (char) i;
        
        for( int j = 65; j <= 122; j++ )
        {
            
            if( j == 91 )
            {
                j = 97;
            }
            
            key[1] = (char) j;
            
            for( int k = 65; k <= 122; k++ )
            {
                
                if( k == 91 )
                {
                    k = 97;
                }
                
                key[2] = (char) k;
                key[3] = '\0';
                count++;
                    
                //crypting the combination and comparing wih the password crypt
                if( !strcmp( crypt( key, salt ), argv[1] ) )
                {
                    printf("%s is the required password!\n",key);
                    printf("%d number of comparisons made.\n", count);
                    return 0;
                }
            }
        }
    }
                
    
    //checking all different 4 letter combination
    //Brute Force technique
    for( int i = 65; i <= 122; i++ )
    {
        
        //transition from upper to lower case
        if( i == 91 )
        {
            i = 97;
        }
        
        //assigning through typecasting
        key[0] = (char) i;
        
        for( int j = 65; j <= 122; j++ )
        {
            
            if( j == 91 )
            {
                j = 97;
            }
            
            key[1] = (char) j;
            
            for( int k = 65; k <= 122; k++ )
            {
                
                if( k == 91 )
                {
                    k = 97;
                }
                
                key[2] = (char) k;
                
                for( int l = 65; l <= 122; l++ )
                {
                    
                    if( l == 91 )
                    {
                        l = 97;
                    }
                    
                    key[3] = (char) l;
                    
                    key[4] = '\0';
                    count++;
                    //crypting the combination and comparing wih the password crypt
                    if( !strcmp( crypt( key, salt ), argv[1] ) )
                    {
                     printf("%s is the required password!\n",key);
                     printf("%d number of comparisons made.\n", count);
                     return 0;
                    }
                }
            }
        }
    }
    
    //failed case
    printf("%d number of comparisons made.\n", count);
    printf("Could not decrypt the password!\n");
    return 1;
}