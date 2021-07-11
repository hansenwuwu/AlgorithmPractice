#include "graph.h"

#include <queue>

void Graph::AddEdgeList(int from, int to){
    AdjList[from].push_back(to);
}

void Graph::printGraph(){
    for(int i=0; i<AdjList.size(); i++){
        std::cout << "From " << i << " :" ;
        for(auto& e:AdjList[i]){
            std::cout << e << " " ;
        }
        std::cout << std::endl;
    }
}

void Graph::printParent(){
    std::cout << "Parent:  ";
    for(auto& e:parent)
        std::cout << e << " " ;
    std::cout << std::endl;
}

void Graph::printDistance(){
    std::cout << "Distance:  ";
    for(auto& e:distance)
        std::cout << e << " " ;
    std::cout << std::endl;
}

void Graph::printColor(){
    std::cout << "Color:  ";
    for(auto& e:color)
        std::cout << e << " " ;
    std::cout << std::endl;
}

void Graph::printDiscover(){
    std::cout << "Discover:  ";
    for(auto& e:discover)
        std::cout << e << " " ;
    std::cout << std::endl;
}

void Graph::printFinish(){
    std::cout << "Finish:  ";
    for(auto& e:finish)
        std::cout << e << " " ;
    std::cout << std::endl;
}

void Graph::BFS(int start){

    color.resize(num_vertex);
    parent.resize(num_vertex);
    distance.resize(num_vertex);

    for(int i=0; i<num_vertex; i++){
        color[i] = 0;
        parent[i] = -1;
        distance[i] = -1;
    }

    std::queue<int> q;
    int i = start;
    
    for(int j=0; j<=num_vertex; j++){
        std::cout << "check: " << i << std::endl;
        if( color[i] == 0 ){
            color[i] = 1;
            q.push(i);
            distance[i] = 0;
            while(!q.empty()){
                int from = q.front();
                q.pop();
                for(auto& to:AdjList[from]){
                    if(color[to] == 0){
                        color[to] = 1;
                        parent[to] = from;
                        distance[to] = distance[from] + 1;
                        q.push(to);
                    }
                }
                color[from] = 2;
            }

        }
        i = j;
    }
    
}

void Graph::DFS(int start){
    for(int i=0; i<num_vertex; i++){
        color[i] = 0;
        parent[i] = -1;
        distance[i] = -1;
        finish[i] = -1;
    }

    int time = 0;
    int j = start;
    for(int i=0; i<=num_vertex; i++){
        if(color[j] == 0){
            DFSVisit(j, time);
        }
        j = i;
    }
    
}

void Graph::DFSVisit(int from, int& time){
    color[from] = 1;
    discover[from] = ++time;
    for(auto& to:AdjList[from]){
        if(color[to]==0){
            parent[to] = from;
            DFSVisit(to, time);
        }
    }
    color[from] = 2;
    finish[from] = ++time;
}