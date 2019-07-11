//--------------------------------------------------------------------------
// Includes 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset.h"


//--------------------------------------------------------------------------
// Basic Utilities and Multi-thread Support

#include "util.h"

//--------------------------------------------------------------------------
// contrast function
 
extern void contrast(int coreid, int ncores, int img_height,int img_width, int xMax, int xMin, const data_t img[IMG_HEIGHT][IMG_WIDTH], data_t result[IMG_HEIGHT][IMG_WIDTH]);

//--------------------------------------------------------------------------
// Main
//
// all threads start executing thread_entry(). Use their "coreid" to
// differentiate between threads (each thread is running on a separate core).

void thread_entry(int cid, int nc)
{	
	static data_t results_data[IMG_HEIGHT][IMG_WIDTH];
	
	contrast(cid, nc, IMG_HEIGHT,IMG_WIDTH,xMAX, xMIN, input1_data, results_data);
	printf("PASSOU!\n");

#ifdef PC
	int res = verify(IMG_HEIGHT*IMG_WIDTH/4, (int*)results_data, (int*)verify_data);
	
	if(res) {
		printf("Vish! %d\n",res);
	}
	else
		printf("DEU BOM\n");
#else
	barrier(nc);

	int res = verify(IMG_HEIGHT*IMG_WIDTH/4, (int*)results_data, (int*)verify_data);

	exit(res);
#endif
	
}