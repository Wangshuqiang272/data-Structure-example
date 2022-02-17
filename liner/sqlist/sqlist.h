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

/**
*	@brief judgment whether the list empty
*	@param the handle of waiting clear list
*	@return  0 -> param Wrong
*		-1 -> Not empty
*		 1 -> empty 
*/
int list_empty(sqlink p);
/**
*	@brief calculate the length of list
*	@param the handle of waiting clear list
*	@return -1 -> param Wrong
*		x -> the length of list 
*/
int list_length(sqlink p);
/**
*	@brief confirm the special value's location in the list
*	@param the handle of waiting clear list
*	@return  -1 -> param wrong
*		 -2 -> didn't find 
*		  x -> location  
*/
int list_locate(sqlink p,data_t vaule);
int list_insert(sqlink p,data_t value,data_t pos);


#endif

