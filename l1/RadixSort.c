#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
//lsd не устойчивая
double wtime()
{
    struct timeval t;
    gettimeofday (&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int max(uint32_t *a, int n)
{
    int num = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > num) {
            num = a[i];
        }
    }
    return num;
}

void radix(uint32_t *a, int n)
{
    int i, semi[n], d = 1;
    int num = max(a, n);

    while (num/d > 0) {
        int bucket[10] = {0};

        for (i = 0; i < n; i++) {
            bucket[(a[i]/d) % 10]++;
        }
        for (i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        for (i = n - 1; i >= 0; i--) {
            semi[--bucket[(a[i]/d) % 10]] = a[i];
        }
        for (i = 0; i < n; i++) {
            a[i] = semi[i];
        }

        d *= 10;
    }
}

int main()
{
    srand(time(NULL));

    int n, i;

    printf("Enter n = ");
    scanf("%d", &n);

    uint32_t c[n];

    for (i = 0; i<n; i++)
    {
       c[i] = rand() % 100001;
    }
    double t1 = wtime();

    radix(c, n);

    double t2 = wtime();

    printf("radixsort = %f sec\n", t2-t1);

    return 0;
}

