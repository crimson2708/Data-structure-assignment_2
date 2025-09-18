#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int main() {
    string str, result = "";
    cout << "Enter a string: ";
    getline(cin, str);

    for (char c : str) {
        if (!isVowel(c))
            result += c;
    }

    cout << "String after removing vowels: " << result << endl;
    return 0;
}