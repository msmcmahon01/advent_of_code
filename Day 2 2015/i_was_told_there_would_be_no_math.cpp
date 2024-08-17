#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int get_min(int l, int w, int h);

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	int l = 0, w = 0, h = 0, paper = 0, flag = 0, min = 0, ribbon = 0;
	string line, num;

	while (getline(inputFile, line)) {
		for (int i = 0; i < line.length(); ++i) {
			if (line[i] != 'x') {
				num += line[i];
			} else {
				if (flag == 0) {
					l = stoi(num);
					num.clear();
					++flag;
				} else if (flag == 1) {
					w = stoi(num);
					num.clear();
					++flag;
				}
			}
		}
		if (flag == 2) {
			h = stoi(num);
			num.clear();
			flag = 0;
		}

        min = get_min(l, w, h);

		paper += (2 * l * w) + (2 * w * h) + (2 * h * l) + min;

        if (min == (l * w)) ribbon += (2 * l + 2 * w);
        else if (min == (w * h)) ribbon += (2 * w + 2 * h);
        else if (min == (h * l)) ribbon += (2 * h + 2 * l);

        ribbon += (l * w * h);
	}

	cout << "Total amount of wrapping paper needed: " << paper << endl;
	cout << "Total amount of ribbon needed: " << ribbon << endl;

	return 0;
}

int get_min(int l, int w, int h) {
	int lw = l * w;
	int wh = w * h;
	int hl = h * l;

	if (lw <= wh && lw <= hl)
		return lw;
	else if (wh <= lw && wh <= hl)
		return wh;
	else if (hl <= lw && hl <= wh)
		return hl;
}