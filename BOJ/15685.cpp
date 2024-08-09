#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> dv; // 방향벡터를 기록하는 스택


void findPath() {
    vector<int> temp(dv);
    while(!temp.empty()) {
        int cur = temp.back();
        dv.push_back((cur + 1) % 4);
        temp.pop_back();
    }
}

void draw(int x, int y) {
    int nx = x;
    int ny = y;
    for (auto path: dv) {
        nx = nx + dx[path];
        ny = ny + dy[path];
        arr[ny][nx] = 1;
    }
}

int count() {
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if(arr[i][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j] == 1 && arr[i+1][j+1] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 101; i++) {
        fill(arr[i], arr[i] + 101, 0);
    }
    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        dv.clear();
        arr[y][x] = 1;
        dv.push_back(d);
        for (int gen = 1; gen <= g; gen++) {
            findPath();
        }

        draw(x, y);
    }

    cout << count();



}