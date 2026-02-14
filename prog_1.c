#include <stdio.h>
#include <conio.h>
#include <string.h>

// WAP to check if given mathematical expression has balanced number of parentheses or not.

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if(top == -1)
        return '\0';
    return stack[top--];
}

int isMatching(char open, char close){
    if(open=='(' && close == ')')
        return 1;
    if(open=='{' && close == '}')
        return 1;
    if(open=='[' && close == ']')
        return 1;
    return 0;
}

int main(){
    char exp[MAX];
    int i, balanced=1;

    printf("Enter a mathematical expression: ");
    gets(exp);

    for(i=0; i<strlen(exp); i++){
        char ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(top == -1 || !isMatching(pop(), ch)){
                balanced = 0;
                break;
            }
        }
    }
    if(balanced)
        printf("The given expression is balanced.");

    else
        printf("The given expression isn't balanced.");

    return 0;
}
