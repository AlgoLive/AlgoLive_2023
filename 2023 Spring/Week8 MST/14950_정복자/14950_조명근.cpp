#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, T;
int parent[10001];
long ans;
struct KS
{
    int to;
    int from;
    int weight;
};
bool comp(KS ks1, KS ks2)
{
    return ks1.weight < ks2.weight;
}
vector<KS> Edges;
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
bool Union(int t, int f)
{
    t = Find(t);
    f = Find(f);
    if (t == f)
    {
        return false;
    }
    else
    {
        parent[t] = f;
        return true;
    }
}
void up()
{
    for (int i = 0; i < Edges.size(); i++)
    {
        Edges[i].weight += T;
    }
}
int main()
{
    cin >> N >> M >> T;

    for (int i = 0; i < M; i++)
    {
        KS ks;
        cin >> ks.to >> ks.from >> ks.weight;
        Edges.push_back(ks);
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < M; i++)
    {
        int t = Edges[i].from;
        int f = Edges[i].to;

        if (Union(t, f))
        {
            ans += Edges[i].weight;
            up();
        }
    }
    cout << ans;
}
