#include "Directory.h"

Directory::Directory()
{
	this->parent = NULL;
	this->children.clear();
	this->dirName = "/";
}

Directory::Directory(Directory* parentDirectory, string dirName)
{
	this->parent = parentDirectory;
	this->children.clear();
	this->dirName = dirName;

}

Directory::~Directory()
{
	this->parent = NULL;
	this->children.clear();
	this->dirName = "";
}

void Directory::createNewDirectory(string dirName)
{
	Directory* newDir = new Directory(this->parent, dirName);	/* Create new direcrory with
																   user given name and link
																   current directory as parent
																*/

	this->children.push_back(newDir);		// Push new directory to array of children directories

	if (this->children.back() != newDir) {	// Debug
		cout << "\nFailed to create new directory.";
		return;
	}
}

void Directory::deleteDirectory(string dirName)
{
	// If directory exists, delete
	for (int i = 0; i < this->children.size(); i++) {
		if (this->children[i]->dirName == dirName) {
			delete children[i];
			children.erase(children.begin() + i);
			return;
		}
	}

	cout << "\nNo such directory;";
	return;
}

void Directory::deleteDescendentDirectories()
{
	//DFS
}

void Directory::printChildDirectoryNames()
{
	size_t numChildren = sizeof(this->children) / sizeof(this->children[0]);

	for (int i = 0; i < numChildren; i++) {
		cout << this->children[i]->getDirName() << endl;
	}
}

string Directory::getDirName()
{
	return this->dirName;
}