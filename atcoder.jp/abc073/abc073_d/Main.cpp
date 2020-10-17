#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll INF = 1000000000000005;

int main(){
    int n, m, R; cin >> n >> m >> R;
    vector <int> r(R);
    rep(i, R) cin >> r.at(i);
    sort(r.begin(), r.end());
    vector <vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    rep(i, m){
        int a, b, c; cin >> a >> b >> c;
        dist.at(a).at(b) = c;
        dist.at(b).at(a) = c;
    }

    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                int a = i;
                int b = j;
                if(dist.at(a).at(b) > dist.at(a).at(k) + dist.at(k).at(b)){
                    dist.at(a).at(b) = dist.at(a).at(k) + dist.at(k).at(b);
                    dist.at(b).at(a) = dist.at(a).at(b);
                }
                //dist.at(a).at(b) = min(dist.at(a).at(b), dist.at(a).at(k) + dist.at(k).at(b));
            }
        }
    }

    ll ans = INF;
    do{
        ll tmp = 0;
        rep(i, R - 1){
            tmp += dist.at(r.at(i)).at(r.at(i + 1));
        }
        if(ans > tmp) ans = tmp;
    }while(next_permutation(r.begin(), r.end()));

    cout << ans << endl;

}