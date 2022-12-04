#include <stdio.h>
#include <stdlib.h>

int bin_search(int* a, int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            return m;
        }
        if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int * i_sort(int * A, int n)
{
    int el;
    int i;
    for (i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            el = bin_search(A, i, A[i]);
            int x = A[i];
            int j;
            for (j = i; j > el; j --)
            {
                A[j] = A[j - 1];
            }
            A[el] = x;
        }
    }
    return A;
}


void myswap(int * x, int * y) 
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int* oe_sort(int * A, int lg) 
{
    int sorted = 0;

    int i;
    while (!sorted) 
    {
        sorted = 1;

        for (i = 1; i < lg; i += 2) 
        {
            if (A[i] > A[i + 1]) 
            {
                myswap(&A[i], &A[i + 1]);
                sorted = 0;
            }   
        }

        for (i = 0; i < lg - 1; i += 2) 
        {
            if (A[i] > A[i + 1]) 
            {
                myswap(&A[i], &A[i + 1]);
                sorted = 0;
            }
        }
    }
    return A;
}

int* gener(int* A, int lg)
{
    A = (int*)calloc(lg, sizeof(int));
    int i, el;
    for (i = 0; i < lg; i ++)
    {
        el = rand() % 100;
        A[i] = el;
        //printf("Have: %d ", A[i]);
    }
    return A;
}

int out(int* A, int lg)
{
    int i;
    for (i = 0; i < lg; i ++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int len;
    scanf("%d", &len);
    int* arr;
    arr = gener(arr, len);
    out(arr, len);

    arr = oe_sort(arr, len);
    out(arr, len);
}
