#define _CRT_SECURE_NO_WARNINGS
#define p1 0
#if p1==1
//跑步
#include<iostream>
using namespace std;
int main()
{
	cout << 100.0 / (8 - 5) << endl;
	return 0;
}
#endif
//各数据类型：
/*char          1字节  -128-127 常用
* int           4字节  绝对值不超过约21亿，4*8-1位用于存储数值 常用
* short         2字节  -32768-32767
* unsigned int  4字节  0-pow(2,32)-1,不超过约42亿的非负整数，4*8位用于存储数值
* long long     8字节  9.2*e18,8*8-1位存储数值，负数全，正数最高位留给0
* unsigned long long 8字节 同理
* float         4字节  指数不超过37，6位有效数字，一般用<1e-6表示0
* double        8字节  指数不超过307，15位有效数字,常用
*/
#define p2 0
#if p2==1
//英文字母
#include<iostream>
using namespace std;
int main()
{
	cout << 'M' - 'A' + 1 << endl;
	cout << (char)('A' + 17) << endl;//char型在参与运算时，会自动转为整型
	return 0;
}
#endif
/*常用ASCII表
* 48->'0'
* 65->'A'
* 97->'a'
* 0~31是不可见字符(控制字符)
* 32->空格(可见)
*/
#define p3 0
#if p3==1
//玩橡皮泥
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	const double PI = 3.1415926;
	int l = pow(4.0 / 3 * PI * (pow(4, 3) + pow(10, 3)), 1.0 / 3);//右值为浮点值，赋给整型l实现类型转换
	cout << l << endl;//可以用pow(double,double)实现开三次根
	return 0;
}
#endif
#define p4 0
#if p4==1
//销量预测
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	int a = 1, b = -100, c = 2400;
	double x = (-b + sqrt(b * b - 4 * a * c)) * 1.0 / (2 * a);
	cout << (110 - int(x + 0.5)) << endl;//由于<<运算符优先级低于-，故外层括号可以去掉，若为赋值运算符则不能
	return 0;

}
#endif
//！！！实现四舍五入最简单的方法：正数+0.5之后强制转为int
#define p5 0
#if p5==1
//苹果采购
#include<iostream>
using namespace std;
int main()
{
	int t, n;
	cin >> t >> n;
	cout << t * n << endl;
	return 0;
}
#endif
//使用cin输入整数或者浮点数时，可用空格或者回车隔开，多余的会被忽视
#define p6 0
#if p6==1
//字母转换
#include<iostream>
using namespace std;
int main()
{
	char c;
	cin >> c;
	cout << c << endl;//因为c毕竟是字符串变量，故cout并不会输出其对应的ASCII值
	cout << (char)(c - 97 + 65) << endl;
	//cout<<(char)(c-'a'+'A')<<endl;更简单
	return 0;
}
#endif
#define p7 0
#if p7==1
//数字反转，反转xxx.y格式
#include<iostream>
using namespace std;
int main()
{
	/*double d;
	cin >> d;
	int n = (int)d;
	int n__1 = 10*(d-n);
	int n_0 = n % 10;
	int n_1 = (n - n_0) % 100/10;
	int n_2 = (n - n_0 - n_1)/100;
	cout << n__1 + 0.1 * n_0 + 0.01 * n_1 + 0.001 * n_2 << endl;*/
	//可能会有精度问题,其实先*10以获得各位数大小最简便
	//优化算法
	double d;
	cin >> d;
	int n = d * 10;
	int a = n / 1000;
	//int b = (n - 1000 * a) / 100;
	int b = n / 100 % 10;//除以100以让百位落在个位，%10获得个位
	//int c = (n - 1000 * a - 100 * b) / 10;
	int c = n / 10 % 10;//除以10以让十位落在个位，%10获得个位
	//int q = n - 1000 * a - 100 * b - 10 * c;
	int q = n % 10;//%10直接获得个位
	cout << q << '.' << c << b << a << endl;
	return 0;
	//也可以用字符法，定义五个char型变量，顺序输入，反序输出
}
#endif
#if p7==2
//数字反转，普遍：
//字符法
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char c[100];
	cin >> c;
	int len = strlen(c);
	char newc[100];
	for (int i = len-1;i >=0;i--)
	{
		newc[len - 1 - i] = c[i];
	}
	newc[len] = '\0';
	cout << newc << endl;
	return 0;

}
#endif
#define p8 0
#if p8==1
//再分肥宅快乐水
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double t;int n;
	//cin >> t >> n;
	(void)scanf("%lf%d", &t, &n);//千万别忘了&，double输入用%lf，输出用%f
	printf("%.3f\n%d", t / n, 2 * n);//.3要在%后面
	return 0;
}
#endif
//占位符整理
/*%nd     不足n位，后面用空格补齐直到n
* %0nd    不足n位，前面用0补齐
*/
#define p9 0
#if p9==1
//交换变量
#include<cstdio>
int main()
{
	int a, b, temp;
	(void)scanf("%d%d",&a,&b);
	temp = a;a = b;b = temp;
	printf("%d\n%d", a, b);
	return 0;

}
#endif
#define p10 0
#if p10==1
//小鱼的游泳时间
#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << 60 * (c - a) + d - b << endl;
	return 0;
}
#endif
#define p11 0
#if p11==1
#include<cstdio>
int main()
{
	int a, b, c;
	(void)scanf("%d%d%d", &a, &b, &c);
	printf("%d", a * 2 / 10 + b * 3 / 10 + c * 5 / 10);
	return 0;//因为已经规定输入的a,b,c是10的倍数，若直接*0.2等等，浮点数0.2实则是0.19999...,得到的也是浮点数
	         //比如78.999...，若强制类型转换得到78而非79，还得用+0.5四舍五入去计算，得不偿失，所以在已知都是10的倍数的条件下
	         //建议用*2/10代替*0.2
}
#endif
#define p12 0
#if p12==1
//上学迟到
#include<cstdio>
#include<cmath>
int main()
{
	double s, v;
	scanf("%lf%lf", &s, &v);//double必用lf
	int  min1 = ceil(s / v) + 10;//上学消耗的时间应当手动向上取整
	//太绕了
	//double min8 = (8 + 24) * 60;
	//int min = (min8 - min1 >= 24 * 60 ? min8 - min1 - 24 * 60 : min8 - min1);//可能提前一天出发
	//printf("%02d:%02d", min / 60, min - min / 60 * 60);
	//只需要计算需要的时间减去8*60，<0则提前一天也就是+24*60，直到>0
	int min = 8 * 60 - min1;
	while (min < 0)
		min += 24 * 60;//时钟算法
	printf("%02d:%02d", min / 60, min % 60);
	return 0;
}
#endif
#define p13 0
#if p13==1
//习题2-5：小玉买文具
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a*10 + b) / 19 << endl;
	return 0;
}
#endif
#define p14 0
#if p14==1
//习题2-6：Apples Prologue
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m;double t,s;
	cin >> m >> t>>s;
	int remain = m -  ceil(s / t);//ceil避免浮点误差，手动消除误差
	remain = remain > 0 ? remain : 0;//苹果小于0的情况
	cout << remain << endl;
	return 0;
	
}
#endif
//end

//模板

#define p0 0
#if p0==1
#include<iostream>
using namespace std;
int main()
{

}
#endif
