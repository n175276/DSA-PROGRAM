#include <stdio.h> 
#include <stdlib.h> 
  
/* Linked list node */
struct Node { 
    int data;
	int count; 
    struct Node* next; 
}; 
  
/* Function to create a new node with given data */
struct Node* newNode(int data) 
{ 
    struct Node* new_node = (struct Node*) 
        malloc( 
            sizeof(struct Node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 
  
/* Function to insert a node  
at the beginning of the Singly Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = newNode(new_data); 
  
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 


int length(struct Node* first){
	
	struct Node* temp = first;
	int count=0;
	while (temp != NULL){
		
		count++;
		temp = temp->next;
	}
	
	return count;
	
}  

int isSmall(struct Node* small, struct Node* large){
	
	struct Node* first = small;
	struct Node* second = large;
	if ( (length(small) > length(large)))
	    return 0;
	else if((length(small) < length(large)))
	    return 1;
	
	
	int a[100];
	int b[100];
    int i=0;
	while (first != NULL) { 
	    a[i]= first->data;
	    b[i]= second->data;
        //printf("%d ", node->data); 
        first = first->next;
        second = second->next;
		i++; 
    } 
	//int n = length(small);
	while(i>0){
		if(a[i-1] > b[i-1])
		    return 0;
		else if (a[i-1] < b[i-1])
		    return 1;
		    
		i--;
		//first = first->next;
		//second = second->next;
		
	}
	return 2;
	
	
}

void printList(struct Node* node) 
{ 
    int a[100];
    int i=0;
	while (node != NULL) { 
	    a[i]= node->data;
        //printf("%d ", node->data); 
        node = node->next;
		i++; 
    } 
    while(i>0){
    	printf("%d ",a[i-1]);
    	i--;
	}
    printf("\n"); 
} 


/* Adds contents of two linked 
 lists and return the head node 
 of resultant list */
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


struct Node* mulTwoLists(struct Node* first,struct Node* second){
	
	struct Node* third = NULL;
	struct Node* mul = NULL; 
	//struct Node* res = NULL; 
    struct Node *temp, *prev = NULL; 
    int carry = 0, sum,i=0,j=0;
    
    
    while (second != NULL){
    	
    	third = first;
    	struct Node* res = NULL;
    	for(i=0;i<j;i++)
		{
		    	temp= newNode(0);
		    	
		    	if (res == NULL) 
                    res = temp; 
         
                else
                    prev->next = temp; 
  
 
                prev = temp;
		    	
		}
		while(third !=NULL){
			
			sum = carry + third->data * second->data; 
    	
    	
		    carry = (sum >= 10) ? (sum/10) : 0;
		
		    sum =sum%10;
		    
		    		
	    	temp = newNode(sum); 
  
        
            if (res == NULL) 
                res = temp; 
         
            else
                prev->next = temp; 
  
 
            prev = temp; 
        
            if (third) 
            third = third->next;
            //j++;
		}
		j++; 
		if (carry > 0) 
          temp->next = newNode(carry);
        
		carry=0;  
        
		//printList(res);
        
        mul = addTwoLists(res, mul);
		
        if (second) 
            second = second->next; 
    	
    	//j++;
	}
	 //if (carry > 0) 
        //temp->next = newNode(carry); 
  
 
    return mul; 
}


struct Node* subTwoLists(struct Node* fi,struct Node* se){
	
	struct Node* res = NULL; 
    struct Node *temp, *prev = NULL; 
    int carry = 0, sub; 
    
    struct Node* first = NULL;
    struct Node* second = NULL;
    int n = isSmall(fi, se);
    if(n == 1){
    	
    	first = se;
        second = fi;
	}	
	else if(n==0 ||n==2){
		
		first = fi;
        second = se;
        
	}
  
    while (first != NULL && second != NULL){
    	
    	
		if(first->data >= second->data ){
    	
    		sub =  (first ? (first->data) : 0) - (second ? ((second->data)+carry) : 0);
    		carry = 0;
    		
		}
		
		else if(first->data < second->data){
		
			sub = carry + (first ? (first->data+10) : 0) - (second ? (second->data+carry) : 0);
			carry = 1;
		}
	
		temp = newNode(sub); 
 
        if (res == NULL) 
            res = temp; 

        else
            prev->next = temp; 

        prev = temp; 
 
        if (first) 
            first = first->next; 
        if (second) 
            second = second->next;
		 
    }
    while (first != NULL){
    	
    	int s = first->data - carry;
    	carry =0;
    	temp = newNode(s); 
 
        if (res == NULL) 
            res = temp; 

        else
            prev->next = temp; 

        prev = temp;
    	
    	if (first) 
            first = first->next;
    	
	}

    return res; 
	
}  
// A utility function to print a linked list 


struct Node* divTwoLists(struct Node* first,struct Node* second){
	
	struct Node* res = NULL; 
    struct Node *temp, *prev = NULL;
	struct Node* add= NULL;
	int carry = 0, i= -1;
	int n = isSmall(second, first);
	if (n==0){
		res = newNode(0);
		return res;
	}
	if (n==2){
		res = newNode(1);
		return res;
	}
	while(n!=0){
		add = addTwoLists(add, second);
				
		i++;        
        n = isSmall(add, first);
	}
	
	temp = newNode(i); 
 
        if (res == NULL) 
            res = temp;
            
        else
            prev->next = temp; 

        prev = temp;
	return res;
}
  
/* Driver program to test above function */
int main() 
{ 
    struct Node* res = NULL;
	struct Node* first = NULL; 
    struct Node* second = NULL;
    char E[100];
    printf("Enter the expression : ");
    gets(E);
    char opr;
    int i =0 , j = 0;
    while(E[i] != '\0'){
		
		if(isdigit(E[i])){
		
			//push(&res, E[i]-'0');
			j=i-1;
			while(isdigit(E[i]))
			{
				push(&res,E[i]-'0');
				i++;
			}
			//j=i-1;
			if(j>0 && (E[j])==' ' )
			{
				second = res;
			}
			else if(j == -1)
			{
				first = res;
			}
			res= NULL;
						
		}
		
		
		if(E[i] != ' ')
		{
			opr = E[i];
			
			switch(opr)
			{
				case '+':
					res = addTwoLists(first, second);
				
				case '-':
				    res = subTwoLists(first, second);
				
				case '*':
				    res = mulTwoLists(first, second);
				
				case '/':
				    res = divTwoLists(first, second);	
			}
		}
		i++;
		
		
	}
	printList(res);
    
	

    return 0;
} 
