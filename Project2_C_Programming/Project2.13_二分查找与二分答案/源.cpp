#define _CRT_SECURE_NO_WARNINGS
#define RUN_EXAMPLE_1 0
//有序序列中查找元素
#if RUN_EXAMPLE_1 == 1
#define max_ 100010
int a[max_];
#include<iostream>
using namespace std;
int main()
{
	int n, m;scanf("%d%d", &n, &m);//n个数，m次访问
	for (int i = 0;i < n;i++)scanf("%d", &a[i]);
	while (m--)
	{
		int l = 0, r = n - 1, x;
		scanf("%d", &x);
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (a[mid] >= x)r = mid;
			else l = mid + 1;
		}
		if (a[l] != x)printf("-1 ");
		else
		printf("%d ", l);
	}
	return 0;
}
#endif
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//A-B数对
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,c,a[10010];scanf("%d%d", &n,&c);
	for (int i = 0;i < n;i++)scanf("%d", &a[i]);
	sort(a, a + n);//升序排列
	long long ans = 0;
	for (int i = 0;i < n;i++)
	{
		int* L = lower_bound(a + i, a+n, a[i] + c);
		int* R = upper_bound(a + i, a + n, a[i] + c);
		ans += R - L;
	}
	printf("%lld\n", ans);
}
#endif
#if RUN_EXAMPLE_2 == 2
//双指针优化
//由于随着i增大，L和R也逐渐往后，所以可以对其进行维护
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, c, a[10010];scanf("%d%d", &n, &c);
	for (int i = 0;i < n;i++)scanf("%d", &a[i]);
	sort(a, a + n);//升序排列
	long long ans = 0, L = 0, R = 0;
	for (int i = 0;i < n;i++)
	{
		while (L < n && a[L] < a[i] + c)L++;
		while (R < n && a[R] <= a[i] + c)R++;
		ans += R - L;
	}
	printf("%lld\n", ans);
	return 0;
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//砍树
#include<iostream>
using namespace std;
int max_a(int a[], int n)
{
	int max = a[0];
	for (int i = 1;i < n;i++)
	{
		if (a[i] > max)max = a[i];
	}
	return max;
}
long long collect(int a[], int n, int min)
{
	long long ans = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] > min)ans += a[i] - min;
	}
	return ans;
}
int main()
{
	int n,bal, a[100010];scanf("%d%d", &n,&bal);
	for (int i = 0;i < n;i++)scanf("%d", &a[i]);
	int L = 0, R = max_a(a, n);
	while (L < R)
	{
		int mid = (L + R) / 2;
		if (collect(a, n, mid) < bal)R = mid;
		else L = mid+1;
	}
	printf("%d", L-1);//L以前collect<=bal,L是第一个>bal的
}
#endif
#if RUN_EXAMPLE_3 == 2
//答案法
#include<iostream>
using namespace std;
#define max_ 1000010
long long a[max_], n, m;
bool P(int h)
{
	long long tot = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] > h)tot += a[i] - h;
	}
	return tot >= m;//是否满足要求或溢出
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)scanf("%d", &a[i]);
	int L = 0, R = 1e9, ans, mid;
	while (L <= R)
	{
		if (P(mid = L + R >> 1))
			ans = mid, L = mid + 1;//如果有ans记录，那么就容易了
		else
			R = mid-1;
	}
	printf("%d", ans);
}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//进击的奶牛
#define max_ 1000010
int a[max_], n, c;
bool check(int d)//最小间隔距离
{
	int  last = -max_, temp = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] - last >= d)
		{
			temp++;//放置一头奶牛
			last = a[i];
		}
	}
	return temp >= c;
}
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0;i < n;i++)scanf("%d",&a[i]);
	sort(a, a + n);
	int L = 0, R = max_, mid, ans;
	while (L <= R)
	{
		if (check(mid = L + R >> 1))
			ans = mid, L = mid + 1;
		else
			R = mid - 1; 
	}
	printf("%d", ans);
	return 0;
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//一元三次方程求解
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define esp 1e-6
double A, B, C, D;
double f(double x)
{
	return A * x * x * x + B * x * x + C * x + D;
}
int main()
{
	scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
	for (int i = -100;i < 100;i++)
	{
		double L = i, R = i + 1, mid;
		if (f(L) * f(R) > 0)continue;
		while (R-L>esp)
		{
			mid = (L + R) / 2;
			if (fabs(f(mid)) < esp)
			{
				printf("%.2f", mid);break;
			}
		    else if (f(L) * f(mid) < 0)R = mid;
		    else if (f(R) * f(mid) < 0)L = mid;
		}
	}
}
#endif
#if RUN_EXAMPLE_5 == 2
//答案法
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define esp 1e-6
double A, B, C, D;
double f(double x)
{
	return A * x * x * x + B * x * x + C * x + D;
}
int main()
{
	scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
	for (int i = 0;i <= 100;i++)
	{
		double L = i, R = i + 1, mid;
		if (fabs(f(L)) < esp)printf("%f", L);
		else if (fabs(f(R)) < esp)continue;
		else if (f(L) * f(R) < 0)
		{
			while (R - L > esp)
			{
				mid = (L + R) / 2;
				if (fabs(f(mid)) < esp)break;
				else if (f(R) * f(mid) < 0)L = mid;
				else R = mid;
			}
			printf("%.2f", mid);
		}
	}
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