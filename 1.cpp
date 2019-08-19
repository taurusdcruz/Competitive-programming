/*
ID: taurusd1
TASK: castle
LANG: C++14
*/

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

//print a set of variables in one line
void pline(string message, ll indent_variable/*variable nof parameters*/)
{

}

/**castle**/
/*
The Castle
IOI'94 - Day 1
In a stroke of luck almost beyond imagination, Farmer John was sent a ticket to the Irish Sweepstakes (really a lottery) for his birthday.
This ticket turned out to have only the winning number for the lottery! Farmer John won a fabulous castle in the Irish countryside.

Bragging rights being what they are in Wisconsin, Farmer John wished to tell his cows all about the castle.
He wanted to know how many rooms it has and how big the largest room was.
In fact, he wants to take out a single wall to make an even bigger room.

Your task is to help Farmer John know the exact room count and sizes.

The castle floorplan is divided into M (wide) by N (1 <=M,N<=50) square modules.
 Each such module can have between zero and four walls. Castles always have walls on their "outer edges" to keep out the wind and rain.

Consider this annotated floorplan of a castle:

     1   2   3   4   5   6   7
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 # ->#   |   |   |   |   #   #
   #############################

#  = Wall     -,|  = No wall
-> = Points to the wall to remove to
     make the largest possible new room
By way of example, this castle sits on a 7 x 4 base. A "room" includes any set of connected "squares" in the floor plan.
This floorplan contains five rooms (whose sizes are 9, 7, 3, 1, and 8 in no particular order).

Removing the wall marked by the arrow merges a pair of rooms to make the largest possible room that can be made by removing a single wall.

The castle always has at least two rooms and always has a wall that can be removed.

PROGRAM NAME: castle
INPUT FORMAT
The map is stored in the form of numbers, one number for each module ("room"), M numbers on each of N lines to describe the floorplan.
The input order corresponds to the numbering in the example diagram above.

Each module descriptive-number tells which of the four walls exist and is the sum of up to four integers:

1: wall to the west
2: wall to the north
4: wall to the east
8: wall to the south
Inner walls are defined twice; a wall to the south in module 1,1 is also indicated as a wall to the north in module 2,1.
Line 1:	Two space-separated integers: M and N
Line 2..:	M x N integers, several per line.
SAMPLE INPUT (file castle.in)
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
OUTPUT FORMAT
The output contains several lines:
Line 1:	The number of rooms the castle has.
Line 2:	The size of the largest room
Line 3:	The size of the largest room creatable by removing one wall
Line 4:	The single wall to remove to make the largest room possible
Choose the optimal wall to remove from the set of optimal walls
by choosing the module farthest to the west (and then, if still tied, farthest to the south).
If still tied, choose 'N' before 'E'.
Name that wall by naming the module that borders it on either the west or south, along with a direction of N or E giving the location of the wall with respect to the module.

SAMPLE OUTPUT (file castle.out)
5
9
16
4 1 E
/**/

/**/

//struct node
//About members of the class:
/*
Member variables:
string walls----------------->string of length 4  holding wall directions(SouthEastNorthWest ) in the cell
bool is_vis------------------>Has this cell been visited
ll component--------------->component the cell belongs to
ll order_vis----------------->order this node was traversed in the graph
*/
//node representing a cell/vertex of the graph
struct node
{
    //In structs members are public by default
    string walls;
    bool is_vis;
    ll component;
    ll order_vis;

    //no need to declare constructor as public
    node()
    :walls("SENW")
    ,is_vis(false)
    ,component(-1LL)
    ,order_vis(-1LL)
    {

    }
};

//Overriding << operator for struct node
ostream&  operator<<(ostream& out,const node& nd)
{
  out<<"("/*<<"w:"<<nd.walls<<", v:"<<nd.is_vis<<", c:"<<nd.component*/<<", o:"<<nd.order_vis<<")";
  return out;
}

//Overriding operator+ for pairs
template< class T, class U >
pair<T,U>  operator+(const pair<T,U>& a,const pair<T,U>& b)
{
  return make_pair(a.first+b.first, a.second+b.second);
}

