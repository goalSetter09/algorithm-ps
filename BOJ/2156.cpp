#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10001];
int d[10001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    d[1][1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
        d[i][1] = d[i-1][0] + arr[i];
        d[i][2] = d[i - 1][1] + arr[i];
    }
    cout << max(max(d[n - 1][0], d[n - 1][1]), d[n - 1][2]);

}

