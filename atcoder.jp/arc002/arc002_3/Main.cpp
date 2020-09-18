#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};


int main(){
    Radix r;

    int n; cin >> n;

    string s; cin >> s;

    string com = "ABXY";

    string pat;
    
    int ans = 10000000;
    rep(num, pow(4, 4)){
        pat = r.to(num, 4);
        while(pat.size() < 4){
            pat = '0' + pat;
        }

        string L, R;
        L = L + com.at((pat.at(0) - '0')) + com.at((pat.at(1) - '0'));
        R = R + com.at((pat.at(2) - '0')) + com.at((pat.at(3) - '0'));
        
        int cnt = 0;
        string test;
        for(int i = 0; i < (int)(s.size()); i ++){
            int next = i + 1;
            string now;
            if(next < s.size()){
                now = now + s.at(i) + s.at(next);
                if(L == now || R == now){
                    cnt += 1;
                    i += 1;
                    continue;
                }
            }
            cnt += 1;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}