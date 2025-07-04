/*
Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra de um
texto terminado por ponto (.) preservando a ordem das palavras. Por exemplo, dado o
texto:
ESTE EXERC´ICIO E MUITO F ´ ACIL. ´
A sa´ıda deve ser:
ETSE OIC´ICREXE E OTIUM LIC ´ AF
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    }
    return '\0';
}

void reverseWords(char *str) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '.') {
            push(&stack, str[i]);
        } else {
            while (stack.top != -1) {
                putchar(pop(&stack));
            }
            putchar(str[i]);
        }
    }
    putchar('\n');
}

int main() {
    char text[] = "GABRIEL IS HAPPY.";
    reverseWords(text);
    return 0;
}