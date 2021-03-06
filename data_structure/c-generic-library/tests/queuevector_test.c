#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "gen/error_macros.h"
#define RUNS 1000000
#define BOUND 10000
#define BASE 0
#define NUMCASES 10

int32_t intcmp(const void *, const void *,size_t);
void  print(const void *);
void  ckfree(void *);
void *ckalloc(size_t);

int
main(void) {
  QueueVector  object;
  QueueVectorIter *ptr;
  unsigned int x, y;
  unsigned int value;
  memset(&object, 0, sizeof (object));
  x = RUNS;
  construct(QueueVector, &object,sizeof(x),FREEOBJ);
  set_alloc(QueueVector,  &object, ckalloc);
  set_dealloc(QueueVector,  &object, ckfree);
  set_compare(QueueVector,  &object, intcmp);
  set_print(QueueVector,  &object, print);
  for (y = 0; y < x; y++) {
    srand((x * y) / (x - y) + (x + y / x));
    switch ((rand() % NUMCASES) + BASE) {
        case 0:
        case 10:
        case 11:
        case 1:
        case 12:
        case 13:
        case 2:
        case 14:
          value = rand() % BOUND;
          push(QueueVector,  &object, &value, DYNAMIC);
          break;
        case 3:
        case 15:
        case 4:
        case 5:
        case 6:
        case 16:
          pop(QueueVector,  &object);
          break;
        case 7:
        case 17:
        case 8:
        case 9:
          front(QueueVector,  &object);
          break;
        default:
          break;
    };
  }
  destruct(QueueVector,  &object);
  fprintf(stderr, "Now testing the iterators!\n");
  construct_func(QueueVector,&object,sizeof(x),FREEOBJ, ckalloc, ckfree, intcmp, print,
                 memcpy);
  for (x = 0; x < RUNS; x++) {
	  value = rand();
    push(QueueVector,  &object, &value, STATIC);
  }

  ptr = create(QueueVectorIter,  &object);
  head(QueueVectorIter, ptr);
  do {
    value = *(unsigned int *) retrieve(QueueVectorIter, ptr);
  }
  while (!next(QueueVectorIter, ptr));
  assign(QueueVectorIter, ptr, &object);
  tail(QueueVectorIter, ptr);
  do {
    value = *(unsigned int *) retrieve(QueueVectorIter, ptr);
  } while (!prev(QueueVectorIter, ptr));
  for(x = 0; x < RUNS; x++) {
	  switch(rand() % 2) {
		  case 1:
			  next(QueueVectorIter,ptr);
			  break;
		  case 2:
			  prev(QueueVectorIter,ptr);
			  break;
	  }
  }
  destroy(QueueVectorIter, ptr);
  destruct(QueueVector,  &object);
  return EXIT_SUCCESS;
}

int32_t
intcmp(const void *a, const void *b,size_t x UNUSED)
{
  if ((*(const int *) a) < (*(const int *) b)) {
    return -1;
  } else if ((*(const int *) a) > (*(const int *) b)) {
    return 1;
  } else {
    return 0;
  }
}

void
print(const void *a)
{
  printf("%d ", (*(const int *) a));
}

void *
ckalloc(size_t size)
{
  void *ptr;

  do {
    ptr = malloc(size);
  }
  while (!ptr);
  return ptr;
}

void
ckfree(void *ptr)
{
  free(ptr);
}
