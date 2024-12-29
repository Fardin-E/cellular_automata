#include "header.h"

class Grid {
private:
	std::vector<int> grid;
	const float cell_size = 20.0f;
	const int gridWidth = 20;
	const int gridHeight = 20;
	int currentRow = 0;
public:
	Grid() {
		grid.resize(gridWidth * gridHeight);
		randomizeGrid();
	}
	void randomizeGrid();
	void drawCell(int x, int y, Rectangle& cell);
	void drawGrid();
	void incrementRow();
};