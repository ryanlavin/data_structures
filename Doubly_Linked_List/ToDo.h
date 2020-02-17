#include <fstream>

struct item {
	std::string task;
	item* next;
	item* prev;
};


//template <typename Object> 
class LinkedList { 

public:
	LinkedList();
	~LinkedList();
	void push_back(std::string line);
	void read_file(const char* filePath);
	item* createItem(std::string line);	
	//void insert();
	//void traverse(item*);
	//void append();
	//void remove();
private:
	item* head_;
	item* tail_;
	int size;
};
