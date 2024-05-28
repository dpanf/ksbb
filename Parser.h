#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

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

class Parser
{
    public:
        Parser(string str);
        ~Parser();
        int get_N();
        int get_max_weight();
        vector<Item> items;
        vector<Item> get_items();
        void Parse();

    protected:

    private:
        string filename;
        fstream f_in;
        int N=0;
        int max_weight;
};

#endif // PARSER_H
