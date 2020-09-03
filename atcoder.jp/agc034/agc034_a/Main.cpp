#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c, d;
    string s;
    string block_2, space_3;
    block_2 = "##";
    space_3 = "...";
    cin >> n >> a >> b >> c >> d;
    cin >> s;
    n -= 1;
    a -= 1;
    b -= 1;
    c -= 1;
    d -= 1;

    string s_s = s.substr(a, (c - a) + 1);
    string s_f = s.substr(b, (d - b) + 1);

    string ans;
    if (s_s.find(block_2) == string::npos and s_f.find(block_2) == string::npos){
        if(c > d){
            string S = s.substr(b - 1, (d - b) + 3);
            //cout << S << endl;
            if (S.find(space_3) == string::npos){
                ans = "No";
            }
            else{
                ans = "Yes";
            }
        }
        else{
            //cout << c << " " << d << endl;
            ans = "Yes";
        }
    }
    else{
        ans = "No";
    }
    cout << ans << endl;
}