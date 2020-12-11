#include <iostream>

class Strategy {
public:
	virtual int doOperation(int a, int b) = 0;
};

class Context {
private:
	Strategy* strategy;
public:
	Context(Strategy* strategy) {
		this->strategy = strategy;
	}
	int executeStrategy(int a, int b) {
		return strategy->doOperation(a, b);
	}
};


class addOperation : public Strategy {
public:
	int doOperation(int a, int b) {
		return a + b;
	}
};

class subOperation : public Strategy {
public:
	int doOperation(int a, int b) {
		return a - b;
	}
};

class mulOperation : public Strategy {
public:
	int doOperation(int a, int b) {
		return a * b;
	}
};

int main() {
	
	Context Add = Context(new addOperation());
	std::cout << "10 + 5 = " << Add.executeStrategy(10, 5) << std::endl;

	Strategy* sub = new subOperation();
	Context* Sub = new Context(sub);
	std::cout << "10 - 5 = " << Sub->executeStrategy(10, 5) << std::endl;

	Strategy* mul = new mulOperation();
	Context* Mul = new Context(mul);
	std::cout << "10 * 5 = " << mul->doOperation(10, 5) << std::endl;

}