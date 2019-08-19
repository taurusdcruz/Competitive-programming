/*
ID: taurusd1
TASK: money
LANG: C++14
CONCEPTS: 
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

/**Money**
Money Systems
The cows have not only created their own government but they have chosen to create their own money system. In their own rebellious way, they are curious about values of coinage. Traditionally, coins come in values like 1, 5, 10, 20 or 25, 50, and 100 units, sometimes with a 2 unit coin thrown in for good measure.

The cows want to know how many different ways it is possible to dispense a certain amount of money using various coin systems. For instance, using a system of {1, 2, 5, 10, ...} it is possible to create 18 units several different ways, including: 18x1, 9x2, 8x2+2x1, 3x5+2+1, and many others.

Write a program to compute how many ways to construct a given amount of money using supplied coinage. It is guaranteed that the total will fit into both a signed long long (C/C++) and Int64 (Free Pascal).

PROGRAM NAME: money
INPUT FORMAT
The number of coins in the system is V (1 <= V <= 25).

The amount money to construct is N (1 <= N <= 10,000).
Line 1:	Two integers, V and N
Lines 2..:	V integers that represent the available coins (no particular number of integers per line)
SAMPLE INPUT (file money.in)
3 10
1 2 5
OUTPUT FORMAT
A single line containing the total number of ways to construct N money units using V coins.
SAMPLE OUTPUT (file money.out)
10
/**/

/**/


//class Money
//About members of the class:
/*
Member variables:
task---------------------------------->name of task
V------------------------------------->no of coins in the system
N------------------------------------->amount of money to construct
available_coins----------------------->available coins in the system
res----------------------------------->res[m]number of ways to 
                                        construct m money units using V coins


Member functions:
void Money(ll task)----------------->Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s


*/

class Money
{
//By default data members are private
//
string task;
ll V,N;//no of coins in the system, amount of money to construct
vll available_coins;//available coins in the system
vll res;//number of ways to construct 1..N money units using V coins
public:
    Money(string _task):
        task(_task)
        {
            //Open streams
            open_streams();
            //read input and initialize class member variables
            read();
            //solve
            solve();
            //write output after solving
            write();
            //close streams
            close_streams();
        };
    void open_streams(){
        //open streams
	    freopen((task+".in").c_str(),"r",stdin);//redirects standard input
        freopen((task+".out").c_str(),"w",stdout);//redirects standard output
    }
    void close_streams(){
        //close streams
        fclose(stdin);
        fclose(stdout);
    }
    void read(){
        //read input
        cin>>V>>N;
        available_coins=vll(V,0);
        for(ll i=0;i<V;++i) cin>>available_coins[i];

        //initialize class global variables
        res=vll(N+1,0);
        res[0]=1;
    }
    void write(){
        //write output
        cout<<res[N]<<endl;
    }
    void solve()
    {
        //Logic to solve the problem
        for(ll i_val=0;i_val<V;++i_val){
            ll val=available_coins[i_val];
            vll tmp(N+1,0);
            res[0]=1;
            for(ll i_sum=0;i_sum<N+1;++i_sum){
                //if i_sum is achievable in res[i_sum] ways
                if(res[i_sum]!=0){                    
                    for(ll k=0;i_sum+(k*val)<N+1;++k){
                        ll val1=i_sum+(k*val);//adding k x val coins to i_sum
                        //res[val1] is achievable in (tmp[val1]+res[i_sum]) ways
                        tmp[val1]+=res[i_sum];
                    }
                }
            }
            swap(res,tmp);
        }
        //End of Logic
    }



};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Money("money");
	return 0;
}

/**
TO DO:

---
Proposed Algo:
---
Observations:
---
    
/**/