//class castle
//About members of the class:
/*
Member variables:
ll N,M----------------------------------------------------------->As Defined in
vector<pll > drow_dcol------------------------------------->drow_dcol(change row and col) when moving in direction indexed 0,1,2,3
                                                                                with mappings 0->S, 1->E, 2->N, 3->W
ll largest_component--------------------------------------->size of the largest component
ll combined_adj_components_max-------------------->The size of the largest room creatable by removing one wall
pair< pair<ll,ll>, char> wall_2_remove---------------->The single wall to remove to make the largest room possible
vector<vector< node> > grid----------------------------->2D Grid of nodes where each node(representing each squared module of the castle)
                                                                                stores information about the module/cell of the castle
vector< vector<
reference_wrapper<node>
> > components---------------------------------------------->components[ _ith_component_ ] Stores a vector of references to node ,node&(using reference_wrapper<node>)
                                                                                which belong to the _ith_component_

Member functions:

Castle()------------------------->Constructor
node& get_grid(pll)------------------->access grid[row][col] using get_grid(pll(row,col) )
void assign_components()-------->Traverse grid in BFS manner and assign for each cell/node/module of the castle its component
void solve()-------------------> Self Explanatory

*/

class Castle
{
//By default data members are private
//
ll N,M;
vector<pll > drow_dcol={pll{1,0},pll{0,1},pll{-1,0},pll{0,-1}};
ll largest_component=-1;
ll combined_adj_components_max=-1;
pair< pair<ll,ll>, char> wall_2_remove=make_pair(pair<ll,ll>(-1,-1), 'X');
vector< pair< pair<ll,ll>, char> > optimal_walls={};
vector<vector< node> > grid;
vector< vector< node* > > components;// use reference_wrapper  instead of raw references when creating vector of references
public:
Castle()
    :N([](){ ll c; cin>>c; return c;}())
    ,M([](){ ll c; cin>>c;return c;}())
    ,grid([&](){ return vector< vector<node > > (M, vector<node>(N,node())) ;}())
    ,components()
    {
        rep(m,0,M)
        {
            rep(n,0,N)
            {
                ll c;
                cin>>c;
                grid[m][n].walls= bitset<4>(c).to_string();
            }
        }
        /**
        debug("",grid)
        /**/
    };
    //access grid[row][col] instead using get_grid(pll(row,col) )
    node* get_grid(pll row_col)
    {
        return &grid[row_col.first][row_col.second];
    }
    //Traverse grid in BFS manner and assign for each cell/node/module of the castle its component
    void assign_components()
    {
        ll component_no=-1;//component no of current component
        ll cnt_vis=0;//cnt 0f the number of unique cells we have visited till now
        rep(row,0,M)
        {
            rep(col,0,N)
            {
                if(!grid[row][col].is_vis)
                {
                    component_no+=1;
                    components.push_back(vector<node*>{});// increase the size of the components vector
                    deque< pll > neighbours;//using deque as a queue FIFO. IN->push_back(),OUT-> pop_front()

                    neighbours.push_back(pll(row,col));
                    get_grid(pll(row,col))->is_vis=true;
                    for(;;)
                    {
                        //vertex at the front of the queue
                        pll vertex=neighbours.front();neighbours.pop_front();

                        //!!!Reference!!! to get_grid(vertex) which was the most current node  just popped out from the queue of neighbours
                        node* curr_node=get_grid(vertex);
                        components[component_no].push_back(curr_node );

                        //update members of curr_node
                        curr_node->component=component_no/*assign component */
                        ,curr_node->order_vis=++cnt_vis/*assign the number of nodes already visited including this node*/
                        ;
                        rep(i,0,4)
                        {
                            if(curr_node->walls[i]=='0')
                            {
                                pll neighbour_vertex=vertex+drow_dcol[i];//operator+ for pairs overloaded

                                //neighbouring node in the direction indicated by i  E{0,1,2,3}
                                //where Relation:i -> Direction is set of ordered pairs(i,Direction) belonging to set{(0,S),(1,E),(2,N),(3,W)}
                                node* neighbour_node=get_grid(neighbour_vertex);
                                if(!neighbour_node->is_vis)
                                {
                                    neighbours.push_back(neighbour_vertex);
                                    neighbour_node->is_vis=true;
                                }

                            }
                        }
                        if(neighbours.empty())
                            break;
                    }
                    /**
                    debug("--------",component_no)
                    debug("",neighbours)
                    debug("",components.back())
                    /**/
                }
            }
        }

        return;
    }

