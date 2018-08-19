#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorts.h"

// compare functions
int cmp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int cmp_str(const void *a, const void *b)
{
    return strcmp(*(char const **)a, *(char const **)b);
}

typedef struct
{
    int n;
    char name[4];
} Stu;
int cmp_stu(const void *a, const void *b)
{
    return ((Stu *)a)->n - ((Stu *)b)->n;
}

// test for merge sort
void test_msort(void)
{
    int a[5] = {5, 4, 3, 2, 1}, a_temp[5];
    Stu b[3] = {{3, "ab"}, {2, "cd"}, {1, "ef"}}, b_temp[3];
    char **c = malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
        c[i] = malloc(5 * sizeof(char));
    void *temp = malloc(3 * sizeof(char *));

    // initialize strings
    strcpy(c[0], "xy");
    strcpy(c[1], "gr");
    strcpy(c[2], "ab");

    msort(a, a_temp, 0, 5 - 1, sizeof(int), cmp_int);
    msort(b, b_temp, 0, 3 - 1, sizeof(Stu), cmp_stu);
    msort(c, temp, 0, 3 - 1, sizeof(char *), cmp_str);

    assert(a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4]);
    assert(b[0].n < b[1].n && b[1].n < b[2].n);
    assert(strcmp(c[0], c[1]) < 0 && strcmp(c[1], c[2]) < 0);

    for (int i = 0; i < 3; i++)
        free(c[i]);
    free(c);

    printf("Passed: msort\n");
}

// test for quick sort
void test_qsort(void)
{
    int a[5] = {5, 4, 3, 2, 1};
    Stu b[3] = {{3, "ab"}, {2, "cd"}, {1, "ef"}};
    char **c = malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
        c[i] = malloc(5 * sizeof(char));

    // initialize strings
    strcpy(c[0], "xy");
    strcpy(c[1], "gr");
    strcpy(c[2], "ab");

    my_qsort(a, 0, 5 - 1, sizeof(int), cmp_int);
    my_qsort(b, 0, 3 - 1, sizeof(Stu), cmp_stu);
    my_qsort(c, 0, 3 - 1, sizeof(char *), cmp_str);

    assert(a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4]);
    assert(b[0].n < b[1].n && b[1].n < b[2].n);
    assert(strcmp(c[0], c[1]) < 0 && strcmp(c[1], c[2]) < 0);

    for (int i = 0; i < 3; i++)
        free(c[i]);
    free(c);

    printf("Passed: my_qsort\n");
}

// test for insertion sort
void test_isort(void)
{
    int a[5] = {5, 4, 3, 2, 1};
    Stu b[3] = {{3, "ab"}, {2, "cd"}, {1, "ef"}};
    char **c = malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
        c[i] = malloc(5 * sizeof(char));

    // initialize strings
    strcpy(c[0], "xy");
    strcpy(c[1], "gr");
    strcpy(c[2], "ab");

    isort(a, 0, 5 - 1, sizeof(int), cmp_int);
    isort(b, 0, 3 - 1, sizeof(Stu), cmp_stu);
    isort(c, 0, 3 - 1, sizeof(char *), cmp_str);

    assert(a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4]);
    assert(b[0].n < b[1].n && b[1].n < b[2].n);
    assert(strcmp(c[0], c[1]) < 0 && strcmp(c[1], c[2]) < 0);

    for (int i = 0; i < 3; i++)
        free(c[i]);
    free(c);

    printf("Passed: isort\n");
}

int main(void)
{
    test_msort();
    test_qsort();
    test_isort();
}