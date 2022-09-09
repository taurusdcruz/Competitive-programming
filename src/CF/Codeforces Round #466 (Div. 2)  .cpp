
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
   ll n, d;
   ll diff;
   cin>> n>>d;
   vll a(n);
   vll flg(n,0);


   rep(i,0,n)
   {
       cin>>a[i];
   }
   sort(a.begin(),a.end());
   diff=a[n-1]-a[0];
   ll i=0,j=n-1;
   ll cnt=0;

   while(diff>d && i+1<=j-1)
   {
       ll dl=a[i+1]-a[i] , dr=a[j] -a[j-1];
       if(dl< dr)
       {
           diff-= dr;

           //if(flg[i]==1) cout<<"BS j"<<j;
           flg[j]=1;

           j-=1;
           cnt+=1;

       }
       else if(a[i+1]-a[i] > a[j] -a[j-1])
       {
           diff-=dl;
           //if(flg[i]==1) cout<<"BS i"<<i;
           flg[i]=1;
           i+=1;
           cnt+=1;
       }
       else if(dl==dr)
       {
           ll suml=0, sumr=0, tmpcnt=0, c;
           while(a[i+1]-a[i] !=a[j] -a[j-1])
           {
              c=a[i+1]-a[i] ;
              suml+=c;
               tmpcnt+=1;
              if(diff-suml-sumr<=d) { diff+=-suml-sumr; cnt+=2*tmpcnt-1; break;}
              flg[i]=1;
              sumr+=c;
              if(diff-suml-sumr <=d) { diff+=-suml-sumr; cnt+=2*tmpcnt; break;}
              flg[j]=1;

              i+=1, j-=1;

           }


       }
   }

   cout<< cnt;
   tr(flg,ii)
   {
       if(ii== flg.begin())
       cout<<"\n";
       cout<<" "<<(*ii);
   }




	return 0 ;
}

