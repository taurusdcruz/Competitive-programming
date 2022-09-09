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

const ll mod = 1e9 + 7;
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
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}


// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const set<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const map<T, T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int main()
{
    freopen("in.txt","r",stdin);//redirects standard input
    ll n,m;cin>>n>>m;
    vector< vector< bool> > inked(n, vector<bool>(m,false)), t_inked(n, vector<bool>(m,false));
    vector< vector< bool> > pen_impression={ vector<bool>{1,1,1},vector<bool>{1,0,1},vector<bool>{1,1,1} };
    char c;
    ll no_not_inked=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>c;
            if(c=='#') inked[i][j]=1;
            if(c=='#') no_not_inked+=1;
        }
    }
    //debug("",inked)
    auto can_press_here=[=, &no_not_inked, &t_inked](ll i, ll j)
    {
        bool flg =true;
        rep(ki,i-1,i+2)
        {
            rep(kj,j-1,j+2)
            {
                if(ki==i && kj==j) continue;
                if(!inked[ki][kj]) flg=false;
            }
        }
        if(flg )
        rep(ki,i-1,i+2)
        {
            rep(kj,j-1,j+2)
            {
                if(ki==i && kj==j) continue;
                if( (!t_inked[ki][kj]) && inked[ki][kj]) { t_inked[ki][kj]=1;--no_not_inked; /*debug("", no_not_inked)*/}
            }
        }
        //debug3("",i,j,flg)
        //debug("", t_inked)
    };
    rep(i,1,n-1)
    {
        rep(j,1,m-1)
        {
            can_press_here(i,j);
        }
    }
    //debug("",no_not_inked)
    cout<<((no_not_inked>0)?("NO"):("YES"))<<endl;


    return 0;
}
