#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    int n = numbers.size();
    for(int i = 0; i < n; i++) {
        string s = "";
        for(int j = 0; j < i; j++) {
            s.push_back('0');
        }
        for(int j = i; j < n; j++) {
            s.push_back('1');
        }
        do {
            int sum = 0;
            for(int k = 0; k < n; k++) {
                if(s[k] == '0') {
                    sum += numbers[k];
                } else {
                    sum -= numbers[k];
                }
            }
            if(sum == target) {
                answer++;
            }

        } while(next_permutation(s.begin(), s.end()));

    }
    return answer;
}