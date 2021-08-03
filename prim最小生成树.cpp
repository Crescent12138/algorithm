#include<iostream>  
#include<fstream>  
using  namespace std;  
  
#define MAX 100  
#define MAXCOST 0x7fffffff  
  
int graph[MAX][MAX];  
  
int prim(int graph[][MAX], int n)  
{  
    int lowcost[MAX];  
    int mst[MAX];                                 
    int i, j, min, minid, sum = 0;  
    for (i = 2; i <= n; i++)  
    {  
        lowcost[i] = graph[1][i];  
        mst[i] = 1;                                       //mst[]存放MST外的点i到MST最短距离时候对应的MST里的点标号
    }  
    mst[1] = 0;  
    for (i = 2; i <= n; i++)                        //要找出n-1个点为止
    {  
        min = MAXCOST;  
        minid = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (lowcost[j] < min && lowcost[j] != 0)  
            {  
                min = lowcost[j];  
                minid = j;  
            }  
        }  
        cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;  
        sum += min;  
        lowcost[minid] = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (graph[minid][j] < lowcost[j])                //不更新的话，lowcost[j]存的只是上一时刻的Lowcost[j]，MST外部的点到minid的距离会不会比到之前的MST里点得最小距离小？
       {  
                lowcost[j] = graph[minid][j];  
                mst[j] = minid;                               //点j到MST内的lowcot对应的MST里的点事minid
            }  
        }  
    }  
    return sum;  
}  
  
int main()  
{  
    int i, j, k, m, n;  
    int x, y, cost;  
    ifstream in("input.txt");  
    in >> m >> n;//m=顶点的个数，n=边的个数  
    //初始化图G  
    for (i = 1; i <= m; i++)  
    {  
        for (j = 1; j <= m; j++)  
        {  
            graph[i][j] = MAXCOST;  
        }  
    }  
    //构建图G  
    for (k = 1; k <= n; k++)  
    {  
        in >> i >> j >> cost;  
        graph[i][j] = cost;  
        graph[j][i] = cost;  
    }  
    //求解最小生成树  
    cost = prim(graph, m);  
    //输出最小权值和  
    cout << "最小权值和=" << cost << endl;  
    system("pause");  
    return 0;  
}  