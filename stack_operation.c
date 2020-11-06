#include<stdio.h>
#include<stdlib.h>

struct stack{
	int top;
	int size;
	int* array;
};

struct stack* createstack(int len);
int isFull(struct stack* stack);
int isEmpty(struct stack* stack);
void push(struct stack* stack, int data);
int pop(struct stack* stack);
void printstack(struct stack* stack);
struct stack* add(struct stack* first , struct stack* second);

int main(){
	
	
	//struct stack *stack = createstack(100);
	struct stack* first = NULL ; //createstack(100);
	struct stack* second = NULL ; //createstack(100);
	struct stack* res = NULL; // createstack(100);
	char exp[100];
	printf("\nenter the expression : \n" );
	gets(exp);
	
	int i = 0;
	while(exp[i] != '\0')
	{
		struct stack *stack = createstack(100);
		if(isdigit(exp[i]))
		{
			int n = exp[i] - '0';
			
			push(stack, n);
			
			int j = i+1;
			while(isdigit(exp[j]))
			{
				push(stack, exp[j]-'0');
				j++;
			}
			i=j;
			
		}
		if(first == NULL)
		{
			first = stack;
		}
		else if(second == NULL)
		{
			second = stack;
		}
		//printstack(first);
		
		if(exp[i] != ' ')
		{
			char opr = exp[i];
			
			
			
			switch (opr){
			    
				
				case('+'):
					{
						res = add(first,second);
						/*int sum, carry = 0;
	                    while( !isEmpty(first) || !isEmpty(second) )
                        {
                           	int x = pop(first);
                         	int y = pop(second);
	                       	sum = carry +  x + y ;
	                    	printf("%d %d\n",x,y);
	                    	printf("%d %d\n",first->top,second->top);
	                       	carry = (sum>=10) ? 1 : 0 ;
	                    	sum = sum % 10 ;
	                    	printf("%d\n",sum);
	                    	push(res, sum);
   	                    }
                       	if(carry>0)
   	                    {
   	                    	push(res,carry);
	                    }*/
	                     
					}
			}
			
				
			
			
			
			
			
		}
		
		i++;
		
	}
	printstack(res);
	/*printf("\n");
	printstack(second);
	printf("\n");
	*/
	
	return 0;
}


struct stack* createstack(int len){
	
	struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
	stack->size = len;
	stack->top = -1;
	stack->array = (int*)malloc(stack->size * (sizeof(int)));
	return stack;
	
}

int isFull(struct stack* stack){
	
	return stack->top == stack->size - 1;
	
}

int isEmpty(struct stack* stack){
	
	if(stack->top == -1)
	    return 1;
	return 0;
}

void push(struct stack* stack, int data){
	
	if(isFull(stack))
	    return;
	    
	//stack->top++;    
	stack->array[++(stack->top)] = data;
	
}


int pop(struct stack* stack){
	
	if(isEmpty(stack) == 1)
	    return 0;
	   
    return stack->array[stack->top--];
}

void printstack(struct stack* stack){
	
	//struct stack *temp = stack;
	int i = stack->top;
	
	while(i >= 0){
		
		
		/*if(stack->array[i] == ' '){
			printf("\n");
			i--;
		}*/
		printf("%d", stack->array[i]);
		i--;
		
	}
}


struct stack* add(struct stack* first , struct stack* second){
	
	struct stack *res = createstack(100);
	//struct stack *temp1 = first;
	
	//struct stack *temp2 = second;
	//printf("%d %d\n",first->top,second->top);
	int i, sum, carry = 0;
	while( !isEmpty(first) )
    {
    	int x = pop(first);
    	int y = pop(second);
		sum = carry +  x + y ;
		//printf("%d %d\n",x,y);
		//printf("%d %d\n",first->top,second->top);
		carry = (sum>9) ? 1 : 0 ;
		sum = sum % 10 ;
		//printf("%d\n",sum);
	   	push(res, sum);
   	}
   	if(carry>0)
   	{
   		push(res,carry);
	}
	return (res);
	
}
