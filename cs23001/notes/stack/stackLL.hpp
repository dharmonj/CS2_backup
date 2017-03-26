template <typename T> 
class stack {
public:
	stack() : tos(nullptr){};
	~stack();
	stack(const stack<T>&);
	stack<T>& operator=(stack<T>);
	void swap(stack<T>&);
	bool isFull() const;
	bool isEmpty() const {return tos == nullptr };
	void push(const T&);
	T pop();
	T top() const;

private:
	node<T> * tos;

};

template <typename T>
void stack<T>::push(const T& item){
	assert(!isFull());
	node<T> * temp = new node<T>(item);
	temp->next = tos;
	tos = temp;
}

template <typename T>
T stack<T>::pop(){
	assert(!isEmpty());
	T result = tos->data;
	node<T> * temp = tos;
	tos = tos->next;
	delete temp;
	return result;
}

template <typename T>
stack<T>::~stack(){
	node<T> *temp;
	while(tos != nullptr){
		temp = tos;
		tos = tos->next;
		delete temp;
	}
}

template <typename T>
stack<T>::stack(const stack<T> & actual){
	tos = nullptr;
	node<T> * temp = actual.tos, *bottom = nullptr;
	while(temp != nullptr){
		if(tos == nullptr){
			tos = new node<T>(temp->data);
			bottom = tos;
		}else{
			bottom->next = new node<T>(temp->data);
			bottom = bottom->next;
		}
		temp = temp->next;
	}
}