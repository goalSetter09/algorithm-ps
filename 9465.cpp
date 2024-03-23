#include <bits/stdc++.h>
using namespace std;
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int d[100005][2] = {0};
        int s[2][100005] = {0};
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> s[i][j];
            }
        }
        d[1][0] = s[0][1];
        d[1][1] = s[1][1];
        d[2][0] = d[1][1] + s[0][2];
        d[2][1] = d[1][0] + s[1][2];
        for (int i = 3; i <= n; i++) {
            d[i][0] = max(d[i-1][1] + s[0][i], d[i-2][1] + s[0][i]);
            d[i][1] = max(d[i-1][0] + s[1][i], d[i-2][0] + s[1][i]);
        }

        cout << max(d[n][0], d[n][1]) << '\n';
    }



}