void heapify(void* A, int n, int i, int size, int(*comp)(void *, void *)) 
{
    int big = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && comp(A + left * size, A + big * size) > 0)
    {
        big = left;
    }
    if (right < n && comp(A + right * size, A + big * size) > 0) 
    {
        big = right;
    }
    
    if (big != i) 
    {
        u_swap(A + i * size, A + big * size);
        heapify(A, n, big, size, comp);
    }
}

void heap_sort(void *A, int n, int size, int(*comp)(void *, void *)) 
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
