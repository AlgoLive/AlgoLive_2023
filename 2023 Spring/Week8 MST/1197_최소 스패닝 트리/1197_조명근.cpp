#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct KS
{
    int from, to, val;
};
int V, E;
vector<KS> Edges;
int parent[100001];
long result;
long sum;
int cnt;
bool comp(KS k1, KS k2)
{
    return k1.val < k2.val;
}
int find(int num)
{
    if (num == parent[num])
    {
        return num;
    }
    return parent[num] = find(parent[num]);
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
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        Edges.push_back(ks);
        sum += ks.val;
    }
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < E; i++)
    {
        int f = find(Edges[i].from);
        int t = find(Edges[i].to);

        if (Union(f, t))
        {
            cnt++;
            result += Edges[i].val;
            if (cnt == V - 2)
            {
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}