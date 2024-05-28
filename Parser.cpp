#include "Parser.h"
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

Parser::Parser(string str){
    filename=str;
    f_in.open(filename);
    string s;
    getline(f_in,s,' ');
    N=stoi(s);
    getline(f_in,s,'\n');
    max_weight=stoi(s);
    f_in.clear();
}

Parser::~Parser(){
    filename.clear();
    f_in.close();
    N=0;
    max_weight=0;
    items.clear();
}

vector<Item> Parser::get_items() {return items;}
int Parser::get_N() {return N;}
int Parser::get_max_weight() {return max_weight;}

void Parser::Parse(){
    string a,b;
    char div=' ';
    for(int i=0;i<N;i++){
        getline(f_in,a,div);
        getline(f_in,b,'\n');
        Item item;
        item.weight=stod(b);
        item.value=stod(a);
        items.push_back(item);
    }
    return;
}