    void solve()
    {
        /*
        APPROACH:
        */
        assign_components();

        largest_component=max_element(all(components),[](vector<node* > l, vector<node* > r){ return l.size()<r.size();})->size();
        combined_adj_components_max=largest_component;
        for(ll row=0;row<M;++row)
        {
            for(ll col=0;col<N;++col)
            {
                //current vertex
                pll vertex=pll(row,col);
                rep(i,0,4)
                {
                    //adding the component size( current cell)+ component size( neighbouring cell) (provided they are separated by a wall)
                    if(
                       !(i==0 && vertex.first ==M-1)
                       && !(i==1 && vertex.second ==N-1)
                       && !(i==2 && vertex.first==0)
                       && !(i==3 && vertex.second==0)
                       )
                    {
                        //neighbouring vertex
                        pll neighbour_vertex=vertex+drow_dcol[i];
                        node *curr_node, *neighbour_node;
                        tie(curr_node,neighbour_node)=make_pair(get_grid(vertex),get_grid(neighbour_vertex));
                        if((curr_node->component) ==(neighbour_node->component) )
                            continue;
                        ll curr_component, neighbour_component;
                        tie(curr_component,neighbour_component)=tie(curr_node->component , neighbour_node->component);
                        if(combined_adj_components_max<=(ll)(components[curr_component].size()+ components[neighbour_component].size()))
                        {
                            if(combined_adj_components_max<(ll)(components[curr_component].size()+ components[neighbour_component].size()))
                            {
                                //erase all elements from optimal_walls
                                optimal_walls.erase(all(optimal_walls));
                            }
                            combined_adj_components_max=components[curr_component].size()+ components[neighbour_component].size();

                            char direction;
                            if(i==0) direction='S';
                            else if(i==1) direction='E';
                            else if(i==2) direction='N';
                            else if(i==3) direction='W';
                            wall_2_remove=make_pair(vertex,direction);
                            optimal_walls.push_back(wall_2_remove);
                            /**
                            debug("\t",wall_2_remove)
                            /**/
                        }
                    }
                }
            }
        }
        /**
        debug("",grid)
        debug("", components)
        debug("",optimal_walls)
        /**/
        auto cmp
        =[](pair< pair<ll,ll>, char> l, pair< pair<ll,ll>, char> r)
        {
            ll lrow,lcol, rrow,rcol;
            char ldir,rdir;
            forward_as_tuple(tie(lrow, lcol), ldir) = l;
            forward_as_tuple(tie(rrow, rcol), rdir) = r;
            if(lcol<rcol)
            {
                return true;
            }
            else if(lcol==rcol)
            {
                if(lrow>rrow)
                {
                    return true;
                }
                else if(lrow==rrow)
                {
                    if(ldir=='N')
                        return true;
                }
            }
            return false;
        }
        ;

        sort(all(optimal_walls),cmp);
        wall_2_remove=optimal_walls[0];

        cout<<components.size()<<endl
        <<largest_component<<endl
        <<combined_adj_components_max<<endl
        <<wall_2_remove.first.first+1<<" "<<wall_2_remove.first.second+1<<" "<<wall_2_remove.second<<endl;
        return;
    }
};

int main ( )
{
    /**
    freopen("in.txt","r",stdin);//redirects standard input
    /**/
	freopen("castle.in","r",stdin);//redirects standard input
    freopen("castle.out","w",stdout);//redirects standard output
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    Castle().solve();
	return 0;
}
