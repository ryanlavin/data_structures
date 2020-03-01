#include <iostream>
#include "ToDo.h"


int main() {
	DLList<std::string> superList;
	std::string line;
	superList.read_file("ToDoList.txt", line);
	superList.read_list();
	superList.pop_back();
	superList.read_list();
	superList.~DLList();
	return 0;
}
