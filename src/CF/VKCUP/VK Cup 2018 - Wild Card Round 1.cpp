
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
pll ch(ll n, ll r)
{
    ll resnum=1;
    ll resden=1;
    rep(i,0,r)
    {
        resnum*=n-i;
        resden*=i+1;
    }
    ll g=gcd(resnum,resden);
    resnum/=g;
    resden/=g;
    return pll(resnum,resden);

}

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    LD l,r;
    cin>>l>>r;
    ll n=0;
    LD
    d= r,
    k=1;
    while(d>=k)
    {
        n+=(ll)(log(d/k)/log(2));
        k*=3;
        cout<<"\n"<<d/k<<" "<<n;
    }
    cout<<(ll)n;



    return 0;
}

