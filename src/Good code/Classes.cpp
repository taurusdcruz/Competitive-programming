#include <bits/stdc++.h>
using namespace std;
//#include <bigInt.h>

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

const ll mod = 1e9 + 7;
const LD PI =(LD)acos(-1);
#define sz(a) int((a).size())
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<""<<(m)<<" "<<#arr ; for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m)<<" "<<#c ;for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

//class MothersMilk
class MothersMilk
{
//By default data members are private

    set<vll > traversedabcs;//possible a,b,c pairs
    set<pll> possibleBCs;//possible b,c pairs when a==0
    set<ll > possibleCs;//possible c's when a==0
    const ll A,B,C;//capacities of of the three buckets
    const vll ABC;//capacities of the three buckets in vector form


public:
    ll in_out(ll parano)
    {
        ll c;
        //cout<<"Param No"<<parano<< "Enter no"<<endl;
        cin>>c;return c;
    };
    function<ll ()> in_out_lambda=[=](){return in_out(0);};
    //constructor delegation
    MothersMilk()
        :MothersMilk(in_out(1),in_out(2),in_out(3))
        { };
    //Note: you have to initialize everything inside the constructor's initialization list
    MothersMilk(ll _A, ll _B, ll _C)
        :A(_A)
        ,B(_B)
        ,C(_C)
        ,ABC(vll{_A,_B,_C})
        //Why do I get a warning when i dont initialize some of the following three data members  in the initializer list?
        //Do i have to initialize all the data members in a class within the initializer list of the constructor?
        //( just asking because i get a warning when i don't  initialize some of the m which i dont actually need to initialize)
        ,traversedabcs()//not initialized
        ,possibleBCs()//not initialized
        ,possibleCs()//not initialized
        { };

    void solve()
    {
        vll abc={0,0,C};
        count_(abc);

        // printing the set possibleCs within the solve method because possibleCs is a private data member and is only accessible from functions within the class
        //If you want to print possibleCs in the main function then you would have to define a getter method that returns the set possibleCs and then go ahead and print it
        tr(possibleCs,it)
        {
            cout<<(*it)<<((next(it,1)==possibleCs.end() )?("\n"):(" ") );
        }
    }
    //transfer  between two buckets (denoted by indexes "from" and "to") and return a reference to the new configuration
    vll transfer(vll abc, ll from, ll to)
    {
        ll tmp=min(abc[from],ABC[to]-abc[to]);
        abc[from]+=-tmp;
        abc[to]+=+tmp;
        return abc;
    }

    //populate the sets , traversedabcs, possibleBCs, possibleCs
    void count_(vll abc)
    {
        //debug("",abc)
        if(!present(traversedabcs,abc))
        {
            traversedabcs.insert(abc);
            ll a=abc[0], b=abc[1], c=abc[2];
            if(a==0)
            {
                possibleBCs.insert(pll(b,c) );
                possibleCs.insert(c);
            }
            rep(from,0,3)
            {
                rep(to,0,3)
                {
                    if(from==to) continue;//cant transfer milk from and to the same bucket
                    if(abc[from]==0 || (abc[to]==ABC[to]) ) continue;//cant transfer milk from a bucket that is empty or to a bucket that is filled
                    count_(transfer(abc,from,to) );
                }
            }
        }
        return;
    }
};

/**milk3**/
/*PROBLEM STATEMENT*
Farmer John has three milking buckets of capacity A, B, and C liters. Each of the numbers A, B, and C is an integer from 1 through 20, inclusive. Initially, buckets A and B are empty while bucket C is full of milk. Sometimes, FJ pours milk from one bucket to another until the second bucket is filled or the first bucket is empty. Once begun, a pour must be completed, of course. Being thrifty, no milk may be tossed out.

Write a program to help FJ determine what amounts of milk he can leave in bucket C when he begins with three buckets as above, pours milk among the buckets for a while, and then notes that bucket A is empty.

PROGRAM NAME: milk3
INPUT FORMAT
A single line with the three integers A, B, and C.

OUTPUT FORMAT
A single line with a sorted list of all the possible amounts of milk that can be in bucket C when bucket A is empty.
/**/

/*ABOUT VARIABLES USED*
A,B,C----------------------------->As defined  in "INPUT"
/**/
int main ( )
{
	//freopen("in.txt","r",stdin);//redirects standard input
    //freopen("milk3.out","w",stdout);//redirects standard output

    MothersMilk().solve();
    /*Why can't i get access to the private vector, possibleCs using an object of that class ?
    Reason:private data members cant be accessed from outside the class without using a function of the class to get the private data members(getter methods)
    Eg:
    cout<<mm.possibleCs;// gives error: 'std::set<long long int> MothersMilk::possibleCs' is private
    /**/
	return 0;
}
