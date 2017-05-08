#include <stdio.h>
#include <malloc.h>
// This program allocates the next smallest chunk possible to show that
// memory will be padded to 16 bytes more, also due to the
// chunk headers needing 8 byte addressess for fd and bk
// (32 + 16 = 48)
// Javier Jimenez @ SensePost 2017
int main(){
 void *smallestchunk1, *smallestchunk2;
 smallestchunk1 = malloc(25);
 smallestchunk2 = malloc(25);
 printf("Smallchunk1 at %p, Smallchunk2 at %p\n", smallestchunk1, smallestchunk2);
 return 0;
}
