#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(){
	LinkedList *  list= calloc(sizeof(LinkedList),1);
	Stack s = {list,&list->tail};
	return s;
}

int push(Stack s,void* data){
	int added = add_to_list(s.list, create_node(data));
	if(!added){
		return -1;
	}
	return s.list->count;
}

void * pop(Stack s){
	return deleteElementAt(s.list,s.list->count-1);
}