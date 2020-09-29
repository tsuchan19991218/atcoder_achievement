#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

ll mod = 998244353;
ll INF = 2000000000000000000;

int main(){
    ll n, k; cin >> n >> k;

    vector <int> seen(n + 1, -1);
    vector <ll> sum(n + 1, INF);

    vector <int> p(n + 1);
    vector <ll> c(n + 1);
    vector <vector<int>> un(n + 1);
    vector <int> memo;
    for(int i = 1; i < n + 1; i ++) cin >> p.at(i);
    for(int i = 1; i < n + 1; i ++) cin >> c.at(i);

    for(int i = 1; i < n + 1; i ++){
        if(seen.at(i) != -1) continue;
        ll _sum = 0;
        memo.push_back(i);
        int now = i; int next = p.at(now);
        while(1){
            un.at(i).push_back(now);
            seen.at(now) = 1;
            _sum += c.at(now) - _sum;
            if(seen.at(next) != -1) break;
            c.at(next) += c.at(now);
            now = next;
            next = p.at(now);
        }
        sum.at(i) = _sum;
    }


    ll ans = -INF;

    for(int i: memo){
        ll size = un.at(i).size();
        ll __ans = -INF;
        for(ll start = 0; start < size; start ++){
            for(ll j = 0; j <= min(k, size) - 1; j ++){
                ll end = start + j;
                if(end >= size) end -= size;
                //if(start == end) continue;
                ll tmp = 0;
                // while(now < end){
                //     if(now >= size){
                //         tmp += c.at(un.at(i).at(now - size));
                //     }
                //     else{
                //         tmp += c.at(un.at(i).at(now));
                //     }
                //     now ++;
                // }
                if(start > end){
                    tmp = sum.at(i) - (c.at(un.at(i).at(start - 1)) - c.at(un.at(i).at(end)));
                    //cout << un.at(i).at(start) << "から" << un.at(i).at(end) << "=" << sum.at(i) << " " << c.at(un.at(i).at(start - 1)) << " " << c.at(un.at(i).at(end)) << endl;
                }
                else{
                    if(start == 0) tmp = c.at(un.at(i).at(end));
                    else tmp = c.at(un.at(i).at(end)) - c.at(un.at(i).at(start - 1));
                }
                //cout << tmp << " " << un.at(i).at(start) << "から" << un.at(i).at(end) << endl;
                ll K = k - j - 1;
                K = max(0LL, K);
                K /= size;
                __ans = max(__ans, tmp);
                __ans = max(__ans, tmp + sum.at(i) * K);
            }
        }

        ans = max(ans, __ans);
    }
    cout << ans << endl;
}