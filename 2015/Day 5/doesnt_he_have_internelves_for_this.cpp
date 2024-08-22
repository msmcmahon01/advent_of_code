#include <fstream>
#include <iostream>
#include <string>
using namespace std;

static bool test1(string line);
static bool test2(string line);
static bool test3(string line);

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	string line;
	int total = 0;
	bool one, two, three;

	while (getline(inputFile, line)) {
		one = test1(line);
		two = test2(line);
		three = test3(line);

		if (one && two && three) {
			++total;
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