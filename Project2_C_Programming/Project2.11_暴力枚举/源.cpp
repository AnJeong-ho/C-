#define _CRT_SECURE_NO_WARNINGS
#define RUN_EXAMPLE_1 0
//统计方形加强版
#if RUN_EXAMPLE_1 == 1
//根据矩阵右下角的点
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
typedef long long LL;
using namespace std;
int main()
{
	LL n, m, squ = 0, rec = 0;
	scanf("%lld%lld", &n, &m);
	for (LL x = 0;x <= n;x++)
	{
		for (LL y = 0;y <= m;y++)
		{
			LL tmp = min(x, y);//向左上作对角线，对角线上的点即为左顶点
			squ += tmp;
			rec += x * y - min(x, y);
		}
	}
	printf("%lld   %lld", squ, rec);
	return 0;

}
#endif
#if RUN_EXAMPLE_1 == 2
//根据边枚举
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;
int main()
{
	LL n, m, squ = 0, rec = 0;
	scanf("%lld%lld", &n, &m);
	for (LL x = 1;x <= n;x++)
	{
		for (LL y = 1;y <= m;y++)
		{
			//if (x == y)
				squ += (n - x + 1) * (m - y + 1);
			//else rec += (n - x + 1) * (m - y + 1);
		}
	}
	rec = n * (n + 1) * m * m * (m + 1) / 4 - squ;
	printf("%lld   %lld", squ, rec);
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//烤鸡
#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int ak[60000][10] = { 0 };
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	if (n < 10 || n>30)
	{
		printf("0");
		return 0;
	}
	rep(a, 1, 3)rep(b, 1, 3)rep(c, 1, 3)rep(d, 1, 3)rep(e, 1, 3)rep(f, 1, 3)rep(g, 1, 3)rep(h, 1, 3)rep(i, 1, 3)rep(j, 1, 3)
		if (a + b + c + d + e + f + g + h + i + j == n)
		{
			ans++;
			ak[ans][0] = a;ak[ans][1] = b;ak[ans][2] = c;ak[ans][3] = d;ak[ans][4] = e;
			ak[ans][5] = f;ak[ans][6] = g;ak[ans][7] = h;ak[ans][8] = i;ak[ans][9] = j;
	    }
	printf("%d\n", ans);
	for (int x = 1;x <= ans;x++)
	{
		for (int i = 0;i < 10;i++)
			printf("%d ", ak[x][i]);
		printf("\n");
	}
	return 0;

}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//三连击升级版
#include<iostream>
#include<cstring>
using namespace std;
int flag[10];
void go(int n)
{
	flag[n % 10] = 1;
	flag[n / 10 % 10] = 1;
	flag[n / 100 % 10] = 1;
}
int main()
{
	int A, B, C;cin >> A >> B >> C;bool is = 0;
	for (int a = 100;a < 1000;a++)
	{
		memset(flag, 0, sizeof(flag));
		if (a*B%A != 0 || a*C%A != 0)continue;
		int b = a*B/A, c = a*C/A;
		go(a);go(b);go(c);
		bool h=1;
		for (int i = 0;i < 10;i++)if (flag[i] == 0)h = 0;//如果全为1，说明符合,标识为true,否则为false
		if (h == 1)
		{
			cout << a << " " << b << " " << c << endl;
			is = 1;
		}
	}
	if (is == 0)cout << "No!!!" << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//选数
//从n个数中任选k个数相加
//有多少中情况和为质数
//可将n个数看作集合，用二进制表示全集中的元素是否在该集合中出现以遍历所有集合
//_builtin_popcount()获得整数对应的二进制数字中1的个数，1<<(i-1)获得仅包含第i个元素的子集
int a[30];//元素个数最多为30个，储存元素的数值
#include<iostream>
#include<cstdio>
using namespace std;
int _num_1(int q)
{
	int num = 0;
	while (q > 0)
	{
		if (q & 1)num++;
		q = q >> 1;
	}
	return num;
}
bool isPrime(int n)
{
	if (n < 2)return false;
	if (n < 4)return true;
	if (n % 2 == 0)return false;
	for (int i = 3;i * i <= n;i += 2)
		if (n % i == 0)return false;
	return true;
}
int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0;i < n;i++)cin >> a[i];
	int U = 1 << n;//U-1即为全集
	for (int q = 0;q < U;q++)//遍历所有子集
	{
		//if (__builtin_popcount(q) == k)
		if(_num_1(q)==k)//只选大小为k的子集
		{
			int num = 0;
			for (int i = 0;i < n;i++)
			{
				if (q & 1 << i)num += a[i];//第i位在的话加上其数值
			}
			if (isPrime(num))ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//组合的输出
//n个数任选r个数，按照顺序输出
int a[30];
#include<iostream>
using namespace std;
int main()
{
	int n, r;cin >> n >> r;
	for (int i = 0;i < n;i++)cin >> a[i];
	int U = 1 << n;
	for (int S = U-1;S >=0;S--)
	{
		int cnt = 0;
		for (int i = 0;i < n;i++)
		{
			if (S & 1 << i)a[cnt++] = i;//从右往左录入，a[0]在最右
		}
		if (cnt == r)
		{
			for (int i = r-1;i >=0;i--)//7  5   3  2  1   0   从前往后读取，从高位向低位读取
			{
				printf("%3d", n-a[i]);//1  3   5  6  7   8    录入方向 + 输出方向 + 反转映射，三重反转正好抵消，最终输出是从小到大。
			}
			puts(" ");
		}
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//三连击升级版新解法：
//next_permutation(start,end)以实现全排列，直到最后一个排列，之后返回0，和do_while搭配使用
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int a[10];
int main()
{
	LL A, B, C, x, y, z, cnt = 0;
	cin >> A >> B >> C;
	for (int i = 1;i <= 9;i++)a[i] = i;
	do
	{
		x = a[1] * 100 + a[2] * 10 + a[3];
		y = a[4] * 100 + a[5] * 10 + a[6];
		z = a[7] * 100 + a[8] * 10 + a[9];
		if (x * B == y * A && x * C == z * A)
		{
			printf("%lld %lld %lld\n", x, y, z);
			cnt++;
		}
	} while (next_permutation(a + 1, a + 10));//全排序
	if (!cnt)puts("No!!!");
	return 0;
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//全排列问题
//输出n的全排列
#include<iostream>
#include<algorithm>
using namespace std;
#define max_ 100
int a[max_];
int main()
{
	int n;cin >> n;
	for (int i = 1;i <= n;i++)a[i] = i;
	do
	{
		for (int i = 1;i <= n;i++)cout << a[i];
		cout << "\n";
	} while (next_permutation(a + 1, a + n + 1));
	return 0;
}
#endif
#define RUN_EXAMPLE_8 0
#if RUN_EXAMPLE_8 == 1
//火星人
#include<iostream>
#include<algorithm>
using namespace std;
#define max_ 100
int a[max_];
int main()
{
	int n,m;cin >> n>>m;
	for (int i = 1;i <= n;i++)cin >> a[i];
    while(m--)
	{
		next_permutation(a + 1, a + n + 1);
	} 
	for (int i = 1;i <= n;i++)cout << a[i];
	return 0;
}
#endif
#define RUN_EXAMPLE_9 0
#if RUN_EXAMPLE_9 == 1
//习题10-1：涂国旗
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define max_ 500
int flag[max_][max_];
int main()
{
	srand(time(0));
	int N, M;cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			flag[i][j] = rand() % 3;
		}
	}
	int index_1, index_2;
	int sum , min=1e6;
	for (index_1 = 0;index_1 < N - 1;index_1++)
	{
		for (index_2 = N - 1;index_2 >= index_1 + 1;index_2--)
		{
			sum = 0;
			for (int i = 0;i <= index_1;i++)
				for(int j=0;j<M;j++)
				if (flag[i][j] != 0)sum++;
			for (int i = index_1 + 1;i <= index_2-1;i++)
				for (int j = 0;j < M;j++)
					if (flag[i][j] != 1)sum++;
			for(int i=index_2;i<N;i++)
				for (int j = 0;j < M;j++)
					if (flag[i][j] != 2)sum++;
			if (sum < min)min = sum;
		}
	}
	cout << min << endl;
	return 0;

}
#endif
#define RUN_EXAMPLE_10 0
#if RUN_EXAMPLE_10 == 1
//习题10-2：First Step
#include<iostream>
using namespace std;
#include<cstdlib>
#include<ctime>
#define max_ 300
char field[max_][max_] = { 0 };
int main()
{
	int N, M;cin >> N >> M;int row[max_] = { 0 }, col[max_] = { 0 };
	int K;cin >> K;int num = 0;
	srand(time(0));
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (rand() % 4)
			{
				field[i][j] = '.';
				row[i]++;
				col[j]++;
				num++;
			}
			else field[i][j] = '#';
		}
	}
	int sum = 0;
	if (K == 1)
	{
		cout << num << endl;
		return 0;
	}
	if (K <= M)
	{
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j <= M - K;j++)
			{
				bool is = 1;
				for (int k = j;k < j + K;k++)
				{
					if (field[i][k] == '#')is = 0;
				}
				if (is)sum++;
			}
		}
	}
	if (K <= N)
	{
		for (int j = 0;j < M;j++)
		{
			for (int i = 0;i <= N - K;i++)
			{
				bool is = 1;
				for (int k = i;k < i + K;k++)
				{
					if (field[k][j] == '#')is = 0;
				}
				if (is)sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_11 0
#if RUN_EXAMPLE_11 == 1
//习题10-3：回文质数
#include<iostream>
using namespace std;
bool isPrime(long long n)
{
	if (n < 2)return false;
	if (n < 4)return true;
	if (n % 2 == 0)return false;
	for (int i = 3;i * i <= n;i += 2)
		if (n % i == 0)return false;
	return true;
}
#define max_ 200
int arry[max_];
bool isHui(long long n)
{
	int len = 0;
	while (n > 0)
	{
		arry[++len] = n % 10;
		n /= 10;
	}
	if (len == 1)return true;
	bool is = 1;
	for (int i = 1;i <= len / 2;i++)
	{
		if (arry[i] != arry[len + 1 - i])is = 0;
	}
	return is;
}
int main()
{
	long long a, b;cin >> a >> b;
	for (long long i = a;i <= b;i++)
	{
		if ( isHui(i) && isPrime(i))cout << i << endl;
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 1
//习题10-4：火柴棒等式
#include<iostream>
using namespace std;
int consume[10] = {6,2,5,5,4,5,6,3,7,6};
#define max_ 100
int a[max_];
int count_consume(int n)
{
	if (n == 0)return 6;
	int i = 0;int sum = 0;
	while (n > 0)
	{
		a[i++] = n % 10;
		n /= 10;
		sum += consume[a[i - 1]];
	}
	return sum;
}
int main()
{
	int n;cin >> n;int sum = 0;
	if (n <=10)return 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			int k = i + j;
				if (count_consume(i) + count_consume(j) + count_consume(k) + 4 == n)
					sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_13 0
#if RUN_EXAMPLE_13 == 1
//习题10-5：妖梦拼木棒
#include<iostream>
#include<algorithm>
using namespace std;
#define max_ 400
int ar[max_];
int _num_1(int q)
{
	int num = 0;
	while (q > 0)
	{
		if (q & 1)num++;
		q = q >> 1;
	}
	return num;
}
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++)cin >> ar[i];
	int U = 1 << n;
	int ans[4], count, sum = 0;
	for (int S = 0;S < U;S++)
	{
		if (_num_1(S) == 4)
		{
			count = 0;
			for (int i = 0;i < n;i++)
				if (S & 1 << i)ans[count++] = ar[i];
			sort(ans, ans + 4);
		if (ans[0] + ans[1] == ans[2]&&ans[2] == ans[3])sum++;//两个短边相加之后和两条边相等
		}
		
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_14 0
#if RUN_EXAMPLE_14 == 1
//习题10-6：kkksc03 考前抱佛脚
#include<iostream>
#include<cmath>
using namespace std;
#define max_ 200
int a[4][max_];
int main()
{
	int len[4];
	for (int i = 0;i < 4;i++)cin >> len[i];
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < len[i];j++)
		{
			cin >> a[i][j];
		}
	}
	int sum = 0;
	for (int i = 0;i < 4;i++)
	{
		int p1=0, p2=0, min_differ=1e6;
		int U = 1 << len[i];
		for (int S = 0;S < U;S++)
		{
			int t1 = 0,t2 = 0;
			for (int index = 0;index < len[i];index++)
			{
				if (S & 1 << index)t1 += a[i][index];
				else t2 += a[i][index];
			}
			if (abs(t1 - t2) < min_differ)
			{
				min_differ = abs(t1 - t2);
				p1 = t1;p2 = t2;
			}
		}
		sum += min(p1, p2) + min_differ;
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_15 0
#if RUN_EXAMPLE_15 == 1
//习题10-7：Perket
#include<iostream>
#include<cmath>
using namespace std;
#define max_ 10
int ar[2][max_];
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> ar[0][i] >> ar[1][i];
	}
	int U = 1 << n;int min_differ = 1e6;
	int temp;
	for (int S = 1;S < U;S++)
	{
		int t1 = 1, t2 = 0;
		for (int i = 0;i < n;i++)
		{
			if (S & 1 << i)
			{
				t1 *= ar[0][i];
				t2 += ar[1][i];
			}
		}
		if (abs(t1 - t2) < min_differ)
		{
			min_differ = abs(t1 - t2);
			temp = S;
		}
	}
	for (int i = 0;i < n;i++)
	{
		if (temp & 1 << i)cout << i << " ";
	}
	cout << min_differ << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_16 0
#if RUN_EXAMPLE_16 == 0
//习题10-8：吃奶酪
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define max_ 15
struct coor
{
	int x;
	int y;
	coor(){}
	coor(int a,int b):x(a),y(b){}
}cr[max_];//这里必须有默认构造函数
double dist(const coor& c1, const coor& c2)
{
	return sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2));
}
bool cmp(coor c1, coor c2)
{
	if (c1.x != c2.x)return c1.x < c2.x;
	return c1.y < c2.y;
}//定义比较规则，后续sort和next_permatation才有比较依据
int main()
{
	int n;cin >> n;double d;double mind = 1e10;
	for (int i = 0;i < n;i++)
	{
		cin >> cr[i].x >> cr[i].y;
	}
	coor begin(0, 0);
	sort(cr, cr + n,cmp);
	do
	{
		d = 0;
		d += dist(begin, cr[0]);
		for (int i = 0;i < n - 1;i++)
		{
			d += dist(cr[i], cr[i + 1]);
		}
		if (d < mind)mind = d;
	} while (next_permutation(cr, cr + n,cmp));//由于遇到全降序排列后返回0，所以在使用前需要升序排列
	cout << mind << endl;
	return 0;

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