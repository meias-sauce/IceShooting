#include "ResourceManager.h"


ResourceManager* ResourceManager::instance = nullptr;

ResourceManager * ResourceManager::GetInstance()
{
	if (ResourceManager::instance == nullptr) {
		ResourceManager::instance = new ResourceManager();
	}
	return ResourceManager::instance;
}

//ファイルパスから読み込んでリソースを返す
int ResourceManager::Load(const char * filePath) {
	this->resource_list.push_back(new Resource(filePath));
	return this->resource_list.back()->handle;
}

ResourceManager::ResourceManager() {
}


ResourceManager::~ResourceManager() {
	//全解放（こいつはずっと生きてるはずだが一応）
	for (auto resource : this->resource_list) {
		delete resource;
	}
	this->resource_list.clear();
}

