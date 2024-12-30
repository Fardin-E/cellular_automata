#include "draw.h"

int main() {

	const int screenWidth = 1200;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);

	Camera2D camera = { 0, 0 };
	camera.zoom = 1.0f;

	Grid grid(500, 500, 5.0f);
	grid.setToZero();

	while (!WindowShouldClose()) {

		// camera
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			Vector2 delta = GetMouseDelta();
			delta = Vector2Scale(delta, -1.0f / camera.zoom);
			camera.target = Vector2Add(camera.target, delta);
		}

		float wheel = GetMouseWheelMove();
		if (wheel != 0) {
			Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
			camera.offset = GetMousePosition();
			camera.target = mouseWorldPos;
			float scaleFactor = 1.0f + (0.25f * fabs(wheel));
			if (wheel < 0) scaleFactor = 1.0f / scaleFactor;
			camera.zoom = Clamp(camera.zoom * scaleFactor, 0.125f, 64.0f);
		}

		// Update
		grid.incrementRow();

		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode2D(camera);
		grid.drawGrid();

		EndMode2D();

		EndDrawing();

	}

	CloseWindow();

	return 0;
}