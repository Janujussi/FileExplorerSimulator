#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Directory
{
	public:
		// Constructor for Directory class
		Directory();

		// Constructory for Directory with parent directory
		Directory(Directory* parentDirectory, string dirName);

		// Destructor for Directory class
		~Directory();

		// Creates new directory under current directory
		void createNewDirectory(Directory* currDirectory, string dirName);

		// Deletes directory of specified name
		void deleteDirectory(string dirName);

		// Deletes all directories under current directory
		void deleteDescendentDirectories();

		// Prints names of child directories
		void printChildDirectoryNames();

		// Get directory name
		string getDirName();

		// Get directory size
		size_t getDirSize();

		// Get list of children directories
		vector<Directory*> getChildrenDirectories();

		// Get parent directory
		Directory* getParentDirectory();

		// Return if directory is root directory
		bool isRoot();

	private:
		Directory* parent;				// Parent directory
		vector<Directory*> children;	// Children directories
		string dirName;					// Name of directory
		size_t dirSize;					// Size of directory
};