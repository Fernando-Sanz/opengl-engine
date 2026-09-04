#pragma once


namespace renderer {
	unsigned int createShaderProgram(const char* vertexshaderCode, const char* fragmentshaderCode);
	void checkShaderCompilation(unsigned int shader);
	void checkShaderProgramLinking(unsigned int shaderProgram);
}
