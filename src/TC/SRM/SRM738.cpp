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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions


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
void indent(ll indent_variable)
{
    cout<<"\n";rep(i,0,indent_variable)cout<<"\t";
}
class DriveTheCarEasy
{
public:
 long long calculateDistance(int S, int N, vector <int> speed_changes, vector <int> moments)
{
    ll curr_speed=0, distance=0;
    vector< pair<ll,ll> > sm_;
    rep(i,0,N)
    {
        sm.push_back(pll(speed_changes[i],moments[i]));
    }
    sort(all(sm),[](pll l, pll r){ if(l.second<r.second) return true; else if(l.second== r.second && l.first< r.first) return true; return false; });
    map<ll,ll> ms;
    rep(i,0,N)
    {
        if(i!=0)
        {

            if(i+1!=N)
                while(sm_[i+1].second==sm_[i].second)
            {
                ms[sm_[i+1].second]+=sm_[i+1].first;
                if(i++>=N)break;
            }
        }
    }
    debug("",sm)
    tr(ms,it)
    {
        curr_speed+=(*it).second;
        if(it!=ms.begin())
        {
            distance+=curr_speed*((*it).first- (*prev(it,1)).first);
        }
        if(next(it,1)==ms.end())
        {
            if((*it).second<S)
            {
                distance+=curr_speed*(S-sm[i].second);
            }
        }
    }
    return distance;
}
};

int main ( )
{
	//freopen("in.txt","r",stdin);//redirects standard input
	//freopen("out.txt","w",stdout);//redirects standard output
    DriveTheCarEasy m;
cout<<m.calculateDistance(
100,
10,
vector<int>{522,426,772,447,497,775,982,417,932,728},
vector<int>{75,45,81,29,2,25,84,56,2,37})
<<endl;

	return 0 ;
}

