#include <stdio.h>

void radixsort(int *a, int arraySize)
{
    int i, bucket[sortsize], maxVal = 0, digitPosition =1 ;

    for(i = 0; i < arraySize; i++) 
    {
        if(a[i] > maxVal) maxVal = a[i];
    }

    int pass = 1; 
    while(maxVal/digitPosition > 0) 
    {
        int digitCount[10] = {0};

        for(i = 0; i < arraySize; i++)
            digitCount[a[i]/digitPosition%10]++;

        for(i = 1; i < 10; i++)
            digitCount[i] += digitCount[i-1];

        for(i = arraySize - 1; i >= 0; i--)
            bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

        for(i = 0; i < arraySize; i++)
            a[i] = bucket[i];

        cout << "pass #" << pass++ << ": ";
        digitPosition *= 10;
    }

}

int main()
{
    
}