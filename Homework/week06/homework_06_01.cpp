#include <iostream>

class My_cat {
	char* name;
	int weight;

public:
	My_cat();
	My_cat(const char* name);
	My_cat(const My_cat& cat);
	~My_cat();

	My_cat  eat(int a);
	//리턴타입을 객체 레퍼런스로 선언

	void show_status() const;
};

My_cat::My_cat() :name(NULL), weight(10) { }

My_cat::My_cat(const char* cat_name) : weight(10) {
	name = new char[strlen(cat_name) + 1];
	strcpy_s(name,strlen(cat_name)+1, cat_name);
}

My_cat::My_cat(const My_cat& cat) : weight(10) { //Copy constructor
	std::cout << "Copy constructor invocation ! " << std::endl;
	name = new char[strlen(cat.name) + 1];
	strcpy_s(name,strlen(cat.name)+1, cat.name);
}

My_cat::~My_cat() {		//Destructor
	if (name) delete[] name;
}

//eat 함수를 구현하세요.
My_cat My_cat::eat(int a) {
	this->weight += a;
	return *this;
	// 레퍼런스와 this를 통해 연산 끝난 후의 내 자신을 반환
}

void My_cat::show_status() const {
	std::cout << " Weight : " << weight << std::endl;
}
int main() {
	My_cat cat1("Nabi");	//Cat 1 생성
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4).eat(5).eat(6);
	cat1.show_status();

	getchar();
	return 0;
}
