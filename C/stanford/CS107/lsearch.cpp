#include <iostream>
using namespace std;

// basic generic array search
void* lsearch(void *key, void *base, int n, int elemsize) {
  for (int i = 0; i < n; ++i) {
    void *elemaddr = (char*)base + i*elemsize;    // casting to char* to allow pointer arithmetic against void*
    if (memcmp(key, elemaddr, elemsize) == 0)
       return elemaddr;
  }
  return NULL;
}

// better generic array search
void* lsearch(void *key, void *base, int n, int elemsize, int (*cmpfn)(void*, void*)) {
  for (int i = 0; i < n; ++i) {
    void *elemaddr = (char*)base + i*elemsize;    // casting to char* to allow pointer arithmethic against void*
    if (cmpfn(key, elemaddr) == 0)    // 0 if equal
      return elemaddr;
  }
  return NULL;
} 

// USAGE with INT
int intcmp(void*, void*); // returns 0 if found
int arr[5];
int size = 5;
int key = 3;
int *found = (int*)lsearch(&key, arr, 6, sizeof(int), intcmp);

// INT COMPARE FUNCTION
int intcmp(void *elem1, void *elem2) {
  int *ip1 = (int*)elem1;   // reinterpret cast
  int *ip2 = (int*)elem2;
  return *ip1 - *ip2;
}

// USAGE with CHAR
int Strcmp(void *vp1, void *vp2);
char* notes[] = {"a", "b", "c", "d"};
char *fn = "b";
char **found = (char**)lsearch(&fn, notes, 5, sizeof(char*), Strcmp);

// STR COMPARE FUNCTION
int Strcmp(void *vp1, void *vp2) {
  char *s1 = *(char**)vp1;    // casting to ** as I know they really are **
  char *s2 = *(char**)vp2;    // then dereferencing once to get to the CStrings
  return strcmp(s1, s2);      // to pass them to strcmp.
}

// BUILT-IN BSEARCH lowercase)
void *Bsearch(void *key, void *base, int n, int elemsize, int (*cmp)(void*, void*));