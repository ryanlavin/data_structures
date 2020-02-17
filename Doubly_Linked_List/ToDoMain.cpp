#include <iostream>
#include "ToDo.h"


int main() {
	LinkedList superList;
	superList.read_file("ToDoList.txt");
	superList.~LinkedList();


	return 0;
}
