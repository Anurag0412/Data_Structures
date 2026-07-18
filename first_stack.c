#include<stdio.h>
#define Max 5

//creation of stack
struct Stack{
    int arr[Max];//array to store stack elements
    int top;//variable to keep track of the top element in the stack
};

//initialize the stack
void initialize(struct Stack *stack) {
    //since stack is empty,initialize top to -1
    //top stores the index of the top element in the stack
    stack->top = -1;
    printf("Stack initialized successfully\n Top is : %d", stack->top);
}

//checking if stack is empty
int isEmpty(struct Stack *stack) {
    /* Different ways to check if stack is empty
    if(s->top==1){
        return 1;
    }
    else{
        return 0;
    }
    */
    return (stack->top == -1);
}

//checking if stack is full
int isFull(struct Stack *stack) {
    return (stack->top == Max - 1);//check for the error here, it should be Max-1 instead of Max bcoz array index starts from 0
}

/*
Functions to make
1. Storage Available
2. Push
3. Pop
4. Seek
5. TopIndex
*/

// Checking for storage
void Storage_Available(struct Stack *stack){
    if(stack->top==Max - 1 ){
        printf("No more storage available\n");
        printf("Next Push will make Stack overflow");
    }
    else if(stack->top== -1 ){
        printf("Stack Empty");
        printf("Push Elements to start");
    }
    else{
        printf("Stack has storage available\n");
    }
}

// Push function to add elements to the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    else{
        stack->arr[++(stack->top)] = value;
        printf("Pushed %d to stack\n", value);
    }
}

// Pop function to remove elements from the stack
// Logic for pop is to return the top element and decrease the top index by one
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -1; // Return an error value
    }
    else{
        int poppedValue = stack->arr[(stack->top)--];
        printf("Popped %d from stack\n", poppedValue);
        return poppedValue;
    }
}

int main(){
    //making a structure
    struct Stack s;
    initialize(&s);
    //checking for stack's elements
    if(isEmpty(&s)){
        printf("\nStack is empty");
    }
    else{
        printf("\nStack is not empty");
    }
    if(isFull(&s)){
        printf("\nStack is full");
    }
    else{
        printf("\nStack is not full");
    }

}