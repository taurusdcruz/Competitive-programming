
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
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)
#define ADJ(i1,i2,i3,delta,ad) ((i1==0 || i1% i3==0 )?SIGN(delta):ad)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
template <class T>
struct PT
{
	T x,y;
	PT() : x{0}, y{0} { }
	PT (T a, T b) : x{a}, y{b} { }
	bool operator < (PT<T> other) const { if (fabs(x - other.x) > EPS) return x < other.x; return y < other.y; }
public :
    void pp(PT<T> p)
    {
        cout<<p.x<<","<<p.y;
    }
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
        cout<<((i==0)?"":"\n")<<v[i].x<<","<<v[i].y;
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
			cout<<"\n       prnt function\n     ("<<p1.x<<","<<p1.y<<")\n       -to-\n      ("<<p2.x<<","<<p2.y<<")";//Debug
			PT< T> p;
			if(p1.x == p2.x)
            {
                k=p2.y-p1.y;
                ll c=SIGN(k);

                for(ll i=0; c*i<=c*k;i+=c)
                {

                    p.x=p1.x, p.y=p1.y+i;
                    res.push_back(p);
                    cout<<"\n       "<<p.x<<", "<<p.y;//Debug
                    no_points_remaining-=1;
                    if(no_points_remaining<=0) break;
                }
            }
            else if(p1.y==p2.y)
            {
                k=p2.x-p1.x;
                ll c=SIGN(k);

                for(ll i=0; c*i<= c*k;i+=c)
                {

                    p.x=p1.x+i, p.y=p1.y;
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
		NoElem2Prnt=72, cnt=NoElem2Prnt;
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

		cout<<"\n"<<coord[CORRECT(11, N)].x;

		cout<<"\nPolygon\n   "<<indx.ul<<"   "<<indx.ur;
		cout<<"\n"<<indx.lu<<"          "<<indx.ru;
		cout<<"\n"<<indx.ld<<"          "<<indx.rd;
		cout<<"\n   "<<indx.dl<<"   "<<indx.dr;




		ll delta_x=indx.rd -indx.ld,
		delta_y=indx.ul -indx.dl;

		cout<<"\n delta_x, delta_y"<<delta_x<<" "<<delta_y;


		traverse_along_x=(abs(delta_y) < abs(delta_x))?true:false;


		if(traverse_along_x)
		{
            //Scan line |
			ll max_no_indx_x_d=CORRECT(indx.rd -indx.ld, N);//max no of indexes to x traverse in d(clockwise)
			ll max_no_indx_x_u=CORRECT(indx.ru -indx.lu, N);//max no of indexes to  x traverse in u(anticlockwise)

			cout<<"\n"<<max_no_indx_x_d<<" "<<max_no_indx_x_u;


            ll indx_k_d=0, indx_k_u=0;//index of beginning point of curr segment
            ll delta_x_d, delta_x_u, delta_y_d, delta_y_u;//delta x of current segment
            ll x_actual=coord[indx.rd].x, y_actual_d, y_actual_u;//defining x_actual, and declaring others
            ll k_curr_seg_d=0, k_curr_seg_u=0;//amount to added to index to  get the k th point in current segment
            ll adjustment_d=0, adjustment_u=0,//adjustment due to rounding error
            c_d=0, c_u=0;// adjustment due to no rounding error


            bool flg_d=true, flg_u=true;//last point on segement
            bool NFT_d=false, NFT_u=false;//NOT first time entering loop
			while( x_actual> coord[indx.ld].x)
			{


			    if(flg_d) //down
                    {
                        cout<<"\n NEW SEG D";
                        if(NFT_d)indx_k_d=indx_k_d-1, k_curr_seg_d=0;

                        delta_x_d=coord[CORRECT(indx.rd +indx_k_d-1, N) ].x- coord[CORRECT(indx.rd +indx_k_d, N) ].x,//clockwise
                        delta_y_d=coord[CORRECT(indx.rd +indx_k_d-1, N) ].y- coord[CORRECT(indx.rd +indx_k_d, N) ].y;//clockwise

                        m.gcdd=abs(gcd(delta_x_d, delta_y_d)),
                        m.xd=delta_x_d/m.gcdd,
                        m.yd=delta_y_d/m.gcdd,
                        adjustment_d=(delta_y_d>=0 && delta_x_d <0)?+1:0;

                        cout<<"\n"<<
                        indx_k_d <<"\n"<<
                        k_curr_seg_d<<"\n"<<
                        delta_x_d<<"\n"<<
                        delta_y_d<<"\n"<<
                        m.gcdd<<"\n"<<
                        m.xd<<"\n"<<
                        m.yd<<"\n"<<
                        adjustment_d;

                        flg_d=false;
                    }
			    if(flg_u) //up
                    {
                        cout<<"\n NEW SEG U";
                        if(NFT_u) indx_k_u=indx_k_u+1, k_curr_seg_u=0;

                        delta_x_u=coord[CORRECT(indx.ru +indx_k_u+1, N) ].x- coord[CORRECT(indx.ru +indx_k_u, N) ].x,//anticlockwise
                        delta_y_u=coord[CORRECT(indx.ru +indx_k_u+1, N) ].y- coord[CORRECT(indx.ru +indx_k_u, N) ].y;//anticlockwise
                        //if(!NFT_u) k_curr_seg_u=SIGN(delta_x_u), NFT_u=true;//needs val of delta_x_u
                        m.gcdu=abs(gcd(delta_x_u, delta_y_u)),
                        m.xu=delta_x_u/m.gcdu,
                        m.yu=delta_y_u/m.gcdd,
                        adjustment_u=(delta_y_u<=0 && delta_x_u <0)?-1:0;

                        cout<<"\n"<<
                        indx_k_u <<"\n"<<
                        k_curr_seg_u<<"\n"<<
                        delta_x_u<<"\n"<<
                        delta_y_u<<"\n"<<
                        m.gcdu<<"\n"<<
                        m.xu<<"\n"<<
                        m.yu<<"\n"<<
                        adjustment_u;

                        flg_u=false;
                    }

                if(NFT_d && NFT_u)//skip so as to check if  first segment id not of unit length
                {

                c_d=(k_curr_seg_d==0 || k_curr_seg_d % m.xd ==0 )?(SIGN(delta_x_d) *(-1)):adjustment_d;
                c_u=(k_curr_seg_u==0 || k_curr_seg_u % m.xu ==0 )?SIGN(delta_x_u):adjustment_u;
			    y_actual_d= coord[CORRECT(indx.rd + indx_k_d, N)].y +((k_curr_seg_d)*(m.yd) )/m.xd +c_d;
			    y_actual_u= coord[CORRECT(indx.ru + indx_k_u, N)].y +((k_curr_seg_u)*(m.yu) )/m.xu +c_u;


                cout
                <<"\nbeginning point_d"<<coord[CORRECT(indx.rd + indx_k_d, N)].y
                <<"\ndelta_y_d(curr):"<<((k_curr_seg_d)*(m.yd) )/m.xd
			    <<"\nadjustment_d:"<<c_d
			    <<"\nbeginning point_u"<<coord[CORRECT(indx.ru + indx_k_u, N)].y
			    <<"\ndelta_y_u(curr):"<<((k_curr_seg_u)*(m.yu) )/m.xu
			    <<"\nadjustment_u:"<<c_u;

			    cout<<"y_actual_d<<\" \"<<y_actual_u"<<y_actual_d<<" "<<y_actual_u;

                PT<ll> p1(x_actual,y_actual_d),p2(x_actual,y_actual_u);
			    prnt<ll>(p1, p2, res, cnt);

			    if(cnt==0) {cout<<"\nHURRAY! cnt:"<<cnt;break;}
			    else cout<<"\n cnt:"<<cnt;

			    if(coord[CORRECT(indx.rd+indx_k_d, N) ].x-k_curr_seg_d != coord[CORRECT(indx.ru+indx_k_u, N) ].x+k_curr_seg_u) cout<<"\nSomething WRONG!";//Debug

                }
                else
                {
                    NFT_d=true, NFT_u=true;
                }

			    k_curr_seg_d+=SIGN(delta_x_d),k_curr_seg_u+=SIGN(delta_x_u), x_actual+=-1;
			    if(abs(k_curr_seg_d)>=abs(delta_x_d)) flg_d=true;
			    if(abs(k_curr_seg_u)>=abs(delta_x_u)) flg_u=true;
			}

		}
		else
		{
			//Scan line --------
			ll max_no_indx_y_l=CORRECT(indx.ul - indx.dl, N) ;//max no of indexes to y traverse in l(clockwise)
			ll max_no_indx_y_r=CORRECT(indx.ur -indx.dr, N) ;//max no of indexes to y traverse in r(anticlockwise)
			cout<<"\nmax_no_indx_y_l<<\" \"<<max_no_indx_y_r"<<max_no_indx_y_l<<" "<<max_no_indx_y_r;


            ll indx_k_l=0, indx_k_r=0;//index of beginning point of curr segment
            ll delta_x_l, delta_x_r, delta_y_l, delta_y_r;//delta x, delta y of current segment
            ll x_actual_l, x_actual_r, y_actual=coord[indx.dl].y;//defining y_actual and declaring others
            ll k_curr_seg_l=0, k_curr_seg_r=0;//amount to added to index to get the k th point in current segment basically delta y upto that point
            ll adjustment_l=0, adjustment_r=0,//adjustment due to rounding error
            c_l, c_r;// adjustment due to no rounding error



            bool flg_l=true, flg_r=true;//last point on segement
            bool NFT_l=false, NFT_r=false;//NOT first time entering loop
			while( y_actual < coord[indx.ul].y)
			{


			    if(flg_r) //down
                    {
                        cout<<"\n NEW SEG R";
                        if(NFT_r)indx_k_r=indx_k_r+1, k_curr_seg_r=0;
                        //else indx_k_r=0;
                        delta_x_r=coord[CORRECT(indx.dr +indx_k_r+1, N) ].x- coord[CORRECT(indx.dr +indx_k_r, N) ].x,//anticlockwise
                        delta_y_r=coord[CORRECT(indx.dr +indx_k_r+1, N) ].y- coord[CORRECT(indx.dr +indx_k_r, N) ].y;//anticlockwise
                        //if(!NFT_r) k_curr_seg_r=SIGN(delta_y_r), NFT_r=true;//needs val of delta_y_l
                        m.gcdr=abs(gcd(delta_x_r, delta_y_r)),
                        m.xr=delta_x_r/m.gcdr,
                        m.yr=delta_y_r/m.gcdr,
                        adjustment_r=(delta_x_r<=0 && delta_y_r >0)?-1:0;

                        cout<<"\n"<<
                        indx_k_r <<"\n"<<
                        k_curr_seg_r<<"\n"<<
                        delta_x_r<<"\n"<<
                        delta_y_r<<"\n"<<
                        m.gcdr<<"\n"<<
                        m.xr<<"\n"<<
                        m.yr<<"\n"<<
                        adjustment_r;

                        flg_r=false;
                    }
			    if(flg_l) //up
                    {
                        cout<<"\n NEW SEG L";
                        if(NFT_l)indx_k_l=indx_k_l-1, k_curr_seg_l=0;

                        delta_x_l=coord[CORRECT(indx.dl +indx_k_l-1, N) ].x- coord[CORRECT(indx.dl +indx_k_l, N) ].x,//clockwise
                        delta_y_l=coord[CORRECT(indx.dl +indx_k_l-1, N) ].y- coord[CORRECT(indx.dl +indx_k_l, N) ].y;//clockwise

                        m.gcdl=abs(gcd(delta_x_l, delta_y_l)),
                        m.xl=delta_x_l/m.gcdl,
                        m.yl=delta_y_l/m.gcdl,
                        adjustment_l=(delta_x_l>=0 && delta_y_l >0)?+1:0;
                        cout
                        <<"\n"<<indx_k_l
                        <<"\n"<<k_curr_seg_l
                        <<"\n"<<delta_x_l
                        <<"\n"<<delta_y_l
                        <<"\n"<<m.gcdl
                        <<"\n"<<m.xl
                        <<"\n"<<m.yl
                        <<"\n"<<adjustment_l;

                        flg_l=false;
                    }

                if(NFT_l && NFT_r)//skip so as to check if  first segment id not of unit length
                {



                c_r=(k_curr_seg_r==0 || k_curr_seg_r% m.yr ==0 )?SIGN(delta_y_r)*(-1):adjustment_r;
                c_l=(k_curr_seg_l==0 || k_curr_seg_l % m.yl ==0 )?(SIGN(delta_y_l)):adjustment_l;
			    x_actual_r= coord[CORRECT(indx.dr + indx_k_r, N)].x +((k_curr_seg_r)*(m.xr) )/m.yr +c_r;
			    x_actual_l= coord[CORRECT(indx.dl + indx_k_l, N)].x +((k_curr_seg_l)*(m.xl) )/m.yl +c_l;
                cout
                <<"\nbeginning point_r"<<coord[CORRECT(indx.dr + indx_k_r, N)].x
                <<"\ndelta_x_r(curr):"<<((k_curr_seg_r)*(m.xr) )/m.yr
			    <<"\nadjustment_r:"<<c_r
			    <<"\nbeginning point_l"<<coord[CORRECT(indx.dl + indx_k_l, N)].x
			    <<"\ndelta_x_l(curr):"<<((k_curr_seg_l)*(m.xl) )/m.yl
			    <<"\nadjustment_l:"<<c_l;



			    cout<<"\nx_actual_r <<\" \"<<x_actual_l"<<x_actual_r <<" "<<x_actual_l;

			    PT<ll> p1(x_actual_l,y_actual),p2(x_actual_r,y_actual);

			    prnt<ll>(p1, p2, res, cnt);
			    if(cnt==0) {cout<<"\nHURRAY! cnt:"<<cnt;break;}
			    else cout<<"\n cnt:"<<cnt;

			    if(coord[CORRECT(indx.dr+indx_k_r, N) ].y+k_curr_seg_r != coord[CORRECT(indx.dl+indx_k_l, N) ].y+k_curr_seg_l) cout<<"\nSomething WRONG!\n"<<coord[CORRECT(indx.dr+indx_k_r, N) ].y+k_curr_seg_r<<" !="<< coord[CORRECT(indx.dl+indx_k_l, N) ].y+k_curr_seg_l;//Debug

                }
                else
                {
                    NFT_l=true, NFT_r=true;
                }

			    k_curr_seg_r+=SIGN(delta_y_r),k_curr_seg_l+=SIGN(delta_y_l), y_actual+=1;
			    if(abs(k_curr_seg_l)>=abs(delta_y_l)) flg_l=true;
			    if(abs(k_curr_seg_r)>=abs(delta_y_r)) flg_r=true;


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

