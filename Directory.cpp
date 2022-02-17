#include "Directory.h"
#include <stack>

Directory::Directory()
{
	this->parent = NULL;
	this->children.clear();
	this->dirName = "/";
	this->dirSize = 0;
}

Directory::Directory(Directory* parentDirectory, string dirName)
{
	this->parent = parentDirectory;
	this->children.clear();
	this->dirName = dirName;
	this->dirSize = 0;
}

Directory::~Directory()
{
	this->parent = NULL;
	this->children.clear();
	this->dirName = "";
}

void Directory::createNewDirectory(Directory* currDirectory, string dirName)
{
	Directory* newDir = new Directory(currDirectory, dirName);	/* Create new direcrory with
																   user given name and link
																   current directory as parent
																*/

	this->children.push_back(newDir);		// Push new directory to array of children directories

	if (this->children.back() != newDir) {	// Debug
		cout << "\nFailed to create new directory.";
		return;
	}

	this->dirSize++;
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

	// If directory doesn't exist
	cout << "\nNo such directory;";
	return;
}

void Directory::deleteDescendentDirectories()
{
	vector<Directory*> childrenDirectories = this->children;	// Array of children directories to delete
	stack<Directory*> toDelete;									// Tracking all descendents to delete

	// DFS
	// Push children directories onto stack
	for (int i = 0; i < childrenDirectories.size(); i++) {
		toDelete.push(childrenDirectories[i]);
	}

	// While stack is not empty
	while (!toDelete.empty()) {
		// If has children directories
		if (toDelete.top()->dirSize != 0) {
			toDelete.top()->deleteDescendentDirectories();		// Recursive call to function
		}
		delete toDelete.top();		// Delete top directory
		toDelete.pop();				// Pop top directory
	}
}

void Directory::printChildDirectoryNames()
{
	size_t numChildren = this->getDirSize();

	if (numChildren == 0) {
		cout << "No directories." << endl;
		return;
	}

	for (int i = 0; i < numChildren; i++) {
		cout << this->children[i]->getDirName() << endl;
	}
}

string Directory::getDirName()
{
	return this->dirName;
}

size_t Directory::getDirSize()
{
	return this->dirSize;
}

vector<Directory*> Directory::getChildrenDirectories()
{
	return this->children;
}

Directory* Directory::getParentDirectory()
{
	return this->parent;
}

bool Directory::isRoot()
{
	return this->parent == NULL;
}