#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    string s, t;
    cin >> s >> t;
    if(s.at(0) == 'N'){
        cout << t << endl;
    }
    else{
        t.at(0) -= abs('a' - 'A');
        cout << t << endl;
    }
}