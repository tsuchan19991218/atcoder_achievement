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
    int n; cin >> n;
    int m; cin >> m;

    vector <vector<int>> G(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        a --;
        b --;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    int k; cin >> k;
    vector <int> is_v(n);
    vector <int> is_zip(n, -1);
    rep(i, k){
        int c; cin >> c;
        c --;
        is_v.at(c) = 1;
        is_zip.at(c) = i;
    }

    //各i,jについてc_i ~ c_jの最短距離を求める
    vector <vector <int>> dist(k, vector<int>(k, INF));
    for(int i = 0; i < n; i ++){
        if(is_v.at(i) == 0) continue;
        deque <pair<int, int>> d; d.push_back(make_pair(i, 0));
        vector <int> seen(n, -1); seen.at(i) = 1;
        while(d.size()){
            auto p = d.front();
            d.pop_front();
            int now = p.first;
            int cost = p.second;
            if(is_v.at(now) != 0){
                dist.at(is_zip.at(i)).at(is_zip.at(now)) = min(dist.at(is_zip.at(i)).at(is_zip.at(now)), cost);
            }
            for(auto next: G.at(now)){
                if(seen.at(next) != -1) continue;
                int next_cost = cost + 1;
                seen.at(next) = 1;
                d.push_back(make_pair(next, next_cost));
            }
        }
    }

    // for(int i = 0; i < k; i ++){
    //     rep(j, k){
    //         //dist.at(i).at(j) ++;
    //         cout << dist.at(i).at(j) << "  ";
    //     }
    //     cout << endl;
    // }

    //求めた距離から巡回セールスマンを行う
    vector <vector <int>> dp((1 << k), vector<int>(k, INF));
    rep(i, k){
        dp.at((1 << i)).at(i) = 1;
    }
    rep(s, (1 << k)){
        if(s == 0) continue;
        rep(i, k){
            if(!((s >> i) & 1)) continue;
            int tmp = INF;
            rep(j, k){
                tmp = min(tmp, dp.at(s ^ (1 << i)).at(j) + dist.at(j).at(i));
            }
            //cout << tmp << endl;
            dp.at(s).at(i) = min(dp.at(s).at(i), tmp);
        }
    }

    int ans = INF;
    for(auto tmp: dp.at((1 << k) - 1)) ans = min(ans, tmp);
    if(ans == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;


// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('joshima', 'tokio', 'nara', 'o',1970);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('kokubun', 'tokio', 'tokyo', 'o',1974);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('matsuoka', 'tokio', 'hokkaido', 'a',1977);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('nagase', 'tokio', 'kanagawa', 'o',1978);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('ohno', 'arashi', 'tokyo', 'a',1980);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('sakurai', 'arashi', 'tokyo', 'a',1982);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('aiba', 'arashi', 'chiba', 'ab',1982);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('ninomiya', 'arashi', 'tokyo', 'a',1983);
// insert into Johnnys (name, team, bornIn, bloodType, birthYear) VALUES ('matsumoto', 'arashi', 'tokyo', 'a',1983);


}