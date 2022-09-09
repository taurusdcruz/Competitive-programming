/*
ID: taurusd1
TASK: GMEDIAN
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
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
#define some(c,l,r) next((c).begin(),l),next((c).begin(),r-1) //Range:[l.r)
#define rall(c) (c).rbegin(),(c).rend()
#define rsome(c,l,r) next((c).rbegin(),l),next((c).rbegin(),r-1) //Range:[l.r)
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)//Range:[l.r)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}//Range:[l/r)
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

// Overloading << operator for deque
template < class T >
ostream& operator << (ostream& os, const deque<T>& v)
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
        os << ((ii != v.begin() )?("") :(",") )<< *ii;
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

/**GMEDIAN**/
/*Raja only participates in contests and does not upsolve, but he claims that he has been upsolving.
Chef wants to test if he is really improving, so he asks Raja to solve the following problem.

The median of a sequence of numbers is computed in the following way:

sort the sequence in non-decreasing order
if the number of elements of this sequence is odd, the median is its middle element
if the number of elements is even, the median is the average (arithmetic mean) of its two middle elements
For example, the median of [1,3,2] is 2 and the median of [2,3,3,2] is (2+3)/2=5/2.

You are given a sequence A1,A2,…,AN.
Let's call a subsequence Ai1,Ai2,…,Aik (for any k>0, 1≤i1<i2<…<ik≤N) good if
    the median of this subsequence is an element of this subsequence.
Find the number of good subsequences.
Since this number may be large, compute it modulo 1000000007 (109+7).

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer — the number of good subsequences modulo 109+7.

Constraints
1≤T≤30
1≤N≤1,000
1≤Ai≤2N for each valid i
/**/

/**/


//class GMEDIAN
//About members of the class:
/*
Member variables:
ll N,M----------------------------------------------------------->As Defined in
vector<pll > drow_dcol------------------------------------->drow_dcol(change row and col) when moving in direction indexed 0,1,2,3
                                                                                with mappings 0->S, 1->E, 2->N, 3->W
ll largest_component--------------------------------------->size of the largest component
ll combined_adj_components_max-------------------->The size of the largest room creatable by removing one wall
pair< pair<ll,ll>, char> wall_2_remove---------------->The single wall to remove to make the largest room possible
vector<vector< node> > grid----------------------------->2D Grid of nodes where each node(representing each squared module of the castle)
                                                                                stores information about the module/cell of the MAGICHF2
vector< vector<
reference_wrapper<node>
> > components---------------------------------------------->components[ _ith_component_ ] Stores a vector of references to node ,node&(using reference_wrapper<node>)
                                                                                which belong to the _ith_component_

Member functions:

GMEDIAN()------------------------->Constructor
node& get_grid(pll)------------------->access grid[row][col] using get_grid(pll(row,col) )
void assign_components()-------->Traverse grid in BFS manner and assign for each cell/node/module of the MAGICHF2 its component
void solve()-------------------> Self Explanatory

*/

class GMEDIAN
{
//By default data members are private
//
ll N;
vll vA;
ll mx=2000+10;
vector< vll > vvA;
ll cnt_good_seq=0;//store the no. of good sub-sequences possible in vA

public:
GMEDIAN()
    :N()
    ,vA()
    ,vvA()
    {
        cin>>N;
        vA.resize(N);
        vvA.resize(mx);
        rep(i,0,N)
        {
            cin>>vA[i];
        }
        sort(all(vA));
        rep(i,0,N)
        {
            vvA[vA[i] ].push_back(i);
        }
        /**
        debug("",vA)
        /**/
    };
GMEDIAN(ll TEST)
    :N()
    ,vA()
    ,vvA()
    {

    };

    ll powmod(ll a, ll x, ll p=1e9+7) {
        // return a^x % p
        ll res = 1;
        while(x>0)
        {
            if(x & 1) res = (res*a) % p;
            a=(a*a)%p;
            x >>= 1;
        }
        return res;
    }

    ll modinv(ll a, ll p=1e9+7)
    {
    // return modular multiplicative of a % p(if p is prime)
    return powmod(a, p-2, p);
    }

    /* n CHOOSE r*/
    ll CHOOSEmod(ll n, ll r, ll p=1e9+7)
    {
        // return C(n,k) % p(if p is prime)
        ll num,den;
        num=den=1;
        for(ll i=n;i>=n-r+1;--i)//n*(n-1)* ... * (n-r+1)
        {
            num=(num*i)%p;
        }
        for(ll i=r;i>=1;--i)//r!
        {
            den=(den*i)%p;
        }
        ll res= (num* modinv(den,p) )%p;
        return res;
    }
    void test()
    {
        rep(n,0,100)
        {
            ll tmp=0;
            rep(k,0,n+1)
            {

            }
        }
        return;
    }
    ll pow2(ll n)
    {
        return powmod(2,n);
    }

    /**/
    void solve()
    {
        /**
        APPROACH:
        /**/

        //Calc alternae terms nc1 + nc3 + nc5 ... or nc0 + nc2 + nc4...
        cnt_good_seq=pow2(N-1);
        //debug("",cnt_good_seq)
        ll nLT=0, nGT=N;
        for(ll i=0;i<vvA.size();++i)
        {
            nGT+=-vvA[i].size();

            if(vvA[i].size()>=2)
            {
                //debug3("",i,nLT,nGT)
                ll ni=vvA[i ].size();
                ll t1=(pow2(ni-2) +pow2(ni-2)-1)%mod;
                ll nbs=min(nLT,nGT);
                ll t2=CHOOSEmod(nLT+nGT, nbs);
                ll t12=(t1*t2)%mod;
                cnt_good_seq+=t12;
                cnt_good_seq%=mod;
                //debug("",(vll{ni,t1,nbs,t2}))
            }
            nLT+=vvA[i].size();
        }
        if(cnt_good_seq<0)
        {
            cnt_good_seq+=mod;
        }
        cout<<cnt_good_seq<<endl;
        return;
    }
    /**/

};

int main ( )
{
    /**/
    freopen("inGMEDIAN.txt","r",stdin);//redirects standard input
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    ll T;cin>>T;
    /**
    GMEDIAN(1).test();
    /**/
    rep(t,0,T)
    {
        GMEDIAN().solve();
    }
    /**/
	return 0;
}

