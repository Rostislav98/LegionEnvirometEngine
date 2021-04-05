#include "Shader.h"

#include<GLFW/glfw3.h>
#include<glad/glad.h>
#include <iostream>

LEE::Shader::Shader(std::string InShaderName, std::string InShaderSource)
{
	Name = InShaderName;
	Source = InShaderSource;
	GLShaderType = -1;
	IsShadeObjectCreated = false;
	IsCompiled = false;
}

LEE::Shader::~Shader()
{
	glDeleteShader(ShaderObjectId);
}

LEE::Shader::Shader(std::string InShaderName, std::string InShaderSource, int InGLShaderType) : Shader(InShaderName, InShaderSource)
{
	GLShaderType = InGLShaderType;
}

std::string LEE::Shader::GetName()
{
	return Name;
}

std::string LEE::Shader::GetSource()
{
	return Source;
}

bool LEE::Shader::GetIsShadeObjectCreated()
{
	return IsShadeObjectCreated;
}

int LEE::Shader::GetShaderType()
{
	return GLShaderType; 
}

unsigned int LEE::Shader::GetShaderObjectId() const
{
	return ShaderObjectId;
}	

void LEE::Shader::Create(int InGLShaderType)
{
	if (!IsShadeObjectCreated)
	{ 
		GLShaderType = InGLShaderType;
		ShaderObjectId = glCreateShader(InGLShaderType);
		IsShadeObjectCreated = true;
	}	
}

void LEE::Shader::Create()
{
	if(!IsShadeObjectCreated)
		Create(GLShaderType);
}

void LEE::Shader::Compile()
{
	const char * CONST_SOURCE = Source.c_str();
	glShaderSource(ShaderObjectId, 1, &CONST_SOURCE, NULL);
	glCompileShader(ShaderObjectId);

	int  success;
	char infoLog[512];
	glGetShaderiv(ShaderObjectId, GL_COMPILE_STATUS, &success);


	if (!success)
	{
		glGetShaderInfoLog(ShaderObjectId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
	}
}