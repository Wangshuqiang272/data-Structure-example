/*****************************************
*Copyright:XXXX.Co.,Ltd
*Filename:sqlist.h
*Author:WSQ
*Version:0.0.1
*Date:
*Others:Function return 1 means NoWrong,meanwhile,0 means failed 
******************************************/
#ifndef SQLIST_H
#define SQLIST_H

typedef int data_t;

#define N 128

typedef struct sqlist_t
{
	data_t data[N];
	data_t last;
}sqlist,*sqlink;
/**
*	@brief create a new list
*	@param void 
*	@return the handle of new list
*/
sqlink list_create();
/**
*	@brief clear the data of special list
*	@param the handle of waiting clear list
*	@return 0 -> failed 1 -> succeed 
*/
int list_clear(sqlink p);

int list_empty(sqlink p);
int list_length(sqlink p);
int list_locate(sqlink p,data_t vaule);
int list_insert(sqlink p,data_t value,data_t pos);


#endif

