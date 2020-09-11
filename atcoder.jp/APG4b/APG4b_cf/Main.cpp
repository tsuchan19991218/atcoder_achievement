#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(void){
    int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }

    int ans = 0;
  for (auto apple: A){
      for (auto pina: P){
          if (apple + pina == S) ans += 1;
      }
  }
  cout << ans << endl;

}
