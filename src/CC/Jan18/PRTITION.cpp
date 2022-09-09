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

template<class T> T abs(T x) { return x > 0 ? x : -x;}

const ll mod = 1000000000 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)

#define INV1(i) ( a[i]==1)? 0:1)
#define INV_a(i)  a[i] =( (a[i]==1)? 0:((a[i]==0)?1:a[i]) )



void solve( vll a, ll x, ll N){


        ll m= (N- (N%4)) /4, z=(x-(x%2))/2, so=0, se=0, diff;
        bool possible;







        //initializing : partition into odd and even
        /*
        for(ll i=1; i<=N; i++)//Debug
        {
            (i==1)?cout<<"\n" :cout<<" ";//Debug
            cout<<i;//Debug
        }
        */

        for(ll i=1; i<=N; i++)
        {
            a[i]= (i)%2;



            if(i==x) a[i]=2;

            //(i==1)?cout<<"\n" :cout<<" ";//Debug
            //cout<<a[i];//Debug

            //(i!=x)?((a[i]==0)?se+=i:so+=i) : se+=0 ;//Debug
            //(i==N)? cout <<"  se "<<se<<", so"<<so : cout<<"";//Debug//initial values of se and so

            //(i==N)?((se>so)?diff=se-so:diff=so-se):diff=diff;//Debug
            //(i==N)?se=0,so=0:se=se;//Debug

        }

        //Solving

        if(x%2==0 )
        {
            if(N%4==3)
            {
                possible=true;
                //cout<<"\nbk3";//Debug
                //cout<<"\n m ,z "<< m<<", "<<z<<" diff "<<diff<<" predicted (2z +2m +2) "<<(2*z + 2*m + 2);//Debug
                if((m+z+1) %2 !=0)
                {
                    INV_a(m+z+1);
                }
                else
                {
                    INV_a(m+z);
                    INV_a(1);
                }

            }
            else if(N%4==0)
            {
                possible=true;
                //cout<<"\nbk0";//Debug
                //cout<<"\n m ,z "<< m<<", "<<z<<" diff "<<diff<<" predicted (2z-2m) "<<(2*z - 2*m);//Debug
                if(z >=1 && z <m)
                {
                    for(ll i= (2*m+2*z +1);i<= (4*m ); i++)
                    {
                        INV_a(i);
                    }
                }
                else if(m<=z && z<=2*m)
                {
                    for(ll i= (2);i<= (2*z - 2*m +1); i++)
                    {
                        INV_a(i);
                    }
                }
            }
            else
            {
                //impossible
                possible=false;
            }
        }
        else if(x%2 ==1)
        {
            if(N%4==1)
            {
                possible=true;
                //cout<<"\nbk1";//Debug
                //cout<<"\n m ,z "<< m<<", "<<z<<" diff "<<diff<<" predicted (2z-2m) "<<(2*z - 2*m);//Debug
                if(z >=0 && z <m)
                {
                    //cout<<"\n mov "<< (2*m+2*z +2) <<" to "<<(4*m +1)<<" in opp set";//Debug
                    for(ll i= (2*m+2*z +2);i<= (4*m +1); i++)
                    {
                        INV_a(i);
                    }
                }
                else if(m<z && z<= 2*m)
                {
                    //cout<<"\n mov "<< (1) <<" to "<<(2*z - 2*m)<<" in opp set";//Debug
                    for(ll i= (1);i<= (2*z - 2*m); i++)
                    {
                        INV_a(i);
                    }
                }

            }
            else if(N%4==2)
            {
                possible=true;
                //cout<<"\nbk2";//Debug
                //cout<<"\n m ,z "<< m<<", "<<z<<" diff "<<diff<<" predicted (2z +2m +2) "<<(2*z + 2*m + 2);//Debug
                if(m%2 ==0)
                {
                    if(z%2 ==0)
                    {
                        //cout<<" sub bk0";//Debug
                        (x==1)? INV_a(m+z+2), INV_a(2), INV_a(3) :INV_a(m+z+2), INV_a(1);
                    }
                    else
                    {
                        INV_a(m+z+1);
                    }
                }
                else
                {
                    if(z%2 !=0)
                    {
                        //cout<<"sub bk1";//Debug
                        (x==1)? INV_a(m+z+2), INV_a(2), INV_a(3) : INV_a(m+z+2), INV_a(1);
                    }
                    else
                    {
                        INV_a(m+z+1);
                    }
                }


            }
            else
            {
                //impossible
                possible= false;
            }
        }



        //print
        a[x]=2;
        if(N<=3) possible=false;
        if(possible)

        for( ll i=1; i<=N; i++)
            {

                //cout<<((i>=1)?"\n ":"");//Debug
                cout<<a[i];
                //(i!=x)?((a[i]==0)?se+=i:so+=i) : se+=0 ;//Debug
                //if(i==N)
                //cout <<" se "<<se<<", so"<<so;//Debug
            }

        else
        cout<<"impossible";


    }



int main()
{
    freopen("inPRTITION.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, x, N;
    vll a;


    cin>>T;

    for(ll i1=0; i1< T && (cin>>x>>N); i1++)
    {

        cin>>x>>N;
        a.resize(N+1);
        a[0]=0;
        solve(a, x, N);
        cout << ((i1<T-1)?"\n":"");
    }
    return 0;
}
