#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>

class Graph{
private:
    int num_vertex;
    std::vector<std::list<int>> AdjList;
    std::vector<int> parent;
    std::vector<int> color;  // record undiscovered, discovered, processed
    std::vector<int> distance;
    std::vector<int> discover;
    std::vector<int> finish;
public:
    Graph(int n): num_vertex(n){
        AdjList.resize(num_vertex);
        color.resize(num_vertex);
        parent.resize(num_vertex);
        distance.resize(num_vertex);
        discover.resize(num_vertex);
        finish.resize(num_vertex);
    };
    void AddEdgeList(int from, int to);
    void printGraph();
    void printParent();
    void printDistance();
    void printColor();
    void printDiscover();
    void printFinish();

    void BFS(int);

    void DFS(int);
    void DFSVisit(int, int&);
};

#endif