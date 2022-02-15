#include "sqlist.h"
#include "stdlib.h"
#include "string.h"
sqlink list_create()
{
	sqlink my_sqlink = NULL;
	my_sqlink = malloc(sizeof(sqlist));
	if(my_sqlink)
	{
		memset(my_sqlink->data,0x0,N);
		my_sqlink->last = 0;
		return my_sqlink;
	}
	else
	{
		return NULL;
	}
}

int list_clear(sqlink p)
{
	sqlink mysqlink;
	mysqlink = p;
	if(mysqlink)
	{
		memset(mysqlink,0x0,N);
		return 1;
	}
	else
	{
		return 0;
	}

}

int list_empty(sqlink p)
{
	return 0;
}

int list_length(sqlink p)
{
	return 0;
}

int list_locate(sqlink p,data_t value)
{
 	return 0;
}

int list_insert(sqlink p,data_t value,int pos)
{
 	return 0;
}

