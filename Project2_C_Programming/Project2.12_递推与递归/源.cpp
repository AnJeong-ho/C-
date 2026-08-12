#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
//数楼梯
int count_(int n)
{
	if (n == 1)return 1;
	if (n == 2)return 2;
	return count_(n - 1) + count_(n - 2);
}
//这是递归，由n向1递归，效率极低
#endif
#if RUN_EXAMPLE_1 == 2
#include<iostream>
using namespace std;
//运用递推
#define max_ 100
struct Bigint
{
	int a[max_];
	int len;
	Bigint(int n=0)
	{
		len = 0;
		for (int i = 0;i < max_;i++) a[i] = 0;//清零
		if (n == 0) {
			a[len++] = 0;
			return;
		}//特殊情况
		while (n > 0)
		{
			a[len++] = n % 10;
			n /= 10;
		}
	}
	void print()
	{
		for (int i = len-1;i >= 0;i--)cout << a[i];
		cout << endl;
	}
	int& operator[](int i)
	{
		return a[i];
	}

	void flatten(int L)
	{
		if (L >= max_) L = max_ - 1;
		if (L < 1) L = 1;

		len = L;
		for (int i = 0; i < len; i++) {
			if (i + 1 < max_) {
				a[i + 1] += a[i] / 10;
			}
			a[i] %= 10;
		}

		while (len > 1 && a[len - 1] == 0) {
			len--;
		}
	}
}f[max_];
Bigint operator+(Bigint& a, Bigint& b)
	{
		Bigint c;
		for (int i = 0;i < max_;i++) c.a[i] = 0;//数组清零，否则位垃圾值
		int len = max(a.len, b.len);
		for (int i = 0; i < len; i++) {
			c[i] += a[i] + b[i];
		}
		c.flatten(len + 2);
		return c;
	}
