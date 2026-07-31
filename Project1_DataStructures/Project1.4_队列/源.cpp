//————————————————————循环队列数组实现
const int Maxsize = 1e4 + 10;
template <class T>
class Queue
{
private:
	T A[Maxsize];
	int front = 0, rear = 0;//初始化
public:
	bool empty() { return front == rear; }
	bool full() { return (rear + 1) % Maxsize == front; }
	void enQueue(T t)
	{
		assert(!full());
		A[rear] = t;
		rear = (rear + 1) % Maxsize;//不能简单++
	}
	T deQueue()
	{
		assert(!empty());
		T temp=A[front];//必须暂存，不能提前返回，也不能返回简单的front-1
		front = (front + 1) % Maxsize;//不能简单++
		return temp;
	}
};


//————————————————————迷宫寻径2.0
//起点到终点最少需要多少步
const int maxn = 50;
const int maxsize = maxn * maxn;
struct point
{
	int x, y;
	point(int a = 0, int b = 0) { x = a;y = b; }
};
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
char map[maxn][maxn];//记录地图特征，比如有障碍物之类的
int vis[maxn][maxn] = { {0} };
int dist[maxn][maxn] = { {0} };
bool feasible(int x, int y)
{
	if (x<0 || y<0 || x>maxn || y>maxn)return 0;
	if (map[x][y] == '#')return 0;
	if (vis[x][y] == 1)return 0;
	return 1;
}
int BFS(int n, int m)//思路：让该点所有可达方向入队，出队一个点以更新
{
	Queue<point> Q;//创建队列
	Q.enQueue(point(0, 0));
	dist[0][0] = 1;vis[0][0] = 1;
	while (!Q.empty())
	{
		point p = Q.deQueue();//取得点
		for (int i = 0;i < 4;i++)//将该点可达点入队
		{
			int nx = p.x + dx[i], ny = p.y + dy[i];
			if (feasible(nx, ny))
			{
				vis[nx][ny] = 1;dist[nx][ny] = dist[p.x][p.y] + 1;
				if (nx == n - 1 && ny == m - 1)return dist[nx][ny];
				Q.enQueue(point(nx, ny));//并将该点入队
			}
		}

	}
	return -1;//不可达
}
//深度优先搜索：一条路走到黑，用回溯法实现
//广度优先搜索：地毯式搜索，路径长度递增，直到终点，常用于寻找最短路径


