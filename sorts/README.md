# Sorting algorithms

`sorts.h` header file contain function declarations for the following sorting algorithms. All sorts are implemented in generic way, i.e. can be used to sort any data type in any way based on compare function.

1. Merge sort
1. Quick sort (Randomized)
1. Insertion sort

## Usage
```C
void msort(void *base, void *aux, int start, int end, int size, int (*compar)(const void *a, const void *b));

void my_qsort(void *base, int start, int end, int size, int (*compar)(const void *a, const void *b));

void isort(void *base, int start, int end, int size, int (*compar)(const void *a, const void *b));
```

## Tests
```bash
$ make all
$ ./test
```