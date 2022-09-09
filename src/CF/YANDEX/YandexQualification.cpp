
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
//const LD EPS=1e-12;
//const LD INF=1e100;
const ll MN =-1000000000 -1;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
struct stck
{
    ll indx;
    ll len;

    stck(): indx{-1}, len{-1} { }
    bool operator<(const stck& rhs)
    {
        if(len< rhs.len) return true;
        return false;
    }


};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

template <class T>
ll gcd(T a1, T b1) {

	T a=abs(a1), b=abs(b1);
	return b == 0 ? a : gcd(b, fmod(a, b));
}

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll n, q;
    ll a, b;
    cin>>n>>q;
    stck s;
    s.indx=-1, s.len=-1;
    vector<stck> l(n+1, s);

    rep(i,1,n+1)
    {
        cin>>l[i].len;
        l[i].indx=i;
    }
    sort(l.begin(),l.end());
    ll intrvllen;
    bool flg;
    rep(i,0,q)
    {
        cin>>a>>b;
        intrvllen=b-a+1;
        flg=false;
        rep(i,a, b+1 -2)
        rep(j, i+1, b+1-1)
        rep(k,i+2, b+1)
        {
            if( l[i].len + l[j]. len > l[k].len) {cout<<"\n"<<l[i].indx<<" "<<l[j].indx <<" "<<l[k].indx; flg=true;break;}
        }

        if(!flg) cout<<"\n"<<-1;

    }


	return 0 ;
}

