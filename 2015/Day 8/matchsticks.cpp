#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	string line;
	int totala = 0, totalb = 0, totalc = 0;

	while (getline(inputFile, line)) {
		int testa = 0, testc = 0;
		cout << line << endl;
		for (int i = 0; i < line.length(); ++i) {
			if (i == 0 || i == line.length() - 1) {
				++totala;
				++testa;
				++totalc;
				++testc;
				cout << line[i] << testa << " " << testc << endl;
			} else if ((line[i] == '\\' && line[i + 1] == '\\') ||
					   (line[i] == '\\' && line[i + 1] == '"')) {
				totala += 2;
				testa += 2;
				++totalb;
				totalc += 4;
				testc += 4;
				++i;
				cout << line[i] << testa << " " << testc << endl;
			} else if (line[i] == '\\' && line[i + 1] == 'x' &&
					   (line[i + 2] != line.length() &&
						isxdigit(line[i + 2])) &&
					   (line[i + 3] != line.length() &&
						isxdigit(line[i + 3]))) {
				totala += 4;
				testa += 4;
				++totalb;
				totalc += 5;
				testc += 5;
				i += 3;
				cout << line[i] << testa << " " << testc << endl;
			} else {
				++totala;
				++testa;
				++totalb;
				++totalc;
				++testc;
				cout << line[i] << testa << " " << testc << endl;
			}
		}

		totalc += 4;
		testc += 4;
		cout << testa << " " << testc << endl;
	}

	cout << totala << " - " << totalb << endl;
	cout << "The total number of characters in the strings is: "
		 << totala - totalb << endl;

	cout << totalc << " - " << totala << endl;
	cout << "The total for part 2 is: " << totalc - totala << endl;

	return 0;
}