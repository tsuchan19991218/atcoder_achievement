#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n, k; cin >> n >> k;
    vector <int> a(n); rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());

    vector <int> num_cnt(n);
    for(auto num: a){
        num_cnt.at(num) ++;
    }

    vector <int> score(k);

    vector <int> accum_min(n);
    accum_min.at(0) = num_cnt.at(0);
    rep(i, n){
        if(i == 0) continue;
        accum_min.at(i) = min(accum_min.at(i-1), num_cnt.at(i));
    }

    int j = n-1;
    for(int i = 1; i <= k; i ++){
        while(j >= 0){
            if(accum_min.at(j) >= i){
                score.at(i-1) = j + 1;
                break;
            }
            else{
                j --;
            }
        }
    }
    int ans = 0;
    rep(i, k){
        ans += score.at(i);
    }
    cout << ans << endl;
}

