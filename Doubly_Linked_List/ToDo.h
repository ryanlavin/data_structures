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
	void read_list(item<T>* head);
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
	std::cout << "push_back over  & the size is: " << size << std::endl;
	item<T>* rando = head_;

/* For iteratively reading through the linked list
	for(int i = 0; i < size; i++){
		std::cout << rando->task << std::endl;
		rando = rando->next;
	}
*/
	//DLList<T>::read_list(this->head_);
	return;
}


template <typename T> 
void DLList<T>::push_back(T line){

	item<T>* newItem = this->createItem(line);
	if(head_ == NULL && tail_ == NULL) { 
		head_ = newItem;
		tail_ = newItem;
		newItem->next = NULL;
		newItem->prev = NULL;
		
		std::cout << "Head was null:   ";
		this->size++;
		std::cout << head_->task << "   And size: " << size << std::endl;
		return;
	}
	else if(head_->next == NULL) {
		head_->next = newItem;
		newItem->prev = head_;
		tail_ = newItem;
		tail_->prev = head_;
		std::cout << "Head->next was null:   ";
		this->size++;
		std::cout << newItem->task << "   And size: " << size << std::endl;
		return;
	}
	else{
		tail_->next = newItem;
		tail_ = newItem;
		tail_->prev = newItem->prev;
		this->size++;
		std::cout << newItem->task  << "   And size: " << size << std::endl;
		return;
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
void DLList<T>::read_list(item<T>* head_){
	std::cout << "Now beginning to read the list" << std::endl;
	if(head_ == NULL){
		std::cout << "Head is null" << std::endl;
		return;
	}
	else{
		item<T>* temporary = head_;
		while(temporary != NULL){
			std::cout << temporary->task << std::endl;
			temporary = temporary->next;
		}
	}
/*
	else{
		item<T>* temp = tail_;
		temp->prev = tail_->prev;
		while(temp->prev != NULL) {
			std::cout << temp->task << "   || and the size is: " << size  << std::endl;
			std::cout << temp->prev->task << std::endl;
			temp = temp->prev;
			std::cout << temp->prev->task << std::endl;
		}
	}
*/
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




