#include "Title.h"
#include "../object/Player.h"

Title::Title()
{
	this->object_list.push_back(new Player());
}

Title::~Title()
{
}
