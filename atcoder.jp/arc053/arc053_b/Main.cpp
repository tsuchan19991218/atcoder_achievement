#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    string s; cin >> s;
    vector <int> chr_cnt(400, -1);
    for(auto c: s){
        if(chr_cnt.at(c) == -1){
            chr_cnt.at(c) = 1;
            continue;
        }
        chr_cnt.at(c) ++;
    }
    int cnt_1 = 0;
    int min_not_1 = 10000000;
    ll sum_not_1 = 0;
    ll sum_kisu = 0;
    priority_queue <int, vector<int>, greater<int>> box;
    for(auto num: chr_cnt){
        if(num == -1) continue;
        //cout << num << endl;
        if(num % 2 == 1){
            cnt_1 ++;
            sum_kisu += num / 2;
        }
        else{
            sum_not_1 += num / 2;
        }
        min_not_1 = min(min_not_1, num);
    }
    if(min_not_1 == 10000000){
        cout << 1 << endl;
        return 0;
    }
    if(cnt_1 == 0){
        cout << sum_not_1 * 2 << endl;
        return 0;
    }

    float ans = 0;
    ans = (float)(sum_kisu) / (float)cnt_1;
    ans += (float)(sum_not_1) / (float)cnt_1;

    //cout << sum_kisu << " " << sum_not_1 << endl;
    cout << (int)(ans) * 2 + 1 << endl;
}