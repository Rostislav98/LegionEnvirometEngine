#pragma once

#include <string>
#include <vector>



namespace LEE
{ 
	class Shader;

	class ShaderProgram
	{
	
	public:
		ShaderProgram();
		virtual ~ShaderProgram();

		void AddShader(const LEE::Shader& InShader);
		void Create();
		void Link();
		void Use();

		unsigned int GetShaderProgramObjectId();

	private:
		std::string Name;
		unsigned int ShaderProgramObjecId;
		std::vector<int> ShadersObjectIdArray;
		
	};
}

