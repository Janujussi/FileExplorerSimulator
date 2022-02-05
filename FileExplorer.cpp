#include "FileExplorer.h"

FileExplorer::FileExplorer()
{
	this->root = new Directory();
}

FileExplorer::~FileExplorer()
{
	this->root->deleteDescendentDirectories();
	delete this->root;
}

Directory* FileExplorer::getRoot()
{
	return this->root;
}