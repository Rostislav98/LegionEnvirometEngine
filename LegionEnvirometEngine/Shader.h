
#pragma once

#include<string>


namespace LEE
{
	class Shader
	{
	
	public: 

		Shader(std::string InShaderName, std::string InShaderSource);

		Shader(std::string InShaderName, std::string InShaderSource, int InGLShaderType);

		virtual ~Shader();
		
		std::string GetName();
		std::string GetSource();
		bool GetIsShadeObjectCreated();
		int GetShaderType();
		unsigned int GetShaderObjectId() const;

		void Create(int InGLShaderType);
		void Create();

		void Compile();

	private:
		std::string Source;
		std::string Name;
		unsigned int ShaderObjectId;
		int GLShaderType;
		bool IsShadeObjectCreated;
		bool IsCompiled;
	};
}



