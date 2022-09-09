
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
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) cout<<"\n"; for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define debug(m,x) cout <<"\n"<<m<< x;
#define debug2(m,x,y) cout <<"\n"<<m<<" "<< x << " " << y;
#define debug3(m,x,y,z) cout <<"\n"<<m<< x << " " << y << " " << z;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions


//Overriding < operator
template< class T, class U >
 bool operator<(const pair<T,U>& a, const pair<T,U>& b)
{
  if (a.first < b.first) return true;
  else if ( (a.first == b.first) && (a.second < b.second) ) return true;
  else return false;
}

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

ll time(ll pilelen,ll k)
{
    return (pilelen/k +((pilelen%k ==0)?0:1) );
}

ll ttime(vector< pair<ll,ll> > &ac, ll bix, ll k)
{
    ll tt=bix;
    rep(i,bix,ac.size())
    {
        tt+= ac[i].second * time(ac[i].first, k);
    }
    return tt;
}

ll ttime(vector< pair<ll,ll> > &ac, ll k)
{
    ll tt=0;
    rep(i,0,ac.size())
    {
        tt+= ac[i].second * time(ac[i].first, k);
    }
    return tt;
}
ll calcbix(vector< pair<ll,ll> > &ac, ll bixl, ll k)
{
    rep(i,bixl,ac.size())
    {
        if(ac[i].first>=k ) {return i;}
    }
}


int main()
{
    freopen("inXXOR.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll N, Q;
    ll L, R;
    ll EM=214748364700000;
    ll XM=2147483647;
    cin>>N>>Q;
    vll a(N+1);
    vll aasm(N+1,0);
    vector<pair<ll,ll> >  p_mx;
    ll sm;
    rep(i,1,N+1)
    {
        cin>>a[i];
        rep(i,0,N+1)
        {

            if(i==0) sm=a[i];
            else sm += a[i] ;
            aasm[i]=sm;
        }
    }


    ll smlr;
    ll mxs;
    ll rs;
    rep(i,0,Q)
    {
        p_mx.resize(0);
        mxs=-1;

        cin>>L>>R;
        smlr=aasm[R]-aasm[L-1];

        rep(i,0,XM+1)
        {
            if(mxs< (smlr^XM)) {mxs=(smlr^i), rs=i;}
        }
        cout<<"\nrs"<<rs;
    }

    return 0;



}
