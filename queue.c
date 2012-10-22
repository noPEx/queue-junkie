#include <stdio.h>
#include <stdlib.h>

typedef struct {
	struct node* next ;
	int value ;

} node ;


/* given a node prints all the nodes */
/* parameters
	@head :
		head of the linked list
*/
void print_nodes( node* head ){
	node* oldhead = head ;
	while( head ) {
		printf("%d-> ",head->value ) ;
		head = head->next ;

	}
	printf("\n") ;
}

/* given the tail of the queue append a number */
/*
	parameters
		@tail_add_Ptr:
			it is the address of the head, head is itself a address :P
*/
void enqueue( node** tail_add_Ptr, int n ) {
	node* new = ( node* )malloc( sizeof( node ) ) ;
	new->value = n ;
	new->next = NULL ;
	(*tail_add_Ptr)->next = new ;
	*tail_add_Ptr = (*tail_add_Ptr)->next ;

}

/* dequeues the first element in the queue LIFO : first appended remove first */
void dequeue( node** head_add_Ptr ) {
	*head_add_Ptr = (*head_add_Ptr)->next ;
}

void initialize( node** head_add_Ptr, node** tail_add_Ptr, int arr[],int size ) { // add is address
	node* temp_head = NULL ;
	node* temp_tail = NULL ;

	temp_head = ( node* )malloc( sizeof( node ) ) ;
	temp_head->value = arr[0] ;
	temp_tail = temp_head ;
	temp_tail->next = NULL ;
	int i ;
	for( i = 1 ; i < size ; i++ ) {
		node* new  = ( node* )malloc( sizeof( node ) ) ;
		new->value = arr[i] ;
		new->next = temp_tail->next ;
		temp_tail->next = new ;
		temp_tail = temp_tail->next ;
	}

	*head_add_Ptr = temp_head ;
	*tail_add_Ptr = temp_tail ;

}
int main( int argc,char** argv ) {
	
	int arr[] = {1,2,3,4,5 } ;
	node* head = NULL ;
	node* tail = NULL ;

	initialize( &head, &tail, arr, 5 ) ;

	printf("nodes in list are :\n");
	print_nodes( head ) ;
	enqueue( &tail,6 ) ;
	print_nodes( head ) ;
	dequeue( &head ) ;
	printf("after dequeuing 1 element queue becomes\n");
	print_nodes( head ) ;


	return 0 ;
}
