#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int grid_size = 1000;

static int **toggle2(int **lightArr2, string line, int &total);
static int **turn_on2(int **lightArr2, string line, int &total);
static int **turn_off2(int **lightArr2, string line, int &total);

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	int **lightArr2 = new int *[grid_size];

	for (int i = 0; i < grid_size; ++i) {
		lightArr2[i] = new int[grid_size];
	}

	for (int i = 0; i < grid_size; ++i) {
		for (int j = 0; j < grid_size; ++j) {
			lightArr2[i][j] = 0;
		}
	}

	string line;
	int total2 = 0;

	while (getline(inputFile, line)) {
		if (line[1] == 'o')
			toggle2(lightArr2, line, total2);
		else if (line[6] == 'n')
			turn_on2(lightArr2, line, total2);
		else if (line[6] == 'f')
			turn_off2(lightArr2, line, total2);
	}

	cout << "Total brightness: " << total2 << endl;

    for (int i = 0; i < grid_size; ++i) {
        delete[] lightArr2[i];
    }
    delete[] lightArr2;

	return 0;
}

static int **toggle2(int **lightArr2, string line, int &total2) {
	int x1, x2, y1, y2;

	sscanf(line.c_str(), "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2);

	cout << x1 << x2 << y1 << y2 << endl;

	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			lightArr2[i][j] += 2;
			total2 += 2;
		}
	}

	return lightArr2;
}

static int **turn_on2(int **lightArr2, string line, int &total2) {
	int x1, x2, y1, y2;

	sscanf(line.c_str(), "turn on %d,%d through %d,%d", &x1, &y1, &x2, &y2);

	cout << x1 << x2 << y1 << y2 << endl;

	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			++lightArr2[i][j];
			++total2;
		}
	}

	return lightArr2;
}

static int **turn_off2(int **lightArr2, string line, int &total2) {
	int x1, x2, y1, y2;

	sscanf(line.c_str(), "turn off %d,%d through %d,%d", &x1, &y1, &x2, &y2);

	cout << x1 << x2 << y1 << y2 << endl;

	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			if (lightArr2[i][j] > 0) {
				--lightArr2[i][j];
				--total2;
			}
		}
	}

	return lightArr2;
}