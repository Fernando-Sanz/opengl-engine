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

	constexpr float exercise1Vertices[] = {
		-0.8f, -0.5f, 0.0f,
		-0.4f, 0.5f, 0.0f,
		0.0f, -0.5f, 0.0f,
		0.4f, 0.5f, 0.0f,
		0.8f, -0.5f, 0.0f,
	};
	unsigned int exercise1Indices[] = {
		0, 1, 2,
		2, 3, 4
	};
}
