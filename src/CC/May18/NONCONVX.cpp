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
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;

const LD EPS=1e-12;
const LD INF=1e100;

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") \n";
  return out;
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

vll rem_mod_upto_2e60;
void precomp()
{
    ll N_MX=(ll) 1e18;
    ll c= floor(log2(N_MX));
    rem_mod_upto_2e60.resize(c);
    rem_mod_upto_2e60[0]=10LL;
    rep(p,1,c+1)
    {
        rem_mod_upto_2e60[p]=(rem_mod_upto_2e60[p-1] * rem_mod_upto_2e60[p-1])% mod;
    }
}
int main()
{
    freopen("inWGHTNUM.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
   ll T;
   cin>>T;
   precomp();
   _(rem_mod_upto_2e60)
   rep(t,0,T)
   {
        //debug("------",t)
        ll N, W;
        cin>>N>>W;
        //debug2("",N, W)
        ll N1=N-2;
        ll res0=1;
        //_((bitset<60>)N1)
        for(ll p=0;N1 >0LL;N1>>=1LL,p+=1)
        {
            if(N1 & 1LL)
            {
                res0=( res0 * rem_mod_upto_2e60[p]) % mod;
                //debug3("", p, res0, rem_mod_upto_2e60[p]);
                debug("",(bitset<60>)N1)
            }
        }
        ll res1=(W<-9 || W>8 )?(0):((W>=0)?(9- abs(W)):(10-abs(W)));
        ll res= (res0* res1)% mod;
        if(res<0) res+=mod;
        cout<<((t>0)?"\n":"")<<res;
   }
    return 0;
}
