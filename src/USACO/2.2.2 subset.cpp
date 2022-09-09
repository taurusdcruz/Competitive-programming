/*
ID: taurusd1
TASK: subset
LANG: C++14
CONCEPTS: DP
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

/**subset**/
/*
Subset Sums
JRM
For many sets of consecutive integers from 1 through N (1 <= N <= 39),
one can partition the set into two sets whose sums are identical.

For example, if N=3, one can partition the set {1, 2, 3} in
one way so that the sums of both subsets are identical:
{3} and {1,2}
This counts as a single partitioning
(i.e., reversing the order counts as the same partitioning
and thus does not increase the count of partitions).

If N=7, there are four ways to partition the set {1, 2, 3, ... 7}
so that each partition has the same sum:

{1,6,7} and {2,3,4,5}
{2,5,7} and {1,3,4,6}
{3,4,7} and {1,2,5,6}
{1,2,4,7} and {3,5,6}
Given N, your program should print
the number of ways a set containing the integers from 1 through N
can be partitioned into two sets whose sums are identical.
Print 0 if there are no such ways.

Your program must calculate the answer, not look it up from a table.

PROGRAM NAME: subset
INPUT FORMAT
The input file contains a single line with a single integer representing N, as above.
SAMPLE INPUT (file subset.in)
7
OUTPUT FORMAT
The output file contains a single line with a single integer that tells how many same-sum partitions can be made from the set {1, 2, ..., N}. The output file should contain 0 if there are no ways to make a same-sum partition.

SAMPLE OUTPUT (file subset.out)
4


/**/

/**/

//class Subset
//About members of the class:
/*
Member variables:
ll N-------------------------------->As Defined in Problem
ll sum_req-------------------------->The sum the subset must sum up to (=N*(N+1)/2)
ll cnt------------------------------> the number of possible subsets summing up to sum_req
ip---------------------------------->ip[sum][indx] = is it possible to get sum-indx 
                                                        using set A = {x | xEZ, 0<x<indx}
                                                        
Member functions:

void Subset(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s
 


*/

class Subset
{
//By default data members are private
//
string task;
ll N;
ll sum_req=1;
ll cnt;
vector< vector<ll> > ip;//ip[sum][indx] = is it possible to get sum-indx 
                                 //using set A = {x | xEZ, 0<x<indx}
public:
    Subset(string _task):
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
        }
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
        //initializing class member variables
        sum_req=N*(N+1)/4;
        cnt=0ll;
        ip=vector<vector<ll>>(N+1,vector<ll>(sum_req+1,0ll));
    }
    void write(){
        //write output
        cout<<cnt<<endl;
    }
    void solve()
    {
        //Logic to solve the problem
        if(N%4!=0 and (N+1)%4!=0){
            cnt=0;
            return;
        }
        //Filling ip
        ll i=1;
        ip[0][0]=1;
        while(i<N+1){
            ll s=0;
            while(s < sum_req+1){
                ip[i][s]=ip[i-1][s]+((s-i>=0)?(ip[i-1][s-i]):(0)) ;
                auto x=ip[i][s];
                s+=1;
            }
            i+=1;
        }
        cnt=ip[N][sum_req]/2;        
        //End of Logic
    }
};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Subset("subset");
	return 0;
}

/**
is 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
0   1
1   1   1
2   1   1   1   1
3   1   1   1   2   1   1
4   1   1   1   2   2   
**/

