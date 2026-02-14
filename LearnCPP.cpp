#include <iostream>

int readNumber() {

	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	return a + b;
}

void writeAnswer(int a) {
	std::cout << "The answer is: " << a << std::endl;

}