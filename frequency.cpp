#include <iostream>
#include <string>
#include<unordered_map>
#include <cctype>
using namespace std;

int main() {
    string paragraph;
    cout << "Enter the input string/paragraph - ";
    getline(cin, paragraph);
    unordered_map<char, int> frequencyMap;
    for (char ch : paragraph) {
        if (isalpha(ch)) {
            frequencyMap[ch]++;
        }
    }
    cout << "Character - Frequency" << endl;
    for (const auto& [character, frequency] : frequencyMap) {
        cout << character << " - " << frequency << endl;
    }
}
