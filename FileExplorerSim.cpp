#include "FileExplorer.h"
#include <iostream>
#include <string>

using namespace std;

string printDirectory(Directory* currDirectory);						// Print current directory
void split(string stringToSplit, vector<string>& splitStringOutput);	// Split string

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
	vector<string> userCommand;		// Command user enters
	string commandInput;	// Input of command line
	string dirName;			// Name of directory in command
	string sCommand;		// User command
	int command;			// Index of user command
	bool validCommand;		// Check command is valid flag

	while(true) {
		commandInput = "";
		userCommand.clear();
		validCommand = false;

		cout << endl << printDirectory(currDirectory) << " >> ";	// Print current directory in command line
		getline(cin, commandInput); 					// Getting user input
		split(commandInput, userCommand);
		cout << endl;

		sCommand = userCommand[0];
		dirName = userCommand[1];

		// Check command list for command and assign index to command
		for (int i = 0; i < numOfCommands; i++) {
			if (sCommand == commands[i]) {
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
				for (int i = 0; i < currDirectory->getDirSize(); i++) {
					if (currDirectory->getChildrenDirectories()[i]->getDirName() == dirName) {
						currDirectory->getChildrenDirectories()[i]->deleteDescendentDirectories();
					}
				}

				currDirectory->deleteDirectory(dirName);

				break;
			}

			case 2: {	// ls
				currDirectory->printChildDirectoryNames();

				break;
			}

			case 3: {	// cd
				string iterateChildName = "";		// Name of child directory to compare to dirName
				bool changed = false;				// flag for changing directory

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

void split(string stringToSplit, vector<string>& splitStringOutput) {
	int iterateNum = stringToSplit.length();
	string stringToInsert = "";

	for (int i = 0; i < iterateNum; i++) {
		if (stringToSplit[i] != ' ') {
			stringToInsert += stringToSplit[i];
		} else {
			splitStringOutput.push_back(stringToInsert);
			stringToInsert = "";
		}
	}
	splitStringOutput.push_back(stringToInsert);
}