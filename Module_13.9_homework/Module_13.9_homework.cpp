
#pragma once
#include <iostream>
#include "Graph.h"
#define VERYBIGINT 1000000000
#define SIZE 10
using namespace std;



int main()
{
    Graph g;

    g.addVertex(0, "Oleg");
    g.addVertex(1, "Nikita");
    g.addVertex(2, "Nastya");
    g.addVertex(3, "Vanya");
    g.addVertex(4, "Liza");
    g.addVertex(5, "Malish");
    g.addVertex(6, "Gena");
    g.addVertex(7, "Sharik");
    g.addVertex(8, "Rosa");

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    g.findMinDistancesFloyd();
    return 0;
}