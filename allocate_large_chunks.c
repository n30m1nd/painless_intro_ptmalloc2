#include <stdio.h>
#include <malloc.h>

// This program allocates large chunks so we can inspect the P->fd_nextsize
// and P->bk_nextsize pointers in memory.

// Javier Jimenez @ SensePost 2017

int main(){
 void *large1,*large2, *large3, *large4; 

 printf("[info] allocating 4 large chunks (+0x400 bytes each)\n");
 large1 = malloc(0x3f0);
 large2 = malloc(0x3f0);
 large3 = malloc(0x3f0);
 large4 = malloc(0x3f0);
 printf("[+] large1 at %p\n", large1);
 printf("[+] \tdistance: %ld\n", large2-large1);
 printf("[+] large2 at %p\n", large2);
 printf("[+] \tdistance: %ld\n", large3-large2);
 printf("[+] large3 at %p\n", large3);
 printf("[+] \tdistance: %ld\n", large4-large3);
 printf("[+] large4 at %p\n", large4);
 printf("[info] freeing large1 and large2\n");
 free(large1);
 free(large3);
 return 0;
}
