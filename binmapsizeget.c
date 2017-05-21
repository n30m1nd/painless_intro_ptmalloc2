#include <stdio.h>

#define NBINS		128
#define BINMAPSHIFT      5
#define BITSPERMAP       (1U << BINMAPSHIFT)
#define BINMAPSIZE       (NBINS / BITSPERMAP)

// This program give us a visual representation of 
// the sizes used by the bins in malloc.c 
// Javier Jimenez @ SensePost 2017

int main(){
 printf("NBINS:%u BINMAPSHIFT:%u BITSPERMAP:%u BINMAPSIZE:%u\n",NBINS,BINMAPSHIFT,BITSPERMAP,BINMAPSIZE);
 return 0;
}
