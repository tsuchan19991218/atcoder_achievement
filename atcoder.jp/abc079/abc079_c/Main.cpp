#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    string s; cin >> s;
    
    rep(pat, pow(2, 3)){
        int ans = s.at(0) - '0';
        vector <char> op;
        for(int i = 0; i < 3; i ++){
            if((pat >> i & 1)){
                ans += s.at(i + 1) - '0';
                op.push_back('+');
            }
            else{
                ans -= s.at(i + 1) - '0';
                op.push_back('-');
            }
        }

        if(ans == 7){
            rep(i, 4){
                if(i != 0){
                    cout << op.at(i - 1);
                }
                cout << s.at(i);
            }
            cout << "=7" << endl;
            return 0;
        }
    }
     
}