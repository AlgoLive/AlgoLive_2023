#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct KS
{
    int to;
    int from;
    int weight;
};
int cnt;
vector<KS> Edges;
int parent[1001];
char mw[1001];
int N, M;
long ans;
bool comp(KS a, KS b)
{
    return a.weight < b.weight;
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
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> mw[i];
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        KS ks;
        cin >> ks.from >> ks.to >> ks.weight;
        Edges.push_back(ks);
    }
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < M; i++)
    {
        int f = Find(Edges[i].to);
        int t = Find(Edges[i].from);
        if (mw[Edges[i].to] != mw[Edges[i].from])
        {
            if (Union(f, t))
            {
                ans += Edges[i].weight;
                cnt++;
            }
        }
        else
        {
            continue;
        }
    }
    if (cnt == N - 1)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
}
