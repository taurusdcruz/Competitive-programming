
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
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(arr) cout<<"\n";for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define prrange(c,l,r) cout<<"\n";for (auto b = next(c.begin(),l),i=b, e=next(c.begin(),r); i != e; ++i) cout << *i << " ";
#define debug(m,x) cout <<"\n"<<m<< x;
#define debug2(m,x,y) cout <<"\n"<<m<<" "<< x << " " << y;
#define debug3(m,x,y,z) cout <<"\n"<<m<< x << " " << y << " " << z;
const LD EPS=1e-12;
const LD INF=1e100;



template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions


int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll n,m;
    cin>>n>>m;
    /*
    cout<<"\n"<<n<<" "<<m;
    */
    vll a(n), b(m);
    vector< vll > dp(2, vll(m));
    ll c=1000000000;

    rep(i,0,n) {cin>>a[i];}
    rep(j,0,m) {cin>>b[j];}
    dp[0][0]=(c)*a[0] + b[0];
    rep(j,1,m) {dp[0][j]=dp[0][j-1]+(c)*a[0]+b[j];}
    ll ic,il,j;
    rep(i,1,n)
    {
        ic=i%2;
        il=(i+1)%2;
        j=0;
        dp[ic][j]=dp[il][j] +(c)*a[i]+b[j];
        j+=1;
        while(j<m)
        {
            while(dp[il][j]>dp[ic][j-1] && j<m)
            {
                dp[ic][j]=dp[il][j] +(c)*a[i]+b[j];
                j+=1;
            }
            while(dp[il][j]<=dp[ic][j-1] && j<m)
            {
                dp[ic][j]=dp[ic][j-1] +(c)*a[i]+b[j];
                j+=1;
            }
        }
        /*
        if(i==1) {prall(dp[il]);cout<<"["<<0<<"]";}
        prall(dp[ic]);cout<<"["<<i<<"]";
        */
    }

    cout<<dp[ic][m-1];
}

