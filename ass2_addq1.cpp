#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    int countPairs = 0;

    for(int i = 0; i < n; i++) {
        int x = arr[i];

        if(mp.find(x - k) != mp.end()) {
            countPairs += mp[x - k];
        }

        if(mp.find(x + k) != mp.end()) {
            countPairs += mp[x + k];
        }

        mp[x]++;
    }

    cout << countPairs;

    return 0;
}
