#include<stdio.h>
#include<stdlib.h>


struct Node { 
    int data; 
    struct Node* next; 
}; 


/*typedef struct Stack 
{ 
    int top; 
    int capacity; 
    int* array; 
}stack;*/


struct Node* newNode(int data) 
{ 
    struct Node* new_node = (struct Node*) 
        malloc( 
            sizeof(struct Node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 


/*int pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 


void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} */


void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = newNode(new_data); 
    
    
    //if(head_ref == NULL)
	
		
	 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 


struct Node* addTwoLists(struct Node* first,struct Node* second) 
{ 
  
    // res is head node of the resultant list 
    struct Node* res = NULL; 
    struct Node *temp, *prev = NULL; 
    int carry = 0, sum; 
  
    // while both lists exist 
    while (first != NULL || second != NULL) { 
        // Calculate value of next 
        // digit in resultant list. 
        // The next digit is sum 
        // of following things 
        // (i)  Carry 
        // (ii) Next digit of first 
        // list (if there is a next digit) 
        // (ii) Next digit of second 
        // list (if there is a next digit) 
        sum = carry + (first ? first->data : 0)+ (second ? second->data : 0); 
  
        // Update carry for next calulation 
        carry = (sum >= 10) ? 1 : 0; 
  
        // Update sum if it is greater than 10 
        sum = sum % 10; 
  
        // Create a new node with sum as data 
        temp = newNode(sum); 
  
        // if this is the first node then 
        // set it as head of the resultant list 
        if (res == NULL) 
            res = temp; 
        // If this is not the first node 
        // then connect it to the rest. 
        else
            prev->next = temp; 
  
        // Set prev for next insertion 
        prev = temp; 
  
        // Move first and second 
        // pointers to next nodes 
        if (first) 
            first = first->next; 
        if (second) 
            second = second->next; 
    } 
  
    if (carry > 0) 
        temp->next = newNode(carry); 
  
    // return head of the resultant list 
    return res; 
} 
  
// A utility function to print a linked list 
void printList(struct Node* node) 
{ 
    int a[100];
    int i=0,j=0,temp,k;
    while (node != NULL) {
	    a[i]= node->data; 
        //printf("%d ", node->data);
		//printf("%d",a[i]); 
        node = node->next; 
        i++;
    }
    k=i;
	while(j<=i){
		temp = a[i];
		a[i]= a[j];
		a[j]= temp;
		j++;
		i--;
	}
	for(i=0 ; i<=k ; i++){
		printf("%d",a[k]);
	}
	
    printf("\n"); 
} 
  
/* Driver program to test above function */
int main(void) 
{ 
    struct Node* res = NULL; 
    struct Node* first = NULL; 
    struct Node* second = NULL; 
  
    // create first list 7->5->9->4->6 
    push(&first, 6); 
    push(&first, 4); 
    push(&first, 9); 
    push(&first, 5); 
    push(&first, 7); 
    printf("First List is "); 
    printList(first); 
  
    // create second list 8->4 
    push(&second, 4); 
    push(&second, 8); 
    printf("Second List is "); 
    printList(second); 
  
    // Add the two lists and see result 
    res = addTwoLists(first, second); 
    printf("Resultant list is "); 
    printList(res); 
  
    return 0; 
} 





