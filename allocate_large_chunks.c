#include <stdio.h>
#include <malloc.h>

// This program allocates large chunks so we can inspect the P->fd_nextsize
// and P->bk_nextsize pointers in memory.

// Javier Jimenez @ SensePost 2017

int main(){
 void *large1,*large2, *large3; 

 printf("[info] allocating 2 large chunks (+1024 bytes each)\n");
 large1 = malloc(1025);
 large2 = malloc(1025);
 large3 = malloc(1025);
 printf("[+] large1 at %p\n", large1);
 printf("[+] \tdistance: %ld\n", large2-large1);
 printf("[+] large2 at %p\n", large2);
 printf("[+] \tdistance: %ld\n", large3-large2);
 printf("[+] large3 at %p\n", large3);
 printf("[info] freeing large2\n");
 free(large2);
 return 0;
}
