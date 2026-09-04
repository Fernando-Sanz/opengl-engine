#pragma once


namespace assets {
	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main()\n"
		"{\n"
		"   fragColor = vec4(0.5f, 0.7f, 1.0f, 1.0f);\n"
		"}\0";
	const char* fragmentShaderSource2 =
		"#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main()\n"
		"{\n"
		"   fragColor = vec4(1f, 0.3f, 0.7f, 1.0f);\n"
		"}\0";
}
