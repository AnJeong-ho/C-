#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
//冰雹猜想
#include<iostream>
using namespace std;
int main()
{
	int n;cin >> n;int a[200];int i = 1;
	a[0] = n;
	while (n != 1)
	{
		if (n % 2 == 1)n = n * 3 + 1;
		else n /= 2;
		a[i] = n;
		i++;
	}
	i--;
	cout << "[";
	for (int j = i;j >= 0;j--)cout << a[j] << " ";
	cout << "]";
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//校门外的树
#include<iostream>
using namespace std;
void move(bool t[],int L,int a,int b)
{
	if (a<0 || b>L)return;
	for (int i = a;i <= b;i++)t[i] = 1;
}
int main()
{
	bool tree[10010] = { 0 };
	//初始化为空则代表全部为空
	//bool tree[10010] = { false };  // ✅ 全部为 false
	//bool tree[10010] = { 0 };      // ✅ 全部为 0（false）
	//bool tree[10010] = {};         // ✅ 全部为 0
	//memset(数组名，0或者-1或者char或者bool，sizeof())
	//需要引入cstring
	//fill(数组首地址，数组末地址，任意值)
	//需要引入algorithm
	int L;cin >> L;int n;cin >> n;
	for (int i = 0;i < n;i++)
	{
		int a, b;cin >> a >> b;
		move(tree, L, a, b);//时间复杂度O(n²)
	}
	int sum = 0;
	for (int i = 0;i <= L;i++)
	{
		if (tree[i] == 0)sum++;
	}
	cout << sum;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 2
//差分数组，用前n项的和表示元素，优点是不用修改a到b的状态，只需要修改两边
#include<iostream>
using namespace std;
int main()
{
	int tree[10010] = { 0 };int L;cin >> L;
	int n;cin >> n;
	for (int i = 0;i < n;i++)
	{
		int a, b;cin >> a >> b;
		tree[a] += 1;
		tree[b + 1] -= 1;
	}
	int sum = 0,current = 0;
	for (int i = 0;i <=L;i++)//注意<=是一个整体，中间不能有空格
	{
		current += tree[i];//current相当于游标，通过累加来移动
		if (current == 0)sum++;
	}
	cout << sum << endl;
	return 0;

}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//旗鼓相当的对手
#define MAX 10010
#include<iostream>
#include<cmath>
using namespace std;
bool isValid(int a[3], int b[3])
{
	for (int i = 0;i < 3;i++)
	{
		if (abs(a[i] - b[i]) > 5)return false;
	}
	int sum1=0, sum2=0;//时刻注意初始化
	for (int i = 0;i < 3;i++)
	{
		sum1 += a[i];sum2 += b[i];
	}
	if (abs(sum1 - sum2) > 10)return false;
	return true;
}
int main()
{
	int a[MAX][3];//MAX只是向系统要的空间，实际上并未使用那么多
	int n;cin >> n;//亲手设置总数，更加灵活
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cin >> a[i][j];
		}
	}
	int sum = 0;
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			if (isValid(a[i], a[j]))sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//地毯
//校门外的树二维化
//地铁->地毯
//要求被多少地毯覆盖而不是有多少点被覆盖
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100
int main()
{
	int a[MAX][MAX] = { 0 };int m, n;cin >> m >> n;
	for (int k = 0;k < m;k++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)swap(x1, x2);
		if (y1 > y2)swap(y1, y2);
		for (int i = x1;i <= x2;i++)
		{
			for (int j = y1;j <= y2;j++)
				a[i][j]++;
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << a[i][j] << (j == n-1 ? "\n" : " ");//每个格子被多少毯子覆盖
		}
	}
	return 0;

}
#endif
//二维差分(二维前缀和)
#if RUN_EXAMPLE_4 == 2
#include<iostream>
using namespace std;
#define MAX 100
int main()
{
	int a[MAX][MAX] = { 0 };int m, n;cin >> m >> n;
	for (int i = 0;i < m;i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)swap(x1, x2);
		if (y1 > y2)swap(y1, y2);
		//根据差分原理，起点+1，终点的下个点-1
		a[x1][y1] += 1;a[x1][y2 + 1] -= 1;
		a[x2 + 1][y1] -= 1;a[x2 + 1][y2 + 1] +=1;//先横向前缀和，再纵向前缀和
		//若地毯覆盖到边界，不需要结束标记！不用必须遍历到边界
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 1;j < n;j++)
		{
			a[i][j] += a[i][j - 1];
		}
	}
	for (int i = 1;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			a[i][j] += a[i - 1][j];
		}
	}
	//通过前缀和，差分数组已经还原为原数组
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << a[i][j] << (j == n - 1 ? "\n" : " ");//每个格子被多少毯子覆盖
		}
	}
	return 0;
}
#endif
//示意图
/*      0   1   2   3   4   5
    0   ·   ·   ·   ·   ·   ·
    1   ·  +1   ·   ·  -1   ·
    2   ·   ·   ·   ·   ·   ·
    3   ·   ·   ·   ·   ·   ·
    4   ·  -1   ·   ·  +1   ·
    5   ·   ·   ·   ·   ·   ·
* 横向前缀和：a[i][j] += a[i][j - 1];j遍历2~4
*       0   1   #2  #3  #4  5
    0   ·   ·   ·   ·   ·   ·
    1   ·  +1   +1  +1  0   ·
    2   ·   ·   ·   ·   ·   ·
    3   ·   ·   ·   ·   ·   ·
    4   ·  -1   -1  -1  0   ·
    5   ·   ·   ·   ·   ·   ·
* 纵向前缀和：a[i][j] += a[i - 1][j];i遍历2~4
*       0   1   2   3   4   5
    0   ·   ·   ·   ·   ·   ·
    1   ·  +1   +1  +1  0   ·
   #2   ·  +1   +1  +1  0   ·
   #3   ·  +1   +1  +1  0   ·
   #4   ·   0    0   0  0   ·
    5   ·   ·   ·   ·   ·   ·
*/
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//工艺品制作
//校门外的树三维化
//由于数据很小，所以直接暴力枚举
#include<iostream>
using namespace std;
int main()
{
	int w, x, h, q;
	cin >> w >> x >> h >> q;

	// 三维数组标记小方块是否存在
	bool cube[25][25][25] = { false };

	// 初始化：所有小方块都存在
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= x; j++)
			for (int k = 1; k <= h; k++)
				cube[i][j][k] = true;

	// 处理 q 次切割
	for (int t = 0; t < q; t++)
	{
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		// 保证坐标顺序（输入保证 x1≤x2, y1≤y2, z1≤z2）
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				for (int k = z1; k <= z2; k++)
					cube[i][j][k] = false;  // 切掉
	}

	// 统计剩余体积
	int sum = 0;
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= x; j++)
			for (int k = 1; k <= h; k++)
				if (cube[i][j][k]) sum++;

	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//彩票摇奖
