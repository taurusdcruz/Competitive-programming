/*
ID: taurusd1
TASK: zerosum
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

/**Zerosum**
Zero Sum
Consider the sequence of digits from 1 through N (where N=9) 
in increasing order: 1 2 3 ... N.

Now insert either 
a `+' for addition 
or a `-' for subtraction 
or a ` ' [blank] 
to run the digits together 
between each pair of digits (not in front of the first digit). 
Calculate the result that of the expression and see if you get zero.

Write a program that will find 
all sequences of length N that produce a zero sum.

PROGRAM NAME: zerosum
INPUT FORMAT
A single line with the integer N (3 <= N <= 9).
SAMPLE INPUT (file zerosum.in)
7
OUTPUT FORMAT
In ASCII order, show each sequence that can create 0 sum with a `+', `-', or ` ' between each pair of numbers.
SAMPLE OUTPUT (file zerosum.out)
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
/**/

/**/


//class Zerosum
//About members of the class:
/*
Member variables:
task---------------------------------->name of task
N------------------------------------->As defined in question
res----------------------------------->vector of strings of possible expressions with zero sum


Member functions:
void Zerosum(ll task)----------------->Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s
void recursive(ll i,
                ll concat,
                ll sum,
                string seq)----------->recursive solution on

*/

class Zerosum
{
//By default data members are private
//
string task;
ll N;//As defined in question
vector<string> res;
public:
    Zerosum(string _task):
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
        cin>>N;
        //initialize class global variables

    }
    void write(){
        //write output
        ll i=-1;
        while(++i<res.size()){
            cout<<res[i]<<endl;
        }
    }
    void solve()
    {
        //Logic to solve the problem
        recursive(2,1,1,"1");
        //End of Logic
    }

    void recursive(ll i,ll concat,ll sum,string seq){
        //Input Parameters:
        //i-------->curr_index
        //concat--->concatination upto now
        //sum------>sum upto now
        //seq------>the expression upto now
        if(i==N+1 ){
            if(sum==0) {
                res.push_back(seq);
            }
        }
        else{
            ll c=(concat>0)?(1):(-1);
            recursive(i+1,(concat*10)+(c*i),sum+(concat*9)+(c*i),seq+" "+to_string(i));
            recursive(i+1,+i,sum+i,seq+"+"+to_string(i));
            recursive(i+1,-i,sum-i,seq+"-"+to_string(i));
        }
    }

};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Zerosum("zerosum");

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


