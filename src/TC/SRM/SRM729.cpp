
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
const LD EPS=1e-12;
const LD INF=1e100;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
template <class T>
struct PT
{
	T x,y;
	PT() : x{0}, y{0} { }
	PT (T a, T b) : x{a}, y{b} { }
	bool operator < (PT<T> other) const { if (fabs(x - other.x) > EPS) return x < other.x; return y < other.y; }
};

struct indexes
{
	//u-up,d-down,l-left,r-right
	ll ul,ur,dl,dr,lu,ld,ru,rd;

};

struct slope
{
    ll xu,yu,xd,yd,xl,yl,xr,yr,gcdu,gcdd,gcdl,gcdr;
};

struct direction_vertical
{
    ll u,d;
};
struct direction_horizontal
{
    ll l,r;
};

template <class T>
struct CONCAVEPOLY
{
    vector<PT<T> > vertex;
    T ul,ur,dl,dr,lu,ld,ru,rd;

    void print_vertices();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

template <class T>
int gcd(T a1, T b1) {
	ll a=(ll)a1,b=(ll)b1;
	a=abs(a), b=abs(b);
	return b == 0 ? a : gcd(b, a % b);
}

template <class T>
prnt_points( vector<PT<T> > v )
{
    for(ll i=0; i < v.size(); i++)
    {
        cout<<((i==0)?"\n":" ")<<v[i].x<<","<<v[i].y;
    }
}

template <class T>
void fill_points( PT<T> p1, PT<T> p2, vector<PT<T> >& res)
{
    ll k=abs( p2.x - p1.x ),
    gcd_slope= abs(gcd( (p2.x - p1.x) , (p2.y - p1.y))),
    slope_x= (p2.x - p1.x )/gcd_slope, slope_y=(p2.y -p1.y)/gcd_slope;
    ll slope_int=slope_y/slope_x, slope_rem=slope_y%slope_x,
     x_incrd=0.0, y_incrd;
     res.push_back(p1);
    for(LD i=0.0;i<k-2;i++)
    {
        x_incrd+=1.0;//
        y_incrd=x_incrd *slope_int +(x_incrd* slope_rem)/(slope_x);//
        PT<T> p {p1.x+x_incrd , p1.y +y_incrd };
        res.push_back(p);
    }



}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template < class T>
void prnt(PT<T>& p1, PT<T>& p2,vector< PT<T> > &res, ll & no_points_remaining)
		{
            //p2 > p1
			ll k=0;
			cout<<"\n       prnt function\n     ("<<p1.x<<","<<p1.y<<")-to-("<<p2.x<<","<<p2.y<<")";//Debug
			PT< T> p;
			if(p1.x == p2.x)
            {
                k= abs(p2.y -p1.y);
                rep(i,0,k+1)
                {

                    p.x=p2.x, p.y=p2.y-k;
                    res.push_back(p);
                    cout<<"\n       "<<p.x<<", "<<p.y;//Debug
                    no_points_remaining-=1;
                    if(no_points_remaining<=0) break;
                }
            }
            else if(p1.y==p2.y)
            {
                k=abs(p1.x-p2.x);
                rep(i,0,k+1)
                {

                    p.x=p2.x-k, p.y=p2.y;
                    res.push_back(p);
                    cout<<"\n       "<<p.x<<", "<<p.y;//Debug
                    no_points_remaining-=1;
                    if(no_points_remaining<=0) break;
                }

            }


		}


int main ( )
{
	freopen("inPOINPOLY.txt","r",stdin);//redirects standard input
	//freopen("out.txt","w",stdout);//redirects standard output


	ll T, N, NoElem2Prnt, cnt;
	vector<PT<ll> > coord,
	res;

	map<ll, direction_vertical> jrsdctn_x; // x, d_indx, u_indx
	map<ll, direction_horizontal> jrsdctn_y;// y, l_indx, r_indx


	indexes indx;
	bool traverse_along_x;
	slope m;


	cin>> T;
	//cout<<T;//Debug

	rep(i1, 0, T)
	{
		cin>>N;
		//cout<<"\n"<<N;//Debug
		NoElem2Prnt=N/10, cnt=NoElem2Prnt;
		coord.resize(N);
		cin>>coord[0].x>>coord[0].y;



		rep(i,1,N+1)
		{
			if(i<N)cin>>coord[i].x>>coord[i].y;



			ll i0=i%N, i1=(i-1)%N;
			ll kx=coord[i0].x-coord[i1].x;
			ll ky=coord[i0].y-coord[i1].y;
			bool  flgkx=coord[i0].x >coord[i1].x;
			bool flgky=coord[i0].y >coord[i1].y;
			cout<<"\n   coordinate begin:"<<coord[i1].x<<" "<<coord[i1].y;
            cout<<"\n   coordinate end   :"<<coord[i0].x<<" "<<coord[i0].y;
			cout<<"\n   kx,ky:"<<kx<<" "<<ky;


			for(ll k=0;flgkx?k<=kx:k>=kx ; k+=flgkx?1:-1)
			{

			    if(kx>0)
			    jrsdctn_x[coord[i1].x+k].d=i1;// storing index of initial vertex of line segments in d
			    else if(kx<0)
                jrsdctn_x[coord[i1].x+k].u=i1;// storing index of initial vertex of line segments in u
                else
                {
                    //do nothing
                }

			    auto i= jrsdctn_x.find(coord[i1].x+k);
			    cout<<"\n   x"<< i->first<<" "<< i->second.d<<" "<<i->second.u;

			}
			for(ll k=0; flgky?k<=ky:k>=ky; k+=flgky?1:-1)
			{
			    if(ky>0)
			    jrsdctn_y[coord[i1].y+k].r=i1;// storing index of initial vertex of line segments in r
			    else if(ky<0)
                jrsdctn_y[coord[i1].y+k].l=i1;// storing index of initial vertex of line segments in l
                else
                {
                    //do nothing
                }
			    auto i= jrsdctn_y.find(coord[i1].y+k);
			    cout<<"\n   y"<< i->first<<" "<< i->second.l<<" "<<i->second.r;
			}
			cout<<"\nINDEX"<<i0;

			cout<<"\nPRINTINGjrsdctn_x";

			rep(j,0,3) tr(jrsdctn_x,i) {bool flg= (i==jrsdctn_x.begin());if(flg) cout<< "\n"<<(j==0?"x":j==1?"d":"u") ; cout<<j==0? i->first :j==1? i->second.d :i->second.u;}

            cout<<"\nPRINTINGjrsdctn_y";
            rep(j,0,3) tr(jrsdctn_y,i) {bool flg= (i==jrsdctn_y.begin());if(flg) cout<<"\n"<<(j==0?"y":j==1?"r":"l") ; cout<<j==0? i->first :j==1? i->second.r :i->second.l;}




			if(kx ==0 )  if(ky>0) indx.ru=i0, indx.rd=i1; else indx.ld=i0, indx.lu=i1;
			if(ky ==0 )  if(kx>0) indx.dr=i0, indx.dl=i1; else indx.ul=i0, indx.ur=i1;



		}


		ll delta_x=indx.rd -indx.ld,
		delta_y=indx.ul -indx.dl;

		cout<<"\n delta_x, delta_y"<<delta_x<<" "<<delta_y;


		traverse_along_x=(abs(delta_y) > abs(delta_x))?true:false;


		if(traverse_along_x)
		{

			ll max_no_indx_x_d=indx.rd -indx.ld;//max no of indexes to x traverse in d(anticlockwise)
			ll max_no_indx_x_u=indx.ru -indx.lu;//max no of indexes to  x traverse in u(clockwise)

			cout<<"\n"<<max_no_indx_x_d<<" "<<max_no_indx_x_u;


            ll indx_k_d=0, indx_k_u=0;//index of beginning point of curr segment
            ll delta_x_d, delta_x_u, delta_y_d, delta_y_u;//delta x of current segment
            ll x_actual=coord[indx.rd].x-1, y_actual_d, y_actual_u;
            ll k_curr_seg_d=0, k_curr_seg_u=0;//k th point in current segment
            ll adjustment_d=0, adjustment_u=0;


            bool flg_d=true, flg_u=true;//last point on segement
			while( indx_k_d<=abs(max_no_indx_x_d)  && indx_k_u <=abs(max_no_indx_x_u))
			{
			    if(k_curr_seg_d>=delta_x_d) flg_d=true;
			    if(k_curr_seg_u>=delta_x_u) flg_u=true;

			    if(flg_d) //down
                    {
                        indx_k_d-=1, k_curr_seg_d=0,
                        delta_x_d=coord[indx.rd -indx_k_d-1].x- coord[indx.rd -indx_k_d].x,//anticlockwise
                        delta_y_d=coord[indx.rd -indx_k_d-1].y- coord[indx.rd -indx_k_d].y,//anticlockwise
                        m.gcdd=abs(gcd(delta_x_d, delta_y_d)),
                        m.xd=delta_x_d/m.gcdd,
                        m.yd=delta_y_d/m.gcdd;
                        adjustment_d=(delta_y_d>=0 && delta_x_d >0)?+1:0;

                        flg_d=false;
                    }
			    if(flg_u) //up
                    {
                        indx_k_u+=1, k_curr_seg_u=0,
                        delta_x_u=coord[indx.ru +indx_k_u+1].x- coord[indx.ru +indx_k_u].x,//clockwise
                        delta_y_u=coord[indx.ru +indx_k_u+1].y- coord[indx.ru +indx_k_u].y,//clockwise
                        m.gcdu=abs(gcd(delta_x_u, delta_y_u)),
                        m.xu=delta_x_u/m.gcdu,
                        m.yu=delta_y_u/m.gcdd;
                        adjustment_u=(delta_y_u<=0 && delta_x_u >0)?-1:0;

                        flg_u=false;
                    }

			    y_actual_d= coord[indx_k_d].y +((-1)*(k_curr_seg_d)*(m.yd) )/m.xd +adjustment_d;
			    y_actual_u= coord[indx_k_u].y +((k_curr_seg_u)*(m.yu) )/m.xu +adjustment_u;

			    cout<<"y_actual_d<<\" \"<<y_actual_u"<<y_actual_d<<" "<<y_actual_u;

                PT<ll> p1(x_actual,y_actual_d),p2(x_actual,y_actual_u);
			    prnt<ll>(p1, p2, res, cnt);
			    if(cnt==0) break;

			    if(coord[indx.rd-indx_k_d].x-k_curr_seg_d != coord[indx.ru+indx_k_u].x+k_curr_seg_u) cout<<"\nSomething WRONG!";//Debug

			    k_curr_seg_d+=1,k_curr_seg_u+=1, x_actual-=1;
			}

		}
		else
		{
			ll max_no_indx_y_l=indx.ul    - indx.dl;//max no of indexes to y traverse in l(anticlockwise)
			ll max_no_indx_y_r=indx.ur -indx.dr  ;//max no of indexes to y traverse in r(clockwise
			cout<<"\n"<<max_no_indx_y_l<<" "<<max_no_indx_y_r;


            ll indx_k_l=0, indx_k_r=0;//index of beginning point of curr segment
            ll delta_x_l, delta_x_r, delta_y_l, delta_y_r;//delta x, delta y of current segment
            ll x_actual_l, x_actual_r, y_actual;
            ll k_curr_seg_l=0, k_curr_seg_r=0;//k th point in current segment
            ll adjustment_l=0, adjustment_r=0;


            bool flg_l=true, flg_r=true;//last point on segement
			while( indx_k_l<=abs(max_no_indx_y_l)  && indx_k_r <=abs(max_no_indx_y_r))
			{
			    if(k_curr_seg_l>=delta_y_l) flg_l=true;
			    if(k_curr_seg_r>=delta_y_r) flg_r=true;

			    if(flg_r) //down
                    {
                        indx_k_r+=1, k_curr_seg_r=0,
                        delta_x_r=coord[indx.dr +indx_k_r+1].x- coord[indx.rd +indx_k_r].x,//anticlockwise
                        delta_y_r=coord[indx.rd +indx_k_r+1].y- coord[indx.rd +indx_k_r].y,//anticlockwise
                        m.gcdr=abs(gcd(delta_x_r, delta_y_r)),
                        m.xr=delta_x_r/m.gcdr,
                        m.yr=delta_y_r/m.gcdr;
                        adjustment_r=(delta_x_r<=0 && delta_y_r <0)?-1:0;

                        flg_r=false;
                    }
			    if(flg_l) //up
                    {
                        indx_k_l-=1, k_curr_seg_l=0,
                        delta_x_l=coord[indx.dl -indx_k_l-1].x- coord[indx.dl -indx_k_l].x,//clockwise
                        delta_y_l=coord[indx.dl -indx_k_l-1].y- coord[indx.dl -indx_k_l].y,//clockwise
                        m.gcdl=abs(gcd(delta_x_l, delta_y_l)),
                        m.xl=delta_x_l/m.gcdl,
                        m.yl=delta_y_l/m.gcdl;
                        adjustment_l=(delta_x_l>=0 && delta_y_l >0)?+1:0;

                        flg_l=false;
                    }

			    x_actual_r= coord[indx_k_r].x +((k_curr_seg_r)*(m.xr) )/m.yr +adjustment_r;
			    x_actual_l= coord[indx_k_l].x +((-1)*(k_curr_seg_l)*(m.xl) )/m.yl +adjustment_l;

			    cout<<"\nx_actual_r <<\" \"<<x_actual_l"<<x_actual_r <<" "<<x_actual_l;

			    PT<ll> p1(x_actual_l,y_actual),p2(x_actual_r,y_actual);
			    prnt<ll>(p1, p2, res, cnt);
			    if(cnt==0) break;

			    if(coord[indx.dr+indx_k_r].y+k_curr_seg_r != coord[indx.dl-indx_k_l].y-k_curr_seg_l) cout<<"\nSomething WRONG!";//Debug

			    k_curr_seg_r+=1,k_curr_seg_l+=1, y_actual+=1;

			}


		}
		if(cnt>0)
        {
            cout<<"\n"<<"-1";
        }
        else
        {
            prnt_points<ll>(res);
        }

	}
	return 0 ;
}

