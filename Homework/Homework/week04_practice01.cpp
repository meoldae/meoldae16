#include <iostream>

void increment(int &x) {
	++x;
}

int main(void) {
	int x = 55;
	int& y = x;
	std::cout << "Before" << x << std::endl;
	increment(x);
	std::cout << "After" << x << std::endl;

	system("pause");
	return 0;
}