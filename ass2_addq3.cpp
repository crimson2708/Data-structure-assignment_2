#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    if (str1.size() != str2.size()) {
        cout << "NO";
        return 0;
    }

    int freq[26] = {0};

    for (char c : str1) {
        freq[c - 'a']++;
    }

    for (char c : str2) {
        freq[c - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
