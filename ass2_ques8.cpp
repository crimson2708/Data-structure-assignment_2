#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> st;

    for(int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    cout << "Number of distinct elements: " << st.size();

    return 0;
}
