#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isBinaryString(const std::string& str) {
	for (char c : str) {
		if (c != '0' && c != '1') {
			return false;
		}
	}
	return true;
}

std::string readBinaryString() {
	std::string input;
	do {
		std::cout << "Introduceti un sir binar (multiplu de 7 caractere): ";
		std::cin >> input;

		if (!isBinaryString(input)) {
			std::cout << "Eroare: Sirul introdus contine caractere nepermise. Introduceti doar 0 si 1.\n";
			continue;
		}

		if (input.size() % 7 != 0) {
			std::cout << "Eroare: Sirul introdus nu este multiplu de 7.\n";
			continue;
		}

		break;
	} while (true);
	return input;
}

std::vector<std::vector<int>> createParityMatrix(const std::string& input) {
	int rows = input.size() / 7;
	std::vector<std::vector<int>> matrix(rows + 1, std::vector<int>(8, 0));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < 7; ++j) {
			matrix[i][j] = input[i * 7 + j] - '0';
		}
	}

	for (int i = 0; i < rows; ++i) {
		int sum = 0;
		for (int j = 0; j < 7; ++j) {
			sum += matrix[i][j];
		}
		matrix[i][7] = sum % 2;
	}

	for (int j = 0; j < 8; ++j) {
		int sum = 0;
		for (int i = 0; i < rows; ++i) {
			sum += matrix[i][j];
		}
		matrix[rows][j] = sum % 2;
	}

	return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (int bit : row) {
			std::cout << bit << " ";
		}
		std::cout << std::endl;
	}
}

void corruptBit(std::vector<std::vector<int>>& matrix) {
	std::srand(std::time(0));
	int row = std::rand() % (matrix.size() - 1);
	int col = std::rand() % 7;
	if (matrix[row][col] == 0) {
		matrix[row][col] = 1;
	}
	else {
		matrix[row][col] = 0;
	}
	std::cout << "Bitul corupt este la pozitia: (" << row << "," << col << ")\n";
}

void detectCorruption(std::vector<std::vector<int>>& matrix) {
	int rows = matrix.size() - 1, cols = 8;
	int errorRow = -1, errorCol = -1;

	for (int i = 0; i < rows; ++i) {
		int sum = 0;
		for (int j = 0; j < 7; ++j) {
			sum += matrix[i][j];
		}
		if ((sum % 2) != matrix[i][7]) {
			errorRow = i;
		}
	}

	for (int j = 0; j < 7; ++j) {
		int sum = 0;
		for (int i = 0; i < rows; ++i) {
			sum += matrix[i][j];
		}
		if ((sum % 2) != matrix[rows][j]) {
			errorCol = j;
		}
	}

	if (errorRow != -1 && errorCol != -1) {
		std::cout << "Bitul corupt a fost detectat la pozitia: (" << errorRow << "," << errorCol << ")\n";
	}
	else {
		std::cout << "Nicio eroare detectata.\n";
	}
}

int main() {
	std::string input = readBinaryString();
	std::vector<std::vector<int>> matrix = createParityMatrix(input);

	std::cout << "Matricea initiala cu biti de paritate:\n";
	printMatrix(matrix);

	corruptBit(matrix);
	std::cout << "Matricea dupa coruperea unui bit:\n";
	printMatrix(matrix);

	detectCorruption(matrix);

	return 0;
}