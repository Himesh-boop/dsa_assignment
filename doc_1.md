# Documentation for prog_1.c

## (a) Data Structures

**Stack Implementation:**
- `char stack[MAX]`: Array to store opening brackets
- `int top = -1`: Index of the top element in stack (-1 means empty)

## (b) Functions

**`void push(char ch)`**
- Adds a character to the top of the stack
- Increments top and stores the character

**`char pop()`**
- Removes and returns the top character from stack
- Returns '\0' if stack is empty

**`int isMatching(char open, char close)`**
- Checks if opening and closing brackets match
- Returns 1 if matched, 0 otherwise
- Validates pairs: (), {}, []

## (c) Main Method Organization

1. Declares expression array and balanced flag
2. Takes input expression from user
3. Loops through each character:
   - Pushes opening brackets (,{,[ onto stack
   - For closing brackets ),},]: pops from stack and checks if they match
   - Sets balanced to 0 if mismatch found
4. Prints whether expression is balanced or not

## (d) Sample Output

```
Enter a mathematical expression: {[(a+b)*(c-d)]}
The given expression is balanced.
```

```
Enter a mathematical expression: {[(a+b]*c}
The given expression isn't balanced.
```