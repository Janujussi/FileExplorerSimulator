#include "FileExplorer.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	FileExplorer thisSimulation;
	string commands[] = {
		"mkdir",
		"deldir",
		"ls",
		"cd"
	};
	size_t numOfCommands = sizeof(commands) / sizeof(commands[0]);

	while(true) {
		string userCommand = "";
		int command;

		cin >> userCommand;

		for (int i = 0; i < numOfCommands; i++) {
			if (userCommand == commands[i]) {
				command = i;
			}
		}

		switch(command) {
			case 0: {	// mkdir
				string dirName = NULL;		// Name of new directory

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

				thisSimulation.getRoot()->createNewDirectory(dirName);

				break;
			}

			case 1: {	// deldir

				break;
			}

			case 2: {	// ls
				thisSimulation.getRoot()->printChildDirectoryNames();
			}
		}
	}

	return 0;
}