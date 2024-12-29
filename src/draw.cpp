#include "draw.h"

void Grid::randomizeGrid() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	for (auto &cell : grid) {
		cell = dis(gen);
	}
}

void Grid::drawCell(int x, int y, Rectangle& cell) {
	cell.x = static_cast<float>(x * cell_size);
	cell.y = static_cast<float>(y * cell_size);

	if (grid[y * gridWidth + x] == 0) {
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