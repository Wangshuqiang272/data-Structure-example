
#ifndef SQLIST_H
#define SQLIST_H

typedef int data_t;

#define N 128

typedef struct sqlist_t
{
	data_t data[N];
	data_t last;
}sqlist,*sqlink;

sqlink list_create();
int list_clear(sqlink p);
int list_empty(sqlink p);
int list_length(sqlink p);
int list_locate(sqlink p,data_t vaule);
int list_insert(sqlink p,data_t value,data_t pos);


#endif

