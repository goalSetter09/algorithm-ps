#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int solution(vector<int> nums)
{
    int length = nums.size() / 2;
    cout << "nums.size" << ' ' << length << '\n';
    for(auto v : nums) {
        arr[v]++;
    }

    int cnt = 0;

    sort(arr, arr + 200001);
    for(int i = 1; i <= 200001; i++) {
        if(arr[i] == 0) {
            continue;
        }
        cnt++;
        cout << i << ' ' << cnt << '\n';
    }
    int answer = 0;
    cout << cnt << '\n';

    if(cnt >= length) {
        answer = length;
    } else {
        answer = cnt;
    }

    return answer;
}