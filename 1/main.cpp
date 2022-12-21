#include<iostream>
#include"Graph.h"


int extractMinimum(int key[], bool isVisited[], int size)
{
    int min = INT_MAX, currentVertex;
        for (int v = 0; v < size; v++)
            if ( key[v] < min && isVisited[v] == false)
                min = key[v], currentVertex = v;

    return currentVertex;
}

void primMST(Graph graph)
{

    int prev[graph.size], key[graph.size];
    Graph mst(graph.size);
    bool isVisited[graph.size];

    for (int i = 0; i < graph.size; i++){
        key[i] = INT_MAX;
        isVisited[i] = false;
    }
    key[0] = 0;


    for (int count = 0; count < graph.size - 1; count++) {

        int currentVertex = extractMinimum(key, isVisited, graph.size);
        isVisited[currentVertex] = true;

        for (int j = 0; j < graph.size; j++){
            if (graph.getEdge(currentVertex,j) && isVisited[j] == false && graph.getEdge(currentVertex,j) < key[j]){
                prev[j] = currentVertex;
                key[j] = graph.getEdge(currentVertex,j);
            }
        }
    }

    for(int i = 1; i < mst.size; i++)
        mst.insertEdge(i, prev[i], graph.getEdge(i,prev[i]));

    mst.printMatrix();

}

int main(){
    Graph g(7);
    g.insertEdge(0, 1, 2);
    g.insertEdge(0, 2, 4);
    g.insertEdge(0, 3, 1);
    g.insertEdge(1, 4, 10);
    g.insertEdge(1, 3, 3);
    g.insertEdge(2, 3, 2);
    g.insertEdge(2, 5, 5);
    g.insertEdge(5, 3, 8);
    g.insertEdge(5, 6, 1);
    g.insertEdge(6, 4, 6);
    g.insertEdge(3, 4, 7);
    g.insertEdge(6, 3, 4);


    primMST(g);

    std::cout<<std::endl;

}
