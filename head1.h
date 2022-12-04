#ifndef LAB4_HEAD_H
#define LAB4_HEAD_H

//структура
typedef struct User{
    char* name;
    char* adr;
    int time;
} User;

//ввод
User* rand_input(User* p, int* n);
User* std_input(User* p, int* n);
User* f_in(User* A, int* n);

//обработка
User* insert(User* A, int* n, int ind);
User* del(User* A, int* n, int ind, int *lg);

//очистка массива
void myfree(User* A, int n);

//вывод
void file_out(User* A, int n);
int s_out(User * A, int n);

//ввод строки
char* myreadline();


//компараторы и свап
void u_swap(void * a, void * b);
int comp_name(void* x, void * y);
int comp_adr(void* x, void * y);
int comp_time(void* x, void* y);

//четно-нечетная
void oe_sort(void* A, int lg, int size, int (*comp)(void *, void *));

//вставкой с бинарным 
int bin_search(void* a, int n, void* x, int s, int (*cmp)(void *, void *));
void i_sort(void* A, int n, int size, int (*comp)(void *, void *));

//кучей
void heapify(void* A, int n, int i, int s, int(*cmp)(void *, void *));
void h_sort(void *A, int n, int size, int(*comp)(void *, void *));

#endif