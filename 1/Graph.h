#ifndef __Graph__
#define __Graph__
#include <iostream>
#include <vector>

class node{
    private:
        int id;
        int value;
        bool isVisited;
    public:
        node(int id, int val){
            value = val;
        }
};

class Graph{
    private:
        int ** adjMatrix;
    public:
        int size;

        Graph(int Size){
            size = Size;
            adjMatrix = new int*[size];
            for(int i = 0; i < size; i++)
                adjMatrix[i] = new int[size];

            for(int i = 0 ; i < size; i++)
                for(int j = 0; j < size; j++)
                    adjMatrix[i][j] = 0;


        }
        int getEdge(int nodeA, int nodeB){
            return adjMatrix[nodeA][nodeB];
        }
        void insertEdge(int nodeA, int nodeB, int weight){
            if(nodeA >= size || nodeB >= size){
                std::cout<<"please enter a valid node" << std::endl;
                return;
            }

            adjMatrix[nodeA][nodeB] = weight;
            adjMatrix[nodeB][nodeA] = weight;

        }
        void removeEdge(int nodeA, int nodeB){
            if(nodeA >= size || nodeB >= size){
                std::cout<<"please enter a valid node" << std::endl;
                return;
            }
            adjMatrix[nodeA][nodeB] = 0;
            adjMatrix[nodeB][nodeA] = 0;
        }
        void printMatrix(){
            for(int i = 0 ; i < size; i++){
                for(int j = 0; j < size; j++){
                    std::cout<<adjMatrix[i][j]<<"  ";
                }
                std::cout<<std::endl;
            }
        }
};


#endif
