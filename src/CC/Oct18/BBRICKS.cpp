/*
ID: taurusd1
TASK: BBRICKS
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
#define debug(m,x) cout <<"\n"<<(m)<<" "<<#x<<"| "<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;


//Overriding << operator for pair
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}
//Overriding >> operator for pair
template< class T, class U >
istream&  operator>>(istream& is,pair<T,U>& a)
{
  is>>a.first>>a.second;
  return is;
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
class BBRICKS
{
    //By default data members are private
    //note: that order of assignment in the initializer list is the same as the order of declaration of the variables and
    // not the order of the variables in the initializer list of the constructor
    ll T;
    vector<ll> res;
    vector<pair<ll,ll> > vpnk;


public:

    //constructor
    BBRICKS(ll& _T):
        T(_T)
        ,res
        (
            [&]()->vector<ll>
            {
                vector<ll> res(T,-1);
                return res;
            }
            ()
         )
        ,vpnk
        (
            [&]()
            {
                vector<pair<ll,ll> > vpnk(T);
                rep(t,0,T)
                {
                    cin>>vpnk[t].first>>vpnk[t].second;
                }
                return vpnk;
            }
            ()
        )
        {
        };

    void test()
    {
        cout<<"Testing...\n";
        /*
        */
    }
    string indent( ll n,string s="")
    {
        string tmp="\n";
        rep(i,0,n) tmp+="\t";
        s=tmp+s;
        return s;
    }
    void print(vector<vector<vector<vector<ll > > > >& some_vvvv,ll _1, ll _2, ll _3,ll _4, ll indent_n )
    {
        cout<<indent(indent_n,"")<<some_vvvv[_1][_2][_3][_4];
    }
    void print_v(vector<vector<vector<vector<ll > > > >& some_vvvv,ll _1, ll _2, ll _3,ll indent_n )
    {
        cout<<indent(indent_n,"")<<some_vvvv[_1][_2][_3];
    }
    void print_vv(vector<vector<vector<vector<ll > > > >& some_vvvv,ll _1, ll _2, ll indent_n )
    {
        for(ll _3=0;_3<some_vvvv[_1][_2].size();++_3)
        {
            cout<<indent(indent_n,"")<<some_vvvv[_1][_2][_3];
        }
    };
    void print_vvv(vector<vector<vector<vector<ll > > > >& some_vvvv,ll _1, ll indent_n )
    {
        for(ll _2=0;_2<some_vvvv[_1].size();++_2)
        {
            for(ll _3=0;_3<some_vvvv[_1][_2].size();++_3)
            {
                cout<<indent(indent_n,"")<<some_vvvv[_1][_2][_3];
            }
            cout<<indent(indent_n,"_____");
        }
    }
    void print_vvvv(vector<vector<vector<vector<ll > > > >& some_vvvv, ll indent_n )
    {
        for(ll _1=0;_1<some_vvvv.size();++_1)
        {
            for(ll _2=0;_2<some_vvvv[_1].size();++_2)
            {
                for(ll _3=0;_3<some_vvvv[_1][_2].size();++_3)
                {
                    cout<<indent(indent_n,"")<<some_vvvv[_1][_2][_3];
                }
                cout<<indent(indent_n,"_____");
            }
            cout<<indent(indent_n,"=====");
        }
    }
    //Calc log with error checking
    ll log2_ErrorChecking(ll& IN)
    {
        /**
        IN>0------>returns the floor of the log2 of IN
        IN<=0----> returns -1
        /**/
        return (IN > 0 )?(floor(log2( IN)) ):(-1LL);
    }
    ;

    void solve()
    {
        /*
        APPROACH:

        */
        ll myN
        =max_element
        (
            all(vpnk)
            ,[](const pll& l, const pll& r) { return l.first<r.first;}
        )
        ->first;
        ll myK
        =max_element
        (
            all(vpnk)
            ,[](const pll& l, const pll& r){ return l.second<r.second;}
        )
        ->second;

        myK=min(myN,myK);
        auto tmp
        =vector< vvll >
        (
            myN+1
            ,vvll
            {
                vll{0,0,0}
                ,vll{0,0,0}
                ,vll{0,0,0}
            }
        );
        tmp[0]
        =vvll
            {
                vll{0,0,0}
                ,vll{0,0,0}
                ,vll{0,0,1}
            };


        vector< vector< vector< vector<ll> > > >
        nkc
        (
            floor(log2(myN))+1
            ,tmp
        );
        nkc[0][1]
        =vvll
            {
                vll{1,0,0}
                ,vll{0,1,0}
                ,vll{0,0,0}
            }
        ;

        vector< vector<ll> >
        be
        {
            {0,1}
            ,{0,2}
            ,{1,0}
            ,{1,2}
            ,{2,0}
            ,{2,1}
            ,{2,2}
         }
         ;

        for(ll n=1,P=0; 2*n<myN+1;n*=2,P+=1)
        {
            ll _2n=2*n;
            ll IP=P+1;
            /**
            --------------------------------------------
            |                        _2n                          |
            --------------------------------------------
            ------------------  ------------------------
            |      n,k_i        | |        n, k-k_i          |
            ------------------  ------------------------

            /**/
            cout<<indent(0,"n:")<<n;
            for(ll IK=1; IK<_2n+1;++IK)
            {
                //calc nkc[IP][IK], where IK (belongs to )E[1,_2n+1)
                //=sum over k( nkc[P][k][][] * nkc[P][K-k][][])
                /**for(ll K=1; K<IK+1;++K)/**/ll K=IK;
                {
                    cout<<indent(1,"IK:")<<IK;
                    //calc nkc[IP][IK] with IK=K for the 3x3 grid of BxE
                    for(ll B=0; B<3;++B)
                    {
                        cout<<indent(2,"B:")<<B;
                        for(ll E=0; E<3;++E)
                        {
                            cout<<indent(3,"E:")<<E;
                            for(ll k=max(0LL,IK-n); k<min(n+1,IK+1);++k )
                            {
                                cout<<indent(4,"k:")<<k;
                                ll e,b;
                                for(ll i=0; i<be.size(); ++i)
                                {
                                    auto nkc_dbg
                                    =[&](ll P,ll K,ll B,ll E)
                                    {
                                        return "nkc["+to_string(P)+"]["+to_string(K)+"]["+to_string(B)+"]["+to_string(E)+"]";
                                    };
                                    b=be[i][0], e=be[i][1];
                                    cout<<indent(5,"b"+to_string(b)+",e"+to_string(e));
                                    auto end_P_IK=make_pair(1LL,4LL);
                                    if(make_pair(P,IK)== end_P_IK)
                                    {
                                    /**/
                                        cout<<indent(5," ")
                                        +nkc_dbg(IP,IK,B,E)+ to_string( nkc[IP][IK][B][E] + nkc[P][k][B][e] * nkc[P][IK-k][b][E])
                                        +"= "+nkc_dbg(IP,IK,B,E)+to_string( nkc[IP][IK][B][E] )
                                        +"+ ( "+nkc_dbg(P,k,B,e)+ to_string(nkc[P][k][B][e] )
                                        +"* " +nkc_dbg(P,IK-k,b,E)+to_string(nkc[P][IK-k][b][E])
                                        +") ";
                                    /**/
                                    }
                                    if(make_pair(P,IK)> end_P_IK) return ;
                                    nkc[IP][IK][B][E]
                                    =
                                    (
                                    nkc[IP][IK][B][E]
                                    +nkc[P][k][B][e] * nkc[P][IK-k][b][E]
                                    )%mod;
                                }
                            }//end of k
                            cout<<indent(3,"calc npk["+to_string(IP)+"]["+to_string(IK)+"]["+to_string(B)+"]["+to_string(E)+"]=");print(nkc,IP,IK,B,E,3);
                        }//end of E
                    }//end of B
                    cout<<indent(1,"KKKKcalc npk["+to_string(IP)+"]["+to_string(IK)+"]=");print_vv(nkc,IP,IK,1);


                }//end of K
                cout<<indent(0,"IKIKIK Final value npk["+to_string(IP)+"]["+to_string(IK)+"]=");print_vv(nkc,IP,IK,0);
            }//end of IK
            cout<<"\nHERE";
        }
        cout<<"\nOUT OF FOR";
        for(ll i=0;i<vpnk.size();++i)
        {
            auto tmp1=tmp;
            tmp1[1]
            =vvll
                {
                    vll{1,0,0}
                    ,vll{0,1,0}
                    ,vll{0,0,0}
                }
            ;
            vector< vector< vector<ll> > >
            lastnkc(all(tmp1))
            ,currnkc(all(tmp))
            ;
            ll IN=vpnk[i].first, IK=vpnk[i].second;
            if(IN<IK)
            {
                cout<<0<<endl;
                continue;
            }
            debug2("",IN,IK)
            ll P;
            for
                (
                    P=log2_ErrorChecking(IN),lastnkc=nkc[P], IN=IN-exp2(P), P=log2_ErrorChecking(IN);
                    log2_ErrorChecking(IN)>=0;
                    P=log2_ErrorChecking(IN), IN=IN-exp2(P)
                )
            {

                // calc currnkc[] where K belongs to 1, 2, ... IK+1
                for(ll K=1; K<IK+1;++K)
                {
                    //calc currnkc[IK<-K][B][E]  for the 3x3 grid of BxE
                    for(ll B=0; B<3; ++B)
                    {
                        for(ll E=0; E<3; ++E)
                        {
                            //Using the formula
                            //
                            for(ll k=0; k<K+1;++k )
                            {
                                /**
                                -----------------------   -----------
                                |        lastnkc              currnkc
                                -----------------------   -----------
                                /**/
                                ll k_nkc_P=min(exp2(P), k);
                                ll k_last_nkc=K-k_nk;
                                ll e,b;
                                for(ll i=0; i<be.size(); ++i)
                                {
                                    b=be[i][0], e=be[i][1];
                                    currnkc[K][B][E]
                                    =
                                    (
                                    currnkc[K][B][E]
                                    +lastnkc[K-k][B][e] * nkc[P][k][b][E]
                                    )%mod;
                                }
                            }
                        }
                    }
                }
                swap(currnkc, lastnkc);
            }
            cout<<currnkc[IK];
        }
    }
};
int main( )
{

	freopen("inBBRICKS.txt","r",stdin);//redirects standard input
    ll T;cin>>T;

    /**
    BBRICKS().test();
    /**/
    BBRICKS(T).solve();
    /**/
	return 0;
}