int main()
{
	int N;cin >> N;
	f[1] = Bigint(1);
	f[2] = Bigint(2);
	for (int i = 3;i <= N;i++)
	{
		f[i] = f[i - 2] + f[i - 1];
	}
	f[N].print();
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//过河卒
//易知，由于左上角出发的卒只能向下或者向右运动，故到达某点的路径数等于上面一点的路径数＋左面一点的路径数，若在最上或最左，不变，路径数为1
//输入卒的位置和马的位置
#include<iostream>
using namespace std;
#define max_ 22
long long f[max_][max_] = { 0 };
int ctrl[max_][max_] = { 0 }, m, n, hx, hy;
int d[9][2] = { {0,0},{1,2},{2,1},{1,-2},{-1,2},{-1,-2},{-2,1},{2,-1},{-2,-1} };
int main()
{
	cin >> n >> m >> hx >> hy;
	for (int i = 0;i < 9;i++)
	{
		int temx = hx + d[i][0], temy = hy + d[i][1];
		if(temx>=0&&temx<=n&&temy>=0&&temy<=m)
		ctrl[temx][temy] = 1;
	}
	if (!ctrl[0][0])f[0][0] = 1;
	for(int i=0;i<=n;i++)
		for (int j = 0;j <= m;j++)//双层循环实现递推
		{
			if (ctrl[i][j])continue;//遇到障碍跳过
			if (i)f[i][j] += f[i - 1][j];
			if (j)f[i][j] += f[i][j - 1];
		}
	cout << f[n][m] << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//栈
//让最后一个出管的球从1到n遍历，
//观察第k个管子的出管方式，前面右k-1个球，f(k-1)个出管方式，后面右N-k个球，有f(N-k)个出管方式，则
//h(n)=h(0)*h(n-1)+...+h(n-1)*h(0)
//易知h(0)=h(1)=1
#include<iostream>
using namespace std;
#define max_ 100
int h[max_] = { 0 };
int main()
{
	int n;cin >> n;
	h[0] = h[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		for (int j = 0;j < i;j++)
		{
			h[i] += h[j] * h[i-1-j];
		}
	}
	cout << h[n] << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//数的计算
#include<iostream>
using namespace std;
int count(int n)
{
	if (n <= 1)return 1;
	int ans = 1;
	for (int i = 1;i <= n / 2;i++)
		ans += count(i);
	return ans;
}
int main()
{
	int n;cin >> n;
	cout << count(n) << endl;
	return 0;
}
#endif
#if RUN_EXAMPLE_4 == 1
#include<iostream>
#include<cstring> 
using namespace std;
int  f[1010];
int sol(int x)
{
	int ans = 1;
	if (f[x] != -1)return f[x];
	for (int i = 1;i <= x / 2;i++)
		ans += sol(i);
	return f[x]=ans;

}

int main()
{
	int n;cin >> n;
	memset(f, -1, sizeof(f));
	f[1] = 1;
	cout << sol(n) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//Function
long long w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	if (a >= 20 || b >= 20 || c >= 20)return w(20, 20, 20);
	if (a < b && b < c)return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
#include<iostream>
using namespace std;
int main()
{
	int a, b, c;cin >> a >> b >> c;
	cout << w(a, b, c) << endl;
	return 0;
}
#endif
#if RUN_EXAMPLE_5 == 2
//改版：记忆化搜索
#include<iostream>
using namespace std;
long long f[25][25][25] = { 0 };
long long w(int a, int b, int c)
{
	if (f[a][b][c] != 0)return f[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0)return f[a][b][c]=1;
	if (a >= 20 || b >= 20 || c >= 20)return f[a][b][c] = w(20, 20, 20);
	if (a < b && b < c)return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	int a, b, c;cin >> a >> b >> c;
	cout << w(a, b, c) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//外星密码
#include<iostream>
#include<cstring>
using namespace std;
string expand()
{
	string s = "", X;
	char c;int d;
	while (cin >> c)
	{
		if (c == '[')
		{
			cin >> d;
			X = expand();
			while (d--)s += X;
		}
		else if (c == ']')return s;
		else s += c;//不在括号内部的直接加
	}
}
int main()
{
	cout << expand() << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//习题11-1：蜜蜂路线
#include<iostream>
using namespace std;
int sol(int m, int n)
{
	if (m > n)return 0;
	if (n-m==1||n==m)return 1;
	if (n - m == 2)return 2;
	return sol(m, n - 1) + sol(m, n - 2);
}
int main()
{
	int M, N;cin >> M >> N;
	cout << sol(M, N) << endl;
	return 0;
}
#endif
#if RUN_EXAMPLE_7 == 2
#include<iostream>
using namespace std;
#define max_ 100
int f[max_][max_] = {0};
int sol(int m, int n)
{
	if (m > n)return 0;
	if (n - m == 1 || n == m)return 1;
	if (n - m == 2)return 2;
	if (f[m][n] != 0)return f[m][n];
	return sol(m, n - 1) + sol(m, n - 2);
}
int main()
{
	int M, N;cin >> M >> N;
	cout << sol(M, N) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_8 0
//习题11-2：小A点菜
#if RUN_EXAMPLE_8 == 1
//子集枚举法
#include<iostream>
using namespace std;
#define max_ 300
int a[max_], N, M;
int main()
{
	cin >> N >> M;
	for (int i = 0;i < N;i++)cin >> a[i];
	int U = 1 << N;int sum = 0;
	for (int S = 0;S < U;S++)
	{
		int temp = 0;
		for (int i = 0;i < N;i++)
			if (S & 1 << i)temp += a[i];
		if (temp == M)sum++;
	}
	cout << sum << endl;
	return 0;
}
#endif
#if RUN_EXAMPLE_8 == 2
//背包DP法
#include<iostream>
using namespace std;
#define max_ 300
int a[max_], N, M;
int dp[max_] = { 0 };
int main()
{
	cin >> N >> M;
	for (int i = 0;i < N;i++)cin >> a[i];
	dp[0] = 1;
	for (int i = 0;i < N;i++)
	{
		for (int j = M;j >= a[i];j--)//注意这里，从大到小遍历是1-0背包，从小到大遍历是完全背包
		{
			dp[j] += dp[j - a[i]];
		}
	}
	cout << dp[M] << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_9 0
//习题11-3：选数
#if RUN_EXAMPLE_9 == 1
//子集枚举法
#include<iostream>
using namespace std;
#define max_ 100
int a[max_];
bool isPrime(int n)
{
	if (n < 2)return false;
	if (n < 4)return true;
	if (n % 2 == 0)return false;
	for (int i = 3;i * i <= n;i += 2)if (n % i == 0)return false;
	return true;
}
int num(int S)
{
	int sum = 0;
	while (S > 0)
	{
		if (S & 1)sum++;
		S = S >> 1;
	}
	return sum;
}
int main()
{
	int n, k;cin >> n >> k;
	for (int i = 0;i < n;i++)cin >> a[i];
	int U = 1 << n;int count = 0;
	for (int S = 0;S < U;S++)
	{
		if (num(S) == k)
		{
			int sum = 0;
			for (int i = 0;i < n;i++)
				if (S & 1 << i)sum += a[i];
			if (isPrime(sum) == 1)count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif
#if RUN_EXAMPLE_9 == 2
//DP解法
#include<iostream>
using namespace std;
bool isPrime(int n)
{
	if (n < 2)return false;
	if (n < 4)return true;
	if (n % 2 == 0)return false;
	for (int i = 3;i * i <= n;i += 2)if (n % i == 0)return false;
	return true;
}
#define max_sum 30000  //最大和
#define max_num 30
int a[max_num];
int bag[max_num][max_sum] = { 0 };//选num的数，和为sum的方案数
int main()
{
	int n, k;cin >> n >> k;
	for (int i = 0;i < n;i++)cin >> a[i];
	bag[0][0] = 1;
	for (int i = 0;i < n;i++)//遍历每个数
	{
		for (int j = k;j >= 1;j--)//从大到小遍历，1-0背包，个数遍历
		{
			for (int s = a[i];s < max_sum;s++)
			{
				bag[j][s] += bag[j - 1][s - a[i]];//由最外层的i可知，已经选了一道菜，菜价格为a[i],那怎样实现买j道菜，花了s钱呢，在该道菜的基础上买j-1道菜，花了s-a[i]钱
				                                  //由于已经选了i,所以s从a[i]开始，直到max_sum
			}
		}
	}
	int ans = 0;
	for (int i = 0;i < max_sum;i++)
	{
		if (isPrime(i))
			ans += bag[k][i];
	}
	cout << ans << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_10 0
//习题11-4：覆盖墙壁
#if RUN_EXAMPLE_10 == 1
#include<iostream>
using namespace std;
#define max_ 10000
const int MOD = 10000;
int dp[max_][2];
int main()
{
	int n;cin >> n;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[0][1] = 0;
	dp[1][1] = 0;
	for (int i = 2;i <= n;i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2 * dp[i - 2][1]) % MOD;
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
		//记录平整还是突出的状态即可，我用index表示高度，这是没必要的
	}
	cout << dp[n][0] % MOD << endl;
	return 0;

}
#endif
#define RUN_EXAMPLE_11 0
//习题11-5：秘密奶牛码
#if RUN_EXAMPLE_11 == 1
#include<iostream>
using namespace std;
string reverse_add(string s, int N)
{
	int i = s.size();
	if(i <= N)
	{
		string s2 = s;
		s2 += s[i - 1];
		for (int j = 0; j < i - 1; j++)    // 加前面的字符（去掉最后一个）
			s2 += s[j];
		return reverse_add(s2, N);
	}
	return s;
}
int main()
{
	string s;cin >> s;
	int N;cin >> N;
	string ans = reverse_add(s, N);
	cout << ans[N-1] << endl;
	return 0;
}
#endif
#if RUN_EXAMPLE_11 == 2
//逆向定位法：无需构造完整字符串
#include<iostream>
using namespace std;
string s;
long long N;
char find_char(long long n,long long len)//len为虚拟长度
{
	if (n <= s.size())return s[n - 1];
	long long half = len / 2;
	if (n <= half)return find_char(n,len/2);//落在前半段，长度减半
	long long  offset = n - half;
	if (offset == 1)return find_char(half,len)；//加入的最后一个字符
	return find_char(offset-1,len/2);//加入的翻转字符
}
int main()
{
	cin >> s >> N;
	int len = s.size();
	while (len <= N)len *= 2;
	cout << find_char(N,len) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 1
//习题11-6：黑白棋子的移动
#include<iostream>
#include<algorithm>
using namespace std;
int a[200] = { 0 };
int step = 1;
void show(int n)
{
	if (n == 2)cout << 'o';
	else if (n == 1)cout << '*';
	else cout << '-';
}
void move(int a[], int m,int n,int N)
{
	swap(a[m-1], a[n-1]);
	swap(a[m], a[n]);
	printf("step %d:", step);
	for (int i = 0;i < N;i++)show(a[i]);
	printf("\n");
	step++;
}
void sol(int a[], int n,int N)//整理前n个棋子，共N个棋子
{
	if (n <= 10)//进入斩杀线
	{
		move(a, 4, 9, N);
		move(a, 4, 8, N);
		move(a, 2, 8, N);
		move(a, 2, 7, N);
		move(a, 1, 7, N);return;
	}
	move(a, (n-2)/2, n - 1, N);
	move(a, (n-2)/2, n - 3, N);
	sol(a, n-2, N);//后两个被整理，整理前n-2个

}
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++)
	{
		a[i] = 2;//白
		a[i + n] = 1;//黑
	}
	printf("step 0:");
	for (int i = 0;i < 2*n+2;i++)show(a[i]);
	printf("\n");
	sol(a, 2*n+2, 2*n+2);
	return 0;
}
#endif
#define RUN_EXAMPLE_13 0
#if RUN_EXAMPLE_13 == 1
//习题11-7：幂次方
#include<iostream>
using namespace std;
void sol(int n)
{
	if (n == 0)return;
	if (n == 1) {printf("2(0)");return;}
	if (n == 2)	{printf("2");return;}
	if (n == 3) {printf("2+2(0)"); return; }
	int i = 1, count = 0;
	while (i <= n)
	{
		i *= 2;
		count++;
	}
	count -= 1;i/=2;
	if (count != 0)
	{
		printf("2(");
		sol(count);
		printf(")");
	}
	int remain = n - i;
	if (remain > 0)//如果等于0，说明是2的倍数，易知这是结尾了，之后不再有加号
	{
		printf("+");
		sol(remain);
	}
	
}
int main()
{
	int n;cin >> n;
	printf("%d=", n);
	sol(n);
	return 0;
}
#endif
#define RUN_EXAMPLE_14 0
#if RUN_EXAMPLE_14 == 1
//习题11-8：地毯填补问题
#include<iostream>
using namespace std;
int k, x, y;
void solve(int x, int y, int sx, int sy, int size)
{
	if (size == 1)return;
	int half = size / 2;
	int center_x = x + half - 1;
	int center_y = y + half - 1;
	if (sx <= center_x && sy <= center_y)
	{
		printf("%d %d 1\n", center_x + 1, center_y + 1);
		printf("%d %d 2\n", center_x + 1, center_y);
		printf("%d %d 3\n", center_x, center_y + 1);
		solve(x, y, sx, sy, size / 2);
		solve(center_x + 1, center_y + 1, center_x + 1, center_y + 1, size / 2);
		solve(x, center_y + 1, x, center_y + 1, size / 2);
		solve(center_x + 1,y, center_x + 1, y,size / 2);
	}
	else if (sx <= center_x && sy > center_y)
	{
		printf("%d %d 1\n", center_x + 1, center_y);
		printf("%d %d 2\n", center_x + 1, center_y + 1);
		printf("%d %d 4\n", center_x, center_y);

		solve(x, y, center_x, center_y, half);
		solve(x, y + half, sx, sy, half);
		solve(x + half, y, center_x + 1, center_y, half);
		solve(x + half, y + half, center_x + 1, center_y + 1, half);
	}
	else if (sx > center_x && sy <= center_y)
	{
		printf("%d %d 1\n", center_x, center_y + 1);
		printf("%d %d 3\n", center_x + 1, center_y + 1);
		printf("%d %d 4\n", center_x, center_y);

		solve(x, y, center_x, center_y, half);
		solve(x, y + half, center_x, center_y + 1, half);
		solve(x + half, y, sx, sy, half);
		solve(x + half, y + half, center_x + 1, center_y + 1, half);
	}
	else
	{
		printf("%d %d 2\n", center_x, center_y + 1);
		printf("%d %d 3\n", center_x + 1, center_y);
		printf("%d %d 4\n", center_x, center_y);

		solve(x, y, center_x, center_y, half);
		solve(x, y + half, center_x, center_y + 1, half);
		solve(x + half, y, center_x + 1, center_y, half);
		solve(x + half, y + half, sx, sy, half);
	}

}
int main()
{

	cin >> k >> x >> y;
	solve(1, 1, x, y, 1 << k);
	return 0;
}
#endif
#define RUN_EXAMPLE_15 0
#if RUN_EXAMPLE_15 == 1
//习题11-9：南蛮图腾
#include<iostream>
using namespace std;
char a[1000][1000];
void make(char a[1000][1000],int x,int y,int n)
{
	if (n == 1)
	{
		a[x][y] = ' ';a[x][y + 1] = '/';a[x][y + 2] = '\\';a[x][y + 3] = ' ';
		a[x + 1][y] = '/';a[x + 1][y + 1] = '_';a[x + 1][y + 2] = '_';a[x + 1][y + 3] = '\\';
	}
	else
	{
		int len = 1 << (n - 1);
		make(a, x, y + len, n - 1);
		make(a, x + len, y, n - 1);
		make(a, x + len, y + len * 2, n - 1);
	}
} 
void show(char a[1000][1000], int n)
{
	int len = 1 << (n+1);
	for (int i = 0;i < len;i++)
	{
		for (int j = 0;j < len;j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n;cin >> n;
	int len = 1 << (n + 1);
	for (int i = 0;i < len;i++)
	{
		for (int j = 0;j < len;j++)
		{
			a[i][j] = ' ';
		}
	}
	make(a, 0, 0, n);
	show(a, n);
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