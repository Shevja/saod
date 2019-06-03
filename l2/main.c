#include "bstree.h"
#include "hashtab.h"

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED   "\033[1;31m"
#define CYAN  "\033[1;36m"

int main() {
    struct bstree *tree, *node;
    char words[200000][25];
    char *w;
    struct listnode *hnode;
    struct listnode *hashtab[200000];
    int j = 1, n = 1, choose = 0;
    hashtab_init(hashtab);
    FILE *fo = fopen("words.txt", "r");
    if (fo == NULL) {
        printf("НЕТ ФАЙЛА\n");
        return 0;
    }
    for (int i = 0; i < 200000; i++) {
        fscanf(fo, "%s", words[i]);
    }
    fclose(fo);
    printf("Choose ur experiment:\n 1-treelookup\n 2-hashlookup\n 3-treeadd\n 4-hashadd\n ");
    scanf("%d", &choose);
    if (choose == 1) {
        tree = bstree_create(words[0], 0);
        printf("%s\t\t\tBSTREE LOOKUP%s\n", RED, RESET);
        printf("%sЭлементов: \t %sВремя, с \t Слово:%s\n", RED, GREEN, RESET);
        for (int i = 1; i <= 200000; i++) {
            bstree_add(tree, words[i], i);
            if (i % 10000 == 0) {
                w = words[rand() % i];
                double begin_1 = clock();
                srand(time(NULL));
                node = bstree_lookup(tree, w);
                double end_1 = clock();
                double time = difftime(end_1, begin_1) / 1000000;
                printf("%d\t\t %f\t ", i, time);
                printf("%s\n", node->key);
            }
        }
    } else if (choose == 2) {
        printf("%s\t\t\tHASHTAB LOOKUP%s\n", RED, RESET);
        printf("%sЭлементов: \t %sВремя, с \t %sКоллизий: \t Слово:%s\n", RED, GREEN, CYAN, RESET);
        for (int i = 1; i <= 200000; i++) {
            hashtab_add(hashtab, words[i], i);
            if (i % 10000 == 0) {
                w = words[rand() % i];
                double begin_1 = clock();
                srand(time(NULL));
                hnode = hashtab_lookup(hashtab, w);
                double end_1 = clock();
                double time = difftime(end_1, begin_1) / 1000000;
                printf("%d\t\t %f\t ", i, time);
            }
            if (i % 10000 == 0) {
                unsigned int collision;
                collision = 0;
                for (int f = 0; f < i; f++) {
                    if (hashtab[f] != NULL) {
                        struct listnode *trp = hashtab[f];
                        while (trp->next != NULL) {
                            collision++;
                            trp = trp->next;
                        }
                    }
                }
                printf("%d\t\t ", collision);
                printf("%s\n", hnode->key);
            }
        }
    } else if (choose == 3) {
        tree = bstree_create(words[0], 0);
        printf("%s\t\t\tBSTREE ADD%s\n", RED, RESET);
        printf("%sЭлементов: \t %sВремя, с \t Слово:%s\n", RED, GREEN, RESET);
        for (int i = 1; i <= 200000; i++) {
            bstree_add(tree, words[i], i);
            if (i % 10000 == 0) {
                w = words[rand() % i];
                double begin_1 = clock();
                srand(time(NULL));
                bstree_add(tree, w, n + 200000);
                double end_1 = clock();
                double time = difftime(end_1, begin_1) / 1000000;
                printf("%d\t\t %f\t ", i, time);
                printf("%s\n", w);
                n++;
            }
        }
    } else if (choose == 4) {
        printf("%s\t\t\tHASHTAB ADD%s\n", RED, RESET);
        printf("%sЭлементов: \t %sВремя, с \t Слово:%s\n", RED, GREEN, RESET);
        for (int i = 1; i <= 200000; i++) {
            hashtab_add(hashtab, words[i], i);
            if (i % 10000 == 0) {
                w = words[rand() % i];
                double begin_1 = clock();
                srand(time(NULL));
                hashtab_add(hashtab, w, j + 200000);
                double end_1 = clock();
                double time = difftime(end_1, begin_1) / 1000000;
                printf("%d\t\t %f\t ", i, time);
                printf("%s\n", w);
                j++;
            }
        }
    }
    return 0;
}