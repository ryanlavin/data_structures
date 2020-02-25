#include <iostream>
#include "ToDo.h"


int main() {
	DLList<std::string> superList;
	std::string line;
	//item* list;
	superList.read_file("ToDoList.txt", line);


	return 0;
}
