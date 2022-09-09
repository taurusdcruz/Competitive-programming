/*
ID: taurusd1
TASK: CCIRCLES
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
#define debug(m,x) cout <<"\n"<<(m)<<" "<<#x<<" "<< (x);
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

struct circle
{
    LD x,y,r;
public:
    istream& operator>>(istream& is);
    ostream& operator<<(ostream& os);

};

istream& operator>>(istream& is, circle& obj)
{
    // read obj from stream
    is>>obj.x>>obj.y>>obj.r;
    return is;
}
ostream& operator<<(ostream& os, const circle& obj)// not
{
    // write obj to stream
    os<<"("<<obj.x<<", "<<obj.y<<", "<<obj.r<<" )";
    return os;
}
class circlex2
{
    circle c1,c2;
    LD c_dis;//distance between centres
    bool inside_the_other;

public:
    LD max_dis, min_dis;

    //Why Overloading in classes, we need to use the function as friend for the function to access the private members???
    friend istream& operator>>(istream& , circlex2& );// i wont be able to access  private members to print out if i don't declare this function here
    friend ostream& operator<<(ostream& ,const circlex2& );// i wont be able to access  private members to print out if i don't declare this function here
    bool in_range(ll& K){ return ((LD)K)>=min_dis && ((LD)K)<=max_dis;}
    circlex2(circle _c1,circle _c2):
        c1(_c1)
        ,c2(_c2)
        ,c_dis
        ( [&]()
            {
                LD tmp
                =sqrt
                    (
                        pow((c1.x-c2.x),2)
                        + pow((c1.y-c2.y),2)
                     );
                return tmp;
            }
            ()
        )
        ,inside_the_other
        (
            ( c_dis < abs(c2.r-c1.r) )
           ?true
           :false
        )
        ,max_dis
        ([&]()
            {
                    return
                        floor
                        (
                            (inside_the_other)
                            ?(c_dis + abs(c2.r+ c1.r) )
                            :(c_dis + (c2.r+ c1.r) )
                         );
            }
            ()
         )
        ,min_dis
        ( [=]()
             {
                return
                ceil
                (
                    (inside_the_other)
                    ?(- c_dis + abs(c2.r- c1.r) )
                    :( max((LD)0,c_dis - (c2.r+ c1.r)) )
                 );
             }()
        )
        {
            /*Debug in constructor*
            cout<<make_pair(c1,c2)<<" "<<c_dis<<" "<< make_pair(min_dis, max_dis)<<(inside_the_other?"T":"F")<<endl;
            /**/
        };
};

istream& operator>>(istream& is, circlex2& obj)
{
    // read obj from stream
    is>>obj.c1>>obj.c2;
    return is;
}
ostream& operator<<(ostream& os, const circlex2& obj)
{
    // write obj to stream
    os<<"\n("<<obj.c1<<", "<<obj.c2<<", "<<obj.min_dis<<", "<<obj.max_dis<<", "<<(obj.inside_the_other?"T":"F")
    <<", "<<obj.c_dis<<" )";
    return os;
}
class CCIRCLES
{
    //By default data members are private
    //note: that order of assignment in the initializer list is the same as the order of declaration of the variables and
    // not the order of the variables in the initializer list of the constructor
    ll N,Q;
    vector< circle > vcir;
    vll vK;
    vector< circlex2 > vcirx2;

public:
    //constructor
    CCIRCLES()
        :N()
        ,Q()
        ,vcir()
        ,vK()
        ,vcirx2()
        {};
    CCIRCLES(ll _N, ll _Q, vector<circle> _vcir, vector<ll> _vK, vector<circlex2> _vcirx2)
        :N(_N)
        ,Q(_Q)
        ,vcir(_vcir)
        ,vK(_vK)
        ,vcirx2(_vcirx2)
        {
        };


    void test()
    {
        cout<<"Testing...\n";
        circle c1{0.0L,0.0L,100.0L};
        rep(i,0,200)
        {
            _(i)cout<<"| ";
            circlex2{c1, circle{0.1L*i+96,0.0L,3.0L}};

        }
    }
    void solve()
    {
        /*
        APPROACH:

        */
        /**
        debug2("",N,Q)
        debug("", vcir)
        debug("",vK)
        debug("",vcirx2)
        /**/
        ll max_vK=*max_element(all(vK));
        vll no_end(max_vK+1,0), no_beg(max_vK+1,0);
        /**
        debug("", max_vK)
        /**/
        rep(i,0,vcirx2.size())
        {

            if(vcirx2[i].max_dis<max_vK+1) ++no_end[vcirx2[i].max_dis ];
            if(vcirx2[i].min_dis<max_vK+1)  ++no_beg[vcirx2[i].min_dis];
            /**
            auto _maxLT=(vcirx2[i].max_dis<max_vK+1)?("T"):("F");
            auto _minLT=(vcirx2[i].min_dis<max_vK+1)?("T"):("F");
            auto _min_dis=make_pair(vcirx2[i].min_dis,_minLT);
            auto _max_dis=make_pair(vcirx2[i].max_dis,_maxLT);
            debug3("",i,_min_dis ,_max_dis )
            /**/
        }
        vll res(max_vK+1,0);
        rep(i,0,max_vK+1)
        {
            if(i==0)
            {
                res[i]=no_beg[0];
            }
            else
            {
                res[i]=res[i-1] -no_end[i-1] +no_beg[i];
            }
            /**
            debug4("",i, res[i], no_end[i-1], no_beg[i])
            /**/
        }
        /**
        debug("",res)
        /**/
        rep(q,0,Q)
        {
            ll K=vK[q];
            cout<<res[K]<<endl;
        }
    }
};

int main ( )
{
	freopen("inCCIRCLES.txt","r",stdin);//redirects standard input

	ll N, Q;cin>>N>>Q;
	vector<circle> vcir(N); rep(i,0,N){ cin>>vcir[i];};
	vector<circlex2>vcirx2; rep(i,0,N) rep(j,i+1,N) vcirx2.push_back(circlex2{vcir[i],vcir[j]});
	vll vK(Q);rep(q,0,Q) cin>>vK[q];
    /**
    CCIRCLES().test();
    /**/
    CCIRCLES(N,Q,vcir,vK,vcirx2).solve();
    /**/

	return 0;
}
