// C program to convert infix expression to postfix  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
//#define len 100  
// Stack type 
typedef struct Stack 
{ 
    int top; 
    unsigned capacity; 
    long int* array; 
}stack; 


void init(stack *s, int len){
    //struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
	s->array = (long int *)malloc (sizeof(long int)*len);
	s->capacity = len;
    s->top = -1;
}
  
// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack)  
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
  
    stack->array = (long int*) malloc(stack->capacity * sizeof(long int)); 
  
    return stack; 
} 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
char peek(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 


char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 


void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
  
  
// A utility function to check if the given character is operand 
int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 
  
// A utility function to return precedence of a given operator 
// Higher returned value means higher precedence 
int Prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 
  
  
// The main function that converts given infix expression 
// to postfix expression.  
int infixToPostfix(char* exp, char* E) 
{ 
    int i, k, j; 
  
    // Create a stack of capacity equal to expression size  
    struct Stack* stack = createStack(strlen(exp)); 
    if(!stack) // See if stack was created successfully  
        return -1 ; 
  
    for (i = 0, k = -1; E[i]; ++i) 
    { 
        // If the scanned character is an operand, add it to output. 
        if (isdigit(E[i])){
		 
            j = i+1;
        	//printf("%c\n",E[i]);        	      	       	
            exp[++k] = E[i];
            if(!isdigit(E[j])){
        		exp[++k] = ' ';       		
        		
			}  
        }
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (E[i] == '(') 
            push(stack, exp[i]); 
          
        // If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
        else if (E[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                exp[++k] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1; // invalid expression              
            else
                pop(stack); 
        } 
        else // an operator is encountered 
        { 
            while (!isEmpty(stack) && Prec(E[i]) <= Prec(peek(stack))) 
                exp[++k] = pop(stack); 
            push(stack, E[i]); 
        } 
  
    } 
  
    // pop all the operators from the stack 
    while (!isEmpty(stack)) 
        exp[++k] = pop(stack ); 
  
    exp[++k] = '\0'; 
    printf( "%s\n", exp ); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    //char E[] = "a+b*(c^d-e)^(f+g*h)-i"; 
   	//infixToPostfix(E); 
    //printf("\n%s",E);
    char E[100];
    char exe[100];
    stack s1;
    //struct Stack* s1 = (struct Stack*) malloc(sizeof(struct Stack));
    init(&s1, 100);
    //char E[100];
    int n = 0, m;
    int i = 0,operand1, operand2;
    char opr;
    long int r;
    int j;
    char reply = 'Y';
    while(reply == 'Y' || reply == 'y') {
        printf("\nEnter a postfix expression:\n");
        gets(E);
        infixToPostfix(exe,E);
        //printf( "%s",E );
        i = 0;
        while(exe[i]!= '\0'){
            if(isdigit(exe[i])){
                 n = exe[i] - '0' ;
                 j = i - 1;

                 if(j >= 0 && isdigit(E[j])){
                    m = pop(&s1);
                    n = m*10 + n;
                 }
                 push(&s1,n);
                 //printf("\n%d",n);
            }
            else if(exe[i] != ' '){
                    opr = exe[i];
                    operand2 = pop(&s1);
                    operand1 = pop(&s1);
                    switch(opr){
                        case '+' : r = operand1 + operand2;
                                   break;
                        case '-' : r = operand1 - operand2;
                                   break;
                        case '*' : r = operand1 * operand2;
                                   break;
                        case '/' : r = operand1 / operand2;
                                   break;
                        default  : printf("Undefined operator\n");
                                      break;
                }
                push(&s1, r);
            }
        i++;  
    }
    r = pop(&s1);
    printf("%ld\n", r);
    printf("Do you want to cont.? (Y/N)\n");
    reply = getche();
   }
    return 0; 
} 
