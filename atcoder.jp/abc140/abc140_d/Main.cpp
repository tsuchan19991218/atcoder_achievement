#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){

    int n, k; cin >> n >> k;
    string s; cin >> s;

    int RL_cnt = 0;
    int max_ans = n - 1;
    int ans = 0;

    bool R = false;
    char pre = 'a';
    for(auto c: s){
        if(c == pre) ans ++;
        else pre = c;

        if(!R && c == 'R') R = true;
        if(R && c == 'L'){
            RL_cnt ++;
            R = false;
        }
    }

    ans += 2 * min(k, RL_cnt);

    k -= RL_cnt;
    ans += max(0, k);

    cout << min(ans, max_ans) << endl;

}