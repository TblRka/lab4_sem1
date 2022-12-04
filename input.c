#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct User{
    char* name;
    char* adr;
    int time;
} User;

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

char *myreadline()
{
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do
    {
        n = scanf("%80[^\n]", buf);
        if (n < 0)
        {
            if (!res) 
            {
                return NULL;
            }
        } else if (n > 0) 
        {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else 
        {
            scanf("%*c");
        }

    }while (n > 0);

    if (len > 0) 
    {
        res[len] = '\0';
    } else 
    {
        res = calloc(1, sizeof(char));
    }
    return res;

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

User* std_input(User* p, int* n)
{
    if (p)
    {
        myfree(p, *n);
    }

    scanf("%d", n);
    p = (User*)calloc(*n, sizeof(User));
    
    int i;
    for (i = 0; i < *n; i ++)
    {
        scanf("%*c");
        p[i].name = myreadline();

        p[i].adr = myreadline();
        int k = 0;
        while (!k)
        {
            //printf("%d\n", strlen(b));
            if (strlen(p[i].adr) != 17 || p[i].adr[2] != '-' || p[i].adr[5] != '-' || p[i].adr[8] != '-' || p[i].adr[11] != '-' || p[i].adr[14] != '-')
            {
                printf("Error, please try again: ");
                p[i].adr = myreadline();
            }
            else
            {
                k += 1;
            }    
        }
        scanf("%d", &p[i].time);
        //printf("name: %s ", p[i].name);
        //printf("adr: %s ", p[i].adr);
        //printf("time: %d\n", p[i].time);
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

User* insert(User* A, int* n, int ind)
{
    User* copy;
    copy  = (User*)calloc(*n + 1, sizeof(User));
    int i;
    for (i = 0; i < *n + 1; i++)
    {
        if (i < ind)
        {
            copy[i] = A[i];
        }
        else if (i > ind)
        {
            copy[i] = A[i - 1];
        }
        else if (i == ind)
        {
            //scanf("%*c");
            copy[i].name = myreadline();
            copy[i].adr = myreadline();
            scanf("%d", &copy[i].time);
        }
    }
    *n = *n + 1;
    return copy;
}

User* del(User* A, int* n, int ind, int *lg)
{
    User* copy;
    if (ind + *lg > *n)
    {
        *lg = *n - ind;
    }

    copy  = (User*)calloc(*n - *lg, sizeof(User));
    int i;
    for (i = 0; i < *n; i++)
    {
        if (i < ind)
        {
            copy[i] = A[i];
        }
        else if (i >= ind + *lg)
        {
            copy[i - *lg] = A[i];
        }
    }
    *n = *n - *lg;
    return copy;
}

void f_out(User* A, int n)
{
    printf("1\n");
    scanf("%*c");
    char* f = myreadline();
    FILE* GK = fopen(f, "w");
    fprintf(GK,"%d\n", n);
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(GK,"%s\n%s\n%d\n", A[i].name, A[i].adr, A[i].time);
    }
    free(f);
    fclose(GK);
    return;
}

char* freadline(FILE * A)
{
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do
    {
        n = fscanf(A, "%80[^\n]", buf);
        if (n < 0)
        {
            if (!res) 
            {
                return NULL;
            }
        } else if (n > 0) 
        {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else 
        {
            fscanf(A, "%*c");
        }

    }while (n > 0);

    if (len > 0) 
    {
        res[len] = '\0';
    } else 
    {
        res = calloc(1, sizeof(char));
    }
    return res;
}

User* f_input(User* A, int* n)
{
    if (A)
    {
        myfree(A, *n);
    }

    char* f = myreadline();
    printf("File: %s\n", f);

    FILE* GK = fopen(f, "r");
    fscanf(GK, "%d", n);
    printf("%d\n", *n);

    A = (User*)calloc(*n + 1, sizeof(User));

    fscanf(GK, "%*c");
    int i;
    for (i = 0; i < *n; i++)
    {
        A[i].name = freadline(GK);
        A[i].adr = freadline(GK);
        fscanf(GK, "%d%*c", &(A[i].time));
    }
    free(f);
    fclose(GK);
    return A;
}

int main()
{
    User* test = NULL;
    User* test1;
    int len = 0;

    test = rand_input(test, &len);
    s_out(test, len);
    //f_out(test, len);
    int ix, lo;

    scanf("%d", &ix);
    scanf("%d", &lo);

    test = del(test, &len, ix, &lo);
    s_out(test, len);

    //test1 = insert(test, &len, ix);
    //s_out(test1, len);
}