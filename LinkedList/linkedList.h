typedef struct linkedList LinkedList;
typedef struct node Node;
typedef void (Oprate)(void *data);
typedef int (predicate)(void *data);
struct linkedList{
	Node* head;
	Node* tail;
	int count;
};
struct node
{
	void* data;
	Node* next;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void traverse(LinkedList, Oprate *);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **);
LinkedList * filter(LinkedList, predicate *);
