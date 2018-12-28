#pragma once
#include "Resource.h"
#include <list>

class ResourceManager final {
private:
	ResourceManager();
	static ResourceManager* instance;
	std::list<Resource*> resource_list;
public:
	static ResourceManager * GetInstance();
	int Load(const char* filePath);
	void Unload(int handle);
	~ResourceManager();
};

