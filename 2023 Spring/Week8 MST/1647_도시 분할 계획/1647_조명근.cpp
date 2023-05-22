#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
struct KS
{
    int to;
    int from;
    int weight;
};
using namespace std;
int V, E;
int parent[100001];
long answer;
vector<KS> Edges;
bool comp(KS ks1, KS ks2)
{
    return ks1.weight < ks2.weight;
}
int Find(int num)
{
    if (parent[num] == num)
    {
        return num;
    }
    else
    {
        return parent[num] = Find(parent[num]);
    }
}
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
    {
        return false;
    }
    else
    {
        parent[a] = b;
        return true;
    }
}

int main()
{
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        KS ks;
        cin >> ks.to >> ks.from >> ks.weight;
        Edges.push_back(ks);
    }
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < E; i++)
    {
        int t = Find(Edges[i].to);
        int f = Find(Edges[i].from);
        if (Union(t, f))
        {
            answer += Edges[i].weight;
        }
    }
    cout << answer << endl;
}