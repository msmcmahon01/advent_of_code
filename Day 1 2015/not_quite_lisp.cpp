#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    int count = 0;
    int flag = 0;

    string line;

    while (getline(inputFile, line)) {
        int length = line.length();
        for (int i = 0; i < length; ++i) {
            if (line[i] == '(') ++count;
            else --count;

            if (count == -1 && flag != 1) {
                cout << "First access to -1, char number: " << i + 1 << endl;
                flag = 1;
            }
        }
    }

    cout << "Final floor: " << count << endl;

    inputFile.close();

    return 0;
}