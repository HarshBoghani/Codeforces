#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define ll long long
#define li long int
#define ull unsigned long long
#define ld long double
#define all(v) v.begin(),v.end()
#define disp(v) for(int i=0 ;i<v.size() ;i++) cout << v[i] <<' '; cout << endl;
#define sum(v,a,b) accumulate(v+a,v+b,0)
#define fix fixed<<setprecision(10)
#define mod LONG_LONG_MAX
#define M 1000000007
#define pb push_back
#define ff first
#define ss second
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl

void printmap(map<ll,ll>& m){for(auto it : m){cout<<it.ff<<" "<<it.ss<<endl;}cout<<endl;}
void printset(set<ll>& st){for(auto it : st){cout<<it<<" ";}cout<<endl;}
void printmat(vector<vector<ll>>& dp){for(int i=0;i<dp.size();i++){for(int j=0;j<dp[0].size();j++){cout<<dp[i][j]<<" ";}cout<<endl;}cout<<endl;}

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = ans * x;
            ans %= mod;
        }
        y = y >> 1;
        x = x * x;
        x %= mod;
    }
    return ans%mod;
}

bool comp(int x, int y) { return x > y; }

ll modInv(ll n, ll p) { return power(n, p - 2); }

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }

bool is_square(li n) { if (power((int)sqrtl(n), 2) == n) return true; return false; }

ll add(ll a, ll b) { return (a % mod + b % mod) % mod; }

ll mult(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }

ll fact(ll n)
{
    if (n == 0)
        return 1;
    return mult(n,fact(n - 1));
}

ll nCr(ll n, ll r, ll m)
{
    if (r == 0)
        return 1;
    return (fact(n) * modInv(fact(r), mod) % m * modInv(fact(n - r), m) % m) % m;
}

double distance(int x1, int y1, int x2, int y2)
{
    double result = sqrtl(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return result;
}

void printBinary(int num){
    for (int i = 31; i>=0; --i)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
bool isint(double x){
    if(ceil(x)==floor(x)) return true;
    return false;

}
int toggle(int num)
{   
    int n = 31;
    int mask = pow(2, n) - 1;
    return num ^ mask;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0; i<n ; i++){
            cin>>v[i];
        }
        if(n==2){
            cout<<min(v[0],v[1])<<endl;
            continue;
        }
        ll ans=0;
        for(int i=0;i<n-2;i++){
            ll a = v[i];
            ll b = v[i+1];
            ll c = v[i+2];
            ll x[3];
            x[0]=a;
            x[1]=b;
            x[2]=c;
            sort(x,x+3);
            ans=max(ans,x[1]);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}  