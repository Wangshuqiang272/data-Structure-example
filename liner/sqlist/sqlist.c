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
	int i;
	if(p)
	{
		for(i = 0;i < N;i++)
		{
			if(p->data[i])
			{
				return -1;	
			}		
		}
		return 1;
		
	}
	else
	{	
		return 0;
	}

}

int list_length(sqlink p)
{
	int i,flag = 0;
	if(p)
	{
		for(i = 0;i < N;i++)
		{
			if(p->data[i])
			{
				p->last = i;
				flag = 1;
				break;
			}
		}
		if(flag = 1)
			return p->last;
		else
			return 0;
	}
	else
	{
		return -1;
	}
}

int list_locate(sqlink p,data_t value)
{
	int i;
 	if(p)
	{
		for(i = 0;i < N; i++)
		{
			if(p->data[i] == value)
			{
				return i;	
			}
		}
		return -2;
	}
	else
	{
		return -1;
	}
}

int list_insert(sqlink p,data_t value,int pos)
{
 	return 0;
}

