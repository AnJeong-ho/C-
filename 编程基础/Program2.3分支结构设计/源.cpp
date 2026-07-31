#define p1 0
#if p1==1
//例3-1
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a > b) << " "
		 << (a <= b) << " "
		 << (a != b) << " "
		<< endl;
	return 0;
}
#endif
//时刻铭记比较是否相等是==而非=
//——————————各运算符优先级比较：
/*单目>算数>移位>关系>位运算>逻辑运算符>赋值运算符>逗号运算符
* 各运算符内部也存在优先级高低
* 胆酸一贯welofdo
* 单算移关位逻赋逗
* 记忆点1：<<优先级高于<号，移位高于关系，如本题cout时必须加括号
* 记忆点2：与运算高于或运算
* 记忆点3：==，!=低于<,大小比较优先于相等性判断
* 记忆点4：位运算(&,^,|)低于关系，高于逻辑运算
*/
//!!!一般不会用==去判断两个浮点数是否相等，因为会有精度误差
//一般这样判断：fabs(a-b)<1e-6,其中fabs(double)专门用于得到浮点数的绝对值
#define p2 0
#if p2==1
#include<iostream>
using namespace std;
int main()
{
	int x;
	cin >> x;
	/*bool a = (x % 2 == 0) && (x > 4 && x <= 12);
	bool b = (x % 2 == 0) || (x > 4 && x <= 12);
	bool c = (x % 2 == 0) ^ (x > 4 && x <= 12);
	bool d = !(x % 2 == 0) && !(x > 4 && x <= 12);*/
	bool a = x % 2 == 0, b = x > 4 && x <= 12;
	//cout << a&&b << " " << a||b << " " << a^b << " " << !a&&!b << endl;错误，因为移位运算高于逻辑运算
	cout << (a && b) << " " << (a || b) << " " << (a ^ b) << " " << (!a && !b) << endl;
	return 0;

}
#endif
//只有单目运算符，算数运算符不被<<干扰，单算移关位逻赋逗
//注意，异或运算符是位运算符而不是逻辑运算符，优先级高于逻辑运算符
#define p3 0
#if p3==1
//闰年判断
#include<iostream>
using namespace std;
int main()
{
	int year;
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)cout << 1;
	else cout << 0;
	return 0;
}
#endif
#define p4 0
#if p4==1
//Apples
#include<cstdio>
int main()
{
	int x;
	scanf("%d", &x);
	if (x == 0)printf("I ate 0 apple.");
	else if (x == 1)printf("I ate 1 apple.");
	else printf("I ate %d apples.", x);
	return 0;
}
#endif
#define p5 0
#if p5==1
//洛谷团队系统
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int t1 = 5 * n;
	int t2 = 11 + 3 * n;
	if (t1 > t2)cout << "Luogu";
	else cout << "Local";
	return 0;
}
#endif
#define p6 0
#if p6==1
//小洛机器人
#include<iostream>
using namespace std;
int main()
{
	char c;
	cin >> c;
	switch (c)
	{
	    case 'G':cout << "Hello,my master!\nI'm Xiaoluo.";break;//中间插入换行建议用\n
		case 'N':cout << "I'm Xiaoluo.";break;
		case 'S':cout << "Teinei teinei teinei~";break;
		case 'B':
		case 'Q':cout << "BYe bye!";break;
		default:cout<<"Sorry...";//用default兜底
	}
	return 0;
}
#endif
#define p7 0
#if p7==1
//肥胖问题
#include<iostream>
using namespace std;
int main()
{
	double m, h;
	cin >> m >> h;
	double BMI = 1.0 * m / (h * h);
	if (BMI < 18.5)cout << "Underweight" << endl;
	else if (BMI >= 24)cout << BMI << ",Overweight" << endl;
	else cout << "Normal" << endl;
	return 0;
}
#endif
#define p8 0
#if p8==1
//三个数排序
#include<iostream>
using namespace std;
void swap(int& a, int& b)//注意该函数不能定义在主函数内部,要用引用或者指针，否则传过来的只能是数值
	{
		int temp = a;a = b;b = temp;
	}
