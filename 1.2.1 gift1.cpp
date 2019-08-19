/*
ID: taurusd1
TASK: gift1
LANG: C++14
*/

#include <bits/stdc++.h>
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
        os << " " << *ii;
    }
    os << "]";
    return os;
}

struct person
{
    string name;
    ll M, NG;
public:
    person(): name("NA"), M(-1), NG(-1) {}
    person(string _name, ll _M, ll _NG) : name(_name), M(_M), NG(_NG) { }
    person& operator = (const person& p) ;
    //ostream& operator<< ( ostream& os) ; if you declare her will have to do (obj<< cout) which is non intuitive

};

person& person::operator= (const person& p)
{
    if(this == &p ) return *this;
    this->name=p.name;
    this->M=p.M;
    this->NG=p.NG;
    return *this;
}

ostream& operator<< ( ostream& os, const person& p) // if i do (person:: operator<<) then this will automatically be appended as a third argument and hence will have to remove person& p
{
    os << "( "<<(p.name)<<", "<<(p.M )<<", "<< (p.NG)<<" ) ";
    return os;
}

int main ( )
{
	freopen("gift1.in","r",stdin);//redirects standard input
	freopen("gift1.out","w",stdout);//redirects standard output

	ll NP;
	cin>>NP;
	person tmp, tmp1;
	tmp1=tmp;
	//debug("", tmp)
	vector<person> p(NP, tmp);
	vll pM1(NP,0);
	map<string, ll > personmindex;
	rep(i,0,NP)
	{
	    cin>>p[i].name;
	    personmindex[ p[i].name]=i;
	}
	//debug("", p)
	//debug("", pM1)
	//debug("", personmindex)
	string s;
	rep(i,0,NP)
    {
         //debug("", i)
         cin>>s;
         ll indx=personmindex[s];
         cin>>p[indx].M>>p[indx].NG;
         ll NG=p[indx].NG, M=p[indx].M;
         if(NG==0) continue;
         //debug("\t", s)
         ll MG=M/NG;// assume NG>0
         pM1[indx]+=M%NG;
         //debug2("\t",MG, pM1[indx] )
         rep(i,0,NG)
         {
             cin>>s;
             indx=personmindex[s];
             //debug("\t\t|",s)
             pM1[indx] +=MG;
         }
    }
    //debug2("", p, pM1)
    rep(i,0,NP)
    {
        cout << ((i==0)?(""):("\n")) << p[i].name << " " << (pM1[i]- p[i].M);
    }
    cout<<"\n";

}

