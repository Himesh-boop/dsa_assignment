#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {

    int i = 0, j = 0;

    while (infix[i] != '\0') {

        if (isdigit(infix[i])) {

            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }

            postfix[j++] = ' '; 
            continue;
        }

        else if (infix[i] == '(') {
            push(infix[i]);
        }

        else if (infix[i] == ')') {

            while (stack[top] != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            pop();
        }

        else if (infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/') {

            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(infix[i]);
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

int evalStack[MAX];
int evalTop = -1;

void pushEval(int x) {
    evalStack[++evalTop] = x;
}

int popEval() {
    return evalStack[evalTop--];
}

int evaluatePostfix(char postfix[]) {

    int i = 0;

    while (postfix[i] != '\0') {

        if (isdigit(postfix[i])) {

            int num = 0;

            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }

            pushEval(num);
        }

        else if (postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/') {

            int b = popEval();
            int a = popEval();

            switch(postfix[i]) {
                case '+': pushEval(a + b); break;
                case '-': pushEval(a - b); break;
                case '*': pushEval(a * b); break;
                case '/': pushEval(a / b); break;
            }
        }

        i++;
    }

    return popEval();
}


int main() {

    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}
