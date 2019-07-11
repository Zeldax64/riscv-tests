// See LICENSE for license details.

#ifndef __DATASET_H
#define __DATASET_H
#define IMG_HEIGHT 4
#define IMG_WIDTH 4
#define xMAX 185
#define xMIN 72


typedef unsigned char data_t;static data_t input1_data[IMG_HEIGHT][IMG_WIDTH] ={
{146,146,145,145},
{146,146,145,145},
{146,145,144,145},
{144,144,144,144}
};


static data_t verify_data[IMG_HEIGHT][IMG_WIDTH] ={
{166,166,164,164},
{166,166,164,164},
{166,164,162,164},
{162,162,162,162}
};

#endif