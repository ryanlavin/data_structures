#include "ToDo.h"
#include <sstream>
#include <iostream>
#include <fstream>



LinkedList::LinkedList(){
	//&(next) = new Item* head_;
	//&(prev) = new Item* tail_;
	head_ = NULL;
	tail_ = NULL;
	size = 0;
}

LinkedList::~LinkedList(){
	for(int i = 0; i < size; i++){
		if(head_ != tail_){
			head_ = head_->next;
			delete head_->prev;
		}
		else{
			delete head_;
			break;
		}
	}
}


void LinkedList::read_file(const char* filePath){
	
	std::fstream stream;
	std::stringstream current; 
	std::string line;
	stream.open(filePath);
	if (!stream) {
		throw "Error opening file, please try again later";
		return;
	}
	
	while (std::getline(stream, line)) {
		LinkedList::createItem(line);
		//(*next).push_back(line);
	}
}

void LinkedList::push_back(std::string line){
	item* newItem = createItem(line);
	if(tail_ == NULL){
		tail_ = newItem;	
	}
	else{
		tail_->next = newItem;
		newItem->prev = tail_;
		tail_ = newItem;
	}
	size++;	
}

item* LinkedList::createItem(std::string line){
	item* item = new struct item;
	std::cout << line << std::endl;
	item->next = NULL;
	item->prev = NULL;
	item->task = line;
	return item;
}

//void List::insert(){
	
//}

//void List::append(){

//}

//void List::remove(){

//}