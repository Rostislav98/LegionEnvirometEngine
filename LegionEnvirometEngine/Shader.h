
#pragma once

#include<string>

namespace LEE
{
	class Shader
	{
	
	public: 

		Shader(std::string InShaderName, std::string InShaderSource);
		
		std::string GetName();
		std::string GetSource();

	private:
		std::string Source;
		std::string Name;
		
	};
}



