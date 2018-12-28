#include "ResourceManager.h"


ResourceManager* ResourceManager::instance = nullptr;

ResourceManager * ResourceManager::GetInstance()
{
	if (ResourceManager::instance == nullptr) {
		ResourceManager::instance = new ResourceManager();
	}
	return ResourceManager::instance;
}

//�t�@�C���p�X����ǂݍ���Ń��\�[�X��Ԃ�
int ResourceManager::Load(const char * filePath) {
	this->resource_list.push_back(new Resource(filePath));
	return this->resource_list.back()->handle;
}

ResourceManager::ResourceManager() {
}


ResourceManager::~ResourceManager() {
	//�S����i�����͂����Ɛ����Ă�͂������ꉞ�j
	for (auto resource : this->resource_list) {
		delete resource;
	}
	this->resource_list.clear();
}

