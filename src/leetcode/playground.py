from collections import defaultdict as dd

class Solution:
    def minCostToSupplyWater(self, n, wells, pipes) -> int:
        solution = (
            sum( wells[i]  for i in range(len(wells)) if f_is_unreachable(i) )
            + sum( )
        )
        exists=lambda x : x is not None
        imaginary_vertex=-1
        def make_empty_graph():
            g=dd(lambda:None)
            g['e']=dd(lambda: dd(lambda: None))
            g['v']=dd(lambda: False) # does a vertex exist
            g['cc']=dd(lambda:None) # index identifying connected component
            g['0']=dd(lambda:None) # source for connected component
            g['x']=dd(lambda:False)
            return g
        def populate_graph(G,EDGES,VERTICES):
            if(len(EDGES)>0):
                for e in EDGES:
                    add_edge(G,e)
            if(len(VERTICES)>0):
                for v,w in VERTICES:
                    add_edge(G,(v,imaginary_vertex,w))
        def get_source(G,v):
            if(exists(G['v'][v])):
                connected_component_index=G['cc'][v]
                return G['0'][connected_component_index]
            return False
        def add_vertex(G,v):
            G['v'][v]=True
        def add_edge(G,e,on_duplicate_edge=False):
            v1,v2,w12 =e
            G['v'][v1]= G['v'][v2] = True
            if(on_duplicate_edge):
                if(on_duplicate_edge=='consider minimum weight edge'):
                    w_initial=get_edge_weight(G,v1,v2)
                    if(w_initial):
                        G['e'][v1][v2]= min(w_initial,w12)
                    else:
                        G['e'][v1][v2]= w12
            else:
                G['e'][v1][v2]= w12

        def get_edge_weight(G,v1,v2):
            if(v1 in G['e']):
                if(v2 in G['e'][v1]):
                    return G['e'][v1][v2]
            return False
        def remove_edge(G,v1,v2):
            for vi,vj in [(v1,v2),(v2,v1)]:
                if(vi in G['e']):
                    if( vj in  G['e'][vi]):
                        del G['e'][vi][vj]
                        if(len(G['e'][vi]==0)):
                            del G['e'][vi]
        def add_well(G,v,w):
            add_edge(G,(v,imaginary_vertex,w))
        def remove_well(G,v):
            remove_edge(G,v,imaginary_vertex)
        def get_well_cost(G,v):
            return G['e'][v][imaginary_vertex]
        def mark_vertex_visited(G,v):
            G['x'][v]=True
        def is_vertex_visited(G,v):
            return G['x'][v]
        def should_add_edge(G,e):
            v,v_external,w=e
            source=get_source(G,v)
            if(get_well_cost(G,source) > w + get_well_cost(G,v_external)):
                add_edge(G,e)
                add_well(G,v_external)
                remove_well(G,source)
            elif(w< get_well_cost(G,v_external)):
                add_edge(G,e)
            elif(w< get_well_cost(G,v_external)):
                add_well(G,v_external)
        def which_edge_to_add(G,v):
            for vertex in G['e'][v]:
                if(is_vertex_visited(G,vertex)):
                    ok=should_add_edge(G,(v,vertex,G['e'][v][vertex]))
                    if(ok):
                        pass
            add_vertex(G,v)
            mark_vertex_visited(G,v)
        
        def solve():
            G=make_empty_graph()
            for v1,v2,w12 in pipes.values():
                add_vertex(G,v1)
                add_vertex(G,v2)
                add_edge(G,(v1,v2,w12),on_duplicate_edge='consider minimum weight edge')
                add_edge(G,(v2,v1,w12),on_duplicate_edge='consider minimum weight edge')
            G1=make_empty_graph()
            for v in G['v'].keys():
                pass

            pass
        '''
        -introduce a new node Cn
        -Say Ci, from the list of connections ( C ),
            - Q: min ( ++ Ci --- Cn , ++ [_]Wn)
            
        '''
