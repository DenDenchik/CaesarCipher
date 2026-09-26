#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdio.h>
using namespace std;

string caesar(int key, string text) {
    int len = text.length();
    int i = 0;
    while (i < len) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ('a' + (text[i] - 'a' + key) % 26);
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ('A' + (text[i] - 'A' + key) % 26);
        }
        i++;
    }
    return text;
}

int main() {
    int key;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> key;
    key = key % 26;
    if (key < 0) {
        key = 26 - abs(key);
    }
    string text;
    getline(fin, text);
    getline(fin, text);
    fin.close();
    fout << "Original text:\n";
    fout << text;

    fout << "\n\nEncrypted text:\n";
    text = caesar(key, text);
    fout << text;

    fout << "\n\nDecrypted text:\n";
    key = 26 - key;
    text = caesar(key, text);
    fout << text;
    fout.close();

    return 0;
}