//最短路径 - Dijkstra算法 参数：图G、源点v
void Dijkstra(Graph G, int v)
{
	//初始化
	int n = G.vexnum;//n为图的顶点个数
	for (int i = 0; i < n; i++)
	{
		S[i] = false;
		D[i] = G.Edge[v][i];
		if (D[i] < INF)Pr[i] = v; //v与i连接，v为前驱
		else Pr[i] = -1;
	}
	S[v] = true;
	D[v] = 0;
	//初始化结束,求最短路径，并加入S集
	for (int i = 1; i < n; i++)
	{
		int min = INF;
		int temp;
		for (int w = 0; w < n; w++)
			if (!S[w] && D[w] < min) //某点temp未加入s集，且为当前最短路径
			{
				temp = w;
				min = D[w];
			}
		S[temp] = true;
	//更新从源点出发至其余点的最短路径 通过temp
		for (int w = 0; w < n; w++)
			if (!S[w] && D[temp] + G.Edge[temp][w] < D[w])
			{
				D[w] = D[temp] + G.Edge[temp][w];
				Pr[w] = temp;
			}
	}
}