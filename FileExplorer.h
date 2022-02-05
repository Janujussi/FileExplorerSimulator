#include "Directory.h"

class FileExplorer
{
	public:
		// Constructor for FileExplorer class
		FileExplorer();

		// Destructor for FileExplorer class
		~FileExplorer();

		Directory* getRoot();

	private:
		Directory* root;
};