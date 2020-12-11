#include <iostream>

class SetValue {
public:
	int x, y;

};

class capsulation : private SetValue {
private:
	SetValue obj;

public:
	void setA(int a) {
		obj.x = a;
	}
	void setB(int b) {
		obj.y = b;
	}
	int getA() {
		return obj.x;
	}
	int getB() {
		return obj.y;
	}
};

int main() {
	capsulation cap;
	cap.setA(33);
	cap.setB(44);

	std::cout << "X = " << cap.getA() << " ,Y = " << cap.getB() << std::endl;
	return 0;
}