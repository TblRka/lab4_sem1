typedef struct User{
    char* name;
    char* adr;
    int time;
} User;

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
            scanf("%*c");
            copy[i].name = myreadline();
            copy[i].adr = myreadline();
            scanf("%d", &copy[i].time);
        }
    }
    return copy;
}

User* delete(User* A, int* n, int ind, int lg)
{
    User* copy;
    copy  = (User*)calloc(*n - lg, sizeof(User));
    int i;
    for (i = 0; i < *n; i++)
    {
        if (i < ind)
        {
            copy[i] = A[i];
        }
        else if (i >= ind + lg)
        {
            copy[i - lg] = A[i];
        }
    }
    return copy;
}