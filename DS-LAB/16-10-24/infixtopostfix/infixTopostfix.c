#include<stdio.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}


int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

   
        if (isalnum(c)) {
            postfix[j++] = c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }

        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }


    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

  
    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
