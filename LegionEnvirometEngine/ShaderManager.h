#pragma once

#include <vector>
#include <string>
#include <memory>

#include"Shader.h"
#include"ShaderProgram.h"

class ShaderProgram;


namespace LEE
{
	const std::string DEFFAULT_SHADER_FOLDER_PATH = "C:\\Users\\r.reshetnyak\\source\\repos\\LegionEnvirometEngine\\x64\\Debug\\Shaders\\";
	const std::string VERTEX_SHADER_FILE_EXTENSION = ".vs";
	const std::string FRAGMENT_SHADER_FILE_EXTENSION = ".fs";
 	

	class ShaderManager
	{
		
		public:
			void LoadShadersToMemory();

			void CreateObjectIdForShaders();

			void CompileLoadedShader();

			int DetectShaderFileExtension(const std::string& InFileExtension);

			std::shared_ptr<Shader> operator [] (int InIndex);

		private:
			std::vector<std::shared_ptr<ShaderProgram>> ShaderPrograms;
			std::vector<std::shared_ptr<Shader>> LoadedShaders;
	};
}



