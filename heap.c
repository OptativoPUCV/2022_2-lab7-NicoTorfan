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
  if (pq->size+1>=pq->capac){
    pq->capac=((pq->capac) * 2)+1;
    pq->heapArray=realloc(pq->heapArray,pq->capac*(sizeof(Heap)));
  }
  heapElem aux;
  int ub=pq->size;
  double fatherD=(pq->size -1 )/2;
  int father= trunc(fatherD);
  while (pq->heapArray[father].priority < priority){
    if(pq->heapArray[father].priority > priority) break;
    aux=pq->heapArray[father];
    pq->heapArray[father]=pq->heapArray[ub];
    pq->heapArray[ub]=aux;
    ub = father;
    fatherD=(fatherD - 1)/2;
    father= trunc(fatherD);
  }
  pq->size=pq->size+1;
}


void heap_pop(Heap* pq){
  heapElem aux;
  int son1=0 ,son2=0 ,son=0,father=0;
  pq->size=pq->size-1;
  aux=pq->heapArray[pq->size];
  pq->heapArray[pq->size]=pq->heapArray[0];
  pq->heapArray[0]=aux;
  pq->heapArray[pq->size].data=NULL;
  pq->heapArray[pq->size].priority=0;
  while (son < pq->size){
    son1 = 2*father + 1;
    son2 = 2*father + 2;
    if (son1>pq->size) pq->heapArray[son1].priority= 0;
    if (son2>pq->size) pq->heapArray[son2].priority= 0;
    if(pq->heapArray[son2].priority>son1) son=son2;
    else son=son1;
    if (pq->heapArray[son].priority>pq->heapArray[father].priority){
      aux=pq->heapArray[father];
      pq->heapArray[father]=pq->heapArray[son];
      pq->heapArray[son]=aux;
      father=son;
    }
    else break;
  }
}

Heap* createHeap(){
  Heap * heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray= (heapElem*) malloc(3*sizeof(heapElem));
  heap->size=0;
  heap->capac=3;
  return heap;
}
