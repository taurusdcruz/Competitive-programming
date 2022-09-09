
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

template < class T>
ostream& operator << (ostream& os, const list<T>& lst)
{
    os << "lst:[";
    for (auto ii = lst.begin(); ii != lst.end(); ++ii)
    {
        os << "\n" << *ii;
    }
    os << "]";
    return os;
}

template < class T,class cmp=less<T>>
ostream& operator << (ostream& os, const set<T,cmp>& st)
{
    os << "St:{";
    for (auto ii = st.begin(); ii != st.end(); ++ii)
    {
        os << "\n" << *ii;
    }
    os << "}";
    return os;
}

class Node1{

    public:


    ll indx;
    ll val;
    
    Node1(ll _indx,ll _val)
        :indx(_indx)
        ,val(_val)
        {
    };  
    // Below constructor is not possible as  references have to be bound to target object immediately
    Node1()
        :indx()
        ,val(){
    };

    Node1(Node1& rhs)
        :indx(rhs.indx)
        ,val(rhs.val){
    };

    Node1& operator=(Node1& rhs){
        this->indx=rhs.indx;
        this->val=rhs.val;
        return *this;
    }

    //get next iterator in a circular manner                                     
    friend list<Node1*>::iterator cir_next( list<Node1*>::iterator it_begin
                                    ,list<Node1*>::iterator it_end
                                    ,list<Node1*>::iterator& it  ){
        auto it_nxt=next(it,1);                                   
        if( it_nxt!=it_end ) return it_nxt;
        return it_begin;
    }
    //get next iterator in a circular manner                                     
    friend list<Node1*>::iterator cir_prev( list<Node1*>::iterator it_begin
                                    ,list<Node1*>::iterator it_end
                                    ,list<Node1*>::iterator& it  ){
        auto it_prev=it;                                   
        if( it!=it_begin ) it_prev=prev(it,1);
        return prev(it_end,1);
    }
    friend ll g_val(Node1* nd_ptr){
        return g_val(*nd_ptr);
    }
    friend ll g_val(Node1& nd){
        return nd.val;
    }
    friend ll g_indx(Node1* nd_ptr){
        return g_indx(*nd_ptr);
    }
    friend ll g_indx(Node1& nd){
        return nd.indx;
    }
    //Overriding << operator for Node1&
    friend ostream&  operator<<(ostream& out,const Node1& obj){     
        out<<"( "<<obj.indx<<", "<<obj.val<<")";
        return out;
    }

    //Overriding << operator for Node1*
    friend ostream&  operator<<(ostream& out,const Node1* obj_ptr){
        out<<(*obj_ptr);
        return out;
    }
};
void solve(){
    ll N;cin>>N;
    vll vA(N);for(ll i=0;i<N;++i){ cin>>vA[i];}
    ll min_penalty=0;
    vll vi2ni(N,-1);
    vll vi2pi(N,-1);
    //custom compare function to sort based on sum of consecutive values in ascending order
    auto cmp_lesser
        =[&](
            Node1* lptr, Node1* rptr 
        ){  
            auto li=lptr->indx;
            auto ri=rptr->indx;
            auto nxt_li=vi2ni[li];
            auto nxt_ri=vi2ni[ri];
            auto l_sum=vA[li]+vA[nxt_li];
            auto r_sum=vA[ri]+vA[nxt_ri];
            bool is_lesser=(
                (l_sum<r_sum)
                || ((l_sum==r_sum) && (li < ri))
            );
            // if(!is_lesser){
            //     cout<<make_pair(li,make_pair(vA[li],vA[nxt_li]))<<">="<<make_pair(ri,make_pair(vA[ri],vA[nxt_ri]))<<endl;
            // }
            return is_lesser;
        };   
    vector<Node1> vNode1(N);
    vector<Node1*> lA1(N);
    list<Node1*,decltype(cmp_lesser)> lA2(cmp_lesser);  
    vector<list<Node1*>::iterator> vit2lA2(N) ;
    for(ll i=0;i<N;++i){
        vi2ni[i]=(i+1)%N;
        vi2pi[i]=(N+i-1)%N;
    }
    for(ll i=0;i<N;++i){
        vNode1[i].indx=i;
        vNode1[i].val=vA[i];
        lA1[i]=&vNode1[i];
        // cout<<"Inserting..."<<lA1[i]<<endl;
        lA2.insert(lA1[i]);
        // cout<<"Done inserting..."<<endl;
        // cout<<"Updated lA2..."<<lA2<<endl;
    }
    //no operator "<<" matches these operands -- operand types are: std::ostream << std::set<Node1 *, lambda []bool (Node1 *lptr, Node1 *rptr)->bool, std::allocator<Node1 *>>
/*Lists have the important property that insertion and splicing do not invalidate iterators to list elements, and that even removal invalidates only the iterators that point to the elements that are removed */
    while(lA2.size()>2){
        //remove smallest node from lA2( corresponding to ith and i+1th elements in the circle acc to initial indexing)
        auto i_it2=lA2.begin();//iterator to minimum node
        auto ix=(*i_it2)->indx;//index corresponding to minimum node in lA2
        auto p_ix=vi2pi[ix];//previous index
        auto n_ix=vi2ni[ix];//next index
        auto nn_ix=vi2ni[n_ix];//next2next index
        // cout<<lA1[ix]<<lA1[n_ix]<<endl;
        // tr(lA2,it){
        //     auto it_prev=(it==lA2.begin())?(prev(lA2.end(),1)):(prev(it,1));
        //     cout<<"("<<(*it_prev)->indx<<(((cmp_lesser(*it_prev,*it))?("is lesser"):("is more than")))<<(*it)->indx<<")"<<endl;
        // }
        //update lA2 (before you make changes to nodes)
        //  -remove nodes with index ix,n_ix
        //  -Note:Later on inset new updated ix
        lA2.erase(lA1[ix]);
        lA2.erase(lA1[n_ix]);

        //remove first, insert new first
        //  -update Node1 at index=ix
        lA1[ix]->val+=lA1[n_ix]->val;
        vA[ix]+=vA[n_ix];
        //  -discard n_ix by skipping over it
        vi2ni[ix]=nn_ix;
        vi2pi[nn_ix]=ix;
        vi2ni[n_ix]=vi2pi[n_ix]=-1;

        //inserting updated ix
        // cout<<"Inserting..."<<lA1[ix]<<endl;
        lA2.insert(lA1[ix]);
        // cout<<"Done inserting..."<<endl;
        // cout<<"Updated lA2..."<<lA2<<endl;
        //adding the penalty
        min_penalty+=lA1[ix]->val;
        // cout<<lA2<<"\npenalty:"<<min_penalty<<"\nxxx"<<endl;
        //remove corresponding i+1th element from lA2( using ith and i+1th indexed nodes from lA1)
        //insert the new node into lA1 have value sum of value of the two removed nodes in such a awy so as to maintain sorted order
        //remove ith and i+1th elements from lA1 and insert at the same position a single node having value the sum of the values of the removed nodes
        //update the iterator of the newly inserted node in lA1 and lA2.
    }
    min_penalty+=(*lA2.begin())->val+(*next(lA2.begin(),1))->val;
    cout<<min_penalty<<endl;
}

int main(){
    string s=R"(
1
3
10 10 1
    )";
    istringstream iss(s);
    cin.rdbuf(iss.rdbuf());
    ll T;cin>>T;
    for(ll t=0;t<T;++t){
        solve();
    }
    return 0;
}