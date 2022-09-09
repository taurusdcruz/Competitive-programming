/*
ID: taurusd1
TASK: MAGICHF2
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

/**MAGICHF2**/
/*The last time in Byteland, Chef defeated the magician in his challenge and won a gold coin.

The magician does not want to give up his coin so easily, so he gives Chef N coins. One of them is real and the remaining N−1 are fake; all fake coins have equal weights, different from the weight of the real coin. The coins are otherwise indistinguishable.

Chef has to find the real coin by himself. To make it fair, the magician gives Chef a balance. The balance is magical — it stays balanced when the sums of weights of coins put on each side are equal, but if they are not equal, the balance tilts to a random side instead of the side with the greater sum of weights. Chef can only use this balance up to K times; if he cannot uniquely determine which coin is the real one afterwards, he has to guess the real coin (he may make a guess in any way he wants).

If Chef uses the balance optimally, what is the minimum possible probability that he will correctly determine the real coin at the end? We are interested in the worst-case scenario where the position of the gold coin is fixed initially (but unknown to Chef).

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers N and K.
Output
For each test case, print a single line containing one integer — the minimum probability that Chef will find the gold coin. Your output will be considered correct if its absolute error does not exceed 10−6.

Constraints
1≤T≤2⋅105
1≤N≤1018
0≤K≤109
Subtasks
Subtask #1 (25 points): 1≤N≤105
Subtask #2 (75 points): original constraints

Example Input
4
3 1
3 2
4 1
1 5
Example Output
0.500000
1.000000
0.500000
1.000000
/**/

/**/


//class MAGICHF2
//About members of the class:
/*
Member variables:
ll N,K----------------------------------------------------------->As Defined in

Member functions:

MAGICHF2()------------------------->Constructor
void solve()-------------------> Self Explanatory

*/

class MAGICHF2
{
//By default data members are private
//
LD N, K,p;

public:
MAGICHF2()
    :N()
    ,K()
    {

    };
MAGICHF2(ll _N, ll _K)
    :N(_N)
    ,K(_K)
    {

    };
    void test()
    {
        for(LD N_=1.0l;N_<100.0l;++N_)
        {
            for(LD K_=0.0l;K_<= 2.0l * ( log(N_)/log(3.0l) );++K_)
            {
                MAGICHF2::N=N_;
                MAGICHF2::K=K_;

                solve();
                //debug3("",N,K,p)
            }
        }
        return;
    }
    /**/
    void solve()
    {
        /**
        APPROACH:
        /**/
        /**/

        if(N==1.0l)
        {
            p=1.0l;
        }
        else if(N==2.0l)
        {
            if(K>=1.0l)
                p=1.0l;
            else p=0.5l;
        }
        else if(N>=3.0l)
        {
            LD K_MX=0.0l;
            LD N1=N, K1=K;
            K_MX= 0.0l;
            LD last_remaining=N1;//coins remaining at the end in the worst case
            LD c;

            for(
                ;last_remaining>=3.0l && K1>=1.0l
                ; K_MX+=1.0l, K1+=-1.0l
                )
            {
                LD _2x=2.0l *floor(last_remaining/3.0l);
                last_remaining=max(_2x, last_remaining - _2x );
            }
            if(K1>0.0l)
            {
                if(last_remaining==1.0l)
                {
                    /*Do nothing*/
                }
                else if(last_remaining==2.0l)
                {
                    last_remaining=1.0l;
                    K_MX+=1.0l;
                    K1+=-1.0l;
                }
                else if(last_remaining>=3.0l)
                {
                    /*K1 has to be <=1.0l as if K1 would be 2.0l the we would perform K1+=-2.0l as last_remaining >=3.0l*/
                    /*Hence K1 in range:[0.0l,1.0l]*/
                    if(K1==1.0l)
                    {
                        LD _2x=2.0l *floor(last_remaining/3.0l);
                        last_remaining=max(_2x, last_remaining - _2x );
                        K_MX+=1.0l;
                        K1+=-1.0l;
                    }
                }
            }
            p=1.0l/last_remaining;

            //debug("",last_remaining)
            /**/
        }
        cout<<setprecision(15)<<p<<endl;
        return;
    }
    /**/

};

int main ( )
{
    /**/
    freopen("inMAGICHF2.txt","r",stdin);//redirects standard input
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object

    /**
    MAGICHF2().test();
    /**/
    ll T;cin>>T;
    rep(t,0,T)
    {
        ll N,K;cin>>N>>K;
        MAGICHF2(N,K).solve();
    }
	return 0;
}

