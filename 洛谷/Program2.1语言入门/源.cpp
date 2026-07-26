#define p1 0
#if p1==1
//例1-1
#include<iostream>//外部库
using namespace std;//引入名字空间
int main()
{
	cout << "I love Luogu!";
	return 0;//返回0说明程序正常运行，如果不加，程序在编译时会自动补全
}
//注意要求半角而非全角
//不要忘了句末的分号
#endif
#define p2 0
#if p2==1
//例1-2
#include<iostream>
using namespace std;
int main()
{
	cout << 2 + 4 << "," << 10 - 2 - 4 << endl;
	return 0;
}
#endif
#define p3 0
#if p3==1
//例1-3
#include<iostream>
using namespace std;
int main()
{
	cout << 14 / 4 <<endl<< 14 - 14 % 4 << endl<<14 % 4 << endl;
	return 0;
}
//整型除法自动向下取整，故整型除法可能遗失一些东西
//乘号不能省略
#endif
#define p4 0
#if p4==1
//例1-4
#include<iostream>
using namespace std;
int main()
{
	cout << 500.0 / 3 << endl;
	return 0;
}
//若想更加精确，最简单的就是加上.0，代表这是个浮点数
#endif
#define p5 0
#if p5==1
//例1-5，关于输出
#include<iostream>
using namespace std;
void show_printf()
{
	int r1, r2, r3;
	r1 = printf("Hello\n");
	r2 = printf("%d\n", 42);
	r3 = printf("%d %f %s\n", 42, 3.14, "hi");
	printf("%d,%d,%d",r1, r2, r3);//6,3,15
}
int main()
{
	cout << 5000000.0 / 3 << endl;
	cout << 0.000005 / 3 << endl;
	printf("%f\n", 5000000.0/3);
	printf("%f\n", 0.0000005 / 3);
	printf("%f\n", 0.005 / 3);
	show_printf();
	return 0;
}
/*输出：
1.66667e+06
1.66667e-06
1666666.666667
0.000000
0.001667
*/
//对于cout输出：有效数字要小于等于6，大了自动四舍五入
// 特别地，若为浮点型，则当>=10e6或<1e-4时，会调用科学计数法,用不用科学计数法与有效数字个数无关
//对于printf输出：永远固定是小数且默认六位小数，太小了会显示0.000000，例如第四行输出
//%d输出整型，%f浮点(一定输出六位小数)，%e用科学计数法输出，%g自动选择，类似于cout
//人工选择精度：如%.2f为保留两位小数
//\n是转义字符，起到换行作用
//——————对于printf函数,返回类型是整型，返回成功输出的字符数，第一个参数是const char* format-格式控制字符串，后续参数为数量可变参数列表
//为何r3是15：42空格3点140000空格hi转义字符
#endif
#define p6 0
#if p6==1
//火车问题
#include<iostream>
using namespace std;
int main()
{
	cout << (260 + 220) / (12 + 20) << endl;
	return 0;
}
#endif 
#define p7 0
#if p7==1
//对角线问题：长为6，宽为9，求对角线
#include<cmath>//包含许多常用数学函数
#include<iostream>
using namespace std;
int main()
{
	cout << sqrt(pow(6, 2) + pow(9, 2)) << endl;
	return 0;
}
//pow()返回的是浮点数，用于求算出平方根的sqrt()也是
/*一些其他cmath库函数：
* double fabs(double x) 返回x的绝对值
* double ceil(double x) 向上取整
* double floor(double x)向下取整
*/
#endif
#define p8 0
#if p8==1
//存钱问题
#include<iostream>
using namespace std;
int main()
{
	int balance = 100;
	//cout << balance += 10 << endl;错误，因为<<优先级高于+=运算符
	cout << (balance += 10) << endl;
	cout << (balance -= 20) << endl;
	cout << (balance = 0) << endl;
	return 0;
}
#endif
#define p9 0
#if p9==1
#define PI 3.14
#include<iostream>
using namespace std;
int main()
{
	int r = 5;
	//const double PI=3.14 也可以
	cout << "周长：" << 2 * PI * r << endl;
	cout << "面积：" << PI * r * r << endl;
	//cout << "体积:" << 4 / 3 * PI * r * r * r << endl;错误，因为4和3均为整型，相除得到1
	cout << "体积：" << 4.0 / 3 * PI * r * r * r << endl;
}
//变量与常量的命名规则：
/*只能由英文字母，数字，下划线组成
* 不能以数组开头
* 不能和关键字重复
*/
#endif
#define p10 0
#if p10==1
//猴子吃桃
#include<iostream>
using namespace std;
int main()
{
	int n = 1;
	for (int i = 0;i < 3;i++)
		n = (n + 1) * 2;
	cout << n << endl;
	return 0;
}
#endif
#define p11 0
#if p11==0
//评测机队列
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	int n1 = 8, t1 = 30, n2 = 10, t2 = 6;
	double rate = (1.0 * n1 * t1 - n2 * t2) / (t1 - t2);//先求增长速度,注意1.0的作用
	double origin = n1 * t1 - rate * t1;
	double num = (origin + rate * 10) / 10;
	cout << ceil(num) << endl;
	return 0;

}
#endif
//常见名字整理
//值：index(索引，下标),val,count,num,sum,total,remain,inc,dec,
// init(初始值)，cur(当前值)，temp,rate,step,len,max,min,flag
//函数：isValid,show_abc,isEmpty,get_abc,ste_abc,find_abc





//模板

#define p0 0
#if p0==1
#include<iostream>
using namespace std;
int main()
{

}
#endif





