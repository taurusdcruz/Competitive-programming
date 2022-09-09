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
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<(w)<<" "<< (x) << " " << (y) << " " << (z);

const LD EPS=1e-12;
const LD INF=1e100;

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}
/*
// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]\n";
    return os;
}
*/
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

//class holding state with state variables (the type of ally state variable is assumed to same of type T) stored in a vector
template <class T>
class state
{
public:
    state(int size): s(size, 0) {}// size is the number of state variables in current state

    vector< T > s;

     friend ostream& operator<<( ostream& os , state<T> &st)
    {
        os<<s;
        return os;

    }
    friend ostream& operator<<( ostream& os , vector<T> &v)
    {
        os << "[";
        for (auto ii = v.begin(); ii != v.end(); ++ii)
        {
            os <<( (distance(v.begin(),ii )>0)?(", "):("") )<< *ii;
        }
        os << "]\n";
        return os;
    }

};

int main()
{
    state<ll> curr_state(5);
    vector< state<ll> > st;

    rep(i,0,2)
    rep(j,0,2)
    rep(k,0,2)
    rep(l,0,2)
    rep(m,0,2)
    {
        ll a[]={i,j,k,l,m};
        //assigning from an array which destroys the vector and constructs a new vector with same size size of array.
        curr_state.s.assign( a, a + sizeof(a)/sizeof(a[0]) );
        //cout<<"\ncurr_state.s.size()"<<curr_state.s.size();
        st.pb(curr_state);

    }

    //printing the states for purpose of debugging
    prall("state", st);

    return 0;
}
