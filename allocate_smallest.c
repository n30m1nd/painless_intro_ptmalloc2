#include <stdio.h>
#include <malloc.h>

// This program allocates the smallest chunk possible to show that
// actually in memory will be a 32 bytes sized chunk due to the
// chunk headers in 64 bit (8 byte addressess for fd and bk) 
// Javier Jimenez @ SensePost 2017
int main(){
 void *smallestchunk1, *smallestchunk2;
 smallestchunk1 = malloc(1);
 smallestchunk2 = malloc(1);
 printf("Smallchunk1 at %p, Smallchunk2 at %p\n", smallestchunk1, smallestchunk2);
 printf("Distance from 1 to 2 (ie size): %d\n", smallestchunk2-smallestchunk1);
 return 0;
}
