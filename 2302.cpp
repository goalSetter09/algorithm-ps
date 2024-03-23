#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[45], d[45];
int result = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> f[i];
    }
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    for (int i = 1; i <= m; i++) {
        result *= d[f[i] - f[i - 1] - 1];
    }
    result *= d[n - f[m]];
    cout << result;
}