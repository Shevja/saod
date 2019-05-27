#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>

//не устойчивая на месте
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

void heapify(uint32_t *a, int i, int n)
{
    int max = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((left < n) && (a[left] > a[max])) {
        max = left;
    }
    if ((right < n) && (a[right] > a[max])) {
        max = right;
    }
    if (max != i) {
        swap(&a[i], &a[max]);
        heapify(a, max, n);
    }
}

void heap(uint32_t *a, int n)
{
    int i;

    for (i = (n/2) - 1; i >= 0; i--) {
        heapify(a, i, n);
    }
    for (i = n - 1; i >= 0; i--) {
        swap(&a[i], &a[0]);
        heapify(a, 0, i);
    }
}

int main()
{
    srand(time(NULL));

    int n, i;

    printf("Введите n = ");
    scanf("%d", &n);

    uint32_t b[n];

    for (i = 0; i < n; i++)
    {
        b[i] = rand() % 100001;
    }

    double t1 = wtime();
    heap(b, n);
    double t2 = wtime();
    printf("heapsort = %f sec\n", t2-t1);

    return 0;
}
