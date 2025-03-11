#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"

//struct Edge {
//    int src=0;
//    int dst=0;
//    int weight=0;
//};
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int size = G.numVertices;
    vector<int> distance{};
    vector<bool> visited{};
    distance.resize(size, INF);
    previous.resize(size, -1);
    visited.resize(size, false);

    priority_queue<Node> pq{};
    pq.push(Node{source, 0});
    distance[source] = 0; //Distance from source to itself is 0

    while(!pq.empty())
    {
        int u = pq.top().vertex; pq.pop();

        if(visited[u])
            continue;
        visited[u] = true;

        for (Edge neighbor : G[u])
        {
            int v = neighbor.dst;
            int weight = neighbor.weight;

            if(!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Node{v, distance[v]});
            }
        }
    }
    return distance;
}
vector<int> extract_shortest_path(const vector<int>& distances,
 const vector<int>& previous, 
 int destination)
{
    vector<int> path{};
    vector<int> f_path{};
    int end = destination;
    if(end < 0 || end >= distances.size())
        return f_path;
    path.push_back(end);
    while(previous[end] != -1 && distances[end] != 0)
    {
        end = previous[end];
        path.push_back(end);
    }
    for(int i = path.size() - 1; i >= 0; --i)
    {
        f_path.push_back(path[i]);
    }
    return f_path;
}
void print_path(const vector<int>& v, int total)
{
    for(auto i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
