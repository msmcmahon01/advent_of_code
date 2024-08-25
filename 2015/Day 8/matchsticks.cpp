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
	int totala = 0, totalb = 0;

	while (getline(inputFile, line)) {
		cout << line << endl;
		for (int i = 0; i < line.length(); ++i) {
			if (i == 0 || i == line.length() - 1) {
				++totala;
				cout << line[i] << totala << " " << totalb << endl;
			} else if ((line[i] == '\\' && line[i + 1] == '\\') ||
					   (line[i] == '\\' && line[i + 1] == '"')) {
				totala += 2;
				++totalb;
				++i;
				cout << line[i] << totala << " " << totalb << endl;
			} else if (line[i] == '\\' && line[i + 1] == 'x' &&
					   (line[i + 2] != line.length() &&
						isxdigit(line[i + 2])) &&
					   (line[i + 3] != line.length() &&
						isxdigit(line[i + 3]))) {
				totala += 4;
				++totalb;
				i += 3;
				cout << line[i] << totala << " " << totalb << endl;
			} else {
				++totala;
				++totalb;
				cout << line[i] << totala << " " << totalb << endl;
			}
		}
	}

	cout << totala << " - " << totalb << endl;
	cout << "The total number of characters in the strings is: "
		 << totala - totalb << endl;

	return 0;
}