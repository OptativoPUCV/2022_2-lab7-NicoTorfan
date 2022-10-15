#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  void *top;
  top=pq->heapArray[0].data;
  if (pq->size==0) return NULL;
    return top;
}



void heap_push(Heap* pq, void* data, int priority){
  pq->heapArray[pq->size].data=data;
  pq->heapArray[pq->size].priority=priority;
  heapElem aux;
  double fatherD=(pq->size -1 )/2;
  int father= trunc(fatherD);
  while (pq->heapArray[father].priority < priority){
    if(pq->heapArray[father].priority > priority) break;
    aux=pq->heapArray[father];
    pq->heapArray[father]=pq->heapArray[pq->size];
    pq->heapArray[pq->size]=aux;
    fatherD=(fatherD - 1)/2;
    father= trunc(fatherD);
  }
  if(pq->heapArray[0].priority<=priority){
    aux=pq->heapArray[0;
    pq->heapArray[0]=pq->heapArray[pq->size];
    pq->heapArray[pq->size]=aux;
  }
  pq->size=pq->size+1;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray= (heapElem*) malloc(3*sizeof(heapElem));
  heap->size=0;
  heap->capac=3;
  return heap;
}
