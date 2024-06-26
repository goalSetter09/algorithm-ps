//
// Created by 김동영 on 2024/01/07.
//
#include <bits/stdc++.h>

using namespace std;

int t, n;
int d[1000001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    d[1][0] = 1;
    d[2][0] = 1;
    d[2][1] = 1;
    d[3][0] = 2;
    d[3][1] = 1;
    d[3][2] = 1;
    for (int i = 4; i <= 1000000; i++) {
        d[i][0] = ((d[i - 1][0] + d[i - 1][1]) % 1000000009 + d[i - 1][2]) % 1000000009;
        d[i][1] = ((d[i - 2][0] + d[i - 2][1]) % 1000000009 + d[i - 2][2]) % 1000000009;
        d[i][2] = ((d[i - 3][0] + d[i - 3][1]) % 1000000009 + d[i - 3][2]) % 1000000009;
    }

    while (t--) {
        cin >> n;
        cout << ((d[n][0] + d[n][1]) % 1000000009 + d[n][2]) % 1000000009<< '\n';
    }

}
