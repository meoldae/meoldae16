#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	vec.push_back(11);
	vec.push_back(22);
	vec.push_back(33);
	vec.push_back(44);

	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		if (*itr == 22) {
			vec.erase(itr);
			itr = vec.begin();
		}
	}

	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << "Vector element: " << *itr << std::endl;
	}

	getchar();
}