#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct KS
{
    int to;
    int from;
    int weight;
};
long long result;
int parent[1001];
int N;
int arr[1001][1001];
vector<KS> Edges;
bool comp(KS a, KS b)
{
    return a.weight < b.weight;
}
int Find(int num)
{
    if (num == parent[num])
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
    a = parent[a];
    b = parent[b];
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
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            KS ks;
            ks.from = i;
            ks.to = j;
            ks.weight = arr[i][j];
            Edges.push_back(ks);
        }
    }
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < Edges.size(); i++)
    {
        int f = Find(Edges[i].to);
        int t = Find(Edges[i].from);
        if (Union(f, t))
        {
            result += Edges[i].weight;
        }
    }
    cout << result << endl;
}