#include <iostream>
#include <vector>
#include <string>

bool isBinary(const std::string& str) {
	for (char c : str) {
		if (c != '0' && c != '1') {
			return false;
		}
	}
	return true;
}

std::string xorDivide(std::string dividend, const std::string& divisor) {
	int len = divisor.length();
	std::string rest = dividend.substr(0, len);

	for (size_t i = len; i <= dividend.length(); ++i) {
		std::cout << "Rest curent: " << rest << "\n";
		if (rest[0] == '1') {
			for (size_t j = 0; j < len; ++j) {
				if (rest[j] == divisor[j]) {
					rest[j] = '0';
				}
				else {
					rest[j] = '1';
				}
			}
		}
		rest.erase(0, 1);
		if (i < dividend.length()) {
			rest += dividend[i];
		}
	}
	std::cout << "Rest final: " << rest << "\n";
	return rest;
}

int main() {
	std::string message, generator;

	do {
		std::cout << "Introduceti un sir binar: ";
		std::cin >> message;
	} while (!isBinary(message));

	do {
		std::cout << "Introduceti un polinom generator binar: ";
		std::cin >> generator;
	} while (!isBinary(generator) || message.length() <= generator.length());

	int polyDegree = generator.length() - 1;
	std::string extendedMessage = message + std::string(polyDegree, '0');
	std::cout << "Mesaj extins: " << extendedMessage << "\n";

	std::string rest = xorDivide(extendedMessage, generator);
	std::string transmittedMessage = message + rest;
	std::cout << "Mesaj transmis: " << transmittedMessage << "\n";

	return 0;
}