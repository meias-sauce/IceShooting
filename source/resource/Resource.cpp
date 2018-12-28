#include "Resource.h"
#include "DxLib.h"


std::list<Resource*> Resource::resource_list = std::list<Resource*>();
Camera* Resource::camera = Camera::GetInstance();


Resource::Resource(const char * filePath) {
	this->filePath = filePath;
	//拡張子抽出
	auto dotPos = this->filePath.find_last_of('.');
	if (dotPos == std::string::npos) {
		//ここに来たら拡張子が読み取れてないのでブレークさせる
		__asm int 3;
		return;
	}
	auto strExtension = this->filePath.substr(dotPos + 1, this->filePath.size() - (dotPos + 1));
	//VC++では文字列switchができないらしいのでif文で頑張る
	if (strExtension == "mp3") {
		this->extension = MP3;
		this->type = SOUND;
	}
	else if (strExtension == "wav") {
		this->extension = WAV;
		this->type = SOUND;
	}
	else if (strExtension == "ogg") {
		this->extension = OGG;
		this->type = SOUND;
	}
	else if (strExtension == "png") {
		this->extension = PNG;
		this->type = GRAPHIC;
	}
	else if (strExtension == "jpg") {
		this->extension = JPG;
		this->type = GRAPHIC;
	}

	//ロード、ハンドル取得
	switch (this->type) {
	case SOUND:
		this->handle = LoadSoundMem(filePath);
		break;
	case GRAPHIC:
		this->handle = LoadGraph(filePath);
		break;
	default:
		__asm int 3;
		break;
	}

	//リストに追加
	Resource::resource_list.push_back(this);
}

Resource * Resource::Load(const char * filePath)
{
	//重複ロードを防ぐ
	for (auto resource : Resource::resource_list) {
		if (resource->filePath == filePath) {
			return resource;
		}
	}
	return new Resource(filePath);
}

//Cameraに頼む
void Resource::Draw(float x, float y)
{
	Resource::camera->Draw(x, y, this->handle);
}

Resource::~Resource()
{
	//リストから追い出し
	for (auto resource : Resource::resource_list) {
		if (resource->filePath == this->filePath) {
			Resource::resource_list.remove(resource);
			break; //breakしないとresourceの指す値が不定なので注意
		}
	}
	//リソース解放
	switch (this->type) {
	case SOUND:
		DeleteSoundMem(this->handle);
		break;
	case GRAPHIC:
		DeleteGraph(this->handle);
		break;
	default:
		__asm int 3;
		break;
	}
}
