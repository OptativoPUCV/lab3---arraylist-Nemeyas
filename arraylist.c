#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *lista=malloc(sizeof(ArrayList));
  lista->data = malloc(sizeof(void*) * lista->capacity);
  lista->size=0;
  lista->capacity=2;
  return NULL;
}

void append(ArrayList * l, void * data){
  if(l->capacity == l->size){ 
    l->capacity*=2;
    l->data =(void*) realloc(l->data, sizeof(void*)*l->capacity);
  }
}

void push(ArrayList * l, void * data, int i){
  if(i>l->size) return;
  if(l->capacity==l->size){
    l->capacity=l->capacity*2;
    l->data =(void*) realloc(l->data, sizeof(void*)*l->capacity);
  }
  if(i<l->size){
    for(size_t k=l->size; k>i; k--){
    l->data[k] = l->data[k-1];
  }
  l->data[i]=data;
  l->size++;
  }
}

void* pop(ArrayList * l, int i){
  if(i>l->size){ 
    return NULL;
  }
}

void* get(ArrayList * l, int i){
  if(i>=l->size){
    return NULL;
  }
  if(i<0){
    if(l->capacity==0){
      return NULL;
    }
     return l->data[l->size+i]; 
    }
  return l->data[i];
}

int get_size(ArrayList * l){
  
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  l->capacity=2;
  l->size=0;
  l->data =realloc(l->data, sizeof(void*)*l->capacity);
}
