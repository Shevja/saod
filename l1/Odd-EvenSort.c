#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
//устойчивая
double wtime()
{
    struct timeval t;
    gettimeofday (&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void swap(uint32_t* a, uint32_t* b)
{
    int c = *a;
    *a = *b;
    *b = c;
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

void oddeven(uint32_t* a, int n)
{
    int k = 0, x = 0, i;

    while (k < n) {
        for (i = x; i <=  n - 1; i += 2) {
            if (a[i+1] < a[i]) {
                swap(&a[i], &a[i+1]);
                k = 0;
            } else {
                k++;
            }
        }
        x = (x + 1) % 2;
    }
}

int main()
{
    srand(time(NULL));

    int n, i;

    printf("Enter n = ");
    scanf("%d", &n);

    uint32_t a[n];

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100001;
    }

    double t1 = wtime();
    oddeven(a,n);
    double t2 = wtime();
    printf("odd-even = %f sec\n", t2-t1);

    return 0;
}
