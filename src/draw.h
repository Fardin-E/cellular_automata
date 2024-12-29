#include "header.h"

class Grid {
private:
	std::vector<int> grid;
	const float cell_size = 20.0f;
	const int gridWidth = 21;
	const int gridHeight = 21;
	int currentRow = 0;
public:
	Grid() {
		grid.resize(gridWidth * gridHeight);
		randomizeGrid();
	}
	void randomizeGrid();
	void setToZero();
	void drawCell(int x, int y, Rectangle& cell);
	int checkNeighbor(int x, int y);
	void drawGrid();
	void incrementRow();
};