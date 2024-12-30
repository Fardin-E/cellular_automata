#include "draw.h"

void Grid::randomizeGrid() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	for (auto &cell : grid[currentRow]) {
		cell = dis(gen);
	}
}

void Grid::setToZero() {
	for (int i = 0; i < gridWidth; i++) {
		grid[currentRow][i] = 0;
	}
	int middleIndex = gridWidth / 2;
	grid[currentRow][middleIndex] = 1;
}

int Grid::checkNeighbor(int x, int prevRow) {
	// Get the states of the three cells above
	int left = (x > 0) ? grid[prevRow][x - 1] : 0;
	int center = grid[prevRow][x];
	int right = (x < gridWidth - 1) ? grid[prevRow][x + 1] : 0;

	// Convert the three cells into a binary number (0-7)
	int pattern = (left * 4) | (center * 2) + right;

	// ruleset
	int rule = 110;
	
	/*
	* example: 
	* rule = 30 (00011110)
	* pattern = 6
	* rule >> pattern = 00011110 >> 6 = 00000000
	* 00000000 & 1 = 0 (returns 0)
	* the & 1 at the end checks the rightmost bit
	*/
	return (rule >> pattern) & 1;
}

void Grid::drawCell(int x, int y, Rectangle& cell) {
	cell.x = static_cast<float>(x * cell_size);
	cell.y = static_cast<float>(y * cell_size);

	
	int cellBox = grid[y][x];

	if (cellBox == 0) {
		DrawRectangleRec(cell, LIGHTGRAY);
	}
	else {
		DrawRectangleRec(cell, DARKGRAY);
	}
}

void Grid::drawGrid() {
	Rectangle cell = { 0, 0, static_cast<float>(cell_size), static_cast<float>(cell_size) };
	for (int y = 0; y <= currentRow; y++) {
		for (int x = 0; x < gridWidth; x++) {
			drawCell(x, y, cell);
		}
	}
}

void Grid::incrementRow() {
	if (currentRow < gridHeight - 1) {
		currentRow++;
	}

	// create the next generation based on the current one
	for (int x = 0; x < gridWidth; x++) {
		grid[currentRow][x] = checkNeighbor(x, currentRow - 1);
	}
}
