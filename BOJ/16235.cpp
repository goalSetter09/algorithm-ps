#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int r;
    int c;
    int age;
    int energy;
    bool operator <(const Tree& other) const {
        return age > other.age;
    }
};

int n, m, k;
int food[11][11]; // 땅에 있는 양분
int a[11][11]; // 기계가 추가하는 양분
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<Tree> deadTree;
vector<Tree> trees;

void spring() {
    for (int i = trees.size() - 1; i >= 0; i--) {
        if (food[trees[i].r][trees[i].c] < trees[i].age) {
            deadTree.push_back(trees[i]);
            trees.erase(trees.begin() + i);
        } else {
            food[trees[i].r][trees[i].c] -= trees[i].age;
            trees[i].age++;
            trees[i].energy += trees[i].age;
        }
    }
}


void summer() {
    for (auto dt: deadTree) {
        food[dt.r][dt.c] += dt.age / 2;
    }
    deadTree.clear(); // 초기화
}

void fall() {
    vector<Tree> addList;
    for (auto t : trees) {
        if (t.age % 5 == 0) {
            for (int dir = 0; dir < 8; dir++) {
                int nr = t.r + dx[dir];
                int nc = t.c + dy[dir];
                if (nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                    struct Tree nt = {nr, nc, 1, 0};
                    addList.push_back(nt);
                }
            }
        }
    }

    for (auto t: addList) {
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end());
}

void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            food[i][j] += a[i][j];
        }
    }
}

void year() {
    spring();
    summer();
    fall();
    winter();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        struct Tree tree = {x, y, z, 0};
        trees.push_back(tree);
    }

    sort(trees.begin(), trees.end());

    while (k--) {
        year();
    }

    cout << trees.size();
}
