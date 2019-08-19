/*
ID: taurusd1
TASK: concom
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

/**Concom**
Controlling Companies
Some companies are partial owners of other companies 
because they have acquired part of their total shares of stock. 
For example, Ford at one point owned 12% of Mazda. 
It is said that a company A controls company B if 
at least one of the following conditions is satisfied:
    COND1: Company A = Company B
    COND2: Company A owns more than 50% of Company B
    COND3: Company A controls K (K >= 1) companies 
        denoted C1, ..., CK with each company Ci 
        owning xi% of company B and x1 + .... + xK > 50%.
    
Given a list of triples (i,j,p) which denote 
company i owning p% of company j, 
calculate all the pairs (h,s) in which 
company h controls company s. 
There are at most 100 companies.

Write a program to read the list of triples (i,j,p) 
where i, j and p are positive integers all in the range (1..100) 
and find all the pairs (h,s) so that company h controls company s.

PROGRAM NAME: concom
INPUT FORMAT
Line 1:	n, the number of input triples to follow
Line 2..n+1:	Three integers per line as a triple (i,j,p) described above.
SAMPLE INPUT (file concom.in)
3
1 2 80
2 3 80
3 1 20
OUTPUT FORMAT
List 0 or more companies that control other companies. 
Each line contains two integers that denote that 
the company whose number is the first integer 
controls the company whose number is the second integer. 
Order the lines in ascending order of the first integer 
(and ascending order of the second integer to break ties). 
Do not print that a company controls itself.
SAMPLE OUTPUT (file concom.out)
1 2
1 3
2 3

/**/

/**/
//class Concom
//About members of the class:
/*
Member variables:
task---------------------------------->name of task
N------------------------------------->As defined in question
shr_invstd---------------------------->[c1][c2]:Amount of shares 
                                        c1 owns of c2(directly or indirectly)
co_invstd----------------------------->co_invstd[owner]:represent companines that are                                               invested in(directly or indirectly) by owner
                                        Note:
                                        Indirect investment can only be done 
                                        by c1 in c3 if:
                                            -c1 owns c2
                                            -c2 has invested in c3

Member functions:
void Concom(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s
void add_neighbours(ll c1, ll c2)----->Adding the shares of each 
                                        neighbour of c2(say c3) to c1.
                                        Assumption:c1 owns c2

*/

class Concom
{
//By default data members are private
//
string task;
ll N;
vector<vector<ll>> shr_invstd;//[c1][c2]:Amount of shares 
                                //c1 owns of c2(directly or indirectly)
vector<vector<ll>> co_invstd;//co_invstd[owner]:represent companines that are either:
                           //-invested in(directly or indirectly) by owner
                           //Note:
                           //Indirect investment can only be done by c1 in c3 if:
                           // c1 owns c2 and c2 has invested in c3
public:
    Concom(string _task):
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
        //initialize class global variables
        shr_invstd=vector<vector<ll>>(100+1,vector<ll>(100+1,0));
        co_invstd=vector<vector<ll>>(100+1);

        //read input
        cin>>N;
        ll c1,c2,share;
        for(ll i=0;i<N;++i){
            cin>>c1>>c2>>share;
            //IMP!!!
            //Ignoring case  when c1 owns c1(Problem asks us to ignore this case)
            if(c1==c2){continue;}
            shr_invstd[c1][c2]+=share;
            co_invstd[c1].push_back(c2);
        }

        //initialize class global variables

    }
    void write(){
        //write output
        for(ll c1=1;c1<100+1;++c1){
            for(ll c2=1;c2<100+1;++c2){
                if(c1==c2){continue;}
                if(shr_invstd[c1][c2]>50){
                    cout<<c1<<" "<<c2<<endl;
                }
            }
        }
    }
    void solve()
    {
        //Logic to solve the problem        
        //Terms:
        //  neighbour:  ci is a neighbour of cj implies that 
        //              cj invested(directly or indirectly) ci.
        for(ll c1=1;c1<100+1;++c1){
            for(ll ic2=0;ic2<co_invstd[c1].size();++ic2){
                //Iterating through each neighbour of c1, i.e c2.
                ll c2=co_invstd[c1][ic2];
                //If c1 owns c2, then, add 
                //shares of each neighbour of c2(say c3) 
                //as an indirect investment by c1 in c3.
                if(shr_invstd[c1][c2]>50){
                    add_neighbours(c1,c2);
                }                
            }        
        }
        //End of Logic
    }

    void add_neighbours(ll c1, ll c2){
        //Terms:
        //  neighbour:  ci is a neighbour of cj implies that 
        //              cj invested(directly or indirectly) ci.
        //A1:assuming shr_invstd[c1][c2]>50

        //Adding the shares of each neighbour of c2(say c3) to c1
        for(ll ic3=0;ic3<co_invstd[c2].size();++ic3){
            ll c3=co_invstd[c2][ic3];
            //We only care about neighbours of c2 other than c1 
            //as this would lead to the 'c1 owns c1' case 
            //which we are asked to ignore in the problem.  
            if(c3==c1){                        
                continue; 
            }
            if(shr_invstd[c1][c3]<=50 && shr_invstd[c2][c3]>0){
                shr_invstd[c1][c3]+=shr_invstd[c2][c3];
                //Let,
                //I23 : indirect investment by c1 in c3 
                //      via c2(Since c1 owns c2).
                //I13 : c1's investment(upto now) in c3.
                //_I13: Upadted value of I13 after adding c1's
                //      indirect investment to its initial investment
                //Now,
                //If _I13>50, then 
                //      c1 owns c3(Using COND3 in problem statement)
                if(shr_invstd[c1][c3]>50){
                    //Append c3 to list of neighbours c1
                    co_invstd[c1].push_back(c3);
                    //Note:we will traverse the neighbours of c3 in the solve() function itself 
                    //as it is now appended to the list of neighbours owned by c1 after c2.
                    //Sweet :P !!!
                }
            }
        }
    }
};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Concom("concom");
	return 0;
}

/**
TO DO:

---
Proposed Algo:
---
Observations:
Need to do multiple levels 
---
    
/**/


