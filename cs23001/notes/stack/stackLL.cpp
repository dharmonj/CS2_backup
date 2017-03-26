template <typename T>
void stack<T>::push(const T& item){
	node<T> * temp = new node<T>(item);
	temp->next = tos;
	tos = temp;
}