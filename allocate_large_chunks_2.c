#include <stdio.h>
#include <malloc.h>

// This program allocate large chunks and then frees the odd ones to
// cause fragmentation so we can inspect what happens to the 
// P->fd_nextsize and P->bk_nextsize pointers in memory

// Javier Jimenez @ SensePost 2017

int main(){
 void *large1, *large2, *large3, *large4, *large5, *large6; 

 printf("[info] allocating 2 large chunks (+1024 bytes each)\n");
 large1 = malloc(20050);
 large2 = malloc(20025);
 large3 = malloc(20058);
 large4 = malloc(20060);
 large5 = malloc(20068);
 large6 = malloc(20075);
 printf("[+] large1 at %p\n", large1);
 printf("[+] \tdistance: %ld\n", large2-large1);
 printf("[+] large2 at %p\n", large2);
 printf("[+] \tdistance: %ld\n", large3-large2);
 printf("[+] large3 at %p\n", large3);
 printf("[+] \tdistance: %ld\n", large4-large3);
 printf("[+] large4 at %p\n", large4);
 printf("[+] \tdistance: %ld\n", large5-large4);
 printf("[+] large5 at %p\n", large5);
 printf("[+] \tdistance: %ld\n", large6-large5);
 printf("[+] large6 at %p\n", large6);
 printf("[info] freeing larges 1 3 5\n");
 free(large1);
 free(large3);
 free(large5);
 return 0;
}
