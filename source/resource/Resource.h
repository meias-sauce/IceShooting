#pragma once
#include <list>
#include <string>

enum ResourceType;

enum ResourceExtension;

class Resource final
{
private:
	ResourceType type;
	ResourceExtension extension;
	std::string filePath;
	Resource(const char* filePath);
	static std::list<Resource*> resource_list;
public:
	int handle;
	static Resource* Load(const char* filePath);
	~Resource();
};