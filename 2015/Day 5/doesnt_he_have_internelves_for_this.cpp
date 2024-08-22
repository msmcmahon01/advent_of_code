#include <fstream>
#include <iostream>
#include <string>
using namespace std;

static bool test1(string line);
static bool test2(string line);
static bool test3(string line);
static bool test4(string line);
static bool test5(string line);

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	bool part2 = true; // Control part 1 and part 2
	string line;
	int total = 0;

	if (!part2) {
		while (getline(inputFile, line)) {
			if (test1(line) && test2(line) && test3(line)) {
				++total;
			}
		}
	} else {
		while (getline(inputFile, line)) {
			if (test4(line) && test5(line)) {
				++total;
			}
		}
	}

	cout << "The total number of 'nice' strings is: " << total << endl;

	return 0;
}

static bool test1(string line) {
	cout << "test 1" << endl;
	int vowels = 0;
	for (int i = 0; i < line.length(); ++i) {
		if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
			line[i] == 'o' || line[i] == 'u') {
			++vowels;
		}
	}

	if (vowels >= 3) {
		cout << "TEST 1 PASS: " << line << endl;
		return true;
	}

	return false;
}

static bool test2(string line) {
	cout << "test 2" << endl;
	for (int i = 0; i < line.length(); ++i) {
		if (line[i] == line[i + 1]) {
			cout << "TEST 2 PASS: " << line << endl;
			return true;
		}
	}

	return false;
}

static bool test3(string line) {
	cout << "test 3" << endl;
	for (int i = 0; i < line.length(); ++i) {
		if ((line[i] == 'a' && line[i + 1] == 'b') ||
			(line[i] == 'c' && line[i + 1] == 'd') ||
			(line[i] == 'p' && line[i + 1] == 'q') ||
			(line[i] == 'x' && line[i + 1] == 'y'))
			return false;
	}

	cout << "TEST 3 PASS: " << line << endl;
	return true;
}

static bool test4(string line) {
	for (int i = 0; i < line.length() - 3; ++i) {
		for (int j = i + 2; j < line.length() - 1; ++j) {
			auto combined1 = string(1, line[i]) + line[i + 1];
			auto combined2 = string(1, line[j]) + line[j + 1];

			if (combined1 == combined2) {
				cout << combined1 << " " << combined2 << endl;
				cout << "TEST 4 PASS: " << line << endl;
				return true;
			}
		}
	}

	return false;
}

static bool test5(string line) {
	for (int i = 0; i < line.length(); ++i) {
		if (line[i] == line[i + 2]) {
			cout << line[i] << line[i + 1] << line[i + 2] << endl;
			cout << "TEST 5 PASS: " << line << endl;
			return true;
		}
	}

	return false;
}