#include <bits/stdc++.h>
#include <atcoder/all>
#include <math.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000; 

ll mod = 1000000007;

int main(){
    int n, Q; cin >> n >> Q;
    vector <int> c(n);
    rep(i, n){
        int _c; cin >> _c;
        _c --;
        c.at(i) = _c;
    }
    vector <vector<int>> q(Q);
    rep(i, Q){
        int x, y, z; cin >> x >> y >> z;
        y --;
        z --;
        q.at(i) = {x, y, z};
    }

    // mp[group][class] ... 各グループに属する各クラスの人数
    vector <map<int, int>> mp(n);

    dsu uf(n);
    rep(i, n){
        mp.at(i)[c.at(i)] ++;
    }



    for(auto query: q){
        if(query.at(0) == 1){
            int a, b;
            tie(a, b) = make_tuple(query.at(1), query.at(2));
            if(uf.same(a, b)) continue;
            int g1, g2;
            g1 = uf.leader(a);
            g2 = uf.leader(b);

            uf.merge(a, b);

            int to = uf.leader(g1);
            int from = g1 + g2 - to;

            auto begin = mp.at(from).begin(), end = mp.at(from).end();
            for (auto iter = begin; iter != end; iter++) {
                // first: key, second: value
                // cout << "key = " << iter->first << "\n";
                // cout << "value = " << iter->second << "\n";
                auto key = iter->first;
                auto value = iter->second;

                mp.at(to)[key] += value;
            }
        }
        else{
            int a, b;
            tie(a, b) = make_tuple(query.at(1), query.at(2));
            cout << mp.at(uf.leader(a))[b] << endl;
        }
    }
}