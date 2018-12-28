#include "Resource.h"
#include "DxLib.h"


std::list<Resource*> Resource::resource_list = std::list<Resource*>();
Camera* Resource::camera = Camera::GetInstance();


Resource::Resource(const char * filePath) {
	this->filePath = filePath;
	//�g���q���o
	auto dotPos = this->filePath.find_last_of('.');
	if (dotPos == std::string::npos) {
		//�����ɗ�����g���q���ǂݎ��ĂȂ��̂Ńu���[�N������
		__asm int 3;
		return;
	}
	auto strExtension = this->filePath.substr(dotPos + 1, this->filePath.size() - (dotPos + 1));
	//VC++�ł͕�����switch���ł��Ȃ��炵���̂�if���Ŋ撣��
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

	//���[�h�A�n���h���擾
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

	//���X�g�ɒǉ�
	Resource::resource_list.push_back(this);
}

Resource * Resource::Load(const char * filePath)
{
	//�d�����[�h��h��
	for (auto resource : Resource::resource_list) {
		if (resource->filePath == filePath) {
			return resource;
		}
	}
	return new Resource(filePath);
}

//Camera�ɗ���
void Resource::Draw(float x, float y)
{
	Resource::camera->Draw(x, y, this->handle);
}

Resource::~Resource()
{
	//���X�g����ǂ��o��
	for (auto resource : Resource::resource_list) {
		if (resource->filePath == this->filePath) {
			Resource::resource_list.remove(resource);
			break; //break���Ȃ���resource�̎w���l���s��Ȃ̂Œ���
		}
	}
	//���\�[�X���
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