#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAX 100
using namespace std;
int main()
{
	srand(time(0));
	int prize[7] = { 0 };//prize[0]=特等奖, prize[6]=六等奖
	int p_number[7];
	int number[MAX][7];
	int n;cin >> n;//小明买了n张彩票
	// 生成开奖号码
	for (int i = 0;i < 7;i++)
	{
		p_number[i] = rand() % 33 + 1;
	}
	//可能重复，要想不重复，与之前的比较，若出现相同，重新摇号
	for (int i = 0;i < n;i++)
	{
		int num = 7;
		for (int j = 0;j < 7;j++)
		{
			number[i][j] = rand() % 33 + 1;
			for (int k = 0;k < 7;k++)
				if (number[i][j] == p_number[k])num--;
		}
		if (num != 7)prize[num]++;// num=0~6 对应 prize[0]~prize[6]
	}
	for (int i = 0;i < 7;i++)
		cout << prize[i] << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//神奇的幻方
#include<iostream>
using namespace std;
int main()
{
	int a[40][40]={0}, N;cin >> N;
	int prev_x, prev_y;
	for (int i = 1;i <= N * N;i++)
	{
		//int prev_x, prev_y;//每次循环都会重新创建 prev_x 和 prev_y，循环结束后，它们的值就消失了下一次循环，又是全新的变量，之前的值丢失！
		if (i == 1)
		{
			prev_x = 0;
			prev_y = (N - 1) / 2;
		}
		else if (prev_x == 0 && prev_y != N - 1)
		{
			prev_x = N - 1;prev_y += 1;
		}
		else if (prev_y == N - 1 && prev_x != 0)
		{
			prev_x -= 1;prev_y = 0;
		}
		else if (prev_x == 0 && prev_y == N - 1)
		{
			prev_x += 1;
		}
		else if (prev_x != 0 && prev_y != N - 1)
		{
			if (a[prev_x - 1][prev_y + 1] == 0)
			{
				prev_x -= 1;prev_y += 1;
			}
			else
			{
				prev_x += 1;
			}
		}
		a[prev_x][prev_y] = i;

	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cout << a[i][j] << ((j+1) % N ? " " : "\n");
		}
	}

}
#endif
#define RUN_EXAMPLE_8 0
#if RUN_EXAMPLE_8 == 1
//显示屏
//暴力枚举
#include<iostream>
#include<cstring>
using namespace std;
void set(char a[5][3], int k)
{
	switch (k)
	{
	case 0:a[0][0] = a[0][1] = a[0][2] = 'X';break;
	case 1:a[0][0] = a[1][0] = a[2][0] = 'X';break;
	case 2:a[0][2] = a[1][2] = a[2][2] = 'X';break;
	case 3:a[2][0] = a[2][1] = a[2][2] = 'X';break;
	case 4:a[2][0] = a[3][0] = a[4][0] = 'X';break;
	case 5:a[2][2] = a[3][2] = a[4][2] = 'X';break;
	case 6:a[4][0] = a[4][1] = a[4][2] = 'X';break;
	}
}
int main()
{
	char a[100][5][3];memset(a, '.', sizeof(a));
	int n ;cin>>n;int num[100];
	for (int i = 0;i < n;i++)
	{
		cin>>num[i];
		switch (num[i])
		{
		case 0:set(a[i], 0);set(a[i], 1);set(a[i], 2);set(a[i], 4);set(a[i], 5);set(a[i], 6);break;
		case 1:set(a[i], 2);set(a[i], 5);break;
		case 2:set(a[i], 0);set(a[i], 2);set(a[i], 3);set(a[i], 4);set(a[i], 6);break;
		case 3:set(a[i], 0);set(a[i], 2);set(a[i], 3);set(a[i], 5);set(a[i], 6);break;
		case 4:set(a[i], 1);set(a[i], 2);set(a[i], 3);set(a[i], 5);break;
		case 5:set(a[i], 0);set(a[i], 1);set(a[i], 3);set(a[i], 5);set(a[i], 6);break;
		case 6:set(a[i], 0);set(a[i], 1);set(a[i], 3);set(a[i], 4);set(a[i], 5);set(a[i], 6);break;
		case 7:set(a[i], 0);set(a[i], 2);set(a[i], 5);break;
		case 8:set(a[i], 0);set(a[i], 1);set(a[i], 2);set(a[i], 3);set(a[i], 4);set(a[i], 5);set(a[i], 6);break;
		case 9:set(a[i], 0);set(a[i], 1);set(a[i], 2);set(a[i], 3);set(a[i], 5);set(a[i], 6);break;
		}
	}
	for (int j = 0;j < 5;j++)
	{
		for (int i = 0;i < n;i++)
		{
			for (int k = 0;k < 3;k++)
				cout << a[i][j][k];
			cout << " ";
		}
		cout << "\n";
	}


}
#endif
//查表法
//也可以用位运算，但是简洁程度没比查表法高多少
#if RUN_EXAMPLE_8 == 2
#include<iostream>
using namespace std;
void set(char a[5][3], int k)
{
	switch (k)
	{
	case 0:a[0][0] = a[0][1] = a[0][2] = 'X';break;
	case 1:a[0][0] = a[1][0] = a[2][0] = 'X';break;
	case 2:a[0][2] = a[1][2] = a[2][2] = 'X';break;
	case 3:a[2][0] = a[2][1] = a[2][2] = 'X';break;
	case 4:a[2][0] = a[3][0] = a[4][0] = 'X';break;
	case 5:a[2][2] = a[3][2] = a[4][2] = 'X';break;
	case 6:a[4][0] = a[4][1] = a[4][2] = 'X';break;
	}
}
int main()
{
	char a[100][5][3];memset(a, '.', sizeof(a));
	int n;cin >> n;int num[100];
	// 每个数字对应的段位（0~6）
	int segments[10][7] = {
		{1,1,1,0,1,1,1},  // 0
		{0,0,1,0,0,1,0},  // 1
		{1,0,1,1,1,0,1},  // 2
		{1,0,1,1,0,1,1},  // 3
		{0,1,1,1,0,1,0},  // 4
		{1,1,0,1,0,1,1},  // 5
		{1,1,0,1,1,1,1},  // 6
		{1,0,1,0,0,1,0},  // 7
		{1,1,1,1,1,1,1},  // 8
		{1,1,1,1,0,1,1}   // 9
	};
	for (int i = 0;i < n;i++)
	{
		cin >> num[i];
		for (int s = 0;s < 7;s++)
		{
			if (segments[num[i]][s])set(a[i], s);
		}
		
	}
	for (int j = 0;j < 5;j++)
	{
		for (int i = 0;i < n;i++)
		{
			for (int k = 0;k < 3;k++)
				cout << a[i][j][k];
			cout << " ";
		}
		cout << "\n";
	}

}
#endif
#define RUN_EXAMPLE_9 0
#if RUN_EXAMPLE_9 == 1
//习题5-1：梦中的统计
#include<iostream>
using namespace std;
void count(int a[10], int n)
{
	int i = 0;
	while (n > 0)
	{
		a[n % 10]++;//极致简洁
		n /= 10;
		i++;
	}
}
int main()
{
	int a[10] = { 0 };
	int n1, n2;cin >> n1 >> n2;
	for (int i = n1;i <= n2;i++)
		count(a, i);
	for (int i = 0;i < 10;i++)
	{
		cout << i << ":" << a[i] << endl;
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_10 0
#if RUN_EXAMPLE_10 == 1
//习题5-2：珠心算测试
#include<iostream>
using namespace std;
int main()
{
	int n;cin >> n;
	int a[100] = { 0 };bool isValid[100] = { 0 };
	for (int i = 0;i < n;i++)cin >> a[i];
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (j == i)continue;
			for (int k = j+1;k < n;k++)//规定k比j大
			{
				if (k == i || k == j)continue;
				if (a[i] == a[j] + a[k])
				{
					isValid[i] = 1;break;//找到就提前跳出到下一个数
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		if (isValid[i])sum++;
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_11 0
#if RUN_EXAMPLE_11 == 1
//习题5-3：爱与愁的心痛
//想想不用暴力枚举如何用一重循环解题？
//用前缀和避免序列内求和，循环输入的时候就顺便求和
#include<iostream>
using namespace std;
int main()
{
	int m,n;cin >>n>> m;//序列由n个数组成,子序列长度为m，
	int a[300] = { 0 }, sum[300] = { 0 };//前缀和思想再次应用：用sum[i]表示前i个元素之和，那么sum[m]-sum[n]表示从n+1到m这m-n个数的和
	sum[0] = 0;int min=1e9, flag = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	for (int i = 0;i <= n - m;i++)
	{
	 if (min > sum[i + m] - sum[i])
	{
		min = sum[i + m] - sum[i];
		flag = i;
	}
	}
	/*cout << "[";
	for (int i = flag;i < flag + m;i++)
		cout << a[i] << " ";
	cout << "]\n";*/
	cout << min << endl;
}
#endif
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 1
//习题5-4：牛骨头
#include<iostream>
//#include<ctime>
//#include<cstdlib>
using namespace std;
int main()
{
	//srand(time(0));//种下种子
	int n1, n2, n3;cin >> n1 >> n2 >> n3;//输入面数
	int sum[1000] = {0};
	//暴力枚举效率低
	/*int i = 1000;
	while (i--)
	{
		int s1 = rand() % n1 + 1, s2 = rand() % n2 + 1, s3 = rand() % n3 + 1;
		int s = s1 + s2 + s3;
		sum[s]++;
	}
	*///摇号无法处理概率相同
	for (int i = 1;i <= n1;i++)
	{
		for (int j = 1;j <= n2;j++)
		{
			for (int k = 1;k <= n3;k++)
			{
				sum[i + j + k]++;
			}
		}
	}
	int max = 0;int flag = 0;
	for (int j = 1;j <= n1 + n2 + n3;j++)
	{
		if (sum[j] > max||(sum[j] == max && j > flag))
		{
			max = sum[j];flag = j;
		}
	}
	cout << flag << endl;
	return 0;


}
#endif
#define RUN_EXAMPLE_13 0
#if RUN_EXAMPLE_13 == 1
//习题5-5：开灯
#include<iostream>
using namespace std;
int main()
{
	bool light[2000] = { 0 };
	int n;cin >> n;//一共进行n次操作
	for (int i = 0;i < n;i++)
	{
		 int a, t;cin >> a >> t;
		for (int j = 1;j <= t;j++)
		{
			light[j * a] = !light[j * a];
		}
	}
	int i = 0;
	while (light[i] == 0)i++;
	cout << i + 1 << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_14 0
#if RUN_EXAMPLE_14 == 1
//习题5-6：蛇形方阵
#include<iostream>
using namespace std;

int main()
{
	int n;cin >> n;
	int a[10][10] = { 0 };int num = 1;int temp = 0;int new_n = n;
	while (new_n >= 1)
	{
		for (int i = 0;i < new_n;i++)a[temp][i + temp] = num++;
		for (int i = 1;i < new_n;i++)a[i + temp][n - 1 - temp] = num++;
		for (int i = 1;i < new_n;i++)a[n - 1 - temp][n - 1 - i - temp] = num++;
		for (int i = 1;i < new_n - 1;i++)a[n - 1 - i - temp][temp] = num++;
		temp++;new_n -= 2;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
#endif
#define RUN_EXAMPLE_15 0
#if RUN_EXAMPLE_15 == 1
//习题5-7：杨辉三角
#include<iostream>
using namespace std;
int main()
{
	const int MAX_SIZE = 100;
	int a[MAX_SIZE][MAX_SIZE] = { 0 };//易于更改
	int n;cin >> n;
	for (int i = 0;i < n;i++)
	{
		a[i][0] = a[i][i] = 1;
		for (int j = 1;j <= i - 1;j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
#endif
#define RUN_EXAMPLE_16 0
#if RUN_EXAMPLE_16 == 1
//习题5-8：mc生存
#include<iostream>
using namespace std;
void set_torch(int a[100][100],int x,int y,int n)
{
	for (int i = x - 1;i <= x + 1;i++)
	{
		for (int j = y - 1;j <= y + 1;j++)
		{
			if (i >= 0 && i < n && j>=0 && j < n)a[i][j] = 1;
		}
	}
	if (y - 2 >= 0)a[x][y - 2] = 1;
	if (y + 2 < n)a[x][y + 2] = 1;
	if (x - 2 >= 0)a[x - 2][y] = 1;
	if (x + 2 < n)a[x + 2][y] = 1;
}
void set_glowstone(int a[100][100], int x, int y, int n)
{
	for (int i = x - 2;i <= x + 2;i++)
	{
		for (int j = y - 2;j <= y + 2;j++)
		{
			if (i >= 0 && i < n && j>=0 && j < n)a[i][j] = 1;
		}
	}
}
int main()
{
	int a[100][100] = { 0 },x[100],y[100],o[100],p[100];
	int n;cin >> n;
	int m, k;cin >> m >> k;
	for (int i = 0;i < m;i++)
	{
		cin >> x[i] >> y[i];
		set_torch(a, x[i], y[i],n);
	}
	for (int i = 0;i < k;i++)
	{
		cin >> o[i] >> p[i];
		set_glowstone(a, o[i], p[i],n);
	}
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			if (!a[i][j])sum++;
	}
	cout << sum << endl;
}
#endif
#define RUN_EXAMPLE_17 0
#if RUN_EXAMPLE_17 == 1
//习题5-9：压缩技术
#include<iostream>
using namespace std;
int main()
{
	int N, n;cin >> N>>n;//N为规模，n为压缩码个数
	int a[100];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	int i = 0;int num;int sum = 0;
	for (int i = 0;i < n;i++)
	{
		if (i % 2 == 0)num = 0;else num = 1;
		for (int j = 0;j < a[i];j++)
		{
			
			cout << num;sum++;
			if (sum % N == 0)cout << "\n";
		}
	}
}
#endif
#define RUN_EXAMPLE_18 0
#if RUN_EXAMPLE_18 == 1
//习题5-10：压缩技术————续集版
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int N;cin >> N;int a[300] = { 0 }; int temp = 0;  // 全部设为 2
	for (int i = 0;i < N;i++)
	{
		char s[100];int j = 0;cin >> s;
		for (int j = 0;j < N;j++)
		{
			a[temp] = s[j] - '0';
			temp++;
		}
	}

	int num[100] = { 0 };
	num[0] = N;int k = 1;
	for (int i = 1;i < N * N;i++)
	{
		if (a[i] == 0)
		{
			if (a[i - 1] != 0)
			{
				num[k]++;k++;
			}
			else num[k]++;
		}
		if (a[i] == 1)
		{
			if (a[i - 1] != 1)
			{
				num[k]++;k++;
			}
			else num[k]++;
		}
	}
	num[k]++;
	for (int i = 0;i <= k;i++)
		{
			cout << num[i] << " ";

		}
return 0;
}
#endif
#define RUN_EXAMPLE_19 0
#if RUN_EXAMPLE_19 == 0
//方块变换
//以后再说
#include<iostream>
using namespace std;
int main()
{

}
#endif















//模板

#define RUN_EXAMPLE_ 0
#if RUN_EXAMPLE_ == 1
#include<iostream>
using namespace std;
int main()
{

}
#endif

