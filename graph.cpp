#include<iostream>
#include<list>
using namespace std;
class graph{
    int V;
    list<int> *adj;
    public:
    graph(int v);
    void addEdge(int v,int w);
    void printgraph();
};

graph::graph(int v){
    this->V=v;
    adj = new list<int>[v];
}

void graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void graph::printgraph(){
    for (int i=0;i<this->V;i++){
        cout<<"vertex "<<i<<": ";
        cout<<"Head";
        for(auto it = adj[i].begin(); it!=adj[i].end(); ++it)
        cout <<" -> "<<*it;
        cout<<"\n";
    }
}

int main() {
    graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.printgraph();
    return 0;
}