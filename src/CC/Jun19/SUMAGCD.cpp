/*
ID: taurusd1
TASK: sumagcd
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

/**Sumagcd**

/**/

/**/
//class Sumagcd
//About members of the class:
/*
Member variables:
task---------------------------------->name of task

Member functions:
void Sumagcd(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s

Additional Member functions(Non-Boiler-plate):

*/

class Sumagcd
{
//By default data members are private
//
string task;
vll res_all;//store result for each test case
ll T,N;
vll A;

public:
    Sumagcd(string _task):
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
            solve();
        }

        //initialize class global variables

    }
    void write(){
        //write output
        for(ll i=0;i<res_all.size();++i){cout<<res_all[i]<<endl;}        
    }
    void solve()
    {
        //Logic to solve the problem
        map<ll,map<ll,bool>> vis;
        vector<pll> combos;//gcd combos possible upto now
        pll res=pll(min(A[0],A[1]),max(A[0],A[1]));
        combos.push_back(pll(0,A[0]));
        vis[res.first][res.second]=true;
        ll i=1;
        while(i<N){
            map<ll,map<ll,bool>> vis1;
            ll a=A[i];
            vector<pll> combos1;
            for(ll j=0;j<combos.size();++j){
                if(j==0){
                    res=combos.front();
                }

                pll curr_combo=combos[j];
                pll tmp1 =pll(gcd(curr_combo.first,a),curr_combo.second);
                pll tmp2 =pll(curr_combo.first,gcd(curr_combo.second,a));
                if(i==N-1 && tmp2.first==0){
                    tmp2=tmp1;
                }
                if(i==N-1 && res.first==0){
                    res=tmp1;
                }
                if (tmp1.first>tmp1.second){ swap(tmp1.first,tmp1.second);}
                if (tmp2.first>tmp2.second){ swap(tmp2.first,tmp2.second);}
                if(not vis1[tmp1.first][tmp1.second]){
                    vis1[tmp1.first][tmp1.second]=true;
                    combos1.push_back(tmp1);
                    if(res.first+res.second < tmp1.first+tmp1.second){
                        res=tmp1;
                    }
                }
                if(not vis1[tmp2.first][tmp2.second]){
                    vis1[tmp2.first][tmp2.second]=true;
                    combos1.push_back(tmp2);
                    if(res.first+res.second < tmp2.first+tmp2.second){
                        res=tmp2;
                    }
                }
            }
            swap(vis,vis1);
            combos.resize(combos1.size());
            swap(combos,combos1);
            i+=1;
        }
        res_all.push_back(res.first+res.second);
        //End of Logic
    }
};

int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object

    Sumagcd("sumagcd");
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


