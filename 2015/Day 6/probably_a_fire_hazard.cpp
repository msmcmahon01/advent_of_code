#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int grid_size = 1000;

static void turn_on(bool lightArr[grid_size][grid_size], string line);
static void turn_off(bool lightArr[grid_size][grid_size], string line);
static void toggle(bool lightArr[grid_size][grid_size], string line);

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	bool lightArr[grid_size][grid_size] = {false};

	string line;
	int total = 0;

	while (getline(inputFile, line)) {
		if (line[1] == 'o')
			toggle(lightArr, line);
		else if (line[6] == 'n')
			turn_on(lightArr, line);
		else if (line[6] == 'f')
			turn_off(lightArr, line);
	}

	for (int i = 0; i < grid_size; ++i) {
		for (int j = 0; j < grid_size; ++j) {
			if (lightArr[j][i] == true) {
				++total;
			}
		}
	}

	cout << "Total number of lights on: " << total << endl;

	return 0;
}

static void toggle(bool lightArr[grid_size][grid_size], string line) {
	int x1, x2, y1, y2;

	sscanf(line.c_str(), "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2);

	cout << x1 << x2 << y1 << y2 << endl;

	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			lightArr[i][j] = !lightArr[i][j];
		}
	}
}

static void turn_on(bool lightArr[grid_size][grid_size], string line) {
	int x1, x2, y1, y2;

	sscanf(line.c_str(), "turn on %d,%d through %d,%d", &x1, &y1, &x2, &y2);

	cout << x1 << x2 << y1 << y2 << endl;

	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			lightArr[i][j] = true;
		}
	}
}

static void turn_off(bool lightArr[grid_size][grid_size], string line) {
	int x1, x2, y1, y2;

	sscanf(line.c_str(), "turn off %d,%d through %d,%d", &x1, &y1, &x2, &y2);

	cout << x1 << x2 << y1 << y2 << endl;

	for (int i = y1; i <= y2; ++i) {
		for (int j = x1; j <= x2; ++j) {
			lightArr[i][j] = false;
		}
	}
}