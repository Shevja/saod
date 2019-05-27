#include "bstree.h"
#include <sys/time.h>
#include <string.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main() {
	struct bstree *tree, *node;
	char words[200000][25];
	char *w;
    char file[25];

    printf("Функция bstree_lookup\n");
	FILE *op_f = fopen("wars.txt", "r");
	if (op_f == NULL) {
		printf("НЕТ ФАЙЛА\n");
		return 0;
	}
	for (int i = 0; i < 200000; i++) {
		fscanf(op_f, "%s", words[i]);
	}
	fclose(op_f);

    tree = bstree_create(words[0], 0);
    for (int i = 2; i <= 200000; i++) {
        bstree_add(tree, words[i - 1], i - 1);
        if (i % 10000 == 0) {
            w = words[getrand(0, i - 1)];
            double t = wtime();
            node = bstree_lookup(tree, w);
            t = wtime() - t;
            printf("n = %d; time = %.6lf\n", i, t);
        }
    }
    printf("\n");
    
    printf("Функция bstree_max(с)\n");
	op_f = fopen("wars.txt", "r");
	if (op_f == NULL) {
		printf("НЕТ ФАЙЛА\n");
		return 0;
	}
	for (int i = 0; i < 200000; i++) {
		fscanf(op_f, "%s", words[i]);
	}
	fclose(op_f);
    
    tree = bstree_create(words[0], 0);
    for (int i = 2; i <= 200000; i++) {
        bstree_add(tree, words[i - 1], i - 1);
        if (i % 10000 == 0) {
            double t = wtime();
            node = bstree_max(tree);
            t = wtime() - t;
            printf("n = %d; time = %.6lf\n", i, t);
        }
    }
    printf("\n");
    
    printf("Функция bstree_max(х)\n");

	op_f = fopen("warh.txt", "r");
	if (op_f == NULL) {
		printf("НЕТ ФАЙЛА\n");
		return 0;
	}
	for (int i = 0; i < 200000; i++) {
		fscanf(op_f, "%s", words[i]);
	}
	fclose(op_f);
    
    tree = bstree_create(words[0], 0);
    for (int i = 2; i <= 200000; i++) {
        bstree_add(tree, words[i - 1], i - 1);
        if (i % 10000 == 0) {
            double t = wtime();
            node = bstree_max(tree);
            t = wtime() - t;
            printf("n = %d; time = %.6lf\n", i, t);
        }
    }

	return 0;
}