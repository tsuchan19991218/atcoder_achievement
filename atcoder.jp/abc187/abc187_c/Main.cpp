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
    vector <string> s(n);
    map <string, int> cnt;
    int c = 0;
    rep(i, n){
        string _s; cin >> _s;
        if(cnt[_s] == 0){
            cnt[_s] = 1;
        }
        else{
            cnt[_s] += 1;
        }

        if(_s.at(0) == '!'){
            _s.erase(0, 1);
            if(cnt[_s] >= 1){
                cout << _s << endl;
                return 0;
            }
        }
        else{
            if(cnt['!' + _s] > 0){
                if(cnt[_s] >= 1){
                    cout << _s << endl;
                    return 0;
                }
            }    
        }
    }
    // sort(s.begin(), s.end());

    // for(int i = 1; i < n; i ++){
    //     if(s.at(i) == s.at(i - 1)){
    //         cout << s.at(i) << endl;
    //         return 0;
    //     }
    // }
    cout << "satisfiable" << endl;
}