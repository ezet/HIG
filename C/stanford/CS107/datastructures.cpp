#include <iostream>
#include <cstdlib>
using namespace std;

// generic stack.h
typedef struct {
  void *elems;
  int elemsize;
  int loglength;
  int alloclength;
} Stack;

void StackInit(Stack *s, int elemsize) {
  s->loglength = 0;
  s->alloclength = 4;
  s->elems = malloc(4*elemsize);
  assert(s->elems != NULL);
}

void StackDispose(Stack *s) {
  free(s->elems);

}

static void StackGrow(Stack *s) {
  s->alloclength *= 2;
  s->elems = realloc(s->elems, s->alloclenght * s->elemsize);
}

void StackPush(Stack *s, void *elemaddr){
  if (s->loglength == s->alloclength)
    StackGrow(s);
  void *target = (char*)s->elems + (s->loglength*s->elemsize);
  memcpy(target, elemaddr, s->elemsize);
  s->loglength++;
}

void StackPop(Stack *s, void *elemaddr) {
  s->loglength--;
  void *source = (char*)s->elems + (s->loglength * s->elemsize);
  memcpy(elemaddr, source, s->elemsize);
}

int main() {
  int top;
  Stack s;
  StackInit(&s, sizeof(int));
  StackPop(&s, &top);


return 0;
}