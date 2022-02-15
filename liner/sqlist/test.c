#include "sqlist.h"
#include "stdio.h"
int main()
{
	sqlink mysqlink;
	mysqlink = list_create();
	if(mysqlink)
		printf("list create successed\n");
	else
		printf("list create failed\n");
	
	mysqlink->data[5] = 28;
	printf("test value is %d\n",mysqlink->data[5]);
	if(list_clear(mysqlink))
	{
		printf("list clean finished\n");
		printf("value is %d\n",mysqlink->data[5]);
	}
	else 
		printf("list clean failed\n");
	return 0;
}
