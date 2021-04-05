#include "ShaderManager.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>

#include "Shader.h"
#include <glad/glad.h>

namespace fs = std::filesystem;

void LEE::ShaderManager::LoadShadersToMemory()
{
	std::cout << "Loading shaders from file...\n";

	for (const auto& entry : fs::directory_iterator(DEFFAULT_SHADER_FOLDER_PATH))
	{
		std::cout << entry.path().filename().string() << "\n";

		std::string StrFileName = entry.path().filename().string();

		std::ifstream fin(entry.path());

		std::string ShaderSource((std::istreambuf_iterator<char>(fin)),
			std::istreambuf_iterator<char>());

		std:: string CurrentFileExtesion = fs::path(entry.path()).extension().string();

		int ShaderType = DetectShaderFileExtension(CurrentFileExtesion);

		if (ShaderType == GL_VERTEX_SHADER)
		{
			LoadedShaders.push_back(std::make_shared<Shader>(StrFileName, ShaderSource, GL_VERTEX_SHADER));
		}
			
		if (ShaderType == GL_FRAGMENT_SHADER)
		{
			LoadedShaders.push_back(std::make_shared<Shader>(StrFileName, ShaderSource, GL_FRAGMENT_SHADER));
		}

	}

	std::cout << "All shaders are loaded from file.\n";
}

void LEE::ShaderManager::CreateObjectIdForShaders()
{
	for (auto& ShaderPtr : LoadedShaders)
	{
		ShaderPtr->Create();
	}
}

void LEE::ShaderManager::CompileLoadedShader()
{
	for (auto& ShaderPtr : LoadedShaders)
	{
		ShaderPtr->Compile();

	}
}

int LEE::ShaderManager::DetectShaderFileExtension(const std::string& InFileExtension)
{
	if (InFileExtension == VERTEX_SHADER_FILE_EXTENSION)
		return GL_VERTEX_SHADER;

	if(InFileExtension == FRAGMENT_SHADER_FILE_EXTENSION)
		return GL_FRAGMENT_SHADER;

	return -1;
}

std::shared_ptr<LEE::Shader> LEE::ShaderManager::operator[](int InIndex)
{
	return LoadedShaders[InIndex];
}
