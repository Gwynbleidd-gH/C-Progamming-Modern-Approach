#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 100

char stack[STACK_MAX_SIZE];

int top = 0;

bool is_full(void)
{
    return top == STACK_MAX_SIZE;
}

bool is_empty(void)
{
    return top == 0;
}

void push(char ch)
{
    if (is_full()) {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    else {
        stack[top++] = ch;
    }
}

char pop(void)
{
    if (is_empty()) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    else {
        return stack[--top];
    }
}

int main(void)
{
    int ch;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if ((ch == ')' || ch == '}') && is_empty()) {
            push(ch);
            break;
        }
        else if (ch == '(' || ch == '{')
            push(ch);
        else if (ch == ')' && pop() != '(')
            break;
        else if (ch == '}' && pop() != '{')
            break;
    }

    if (is_empty())
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not nested properly\n");
    
    return 0;
}
  
