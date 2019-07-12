// See LICENSE for license details.

//**************************************************************************
// Contrast adjustment benchmark
//--------------------------------------------------------------------------
// Authors  : Caio Vieira, Jorge Reis
//
// This benchmarks performs a histogram strecthing in a image
// represented by a matrix and writes the results to a result
// matrix. The input (and reference data) should be generated
// using the contrast_gendata.py python script and dumped to
// a file named dataset.h. Be aware that the image must have
// IMG_WIDTH*IMG_HEIGHT%4=0 dimesions due to use of veirify()
// function in "utils.h". A image of Lena is used as dataset.

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
	
	contrast(cid, nc, IMG_HEIGHT,IMG_WIDTH, xMAX, xMIN, input1_data, results_data);

	barrier(nc);

	int res = verify(IMG_HEIGHT*IMG_WIDTH/4, (int*)results_data, (int*)verify_data);

	exit(res);	
}