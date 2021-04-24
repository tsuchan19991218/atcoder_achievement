#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    // string s1 = s.substr(0, n);
    // string s2 = s.substr(n);
    //cout << s1 << endl;
    int q; cin >> q;
    bool changed = false;
    while(q--){
        int t; cin >> t;
        //cout << t << endl;
        if(t == 1){
            if(changed){
                int a, b; cin >> a >> b;
                a --;
                b --;
                a = (a + n) % (2 * n);
                b = (b + n) % (2 * n);
                //cout << a << " " << b << endl;
                char box = s.at(a);
                s.at(a) = s.at(b);
                s.at(b) = box;
            }
            else{
                int a, b; cin >> a >> b;
                a --;
                b --;
                // a = (a + n) % (2 * n);
                // b = (b + n) % (2 * n);
                char box = s.at(a);
                s.at(a) = s.at(b);
                s.at(b) = box;
            }
        }

        if(t == 2){
            int a, b;
            cin >> a >> b;
            changed = (changed == false);
        }
    }

    string s1 = s.substr(0, n);
    string s2 = s.substr(n);
    if(changed){
        cout << s2 << s1 << endl;
    }
    else{
        cout << s1 << s2 << endl;
    }
}