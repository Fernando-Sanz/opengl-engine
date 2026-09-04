#pragma once


namespace assets {

	constexpr float triangleVertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	constexpr float squareVertices[] = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	unsigned int squareIndices[] = {
		0, 1, 3,
		1, 2, 3
	};

	constexpr float exercise2Vertices1[] = {
		-0.8f, -0.5f, 0.0f,
		-0.4f, 0.5f, 0.0f,
		0.0f, -0.5f, 0.0f,
	};
	unsigned int exercise2Indices1[] = {
		0, 1, 2,
	};
	constexpr float exercise2Vertices2[] = {
		0.0f, -0.5f, 0.0f,
		0.4f, 0.5f, 0.0f,
		0.8f, -0.5f, 0.0f,
	};
	unsigned int exercise2Indices2[] = {
		0, 1, 2
	};
}
