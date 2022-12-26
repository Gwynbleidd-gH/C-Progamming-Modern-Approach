#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STACK_MAX_SIZE 100

char stack[STACK_MAX_SIZE];

int stack_top = 0;

bool is_empty(void);

bool is_full(void);

void push(char value);

char pop(void);

bool bem_formada(char str[]);

int main(void)
{
    char str[10];

    printf("Enter parentheses and/or braces: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if (bem_formada(str))
        printf("parentheses/braces are nested properly\n");
    else
        printf("arentheses/braces are not nested properly\n");

    return 0;
}

bool is_empty(void)
{
    return stack_top == 0;
}

bool is_full(void)
{
    return stack_top == STACK_MAX_SIZE;
}

void push(char value)
{
    if (!is_full())
        stack[stack_top++] = value;
    else {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }  
}

char pop(void)
{
    if (!is_empty())
        return stack[--stack_top];
    else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

bool bem_formada(char str[])
{
    int i;
    char ch;

    for (i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
        case ')':
            if (is_empty() || (ch = pop()) != '(')
                return false;
            break;
        case '}':
            if (is_empty() || (ch = pop()) != '{')
                return false;
            break;
        case '(': case '{':
            push(str[i]);
            break;
        default:
            return false;
        }
    }

    return is_empty();
}
