/*
ID: taurusd1
TASK: crypt1
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

// Overloading << operator for vectors
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
	freopen("crypt1.in","r",stdin);//redirects standard input
    freopen("crypt1.out","w",stdout);//redirects standard output
    ll N;
    cin>>N;
    //vector< vvll >  d1{ {{},{},{} }, {{},{}} }, d2{ vvll(3,vll{ }), vvll(2,vll{}) },  d3{ vvll(3,vll(0), vvll(2,vll(0)) };//d1,d2,d3 are equivalent initializations using braced initializer lists
    //vector< vvll >  e1{ {{1,1},{1,1},{1,1} }, {{3,3}} }, e2{vvll(3,vll{1,1} ), vvll(1, vll{3,3} ) }, e3{vvll(3,vll(2,1) ), vvll(1, vll(2,3) ) };//e1,e2,e3 are equivalent too
    vll dv(N);//digit values
    rep(i,0,N) cin>>dv[i];
    sort(all(dv));
    vll dvm0=dv;//dv minus 0, used for the most significant digit
    if(dvm0[0]==0) dvm0.erase(dvm0.begin());

    vector< vvll >  d{ {dvm0, dv,dv}, {dvm0,dv} };
    ll ans=0;

    vector<bool> is_dig_allowed(10,false);
    rep(i,0,dv.size()){ is_dig_allowed[dv[i] ]=true;}
    auto n2d_valid=
    [=](ll n)
    {
        vll digits;
        while(n>0)
        {
            digits.pb(n%10);
            n/=10;
            if(!is_dig_allowed[digits.back()]) return false;
        }

        reverse(all(digits));
        return true;
    };


    rep(i10,0,dvm0.size())
    {
        rep(i11,0,dv.size())
        {
            rep(i12,0,dv.size())
            {
                ll n1=100*dvm0[i10] +10*dv[i11]+ dv[i12];
                rep(i20,0,dv.size())
                {
                    ll pp1=n1* dvm0[i20];
                    if(pp1>999 ) {i20=dv.size();continue;}
                    if(!n2d_valid(pp1)) continue;

                    rep(i21,0,dv.size())
                    {

                        ll pp2=n1*dv[i21];
                        ll n2=10*dvm0[i20] + dv[i21];
                        ll n1n2=n1*n2;
                        if(n1n2>9999 ) {i20=i21=dv.size(); continue;}
                        if(pp2>999 ){i21=dv.size();continue;}
                        if(!n2d_valid(n1n2)) continue;
                        if(!n2d_valid(pp2)) continue;
                        auto x=pair<pll,ll>(pll(n1,n2),n1*n2);
                        auto xx=pll(n1* dvm0[i20],n1*dv[i21]);
                        //debug2("", x,xx)
                        ans+=1;


                    }
                }
            }
        }
    }
    cout<<ans<<endl;


	return 0;
}
