// Learning Stack
/*
Stack runs on the principle of LIFO that states that the last element to enter will come out first
Defining function to include while making a stack:
1. First creating a basic structure for the stack
2. Initializing the stack
3. Making Function to Check for space in stack like: isFull, isEmpty, isOverflow and isUnderflow
4. Push Function to add the element
5. Pop Function to show and remove the last element of the stack
6. Peek Function to seek a value on the top index value 
*/

#include<stdio.h>
#include<stdbool.h>

#define MAX 5

//Making a user defined datatype to store Stacks structure
struct Stack{
	
	//making a array to store the data 
	int arr[MAX];

	//making a variable to store the index of top most element of stack
	int top;
};

//Initializing a stack
//using pointer to change value at the location to avoid changing or storing the value on the temporary basis

void initialize(struct Stack *stack){
	
	//marking the top element as stack has just started so the top elements index must be -1
	stack->top=-1;
	printf("Stack initialized!!");
}

//Making verification functions

// 1. isFull and isEmpty

bool isFull(struct Stack *stack){
	return (stack->top== MAX -1);
}

bool isEmpty(struct Stack *stack){
	return (stack->top == -1);
}

// 2. Overflow and Underflow check

void flow_check(struct Stack *stack){
	if(stack->top >= MAX - 1){
		printf("Stack Overflow");
	}
	else if(stack->top == -1){
		printf("Stack Underflow");
	}
	else{
		printf("Stack has space");
	}
}

//Making Push Function to add elements i.e., Value, to stack

void Push(struct Stack *stack , int Value){
	if(isFull(stack)){
		printf("Stack Full");
	}
	else{
		stack -> top++;
		stack -> arr[stack -> top] = Value;
	}
}

//Making pop function to remove the top most element of the stack

void Pop(struct Stack *stack){
	if(isEmpty(stack)){
		printf("Stack Underflow \n No elements to remove"); 
	}
	else{
		printf("Top Element to pop out is: %d",stack -> arr[stack -> top]);
		stack -> top = stack -> top - 1; 
	}
}

// Making Seek function to display the top value of the stack

int Peek(struct Stack *stack ){
	if(isEmpty(stack)){
		printf("Stack Underflow \n No elements to display"); 
	}
	else{
		printf("Top Element is: %d", stack -> arr[stack -> top]);
	}
}

// Display Stack
void Display(struct Stack *stack) {

    if (isEmpty(stack)) {
        printf("Stack Empty\n");
        return;
    }

    printf("Stack Elements:\n");

    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

int main(){
	struct Stack stack;
	initialize(&stack);
	Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    printf("Top Element = %d\n", Peek(&stack));
	Display(&stack);
	Pop(&stack);
	Display(&stack);
	return 0;
}
