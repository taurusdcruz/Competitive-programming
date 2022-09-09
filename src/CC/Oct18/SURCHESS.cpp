/*
ID: taurusd1
TASK: SURCHESS
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

class SURCHESS
{
    //By default data members are private
    //note: that order of assignment in the initializer list is the same as the order of declaration of the variables and
    // not the order of the variables in the initializer list of the constructor
    ll N,M;
    vector< vector<ll> > board;
    ll Q;
    vll vQ;

public:
    //constructor
    SURCHESS()
        :N
        (
             []()
             {
                 ll N;cin>>N;return N;
             }
             ()
         )
        ,M
        (
             []()
             {
                 ll M;cin>>M;return M;
             }
             ()
         )
        ,board
        (
            [&]()
             {
                vector< vector<ll> > board(N+1, vector<ll>(M+1));
                rep(i,1,N+1)
                {
                    rep(j,1,M+1)
                    {
                        char c;cin>>c;
                        board[i][j]=c-'0';

                    }
                }
                return board;
            }()
        )
        ,Q
        (
             []()
             {
                 ll Q;
                 cin>>Q;
                 return Q;
             }
             ()
         )
        ,vQ
        (
             [&]()
             {
                 vll vQ(Q);
                 rep(q,0,Q)
                 {
                     cin>>vQ[q];
                 }
                 return vQ;
             }
             ()
         )
        {
            /**
            debug2("",N,M)
            debug("",board)
            debug2("",Q,vQ)
            /**/
        };


    void test()
    {
        cout<<"Testing...\n";
    }
    void solve()
    {
        /*
        APPROACH:

        */
        //count flips upto given row col
        vector< vector<vector<ll> > >F(N+1, vector< vector<ll> >(M+1,vector<ll>(2,0LL)));//cnt flips Black(0,0)is black, White(0,0) is white

        ll WHT=0,BLK=1;
        for(ll row=1; row<N+1;++row)
        {
            vll col_flips={0,0};
            for(ll col=1; col<M+1; ++col)
            {
                ll cell=board[row][col];
                ll rc=row+col;
                ll rc2=(row+col)%2;

                col_flips[WHT]+= (cell==rc2)?(0):(1);
                col_flips[BLK]+=(cell==rc2)?(1):(0);

                F[row][col][WHT]= F[row-1][col][WHT]+col_flips[WHT];
                F[row][col][BLK]= F[row-1][col][BLK]+col_flips[BLK];
                /**
                debug4("---------\n",cell, rc,rc2,(cell==rc2)?(0):(1))
                debug2("",col_flips[WHT], col_flips[BLK])
                debug2("",F[row-1][col][WHT],F[row-1][col][BLK])
                debug2("",F[row][col][WHT], F[row][col][BLK])
                /**/
            }
        }
        auto print_sub=
        [&](ll _i, ll _j, ll __i,ll __j, ll _1,ll _2, ll _3)
        {
            cout<<"\nWHT ";
            cout<<"r1,c1,r2,c2"<<make_pair(_i,_j)<<make_pair(__i,__j)<<" \n";
            rep(i,_i,__i+1)
            {
                rep(j,_j,__j+1)
                {
                    string tf=(board[i][j]== ((i+j)%2))?("v/"):("X");
                    cout<<"( ";
                    if(_1) cout<<"CL:"<<board[i][j]<<" ";
                    if(_2) cout<<"F:"<<F[i][j][0]<<" ";
                    if(_3) cout<<""<<tf<<" ";
                    cout<<")";
                }
                cout<<endl;
            }
        };
        ll flips_bound=min(F[N][M][WHT], F[N][M][BLK]);
    // map flip to max possible grid size attainable with that many flips
        vector<vector<ll >> res
        (
            flips_bound+1
            ,vector<ll>(4,0)
        );

        for(ll row1=1;row1<N+1;++row1)
        {
            for(ll col1=1;col1<N+1;++col1)
            {
                for(ll len=0;len<min(N-row1,M-col1)+1; ++len)
                {
                    ll row2=row1+len;
                    ll col2=col1+len;

                    //print_sub(row1,col1,row2,col2,0,1,1);

                    ll delta_col=col2-col1+1;
                    ll flipz_WHT
                    =F[row2][col2][WHT]
                    -F[row2][col1-1][WHT]
                    -F[row1-1][col2][WHT]
                    +F[row1-1][col1-1][WHT]
                    ;
                    ll flipz_BLK
                    =F[row2][col2][BLK]
                    -F[row2][col1-1][BLK]
                    -F[row1-1][col2][BLK]
                    +F[row1-1][col1-1][BLK];

                    ll flipz=min(flipz_WHT,flipz_BLK); //flipz_min_black_white
                    ll cc=res[flipz][0];
                    if(cc<len+1)
                    {
                        /**
                        print_sub(row1,col1,row2,col2,0,1,1);
                        debug3("",flipz_WHT,flipz_BLK,flipz)
                        debug("initial--",res[flipz])
                        /**/
                        res[flipz]=vll{len+1,row1,col1,len+1};
                        /**
                        debug("updated--",res[flipz])
                        cout<<"\n_____________________\n";
                        /**/
                    }
                }
            }
        }
        /**
        debug("",flips_bound)
        debug("before updating",res)
        /**/
        rep(i,0,res.size())
        {
            if(i>0)
            {
                if(res[i][0]<res[i-1][0])
                {
                    res[i][0]=res[i-1][0];
                }
            }
        }
        /**
        debug("after updating --",res)
        /**/
        rep(q,0,Q)
        {
            ll c=vQ[q];
            /**
            debug("",c)cout<<" ";
            /**/
            cout<<((c>=flips_bound)?(min(N,M)):(res[c][0]))<<endl;
        }
    }
};

int main ( )
{
	freopen("inSURCHESS.txt","r",stdin);//redirects standard input
    /**
    SURCHESS().test();
    /**/
    SURCHESS().solve();
    /**/

	return 0;
}
