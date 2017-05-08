#include <stdio.h>
#include <malloc.h>

// Taken from ptmalloc2 implementation
#define MALLOC_ALIGNMENT 2 * sizeof(size_t)
#define INTERNAL_SIZE_T size_t
#define SIZE_SZ (sizeof (INTERNAL_SIZE_T))
#define MAX_FAST_SIZE (80 * SIZE_SZ / 4)
#define NBINS             128
#define NSMALLBINS         64
#define SMALLBIN_WIDTH    MALLOC_ALIGNMENT
#define SMALLBIN_CORRECTION (MALLOC_ALIGNMENT > 2 * SIZE_SZ)
#define MIN_LARGE_SIZE    ((NSMALLBINS - SMALLBIN_CORRECTION) * SMALLBIN_WIDTH)

#define in_smallbin_range(sz)  \
  ((unsigned long) (sz) < (unsigned long) MIN_LARGE_SIZE)


int main(){
 printf("MIN_LARGE_SIZE = %lu\n", MIN_LARGE_SIZE);
 printf("1023 is small: %d. 1025 is not: %d.\n", in_smallbin_range(1023), in_smallbin_range(1025));
 return 0;
}
