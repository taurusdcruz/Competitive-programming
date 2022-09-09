/*
ID: taurusd1
TASK: nocows
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

/**Nocows**
Cow Pedigrees
Silviu Ganceanu -- 2003
Farmer John is considering purchasing a new herd of cows. 
In this new herd, each mother cow gives birth to two children. 
The relationships among the cows can easily be represented 
by one or more binary trees with a total of N (3 <= N < 200) nodes. 
The trees have these properties:

The degree of each node is 0 or 2. 
The degree is the count of the node's immediate children.

The height of the tree is equal to K (1 < K < 100). 
The height is the number of nodes 
on the longest path from the root to any leaf; 
a leaf is a node with no children.

How many different possible pedigree structures are there? 
A pedigree is different if 
its tree structure differs from that of another pedigree. 

Output the remainder 
when the total number of different possible pedigrees is divided by 9901.

PROGRAM NAME: nocows
INPUT FORMAT
Line 1: Two space-separated integers, N and K.
SAMPLE INPUT (file nocows.in)
5 3
OUTPUT FORMAT
Line 1: One single integer number representing the number of possible pedigrees MODULO 9901.
SAMPLE OUTPUT (file nocows.out)
2
OUTPUT DETAILS
Two possible pedigrees have 5 nodes and height equal to 3:
           @                   @      
          / \                 / \
         @   @      and      @   @
        / \                     / \
       @   @                   @   @
/**/

/**/


//class Nocows
//About members of the class:
/*
Member variables:
task---------------------------------->name of task
N,K----------------------------------->As defined in question
mod----------------------------------->9901
glo_res------------------------------->stores the result res[K][N]
found--------------------------------->found[h][n], have I found res[h][n] ?
res----------------------------------->res[h][n],no of trees with height h having n nodes

Member functions:
void Nocows(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s
bool chk1(ll h,ll n)------------------>Check if for a given h, is n within the allowed range
ll dfs(ll h,ll n)--------------------->Recursively find res[h][n] 
                            in terms of res[i_h][i_n] 
                            where i_h<h and i_n<n using
                            //f=no of trees with height h having n nodes
                            //f(h,n)= sum over(    sum over(  2xf(i_h,i_n)xf(h-1,n-1-i_n)  )   )  
                            //          i_n=1..n      i_h=1..h
                            //       -sum over(  1xf(h-1,i_n)xf(h-1,n-1-i_n)  ) 
                            //          i_n=1..n   
*/

class Nocows
{
//By default data members are private
//
string task;
ll N,K;//As defined in question
ll mod;
ll glo_res;
vector<vector<bool>> found;
vector<vector<ll>> res;
public:
    Nocows(string _task):
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
        cin>>N>>K;
        //initialize class global variables
        mod=9901;
        glo_res=0;
        found=vector<vector<bool>>(K+1,vector<bool>(N+1,false));//found[height][nodes]
        res=vector<vector<ll>>(K+1,vector<ll>(N+1,0));//res[height][nodes]

    }
    void write(){
        //write output
        cout<<glo_res<<endl;
    }
    void solve()
    {
        //Logic to solve the problem
        found[1][1]=found[1][0]=true;
        res[1][0]=0;
        res[1][1]=1;
        glo_res=dfs(K,N);
        //End of Logic
    }
    bool chk1(ll h,ll n){
        //Assuming: h>0 and n>0(which is given in the question)
        //check if for a given h, is n within the allowed range
        ll lower=2*h+-1,upper=(h<8)?(pow(2,h)-1):(200);// as 2^8 is greater than 200(upper bound for n)
                                                       // also we cant store >2^32 in a long integer
        if(lower>n or n>upper){return false;}

        //by default return true
        return true;
    }

    ll dfs(ll h,ll n){    
        //Recursive Approach
        //f=no of trees with height h having n nodes
        //f(h,n)= sum over(    sum over(  2xf(i_h,i_n)xf(h-1,n-1-i_n)  )   )  
        //          i_n=1..n      i_h=1..h
        //       -sum over(  1xf(h-1,i_n)xf(h-1,n-1-i_n)  ) 
        //          i_n=1..n            
        if(!chk1(h,n)){return 0;}
        if(found[h][n]){return res[h][n];}
        if(n%2==0){ found[h][n]=true;return res[h][n]=0;}

        ll loc_res=0;

        ll in=1;//no of nodes in the left sub-tree
        while(in<n){
            ll ih=1;//height of left sub-tree
            if(!chk1(h-1,n-1-in)){in+=2;continue;}
            ll y=dfs(h-1,n-1-in);
            while(ih<h){
                if(!chk1(ih,in)){ih+=1;continue;}
                ll x=dfs(ih,in);                
                loc_res+=(((ih==h-1)?1:2)*x*y)%mod;
                loc_res%=mod;
                ih+=1;
            }
             in+=2;
        }
        found[h][n]=true;
        return res[h][n]=loc_res;
    }
};

int main( )
{
    /**
    freopen("in.txt","r",stdin);//redirects standard input
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Nocows("nocows");

	return 0;
}

/**
TO DO:

----
Proposed Algo:

Observations:
Given H, 2xH+1 <= N <= 2^(H+1) - 1


H\N 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
1   1   0
2   0   0   1
            2
3   0   0   0   0   2   0   1
                    3       4
4   0   0   0   0   0   0   1
5
                                      /     \  
                                          T(h+1,n1+n2)  //n1+n2= 2xk
                                          /     \
                                      T1(1...h,n1) T2(h,n2)

                                      /     \  
                                          T(h+1,n1+n2+1)  //n1+n2= 2xk
                                          /     \
                                      T1(h,n1) T2(1...h,n2)
                                      n1        n2
                                      1         2k-1
                                      3         2k-3
                                      ...       ...
                                      2k-1      1

    h\n 1   3   5   7   9   11  13  15
    1   1   0
    2   
    3
    
/**/


