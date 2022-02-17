## FileExplorerSimulator
### This is a work in progress.

### Description:
#### &ensp; This is a simulation of a file explorer. I have taken some inspiration from Linux command line.
#### &ensp; A tree is used to store the directories.

### Commands:
#### &ensp; Call a command and command input on the same line. Separate them with spaces.
#### &ensp;&ensp; Ex: Call command as "/ >> mkdir example_directory"
* mkdir - creates new directory
  * called by: mkdir \<directory name>
* deldir - deletes a directory
  * called by: deldir \<directory name>
* cd - changes to directory
  * Use ".." to move up a directory
  * called by: cd \<directory name>
* ls - lists children directories
