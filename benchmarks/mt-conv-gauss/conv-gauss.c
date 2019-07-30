
// See LICENSE for license details.
#include <stdio.h>
#include <stdlib.h>
#include "dataset.h"


short sum(data_t_s window[KERNEL_DIM][KERNEL_DIM]){
    short valOutput = 0;
    for(int idxRow = 0;idxRow < KERNEL_DIM;idxRow++) {
        for(int idxCol = 0; idxCol < KERNEL_DIM; idxCol++) {
            valOutput = valOutput + window[idxRow][idxCol];
        }
    }
    return valOutput/16;
}

void convGauss(int coreid, int ncores, int img_height,int img_width,int kernel_dim, data_t img[IMG_HEIGHT][IMG_WIDTH],data_t_s kernel[KERNEL_DIM*KERNEL_DIM], data_t result[IMG_HEIGHT][IMG_WIDTH])
{
    data_t_s window[kernel_dim][kernel_dim];
    int i;int j;
    short valOutput;
    i=coreid;
    while(i< img_height){
        for(j=0;j<img_width;j++){
            if((i>=kernel_dim-1)&&(j>=kernel_dim-1)&&(i<=img_height-kernel_dim)&&(j<=img_width-kernel_dim)){
                for(int idxWinRow = 0; idxWinRow<kernel_dim; idxWinRow++){
                    for(int idxWinCol = 0; idxWinCol<kernel_dim; idxWinCol++){
                        short val = (short) img[i-1+idxWinRow][j-1+idxWinCol];
                        val = (short) kernel[(idxWinRow*kernel_dim)+idxWinCol] * val;
                        window[idxWinRow][idxWinCol]=val;
                    }
                }
                valOutput = sum(window);
                if(valOutput<0)
                    valOutput=0;
                result[i][j]=valOutput;
            }
            else
                result[i][j]=0;
        }
        i=i+ncores;
    }

}