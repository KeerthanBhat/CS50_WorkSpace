/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */


bool search(int value, int values[], int n)
{
    
    //Binary search 
    
    //if search number is negative then return
    if( value < 0 )
    {
        return false;
    }
    
    
    int beg = 0, end = n-1, mid;
    
    while( beg <= end )
    {
        mid = ( beg + end ) / 2;
        
        if( values[mid] == value )
        {
            return true;
        }
        else
        {
            //if element is in the right half
            if( values[mid] < value )
            {
                beg = mid + 1;
            }
            
            //if element is in the left half
            else end = mid - 1;
        }
    }
   
   //if element not found
   return false;
}


/**
 * Sorts array of n values.
 */


void sort(int values[], int n)
{
    
    //Counting sort
    
    int max = values[0];
    for( int i = 0; i < n; i++ )
    {
        //determining the maximum element
        if( values[i] > max )
        {
            max = values[i];
        }
    }
    
    
    //very much essential as we have max+1 number of elements in count array 
    max = max + 1;
    
    //putting elements into the count array
    int count[max];
    for( int i = 0; i < max; i++ )
    {
        count[i] = 0;
        
        for( int j = 0; j < n; j++ )
        {
            if( values[j] == i )
            {
                count[i]++;
            }
        }
    }
    
    //sorting the input array
    for( int i = 0, k = 0; i < n; )
    {
        for( int j = 0; j < count[k]; j++ )
        {
            values[i] = k;
            i++;
        }
        k++;
    }
}
