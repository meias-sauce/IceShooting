#pragma once
#include <list>
#include <string>
#include "../camera/Camera.h"

enum ResourceType {
	SOUND,
	GRAPHIC
};

enum ResourceExtension {
	MP3,
	WAV,
	OGG,
	PNG,
	JPG
};

class Resource final
{
private:
	int handle;
	ResourceType type;
	ResourceExtension extension;
	std::string filePath;

	Resource(const char* filePath);

	static std::list<Resource*> resource_list;
	static Camera* camera;


public:
	static Resource* Load(const char* filePath);
	void Draw(float x, float y, float angle);
	~Resource();
};