
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
void indent(ll indent_variable)
{
    cout<<"\n";rep(i,0,indent_variable)cout<<"\t";
}
void f(vll A, ll& Z1, ll& Z2,ll& res,ll S, bool& is_2)
{
    //debug("",S)
    bool is_2_=false;
    rep(i,0,A.size())
    {
        ll Sp,Sm;
        Sp=S+A[i];
        Sm=S-A[i];
        bool fp=(Sp==Z1 || Sp==Z2);
        bool fm=(Sm==Z1 || Sm==Z2);
        if( (fp || fm)  ) {is_2_=true;}
        //indent(1);cout<<pll(Sm,Sp)<<pll(Z1,Z2)<<pll(fp,fm)<<is_2;
        if(!is_2) return;// break out of all recursions

    }
    is_2=is_2_;
    return;
}

int main()
{
    freopen("in.txt","r",stdin);//redirects standard input
    ll T,N,Z1,Z2;
    cin>>T;
    rep(t,0,T)
    {
        cin>>N>>Z1>>Z2;
        //debug("",t)
        ll S=0;
        ll Z1_=abs(Z1), Z2_=abs(Z2);
        ll res=0;

        set<ll> sA;
        ll c;
        rep(i,0,N){cin>>c; sA.insert(abs(c));};
        vll A(all(sA));

        //debug("",A)

        ll turn=1;
        ll d=1;

        rep(i,0,A.size())
        {
            if(A[i]==abs(Z1)|| A[i]==abs(Z2)) res=1;
        }


        if(res!=1)
        {
            bool is_2=true;
            rep(i,0,A.size())
            {
                ll Sp,Sm;
                Sp=S+A[i];
                Sm=S-A[i];
                f(A,Z1,Z2,res,Sp,is_2);
                f(A,Z1,Z2,res,Sm,is_2);
            }
            if(is_2) res=2;
        }
        cout<<res<<endl;
    }

    return 0;
}
