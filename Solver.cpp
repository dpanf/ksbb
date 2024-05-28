#include "Solver.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item{
    int weight;
    int value;
};

struct Node{
    int level;
    int profit;
    int weight;
    vector<int> item_ind;
};

bool cmp(const Item &a, const Item &b){
    return (a.value/a.weight)>(b.value/b.weight);
}

int Solver::bound(Node u,int n,int mw,vector<Item> it){
    if(u.weight>=mw)
        return 0;
    int profit_bound=u.profit;
    int i=u.level+1;
    int tot_weight=u.weight;
    while((n>i)&&(tot_weight+it[i].weight<=mw)){
        tot_weight+=it[i].weight;
        profit_bound+=it[i].value;
        i+;
    }
    if(n>i)
        profit_bound+=(mw-tot_weight)*(it[i].value/it[i].weight);
    return profit_bound;
}

int Solver::solve(int N,int mw,vector<Item> it){
    sort(it.begin(),it.end(),cmp);
    Node u, v;
    u.level=-1;
    u.profit=0;
    u.weight=0;
    vector<Node> Q;
    Q.push_back(u);
    int M=0;
    while(!Q.empty()){
        u=Q.back();
        Q.pop_back();
        if(u.level!=N-1){
            v.level=u.level+1;
            v.weight=u.weight+it[v.level].weight;
            v.profit=u.profit+it[v.level].value;
            if(v.weight<=mw && v.profit>M)
                M=v.profit;
            v.profit=bound(v,N,mw,it);
            if(v.profit>M)
                Q.push_back(v);
            v.weight=u.weight;
            v.profit=u.profit;
            v.profit=bound(v,N,mw,it);
            if(v.profit>M)
                Q.push_back(v);
        }
    }
    return M;
}
