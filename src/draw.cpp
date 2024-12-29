#include "draw.h"

void Grid::randomizeGrid() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	for (auto &cell : grid) {
		cell = dis(gen);
	}
}

void Grid::setToZero() {
	int size = grid.size();

	if (size == 0) return;

	for (int i = 0; i < size; i++) {
		grid[i] = 0;
	}
	int middleIndex = size / 2;
	grid[middleIndex] = 1;
}

int Grid::checkNeighbor(int x, int y) {

	int count = 0;

	int left = (x - 1 >= 0) ? grid[y * gridWidth + (x - 1)] : 0; // Left neighbor, default 0 if out of bounds
	int center = grid[y * gridWidth + x]; // Current cell
	int right = (x + 1 < gridWidth) ? grid[y * gridWidth + (x + 1)] : 0; // Right neighbor, default 0 if out of bounds


	if (left == 1 && center == 1 && right == 1) return 1;
	if (left == 1 && center == 1 && right == 0) return 0;
	if (left == 1 && center == 0 && right == 1) return 1;
	if (left == 1 && center == 0 && right == 0) return 1;
	if (left == 0 && center == 1 && right == 1) return 0;
	if (left == 0 && center == 1 && right == 0) return 0;
	if (left == 0 && center == 0 && right == 1) return 1;
	if (left == 0 && center == 0 && right == 0) return 0;

	return 0;
}

void Grid::drawCell(int x, int y, Rectangle& cell) {
	cell.x = static_cast<float>(x * cell_size);
	cell.y = static_cast<float>(y * cell_size);

	
	int result = checkNeighbor(x, y);

	if (result == 0) {
		DrawRectangleRec(cell, DARKGRAY);
	}
	else {
		DrawRectangleRec(cell, LIGHTGRAY);
	}
}

void Grid::drawGrid() {
	Rectangle cell = { 0, 0, static_cast<float>(cell_size), static_cast<float>(cell_size) };
	for (int y = 0; y < currentRow; y++) {
		for (int x = 0; x < gridWidth; x++) {
			drawCell(x, y, cell);
		}
	}
}

void Grid::incrementRow() {
	if (currentRow < gridHeight) {
		currentRow++;
	}
}
