#include <iostream>
#include "ToDo.h"


int main() {
	DLList<std::string> superList;
	std::string line;
	//item* list;
	superList.read_file("ToDoList.txt", line);
//	superList.pop_front(line);
//	superList.read_list();
	return 0;
}
