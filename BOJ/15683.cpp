#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m;
int mp[10][10], arr[10][10];
pair<int, int> wall[70];
vector<pair<int, int> > cctv[7];

void copyMap() {
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = mp[i][j];
        }
    }
}

void rotateCCTV() {

}

void play(int &x, int &y, int dir) {
    if(dir == 1) {

    } else if(dir == 2) {

    } else if(dir == 3) {

    } else if(dir == 4) {

    }
}

void xRightMove() {
    for(int j = yIndex; j <= m; j++) {
        if(arr[xIndex][j] == 6) {
            break;
        }
        arr[xIndex][j] = 7;
    }
}

void xLeftMove() {
    for(int j = yIndex; j >= 1; j--) {
        if(arr[xIndex][j] == 6) {
            break;
        }
        arr[xIndex][j] = 7;
    }
}

void yDownMove() {
    for (int i = xIndex; i <= n; i++) {
        if(arr[i][yIndex] == 6;) {
            break;
        }
        arr[i][yIndex] = 7;
    }
}

void yUpMove() {
    for(int j = yIndex; j >= 1; j--) {
        if(arr[i][yIndex] == 6;) {
            break;
        }
        arr[xIndex][j] = 7;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 1) {
                cctv[1].push_back(make_pair(i, j));
                cnt *= 4;
            } else if(mp[i][j] == 2) {
                cctv[2].push_back(make_pair(i, j));
                cnt *= 2;
            } else if(mp[i][j] == 3) {
                cctv[3].push_back(make_pair(i, j));
                cnt *= 4;
            } else if(mp[i][j] == 4) {
                cctv[4].push_back(make_pair(i, j));
                cnt *= 4;
            } else if(mp[i][j] == 5) {
                cctv[5].push_back(make_pair(i, j));
            }
        }
    }

    copyMap();

    for(int i = 0; i < cnt; i++) {
        int brute = cnt;
        int tmp = i % 4;
        brute /= 4;
    }

    vector<int> v = {1, 1, 1 ,1 ,0};
    next_permutation(v, v + 5);

    int xIndex = cctv[1].front().X;
    int yIndex = cctv[1].front().Y;

    for(int j = yIndex; j <= m; j++) {
        if(j == 6) {
            break;
        }
        arr[xIndex][j] = 7;
    }

    for (int i = xIndex; i <= n; i++) {
        if(i == 6) {
            break;
        }
        arr[i][yIndex] = 7;
    }


    /*
     * 1. 판 복사하는 함수
     * 2. cctv 회전시키는 함수
     * 3. cctv 사각지대 구하는 함수
     */


}