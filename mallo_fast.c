// Malloc heap "fragmentation" example for SensePost's blog
// Javier Jimenez @ SensePost 2017

#include <malloc.h>
#include <stdio.h>

// Taken from ptmalloc2 implementation
#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof (INTERNAL_SIZE_T))
#define MAX_FAST_SIZE (80 * SIZE_SZ / 4)

int main(){
 void *malloc1, *malloc2;
 printf("[info] MAX_FAST_SIZE == %zu\n", MAX_FAST_SIZE);
 printf("[info] Allocating 2 malloc of size greater than MAX_FAST_SIZE\n");
 malloc1 = malloc(MAX_FAST_SIZE+16);
 malloc2 = malloc(MAX_FAST_SIZE+16);
 printf("[+]\t malloc1 at %p and malloc2 at %p\n", malloc1, malloc2);

 // Allocating 1 fast malloc and 1 malloc twice to cause fragmentation
 void *fastmalloc1, *malloc3, *fastmalloc2, *malloc4;
 printf("[info] Allocating 1 fast malloc and 1 malloc twice\n");
 fastmalloc1 = malloc(20);
 malloc3 = malloc(MAX_FAST_SIZE+16);
 fastmalloc2 = malloc(20);
 malloc4 = malloc(MAX_FAST_SIZE+16);
 printf("[+]\t %smalloc%d is at %p\n", "fast", 1, fastmalloc1);
 printf("[+]\t %smalloc%d is at %p\n", "", 3, malloc3);
 printf("[+]\t %smalloc%d is at %p\n", "fast", 2, fastmalloc2);
 printf("[+]\t %smalloc%d is at %p\n", "", 4, malloc4);
 printf("[info] The heap is now as follows\n");
 printf("[info] %s\t%p\n", "malloc1    ", malloc1);
 printf("[info] \tdistance: %zu\n", malloc2-malloc1);
 printf("[info] %s\t%p\n", "malloc2    ", malloc2);
 printf("[info] \tdistance: %zu\n", fastmalloc1-malloc2);
 printf("[info] %s\t%p\n", "fastmalloc1", fastmalloc1);
 printf("[info] \tdistance: %zu\n", malloc3-fastmalloc1);
 printf("[info] %s\t%p\n", "malloc3    ", malloc3);
 printf("[info] \tdistance: %zu\n", fastmalloc2-malloc3);
 printf("[info] %s\t%p\n", "fastmalloc2", fastmalloc2);
 printf("[info] \tdistance: %zu\n", malloc4-fastmalloc2);
 printf("[info] %s\t%p\n", "malloc4    ", malloc4);

 // Now we are going to cause fragmentation in the heap
 printf("\n[info] Now causing some fragmentation by freeing the two fastmallocs \n\t\
and the malloc3\n");
 free(fastmalloc1);
 free(malloc3);
 free(fastmalloc2);
 
 void *malloc5, *malloc6;
 printf("[info] Allocating malloc5...\n");
 malloc5 = malloc(MAX_FAST_SIZE+16);
 printf("[+] \tmalloc5 is at %p \n", malloc5);
 malloc6 = malloc(MAX_FAST_SIZE+16);
 printf("[+] \tmalloc6 is at %p \n", malloc6);
 printf("[info] We can check that the pointer used for malloc5(%p) was\n\t the old malloc3(%p)\n\
\tinstead of using the start of the big freed space starting \n\tat fastmalloc1(%p)\n", malloc5, malloc3, fastmalloc1);
 return 0;
}
