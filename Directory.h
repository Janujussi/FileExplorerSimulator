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
		void createNewDirectory(string dirName);

		// Deletes directory of specified name
		void deleteDirectory(string dirName);

		// Deletes all directories under current directory
		void deleteDescendentDirectories();

		// Prints names of child directories
		void printChildDirectoryNames();

		// Print directory name
		string getDirName();

	private:
		Directory* parent;				// Parent directory
		vector<Directory*> children;	// Children directories
		string dirName;					// Name of directory
};