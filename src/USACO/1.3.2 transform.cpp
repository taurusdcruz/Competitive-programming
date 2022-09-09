/*
ID: taurusd1
TASK: transform
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
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
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
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

// Overloading << operator for vectors
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
        os << " " << *ii;
    }
    os << "]";
    return os;
}
template< class T=LD>
struct PT
{
    T x,y;
    public:
    PT(T _x, T _y): x(_x), y(_y) {}
    template<class U>
    PT<T> operator=(PT<U>& right)
    {
    this->x=right.x;
    this->y=right.y;
    return *this;
    }
};
template< class T >
ostream&  operator<<(ostream& out,const PT<T>& pt)
{
  out<<"( "<<pt.x<<", "<<pt.y<<") ";
  return out;
}



int main ( )
{
	freopen("transform.in","r",stdin);//redirects standard input
	freopen("transform.out","w",stdout);//redirects standard output
	ll N;
	cin>>N;
	vector< vector< char > > p(N, vector<char>(N,'x')), p1(all(p)), tp(all(p));
	rep(i,0,N)
	{
	    rep(j,0,N)
	    {
	        cin>>p[i][j];
	    }
	}
	rep(i,0,N)
	{
	    rep(j,0,N)
	    {
	        cin>>p1[i][j];
	    }
	}
	//debug2("",p,p1);
	/*
    #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
    #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
    #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
    #4: Reflection: The pattern was reflected horizontally i.e. using horizontal rays (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
    #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
    #6: No Change: The original pattern was not changed.
    #7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
    */


    auto rott=
    [](complex<LD> complex_no, LD theeta)/*Function to rotate a complex_no by theeta radians clockwise*/
    {
        return complex<LD>(cos(-theeta), sin(-theeta) ) *complex_no; // ans= e^(-i(theeta)) *(complex_no)
    };
    auto cround=
    [](complex<LD> complex_no)
    {
        return complex<LD>(round(real(complex_no)), round(imag(complex_no)));
    };
    vector<bool> flg{1,1,1,1,1,1,1};
    LD d=((LD)N)/2.0;
    LD theeta=0;
    rep(k,0,3)
    {
        theeta+=(LD)(PI/2.0);
        //debug("" , cos(theeta))
        rep(i,0,N)
        {
            rep(j,0,N)
            {
                auto s1p=complex<LD>(i-d+0.5,j-d+0.5);
                auto rp=rott(s1p,theeta);//rotated point  + shifted
                auto s2p=rp+ +complex<LD>(d-0.5,d-0.5);
                auto rdp=cround(s2p);//rounded rp
                ll x_=real(rdp), y_=imag(rdp);
                //debug4("",s1p,rp,s2p,rdp)
                //debug2("",p[i][j], p1[x_][y_] )
                if(p[i][j]!=p1[x_][y_]) {flg[k]=0;i=j=N;}
            }
        }
    }
    tp=p;
    //reflecting matrix t about middle vertical column
    rep(cl,0,N/2)
    {
        rep(rw,0,N)
        {

            swap(tp[rw][cl],tp[rw][N-1-cl]);
        }
    }
    //debug("after reflecting", tp)
    if(tp!=p1) flg[3]=0;

    //Rotating reflected matrix
    vector<bool> tflg(3,true);
    theeta=0.0;
    rep(k,0,3)
    {
        theeta+=(LD)(PI/2.0);
        //debug("" , cos(theeta))
        rep(i,0,N)
        {
            rep(j,0,N)
            {
                auto s1p=complex<LD>(i-d+0.5,j-d+0.5);
                auto rp=rott(s1p,theeta);//rotated point  + shifted
                auto s2p=rp+ +complex<LD>(d-0.5,d-0.5);
                auto rdp=cround(s2p);//rounded rp
                ll x_=real(rdp), y_=imag(rdp);
                //debug4("",s1p,rp,s2p,rdp)
                //debug2("",tp[i][j], p1[x_][y_] )
                if(tp[i][j]!=p1[x_][y_]) {tflg[k]=0;i=j=N;}
            }
        }
    }
    flg[4]=tflg[0] || tflg[1] || tflg[2];

    if(p!=p1) flg[5]=0;

    rep(i,0,6) if(flg[i]) {flg[6]=0;break;}

    //debug("", flg)
    rep(i,0,7) if(flg[i]) {cout<<i+1<<endl;return 0;}

	return 0;
}

