#include <stdio.h>
#include <stdlib.h>

void MissingNumber( int nums[], int size ){
    int arrayValuesSum = 0;
    int expectedSum = 0;
    printf( "\n\nInput: [" );
    for( int i = 0; i < size+1; i++ ) {
        if( i < size ) {
            arrayValuesSum += nums[i];
            if( i != size-1 )
                printf( "%d, ", nums[i] );
            else
                printf( "%d", nums[i] );

        }
        expectedSum += i;
    }

    printf( "]\nMissing value in interval [0,%d]: %d", size, expectedSum - arrayValuesSum );
}

int main( int argc, char const *argv[] )
{
    int nums[10] = {1,4,3,2,7,9,10,0,5,8};
    MissingNumber( nums, 10 );


    int nums2[6] = {6,3,0,1,2,5};
    MissingNumber( nums2, 6 );

    int nums3[7] = {6,3,1,4,2,5,7};
    MissingNumber( nums3, 7 );

    return 0;
}
