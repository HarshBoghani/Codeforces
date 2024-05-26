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
// #define mod LONG_LONG_MAX
#define M 1000000007
#define pb push_back
#define ff first
#define ss second
#define yes cout<<"Yes"<<endl
#define no cout<<"NO"<<endl

void printmap(map<ll,ll>& m){for(auto it : m){cout<<it.ff<<" "<<it.ss<<endl;}cout<<endl;}
void printset(set<ll>& st){for(auto it : st){cout<<it<<" ";}cout<<endl;}
void printmat(vector<vector<ll>>& dp){for(int i=0;i<dp.size();i++){for(int j=0;j<dp[0].size();j++){cout<<dp[i][j]<<" ";}cout<<endl;}cout<<endl;}

ll mult(ll a, ll b, ll mod) { return ((a % mod) * (b % mod)) % mod; }


const int N = 1e5 + 10;
vector<bool> isPrime(N,1);
vector<int> lp(N,0) , hp(N,0);





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2 ; i < N ; i++){
        if(isPrime[i]==true){
            lp[i]=hp[i]=i;
            for(int j = 2*i ; j<N ; j+=i){
                isPrime[j] = false;
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0; i<n ; i++){
            cin>>v[i];
        }
        map<ll,map<ll,ll>> m;
        for(int i=0;i<n;i++){
            ll num=v[i];
            if(m.find(v[i])!=m.end()) continue;
            while(num>1){
                int prime_factor = hp[num];
                while(num % prime_factor==0){
                    num/=prime_factor;
                    m[v[i]][prime_factor]++;
                }
            }
        }
        ll ans=1;
        for(int k=1;k<=200001;k++){
            if(isPrime[k]){
                multiset<ll> freq;
                int flag=0;
                for(int i=0;i<n;i++){
                    if(m[v[i]].find(k) == m[v[i]].end()){
                        flag=1;
                        break;
                    }
                    else freq.insert(m[v[i]][k]);
                }
                if(flag==1) continue;
                else{
                    auto it = freq.begin();
                    it++;
                    //cout<<*it<<" "<<k<<endl;
                    ans*=pow(k,*it);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  