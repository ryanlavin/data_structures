#include <fstream>
#include <sstream>
#include <iostream>

template <typename T>
struct item {
	T task;
	item<T>* next;
	item<T>* prev;
};


template <typename T> 
class DLList { 

public:
	DLList();
	~DLList();
	void push_back(T line);
	//void append(struct item* head_ref, std::string line);
	void read_file(const char* filePath, T line);
	class item<T>* createItem(T line);	
	void pop_front();
	void pop_back();
	void read_list();
	//void insert();
	//void traverse(item*);
	//void append();
	//void remove();
private:
	item<T>* head_;
	item<T>* tail_;
	int size;
};



template <typename T> 
DLList<T>::DLList(){

	this->head_ = NULL;
	this->tail_ = NULL;
	this->size = 0;
}

template <typename T> 
DLList<T>::~DLList(){

	item<T>* current;
	while(head_ != NULL){
		current = head_;
		std::cout << head_->task << std::endl;
		delete head_;
		head_ = current->next;
	}
}


template <typename T> 
void DLList<T>::read_file(const char* filePath, T line){
	
	std::fstream stream;
	std::stringstream current; 
	stream.open(filePath);
	if (!stream) {
		throw "Error opening file, please try again later";
		return;
	}
	while (std::getline(stream, line)) {
		//std::cout << line << "   ";
		DLList<T>::push_back(line);
	}

//For iteratively reading through the linked list
/*	
	item<T>* rando = head_;
	for(int i = 0; i < size; i++){
		std::cout << rando->task << std::endl;
		rando = rando->next;
	}
*/
	return;
}


template <typename T> 
void DLList<T>::push_back(T line){

	item<T>* newItem = this->createItem(line);
	if(head_ == NULL && tail_ == NULL) { 
		head_ = newItem;
		tail_ = newItem;
		head_->next = NULL;
		//std::cout << "Head was null:   ";
		this->size++;
		//std::cout << head_->task << "   And size: " << size << std::endl;
		return;
	}
	else if(head_->next == NULL) {
		head_->next = newItem;
		newItem->prev = head_;
		tail_ = newItem;
		//std::cout << "Head->next was null:   ";
		this->size++;
		//std::cout << newItem->task << "   And size: " << size << std::endl;
		return;
	}
	else{
		tail_->next = newItem;
		newItem->prev = tail_;
		tail_ = newItem;
		newItem->next = NULL;
		this->size++;
		return;
	}
}


template <typename T> 
item<T>* DLList<T>::createItem(T line){
	
	item<T>* itemm = new item<T>;
	itemm->next = NULL;
	itemm->prev = NULL;
	itemm->task  = line;
	return itemm;
}


template <typename T> 
void DLList<T>::pop_front(){
	
	if(head_ == NULL){
		std::cout << "HHead is null" << std::endl;
		return;
	}
	item<T> *new_head = head_->next;
	delete head_;
	head_ = new_head;
	this->size--;
}


template <typename T>
void DLList<T>::pop_back(){

	if(tail_ == NULL){
		std::cout << "Tail is null" << std::endl;
		return;
	}
	else if(tail_->prev == NULL){
		std::cout << "Error" << std::endl;
		return;
	}
	item<T> *new_tail = tail_->prev;
	delete tail_;
	tail_ = new_tail;
	this->size--;	
}


template <typename T> 
void DLList<T>::read_list(){

	if(head_ == NULL){
		std::cout << "Head is null" << std::endl;
		return;
	}
	else{
		item<T>* temp = head_;
		while(temp != NULL){
			std::cout << temp->task << std::endl;
			temp = temp->next;
		}
	}
}
	

