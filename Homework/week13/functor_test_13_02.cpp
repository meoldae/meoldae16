#include <iostream>

struct Functor {
	void operator() () {
		std::cout << "functor executed" << std::endl;
	}
};

int main() {
	Functor functor;
	functor();

	getchar();
}