#include <iostream>
using namespace std;

int i;

class A {
public:
	~A() {
		i = 10;
	}
};
int foo(){
	i = 3;
	cout <<"1 "<< i << endl;
	{A ob;}
	cout <<"2 "<< i << endl;
	return i;
}
int main() {
	cout <<"3 "<< foo() << endl;
	cout <<"4 "<< i << endl;
	return 0;
}