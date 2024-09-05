//Q1.Doubly Linked List Operations with one External Reference pointer
//Name: SUHANA MIRASAB PENDHARI
//Roll No: 2020
//Class: SYB.Tech CSE Div: A
//Batch: S2

#include<stdio.h>
#include<stdlib.h>
//Structure to create node;
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
typedef struct Node NODE;
NODE *start = NULL, *p, *q;

//Create at start
void addFirst(int data){
	if(start == NULL){
			p->next = NULL;
			p->prev = NULL;
			start = p;
		}else{
			p->next = start;
			start->prev = p;
			p->prev = NULL;
			start = p;
		}
}

//Create at end
void addLast(int data){
	if(start == NULL){
			p->next = NULL;
			p->prev = NULL;
			start = p;
		}else{
			 q = start;
			while(q->next != NULL){
				q = q->next;
			}
			q->next = p;
			p->prev = q;
			p->next = NULL;
		}
}

//Create at Given Location
void addAt(int loc, int data){
	if(start == NULL){
		if(loc == 1){
			p->next = NULL;
			p->prev = NULL;
			start = p;
		}else{
			printf("\nInvalid Location....");
			free(p);
		}
	}else{
		if(loc == 1){
			p->next = start->next;
			p->prev = NULL;
			start->prev = p;
			start = p;
		}else{
			int i=1;
			q = start;
			while(i<loc-1 && q != NULL){
				q = q->next;
				i++;
			}
			if(q != NULL){
				p->next = q->next;
				if(q->next != NULL)
					q->next->prev = p;
				p->prev = q;
				q->next = p;
			}else{
				printf("\nInvalid Location...");
				free(p);
			}
		}
	}
}

//delete at start
void deleteFirst(){
	if(start == NULL){
		printf("\nLinked List is empty Nothing is to delete...");
	}else
	if(start->next == NULL){
		p = start;
		start = NULL;
		printf("\n%d is deleted.", p->data);
		free(p);
	}else{
		p = start;
		start = start->next;
		start->prev = NULL;
		printf("\n%d is deleted", p->data);
		free(p);
	}
}

//delete at End
void deleteLast(){
	if(start == NULL){
		printf("\nLinked List is empty Nothing is to delete...");
	}else{
		if(start->next == NULL){
			p = start;
		 	start = NULL;
			printf("\n%d is deleted", p->data);
			free(p);
		}else{
			p = start;
			while(p->next != NULL){
				q = p;
				p = p->next;
			}
			q->next = NULL;
			printf("\n%d is deleted", p->data);
			free(p);
		}
	}
}

//Delete at given location
void deleteAt(int loc){
	if(start == NULL){
		printf("\nLinked List is empty Nothing is to delete...");
	}else{
		if(loc == 1){
			p = start;
			start = start->next;
			printf("\n%d is deleted", p->data);
			free(p);
		}else{
			int i=1;
			p = start;
			while(i<loc && p != NULL){
				q = p;
				p = p->next;
				i++;
			}
			if(p != NULL){
				if(p->next == NULL){
					q->next = NULL;
					free(p);
				}else{
					q->next = p->next;
					q->next->prev = q;
					free(p);
				}
			}else{
				printf("\nInvalid Location....");
			}		
		}
	}
}

//travere or print linked List
void printList(){
	if(start == NULL){
			printf("\nLinked List is empty....");
		}else{
			q = start;
			while(q != NULL){
				printf("%d  ", q->data);
				q = q->next;
			}
		}
}

int main(){
	int choice, loc;
	printf("\n1.Add First\n2.Add Last\n3.Add Node at any given location\n4.Delete first\n5.Delete last\n6.Delete Node at any given location\n7.Traverse or Print the Linked list\n8.Exit");	
	
	do{
		printf("\n\nEnter your choice: ");
	    scanf("%d", &choice);
		switch(choice){
		
		//Create at start	
		case 1: printf("\nEnter the data: ");
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &p->data);
		addFirst(p->data);
		break;
		
		//Create at end
		case 2: printf("\nEnter the data: ");
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &p->data);
		addLast(p->data);
		break;
		
		//Create at Given Location
		case 3: printf("\nEnter the data: ");
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &p->data);
		printf("\nEnter location: ");
		scanf("%d", &loc);
		addAt(loc, p->data);
		break;
		
		//delete at start
		case 4:deleteFirst();
		break;
		
		//delete at End
		case 5:deleteLast();
		break;
		
		//Delete at given location
		case 6:printf("\nEnter location: ");
		scanf("%d", &loc);
		deleteAt(loc);
		break;
		
		//travere or print linked List
		case 7: 
		printList();
		break;
		default : printf("You Exited from the code...");
	}
	}while(choice>=1 && choice<=7);
	
	return 0;
}