int main()
{
	
	int a, b, c;
	cin >> a >> b >> c;
	if (b < a)swap(a, b);
	if (c < a)swap(a, c);
	if (b > c)swap(b, c);
	cout << a << " " << b << " " << c << endl;
}
#endif
#define p9 0
#if p9==1
//月份天数
#include<iostream>
using namespace std;
int main()
{
	int year, month, day;
	cin >> year >> month;
	bool isRun = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:day = 31;break;
	case 4:case 6:case 9:case 11:day = 30;break;
	case 2:day = 28 + isRun;break;
	default:day = 0;cout << "月份输入有误" << endl;
	}
	cout << day << endl;
	return 0;
}
#endif
#define p10 0
#if p10==1
//不高兴的津津
#include<iostream>
using namespace std;
#include<cstdio>
int main()
{
	int day[7];
	for (int i = 0;i < 7;i++)
	{
		cin >> day[i];//输入每天的学习时间
	}
	int maxunhappy_day = 0, max = 0;
	for (int i = 0;i < 7;i++)
	{
		if (day[i] > 8)
		{
			if (day[i] > max)
			{
				max = day[i];
				maxunhappy_day = i + 1;
			}
		}
	}
	if (maxunhappy_day)
		printf("第%d天最不高兴", maxunhappy_day);
	else printf("津津下周不会不高兴");
}
#endif
#define p11 0
#if p11==1
//买铅笔
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int each_price[3], price[3];
	int num[3], n;
	cin >> n;
	for (int i = 0;i < 3;i++)
	{
		cin >> num[i] >> each_price[i];
		//price[i] = !(n % num[i]) ? n / num[i] * each_price[i] : (n / num[i] + 1) * each_price[i];//注意是否整除的表示方法
		//向上取整优雅算法
		price[i] = (n + num[i] - 1) / num[i] * each_price[i];
	}
	//double min = price[0];
	//if (min > price[1])max = price[1];
	//if (min > price[2])max = price[2];
	int min_price = min(price[0], min(price[1], price[2]));
	cout << min_price << endl;
	return 0;
}
#endif
#define p12 0
#if p12==1
//ISBN
#include<cstdio>
int main()
{
	char s[20] = { 0 };int num[20] = { 0 };//数组赋值初始化,空间富裕一点
	scanf("%s", s);
	int j = 0;
	for (int i = 0;i < 13;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num[j] = s[i] - '0';
			j++;
		}
	}
	// 如果想让代码更健壮，可以加一个判断
	if (j != 10) {
		printf("Invalid ISBN format");
		return 0;
	}
	int sum = 0;
	for (int i = 0;i < 9;i++)
	{
		sum += (i + 1) * num[i];
	}
	if (sum % 11 == 10)
	{
		if (s[12] == 'X')printf("Right");
		else
		{
			s[12] = 'X';printf("%s", s);
		}
	}
    else if (sum % 11 == num[9])printf("Right");
	else
	{
		s[12] = sum % 11 + '0';
		printf("%s", s);
	}
}
#endif
/*
输入 ISBN
    ↓
提取10位数字 → 验证格式
    ↓
计算加权和 (1×a₁ + 2×a₂ + ... + 9×a₉)
    ↓
checksum = sum % 11
    ↓
    ├─ checksum == 10 ──→ 校验码是否为'X'?
    │                      ├─ 是 → "Right"
    │                      └─ 否 → 修正为'X'
    │
    ├─ checksum == num[9] ──→ "Right"
    │
    └─ 其他 ──→ 修正为 checksum
*/
#define p13 0
#if p13==0
//习题3-9：ABC
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int A, B, C;cin >> A >> B >> C;
	if (A > B)swap(A, B);
	if (A > C)swap(A, C);
	if (B > C)swap(B, C);
	char c[3];
	for (int i = 0;i < 3;i++)
	{
		cin >> c[i];
		switch (c[i])
		{
		case 'A':cout << A << " ";break;
		case 'B':cout << B << " ";break;
		case 'C':cout << C << " ";break;
		}
	}
	return 0;
}
#endif






//模板

#define p0 0
#if p0==1
#include<iostream>
using namespace std;
int main()
{

}
#endif
