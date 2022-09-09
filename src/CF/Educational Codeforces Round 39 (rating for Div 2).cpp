
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
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //structures
template< class T, class U >
 bool operator<(const pair<T,U>& a, const pair<T,U>& b)
{
  if (a.first < b.first) return true;
  else if ( (a.first == b.first) && (a.second < b.second) ) return true;
  else return false;
}

template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  //out<<"( "<<a.first<<", "<<a.second<<") ";
  out<<a.first<<" ";
  return out;
}
template< class T, class U >
bool  operator==(const pair<T,U>& a,const pair<T,U>& b)
{
  return (a.first==b.first && a.second==b.second);
}




    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Functions

    //check bound correct
    template<class T>
    T cbc(T i,T l,T r)
    {
        T d=i+(i<l)?-l:((i>r)?-r:0);
        return d;
    }
    int main ( )
    {
        freopen("in.txt","r",stdin);//redirects standard input
        //freopen("out.txt","w",stdout);//redirects standard output
        ll n, m, k;
        cin>>n>>m>>k;
        vector< vector<char> > wk(n, vector<char>(m,'.'));
        //vector of pairs val, indx
        vector< pair<ll, pair<ll,ll> > > spc;

        //count before, count after
        ll cb=0,lstcb=0;
        //total hours
        ll thr=0;
        pair<ll, pair<ll,ll> > tmp;

        //index of 1's , periods freed  on removing  the index
        vector< pair<ll,ll> > io1(n);
        vector< ll > io2(n);
         rep(in,0,n)
        {
            rep(im,0,m)
            {
                cin>>wk[in][im];
                if(wk[in][im]=='1')
                {
                    io1.push_back(pair<ll,ll>(in,im));
                    io2.push_back(in*m + im);
                }
            }
        }


        tr(io1,i)
        {
            ll row=(*i).first;
            while(same_row)
            {
                if((i== io1 .begin() || (*i).first != (*(i -1)).first) && (i+1).first != (io) .end())
                {
                    tmp.first= *(j+1) - *j ;
                    tmp.second.first=row;
                    tmp.second.second=*j;
                    thr=tmp.first;
                    spc.push_back(tmp);
                    cout
                    <<"\nbeg"
                    <<"("
                    <<*(j+1)
                    <<"-"
                    <<0
                    <<")"
                    ;
                }
                else if( j== (*i) .end() -1)
                {
                    tmp.first=*j - *(j-1);
                    tmp.second.first=row;
                    tmp.second.second=*j;
                    thr=tmp.first;
                    spc.push_back(tmp);
                    cout
                    <<"\nend"
                    <<"("
                    <<m-1
                    <<"-"
                    <<*(j-1)
                    <<")"
                    ;
                }
                else if(j!= (*i) .begin() )
                {
                    tmp.first=*(j+1) - *(j-1) -1;
                    tmp.second.first=row;
                    tmp.second.second=*j;
                    thr=tmp.first;
                    spc.push_back(tmp);
                    cout
                    <<"\nmid"
                    <<"("
                    <<*(j+1)
                    <<"-"
                    <<*(j-1)
                    <<")"
                    ;
                }
            }
        }


        cout<<"\n";
        tr(wk,i)
        {
            cout<<"\n";
            tr(*i,j)
            {
                cout
                <<((*j=='1')?" 1":" 0");
            }


        }


        cout<<"\n";
        tr(io1,i)
        {
            cout<<"\n";
            tr(*i,j)
            {
                cout
                <<" "
                <<*j;
            }


        }




        cout<<"\n";
        print(spc);
        sort(spc.begin(), spc.end());

        cout<<"\n";
        print(spc);

        ll bunked_classes=0;
        trr(spc,ri)
        {
            if(bunked_classes>=k) break;
            else
            {
                thr+=-((*ri).first);
                bunked_classes+=1;
            }
        }


        cout
        <<"\nRes"
        <<thr;

        return 0 ;
    }

