/*
ID: taurusd1
TASK: numtri
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
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
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
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
void indent(ll indent_variable)
{
    cout<<"\n";rep(i,0,indent_variable)cout<<"\t";
}

/**numtri**/
/*
Number Triangles
Consider the number triangle shown below. Write a program that calculates the highest sum of numbers that can be passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right.

          7

        3   8

      8   1   0

    2   7   4   4

  4   5   2   6   5
In the sample above, the route from 7 to 3 to 8 to 7 to 5 produces the highest sum: 30.

PROGRAM NAME: numtri
INPUT FORMAT
The first line contains R (1 <= R <= 1000), the number of rows. Each subsequent line contains the integers for that particular row of the triangle. All the supplied integers are non-negative and no larger than 100.
SAMPLE INPUT (file numtri.in)
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
OUTPUT FORMAT
A single line containing the largest sum using the traversal specified.
SAMPLE OUTPUT (file numtri.out)
30

/**/

/*ABOUT VARIABLES USED*
R----------------------------->As defined  in "INPUT"
ROW-----------------------> I haven't stored the entire tree! I have just stored the current row of the tree (which is required for my DP approach) in ROW...
MX_SUM_LEAF-------->Defined in NumberTriangles::solve()
/**/

//class NumberTriangles
//About members of the class:
/*
Member variables:
R-------------------------->the number of rows of input

Member functions:
void solve()-------------------> Self Explanatory

*/
class NumberTriangles
{
//By default data members are private
//
ll R;
//deque< vector<ll> > nodes_on_stack;//deque used as a stack



public:

NumberTriangles()
    :R
        (
         //Lambda for taking input and returning the value
            [=](){
                ll _R;cin>>_R;
                return _R;
            }
            ()//calling the lambda
        )
    {
    }

    void solve()
    {
        /*
        APPROACH:
        Maintain an vector, MX_SUM_LEAF which represents for a tree with height, h( the number of rows),
        such that MX_SUM_LEAF[i] represents
        the maximum sum of all the nodes in the max_sum_path( among all the possible paths from (root)---->(ith leaf) traversed by the given constraints of the problem)

        Assume we have the MX_SUM_LEAF vector maintained for a tree of height h,
        we can find MX_SUM_LEAF_ vector for height h+1
        by DP as follows:
        MX_SUM_LEAF_[i]=node_value_col_i +max(left_parent_of_leaf_i, right_parent_of_leaf_i)

        Once we find MX_SUM_LEAF for the last row the answer is the max_element of MX_SUM_LEAF
        */
        vll MX_SUM_LEAF(R,0);
        rep(row,0,R)
        {

            vll ROW(R,0);//row of the tree stored ,and not the entire tree
            vll MX_SUM_LEAF_(R,0);
            rep(col,0,row+1)
            {
                cin>>ROW[col];

                MX_SUM_LEAF_[col]=ROW[col]+max((col>0)?(MX_SUM_LEAF[col-1]):(0LL),MX_SUM_LEAF[col]);

            }
            MX_SUM_LEAF=MX_SUM_LEAF_;
            //debug("",MX_SUM_LEAF)
        }
        cout<<(*max_element(all(MX_SUM_LEAF)))<<endl;
    }
};

int main ( )
{
	freopen("numtri.in","r",stdin);//redirects standard input
    freopen("numtri.out","w",stdout);//redirects standard output

    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    NumberTriangles().solve();
	return 0;
}
