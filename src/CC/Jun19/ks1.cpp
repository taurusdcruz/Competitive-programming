

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
        os << ((ii!=mp.begin())?", ":"") << *ii;
    }
    os << "]";
    return os;
}


void solve(){
    ll N;cin>>N;
    vll A(N);
    for(ll i=0;i<N;++i){
        cin>>A[i];
    }
    map<ll,ll> pref,suff;
    //suff forward
    for(ll i=N-1;i>=0;--i){
        map<ll,ll> suff1;
        
        for(auto& nd:suff){
            auto el=nd.first;
            suff1[(el^A[i])]+=1;
        }
        suff1[A[i]]+=1;
        suff.swap(suff1);
    }
    ll res=0;
    for(ll i=0;i<N;++i){

        //set intersection cnt
        if(i>0){
            // cout<<"p"<<pref<<endl;
            // cout<<"s"<<suff<<endl;
            auto ft1=pref.begin();
            auto lt1=pref.end();
            auto ft2=suff.begin();
            auto lt2=suff.end();

            while (ft1 != lt1 && ft2 != lt2) {
                if (*ft1 < *ft2) {
                    ++ft1;
                } else  {
                    if (!(*ft2 < *ft1)) {
                        
                        res+=min(ft1->second,ft2->second);
                        // cout<<"\t"<<pll(ft2->first,res)<<endl;
                    }
                    ++ft2;
                }
            }
        }

        //tmp sets
        map<ll,ll> pref1,suff1;

        //pref forward
        for(auto& nd:pref){
            auto el=nd.first;
            pref1[(A[i]^el)]+=1;
        }
        pref1[A[i]]+=1;

        //suff reverse
        suff[A[i]]+=-1;
        if(suff[A[i]]<=0){
            suff.erase(A[i]);
        }
        
        for(auto& nd:suff){
            auto el=nd.first;
            suff1[el^A[i]]+=1;
        }

        //swapping
        pref.swap(pref1);
        suff.swap(suff1);
    }
    cout<<res<<endl;
}

int main(){
    char* custom_input=R"(
1
3
5 2 7   
    )";    
    auto iss1=istringstream(custom_input);
    cin.rdbuf(iss1.rdbuf());
    ll T;cin>>T;
    for(ll t=0;t<T;++t){
        solve();
    }
    return 0;
}