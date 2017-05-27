#include <iostream>
using namespace std;

// basic generic C swap
void swap(void *vp1, void *vp2, int size) {
  char buffer[size];    // convert to dynamic allocation using new
  memcpy(buffer, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, buffer, size);
} // USAGE





int main(int argc, char *argv[]) {
  int int1, int2;
  swap(&int1, &int2, sizeof(int));





  return 0; 
}