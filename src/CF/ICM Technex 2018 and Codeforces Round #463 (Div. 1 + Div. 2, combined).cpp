
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
const LD EPS=1e-12;
const LD INF=1e100;





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

template <class T>
ll gcd(T a1, T b1) {

	T a=abs(a1), b=abs(b1);
	return b == 0 ? a : gcd(b, fmod(a, b));
}
ll xDig(ll n)
{
    ll prod=1;
    while(1)
    {
        prod*= (n%10 !=0)?(n%10):1;
        n/=10;
        if(n==0) break;
    }
    return prod;
}

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll Q, l, r, k;
    cin>>Q;


    rep(i,0,Q)
    {
        cin>>l>>r>>k;
        ll cnt=0;
        //cout<<"\n   l,r,k   "<<l<<", "<<r<<", "<<k;//debug

        rep(i,l,r+1)
        {
            //cout<<"\n   no:"<<i;//debug
            ll c=i;
            while(1)
            {
                c=xDig(c);
                //cout<<"\n   c"<<c;//debug
                if(c <10)break;
            }
            if(c==k)cnt+=1;

        }
        cout<<"\n"<<cnt;

    }



	return 0 ;
}

