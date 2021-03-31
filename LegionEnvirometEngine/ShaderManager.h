#pragma once

#include <vector>
#include<string>

#include"Shader.h"

class ShaderProgram;


namespace LEE
{
	const std::string DEFFAULT_SHADER_FOLDER_PATH = "C:\\Users\\r.reshetnyak\\source\\repos\\LegionEnvirometEngine\\x64\\Debug\\Shaders\\";
	
	class ShaderManager
	{
		
		public:
			void LoadShadersToMemory();

		//std::vector<ShaderProgram> ShaderPrograms;

		std::vector<Shader> LoadedShaders;

	};
}



