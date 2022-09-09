
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

class EllysThreePrimes{
    vector<bool> IP;
    vector<int> LP;
    vector<int> fivedigP;
    public:
    EllysThreePrimes(){
        IP = vector<bool>(1000000,false);
        IP[2]=true;
        LP.emplace_back(vector<ll>{2ll});
    };
    vector <int> getPrimes(vector <int> sm){
        //d1 + d2 + d3 = s 
        //-> d3 = s - (d1 + d2) >=0
        generate_primes();
        for(ll ip1=0;ip1<fivedigP.size();ip1+=1){
            for(ll ip2=ip1+1;ip1<fivedigP.size();ip2+=1){
                ll t1=ip1,t2=ip2,t3=0;
                for(ll i=4;i>=0;i+=-1){
                    ll d1=t1%10, d2=t2%10, d3 =sm[i]-(d1+d2) ;
                    if(d3>=0 && d3<=9){
                        
                    }
                }
            }
        }


    }
    bool generate_primes(){
        for(ll ipp=3;ipp<1000000;ipp+=1){
            bool flg=true;
            for(ll ip=0;ip<LP.size();ip+=1){
                flg= flg && (ipp%LP[ip] !=0);
            }
            if(flg){
                LP.emplace_back(ipp);
                IP[ipp]=true;
                if(ipp>9999){
                    fivedigP.emplace_back(ipp);
                }
            }
        }

    }
};


// class EllysViewPoints{
//     public:
//     int getCount(int NR, int NC, vector <string> matrix){
//         vector<bool> r(NR,true), c(NC,true);
//         int res=0;
//         for(ll ir=0;ir<NR;ir+=1){
//             for(ll ic=0;ic<NC;ic+=1){
//                 if(matrix[ir][ic]=='#'){
//                     r[ir]=c[ic]=false;
//                 }
//             }
//         }
//         for(ll ir=0;ir<NR;ir+=1){
//             for(ll ic=0;ic<NC;ic+=1){
//                 if(r[ir] && c[ic]){
//                     res+=1;
//                 }
//             }
//         }
//         return res;   
//     }
// };
