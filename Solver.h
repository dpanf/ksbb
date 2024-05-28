#ifndef SOLVER_H
#define SOLVER_H
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

class Solver
{
    public:
        int bound(Node u,int n,int mw,vector<Item> it);
        int solve(int N,int mw,vector<Item> it);
    protected:

    private:
};

#endif // SOLVER_H
