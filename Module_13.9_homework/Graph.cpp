#pragma once
#include "Graph.h"
#include <iostream>

void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет матрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    /*
    for (int i = 0; i < vertexCount; i++)
    {
        // вывод всех минимальных путей от вершины '0'
        std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
    }
    */

    // вывод всех знакомств через три рукопожатия  
    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            if (weights[i][j] <= 3 && weights[i][j] != 0)
            std::cout << names[i] << " and " << names[j] << " are familiar throug " << weights[i][j] << " handshake;" << endl;
        }
    }
    
}

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}

void Graph::addVertex(int vnumber, string vname)
{
    vertexes[vertexCount] = vnumber;
    names[vertexCount++] = vname;
}

void Graph::addEdge(int v1, int v2)
{
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}

bool Graph::edgeExists(int i, int j)
{
    if (matrix[i][j] != 0) return true;
    else return false;
}