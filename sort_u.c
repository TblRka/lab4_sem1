#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "head1.h"

void u_swap(void * a, void * b)
{
    User tmp;
    User* x = (User* )a;
    User* y = (User* )b;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int comp_name(void* x, void * y)
{
    return strcmp(((User*)x)->name, ((User*)y)->name);
}

int comp_adr(void* x, void * y)
{
    return strcmp(((User*)x)->adr, ((User*)y)->adr);
}

int comp_time(void* x, void* y)
{
    return ((User*)x)->time - ((User*)y)->time;
}

void oe_sort(void* A, int lg, int size, int (*comp)(void *, void *)) 
{
    int sorted = 0;

    int i;
    while (!sorted) 
    {
        sorted = 1;
        for (i = 1; i < lg; i += 2) 
        {
            if (comp(A + i * size, A + (i + 1) * size) > 0) 
            {
                u_swap(A + i * size, A + (i + 1) * size);
                sorted = 0;
            }   
        }

        for (i = 0; i < lg - 1; i += 2) 
        {
            if (comp(A + i * size, A + (i + 1) * size) > 0) 
            {
                u_swap(A + i * size, A + (i + 1) * size);
                sorted = 0;
            }
        }
    }
}

int bin_search(void* a, int n, void* x, int s, int (*cmp)(void *, void *)) 
{
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (cmp(a + m * s, x) == 0) 
        {
            return m;
        }
        if (cmp(a + m * s, x) < 0) 
        {
            l = m + 1;
        } 
        else 
        {
            r = m - 1;
        }
    }
    return l;
}

void i_sort(void* A, int n, int size, int (*comp)(void *, void *))
{
    int el;
    int i;
    for (i = 1; i < n; i++)
    {
        if (comp(A + i * size, A + (i - 1) * size) < 0)
        {
            el = bin_search(A, i, A + i * size, size, comp);
            int j;
            for (j = i; j > el; j --)
            {
                u_swap(A + j * size , A + (j - 1) * size);
            }
        }
    }
}

User* rand_input(User* p, int* n)
{
    if (p)
    {
        myfree(p, *n);
    }
    
    printf("Enter size: ");
    scanf("%d", n);
    srand(time(NULL));
    p = (User*)calloc(*n, sizeof(User));

    int i;
    for (i = 0; i < *n; i ++)
    {
        char* im;
        
        int l;
        l = 1 + rand() % 10;
        im = (char*)calloc(l + 1, sizeof(char));

        int j, el;
        for (j = 0; j < l; j ++)
        {
            el = 65 + rand() % 58;
            im[j] = (char)(el);           
        }
        //strcpy(p[i].name, im);
        p[i].name = im;

        char* id;
        id = (char*)calloc(18, sizeof(char));

        int j1, el1;
        for (j1 = 0; j1 < 17; j1 ++)
        {
            if ( j1 % 3 != 2)
            {
                int r;
                r = rand() % 2;
                if (r == 1)
                {
                    el1 = 48 + rand() % 10;
                }
                else
                {
                    el1 = 65 + rand() % 6;
                }
                id[j1] = (char)(el1);
            }
            else
            {
                id[j1] = (char)(45);
            }
        }
        p[i].adr = id;

        int el2;
        el2 = rand() % 10000;
        p[i].time = el2;
    }
    return p;
}

int s_out(User * A, int n)
{
    int i;
    for (i = 0; i < n; i++ )
    {
        printf("%10s\t", A[i].name);
        printf("%s\t", A[i].adr);
        printf("%4d\n", A[i].time);
    }
    return 0;
} 

void myfree(User* A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(A[i].name);
        free(A[i].adr);
    }
    free(A);
}

void heapify(void* A, int n, int i, int s, int(*cmp)(void *, void *)) 
{
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && cmp(A + l * s, A + big * s) > 0)
    {
        big = l;
    }
    if (r < n && cmp(A + r * s, A + big * s) > 0) 
    {
        big = r;
    }
    
    if (big != i) 
    {
        u_swap(A + i * s, A + big * s);
        heapify(A, n, big, s, cmp);
    }
}

void h_sort(void *A, int n, int size, int(*comp)(void *, void *)) 
{
    int i;
    
    for (i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(A, n, i, size, comp);
    }

    for (i = n - 1; i >= 0; i--) 
    {
        u_swap(A, A + i * size);
        heapify(A, i, 0, size, comp);
    }
}

int main()
{
    User* test = NULL;
    int len = 0;

    test = rand_input(test, &len);
    s_out(test, len);

    printf("\n");
    h_sort(test, len, sizeof(User), comp_name);

    s_out(test, len);
}