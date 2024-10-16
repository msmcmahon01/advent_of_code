#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class City {
	string name;

	City() : name() {};
};

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	string word;
	int count = 0;

	while (inputFile >> word) {
		if (count == 0) {
            
		}
	}
}