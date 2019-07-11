// See LICENSE for license details.

#include "dataset.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

#pragma GCC optimize ("unroll-loops")

void contrast(int coreid, int ncores, int img_height,int img_width, int xMax, int xMin, const data_t img[IMG_HEIGHT][IMG_WIDTH], data_t result[IMG_HEIGHT][IMG_WIDTH]){

	float xMax_minus_xMin= xMax-xMin;

	size_t i, j;
    size_t start = coreid;
    i=start;
	while(i < img_height){
		for(j = 0; j < img_width; j++){
			// Get the pixel data
			unsigned char x_t = img[i][j];

			// Calculate the histogram strech (calculate in float then convert to 8-bits)
			float y_t_float=((x_t- xMin)/(xMax_minus_xMin))*255;

			int y_t=y_t_float;
			result[i][j]=y_t;

		}

		i=i+ncores;
	}
}
