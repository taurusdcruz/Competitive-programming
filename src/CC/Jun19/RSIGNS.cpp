/*
ID: taurusd1
TASK: chfing
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

/**Chfing**

/**/

/**/
//class Chfing
//About members of the class:
/*
Member variables:
task---------------------------------->name of task

Member functions:
void Chfing(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s

Additional Member functions(Non-Boiler-plate):

*/

class Chfing
{
//By default data members are private
//
string task;
vll res_all;//store result for each test case
ll T,K;

public:
    Chfing(string _task):
        task(_task)
        {

            //Open streams
            open_streams();
            //read input and initialize class member variables
            read();
            //solve
            // solve();
            //write output after solving
            write();
            //close streams
            close_streams();
        };
    void open_streams(){
        //open streams
	    // freopen((task+".in").c_str(),"r",stdin);//redirects standard input
        // freopen((task+".out").c_str(),"w",stdout);//redirects standard output
    }
    void close_streams(){
        //close streams
        // fclose(stdin);
        // fclose(stdout);
    }
    void read(){
        //initialize class global variables

        //read input
        cin>>T;
        while(T--){
            cin>>K;
            solve();
        }
        //initialize class global variables

    }
    void write(){
        //write output
        // for(ll i=0;i<res_all.size();++i){cout<<res_all[i]<<endl;}        
    }
    void solve()
    {
        //Logic to solve the problem
        //powers required to for m k
        ll res=1;
        //dp[p]: pow(2,pow(2,p))%mod
        //dp[p]=(dp[p-1]*dp[p-1])%mod as pow(2,pow(2,p))=pow(pow(2,pow(2,p)),2)

        vll dp(floor(log2(K))+1,0);
        dp[0]=2;
        for(ll ip=1;ip<floor(log2(K))+1;++ip){
            dp[ip]=(dp[ip-1]*dp[ip-1])%mod;
        }        
        vll vp;
        for(ll tmp=K;!(tmp==0);){
            ll p = floor(log2(tmp));
            vp.push_back(p);
            tmp=tmp-pow(2.0l,p);
            res= (res*dp[p])%mod;
        }
        res=(res*5)%mod;
        cout<<res<<endl;
        //End of Logic
    }
};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object

    Chfing("chfing");
	return 0;
}

/**
TO DO:

---
Proposed Algo:

A   :   -   a1  ...     ak      ... aN  (1-based indexing)

Let aN=NN
vis :   -   1   ...     ki      ... NN   (1-based indexing)
vis1:  
    vis1[ki] :is ki reachable from a linear combination of ak E A
            aN+1...     aN+ki   ... aN+NN
    vis1[ki]= true  if either:
                        vis[ki-ak]                  if ki>ak
                        vis[(NN-1+ki-ak)%NN+1]      if ki<=ak
    if vis1[ki]= false
        cnt+=1
---
Observations:
Need to do multiple levels 
---
    
/**/


