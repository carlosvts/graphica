#include <iostream>
#include <raylib.h>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

int main()
{
	InitWindow(WIDTH, HEIGHT, "function plotter - carlosvts");

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Plotter", 190, 200, 20, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
