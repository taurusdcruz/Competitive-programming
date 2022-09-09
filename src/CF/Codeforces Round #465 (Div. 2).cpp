/*
ID: taurus1
TASK: ride
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
//#include <bigInt.h>

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

const ll mod = 1000000000 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define MD(i) ((i) -(long long)(i))
//const LD EPS=1e-12;
//const LD INF=1e100;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
struct PT
{
    ll x,y;
    PT(): x{-1},y{0} {}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

bool update_nd_Pay(char mov, PT &p , bool &flgup)
{
    if(mov=='U')
        {
            //cout<<"\n      L";
            p.y+=1;
            if((p.x+1==p.y) && (!flgup)) {flgup =true; return true;}
            else {return false;}


    }
    if(mov=='R')
        {
             //cout<<"\n      R";
             p.x+=1;
             if((p.x==p.y+1) && (flgup)) {flgup =false;return true;}
             else {return false;}


    }

}


int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll n;
     cin>>n;
     string s;

     PT p;
     bool flgup=true;

     cin>>s;
     s.insert(0,"R");
     ll cnt=0;
     rep(i,0,s.size())
     {
        if(update_nd_Pay(s[i], p, flgup)) cnt+=1;
        //cout<<"\n   pt  "<<p.x<< " "<<p.y<<" "<<update_nd_Pay(s[i], p, flgup) <<" "<< cnt;
     }
     cout<<"\n"<<cnt-((s[1]=='R')?1:0);



	return 0 ;
}

