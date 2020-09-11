#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(void){
    vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  bool flag = false;

  rep(i, 5){
      if (i == 0) continue;
      if (data.at(i) == data.at(i - 1)) flag = true;
  }

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;

}
