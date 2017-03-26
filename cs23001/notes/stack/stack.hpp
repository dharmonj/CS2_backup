#ifndef THESTACK
#define THESTACK

const int MAX_VALUES = 256;

template<typename type>
class stack {

	private:

		int tos;
		type values[MAX_VALUES];

	public:

		stack(): tos(-1) {}

		void push(const type & object){
			assert(!full());
			++tos;
			values[tos] = object;
		}

		void pop(){
			assert(!empty());
			--tos;
		}

		type & top(){
			assert(!empty());
			return values[tos];
		}

		type top() const{
			assert(!empty());
			return values[tos];
		}

		bool empty() const{
			return tos == -1;
		}


		bool full() const{
			return tos == MAX_VALUES-1;
		}


	

};














#endif