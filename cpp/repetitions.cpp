#include <bits/stdc++.h>
#include <stack>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set; 
  
#define MOD 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mpii map<int, int>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define lop(i,s,e) for(long long int i=s;i<e;i++)
#define rlop(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back;
ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b;}
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
using namespace std;
bool isPrime(long long n){
    if (n <= 1)
        return false;
 
    for (long long i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
bool prime[10000001];
  
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int smallestDivisor(int n)
{
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
    return n;
}
long long binpow(long long n, long long k, long long mod = MOD){ 
    // n^k % mod
    long long res = 1;
    while (k > 0){
        if (k & 1) res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}
int power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int lcs(string s, string t)
{     vector<vi> dp(s.length(),vi (t.length(),-1));
	dp[0][0]=s[0]==t[0];
	for(int i=1;i<s.length();i++){
				int k=s[i]==t[0];
		dp[i][0]=max(dp[i-1][0],k);
	}
		for(int j=1;j<t.length();j++){
			int k=s[0]==t[j];
			dp[0][j]=max(dp[0][j-1],k);
		}
	for(int i=1;i<s.length();i++){
		for(int j=1;j<t.length();j++){
			
			if(s[i]==t[j])dp[i][j]=1+dp[i-1][j-1];
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}

		}
	}
	return dp[s.length()-1][t.length()-1];
	//Write your code here
}
vector<ll> fact, ifact;

void init_factorials(ll MaxA=1e5+5){
    fact.resize(MaxA + 1);
    ifact.resize(MaxA + 1);

    fact[0] = 1;
    for (int i = 1; i <= MaxA; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[MaxA] = binpow(fact[MaxA], MOD - 2);
    for (int i = MaxA - 1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}

ll ncr(ll n, ll k){
    if (k < 0 || n < k) return 0;
    return fact[n] * (ifact[k] * ifact[n - k] % MOD) % MOD;
}
long long solve(string s,int i,int k,long long sum,vector<vector<int>>& dp){
    if(i==0){
      //  cout<<((s[0]-'0')*binpow(10,k,MOD))%MOD<<":"<<i<<" ";
        return (((s[0]-'0')*binpow(10,k,MOD))%MOD+sum)%MOD;
        
    }
    if(dp[i][k]!=-1)return dp[i][k];
    int con=((s[i]-'0')*binpow(10,k,MOD))%MOD;
    sum+=con;
    sum%=MOD;
   // cout<<con<<":"<<k<<" ";
    return dp[i][k]=((solve(s,i-1,0,sum,dp))%MOD+solve(s,i-1,k+1,sum,dp))%MOD;
}
long long fun(string s){
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(s,n-1,0,0,dp)%MOD;
}
unsigned int getFirstSetBitPos(int n)
    {
        return log2(n & -n) + 1;
    }
    int drow[]={0,1,0,-1};
    int dcol[]={1,0,-1,0};
int bfs(int i,int j,vector<vector<int>>& a,vector<vector<int>>& vis,int n,int m){
    vis[i][j]=1;
    int sum=0;
    for(int k=0;k<4;k++){
        if(i+drow[k]>=0&&j+dcol[k]>=0&&i+drow[k]<a.size()&&j+dcol[k]<a[0].size()&&vis[i+drow[k]][j+dcol[k]]==0&&a[i+drow[k]][j+dcol[k]]>0)
        sum+=bfs(i+drow[k],j+dcol[k],a,vis,n,m);
    }
    return a[i][j]+sum;
}
long long combin(long long n){
    long long ans=n*(n+1)/2;
    return ans;
}

int main()
{
    int t=1;//cin>>t;
    SieveOfEratosthenes(1e7+1);
	init_factorials(1e5+5);
	while(t--){
    string s;cin>>s;
    int n=s.length();
    int maxi=0,cnt=1;
    lop(i,1,n){
        if(s[i]==s[i-1])cnt++;
        else cnt=1;
        maxi=max(cnt,maxi);
    }
    maxi=max(maxi,cnt);
    cout<<maxi<<endl;
    
	}
	    
	return 0;
}