/*
ID: taurusd1
TASK: MINDSUM
LANG: C++14
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
#define debug(m,x) cout <<"\n"<<(m)<<" "<<#x<< (x);
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

/*ABOUT VARIABLES USED*
!!!GTFO!!!
/**/

//class MINDSUM
//About members of the class:
/*
Member variables:
N,D----------------------------->As Defined in

Member functions:
get_long()---------------------> take long from input stream and return it
get_final_digitsum-----------> get the final value of recursively applying digitsum operation on a positive no
void solve()-------------------> Self Explanatory

*/

class MINDSUM
{
//By default data members are private
//
ll N,D;

public:
ll get_long(){ll _R;cin>>_R; return _R;};
function<ll (ll)> get_final_digitsum=[](ll x){return x%9?x%9:9;};
ll get_digitsum(ll x)
{
    ll digitsum;
    for
        (
            digitsum=0;
            x>0/*x is atleast 1 digit long excluding zero(as it doesnt contribute towards the sum of the digits of a number)*/ ;
            digitsum+=x%10,x/=10
        )/*G.O.A.T.*/;
        return digitsum;
}
MINDSUM()
    :N(get_long())
    ,D(get_long())
    {};

    /* f
        (
         intermediary value of N after performing the operations,
         no of digitsum operations performed upto now,
         remaining addD2N operations left to perform,
         minimum possible no of digitsum operations to get the minimum value of N after performing a sequence of operations
     )
     */
    void f(ll N, ll no_oper_digitsum, ll rem_oper_addD2N, ll& min_oper_digitsum, string seq, string seq1)
    {
        auto _=(vll{N,no_oper_digitsum, rem_oper_addD2N, min_oper_digitsum}) ;
        auto indent=[=](){string s; rep(i,0,rem_oper_addD2N) s+="\t"; return s;};
        if(rem_oper_addD2N>0)
        {
            /**
            _=(vll{N+D,no_oper_digitsum, rem_oper_addD2N-1, min_oper_digitsum}) ;debug( indent()+"branch0",_)
            /**/
            f(N+D, no_oper_digitsum,rem_oper_addD2N-1, min_oper_digitsum, seq+"0", seq1+"["+to_string(N+D)+"]");
            /**
            _=(vll{get_digitsum(N),no_oper_digitsum+1, rem_oper_addD2N, min_oper_digitsum}) ;if(N>9)debug( indent()+"branch1",_)
            /**/
            if(N>9) f(get_digitsum(N), no_oper_digitsum+1,rem_oper_addD2N, min_oper_digitsum, seq+"1", seq1+"["+to_string(get_digitsum(N))+"]");
        }
        else
        {

            if(N>9)
            {
                while(N>9)
                {
                    /**
                    _=(vll{get_digitsum(N),no_oper_digitsum+1, rem_oper_addD2N, min_oper_digitsum}) ;debug(indent()+"branch1",_ )
                    /**/
                    N=get_digitsum(N);
                    no_oper_digitsum+=1;
                    seq+="1";
                    seq1+="["+to_string(N)+"]";
                }
            }
            seq+=">>>>no_oper_digitsum="+to_string( no_oper_digitsum)+"xXx";
            if(min_oper_digitsum==-1) min_oper_digitsum=no_oper_digitsum;
            min_oper_digitsum=min(min_oper_digitsum, no_oper_digitsum);
            /**
            debug2("", seq, seq1)
            /**/

        }
        return;



    }

    void solve()
    {
        /*
        APPROACH:
        1.calc min_final_digitsum, cnt_oper_addD2N
        2.calc cnt_oper_digitsum, using N_=new N after performing operation:"addD2n"  cnt_oper_addD2N number of times and

        */
        ll initial_digitsum=get_final_digitsum(N);
        ll min_final_digitsum=initial_digitsum;// minimum possible final digit sum after performing addD2N operation optimal no of times
        ll cnt_oper_digitsum=-1;//no of times  to perform "digit sum" operation to get a single digit no
        ll cnt_oper_addD2N=0;//no of times to perform "add D to N" operation to get the minimum possible result continuously performing the "digit sum" operation
        //debug2("",N,D)

        //calc cnt_oper_addD2N
        ll i=1;
        for(;get_final_digitsum(N+i*D) !=get_final_digitsum(N);++i )
        {
            if(min_final_digitsum>get_final_digitsum(N + i*D) )
            {
                min_final_digitsum=min(min_final_digitsum, get_final_digitsum(N+ i*D) );
                cnt_oper_addD2N=i;
                /**
                debug2("", i,min_final_digitsum)
                /**/
            }
        }
        /**
        debug2("",N,D)
        auto _var_names___="N,no_oper_digitsum, rem_oper_addD2N, min_oper_digitsum";
        debug("",_var_names___)
        /**/

        f(N,0,cnt_oper_addD2N,cnt_oper_digitsum, " "," ");
        cout<<min_final_digitsum<<" " <<cnt_oper_addD2N+cnt_oper_digitsum<<endl;
    }
};

int main ( )
{
	freopen("inMINDSUM.txt","r",stdin);//redirects standard input
    ll T;cin>>T;
    rep(t,0,T) MINDSUM().solve();
	return 0;
}
