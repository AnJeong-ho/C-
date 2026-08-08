#define max_ 100
#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
//计数排序：投票
#include<iostream>
using namespace std;

int main()
{
	int m, n;cin >> m >> n;//m张选票，n名候选人
	int a[max_] = { 0 };
	for (int i = 1;i <= m;i++)
	{
		int temp;cin >> temp;
		a[temp]++;
	}
	for (int i = 0;i < n;i++)
		for (int j = 1;j <= a[i];j++)
			cout << i << " ";
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
//数列排序：从小到大排序
#if RUN_EXAMPLE_2 == 1
//选择排序
#include<iostream>
using namespace std;
int find_min(int a[], int m,int n)
{
	int min = a[m];int ans = m;
	for (int i = m;i < n;i++)
		if (a[i] < min)
		{
			min = a[i];
			ans = i;
		}
	return ans;
}
void swap(int& a,int& b)
{
	int temp = a;a = b;b = temp;
}
int main()
{
	int n;cin >> n;
	int a[max_];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < n;i++)
		swap(a[i], a[find_min(a, i, n)]);
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	return 0;
}
#endif
#if RUN_EXAMPLE_2 == 2
//选择排序2
#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
	int temp = a;a = b;b = temp;
}
int main()
{
	int n;cin >> n;
	int a[max_];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	return 0;
}
#endif
#if RUN_EXAMPLE_2 == 3
//冒泡排序
//依次比较两个相邻元素
#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
	int temp = a;a = b;b = temp;
}
int main()
{
	int n;cin >> n;
	int a[max_];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for(int i=0;i<n-1;i++)//进行n次
		for (int j = 0;j < n - 1 - i;j++)
		{
			if (a[j] > a[j + 1])//只和相邻比较
				swap(a[j], a[j + 1]);
		}
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	return 0;
}
#endif
#if RUN_EXAMPLE_2 == 4
//插入排序
#include<iostream>
using namespace std;
int main()
{
	int n;cin >> n;
	int a[max_];
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 1;i < n;i++)
	{
		int now = a[i], j;//得到无序区第一个数
		for (j = i - 1;j >= 0;j--)//遍历有序区
			if (a[j] > now)
				a[j + 1] = a[j];
			else break;
		a[j+1] = now;
	}
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	return 0;
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//快速排序
//取哨兵数，小于哨兵数的放左边，大于哨兵数的放右边，依次递推
#include<iostream>
using namespace std;
void qsort(int a[], int l, int r)
{
	int i = l, j = r, flag = a[(l + r) / 2], tmp;
	while(1)
	{
		while (a[i] < flag)i++;
		while (a[j] > flag)j--;
		if (i > j)break;
		else
		{
			int temp = a[i];a[i] = a[j];a[j] = temp;
			i++;j--;
		}

	} 
	if (l<j)qsort(a, l, j);//分治思想
	if (i < r)qsort(a, i, r);
}
#endif
//模板
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//求第k小的数
#include<iostream>
using namespace std;
int k;
int findkth(int a[], int l, int r)
{
	if (l == r)return a[l];
	int i = l, j = r, flag = a[(l + r) / 2];
	while (1)
	{
		while (a[i] < flag)i++;
		while (a[j] > flag)j--;
		if (i > j)break;
		else
		{
			int temp = a[i];a[i] = a[j];a[j] = temp;
			i++;j--;
		}
	}
	if (k <= j)return findkth(a, l, j);
	else if (k >= i)    return findkth(a, i, r);
	else    return flag;//结束时，j在左，i在右，中间可能隔着等于flag的数
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//明明的随机数：输出去重后剩余数字的个数以及去重排序后的序列
#include<iostream>
#include<algorithm>//使用STL
using namespace std;
int a[max_], ans[max_], n;
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)cin >> a[i];
	sort(a, a + n);//sort(a,a+n,cmp)根据地址a到a+n进行排序，cmp时自定义排序函数，从小到大排序的话可以缺省
	int k = 0;
	for (int i = 0;i < n;i++)
	{
		if (i == 0)ans[k] = a[i];
		else if (a[i] != a[i - 1])ans[k++] = a[i];
	}
	cout << k << endl;
	for (int i = 0;i < k;i++)
		cout << ans[i] << ' ';
	return 0;
}
//如何实现从大到小排序：自定义cmp函数：
bool cmp(int a, int b)
{
	return a > b;
}
//sort(a,a+n,cmp);即可
//其实有去重函数unique(a,a+n)返回最后一个元素所对应的指针
#endif
#if RUN_EXAMPLE_5 == 2
#include<iostream>
#include<algorithm>
using namespace std;
int a[max_];
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++)cin >> a[i];
	sort(a, a + n);
	int cnt = unique(a, a + n)-a;
	cout << cnt << endl;
	for (int i = 0;i < cnt;i++)cout << a[i] << " ";
	return 0;
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//奖学金
//结构体排序
#include<iostream>
#include<algorithm>
using namespace std;
struct student
{
	int id;
	int chinese;
	int total;
}stu[max_];
bool cmp(struct student s1, struct student s2)
{
	if (s1.total != s2.total)return s1.total > s2.total;
	if (s1.chinese != s2.chinese)return s1.chinese > s2.chinese;
	return s1.id<s2.id;
}
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++)
	{
		stu[i].id = i + 1;int english, math;
		cin >> stu[i].chinese >> math >> english;
		stu[i].total = stu[i].chinese + math + english;
	}
	sort(stu, stu + n, cmp);
	for (int i = 0;i < 5;i++)
		cout << stu[i].id << " " << stu[i].total << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//宇宙总统
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	string x;//高精度
	int num;
}a[max_];
bool cmp(struct node n1, struct node n2)
{
	if (n1.x.size() != n2.x.size())return n1.x.size() > n2.x.size();
	int n = n1.x.size();int i = 0;
	while (n--)
	{
		if (n1.x[i] != n2.x[i])return n1.x[i] > n2.x[i];
		i++;
	}
	return false;
}
#endif
#define RUN_EXAMPLE_8 0
#if RUN_EXAMPLE_8 == 1
//习题9-1：超级书架
#include<iostream>
using namespace std;
int& find_max(int a[], int n)
{
	int max = a[0];int tmp=0;
	for (int i = 1;i < n;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			tmp = i;
		}
	}
	return a[tmp];
}
int main()
{
	int a[max_];int N,B;cin >> N >> B;
	for (int i = 0;i < N;i++)cin >> a[i];
	int sum = 0;int num=0;
	while (sum < B)
	{
		int& tmp = find_max(a, N);
		sum += tmp;
		tmp = 0;
		num++;
	}
	cout << num << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_9 0
#if RUN_EXAMPLE_9 == 1
//习题9-2：车厢重组
#include<iostream>
using namespace std;
int main()
{
	int a[max_];int N;cin >> N;int sum = 0;
	for (int i = 0;i < N;i++)cin >> a[i];
	for (int i = 0;i < N;i++)
	{
		for (int j = 1;j <= N - 1 - i;j++)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];a[j - 1] = a[j];a[j] = temp;
				sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_10 0
#if RUN_EXAMPLE_10 == 1
//习题9-3：欢乐的跳
#include<iostream>
#include<cmath>
using namespace std;
bool isVal(int a[], int n)
{
	int gap[max_] = { 0 };
	for (int i = 1;i <= n-1;i++)gap[i] = 1;
	for (int i = 0;i < n-1;i++)
	{
		if (abs(a[i] - a[i + 1]) == 0 || abs(a[i] - a[i + 1]) >= n)return false;
		if (gap[abs(a[i] - a[i + 1])] == 1)gap[abs(a[i] - a[i + 1])] = 0;
		else return false;
	}
	return true;
}
int main()
{
	int a[max_];int n;cin >> n;
	for (int i = 0;i < n;i++)cin >> a[i];
	if (isVal(a, n))cout << "Jolly" << endl;
	else cout << "Not jolly" << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_11 0
#if RUN_EXAMPLE_11 == 1
//习题9-4：分数线划定
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int num;
	int score;
}a[max_];
ostream& operator<<(ostream& os, const node& obj)
{
	os << obj.num << " " << obj.score << endl;
	return os;
}
istream& operator>>(istream& is, node& obj)
{
	is >> obj.num >> obj.score;
	return is;
}
bool cmp(struct node n1, struct node n2)
{
	if (n1.score != n2.score)
		return n1.score > n2.score;
	return n1.num < n2.num;
}
int main()
{
	int n, m;cin >> n >> m;
	for (int i = 0;i < n;i++)cin >> a[i];
	sort(a, a + n, cmp);
	int s = floor(m * 1.5);
	cout << a[s-1].score << endl;
	for (int i = 0;i < s;i++)cout << a[i];
}
#endif
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 1
//习题9-5：攀登者
//前提：各点z不相等
#include<iostream>
#include<cmath>
#include<algorithm>
struct coor
{
	int x;
	int y;
	int z;
}co[max_];
double dist(struct coor c1, struct coor c2)
{
	double da = (c1.x - c2.x) * (c1.x - c2.x);
	double db = (c1.y - c2.y) * (c1.y - c2.y);
	double dc = (c1.z - c2.z) * (c1.z - c2.z);
	return sqrt(da + db + dc);
}
bool cmp(struct coor& c1, struct coor& c2)
{
	return c1.z > c2.z;
}
istream& operator>>(istream& is, struct coor& obj)
{
	is >> obj.x >> obj.y >> obj.z;
	return is;
}
using namespace std;
int main()
{
	double sum = 0;
	int n;cin >> n;
	for (int i = 0;i < n;i++)cin >> co[i];
	sort(co, co + n, cmp);
	for (int i = 0;i < n - 1;i++)
		sum += dist(co[i], co[i + 1]);
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_13 0
#if RUN_EXAMPLE_13 == 1
#define max_ 1000
//习题9-6：生日
#include<iostream>
#include<algorithm>
using namespace std;
struct stduent
{
	string name;
	int year;
	int month;
	int day;
}std[max_];
bool cmp(stduent& s1, stduent& s2)
{
	if (s1.year != s2.year)return s1.year < s2.year;
	if (s1.month != s2.month)return s1.month < s2.month;
	return s1.day < s2.day;
}
istream& operator>>(istream& is, struct stduent& s1)
{
	is >> s1.name >> s1.year >> s1.month >> s1.day;
	return is;
}
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++)cin >> std[i];
	sort(std, std + n, cmp);
	for (int i = 0;i < n;i++)cout << std[i].name << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_14 0
#if RUN_EXAMPLE_14 == 0
//拼数
#include<iostream>
#include<algorithm>
using namespace std;
string to_s(int n)
{
	if (n == 0) return "0";
	int len = 0;string s;int temp = n;
	while (temp > 0)
	{
		len++;temp /= 10;
	}
	temp = len; s.resize(len);
	while (n > 0)
	{
		s[temp-1] = n % 10+'0';
		n /= 10;
		temp--;
	}
	return s;
}
bool cmp(string s1, string s2)
{
	return s1 + s2 > s2 + s1;
}
int main()
{
	int n;cin >> n;int cnt;string s[max_];
	for (int i = 0;i < n;i++)
	{
		cin >> cnt;
		s[i] = to_s(cnt);
	}
	sort(s, s + n, cmp);
	for (int i = 0;i < n;i++)cout << s[i];
	return 0;
}
#endif



//模板
#define RUN_EXAMPLE_ 0
#if RUN_EXAMPLE_ == 0
#include<iostream>
using namespace std;
int main()
{

}
#endif