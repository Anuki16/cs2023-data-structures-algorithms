#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

const int STACK_SIZE = 128;

typedef struct {
    int arr[STACK_SIZE];
    int top = -1;
} Stack;

void display(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        cout << (stack->arr)[i] << " ";
    }
    cout << endl;
}

void stack_push(Stack* stack, int data) {
    if (stack->top >= STACK_SIZE-1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack->top++;
    (stack->arr)[stack->top] = data;
}

int stack_pop(Stack* stack) {
    if (stack->top == -1) {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    stack->top--;
    return (stack->arr)[stack->top+1];
}

bool stack_is_empty(Stack* stack) {
    return stack->top == -1;
}

bool stack_is_full(Stack* stack) {
    return stack->top == STACK_SIZE-1;
}

int stack_top(Stack* stack) {
    return (stack->arr)[stack->top];
}


int main() {
    Stack stack;

    clock_t start, end;
    double time_spent;

    cout << "Stack with array" << endl;
    start = clock();

    for (int i = 0; i < 10; i++) {
        stack_push(&stack, rand()%100);
    }
    display(&stack);

    for (int i = 0; i < 5; i++) {
        stack_pop(&stack);
    }
    display(&stack);
    
    for (int i = 0; i < 4; i++) {
        stack_push(&stack, rand()%100);
    }
    display(&stack);

    end = clock();
    time_spent = (double)(end - start) / (double)CLOCKS_PER_SEC;
    printf("Time taken: %.6f s\n", time_spent);

    return 0;
}