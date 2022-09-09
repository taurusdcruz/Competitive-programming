/*
ID: taurusd1
TASK: lentmo
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

/**Lentmo**

/**/

/**/
//class Lentmo
//About members of the class:
/*
Member variables:
task---------------------------------->name of task

Member functions:
void Lentmo(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s

Additional Member functions(Non-Boiler-plate):

*/

class Lentmo
{
//By default data members are private
//
string task;
vll res;//store result for each test case
ll T,N,K,X;
vll A,A0,A1,PS0,PS1;

public:
    Lentmo(string _task):
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
	    freopen((task+".in").c_str(),"r",stdin);//redirects standard input
        freopen((task+".out").c_str(),"w",stdout);//redirects standard output
    }
    void close_streams(){
        //close streams
        fclose(stdin);
        fclose(stdout);
    }
    void read(){
        //initialize class global variables

        //read input
        cin>>T;
        while(T--){
            cin>>N;
            A.resize(N);
            for(ll iN=0;iN<N;++iN){
                cin>>A[iN];
            }
            cin>>K>>X;
            solve();
        }

        //initialize class global variables

    }
    void write(){
        //write output
        for(ll i=0;i<res.size();++i){cout<<res[i]<<endl;}        
    }
    void solve()
    {
        //Logic to solve the problem
        vector<ll> Adelta;
        A0.resize(0);
        A1.resize(0);
        PS0.resize(0);
        PS0.resize(0);
        for(ll iN=0;iN<N;++iN){
            ll a=A[iN],ax=A[iN]^X;
            if(A[iN]< (A[iN]^X)){
                A1.push_back(A[iN]);
                
            }
            else{
                A0.push_back(A[iN]);
                
            }
            Adelta.push_back(abs(a-ax));
        }
        ll  N0=A0.size()
        ,   N1=A1.size();
        PS0.resize(N0+1,0);//1-based
        PS1.resize(N1+1,0);//1-based
        auto cmp_less=[=](ll l, ll r){return abs((l)-(l^X)) < abs((r)-(r^X));};
        auto cmp_grtr=[=](ll l, ll r){return abs((l)-(l^X)) > abs((r)-(r^X));};
        sort(all(A0),cmp_less);
        sort(all(A1),cmp_less);

        ll  r0=N0%K
        ,   r1=N1%K;
        ll best_sol=0,sol=0;
        vll A0delta,A1delta;
        for(ll i=0,tmp=0;i<N0;++i){
            //A0 sorted in asc
            //Assuming A0[i] >= (A0[i]^X) 
            PS0[i+1]=tmp+ (A0[i]-(A0[i]^X)) ;
            tmp=PS0[i+1];
            best_sol+=A0[i];
            sol+=A0[i];
            A0delta.push_back(A0[i]-(A0[i]^X));
        }

        for(ll i=0,tmp=0;i<N1;++i){
            //A1 sorted in desc
            //Assuming A1[i] < (A1[i]^X) 
            PS1[i+1]=tmp+ ((A1[i]^X)-A1[i]);
            tmp=PS1[i+1];
            best_sol+=(A1[i]^X);
            sol+=A1[i];
            A1delta.push_back((A1[i]^X)-A1[i]);
        }

        if(K==1){
            sol=best_sol;
        }
        else{
            if(r1%2 == 0){
                sol=best_sol;
            }else{
                //r1>0 ==> A1.size()>0
                if(A0.size()>0 ){
                    sol=max(best_sol-PS0[1],best_sol-PS1[1]);
                }
                else if(A0.size()==0){
                    sol=best_sol-PS1[1];
                }
            }
        }
        res.push_back(sol);
        //End of Logic
    }
};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object

    Lentmo("lentmo");
	return 0;
}

/**
TO DO:

---
Proposed Algo:
N
A[1...N]
K X

A0=set of number which decrease in value on toggling with X once
A1=set of number which increase in value on toggling with X once

PS0= prefix sum for A0
Ps1= prefix sum for A1

Let N0 be the size of A0
Let N1 be the size of A1

let r0 be the no of bags i want to remain untoggled in N0
r0a=N0 % K
r0b=(N0>=K)?(K-1-r0a):r0a 

let r1 be the no of bags i want tot remain toggled in N1
r1=N1 % K
r1b=(N1>=K)?(K-1-r1a):r1a 

CASE1: r0+r1<K
Initially r0(toggled) and r1(untoggled) are unsatisfied in A0 and A1 respectively
Solve issues for:
    r0  |   r1
    -------
    0       K
    1       K-1
    ...     ...
    ki      K-ki    Condition           :   (ki<=N0     &&  K-ki<=N1)
                    New unsolved issues :   abs(ki-r0)      abs(K-ki-r1)
                    Deductions          :   PS0[abs(r0-ki)] PS0[abs(K-ki-r1)]
    ...     ...
    K       0

CASE2: r0+r2>=K
---
Observations:
Need to do multiple levels 
---
    
/**/


