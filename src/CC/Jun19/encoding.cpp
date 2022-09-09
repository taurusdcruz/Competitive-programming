/*
ID: taurusd1
TASK: CHGORAM
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
typedef vector< vvll > vvvll;


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

/**Encoding**
49
/**/

/**/
//class Encoding
//About members of the class:
/*
Member variables:
task---------------------------------->name of task

Member functions:
void Encoding(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s

Additional Member functions(Non-Boiler-plate):
/**/


class Common_stuff{
    public:
    static vll _10e2ep;
    static vll _10eX;
    static void init_static_members(){
        _10eX=vll(10e5,0);precalc2();
        
        
    }
    // static void precalc1(){        
    //     //stores the result for 10^(2^p) (mod 10^9 +7), 1<=p<=10^5

    //     _10e2ep[0]=10;
    //     ll p=0;
    //     while(true){
    //         if(p>log2(10e5)){
    //             break;
    //         }
    //         _10e2ep[p+1]=fmod(pow(_10e2ep[p],2),mod);
    //         p+=1;
    //     }
    // }    
    static void precalc2(){
        _10eX[0]=1;
        for(ll i=0;i<10e5-1;++i){
            _10eX[i+1]=(10*_10eX[i])%mod;
        }
    }
    static ll f_eX(ll X){
        // ll res=0;
        // while(true){
        //     if(X==0){
        //         return fmod(res+1,mod);
        //     }
        //     res= fmod(res+_10e2ep[log2(X)],mod);
        //     X+=-log2(X);
        // }

        //----------
        if(X>10e5 or X<0){
            return -1;
        }else{
            return _10eX[X];
        }
    }

    static ll f_deX(ll d, ll e){
        return (d*_10eX[e])%mod;
    }
};

template<typename T=long long>
class Encoding:Common_stuff{//Using State<T> in member functions of Encoding to return in T!
//By default data members are private
//
string task;
ll res;

vvll sum1,sum2;//suffix,prefix
ll NL,NR;
vll L,R;//stored least significant- to - most significant
public:
    //constructor
    Encoding(string _task):
        task(_task)
        {
            //read input and initialize class member variables
            read();
            //solve
            solve();
        };
    //member functions
    inline void read(){
        //initialize class global variables


        //read input
        cin>>NL;L.resize(NL);
        for(ll i=0;i<NL;++i){
            char ch;cin>>ch;
            L[NL-1-i]=ch-'0';
        }
        cin>>NR;R.resize(NR,0);        
        for(ll i=0;i<NR;++i){
            char ch;cin>>ch;
            R[NR-1-i]=ch-'0';
        }
        //fill with leading zeros
        L.resize(max(NL,NR),0);
        R.resize(max(NL,NR),0);

        //initialize class global variables

    }
    void solve()
    {
        //Logic to solve the problem
        populate_sum1();
        ll N=max(NL,NR);
        ll i=N-1;
        ll res_common_prefix=0;

        for(ll prev_dig=0;i>=0;--i){
            if(L[i]!=R[i]){
                break;
            }else{
                ll common_dig=L[i];
                if(prev_dig!=common_dig){
                    res_common_prefix+=f_deX(common_dig,i);
                    res_common_prefix%=mod;
                }
            }
        }
        ll res=0;
        for(ll d=L[i]+1;d<R[i];++d){
            res+= res_common_prefix+sum1[d][i];
            res%=mod;
        }
        ll res_prefix_L,res_prefix_R;
        res_prefix_L=res_prefix_R=res_common_prefix;
        /* traversing digits most->least significant
            digits: d_N-1,  ...,    d_i,    ...,    d_0
            index:  N-1,    ...,    i,      ...,    0

        */
        for(ll  prev_dig_L=(i<N-1)?L[i+1]:0
                , prev_dig_R=(i<N-1)?R[i+1]:0;i>=0;--i){
           
            for(ll d=L[i]+1;d<10;++d){
                res+=res_prefix_L*f_eX(i+1);
                res%=mod;
            }
            for(ll d=0;d<R[i];++d){
                res+=res_prefix_R*f_eX(i+1);
                res%=mod;
            }
            //updating prefix_l, prefix_R
            if(prev_dig_L!=L[i]){
                res_prefix_L+=f_deX(L[i],i);
                res_prefix_L%=mod;
            }
            if(prev_dig_R!=R[i]){
                res_prefix_R+=f_deX(R[i],i);
                res_prefix_R%=mod;
            } 
        }
        cout<<res<<endl;
        //End of Logic
    }




    void populate_sum1(){
        sum1=vvll(10,vll(10e5,0));
        for(ll d=0;d<10;++d){
            sum1[d][0]=f_deX(d,0);
        }
        for(ll i=0;i<10e5-1;++i){
            for(ll d=0;d<10;++d){
                //populate sum1[d][i+1]
                for(ll dj=0;dj<10;++dj){
                    if(d==dj){
                        sum1[d][i+1]+=  sum1[dj][i] 
                                        +(f_eX(i-1 +1))*(f_deX(dj,i+1)-f_deX(dj,i));
                    }else{
                        sum1[d][i+1]+=sum1[dj][i];
                    }
                    sum1[d][i+1]%=mod;
                }
            }            
        }
        
    }

    
};

vll Common_stuff::_10e2ep=vll(log2(10e5),0);
vll Common_stuff::_10eX=vll(10e5,0);
int main( )
{
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object

    string s=R"(
    3
    1 9
    2 97
    1 8
    2 12
    1 1
    1 8
    )";
    istringstream iss(s);
    cin.rdbuf(iss.rdbuf());    
    // Common_stuff::init_static_members();
    ll T;cin>>T;
    for(ll t=0;t<T;++t){
        Encoding<ll>("encoding");
    }
    
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
