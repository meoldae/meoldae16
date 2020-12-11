#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class AnyString {
	string anyString;

public:
	AnyString(const string& anyString) : anyString(anyString) {}
	string getAnyString() {
		return "Stored String :: " + anyString;
	}
	friend ostream& operator<<(ostream& os, AnyString& a);
};

ostream& operator<<(ostream& os, AnyString& a) {
	os << a.getAnyString();
	return os;
}


int main() {
	ofstream out("testOveroding.txt");
	AnyString a("Hello, this is operator overloading test!!!");
	string output = a.getAnyString();
	out << a << std::endl;

	return 0;
}