//由于函数基础较简单，本章只侧重于函数递归与结构体
#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
//计算阶乘
#include<iostream>
using namespace std;
int product(int n)
{
	if (n == 1)return 1;
	return n * product(n - 1);
}
int main()
{
	int n;cin >> n;
	cout << product(n) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//赦免战俘
#include<iostream>
#include<cmath>
using namespace std;
const int MAX = 1000;
int a[MAX][MAX] = { 0 };//把数组设成全局变量，储存在内存较大的静态存储区而非较小的栈
void free(int x, int y, int len)
{
	if (len == 2)a[x][y] = 0;
	else
	{
		for (int i = x;i < x + len / 2;i++)
		{
			for (int j = y;j < y + len / 2;j++)
			{
				a[i][j] = 0;
			}
		}
		free(x + len / 2, y, len / 2);
		free(x, y + len / 2, len / 2);
		free(x + len / 2, y + len / 2, len / 2);
	}
}
int main()
{
	//int a[400][400] = { 0 };
	int n;cin >> n;
	//int len = pow(2, n);
	int len = 1 << n;//对于左移运算符，i<<n的值是i*pow(2,n);相应的，对于右移运算符,i>>n的值是i/pow(2,n)
	for (int i = 0;i < len;i++)
	{
		for (int j = 0;j < len;j++)
		{
			a[i][j] = 1;
		}
	}
	free(0, 0, len);
	for (int i = 0;i < len;i++)
	{
		for (int j = 0;j < len;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//旗鼓相当的对手(加强版)
#include<iostream>
using namespace std;
const int MAX = 1024;
struct student
{
	string name;
	int chinese,math,english;
};
bool check(int a, int b, int n)
{
	//if (a - b <= n && b - a <= n)return 1;
	//return 0;
	return a - b <= n && b - a <= n;
}
struct student std[MAX];//学生结构体类型数组的声明与定义，该类型为struct student，不要漏掉
int main()
{
	int n, ans;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> std[i].name >> std[i].chinese >> std[i].math >> std[i].english;
	}
	for (int i = 0;i < n-1;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			if (check(std[i].chinese, std[j].chinese, 5)
				&& check(std[i].math, std[j].math, 5)
				&& check(std[i].english, std[j].english, 5)
				&& check(std[i].chinese + std[i].math + std[i].english, std[j].chinese + std[j].math + std[j].english, 10))
				cout << std[i].name << " " << std[j].name << endl;
		}
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//评等级
#include<iostream>
using namespace std;
struct student
{
	int number;
	int score;
	int ex_score;
	double ave_score;
	student(int a, int b, int c):number(a),score(b),ex_score(c)
	{
		ave_score = 0.7 * score + 0.3 * ex_score;
	}
	int sum() const//既然不改变成员变量，那么加const修饰
	{
		return score + ex_score;
	}
};
bool isExcellent(const student& s)//传常引用，优点是不用拷贝
{
	return s.sum() > 140 && s.ave_score >= 80;
}
int main()
{
	int N;cin >> N;
	for (int i = 0;i < N;i++)
	{
		int a, b, c;cin >> a >> b >> c;
		student s1=student(a, b, c);
		if (isExcellent(s1))
			cout << "优秀" << endl;
	}
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
bool isPrime(int n)
{
	if (n < 2)return false;
	if (n < 4)return true;
	if (n % 2 == 0)return false;
	for (int i= 3;i * i <= n;i+=2)  //只检查奇数，不用判断是否整除偶数
	{
		if (n % i == 0)return false;
	}
	return true;
}
//哥德巴赫猜想
#include<iostream>
using namespace std;
int main()
{
	int N;cin >> N;
	if (N % 2)
	{
		cout << "error" << endl;
		return 0;
	}
	for (int i = 4;i <= N;i+=2)
	{
		for (int j = 2;j <= i / 2;j++)
		{
			if (isPrime(j) && isPrime(i - j))
			{
				cout << i << "=" << j << "+" << i - j << endl;
				break;
			}
		}
	}
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//集合求和
#include<iostream>
using namespace std;
int sum(int a[], int n)
{
	int summary = 0;
	for (int i = 0;i < n;i++)
	{
		summary += a[i];
	}
	summary *= 1 << (n - 1);
	return summary;
}
int main()
{
	int N;cin >> N;
	int a[30] = { 0 };
	for (int i = 0;i < N;i++)
		cin >> a[i];
	cout << sum(a, N) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//倒序输出
#include<iostream>
using namespace std;
void  show_reverse(int n)
{
	if (n == 0)return;
	int temp = n % 10;
	cout << temp;
	n /= 10;
	show_reverse(n);
	
}
int main()
{
	int n;cin >> n;
	show_reverse(n);
	return 0;
}
#endif
#define RUN_EXAMPLE_8 0
#if RUN_EXAMPLE_8 == 1
//辗转相除法求最大公因数
#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main()
{
	int a, b;cin >> a >> b;
	cout << gcd(a,b) << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_9 0
#if RUN_EXAMPLE_9 == 1
//猴子吃桃
#include<iostream>
using namespace std;
int eat(int n)
{
	if (n == 0)return 1;
	return (eat(n - 1) + 1) * 2;
}
int main()
{
	int n;cin >> n;
	cout << eat(n) << endl;
}
#endif
#if RUN_EXAMPLE_9 == 0
#include<iostream>
using namespace std;
int eat(int day,int total_day)
{
	if (day == total_day)return 1;
	return (eat(day + 1, total_day) + 1) * 2;
}
int main()
{
	int n;cin >> n;
	cout << eat(1,n+1) << endl;
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