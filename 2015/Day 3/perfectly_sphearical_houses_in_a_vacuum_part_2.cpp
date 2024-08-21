#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class House {
   public:
	int presents = 0;
	bool hit = false;

	House() : presents(0), hit(false) {};

	House(int numPresents, bool isHit) : presents(numPresents), hit(isHit) {};

    ~House() {};

	bool been_hit() {
		if (this->presents >= 1) this->hit = true;
	}
};

House** add_presents(House** houseArr, int pos_y, int pos_x, int& total) {
	++houseArr[pos_y][pos_x].presents;

	if (!houseArr[pos_y][pos_x].hit) {
		houseArr[pos_y][pos_x].been_hit();
		++total;
	}

	return houseArr;
}

int main() {
	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 1;
	}

	int def_size_x, def_size_y;
	def_size_x = def_size_y = 250;
	House** houseArr = new House*[def_size_y];

	for (int i = 0; i < def_size_y; ++i) {
		houseArr[i] = new House[def_size_x];
	}

	int pos_x, pos_y, rob_pos_x, rob_pos_y;
	pos_x = rob_pos_x = def_size_x / 2;
	pos_y = rob_pos_y = def_size_y / 2;

	++houseArr[pos_y][pos_x].presents;
	houseArr[pos_y][pos_x].been_hit();

	int total = 1;
	bool is_robot_turn = false;
	string line;

	cout << total << " @: " << pos_x << " " << pos_y << " & " << rob_pos_x
		 << " " << rob_pos_y << endl;

	while (getline(inputFile, line)) {
		for (int i = 0; i < line.length(); ++i) {
			if (!is_robot_turn) {
				if (line[i] == '^')
					++pos_y;
				else if (line[i] == 'v')
					--pos_y;
				else if (line[i] == '<')
					--pos_x;
				else if (line[i] == '>')
					++pos_x;
			} else if (is_robot_turn) {
				if (line[i] == '^')
					++rob_pos_y;
				else if (line[i] == 'v')
					--rob_pos_y;
				else if (line[i] == '<')
					--rob_pos_x;
				else if (line[i] == '>')
					++rob_pos_x;
			}

			if (pos_x < 0 || pos_x > def_size_x || pos_y < 0 ||
				pos_y > def_size_y || rob_pos_x < 0 || rob_pos_x > def_size_x ||
				rob_pos_y < 0 || rob_pos_y > def_size_y) {
				cerr << "More space required!" << endl;

				for (int j = 0; j < def_size_y; ++j) {
					delete[] houseArr[j];
				}
				delete[] houseArr;

				return 1;
			}

			if (!is_robot_turn)
				add_presents(houseArr, pos_y, pos_x, total);
			else if (is_robot_turn)
				add_presents(houseArr, rob_pos_y, rob_pos_x, total);

			is_robot_turn = !is_robot_turn;

			cout << total << " @: " << pos_x << " " << pos_y << " & "
				 << rob_pos_x << " " << rob_pos_y << endl;
		}
	}

	cout << "The total number of houses hit is: " << total << endl;

	for (int i = 0; i < def_size_y; ++i) {
		delete[] houseArr[i];
	}
	delete[] houseArr;

	return 0;
}