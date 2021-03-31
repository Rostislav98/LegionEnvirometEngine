#include "Shader.h"

LEE::Shader::Shader(std::string InShaderName, std::string InShaderSource)
{
	Name = InShaderName;
	Source = InShaderSource;
}

std::string LEE::Shader::GetName()
{
	return Name;
}

std::string LEE::Shader::GetSource()
{
	return Source;
}
