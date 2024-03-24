#include <bits/stdc++.h>
using namespace std;
int n;
int d[1005][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i <= 9; i++) {
        d[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = j; k <=9; k++){
                d[i][j] = (d[i][j] + d[i-1][k]) % 10007;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum = (sum + d[n][i]) % 10007;
    }
    cout << sum;
}