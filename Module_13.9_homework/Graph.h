#pragma once
#define VERYBIGINT 1000000000
#define SIZE 10
#include <string>
using namespace std;

class Graph
{
public:
    Graph();
    void findMinDistancesFloyd();
    void addVertex(int vnumber, string vname);
    void addEdge(int v1, int v2);
    bool edgeExists(int i, int j);

private:
    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexes[SIZE]; // хранилище вершин
    string names[SIZE];
    int vertexCount; // количество добавленных вершин
};

