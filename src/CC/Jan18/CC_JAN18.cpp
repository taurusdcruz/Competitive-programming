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


/*
//https://www.codechef.com/JAN18/problems/RECTANGL
int main()
{

    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    long long int T, a[4];
    string res;

    cin>>T;
    vector<long long int> va(4);
    rep(i1,0,T)
    {
        res="NO";
        cin>>a[0]>>a[1]>>a[2]>>a[3];
         //va.insert(va.begin(), a, a +4);
         copy ( a, a+4, va.begin() );
         sort(va.begin(), va.end());
         if(va[0]== va[1] && va[2]==va[3]) res="YES";
         //cout<<va[0]<< va[1]<<va[2]<<va[3];//Debug
         cout<<res<<((i1!=T-1)?"\n":"");

    }


    return 0;
}
*/

/*
//https://www.codechef.com/JAN18/problems/MAXSC

int main()
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    long long int T, N;

    cin>>T;

    rep(i1, 0, T)
    {
        cin>>N;

        vector< vector< long long int > > a(N, vector<long long int>(N));
        vector< vector<long long int> >::iterator row;
        vector<long long int>::iterator col;
        for (row = a.begin(); row != a.end(); row++)
            {
                for (col = row->begin(); col != row->end(); col++)
                {
                    cin>>*col;
                }
                sort(row->begin(), row->end());
                for (col = row->begin(); col != row->end(); col++)
                {
                    //cout<<*col<<((col == (row->end()-1)) ?"\n":" ");//Debug
                }

        }


        long long int prev_no=a[N-1][N-1], sum =prev_no;
        //cout<< "\n"<<prev_no<<"\n"; //Debug
        bool smaller_found=true;
        for(long long int ir=N-2; ir>=0 && smaller_found;ir--)
        {
            smaller_found=false;
            for(long long int ic=N-1; ic>=0;ic--)
            {
                if(a[ir][ic] < prev_no)
                    {
                        sum+=a[ir][ic]; prev_no=a[ir][ic] ;smaller_found=true;
                        //cout<<"\n" <<sum;//Debug
                        break;
                    }


            }


        }
        cout<<(smaller_found?sum:(-1))<<((i1<T-1)?"\n":"");

    }

}
*/

//https://www.codechef.com/JAN18/problems/KCON

int main()
{

    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    long long int T, N, N1, K,res[2];
    vector<long long int> a;


    cin>>T;

    for(long long int i1=0; i1< T; i1++)
    {

        long long int res_initialize[]={0,0};
        copy(res_initialize, res_initialize+2, res);
        cin>>N>>K;
        N1=N*K;
        a.resize(N);
        vector< vector <long long int > > sum(N1, vector<long long int >(N1,0));
        int k_is_1=0,k_isgreaterthan_1=1,begining_index=0,ending_index=1;
        rep(i11, 0, N)
        {
            cin>>a[i11];
            //cout<<a[i11]<<" ";//Debug
            sum[i11][i11]=a[i11];

           /* if(res[k_is_1]<a[i11]) res[k_is_1]=a[i11];*/
            if(res[k_isgreaterthan_1]<a[i11]) res[k_isgreaterthan_1]=a[i11];
        }
        rep(i14, N, N1)
        sum[i14][i14]=a[i14%N];

        //append one array and try to find the
        long long int ibeg, len=2, res_i[2][2];

        rep(i12,0,N1)
        {
             ibeg=i12;
             for(len=2;len<=N1 && (ibeg+ len -1 <N1);len++)
            {
                sum[ibeg][(ibeg + len-1)]= sum[ibeg][(ibeg+ len-2)]+a[(ibeg + len -1)%N];
                //if (sum[ibeg][(ibeg + len-1)]> 100) cout<<"\n error "<< sum[ibeg][(ibeg+ len-2)]<< " + "<<a[(ibeg + len -1)%N]<<" \n";//Debug
                if(  res[1] <  sum[ibeg][(ibeg + len-1)] )
                {
                    //only applicable for K>=2
                    res[k_isgreaterthan_1]= sum[ibeg][(ibeg + len-1)];
                    res_i[k_isgreaterthan_1][begining_index]=ibeg; res_i[k_isgreaterthan_1][ending_index]=(ibeg + len-1);
                }
               /* else  if(((ibeg + len-1) < N) && ( res[1] <  sum[ibeg][(ibeg + len-1)%N]  ))
                {
                    //applicable for K==1
                    res[k_is_1]= sum[ibeg][(ibeg + len-1)%N];
                    res_i[k_is_1][begining_index]=ibeg; res_i[k_is_1][ending_index]=(ibeg + len-1)%N;
                }
                */
            }
        }
        //cout<<"\n";//Debug
        //rep(i13,0,N1)rep(i131,0,N1) cout<<sum[i13][i131]<<((i131 <N1-1)?" ":((i13<N1-1)?"\n":""));//Debug

        /*if(K>=2 && sum[0][N-1] >0)
        {
            //find
        }
            res[1]+= (K-2) * sum[0][N-1];
        */
        //cout<<"\n res ";//Debug
        cout<</*(K==1)?res[k_is_1]:*/res[k_isgreaterthan_1]<<((i1<T-1)?"\n":"");






        //count overall sum
        //if <0 dont iterate further

    }
}
