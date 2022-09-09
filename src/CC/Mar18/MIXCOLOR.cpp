
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;

template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

template< class T, class U >
 pair<T,U> operator/( pair<T,U>& a, const pair<T,U>& b)
{
    a.first/=b.first;
    a.second/=b.second;
    return a;
}


template< class T, class U >
 pair<T,U> operator*(pair<T,U>& a, const pair<T,U>& b)
{
    a.first*=b.first;
    a.second*=b.second;
    return a;
}

template< class T >
ll gcdp(pair<T,T> &a)
{
   return  __gcd((ll)(a.first) ,(ll)(a.second));
}

template< class T, class U >
 pair<T,U> operator+(const pair<T,U>& a, const pair<T,U>& b)
{
    pll res(a.first*b.second + b.first*a.second, a.second* b.second);
    ll gc= gcdp<ll>(res);
    return res/pll(gc,gc);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

int main()
{
    freopen("inMIXCOLOR.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T,N;
    cin>>T;
    set< ll > a;
    ll val, cnt;

    rep(i,0,T)
    {
        cin>>N;
        a.clear();
        rep(i,0,N)
        {
            cin>>val;
            a.insert(val);
        }

        cout<<"\n"<< N- (ll)a.size() ;

    }

    return 0;



}
