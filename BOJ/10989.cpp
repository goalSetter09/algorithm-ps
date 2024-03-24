#include <bits/stdc++.h>
using namespace std;

int arr[10002];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp]++;
    }
    for (int i = 1; i <= 10000; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << '\n';
            }
        }
    }

}