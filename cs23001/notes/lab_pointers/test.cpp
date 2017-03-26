#include <iostream>


int main(){

	//int little = 5;
	//int big = 44;

	//int& ref = little;

	{

		char *  pointy = new char[5];
		delete [] pointy;
	}
	return 0;
}
