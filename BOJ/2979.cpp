/**
 * BJO 2979 트럭 주차 / 브론즈 2
 */

#include <bits/stdc++.h>
using namespace std;

int park[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int cnt = 3;
    for (int i = 0; i < 3; i++) {
        int st, en;
        cin >> st >> en;
        for (int j = st; j < en; j++) {
            park[j]++;
        }
    }
    int ans = 0;

    for (int i = 1; i < 101; i++) {
        if (park[i] == 3) {
            ans += (c * 3);
        } else if (park[i] == 2) {
            ans += (b * 2);
        } else if (park[i] == 1) {
            ans += a;
        }
    }

    cout << ans;
}
