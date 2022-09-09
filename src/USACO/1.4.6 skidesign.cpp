/*
ID: taurusd1
TASK: skidesign
LANG: C++14
*/

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
	freopen("skidesign.in","r",stdin);//redirects standard input
    freopen("skidesign.out","w",stdout);//redirects standard output

    /**skidesign**/
    /*PROBLEM STATEMENT*
    Farmer John has N hills on his farm (1 <= N <= 1,000), each with an integer elevation in the range 0 .. 100.
    In the winter, since there is abundant snow on these hills, FJ routinely operates a ski training camp.
    Unfortunately, FJ has just found out about a new tax that will be assessed next year on farms used as ski training camps.
    Upon careful reading of the law, however, he discovers that the official definition of a ski camp requires
    the difference between the highest and lowest hill on his property to be strictly larger than 17.
    Therefore, if he shortens his tallest hills and adds mass to increase the height of his shorter hills,
    FJ can avoid paying the tax as long as the new difference between the highest and lowest hill is at most 17.
    If it costs x^2 units of money to change the height of a hill by x units, what is the minimum amount of money FJ will need to pay?
    FJ can change the height of a hill only once, so the total cost for each hill is the square of the difference between its original and final height.
    FJ is only willing to change the height of each hill by an integer amount.
    /**/

    /*
    E_MX--------------> maximum possible elevation of peak
    n-----------------------> no of peaks in FJ's farm
    oe---------------------->original elevations in FJ's farm sorted by height in ascending order
    oe_mn--------------->minimum height among all peaks in  FJ's farm
    oe_mx--------------->maximum height among all peaks in  FJ's farm
    mn_cost------------->Configuration of elevations resulting in minimum cost  to move from the original configuration of heights in FJ's farm
    ne[h_i]--------------->no of peaks with elevation h_i
    lcost[h_i]------------>cost to bring every peak to the left from their original elevation up to a height h_i.In short, new global elevation minimum is h_i.
    rcost[h_i]------------>cost to bring every peak to the right from their original elevation down to a height h_i. In short, new global elevation maximum is h_i.
    /**/
    const ll E_MX=100;
    ll n;cin>>n;
    vll oe(n);
    rep(i,0,n)
    {
        cin>>oe[i];
    }
    sort(all(oe));
    /*DEBUG*
    debug("",oe)
    /**/
    ll oe_mn=oe[0],oe_mx=oe[n-1];
    ll  mn_cost=LLONG_MAX;
    vll ne(E_MX+1,0);
    vll lcost(E_MX+1,0),
    rcost(E_MX+1,0);


    //lambda function to calculate the cost for the change in elevation
    auto calc_cost=
    [=](ll original_elevation, ll new_elevation)
    {
      return  pow( (new_elevation-original_elevation),2);
    };

    //filling ne
    rep(i,0,n)
    {
        ne[oe[i] ]+=1;
    }

    //filling lcost
    rep(mn_elev,oe_mn, oe_mx+1)
    {
        ll cost=0;
        rep(elev,oe_mn,mn_elev+1)
        {
            cost+=ne[elev]*calc_cost(elev,mn_elev);
        }
        lcost[mn_elev]=cost;
    }

    //filling rcost
    rep(mx_elev,oe_mn, oe_mx+1)
    {
        ll cost=0;
        rep(elev,mx_elev,oe_mx+1)
        {
            cost+=ne[elev]*calc_cost(elev,mx_elev);
        }
        rcost[mx_elev]=cost;
    }


    for(ll elev_mn=oe_mn; elev_mn<=oe_mx; elev_mn++)
    {

        ll elev_mx=elev_mn+17;
        if(elev_mx> oe_mx) break;
        //checking mn_cost and cost for maiking global elevation at a minimum of elev_mn and global elevation at a max of elev_mx( i.e. lcost[elev_mn] + rcost[elev_mx] )
        mn_cost=min(mn_cost, lcost[elev_mn] + rcost[elev_mx] );
    }
    /*DEBUG*
    debug("",ne)
    debug("",lcost)
    debug("", rcost)
    debug("", mn_cost)
    /**/

    cout<<mn_cost<<endl;
	return 0;
}
