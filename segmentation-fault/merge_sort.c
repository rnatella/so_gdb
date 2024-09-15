/**
 * @file
 * @brief Implementation of [merge
 * sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Swap two integer variables
 * @param [in,out] a pointer to first variable
 * @param [in,out] b pointer to second variable
 */
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Perform merge of segments.
 *
 * @param a array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 */
void merge(int *a, int l, int r, int n)
{
    int *b = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */
    if (b == NULL)
    {
        printf("Can't Malloc! Please try again.");
        exit(EXIT_FAILURE);
    }
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1))
    {
        if (a[p1] <= a[p2])
        {
            b[c++] = a[p1];
            p1++;
        }
        else
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1)
    {
        while ((p1 < ((l + r) / 2) + 1))
        {
            b[c++] = a[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < r + 1))
        {
            b[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) a[c] = b[c];

    free(b);
}

/** Merge sort algorithm implementation
 * @param a array to sort
 * @param n number of elements in the array
 * @param l index to sort from
 * @param r index to sort till
 */
void merge_sort(int *a, int n, int l, int r)
{
    if (r - l == 1)
    {
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
    }
    else if (l != r)
    {
        merge_sort(a, n, l, (l + r) / 2);
        merge_sort(a, n, ((l + r) / 2) + 1, r);
        merge(a, l, r, n);
    }

    /* no change if l == r */
}
/** @} */

#define MAX_DIM 1000

struct dati {
    int array[MAX_DIM];
    int dim;
};

void inizializza_array(struct dati * a)
{
    int n;

    printf("Inserire il numero di elementi desiderato: ");
    scanf("%d", &n);

    if (n <= 0) /* exit program if arraysize is not greater than 0 */
    {
        printf("Deve essere maggiore di 0!\n");
        exit(1);
    }

    if (n >= MAX_DIM)
    {
        printf("Deve essere minore di %d!\n", MAX_DIM);
        exit(1);
    }

    a->dim = n;


    srand(time(NULL));

    for (int i = 0; i < a->dim; i++)
    {
        a->array[i] = rand() % 100;
    }

}

void stampa_array(struct dati * a)
{

    for (int i = 0; i < a->dim; i++)
    {
        printf("%d ", a->array[i]);
    }
    printf("\n");

}



/** Main function */
int main(void)
{
    int n;
    struct dati * a;

    inizializza_array(a);

    printf("Array non ordinato: ");

    stampa_array(a);


    merge_sort(a->array, a->dim, 0, a->dim - 1);


    printf("Array ordinato: ");

    stampa_array(a);


    return 0;
}
