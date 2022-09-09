/*
ID: taurusd1
TASK: ariprog
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

//print a set of variables in one line
void pline(string message, ll indent_variable/*variable nof parameters*/)
{

}
void indent(ll indent_variable)
{
    cout<<"\n";rep(i,0,indent_variable)cout<<"\t";
}

int main ( )
{
	freopen("ariprog.in","r",stdin);//redirects standard input
    freopen("ariprog.out","w",stdout);//redirects standard output

    /**skidesign**/
    /*PROBLEM STATEMENT*
    An arithmetic progression is a sequence of the form a, a+b, a+2b, ..., a+nb where n=0, 1, 2, 3, ... .
    For this problem, a is a non-negative integer and b is a positive integer.
    Write a program that finds all arithmetic progressions of length n in the set S of bisquares.
    The set of bisquares is defined as the set of all integers of the form p2 + q2 (where p and q are non-negative integers).
    /**/

    /*INPUT*

    Line 1:	N (3 <= N <= 25), the length of progressions for which to search
    Line 2:	M (1 <= M <= 250), an upper bound to limit the search to the bisquares with 0 <= p,q <= M
    /**/

    /*ABOUT VARIABLES USED*
    N,M----------------------------->As defined  in "INPUT"
    sbisq--------------------------->set of bisquares( p*p+q*q, where 0<=p,q <= M )
    vbisq--------------------------->vector of all bisquares(subject to the above mentioned constraints) which are sorted in ascending order
    is_bisq------------------------->map that maps integers belonging to sbisq/vbisq to boolean value true
    a--------------------------------->first element of the arithmetic progression
    b--------------------------------->common difference of the arithmetic progression
    ab------------------------------->set of pairs(a,b), each pair representing an arithmetic progression of length N

    /**/

    const ll M_MX=250;
    const ll bisq_MX=M_MX*M_MX*2;
    ll N, M;

    cin>>N>>M;
    set<ll> sbisq;
    vector<bool> is_bisq(bisq_MX+1,false);
    //debug("",is_bisq.max_size()> M_MX*M_MX*2+1)//Checking if is_bisq can contain M_MX*M_MX+1 elements
    rep(p,0,M+1)
    {
        rep(q,0,M+1)
        {
            sbisq.insert(p*p + q*q);
            is_bisq[p*p+q*q]=true;
        }
    }

    vector<ll> vbisq(all(sbisq));// vector of bisquares which are sorted in ascending order

    //Store result containing pairs(a,b) which have length N
    auto comp1=[]( const pll l, const pll r){ if(l.second!=r.second) return l.second<r.second; else return l.first<r.first; };// lambda function to compare pairs based on their second element
    //  For set container, the second template parameter can be used  to pass your own custom compare function for the container
    //               |
    //              V
    set<pll, decltype(comp1) > sab(comp1);//set of pairs(a,b)

    //lambda function to check if a value is within a given range
    auto within_bounds=[](ll val, ll lo, ll hi){ return val>=lo && val <hi ;};
    rep(i,0,vbisq.size())
    {
        rep(j,i+1,vbisq.size())
        {
            ll a=vbisq[i];
            ll b=vbisq[j]-vbisq[i];
            // checking if all the elements of the arithmetic progression (represented by (a,b) )are present in vbisq
            rep(i,0,N)
            {
                if(!within_bounds(a+ (N-1-i)*b,0,2*M*M+1) ) break;//checking if the element is within bounds other wise we will be accessing vector is_bisq out of bounds
                if(!is_bisq[a+ (N-1-i)*b] ) break;

                if(i+1==N)//just before exiting the current loop in present scope
                {
                    ll j=0;
                    while(is_bisq[a+ (i+j)*b] )
                    {
                        if(!within_bounds(a+ (i+j)*b,0,2*M*M+1)) break;//checking if the element is within bounds other wise we will be accessing vector is_bisq out of bounds
                        sab.insert(pair<ll,ll>(a+ j*b,b));
                        //indent(1); cout<<a+j*b<<"inserted"<<pll(a+ j*b,b)<<"inserted";
                        j+=1;
                    }
                }
            }
        }
    }
    tr(sab,it)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    if(sab.size()==0) cout<<"NONE"<<endl;


	return 0;
}
