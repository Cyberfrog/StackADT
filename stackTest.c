#include "expr_assert.h"
#include "stack.h"
#include <stdio.h>

void test_creatStack_initalize_stack_top_filed_null_and_list_has_blank_list(){
	
	Stack s = createStack();
	assert(s.list!=NULL);
	assert(*(s.top)==NULL);
}

void test_push_puts_the_data_in_stack(){
	int data=1,count;
	Stack s = createStack();
	count = push(s,&data);
	assertEqual(count, 1);
	assert((*(s.top))->data==&data);
}
void test_pop_retuns_topmost_element_from_stack(){
	int data1=1,data2 =4,count;
	int * poped;
	Stack s = createStack();
	count = push(s,&data1);
	count = push(s,&data2);
	poped =(int *)pop(s);
	assertEqual(*poped, data2);
	assert((*s.top)->data==&data1);
}