
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

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

const ll mod = (ll)(1e9 + 7);
const LD PI =(LD)acos(-1);
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

// Overloading << operator for sets
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

// Overloading << operator for vector<vector>
template < class T >
ostream& operator << (ostream& os, const vector< vector<T> >& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << ((ii != v.begin() )?("\n") :("\n") )<< *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << "\n" << *ii;
    }
    os << "]";
    return os;
}


int main ( )
{
	//freopen("in.txt","r",stdin);//redirects standard input
    //freopen("wormhole.out","w",stdout);//redirects standard output

    /**********************************************
    *ORDER OF EXECUTION IN FOR-LOOP
    **********************************************/
    /*
    Visual Cues:
    ---------------------------------------
    ==>           |PRE/EXECUTING_BLOCK/COND_EXPRESSION/
    -----------------------------------
     |               |PRE/EXECUTING_BLOCK/COND_EXPRESSION/
    V               |
    ------------------------------------
    ===           |
    ===           | EXECUTING_BLOCK/DO_YOUR_THANG !!!
    ---             |
    ...              |
    ------------------------------------
     --->           |
     |__i           |POST/EXECUTING_BLOCK/LOOP_EXPRESSION/

    */
    ll _i1_, _i11_, _N1_, _N11_;
    for
        (
            _i1_=0,_N1_=4,[=](){debug2("-x-x-x-x-x-x-x-\n____==>____LOOP:1____",_i1_,_N1_) }() ;
            _i1_<_N1_+1/*N_ is double digit*/ && [=](){debug2("\n|\nV ",_i1_,_N1_)return true;}();
            ++_i1_,[=](){debug("-x-x-x-x-x-x-x-\n____--->____\n____|__i____ ",_i1_) }()
        )
        {
            [=](){debug("-x-x-x-x-x-x-x-\n____===____\n____===____\n____---____\n____...____ ","")}();//body of loop1
            for
                (
                _i11_=0,_N11_=2,[=](){debug2("\t-x-x-x-x-x-x-x-\n\t____==>____LOOP:11____ ",_i11_,_N11_) }() ;
                _i11_<_N11_+1/*N_ is double digit*/ && [=](){debug2("\t-x-x-x-x-x-x-x-\n\t____|____\n\t____V____ ",_i11_,_N11_)return true;}();
                ++_i11_,[=](){debug("\t-x-x-x-x-x-x-x-\n\t____--->____\n\t____|__i_____ ",_i11_) }()
                )
                {
                    [=](){debug("\t-x-x-x-x-x-x-x-\n\t____===____\n\t____===____\n\t____---____\n\t____...____ ","")}();
                }
            [=](){debug("-x-x-x-x-x-x-x-\n____===____\n____===____\n____---____\n____...____ ","")}();//still body of loop1
        }


    /**/
    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/
	return 0;
}
