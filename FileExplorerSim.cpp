#include "FileExplorer.h"
#include <iostream>
#include <string>

using namespace std;

// Print current directory
string printDirectory(Directory* currDirectory);

int main() {
	FileExplorer thisSimulation;		// File explorer object
	Directory* currDirectory = thisSimulation.getRoot();	// Current directory user is in
	string commands[] = {		// All commands to use
		"mkdir",
		"deldir",
		"ls",
		"cd"
	};
	size_t numOfCommands = sizeof(commands) / sizeof(commands[0]); 	// Size of command list
	string userCommand;		// Command user enters
	int command;			// Index of user command
	bool validCommand;		// Check command is valid flag

	while(true) {
		userCommand = "";
		validCommand = false;

		cout << endl << printDirectory(currDirectory) << " >> ";	// Print current directory in command line
		cin >> userCommand;
		cout << endl;

		// Check command list for command and assign index to command
		for (int i = 0; i < numOfCommands; i++) {
			if (userCommand == commands[i]) {
				command = i;
				validCommand = true;
			}
		}
		if (validCommand == false) {
			command = -1;
		}

		// Command logic
		switch(command) {
			case 0: {	// mkdir
				string dirName = "";		// Name of new directory

				cout << "Directory name: ";
				cin >> dirName;
				if (						// Check if name is valid
					dirName[0] < 48
					&& dirName[0] > 57
					&& dirName[0] < 65
					&& dirName[0] > 90
					&& dirName[0] < 97
					&& dirName[0] > 122
				) {
					cout << "\nInvalid name" << endl;
					break;
				}

				currDirectory->createNewDirectory(currDirectory, dirName);

				break;
			}

			case 1: {	// deldir
				string dirToDelete = "";

				cout << "Directory name: ";
				cin >> dirToDelete;

				for (int i = 0; i < currDirectory->getDirSize(); i++) {
					if (currDirectory->getChildrenDirectories()[i]->getDirName() == dirToDelete) {
						currDirectory->getChildrenDirectories()[i]->deleteDescendentDirectories();
					}
				}

				currDirectory->deleteDirectory(dirToDelete);

				break;
			}

			case 2: {	// ls
				currDirectory->printChildDirectoryNames();

				break;
			}

			case 3: {	// cd
				string dirName = "";				// Name of directory to change to
				string iterateChildName = "";		// Name of child directory to compare to dirName
				bool changed = false;				// flag for changing directory

				cout << "Directory name: ";
				cin >> dirName;

				if (dirName == "..") {
					if (currDirectory->getParentDirectory() == NULL) {
						cout << "Already at root" << endl;
						break;
					}

					currDirectory = currDirectory->getParentDirectory();
					break;
				}

				// Iterate through child directories
				for (int i = 0; i < currDirectory->getDirSize(); i++) {
					iterateChildName = currDirectory->getChildrenDirectories()[i]->getDirName();

					// If child directory contains same name, change to that directory
					if (dirName == iterateChildName) {
						currDirectory = currDirectory->getChildrenDirectories()[i];
						changed = true;
						break;
					}
				}
				if (changed == false) {
					cout << "No such directory." << endl;
				}

				break;
			}

			default: {
				cout << "Invalid command." << endl;

				break;
			}
		}
	}

	return 0;
}

string printDirectory(Directory* currDirectory) {
	Directory* currDirectoryIterate = currDirectory;
	string directory = "/";

	while (!currDirectoryIterate->isRoot()) {
		directory = "/" + currDirectoryIterate->getDirName() + directory;
		currDirectoryIterate = currDirectoryIterate->getParentDirectory();
	}

	return directory;
}