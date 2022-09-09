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
  out<<"( "<<a.first<<", "<<a.second<<") \n";
  return out;
}


//Overriding << operator for tuple
template< class... T >
ostream&  operator<<(ostream& os,const tuple<T...> & tpl)
{
    const ll tpl_sz= tuple_size<tuple<T...> >::value;
    function< ostream (ostream&, const tuple<T...>&, const ll) > print_tuple;
    print_tuple= [=](ostream& os, const tuple<T...> & tpl, const ll Pos )-> ostream
    {
      os <<  get< tpl_sz -Pos >(tpl) << ',';
      if(Pos>1) {return print_tuple(os, tpl, Pos-1); } else{ return os << get<tpl_sz-1>(tpl); }
    };
    os<<")";
    return os;
}


//Overriding << operator for vector of tuple
template< class... T >
ostream&  operator<<(ostream& os,const vector<tuple<T...> >& v)
{
  os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os <<( (ii == v.begin())?(""):(", ") );
        os<< *ii;
    }
    os << "]\n";
  return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << "\n" << *ii;
    }
    os << "]\n";
    return os;
}

// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

//class holding state
template <class T>
class state
{
public:
    state(int size): s(size, 0) {}

    vll s;

     friend ostream& operator<<( ostream& os , state<T> &st)
    {
        os<<st.s;
        return os;
    }
};


int main()
{
    freopen("in.txt","r",stdin);//redirects standard input

    ll n,s;
    ll h, m;
    ll d=0;
    vector< tuple<ll,ll,ll> > sh;

    cin>>n>>s;


    tuple<ll,ll,ll> tmp(d,n,s);
    sh.pb(tmp);


    rep(i,1,n)
    {
        cin>>h>>s;
        tmp=tuple<ll,ll,ll>(d,n,s);
        if(tmp < sh[i-1]) get<0>(tmp)+=1;

        sh.pb(tmp);


    }

    _(sh)

    return 0;

}
