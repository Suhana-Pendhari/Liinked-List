//Q1.Write program to implement circular linked list operations using two external reference pointers start and last. 
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
};
typedef struct Node NODE;
NODE *start = NULL, *last = NULL, *p, *q;

//Create at start
void addFirst(int data){
	if(start == NULL){
			p->next = p;
			start = p;
			last = p;
		}else{
			p->next = start;
			start = p;
			last->next = start;
		}
}

//Create at end
void addLast(int data){
	if(start == NULL){
			p->next = p;
			start = p;
			last = p;
		}else{
			last->next = p;
			p->next = start;
			last = p;
		}
}

//Create at Given Location
void addAt(int loc, int data) {
    if (start == NULL) {
        if (loc == 1) {
            p->next = p;
            start = p;
            last = p;
        } else {
            printf("\nInvalid Location....");
            free(p);
        }
    } else {
        if (loc == 1) {
            p->next = start;
            last->next = p;
            start = p;
        } else {
            int i = 1;
            q = start;
            while (i < loc - 1 && q != last) {
                q = q->next;
                i++;
            }
            if (q != last) {
                p->next = q->next;
                q->next = p;
            } else if (i == loc - 1) {
                q->next = p;
                last = p;
                p->next = start;
            } else {
                printf("\nInvalid Location....");
                free(p);
            }
        }
    }
}

//delete at start
void deleteFirst(){
	if(start == NULL){
		printf("\nLinked List is empty Nothing is to delete...");
	}else{
		p = start;
		if(p->next == p){
			start = NULL;
			last = NULL;
			printf("\n%d is deleted", p->data);
			free(p);
		}else{
			start = start->next;
			last->next = start;
			printf("\n%d is deleted", p->data);
			free(p);
		}
	}
}

//delete at End
void deleteLast(){
	if(start == NULL){
		printf("\nLinked List is empty Nothing is to delete...");
	}else{
		if(start->next == start){
			p = start;
		 	start = NULL;
		 	last = NULL;
			printf("\n%d is deleted", p->data);
			free(p);
		}else{
			p = start;
			while(p!=last){
				q = p;
				p = p->next;
			}
			last = q;
			q->next = start;
			printf("\n%d is deleted", p->data);
			free(p);
		}
	}
}

//Delete at given location
void deleteAt(int loc){
    if(start == NULL){
        printf("\nLinked List is empty. Nothing to delete...");
    }else{
        p = start;
        q = NULL;
        if (start == last && loc == 1){
            printf("\n%d is deleted", p->data);
            start = NULL;
            last = NULL;
            free(p);
        }else{
            int i = 1;
            while(i < loc && p->next != start){
                q = p;
                p = p->next;
                i++;
            }

            if(i == loc){
                if(p == start){
                    start = p->next;
                    last->next = start;
                    if(p == last){
                        last = NULL;
                    }
                }else if(p == last) {
                    q->next = start;
                    last = q;
                }else{
                    q->next = p->next;
                }
                printf("\n%d is deleted", p->data);
                free(p);
            }else{
                printf("\nInvalid Location...");
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
        do{
            printf("%d  ", q->data);
            q = q->next;
        }while(q != start);
    }
    printf("\n");
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
