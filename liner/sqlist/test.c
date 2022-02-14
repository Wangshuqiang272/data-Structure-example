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

	return 0;
}
