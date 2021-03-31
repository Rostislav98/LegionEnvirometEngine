#include "ShaderManager.h"

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Shader.h"

namespace fs = std::filesystem;

void LEE::ShaderManager::LoadShadersToMemory()
{
	std::cout << "Loading shaders from file...\n";

	for (const auto& entry : fs::directory_iterator(DEFFAULT_SHADER_FOLDER_PATH))
	{
		std::cout << entry.path().filename().string() << "\n";

		std::string StrFileName = entry.path().filename().string();

		//if (entry.is_character_file())


		std::ifstream fin(entry.path());

		std::string ShaderSource((std::istreambuf_iterator<char>(fin)),
			std::istreambuf_iterator<char>());

		LoadedShaders.push_back(Shader(StrFileName, ShaderSource));



	}

	std::cout << "All shaders are loaded from file.\n";
}
