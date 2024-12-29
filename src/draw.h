#include "header.h"

class Grid {
private:
	std::vector<std::vector<int>> grid;
	const float cell_size;
	const int gridWidth;
	const int gridHeight;
	int currentRow = 0;
public:
	Grid(int width, int height, int cellSize)
		: gridWidth(width), gridHeight(height),
		cell_size(cellSize), currentRow(0) 
	{
		grid.resize(gridHeight, std::vector<int>(gridWidth));
	}

	void randomizeGrid();
	void setToZero();
	void drawCell(int x, int y, Rectangle& cell);
	int checkNeighbor(int x, int y);
	void drawGrid();
	void incrementRow();
};