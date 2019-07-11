
#ifdef PC

#include <stdlib.h>
#include <stdio.h>
#include "dataset.h"
#include "util.h"


extern void contrast(int coreid, int ncores, int img_height,int img_width, int xMax, int xMin, const data_t img[IMG_HEIGHT][IMG_WIDTH], data_t result[IMG_HEIGHT][IMG_WIDTH]);
extern void thread_entry(int cid, int nc);

int main(){
	static data_t results_data[IMG_HEIGHT][IMG_WIDTH];
	
	thread_entry(0, 4);
	thread_entry(1, 4);
	thread_entry(2, 4);
	thread_entry(3, 4);

}
#endif