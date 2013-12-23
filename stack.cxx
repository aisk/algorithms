#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int stack_elem_t;

typedef struct _stack_t {
    int size;
    int capacity;
    stack_elem_t *elems;
} _stack_t;

_stack_t* stack_create(const int capacity) {
    _stack_t *s = (_stack_t*) malloc(sizeof(_stack_t));
    s->size = 0;
    s->capacity = capacity;
    s->elems = (stack_elem_t*) malloc (capacity * sizeof(stack_elem_t));
    return s;
}

void stack_destory(_stack_t *s) {
    free(s->elems);
    free(s);
}

int stack_empty(const _stack_t *s) {
    return s->size == 0;
}

int stack_size(const _stack_t *s) {
    return s->size;
}

void stack_push(_stack_t *s, const stack_elem_t x) {
    if (s->size == s->capacity) {
        stack_elem_t* tmp = (stack_elem_t*) realloc(s->elems, s->capacity * 2 * sizeof(stack_elem_t));
        s->capacity *= 2;
        s->elems = tmp;
    }
    s->elems[s->size++] = x;
}

void stack_pop(_stack_t *s) {
    s->size--;
}

stack_elem_t stack_top(const _stack_t *s) {
    return s->elems[s->size -1];
}

int main() {
    _stack_t* s;
    int i;
    s = stack_create(10);
    for (i = 0; i <= 9; i++) {
        stack_push(s, i);
    }
    assert(s->capacity == 10);
    assert(stack_top(s) == 9);
    stack_push(s, 10);
    assert(s->capacity == 20);
    return 0;
}
