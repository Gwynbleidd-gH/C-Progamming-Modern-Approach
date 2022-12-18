#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 100

int stack[STACK_MAX_SIZE];

int s_top = 0;

void make_empty(void);

bool is_empty(void);

bool is_full(void);

void push(int n);

int pop(void);

int main(void)
{
    char ch;
    int result = 0;
    int operand;

    while (true) {
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) && ch != '\n') {
            switch (ch) {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                push(ch - '0');
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                operand = pop();
                push(pop() - operand);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                operand = pop();
                push(pop() / operand);
                break;
            case '=':
                result = pop();
                break;
            case ' ':
                break;
            default:
                exit(1);
            }
        }
        printf("Value of expression: %d\n", result);
    }

    return 0;
}

void make_empty(void)
{
    s_top = 0;
}

bool is_empty(void)
{
    return s_top == 0;
}

bool is_full(void)
{
    return s_top == STACK_MAX_SIZE;
}

void push(int n)
{
    if (!is_full())
        stack[s_top++] = n;
    else {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
}

int pop(void)
{
    if (!is_empty())
        return stack[--s_top];
    else {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
}
