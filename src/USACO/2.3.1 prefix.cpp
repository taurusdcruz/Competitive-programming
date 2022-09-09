/*
ID: taurusd1
TASK: prefix
LANG: C++14
CONCEPTS: Not using substr() & .find() method ; Iterative approach
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

/**Prefix**
The structure of some biological objects is represented by 
the sequence of their constituents, 
where each part is denoted by an uppercase letter. 
Biologists are interested in decomposing a long sequence 
into shorter sequences called primitives.

We say that a sequence S 
can be composed from a given set of primitives P 
if there is a some sequence of (possibly repeated) primitives 
from the set whose concatenation equals S. 
Not necessarily all primitives need be present. 
For instance the sequence ABABACABAAB can be composed from the set of primitives

	   {A, AB, BA, CA, BBC}
The first K characters of S are the prefix of S with length K. 
Write a program which accepts as input 
    a set of primitives 
    and a sequence of constituents 
and then computes the length of the longest prefix 
that can be composed from primitives.

PROGRAM NAME: prefix
INPUT FORMAT
First, the input file contains the list (length 1..200) of primitives (length 1..10) expressed as a series of space-separated strings of upper-case characters on one or more lines. The list of primitives is terminated by a line that contains nothing more than a period (`.'). No primitive appears twice in the list. Then, the input file contains a sequence S (length 1..200,000) expressed as one or more lines, none of which exceeds 76 letters in length. The "newlines" (line terminators) are not part of the string S.
SAMPLE INPUT (file prefix.in)
A AB BA CA BBC
.
ABABACABAABC
OUTPUT FORMAT
A single line containing an integer that is the length of the longest prefix that can be composed from the set P.
SAMPLE OUTPUT (file prefix.out)
11
/**/

/**/


//class Prefix
//About members of the class:
/*
Member variables:
task----------------------------------->name of task
P-------------------------------------->P[l], Set of prefixes of length l
S-------------------------------------->String whose prefix we need to find
max_prefix_indx------------------------>maximum possible prefix length formed from P
vis------------------------------------>vis[i], Is it possible to form a prefix upto _i_th index in S using elements of P

Member functions:

void Prefix(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s

*/

class Prefix
{
//By default data members are private
//
string task;
vector<vector<vector<string>>> P;//P[l]Set of prefixes of length l
string S;//String whose prefix we need to find
ll max_prefix_indx;
vector<bool> vis;
vector<ll> res;// res[i]-----> maximum prefix length possible from S[i,i+1...]

public:
    Prefix(string _task):
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
        P=vector<vector<vector<string>>>(26,vector<vector<string>>(10));//length of each primitive is in the range [1,10]
        bool flg=false;//flg to indicate that we are scanning for the second parameter
        string tmp;
        while(cin>>tmp){
            if(tmp=="."){
                flg=true;
                continue;
            }
            if(!flg){
                P[tmp[0]-'A'][tmp.size()-1].emplace_back(tmp);
            }else{
                S+=tmp;
            }               
        }
        ll sz=S.size();
        //initializing class member variables
        vis=vector<bool>(S.size(),false);
        res=vector<ll>(S.size(),0);
        max_prefix_indx=-1;
    }
    void write(){
        //write output
        cout<<max_prefix_indx+1<<endl;
    }
    void solve()
    {
        //Logic to solve the problem
        ll i =0;
        while(true){
            if(i>=S.size()){
                break;
            }
            if(i>0 && !vis[i-1]){
                i+=1;continue;
            }
            ll ich=S[i]-'A';//character index 0-based
            ll l=0;//l 0-based
            while(l<10){
                if(i+l>=S.size()){
                    l+=1;continue;
                }
                if(vis[i+l]){
                    l+=1;continue;
                }

                ll j=0;//0-based
                while(j<P[ich][l].size()){
                    //matching
                    ll istr=0;//0-based
                    bool flg_match=true;
                    while(istr<l+1){
                        if(S[i+istr]!=P[ich][l][j][istr]){
                            flg_match=false;
                            istr=l+1;break;
                        }
                        istr+=1;
                    }
                    //do if there is a match
                    if(flg_match){
                        vis[i+l]=true;
                        max_prefix_indx=max(max_prefix_indx,i+l);
                        break;
                    }
                    j+=1;
                }
                l+=1;
            }
            i+=1;
        }
        //End of Logic
    }
    //everything passed to the function is 0-based
    bool match_substrings(string s1="",long long ibeg1=0,long long iend1=-1,string s2="",long long ibeg2=0,long long iend2=-1){
        bool flg_match=true;
        long long i1=ibeg1,i2=ibeg2;
        long long s1_sz=s1.size(),s2_sz=s2.size();
        if (iend1==-1){
            iend1=s1_sz-1;
        }
        if (iend2==-1){
            iend2=s2_sz-1;
        }        
        while(true){
            if(i1>=s1_sz || i2>=s2_sz){
                break;
            }
            if(i1>iend2 || i2>iend2){
                break;
            }
            if(s1[i1]!=s2[i2]){
                flg_match=false;
                break;
            }
            i1+=1,i2+=1;
        }
        return flg_match;
    }

};

int main( )
{
    /**
    freopen("in.txt","r",stdin);//redirects standard input
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Prefix("prefix");

	return 0;
}

/**
TO DO:
1.validate the read() method

----
Proposed Algo:
ip[i]----->it is possible to get a prefix upto ith index in string(S)
/**/