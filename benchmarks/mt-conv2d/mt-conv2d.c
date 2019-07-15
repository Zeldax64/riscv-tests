// See LICENSE for license details.

//**************************************************************************
// Contrast adjustment benchmark
//--------------------------------------------------------------------------
// Authors  : Caio Vieira, Jorge Reis
//
// This benchmarks performs a 2-Dimensional convolution using an image
// represented by a matrix and a 3x3 sobel filter.The result is written to a result
// matrix. The input (and reference data) should be generated
// using the conv_gendata.py python script and dumped to
// a file named dataset.h. Be aware that the image must have
// IMG_WIDTH*IMG_HEIGHT%4=0 dimensions due to use of verify()
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
// 2-D convolution function
 
extern void conv2d(int coreid, int ncores, int img_height,int img_width,int kernel_dim, data_t img[IMG_HEIGHT][IMG_WIDTH],data_t_s kernel[KERNEL_DIM*KERNEL_DIM], data_t result[IMG_HEIGHT][IMG_WIDTH]);

//--------------------------------------------------------------------------
// Main
//
// all threads start executing thread_entry(). Use their "coreid" to
// differentiate between threads (each thread is running on a separate core).

void thread_entry(int cid, int nc)
{	
	static data_t results_data[IMG_HEIGHT][IMG_WIDTH];
	
	conv2d(cid, nc, IMG_HEIGHT, IMG_WIDTH, KERNEL_DIM, input1_data,input2_data, results_data);

	barrier(nc);

	int res = verify(IMG_HEIGHT*IMG_WIDTH/4, (int*)results_data, (int*)verify_data);

	exit(res);	
}