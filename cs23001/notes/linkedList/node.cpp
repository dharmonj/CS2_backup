// node.cpp

// Look at these
// dcl
// trailing return type
// QT creator <-- windows apps IDE for c++

#include <iostream>

template <typename type>
struct node {

	node() : data(), next(nullptr) {}
	node(type data) : data(data), next(nullptr) {}
	node(type data, node * next) : data(data), next(nullptr) {}

	type data;
	node<type> * next;

};

int main(){


	node<int> * node_one = new node<int>(1);

	node * node_two = new node(2);
	node_one->next = node_two;

	node * node_three = new node(4);
	node_two->next = node_three;

	std::cerr << node_one->next->next->data << '\n';


	node * node_four = new node(8);

	node_four->next = node_one->next;
	node_one->next = node_four;


	/*node * temp_node = node_one->next->next;
	node_one->next->next = node_one->next->next->next;
	delete temp_node;

	std::cerr << node_one->next->data << '\n';
	std::cerr << node_one->next->next->data << '\n';
	*/

	int pos = 0;
	for(node * temp = node_one; node != nullptr; temp = temp->next ){
		std::cout << "pos: " << pos << "data: " << temp->data << '\n';
		++pos;
	}

	node * temp = node_one;
	while(node != nullptr){
		node * save_ptr = temp->next;
		delete temp;
		temp = save_ptr;
	}

	return 0;
}