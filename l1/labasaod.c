#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void shar(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}


int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}

void swap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}

void swapforoe (int a, int b)
{
    int temple = 0;
    temple = a;
    a = b;
    b = temple;
}

void oddEvenSort(int arr[], int n)
{
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;

        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swapforoe(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swapforoe(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }

    return;
}

void heapSort (int *a, int n) {
    int i;
    
    for (i = (n - 2) / 2; i >= 0; i--) {
        swap(a, n, i);
    }
    
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        swap(a, n - i - 1, 0);
    }
}

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  

void countSort(int arr[], int n, int exp) 
{ 
    int output[n];  
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++){ 
        count[ (arr[i]/exp)%10 ]++; 
    }
   
    for (i = 1; i < 10; i++){ 
        count[i] += count[i - 1]; 
    } 
   
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
   
    for (i = 0; i < n; i++){ 
        arr[i] = output[i]; 
    }
}
  

void radixsort(int arr[], int n) 
{ 
    
    int m = getMax(arr, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10){ 
        countSort(arr, n, exp); 
    }
}


void Count_time(unsigned int n, FILE *sort)
{
    int *arr = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		arr[i] = getrand(0, 100000);
	}
	double htime = wtime();
    heapSort(arr, n);
	htime = wtime() - htime;
	double stime = wtime();
    oddEvenSort(arr, n);
    stime = wtime() - stime;
    double rtime = wtime();
    radixsort(arr, n);
    rtime = wtime() - rtime;


	fprintf(sort, "%d %f %f %f\n", n, htime, stime, rtime);
}

int main()
{
    FILE *sort = fopen("sort.dat", "w");
    for(int i = 1; i <= 20; i++)
    {
		Count_time(i * 5000, sort);
    }
    fclose(sort);
    return 0;
}
