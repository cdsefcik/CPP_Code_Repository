#include <iostream>
#include <string>

inline void keep_window_open() {
	char ch; std::cin >> ch;
}

int main(int argc, char* argv[]) {

	if (argc > 1) {
		std::string param1 = argv[1];
		std::cout << "Parameter: " << param1 << std::endl;
	}
	else {
		std::cout << "No parameter provided" << std::endl;
	}
	return 0;
}