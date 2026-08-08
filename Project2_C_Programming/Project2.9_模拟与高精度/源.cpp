#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
//乒乓球
//用数组a记录输入的数据，以便统一输入，统一输出
#include<iostream>
#include<cmath>
using namespace std;
int f[2] = { 11,21 };//赛制
int a[25 * 2500 + 10] = { 0 }, n = 0;
int main()
{
	char temp;
	while (1)
	{
		cin >> temp;
		if (temp == 'E')break;
		else if (temp == 'W')a[n++] = 1;//注意n++这一简便用法
		else if (temp == 'L')a[n++] = 0;
	}//记录输入
	for (int k = 0;k < 2;k++)//区分赛制
	{
		int w = 0, l = 0;
		for (int i = 0;i < n;i++)
		{
			w += a[i];l += 1 - a[i];
			if (max(w, l) >= f[k] && abs(w - l) >= 2)
			{
				cout << w << " : " << l << endl;
				w = l = 0;//注意，这里重置比分，开下一局，是为了处理溢出的数据
			}
			
		}
		cout << w << " : " << l << endl;
		cout << endl;//用以区分不同赛制
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//扫雷游戏
#include<iostream>
using namespace std;
int search(char a[][102], int n, int m)
{
	if (a[n][m] == '*')return 10;
	int sum = 0;
	for (int i = n - 1;i <= n + 1;i++)
	{
		sum += a[i][m - 1] == '*';
		sum += a[i][m + 1] == '*';
	}
	sum += a[n - 1][m]=='*';
	sum += a[n + 1][m]=='*';
	return sum;
}
int main()
{
	char a[102][102];//边界保护
	for (int i = 0;i < 102;i++)
	{
		for (int j = 0;j < 102;j++)
		{
			a[i][j] = '?';
		}
	}	
	int n, m;cin >> n >> m;
	//布置 30 颗地雷（10x10 区域，约 30 % 概率）
	int mineCount = 30;
	int placed = 0;
	while (placed < mineCount)
	{
		int x = rand() % n + 1;  // 1~n
		int y = rand() % m + 1;  // 1~m

		if (a[x][y] != '*')
		{
			a[x][y] = '*';
			placed++;
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (search(a, i, j) == 10)cout << '*' << " ";
			else cout << search(a, i, j) << " ";

		}
		cout << endl;
	}
	return 0;
}
#endif
#if RUN_EXAMPLE_2 == 2
//答案用到了偏移数组
//这个在数据结构中也用到了
#include<iostream>
const int dx[8] = {1,1,1,0,0,-1,-1,-1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};
#define max  105
char a[max][max];
using namespace std;
int n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (a[i][j] != '*')
			{
				int cnt = 0;
				for (int k = 0;k < 8;k++)
					if (a[i + dx[k]][j + dy[k]] == '*')cnt++;
				cout << cnt;
			}
			else cout << '*';
		}
		cout << endl;
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//玩具谜题
//用整除来完成圈
#include<iostream>
using namespace std;
#define max 100
struct node
{
	int head;
	string name;
	
}a[max];int n, m, x, y;
int main()
{
	cin >> n >> m;//n名同学，m次传递
	for (int i = 0;i < n;i++)
		cin >> a[i].head >> a[i].name;
	int now = 0;
	while (m--)
	{
		int direction, s;//传递方向，传递距离
		cin >> direction >> s;
		if (direction ^ a[now].head)//如果逆时针
			now = (now + n - s) % n;
		else now = (now + s) % n;
	}
	cout << a[now].name << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 2
//用双向链表解决击鼓传花
#include<iostream>
using namespace std;
struct Node
{
	int head;
	string name;
	Node* next;
	Node* prev;
};
int main()
{
	int n, m;
	cin >> n >> m;
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;
	for (int i = 0;i < n;i++)//创建链表
	{
		Node* p = new Node;
		cin >> p->head >> p->name;
		p->next = NULL;
		p->prev = NULL;
		if (head == NULL)
		{
			head = p;
			cur = p;
		}
		else
		{
			cur->next = p;
			p->prev = cur;
			cur = p;
		}
	}
	cur->next = head;
	head->prev = cur;//形成环
	while (m--)
	{
		int direction, step;
		cin >> direction >> step;
		if (direction ^ cur->head)
		{
			for (int i = 0;i < step;i++)
				cur = cur->prev;
		}
		else
		{
			for (int i = 0;i < step;i++)
				cur = cur->next;
		}
	}
	cout << cur->name << endl;
	return 0;

}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//A+B problem 高精度
//加法器
#include<iostream>
#include<cmath> 
using namespace std;
#define maxn 1000
int sum[maxn], a[maxn], b[maxn];
int main()
{
	string A, B;
	cin >> A >> B;
	int n1 = A.size(), n2 = B.size();
	for (int i = n1 - 1;i >= 0;i--)a[i] = A[i] - '0';
	for (int i = n2 - 1;i >= 0;i--)b[i] = B[i] - '0';
	for (int i = 0;i < max(n1, n2);i++)
	{
		int num = a[i] + b[i] + isCarry[0];
		isCarry[1] = num >= 10;
		sum[i] = isCarry[1] ? num - 10 : num;
		isCarry[0] = isCarry[1];
	}
	for (int i = max(n1, n2) + isCarry[1]-1;i >= 0;i--)cout << sum[i];
	cout << endl;
	return 0;

}
#endif
#if RUN_EXAMPLE_4 == 2
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 1000
int sum[maxn], a[maxn], b[maxn];
int main()
{
	string A, B;
	cin >> A >> B;
	int n1 = A.size(), n2 = B.size();
	for (int i = n1 - 1;i >= 0;i--)a[i] = A[i] - '0';
	for (int i = n2 - 1;i >= 0;i--)b[i] = B[i] - '0';
	int i;int carry = 0;
	for (i = 0;i < max(n1, n2);i++)
	{
		sum[i] = a[i] + b[i] + carry;
		carry = sum[i] / 10;
		sum[i] %= 10;
	}
	for (int j= max(n1, n2)+carry-1;j >= 0;j--)cout << sum[j];
	cout << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//A*B problem
#include<iostream>
#include<cmath> 
using namespace std;
#define max_ 1000
int a[max_], b[max_], mul[max_];
void add(int a[],int n1,int b[],int n2,int sum[max_],int& n3)//n1,n2为有效位而非数组容量，无效位为0；n1,n2最低为为0
{
	int i;int carry = 0;
	for (i = 0;i < max(n1, n2);i++)
	{
		
		sum[i] = a[i] + b[i] + carry;
		carry = sum[i] / 10;
		sum[i] %= 10;
		
	}
	sum[i] = 0;
	if (carry != 0)sum[i] = carry;
	n3 = max(n1,n2)+sum[i];
}
void single_mul(int a[], int n1, int num,int mul[],int& n3)
{
	int i;int carry = 0;
	for (i = 0;i < n1;i++)
	{
		mul[i] = a[i] * num + carry;
		carry = mul[i] / 10;
		mul[i] %= 10;
	}
	mul[i] = 0;
	if (carry != 0)mul[i] = carry;
	n3 = n1 + mul[i];
}
void mul_10(int a[], int n1, int mul[], int& n2)//直接移位运算
{
	for (int i = n1-1;i >=0;i--)
	{
		mul[i + 1] = a[i];
	}
	mul[0] = 0;
	n2 = n1 + 1;
}
void copy(int a[], int n1, int b[], int& n2)
{
	n2 = n1;
	for (int i = 0;i < n2;i++)
		b[i] = a[i];
}
void mutiply(int a[], int n1, int b[], int n2, int mul[], int& n3)
{
	int c[max_] = { 0 };int n_c=0;
	for (int i = 0;i < n2;i++)
	{
		int temp[max_] = { 0 };int n4 = 0;
		int tem = i;
		single_mul(a, n1, b[i], temp, n4);
		while (tem--)
		{
			mul_10(temp, n4, temp, n4);
		}
		add(temp, n4, mul, n3, c, n_c);
		copy(c, n_c, mul, n3);
	}
}
int main()
{
	string A, B;
	cin >> A >> B;
	int n1 = A.size(), n2 = B.size();int n3=0;
	for (int i = n1 - 1;i >= 0;i--)a[i] = A[n1-1-i] - '0';
	for (int i = n2 - 1;i >= 0;i--)b[i] = B[n2-1-i] - '0';
	mutiply(a, n1, b, n2, mul, n3);
	for (int i = n3 - 1;i >= 0;i--)cout << mul[i];
	cout << endl;
	return 0;
}
#endif
//当两个参数指向同一个数组的时候，可能会发生数据覆盖进而遗失数据，还要自己定义copy函数，手动拷贝，后面计算高精度阶乘之和的时候会用到结构体或者类，以实现拷贝构造
#if RUN_EXAMPLE_5 == 2
//根据答案的算法：有这样的规律：乘数的第i位和被乘数的第j位乘积作用于积的第i+j-1位，大于10的部分贡献给更高位，本位剩下模10的部分
//这种方法很简单，不详细做了
#include<iostream>
#include<string>
using namespace std;

#define maxn 1000

int a[maxn], b[maxn], c[maxn];

int main() {
	string A, B;
	cin >> A >> B;

	int n1 = A.size(), n2 = B.size();

	// 1. 倒序存储，让a[1]为个位
	for (int i = 1; i <= n1; i++) {
		a[i] = A[n1 - i] - '0';
	}
	for (int i = 1; i <= n2; i++) {
		b[i] = B[n2 - i] - '0';
	}

	// 2. 核心乘法：错位相加
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			c[i + j - 1] += a[i] * b[j];
		}
	}

	// 3. 统一处理进位
	int len = n1 + n2; // 乘积的最大位数
	for (int i = 1; i <= len; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}

	// 4. 去除前导零，同时确保至少保留一位
	while (len > 1 && c[len] == 0) {
		len--;
	}

	// 5. 逆序输出结果
	for (int i = len; i >= 1; i--) {
		cout << c[i];
	}
	cout << endl;

	return 0;
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//阶乘之和
#include<iostream>
using namespace std;
#define max_ 1000
int _1[max_] = { 1 };
void add(int a[], int n1, int b[], int n2, int sum[max_], int& n3)//n1,n2为有效位而非数组容量，无效位为0；n1,n2最低为为0
{
	int i;int carry = 0;
	for (i = 0;i < max(n1, n2);i++)
	{

		sum[i] = a[i] + b[i] + carry;
		carry = sum[i] / 10;
		sum[i] %= 10;

	}
	sum[i] = 0;
	if (carry != 0)sum[i] = carry;
	n3 = max(n1, n2) + sum[i];
}
void mul(int a[], int n1, int b[], int n2, int mul[max_], int& n3)
{
	for (int i = 0; i < n1 + n2; i++)
		mul[i] = 0;//清零
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			mul[i + j] += a[i] * b[j];
	int len = n1 + n2;
	for (int i = 0; i < len; i++)
	{
		mul[i + 1] += mul[i] / 10;
		mul[i] %= 10;
	}
	while (len > 1 && mul[len - 1] == 0)
		len--;
	n3 = len;
}
bool isVal(int a[], int n1, int b[], int n2)
{
	if (n1 != n2)return false;
	else
	{
		for (int i = 0;i < n1;i++)
			if (a[i] != b[i])return false;
	}
	return true;
}
void copy(int a[], int n1, int b[], int& n2)
{
	n2 = n1;
	for (int i = 0;i < n2;i++)
		b[i] = a[i];
}
void fac(int a[], int n1, int ans[], int& n2)
{
	int temp[max_], n_tem = 0;int base[max_] = { 1 }, n_base = 1;ans[0] = 1; n2 = 1;
	while (!isVal(base, n_base, a, n1))
	{
		add(base, n_base, _1, 1, temp, n_tem);
		copy(temp, n_tem, base, n_base);
		mul(ans, n2, base, n_base, temp, n_tem);
		copy(temp, n_tem, ans, n2);
	}
}
int ans[max_] = { 0 };int n_ans = 0;int temp[max_] = { 0 }, n_tem = 0;
int base[max_] = { 1 }, n_base = 1;int mult[max_], n_mul = 0;
int main()
{
	string n;cin >> n;
	int len = n.size();
	int a[max_];
	for (int i = len - 1;i >= 0;i--)a[i] = n[len - 1 - i]-'0';
	while (!isVal(base, n_base, a, len))
	{
		fac(base, n_base, mult, n_mul);
		add(ans, n_ans, mult, n_mul, temp, n_tem);
		copy(temp, n_tem, ans, n_ans);
		add(base, n_base, _1, 1, temp, n_tem);
		copy(temp, n_tem, base, n_base);
	}
	fac(base, n_base, mult, n_mul);
	add(ans, n_ans, mult, n_mul, temp, n_tem);
	copy(temp, n_tem, ans, n_ans);
	for (int i = n_ans-1;i >= 0;i--)cout << ans[i];
	return 0;
}
#endif
#if RUN_EXAMPLE_6 == 0
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define max_ 10000

struct Bigint
{
	int len, a[max_];

	Bigint(int n = 0)
	{
		memset(a, 0, sizeof(a));
		len = 0;
		if (n == 0) {
			a[0] = 0;
			len = 1;
			return;
		}
		while (n > 0 && len < max_) {
			a[len++] = n % 10;
			n /= 10;
		}
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

	void print()
	{
		for (int i = len - 1; i >= 0; i--)
			cout << a[i];
	}
};

Bigint operator+( Bigint& a,  Bigint& b)
{
	Bigint c;
	int len = max(a.len, b.len);
	for (int i = 0; i < len; i++) {
		c[i] += a[i] + b[i];
	}
	c.flatten(len + 2);
	return c;
}

Bigint operator*( Bigint& a, int b)
{
	Bigint c;
	int len = a.len;
	for (int i = 0; i < len; i++) {
		c[i] += a[i] * b;
	}
	c.flatten(len + 20);
	return c;
}

int main()
{
	Bigint ans(0), fac(1);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		fac = fac * i;
		ans = ans + fac;
	}

	ans.print();
	cout << endl;

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