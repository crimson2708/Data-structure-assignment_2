#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    bool possible = false;

    for (int f : freq) {
        if (f >= 2) {
            possible = true;
            break;
        }
    }

    if (possible) cout << "YES";
    else cout << "NO";

    return 0;
}
