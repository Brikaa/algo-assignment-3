#ifndef __Graph__
#define __Graph__
#include <iostream>
#include <vector>
#include <climits>

class Graph
{
private:
    int **adjMatrix;

    int getEdge(int nodeA, int nodeB)
    {
        return adjMatrix[nodeA][nodeB];
    }

    void insertEdge(int nodeA, int nodeB, int weight)
    {
        if (nodeA >= size || nodeB >= size)
        {
            std::cout << "please enter a valid node" << std::endl;
            return;
        }

        adjMatrix[nodeA][nodeB] = weight;
        adjMatrix[nodeB][nodeA] = weight;
    }

    void removeEdge(int nodeA, int nodeB)
    {
        if (nodeA >= size || nodeB >= size)
        {
            std::cout << "please enter a valid node" << std::endl;
            return;
        }
        adjMatrix[nodeA][nodeB] = 0;
        adjMatrix[nodeB][nodeA] = 0;
    }

    int extractMinimum(int key[], bool isVisited[], int size)
    {
        int min = INT_MAX, currentVertex;
        for (int v = 0; v < size; v++)
            if (key[v] < min && isVisited[v] == false)
                min = key[v], currentVertex = v;

        return currentVertex;
    }

public:
    int size;

    Graph(int Size)
    {
        size = Size;
        adjMatrix = new int *[size];
        for (int i = 0; i < size; i++)
            adjMatrix[i] = new int[size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                adjMatrix[i][j] = 0;
    }

    void primMST()
    {

        int prev[size], key[size];
        Graph mst(size);
        bool isVisited[size];

        for (int i = 0; i < size; i++)
        {
            key[i] = INT_MAX;
            isVisited[i] = false;
        }
        key[0] = 0;

        for (int i = 0; i < size - 1; i++)
        {

            int currentVertex = extractMinimum(key, isVisited, size);
            isVisited[currentVertex] = true;

            for (int j = 0; j < size; j++)
            {
                if (getEdge(currentVertex, j) < key[j] &&  getEdge(currentVertex, j) != 0 && isVisited[j] == false)
                {
                    prev[j] = currentVertex;
                    key[j] = getEdge(currentVertex, j);
                }
            }
        }

        for (int i = 1; i < mst.size; i++)
            mst.insertEdge(i, prev[i], getEdge(i, prev[i]));

        mst.printMatrix();
    }

    void printMatrix()
    {
        std::cout << "    ";
        for (int i = 0; i < size; i++)
            std::cout << "v" << i + 1 << " ";
        std::cout << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << "v" << i + 1 << "  ";
            for (int j = 0; j < size; j++)
            {
                if (adjMatrix[i][j] != 0)
                    std::cout << adjMatrix[i][j] << "  ";
                else
                    std::cout << "-"
                              << "  ";
            }
            std::cout << std::endl;
        }
    }

    void runTestCase()
    {
        insertEdge(0, 1, 2);
        insertEdge(0, 2, 4);
        insertEdge(0, 3, 1);
        insertEdge(1, 4, 10);
        insertEdge(1, 3, 3);
        insertEdge(2, 3, 2);
        insertEdge(2, 5, 5);
        insertEdge(5, 3, 8);
        insertEdge(5, 6, 1);
        insertEdge(6, 4, 6);
        insertEdge(3, 4, 7);
        insertEdge(6, 3, 4);
        primMST();
    }
};

#endif
