#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
LinkedList createList(){
	LinkedList list;
	list.head=NULL;
	list.tail=NULL;
	list.count =0;
	return list;
}
Node* create_node(void* data){
	Node* node = (Node *)malloc(sizeof(node));
	node->data = data;
	node->next = NULL;
	return node;
}
int add_to_list(LinkedList* list,Node* node){
	if(!list->head){
		list->head=node;
	}
	else{
		list->tail->next = node;
	}
	list->tail = node;
	list->count++;
	return 1;
}
void *get_first_element(LinkedList list){
	return list.head->data;
}
void *get_last_element(LinkedList list){
	return list.tail->data;
}
void traverse(LinkedList list, Oprate * oprate){
	Node * walker = list.head;
	while(walker!=NULL){
		oprate(walker->data);
		walker = walker->next;
	}
}

void * getElementAt(LinkedList list, int index){
	int i;
	Node* n =list.head;
	if(index>=list.count){
		return NULL;
	} 
	for(i=0;i<index;i++){
		n=n->next;
	}
	return n->data;
}

int indexOf(LinkedList list, void* data){
	int index=0;
	Node* walker = list.head;  
	while(walker!=NULL){
		if(walker->data == data){
			return index;
		}
		index++;
		walker = walker->next;
	}
	return -1;
}
void * deleteElementAt(LinkedList *list, int index){
	int i;
	void* data;
	Node* current =list->head;
	Node* previousNode=NULL;
	
	if(index>=list->count||index<0){
		return NULL;
	} 

	for(i=0;i<index;i++){
		previousNode = current;
		current=current->next;
	}

	if(list->tail==current){
		list->tail=previousNode;
		list->tail->next=NULL;
	}

	data= current->data;
	previousNode?(previousNode->next =current->next):(list->head =list->head->next);
	
	list->count--;
	free(current);
	return data;
}

int asArray(LinkedList list, void **destination){
	int i;
	for (i=0;i<list.count;i++){
		destination[i]=getElementAt(list,i);
	}
	return i;
}

LinkedList * filter(LinkedList list, predicate * p){
	LinkedList *filterd = (LinkedList*)calloc(sizeof(LinkedList),1);
	Node* walker = list.head;
	while(walker!=NULL){
		if(p(walker->data)){
			add_to_list(filterd,walker);
		}
		walker = walker->next;
	}	
	return filterd;
}
