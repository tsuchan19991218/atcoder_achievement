#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n; cin >> n;
    vector <int> indexes(n + 1);
    vector <int> p(n);
    rep(i, n){
        cin >> p.at(i);
        indexes.at(p.at(i)) = i;
    }
    vector <int> is_swaped(n - 1, -1);
    deque <int> ans;

    for(int now = 1; now < n + 1; now ++){
        int index;
        index = indexes.at(now);
        //cout << index << endl;
        if(index < now - 1){
            cout << -1 << endl;
            return 0;
        }
        for(int i = index - 1; i >= now - 1; i --){
            //cout << i << endl;
            if(is_swaped.at(i) == 1){
                cout << -1 << endl;
                return 0;
            }
            is_swaped.at(i) = 1;
            int tmp = p.at(i);
            p.at(i) = p.at(i + 1);
            indexes.at(p.at(i + 1)) = i;
            p.at(i + 1) = tmp;
            indexes.at(tmp) = i + 1;
            ans.push_back(i);
        }
    }

    if(ans.size() != n - 1){
        cout << -1 << endl;
        return 0;
    }
    while(!ans.empty()){
        cout << ans.front() + 1 << endl;
        ans.pop_front();
    }
}