#include <iostream>
#include <raylib.h>
#include <vector>
#include <functional>
#include <cmath>

#include "viewport.hpp"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
Viewport vp {WIDTH, HEIGHT};

void plot_cross()
{
	
	std::vector<Vector2> axis;
	axis.push_back(vp.world_to_screen(0, vp.ymax));
	axis.push_back(vp.world_to_screen(0, vp.ymin));
	axis.push_back(vp.world_to_screen(vp.xmin, 0));
	axis.push_back(vp.world_to_screen(vp.xmax, 0));

	// draw axis 
	for (size_t i {}; i < axis.size(); ++i)
	{
		DrawLineV(axis.at(i), axis.at(i+1), RAYWHITE);
		++i;
	}
	// draw x and y 
	DrawText("x", vp.width - 10, vp.height / 2.0, 20, RAYWHITE);
	DrawText("y", 10 + (vp.width / 2.0), 0, 20, RAYWHITE);
}

void plot(std::function<float(float)> f)
{
	for (int px {}; px < WIDTH; ++px)
	{
		float wx = vp.screen_to_world_x(px);
		float wy {f(wx)};
		Vector2 point = vp.world_to_screen(wx, wy);
		DrawPixel(point.x, point.y, RED);
	}

}

float f(float x)
{
	return x;
}

float g(float x)
{
	return std::sin(x);
}

int main()
{
	InitWindow(WIDTH, HEIGHT, "function plotter - carlosvts");
	Viewport vp {WIDTH, HEIGHT};

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			plot_cross();
			plot(g);
			plot(f);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
