#include <iostream>

class Base {
public:
	int x;

	Base() : x(5) { std::cout << "Base Constructor " << std::endl; }
	~Base() { std::cout << "Base destructor" << std::endl; }
	
	void showInfo() {
		std::cout << x << std::endl;
	}
};

class Derived : public Base {
public:
	int y;

	Derived() : y(10), Base() { std::cout << "Derived Constructor " << std::endl; }
	~Derived() { std::cout << "Derived destructor " << std::endl;  }

	void showInfo() {
		std::cout << Base::x << ", " << y << std::endl;
	}
};
	
int main() {
	Base b;
	Derived d;

	b.showInfo();
	d.showInfo();

	Base* bp = &d;
	bp->showInfo();

	Derived* dp = static_cast<Derived*>(&b);
	dp->showInfo();
	
	std::cout << dp->y << std::endl;

}