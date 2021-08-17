#include<bits/stdc++.h>
// #pragma optimize("-O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,avx,mmx,tune=native")
// #define ll long long
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
#define vvi vector<vector<ll>>
#define vi vector<ll>
#define sz(a) ll((a).size())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// typedef tree<
// ll,
// null_type,
// less<ll>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;
//#define ll long long
const ll MOD =  1e9 + 7;
const ll BIG_INF = 4e18;
const ll INF = 1e17;
const ll mod = 1e9 + 7;
ll fast_exp(ll a, ll b)
{
    if(b <= 0)
       return 1;
    else
    {
       ll res = 1;
       res = fast_exp(a,b/2);
       res = res % mod;     
       res = (res*res)%mod;
       if(b%2 == 1)
          res = (res*a)%mod;
       return res;
 
    }
}





mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(v.begin(),v.end(),rng);
 
ll true_rand(ll n) {
    // Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<ll> uid(0, n - 1);
    return uid(rng);
}

// gambler's ruin: A has i, B has N-i  
// P[i] = A wins = (1 - (q/p)^i)/(1 - (q/p)^n) 
    


// ll fact[N] = {};
// ll fac_inv[N] = {};
// void precompute_factorial()
// {    
//     fact[0] = 1;
//     fac_inv[0] = 1;
//     for(ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i-1] * i) % mod;
//         fac_inv[i] = (fast_exp(i,mod-2) * fac_inv[i-1]) % mod;
//     }
// }
// ll binom(ll n, ll r)
// {
//   if(r < 0 || r > n || n < 0)
//       return 0;
//   ll ans = fact[n];
//   ans = (ans * fac_inv[n-r]) % mod;
//   ans = (ans * fac_inv[r]) % mod;
//   return ans;
// }

typedef double ld;
const long double pi = acos(-1.0);
using cd = complex<double>;
const double PI = acos(-1);
const ll N = 1e6+1000;

bool Q;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};
struct LineContainer : multiset<Line> {
    const ll inf = INF;
    ll div(ll a, ll b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        // If Q = 1 then for max else for min
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.k * x + l.m;
    }
};

const ll sq = 400;

// (N/B) * N + (N * B)/2 + NlogN

int32_t main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("combi.in","r",stdin);
    ll t;
    cin >> t;
    while(t--)
    {
      ll n;
      cin >> n;
      ll a[2 * n + 1];
      ll b[2 * n + 1];
      for(ll i = 1; i <= n; i++)
         cin >> a[i];
      for(ll i = 1; i <= n; i++)
         cin >> b[i];
      for(ll i = n + 1; i <= 2 * n; i++)
      {
         a[i] = a[i-n];
         b[i] = b[i-n];
      }
      ll pref[2 * n + 5] = {}; // for sum of b[i]
      ll cumul[2 * n + 5] = {};
      for(ll i = 1; i <= 2 * n; i++)
      {   
         cumul[i] = cumul[i-1] + a[i];
         pref[i] = pref[i-1] + b[i];
      }
      // cout << "cumul:      ";
      // for(ll i = 1; i <= 2 * n; i++)
      //    cout << cumul[i] << " ";
      ll cumul_of_cumul[2 * n + 5] = {};
      
      for(ll i = 1; i <= 2* n; i++)
         cumul_of_cumul[i] = cumul_of_cumul[i-1] + cumul[i];

      LineContainer CHT;
      
      ll ans = -INF;
      for(ll i = 2; i <= n; i++)
      {
         ll corresponding_right = i + n - 1;
         ll cumuls_right = cumul_of_cumul[corresponding_right] - cumul_of_cumul[n] + pref[corresponding_right] - pref[n];
         ll len = i + n - 1 - n;
         CHT.add(-len,cumuls_right);
         ll rem_cumul = cumul_of_cumul[n] - cumul_of_cumul[i-1] + pref[n] - pref[i-1];
         ll rem_len = n - i + 1;
         ans  = max(ans, CHT.query(cumul[i-1]) + rem_cumul - rem_len * cumul[i-1]); 
      }
      LineContainer CHT2;
      for(ll i = n; i >= 1; i--)
      {
         ll sub_cumul = cumul_of_cumul[n] - cumul_of_cumul[i] + pref[n] - pref[i];
         ll len = n - i;
         CHT2.add(len,-sub_cumul);
         ll cumul_to_end = cumul_of_cumul[n] - cumul_of_cumul[i-1] + pref[n] - pref[i-1];
         ll len_to_end = n - (i - 1);
         ans = max(ans, cumul_to_end - len_to_end * cumul[i-1] + CHT2.query(cumul[i-1]));
      }
      // from a particular i---------------> we need the sum of next len b[i] + cumul[i] - l * cumul[i-1]
   
      cout << ans << endl;
      // from a particular i---------------> we need the sum of next l few cumul[i] - l * cumul[i-1]

    }

    return 0;
    
}
    
