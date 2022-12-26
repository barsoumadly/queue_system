#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> directory;
    fstream file;
    string line = "helzoworld";
    file.open("data.txt", ios::out);
    for (int i = 0; i < line.length(); i++) {
        if (i != line.length() - 1)
            file << line[i] << endl;
        else
            file << line[i];
    }
    file.close();
    file.open("data.txt", ios::in | ios::binary);
    while (!file.eof()) {
        int pos = file.tellg();
        char x = file.get();
        directory.insert(pair<char, int>(x, pos));
    }
    file.close();
    file.open("data.txt", ios::in | ios::out);
    file.seekp(directory['z']);
    file.put('l');
    file.close();
    return 0;
}