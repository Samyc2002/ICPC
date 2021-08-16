#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define gfoi(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define gfod(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define foi(i, j) gfoi(i, 0, j, 1)
#define fod(i, j) gfod(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define endl "\n"
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vii;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
typedef pair<int, int> pii;
typedef map<int, int>::iterator mi;

ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vi a(n);
        vi b(m);
        foi(i, n) {
            cin >> a[i];
        }
        ll suma = accumulate(a.begin(),a.end(),0)%MOD;
        foi(i, m) {
            cin >> b[i];
        }
        ll sumb = accumulate(b.begin(),b.end(),0)%MOD;
        ll score = (suma*sumb)%MOD;
        int q;
        cin >> q;
        while(q--) {
            int type, l, r, x;
            cin >> type;
            if(type == 1) {
                cin >> l >> r >> x;
                suma += ((r-l+1)*x)%MOD;
                score = (suma*sumb)%MOD;
            } else if(type == 2) {
                cin >> l >> r >> x;
                sumb += ((r-l+1)*x)%MOD;
                score = (suma*sumb)%MOD;
            } else {
                cout << score%MOD << endl;
            }
        }
    }
    return 0;
}