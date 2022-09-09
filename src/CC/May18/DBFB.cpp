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

const ll mod = (ll) (1e9 + 7);
#define sz(a) int((a).size())
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;



vll r;
const ll C=(ll) (5e5 +10000) ;
void precomp()
{
    r.pb(1); r.pb(1);
    rep(i, r.size(), C )
    {
        ll c=(r[i-1] + r[i-2]) % mod;
        r.pb(c);
    }
}
int main()
{
    freopen("inDBFB.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    precomp();
   // prrange("",r,0,50)
    ll T, M, N;
    cin>>T;

    rep(t,0,T)
    {
        cin>>M>>N;

        vll A(M), B(M);

        ll rSA=0, rSB=0;
        rep(i,0,M) {cin>>A[i];rSA= (rSA+ A[i])%mod; }
        rep(i,0,M) {cin>>B[i];rSB= (rSB+ B[i])%mod; }
        /*
        vll g;
        ll a=A[1], b=B[1];
        g.pb(-1), g.pb(a), g.pb(b);
        rep(i,3,50)
        {
            ll c=r[i-2]*a + r[i-1]*b;
            g.pb(c);
        }
        prall("",g)
        */

        ll res=0;
        if(N>=3) res= (r[N-3]* rSA)%mod + (r[N-2]*rSB)% mod  ;
        else
        {
            if(N==1) res= rSA;
            else if(N==2) res=rSB;
        }
        res = (res*M) % mod;
        cout<<((t==0)?(""):("\n"))<<res;
    }


    return 0;
}
