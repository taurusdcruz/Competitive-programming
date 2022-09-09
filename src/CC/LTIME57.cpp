
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
const ll MX =1000000000 +1;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
struct pp
{
    ll A, D;
    bool operator < (pp other) const { return A< other.A; }


};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

template <class T>
ll gcd(T a1, T b1) {

	T a=abs(a1), b=abs(b1);
	return b == 0 ? a : gcd(b, fmod(a, b));
}

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, N, K;
    vll  B;
    vector<pp> AD;





    cin>>T;
    rep(i,0,T)
    {
         cin>>N>>K;

         AD.resize(N);
         B.resize(K);
         rep(i,0,N) {cin>>AD[i].A;}
         rep(i,0,N) {cin>>AD[i].D;}
         rep(i,0,K) {cin>>B[i];}

         sort(AD.begin(),AD.end());

         tr(AD,i)
         {
             cout<<"\n  "<<(*i).A<<" "<<(*i).D;
         }


         ll l=0, r=N-1;
         ll k,j;
         rep(i,0,K)
         {
             if(i%2==0)
             {
                 //chef
                 cout<<"\n Chef l,r"<<l<<" "<<r;
                 k=B[i],
                 j=r;
                 while(1)
                 {
                     if(k-AD[j].D <0) {AD[j].D=k; l=j;break;}
                     else{ k-=AD[j].D; j+=-1;}
                 }
             }
             else
             {
                 //bro
                cout<<"\n Bro l,r"<<l<<" "<<r;
                k=B[i],
                 j=l;
                while(1)
                {
                 if(k-AD[j].D <0) {AD[j].D=k;r=j;break;}
                 else{k -=AD[j].D; j+=1;}


                }

             }
         }
         ll sm=0;
         rep(i,l,r+1)
         {
             sm+= AD[i].A*AD[i].D;
         }
         cout<<"\n"<<sm;

    }


	return 0 ;
}

