#include <iostream>
#include <vector>
#include <algorithm>
struct KS
{
    int to;
    int from;
    int weight;
};
using namespace std;
int N;
int parent[51];
int ans;
int total;
int conn;
vector<KS> Edges;
bool comp(KS ks1, KS ks2)
{
    return ks1.weight < ks2.weight;
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
bool Union(int t, int f)
{
    t = Find(t);
    f = Find(f);

    if (f == t)
    {
        return false;
    }
    else
    {
        parent[t] = f;
        return true;
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < a.size(); j++)
        {
            KS ks;
            int tmp;
            tmp = a[j] - 96;
            if (tmp < 0)
            {
                tmp = 58 + tmp;
                if (tmp == 10)
                {
                    continue;
                }
                ks.from = i;
                ks.to = j + 1;
                ks.weight = tmp;
                total += tmp;
                Edges.push_back(ks);
            }
            else if (tmp > 0)
            {
                ks.from = i;
                ks.to = j + 1;
                ks.weight = tmp;
                total += tmp;
                Edges.push_back(ks);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < Edges.size(); i++)
    {
        int f = Edges[i].from;
        int t = Edges[i].to;

        if (Union(f, t))
        {
            conn++;
            ans += Edges[i].weight;
        }
    }
    if (conn == N - 1)
    {
        cout << total - ans;
    }
    else
    {
        cout << -1;
    }
}