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
	void pop_front(T line);
	void read_list(/*item<T>* head*/);
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

	item<T>* current = this->head_;
	item<T>* next;
	while(current != NULL){
		next = current->next;
		delete current;
		current = next;
	}

/*
	for(int i = 0; i < size; i++){
		std::cout << "Deleting line: " << i << std::endl;
		if(head_ != tail_){
			head_ = head_->next;
			delete head_->prev;
		}
		else{
			delete head_;
			std::cout << "deleting head" << std::endl;
			break;
		}
	}
*/
}


template <typename T> 
void DLList<T>::read_file(const char* filePath, T line){
	
	std::fstream stream;
	std::stringstream current; 
	//std::string line;
	stream.open(filePath);
	if (!stream) {
		throw "Error opening file, please try again later";
		return;
	}
	while (std::getline(stream, line)) {
		//std::cout << line << "   ";
		DLList<T>::push_back(line);
	}
	std::cout << "push_back over" << std::endl;
	return;
}


template <typename T> 
void DLList<T>::push_back(T line){

	item<T>* newItem = this->createItem(line);
	if(head_ == NULL) { 
		head_ = newItem;
		tail_->prev = head_;
		head_->next = NULL;
		head_->prev = NULL;
		std::cout << "Head was null:   ";
		std::cout << head_->task << std::endl;
		this->size++;
		return;
		//std::cout << "size: " << size << " line: " << newItem->task << std::endl;
		//return;
	}
	else if(head_->next == NULL) {
		head_->next = newItem;
		newItem->prev = head_;
		tail_->prev = newItem;
		newItem->next = tail_;
		tail_->next = NULL;
		std::cout << "Head->next was null:   ";
		std::cout << newItem->task << std::endl;
		this->size++;
		return;
	}
	else{
		//item<T>* temp = head_->next;
		std::cout << "Third case" << std::endl;
		newItem = tail_;
		tail_->prev = newItem;
		tail_->next = NULL;
		std::cout << newItem->task << std::endl;
/*
		while(temp->next != NULL) { 
			std::cout << "Searching, currently on: " << temp->task << std::endl;
			temp = temp->next;
		}
*/
		this->size++;

	}



/*
	else if (tail_ == NULL) {
		//std::cout << "Tail was null" << std::endl;
		tail_ = newItem;	
	}
	else {
		//std::cout << "Tail was not null   " << newItem << std::endl;
		tail_->next = newItem;
		newItem->prev = tail_;
	}

*/
	size++;	
	//std::cout << "Size: " << size << std::endl;
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
void DLList<T>::pop_front(T line){
	if(head_ == NULL){
		std::cout << "HHead is null" << std::endl;
		return;
	}
	std::cout << "Old head " << (head_->next) << std::endl;
	item<T> *old_head = this->head_->next;
	delete this->head_;
	this->head_ = old_head;
	this->size--;
}


template <typename T> 
void DLList<T>::read_list(/*item<T>* head_*/){
	//std::cout << this->tail_->task << " is the tail" <<  std::endl;
	if(head_ == NULL){
		std::cout << "Head is null" << std::endl;
		return;
	}
	else{
		item<T>* temp = head_;
		while(temp->next != NULL) {
			std::cout << temp->task << "   || and the size is: " << size  << std::endl;
			std::cout << temp->next->task << std::endl;
			temp = temp->next;
		}
		//std::cout << "1" << std::endl;
		//this->head_ = head_->next;
		//this->read_list();
	}
}
	


/*
void LinkedList::append(item* head_ref, std::string line){
	if(head_ == NULL){
		item* newItem = createItem(line);
		head_ = newItem;
	}
	else if (head_->next == NULL){
		item* newItem = createItem(line);
		head_->next = newItem;
	}
	else {
		append(head_->next, line);
	}
}
*/




