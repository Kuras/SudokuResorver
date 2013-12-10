/*
 * SudukuImplementation.cpp
 *
 *  Created on: 1 gru 2013
 *      Author: Baraka
 */

#include "../Interface/sudukuheader.h"
#include<cassert>

static cell getFirstCellFromBox(cell candidateCell);
static bool isLegalInRow (sudukoGame game,cell candidateCell,value initialValue);
static bool isLegalInColumn (sudukoGame game,cell candidateCell,value initialValue);
static bool isLegalOnBox (sudukoGame game,cell candidateCell,value initialValue);
static value getIndexforTheBigestQuant (int count[]);

void notSholution();
bool hasSolution (sudukoGame game);//side effect

bool hasSolution (sudukoGame game) {

	bool solved = false;
	cell candidateCell;
	value trailValue;

	if (isFull (game)) {
		solved = true;
	} else {
		candidateCell = getFreeCell(game);
		trailValue = MIN_VALUE;

		while (!solved && trailValue <= MAX_VALUE) {
			if (isLegal(game,candidateCell,trailValue)) {
				setFreeCell(game,candidateCell,trailValue);
				if (hasSolution(game)) {
					solved = true;
				} else {
					clearCell (game,candidateCell);
				}
			}
			trailValue++;
		}

	}
	return solved;
}

void loadGame (sudukoGame game) {
	value cellValue;
	int i = 0;

	while(i <= MAX_CELL){
		cin >> cellValue;
		if((MIN_VALUE <= cellValue && cellValue <= MAX_VALUE) || cellValue == EMPTY_VALUE) {
			game[i] = cellValue;
			i++;
		}
	}

}

void showGame (sudukoGame game) {
	int i = 0;

	while(i <= MAX_CELL) {
		cout << " " << game[i] << " ";
		if ( (i+1)%NUM_VALUES == 0 )
			cout << endl;
		i++;
	}
}

bool isFull(sudukoGame game) {
	bool full = true;
	cell trialCell = MIN_CELL;
	while ( full && trialCell <= MAX_CELL) {
		if (game[trialCell] == EMPTY_VALUE) {
			full = false;
		}
		trialCell++;
	}
	return	full;
}

cell getFreeCell(sudukoGame game) {
	cell trialCell = MIN_CELL;
	cell freeCell;
	bool find = false;

	while (!find && trialCell <= MAX_CELL) {
		if (game[trialCell] == EMPTY_VALUE) {
			freeCell = trialCell;
			find = true;
		}
		trialCell++;
	}
	assert(MIN_CELL <= freeCell && freeCell <= MAX_CELL);

	return freeCell;
}

void setFreeCell(sudukoGame game,cell candidateCell,value initialValue) {
	assert(MIN_CELL <= candidateCell && candidateCell <= MAX_CELL); // assume
	if(game[candidateCell] < MIN_VALUE || MAX_VALUE < game[candidateCell]){
		game[candidateCell] = initialValue;
	}

}

void clearCell (sudukoGame game,cell candidateCell) {
	assert(MIN_CELL <= candidateCell && candidateCell <= MAX_CELL);
		game[candidateCell] = EMPTY_VALUE;

}

bool isLegal(sudukoGame game,cell candidateCell,value initialValue) {
	bool legal = false;
	assert(MIN_CELL <= candidateCell && candidateCell <= MAX_CELL);

	if (isLegalInRow(game,candidateCell,initialValue)) {
		if (isLegalInColumn(game,candidateCell,initialValue)) {
			if (isLegalOnBox(game,candidateCell,initialValue)) {
				legal =true;
			}
		}
	}

	return legal;
}

static bool isLegalInRow(sudukoGame game,cell candidateCell,value initialValue) {
	bool legal = true;

    int row = candidateCell / NUM_VALUES;
    cell trialCell = row * NUM_VALUES;
    cell maxOfCellInRow = trialCell + (NUM_VALUES-1);
    while (legal && trialCell <= maxOfCellInRow) {
    	if (trialCell != candidateCell && game[trialCell] == initialValue) {
    		legal = false;
    	}
    	trialCell++;
    }

	return legal;
}

static bool isLegalInColumn(sudukoGame game,cell candidateCell,value initialValue) {
	bool legal = true;

    int column = candidateCell % NUM_VALUES;
    cell trialCell = column;
    cell maxOfCellInColumn = trialCell + NUM_VALUES * 8 ;
    while (legal && trialCell <= maxOfCellInColumn) {
    	if (trialCell != candidateCell && game[trialCell] == initialValue) {
    		legal = false;
    	}
    	trialCell = trialCell + NUM_VALUES;
    }

	return legal;
}

static bool isLegalOnBox(sudukoGame game,cell candidateCell,value initialValue) {
	bool legal = true;

	cell topLeftCell = getFirstCellFromBox(candidateCell);
	cell trialCell = topLeftCell;
	int row = 0;
	while (legal && row <= 2) {
		trialCell = topLeftCell + row * 9;
		int column = 0;
		while (legal && column <= 2) {
			trialCell = trialCell + column;
			if (trialCell != candidateCell && game[trialCell] == initialValue){
				legal = false;
			}
			column ++;
		}
		row ++;
	}


	return legal;
}

static cell getFirstCellFromBox(cell candidateCell) {
	cell topLeftCell;
	int column = candidateCell % NUM_VALUES;
    int row = candidateCell / NUM_VALUES;
    //topLeftCell = (column / 3) * 3 + (row / 3) * (3 * 9);
    topLeftCell = (int) (row / 3);
    topLeftCell *= 3 * 9;
    topLeftCell += ((int) (column / 3) ) * 3;

    return topLeftCell;
}

void notSholution() {
	cout << endl << "Not soulution here!" <<endl;
}


value mostCommonValue (sudukoGame game){
	int count[NUM_VALUES] = {0};
	value possibleValue = MIN_VALUE;

	while (possibleValue <= MAX_VALUE) {
		cell cellRef = MIN_CELL;
		int i = 0;
		while (cellRef <= MAX_CELL){
			if (game[cellRef] == possibleValue){
				count[i]++;
			}
			cellRef++;
		}
		i++;
		possibleValue++;
	}
	value commonValue = (value)(1 + getIndexforTheBigestQuant (count));
	return commonValue;
}

static value getIndexforTheBigestQuant (int count[]){
	int bigestIndex;
	int tempIndex=0;
	bigestIndex = tempIndex++;
		while (tempIndex < 9){
			if (count[tempIndex] >= count[bigestIndex]){
				bigestIndex = tempIndex;
			}
			tempIndex++;
		}
	return (value) bigestIndex;
}
