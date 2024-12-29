#include "draw.h"

int main() {

	const int screenWidth = 800;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(20);

	Grid grid;

	while (!WindowShouldClose()) {
		// Update
		grid.incrementRow();

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);
		grid.drawGrid();

		EndDrawing();

	}

	CloseWindow();


	return 0;
}