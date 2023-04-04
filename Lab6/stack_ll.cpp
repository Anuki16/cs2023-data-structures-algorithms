#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

typedef struct {
    Node* top = NULL;
    Node* head = NULL;
} Stack;

void display(Stack* stack) {
    Node* node = stack->head;
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Top is at the end of the list
void stack_push(Stack* stack, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;

    if (stack->top) {
        (stack->top)->next = node;
    } else {
        stack->head = node;
    }
    stack->top = node;
}

int stack_pop(Stack* stack) {
    if (!(stack->top)) {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    int value = (stack->top)->data;

    if (stack->head == stack->top) { // only one node
        stack->head = NULL;
        stack->top = NULL;
    } else {
        Node* node = stack->head;
        while (node->next != stack->top) {
            node = node->next;
        }
        node->next = NULL;
        stack->top = node;
    }
    return value;
}

bool stack_is_empty(Stack* stack) {
    return stack->top == NULL;
}

int stack_top(Stack* stack) {
    return (stack->top)->data;
}


int main() {
    Stack stack;

    clock_t start, end;
    double time_spent;

    cout << "Stack with linked list" << endl;
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