#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n, q; cin >> n >> q;
    vector <vector<int>> G(n + 1);
    vector <int> point(n + 1);

    rep(i, n - 1){
        int a, b; cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    rep(i, q){
        int x, p; cin >> x >> p;
        point.at(x) += p;
    }

    deque <int> d;
    vector <long long> ans(n + 1, 0);
    vector <int> seen(n + 1, -1);
    d.push_back(1);
    ans.at(1) += point.at(1);
    seen.at(1) = 1;

    while(!d.empty()){
        int v = d.front();
        d.pop_front();
        
        int v_child_cnt = G.at(v).size();
        for(int i = 0; i < v_child_cnt; i ++){
            int next = G.at(v).at(i);
            if(seen.at(next) != -1)continue;

            ans.at(next) += point.at(next) + ans.at(v);
            d.push_back(next);
            seen.at(next) = 1;
        }
    }

    for(int i = 1; i < n + 1; i ++){
        cout << ans.at(i) << " ";
    }
    cout << endl;
}