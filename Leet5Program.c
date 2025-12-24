#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *q1;
    int *q2;
    int f1, r1, f2, r2;
    int cap;
} MyStack;

MyStack* myStackCreate() {
    MyStack *s = malloc(sizeof(MyStack));
    s->cap = 100;
    s->q1 = malloc(sizeof(int) * s->cap);
    s->q2 = malloc(sizeof(int) * s->cap);
    s->f1 = s->r1 = s->f2 = s->r2 = 0;
    return s;
}

void myStackPush(MyStack* s, int x) {
    s->q2[s->r2++] = x;
    while (s->f1 < s->r1)
        s->q2[s->r2++] = s->q1[s->f1++];
    int *tq = s->q1; s->q1 = s->q2; s->q2 = tq;
    int tf = s->f1, tr = s->r1;
    s->f1 = s->f2; s->r1 = s->r2;
    s->f2 = tf; s->r2 = tr;
}

int myStackPop(MyStack* s) {
    return s->q1[s->f1++];
}

int myStackTop(MyStack* s) {
    return s->q1[s->f1];
}

bool myStackEmpty(MyStack* s) {
    return s->f1 == s->r1;
}

void myStackFree(MyStack* s) {
    free(s->q1);
    free(s->q2);
    free(s);
}
