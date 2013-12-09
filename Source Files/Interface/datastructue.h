/*
 * datastructue.h
 *
 *  Created on: 1 gru 2013
 *      Author: Baraka
 */

#ifndef DATASTRUCTUE_H_
#define DATASTRUCTUE_H_


#include<iostream>
#include<cstdlib>
using namespace std;

#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'
#define NUM_VALUES ((MAX_VALUE - MIN_VALUE) + 1)
#define GRID_SIZE (NUM_VALUES * NUM_VALUES)
#define MAX_CELL (GRID_SIZE - 1)
#define MIN_CELL 0

typedef char value;
typedef int cell;
typedef value sudukoGame [GRID_SIZE];



#endif /* DATASTRUCTUE_H_ */
