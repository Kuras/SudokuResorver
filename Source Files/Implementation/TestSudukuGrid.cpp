/*
 * testSudukuGrid.cpp
 *
 *  Created on: 1 gru 2013
 *      Author: Baraka
 */
#include "../Interface/sudukuheader.h"
#include "../Interface/testsudukugrid.h"
#include <cassert>
static void checkClearedForAllCell();
static void testAllFreeCell();
static void fullAllSuduko(sudukoGame game);
static void testFullAllSuduko();
static void fillUpColumn(sudukoGame game, int column);
static void fillUpRow(sudukoGame game, int row);
static void fillUpBox(sudukoGame game, cell firstCellFromBox);
static cell getCellFrom(int row, int column);
static cell getFirstCellFromBox(int row, int column);
static void testGetCellFrom();
static void testClearCell (cell i, sudukoGame game);
static void testSetFreeCell (sudukoGame game, cell i);
static void testGetFreeCell ();
static void testIsFull ();
static void testIsLegal ();
/*
clearGame(sudukoGrid game)
testClearGame()
testGetSetCell()
teatIsFullFreeCell()
testFullGrid(sudukoGrid game,cell
testIsLegal()

 */
static void clearGame(sudukoGame game);
static void testMostCommonValue ();

void testSudukoGrid() {

	cout << "testing SudukoGrid.cpp...\n";
/*
 testClearGame ()
testGetSetCell ()
testIsFullFreeCell ()
testIsLegal ()

clearGame (game1)
showGame (game1)

 */
	testMostCommonValue ();

	checkClearedForAllCell();

	testAllFreeCell();

	testGetFreeCell();

	testIsFull();

	testFullAllSuduko();

	testGetCellFrom();
//	testIsLegal ();

	cout << "All tests passed:)!";
}

static void checkClearedForAllCell() {
	int i = 0;
	sudukoGame game;
	while (i <= MAX_CELL) {
		testClearCell(i, game);
		i++;
	}

}
// write getCell
void testClearCell(cell i, sudukoGame game) {
	clearCell(game, i);
	assert(game[i] == EMPTY_VALUE);
}

static void testAllFreeCell() {
	sudukoGame game;
	int i = 0;
	while (i <= MAX_CELL) {
		testSetFreeCell(game, i);
		i++;
	}
}

void testSetFreeCell(sudukoGame game, cell i) {
	bool isFree = true;
	value previousValueForCell;
	if (MIN_VALUE <= game[i] && game[i] <= MAX_VALUE) {
		isFree = false;
		previousValueForCell = game[i];
	}
	value tryValue = MIN_VALUE;

	while (tryValue <= MAX_VALUE) {

		setFreeCell(game, i, tryValue);

		if (isFree) {
			assert(game[i] == tryValue);
		} else {
			assert(game[i] == previousValueForCell);
		}
		clearCell(game, i);
		tryValue++;
	}

}

void testGetFreeCell() {
	sudukoGame game; //exist at least free cell in suduko!
	cell freeCell;
	freeCell = getFreeCell(game);
	assert(0 <= freeCell && freeCell <= 80);
	assert(game[freeCell] == EMPTY_VALUE);
}

void testIsFull() {
	bool full;
	sudukoGame game;
	fullAllSuduko(game);

	full = isFull(game);
	assert(full == true);

	int i = 0;
	while (i <= 80) {

		clearCell(game, i);
		full = isFull(game);
		assert(full == false);

		i++;
		setFreeCell(game, i - 1, MIN_VALUE);
	}
}

static void fullAllSuduko(sudukoGame game) {
	int i = 0;
	while (i <= 80) {
		game[i] = '1';
		i++;
	}
}

static void testFullAllSuduko() {
	sudukoGame game;

	fullAllSuduko(game);
	int i = 0;
	while (i <= 80) {
		assert(game[i] != EMPTY_VALUE);
		i++;
	}
}

void testIsLegal() {
	sudukoGame game;
	int column=0;
	int row=0;
	bool legal;
	cell tryCell = getCellFrom(row, column);
	value initrialValue;
	// assumption tested number must be from this set [0,80]

	fillUpColumn(game, column);
	fillUpRow(game, row);
	fillUpBox(game, getFirstCellFromBox(row, column));
	clearCell(game, tryCell);

	legal = isLegal(game, tryCell, initrialValue);
	assert(legal == false);

}

static void fillUpColumn(sudukoGame game, int column) {

}

static void fillUpRow(sudukoGame game, int row) {

}

static void fillUpBox(sudukoGame game, cell firstCellFromBox) {

}

static cell getCellFrom(int row, int column) {
	cell cellRef;
	assert(0 <= row && row <= 8);
	assert(0 <= column && column <= 8);
	cellRef = row * 9 + column;
	return cellRef;
}

static cell getFirstCellFromBox(int row, int column) {
	cell firstCell;

	return firstCell;
}

static void testGetCellFrom() {
	cell tryCell;
	int r = 0;
	//assumptions row, column [0,8]
	while (r <= 8) {
		tryCell = getCellFrom(r, 0);
		assert(tryCell == r*9);
		r++;

	}
	int c = 0;
	while (c <= 8) {
		tryCell = getCellFrom(0, c);
		assert(tryCell == c);
		c++;

	}
	r = 0;
	c = 0;
	while (r <= 8){
		while (c <= 8) {
			tryCell = getCellFrom(r, c);
			assert(tryCell == r*9 + c);
			c++;
		}
		r++;
	}
}
//=========================
static void clearGame(sudukoGame game){
	cell currentCell = 0;
	while (currentCell <= MAX_CELL){
		game[currentCell] = EMPTY_VALUE;
		currentCell++;
	}
}


static void testMostCommonValue (){
	sudukoGame grid;
	sudukoGame fullGrid = {
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9',
		'1','2','3','4','5','6','7','8','9'
	};
	clearGame(grid);
	value common;

	cout << "Testing mostCommonValue\n";
	//test works for empty grid
	common = mostCommonValue(grid);
	assert(common <= MAX_VALUE);
	assert(common >= MIN_VALUE);
	//test returns legal value for full grid
	common = mostCommonValue(fullGrid);
	assert(common <= MAX_VALUE);
	assert(common >= MIN_VALUE);

}
