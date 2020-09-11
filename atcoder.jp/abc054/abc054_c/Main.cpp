#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
typedef long long ll;

int main(){
    int n, m; cin >> n >> m;
    vector <vector <int>> G(n + 1);
    rep(i, m){
        int from, to; cin >> from >> to;
        G.at(from).push_back(to);
        G.at(to).push_back(from);
    }

    // rep(i, n + 1){
    //     rep(j, G.at(i).size())cout << G.at(i).at(j) << " ";
    //     cout << endl;
    // }

    vector <int> one_pattern;
    rep(i, n){
        if(i == 0) continue;
        one_pattern.push_back(i + 1);
    }

    int ans = 0;

    do{
        vector <int> now_pattern(1, 1);
        copy(one_pattern.begin(), one_pattern.end(), back_inserter(now_pattern));
        // rep(i, one_pattern.size()) cout << one_pattern.at(i) << " ";
        // cout << endl;
        bool ok = true;
        rep(i, n){
            if(i == 0) continue;
            int now, pre;
            now = now_pattern.at(i); pre = now_pattern.at(i - 1);
            if((find(G.at(pre).begin(), G.at(pre).end(), now)) != G.at(pre).end()) continue;

            // if(G.at(pre).size() == 0) ok = false;
            // rep(j, G.at(pre).size()){
            //     if(G.at(pre).at(j) == now){
            //         ok = true;
            //         break;
            //     }
            //     ok = false;
            // }
            ok = false;
            break;
        }

        if(ok) ans += 1;
        // if(ok){
        //         rep(i, one_pattern.size()) cout << one_pattern.at(i) << " ";
        //         cout << endl;
        //     }

    } while (next_permutation(one_pattern.begin(), one_pattern.end()));

    cout << ans << endl;
}