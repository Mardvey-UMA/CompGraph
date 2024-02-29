#pragma once
#include "Matrix.h"
#include <vector>
class path {
public:
	std::vector<vec2> vertices; // последовательность точек
	vec3 color; // цвет, разбитый на составл€ющие RGB
	float thickness; // толщина линии
	path(std::vector<vec2> verts, vec3 col, float thickn) {
		vertices = verts;
		color = col;
		thickness = thickn;
	}
};