#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element ;

typedef struct {
    element data[MAX_STACK_SIZE] ;
    int top ;
} StackType ;

void init_stack(StackType *s) {
    s->top = -1 ;
}

int is_empty(StackType *s) {
    return (s->top == -1) ;
}

int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1)) ;
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "Stack Full") ;
        return ;
    }
    else {
        s->data[++(s->top)] = item ;
    }
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack Empty") ;
        return -1 ;
    }
    else {
        return (s->data[(s->top)--]) ;
    }
}

int eval(char exp[]) {
    int op1, op2, i = 0 ;
    int len = strlen(exp) ;
    char ch ;
    StackType s ;
    init_stack(&s) ;
    for (i=0; i<len; i++) {
        ch = exp[i] ;
        if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0') ;
        }
        else if(ch == '+' || ch == '-'|| ch == '*'|| ch == '/') {
            op2 = pop(&s) ;
            op1 = pop(&s) ;
            switch (ch) {
                case '+': push(&s, op1 + op2); break ;
                case '-': push(&s, op1 - op2); break ;
                case '*': push(&s, op1 * op2); break ;
                case '/': push(&s, op1 / op2); break ;
            }
        }
        else {
            fprintf(stderr, "Invaild Character\n") ;
            return -1 ;
        }
    }
    return pop(&s) ;
}

int main() {
    int result ;
    printf("Enter an infix expression : ") ;
    char user_enter[MAX_STACK_SIZE] ;
    scanf("%s", user_enter) ;
    result = eval(user_enter) ;
    printf("Result : %d\n", result) ;
    return 0 ;
}