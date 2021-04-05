#include "ShaderProgram.h"

#include "Shader.h"

#include<glad/glad.h>

// LEE::ShaderProgram::ShaderProgram()
// {
// 
// }

LEE::ShaderProgram::ShaderProgram()
{
	ShaderProgramObjecId = -1;
}

LEE::ShaderProgram::~ShaderProgram()
{
}

// void LEE::ShaderProgram::AddShader(const LEE::Shader& InShader)
// {
// 	int Id = InShader.GetShaderObjectId();
// 
// 	ShadersObjectIdArray.push_back(InShader.GetShaderObjectId());
// }

void LEE::ShaderProgram::AddShader(const LEE::Shader& InShader)
{
	ShadersObjectIdArray.push_back(InShader.GetShaderObjectId());	
}

void LEE::ShaderProgram::Create()
{
	ShaderProgramObjecId = glCreateProgram();
}

void LEE::ShaderProgram::Link()
{
	for (const auto& ShderId : ShadersObjectIdArray)
	{
		glAttachShader(ShaderProgramObjecId, ShderId);
	}

	glLinkProgram(ShaderProgramObjecId);

	int success;
	char infoLog[512];

	glGetProgramiv(ShaderProgramObjecId, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ShaderProgramObjecId, 512, NULL, infoLog);

	}
}

void LEE::ShaderProgram::Use()
{
	glUseProgram(ShaderProgramObjecId);
}

unsigned int LEE::ShaderProgram::GetShaderProgramObjectId()
{
	return ShaderProgramObjecId;
}
