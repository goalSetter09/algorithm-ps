//
// Created by 김동영 on 2024/01/08.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k, dir;
int c[5][4] = {
        {},
        {},
        {},
        {},
        {},

};
int mp[22][22];
int v[7]; // 주사위에 적혀있는 수

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x >> y >> k;


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
    }
  }
  // 5
  // 4 4 4 1 3 3 3 2
  int index = 6;
  while (k--) {
    cin >> dir;
    if (dir == 1) {
      x++;
    } else if (dir == 2) {
      x--;
    } else if (dir == 3) {
      y--;
    } else { // dir == 4
      y++;
    }
    index = c[index][dir];
    cout << "======index======" << index << '\n';
    if (mp[x][y] == 0) {
      mp[x][y] = v[index];
    } else {
      v[index] = mp[x][y];
      mp[x][y] = 0;
    }
    cout << v[7 - index] << '\n';
  }
}
