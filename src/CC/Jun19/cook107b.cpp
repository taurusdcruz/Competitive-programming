

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

void solve(){
    ll R,C;cin>>R>>C;
    ll cnt_meet=0;
    vector<vector<char>> grdd_init(R+2,vector<char>(C+2,'#'));//1-based
    vector<vector<char>> grdd(R+2,vector<char>(C+2,'#'));//1-based

    vector<vector<bool>> vis(R+2,vector<bool>(C+2,false));//1-based

    ll cnt_ants=0;
    char ch;
    map<char,pll> dir={ make_pair('U',pll(0,1))
                        ,make_pair('D',pll(0,-1))
                        ,make_pair('L',pll(-1,0))
                        ,make_pair('R',pll(1,0))
                    };
    for(ll ry=0+1;ry<R+1;++ry){
        for(ll cx=0+1;cx<C+1;++cx){
            cin>>ch;
            grdd[ry][cx]=ch;
            if(cpresent((vector<char>{'#','-'}),ch)){
                grdd_init[ry][cx]=ch;
            }
            auto flg1=cpresent((set<char>{'U','D','L','R'}),ch);
            if( flg1 ){
                    cnt_ants+=1;
                    vis[ry][cx]=true;//atmost one ant in one cell
            }
        }
    }
    while(true){
        if(cnt_ants<=0){
            break;
        }
        vector<vector<char>> grdd1(all(grdd_init));
        vector<vector<bool>> vis1(R+2,vector<bool>(C+2,false));//1-based

        for(ll ry=0+1;ry<R+1;++ry){
            for(ll cx=0+1;cx<C+1;++cx){
                auto [dx,dy]=dir[ch];
                ll  cx1=cx+dx
                ,   ry1=ry+dy;
                auto in_range=[](ll x){return x>0 && x<=50; };//1-based range checking
                //if blocked
                if( grdd[ry][cx]=='#'){
                    grdd1[ry][cx]=grdd[ry][cx];
                //else if ant
                }else if( cpresent((set<char>{'U','D','L','R'}),grdd[ry][cx])){
                    // if indices in grid
                    if( in_range(cx1) 
                        and in_range(ry1) 
                        ){
                        //if boulder not encountered
                        if(grdd[ry1][cx1]!='#'){
                            grdd1[ry1][cx1]=grdd[ry][cx];
                            //if current position two ants at same position -> res+=1
                            if(vis[ry1][cx1]){
                                cnt_meet+=1;
                            }else{
                                vis[ry1][cx1]=true;
                            }
                        //boulder encountered
                        }else{
                            //ant destroyed
                            cnt_ants+=-1;
                        }
                    //else if end of grid
                    }else{
                        //ant destroyed
                        cnt_ants+=-1;
                    }
                }
            }
        }
        //swap grdd and grdd1 (swapping the new grid state with the old grid state)
        swap(grdd,grdd1);
    }
    // print result
    cout<<cnt_meet<<endl;
}

int main(){
    char* custom_input=R"(
    10
    3 3
    R--
    ---
    --U
    1 4
    R--R
    2 2
    --
    --
    1 4
    R--L
    1 4
    -R-L
    1 4
    -R#L
    3 3
    R-D
    -#-
    R-U
    3 3
    R-D
    ---
    R#U
    3 3
    -D-
    R-L
    -U-
    1 7
    RLLLLLL
    )";    
    auto iss1=istringstream(custom_input);
    cin.rdbuf(iss1.rdbuf());
    ll T;cin>>T;
    for(ll t=0;t<T;++t){
        solve();
    }
    return 0;
}