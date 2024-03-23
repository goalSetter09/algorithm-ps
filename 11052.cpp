#include <bits/stdc++.h>
using namespace std;
int n;
int d[10005], p[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    d[1] = p[1];
    d[2] = max(p[1] * 2, p[2]);
    for (int i = 3; i <= n; i++) {
        d[i] = max(p[i], d[i]);
        for (int j = i - 1; j >= (i / 2); j--) {
            d[i] = max(d[i], d[j] + d[i-j]);
        }
    }
    cout << d[n];
}