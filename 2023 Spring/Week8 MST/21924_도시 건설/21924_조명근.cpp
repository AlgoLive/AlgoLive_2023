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
vector<KS> Edges;
int parent[100001];
long result;
int conn;
long sum;
int V, E;
bool compare(KS k1, KS k2)
{
    return k1.weight < k2.weight;
}
int find(int num)
{
    if (num == parent[num])
    {
        return num;
    }
    else
    {
        return parent[num] = find(parent[num]);
    }
}
bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        KS ks;
        cin >> ks.from >> ks.to >> ks.weight;
        Edges.push_back(ks);
        sum += ks.weight;
    }
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    sort(Edges.begin(), Edges.end(), compare);
    for (int i = 0; i < E; i++)
    {
        int f = find(Edges[i].to);
        int t = find(Edges[i].from);
        if (Union(f, t))
        {
            conn++;
            result += Edges[i].weight;
        }
    }
    if (conn == V - 1)
    {
        cout << sum - result << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}