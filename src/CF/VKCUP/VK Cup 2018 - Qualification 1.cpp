
#include <bits/stdc++.h>
using namespace std;
//#include <bigInt.h>

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector< vll > vvll;



template<class T> T abs(T x) { return x > 0 ? x : -x;}

const ll mod = 1000000000 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define MD(i) ((i) -(long long)(i))




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

ll inbnds(const ll &indx, ll lb,ll ub)// correcting index to be in bounds
{
    return (indx<lb)? lb:(indx>ub)?ub:indx;
}
void solve(const ll &n, const ll &k,ll t,const vll &lnk, vll &dp)
{
    if(lnk[t]>0)
    {

        ll ov=0;
        if(lnk[t]+k >= t-k)
        {
            ov=(lnk[t]+k)-(t-k) +1;
        }
        dp[t]=dp[lnk[t]] + (lnk[t]+k -inbnds(lnk[t]+k,1,n))+k -ov +1+(inbnds(t+k, t, n)-t) ;


    }
    else
    {
        dp[t]= (-inbnds(-k+t,1,n)+t)+1+(-t+inbnds(t+k,1,n));
    }
}







int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll n, k;
    cin>>n>>k;

    vll lnk(n+1,-1);
    rep(i,1,n+1) cin>>lnk[i];

    vll dp(n+1,0);
    dp[1]=inbnds(1+k,1,n);
    rep(t,2,n+1)
    solve(n,k,t,lnk,dp);

    tr(dp,i)(i==dp.begin())?cout<<"\n":cout<<*i<<" ";



	return 0 ;
}

