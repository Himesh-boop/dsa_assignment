# Documentation for prog_2.c

## (a) Data Structures

**Stack for Conversion:**
- `char stack[MAX]`: Array to store operators during conversion
- `int top = -1`: Index of top element in operator stack

**Stack for Evaluation:**
- `int evalStack[MAX]`: Array to store operands during evaluation
- `int evalTop = -1`: Index of top element in evaluation stack

## (b) Functions

**`void push(char x)`**
- Adds an operator to the conversion stack
- Increments top and stores the character

**`char pop()`**
- Removes and returns the top operator from conversion stack
- Decrements top after returning the character

**`int priority(char x)`**
- Returns operator precedence level
- Returns 2 for * and /, 1 for + and -, 0 for others

**`void infixToPostfix(char infix[], char postfix[])`**
- Converts infix expression to postfix notation
- Handles multi-digit numbers by adding spaces between tokens
- Processes operators based on precedence and parentheses

**`void pushEval(int x)`**
- Adds an integer operand to the evaluation stack
- Increments evalTop and stores the number

**`int popEval()`**
- Removes and returns the top operand from evaluation stack
- Decrements evalTop after returning the value

**`int evaluatePostfix(char postfix[])`**
- Evaluates the postfix expression and returns the result
- Parses multi-digit numbers and performs operations

## (c) Main Method Organization

1. Declares arrays for infix and postfix expressions
2. Takes infix expression as input from user
3. Calls `infixToPostfix()` to convert infix to postfix
4. Displays the postfix expression
5. Calls `evaluatePostfix()` to compute the result
6. Displays the final result

## (d) Sample Output

```
Enter infix expression: 3+5*2
Postfix expression: 3 5 2 * + 
Result = 13
```

```
Enter infix expression: (8+2)*3
Postfix expression: 8 2 + 3 * 
Result = 30
```