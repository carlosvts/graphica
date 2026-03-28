#pragma once
#include <utility>
#include <cmath>
struct Viewport
{
	// mathematical interval
	float xmin {-10.0}, xmax{10.0};
	float ymin {-10.0}, ymax{10.0};

	int width {}, height {};
	
	Viewport(int w, int h) : width(w), height(h) {}
	
	Vector2 world_to_screen(float wx, float wy)
	{
		// proportion: pixels per world 
		float kx = (static_cast<float>(width)/(xmax - xmin));
		float ky = (static_cast<float>(height)/(ymax - ymin));

		float px = (wx - xmin) * kx;
		// world has y increasing to top, pixels increase y in negative way
		float py = (ymax - wy) * ky;
		
		return  (Vector2) {px, py};
	}

	float screen_to_world_x(float px)
	{
		// todo
		float kx =(static_cast<float>(width)/(xmax - xmin));	
		float wx = (px/kx) + xmin;
		return wx;
	}
};
