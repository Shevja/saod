#include "hashtab.h"

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
	FILE *fo = fopen("words.txt", "r");
	if (fo == NULL) {
		printf("НЕТ ФАЙЛА\n");
		return 0;
	}
	char words[200000][25];
	char *w;
	struct listnode *node;

	struct listnode *hashtab[200000];
	hashtab_init(hashtab);

	for (int i = 0; i < 200000; i++) {
		fscanf(fo, "%s", words[i]);
	}
	fclose(fo);
    
	printf("%sЭлементов: \t %sВремя, с \t %sКоллизий: \t Слово:%s\n", RED, GREEN, CYAN, RESET);
	for (int j = 1; j <= 200000; j++) {
		hashtab_add(hashtab, words[j], j);
		if (j % 10000 == 0) {
			w = words[getrand(0, j - 1)];
            double t = wtime();
			node = hashtab_lookup(hashtab, w);
            t = wtime() - t;
            printf("n = %d; time = %.6lf\n", j, t);
		}
		// Подсчет коллизий
		if (j % 10000 == 0) {
			unsigned int collision;
			collision = 0;
			for (int i = 0; i < j; i++) {
				if (hashtab[i] != NULL) {
					struct listnode *trp = hashtab[i];
					while (trp->next != NULL) {
						collision++;
						trp = trp->next;
					}
				}
			}
			printf("%d\t\t ", collision);
			printf("%s\n",node->key);
		}
	}
	return 0;
}