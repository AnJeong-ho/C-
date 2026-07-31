#define _CRT_SECURE_NO_WARNINGS  // 放在最开头
#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
//自动修正
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[50];cin >> s;
	for (int i = 0;i < strlen(s);i++)//for(int i=0;s[i]!='\0';i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')s[i] = s[i] - 'a' + 'A';
	}
	cout << s;
}
#endif
//虽然一个字符串只有n个字符，但是这个字符数组却占了8位，因为末尾有结束标记字符'\0'，在循环中可作为读取结束标志
#if RUN_EXAMPLE_1 == 2
#include<iostream>
using namespace std;
int main()
{
	char c;
	//while (1)
	while((c=getchar())!=EOF)//注意优先级，赋值运算符级别非常低，仅次于逗号运算符
	{
		//c = getchar();
		//if (c == EOF)break;
		if (c >= 'a' && c <= 'z')c =c- 'a' + 'A';
		putchar(c);
	}
	return 0;
	//程序读完一个字符都会判断是否读完了整个文件，如果文件读完了，那么getchar()会返回EOF，标志读入已经结束
	//ctrl+z以输入EOF标记
}
#endif
//不建议使用gets()，但是puts()以输出字符串可以使用,自动换行
#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
//凯撒密码
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char s[50];(void)scanf("%s", s);
	int n;(void)scanf("%d", &n);
	for (int i = 0;s[i] != '\0';i++)
	{
		s[i] = (s[i] + n-'a') % 26 + 'a';
	}
	puts(s);
	return 0;

}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//笨小猴
#include<iostream>
using namespace std;
bool isPrime(int n)
{	
	if (n < 2)return false;
	if (n < 4)return true;
	for (int i = 2;i * i <= n;i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}
int main()
{
	int a[128] = { 0 };
	char s[100];
	cin >> s;
	for (int i = 0;s[i] != '\0';i++)
	{
		a[s[i]]++;
	}
	int max = 0, min = 1e6;
	for (int i = 'a';i <= 'z';i++)
	{
		if (a[i] > max)max = a[i];
		if (a[i] < min&&a[i]>=1)min = a[i];//必须出现过才行
	}
	if (isPrime(max - min))
	{
		puts(s);
		cout << max - min << endl;
	}
	else
	{
		cout << "No Answer\n" << 0 << endl;
	}
	return 0;
}
#endif
//char a[100] = "Luogu";   // ✅ 可修改
//a[0] = 'l';              // ✅ 可以改
//char* b = "Luogu";       // ❌ 字符串常量不能修改
//b[0] = 'l';              // ❌ 未定义行为（可能崩溃）
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
//口算练习题
#include<iostream>
#include<cmath>
using namespace std;
int len(int n)
{
	bool is = (n < 0);
	int i = 0;
	while (abs(n) > 0) {
		i++;
		n /= 10;
	}
	return i>0?i+is:1;
}
int main()
{
	int n;cin >> n;//习题个数
	char f='+';char a;int b, c;
	//for (int i = 0;i < n;i++)
	while(n--)
	{
		
		cin >> a;
		if (a == '+' || a == '-' || a == '*' || a == '/')
		{
			f= a;cin >> b;
		}
		else b = a-'0';
		cin >> c;
		cout << b << f << c << '=';
		switch (f)
		{
		case '+':cout << b + c << " " << len(b) + len(c) + len(b + c) + 2 << endl;break;
		case '-':cout << b - c << " " << len(b) + len(c) + len(b - c) + 2 << endl;break;
		case '*':cout << b * c << " " << len(b) + len(c) + len(b * c) + 2 << endl;break;
		case '/':cout << b / c << " " << len(b) + len(c) + len(b / c) + 2 << endl;break;
		}
	}
}
#endif
#if RUN_EXAMPLE_4 == 2
//调用fgets(),sscanf(),sprintf()版本
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n, a, b, c;
	char last;//记录运算符
	char s[20], ans[20];
	scanf("%d\n", &n);//读入习题个数
	while (n--)
	{
		fgets(s, sizeof(s), stdin);//sizeof(s)为s在内存中占用的总空间，int s[100];sizeof(s)==100.stdin为标准输入流，通常键盘输入
		//回车终止，包含了空格和回车.读取sizeof(s)-1个字符，末尾补'\0'
		if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
			last = s[0], s[0] = ' ';//只要用不到这个小表达式的返回值，一般来说就可以用逗号代替分号以实现合并,从前往后执行，返回值是最后一个表达式
		sscanf(s, "%d %d", &a, &b);//从字符串中读入有效字符，而非键盘
		switch (last)
		{
		case '+':c = a + b;sprintf(ans,"%d+%d=%d",a,b,c);break;//将这个字符串输出到s而不是标准输出，以获得字符串长度
		case '-':c = a - b;sprintf(ans, "%d-%d=%d", a, b, c);break;
		case '*':c = a * b;sprintf(ans, "%d*%d=%d", a, b, c);break;
		case '/':c = a / b;sprintf(ans, "%d/%d=%d", a, b, c);break;
		}
		printf("%s\n%d\n", ans, strlen(ans));
	}
	
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//标题统计
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int ans=0;string s;
	while (cin >> s)//由于cin读入读到空格或者回车截止，因此整个大的字符串按照空格和回车被且切割为小的字符串，读到EOF，返回0，循环结束
	{
		ans += s.length();
	}
	cout << ans << endl;
	return 0;
}
#endif
/*string s;//定义一个字符串变量
* s+=str;s.append(str);//在s后面拼接str
* s<str;比较字符串字典序
* s.size();s.length();//获得长度,不含\0
* s.substr(pos,len)//从pos(角标)开始截取长度为len的字符串，末尾(第len+1位)补'\0'
* s.insert(pos,str)//在第pos个字符之前插入字符串str
* s.find(str,pos=0)//从第pos个字符开始查找str，并返回位置，注意，不一定是个整型变量，若找不到，返回-1，pos缺省值位0
*/
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//文字处理软件
#include<iostream>
using namespace std;
int main()
{
	int n, option;cin >> n;//输入要进行的操作数
	string s;cin >> s;
	while (n--)
	{
		cin >> option;cout << option << " ";
		switch (option)
		{
		
		case 1:
		{
			string str;
			cin >> str;cout << (s += str) << endl;
			break;//不能在分支中跳过变量的初始化,在块作用域中定义可以，case 1:{}这样
		}
		case 2:
		{
			int a, b;cin >> a >> b;
			s=s.substr(a, b );//截取不修改原字符串，要赋值操作
			cout << s << endl;
			break;
		}
		case 3:
		{
			int m;cin >> m;
			string str2;cin >> str2;
			s.insert(m,str2);//插入修改原字符串
			cout << s << endl;
			break;
		}
		case 4:
		{
			string str3;cin >> str3;
			cout << s.find(str3) << endl;
		}
		}
	}
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//统计单词数
#include<iostream>
using namespace std;
void f(string& s)//由于string是类不是字符串指针，所以不传引用的话会发生拷贝构造
{
	for (int i = 0;s[i] != '\0';i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}
int main()
{
	string word;cin >> word;f(word);
	string artical;int sum = 0;int pos = 0;
	while (cin >> artical)
	{
		f(artical);
		if (artical == word)sum++;
		if(sum==0)
		pos += artical.size()+1 ;//单词长度＋空格
		
	}
	if (sum == 0)pos = -1;
	cout << sum << " " << pos << endl;
	return 0;
}
#endif
//用getline(cin,s)可以将一整行输入数据输入到字符串s中2
#define RUN_EXAMPLE_8 0
#if RUN_EXAMPLE_8 == 1
//习题6-1：手机
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[128] = { 0 };
	for (int i = 'a';i <= 'r';i++)
		a[i] = (i - 'a' ) % 3+1;
	a['s'] =a['z']= 4;
	a['t'] = a['w'] = 1;a['u'] = a['x'] = 2;a['v'] = a['y'] = 3;
	a[' '] = 1;
	string s;
	getline(cin, s);int sum = 0;
	for (int i = 0;i < s.size();i++)
	{
		sum += a[s[i]];
	}
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_9 0
#if RUN_EXAMPLE_9 == 1
//习题6-2：honoka的键盘VKKVVK
#include<iostream>
using namespace std;
int main()
{
	string s;cin >> s;int sum = 0;
	int a[100] = { 0 };bool is=0;//是否可改善，判断未被标记的部分是否出现VV或者KK
	for (int i = 0;i < s.size()-1;i++)
	{
		if (a[i] == 0)
		{
			if (s[i] == 'V' && s[i + 1] == 'K')
			{
				a[i] = a[i + 1] = 1;
				sum++;
			}
		}
	}
	for (int i = 0;i < s.size()-1;i++)
	{
		if (a[i] == 0 && a[i + 1] == 0)
		{
			if ((s[i] == 'V' && s[i + 1] == 'V') || (s[i] == 'K' && s[i + 1] == 'K'))
				is = 1;
		}
	}
	sum += is;
	cout << sum << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_10 0
#if RUN_EXAMPLE_10 == 1
//习题6-3：单词覆盖还原
#include<iostream>
using namespace std;
int main()
{
	int sum_boy = 0, sum_girl = 0;
	string s;cin >> s;
	if (s == "")
	{
		cout << 0 << " " << 0 << endl;return 0;
	}
	for (int i = 0;i < s.size()-1;i++)
	{
		switch (s[i])
		{
		case 'b':
			if (s[i + 1] != 'o')
			{
				sum_boy++;break;
			}//如果出现bo,进入case 'o'
		case 'o':
			if (s[i + 1] != 'y')
			{
				sum_boy++;break;
			}
		case 'y':sum_boy++;break;
		case 'g':
			if (s[i + 1] != 'i')
			{
				sum_girl++;break;
			}
		case 'i':
			if (s[i + 1] != 'r')
			{
				sum_girl++;break;
			}
		case 'r':
			if (s[i + 1] != 'l')
			{
				sum_girl++;break;
			}
		case 'l':sum_girl++;break;
		}
	}
	//漏了末尾，补充：若倒数第二位是y或者l，还应加1
	if (s[s.size() - 2] == 'y')sum_boy++;
	else if (s[s.size() - 2] == 'l')sum_girl++;
	cout << sum_boy << " " << sum_girl << endl;
}
#endif
#define RUN_EXAMPLE_11 0
#if RUN_EXAMPLE_11 == 1
//习题6-4:数字反转升级版
#include<iostream>
using namespace std;
int check(string s)
{
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '.')return 2;//小数
		else if (s[i] == '/')return 3;//分数
		else if (s[i] == '%')return 4;//百分数
	}
	return 1;//整数
}
string polish(string s, int flag)
{
	string new_s = "";
	int size = 0;
	switch (check(s))
	{
	case 1:
		if (s == "0")return "0";
		for (int i = s.size() - 1;i >= 0;i--)
		{
			if (s[i] == '0' && new_s == "")continue;
			new_s+= s[i];
			size++;
		}
		return new_s;
	case 2:
	{
		int pos = s.find(".");//3.14
		string s1 = s.substr(0, pos);
		s1 = polish(s1, 1);
		s1 += ".";
		string s2 = s.substr(pos + 1);
		if (s2 == "0")return s1 += "0";
		pos = s2.find_first_not_of('0');//找到小数部分第一个不为0的位置
		s2 = s2.substr(pos);//截取从该位置到末尾的字符串
		s2 = polish(s2, 1);
		return s1 + s2;
	}
	case 3:
	{
		int pos = s.find("/");
		string s1 = s.substr(0, pos);
		s1 = polish(s1, 1);
		s1 += "/";
		string s2 = s.substr(pos + 1);
		s2 = polish(s2, 1);
		return s1 + s2;
	}
	case 4:
	{
		string s1 = s.substr(0, s.size() - 1);
		s1 = polish(s1,1);
		return s1 + "%";
	}
	}
}
int main()
{
	string s;cin >> s;
	string new_s = "";
	new_s = polish(s, check(s));
	cout << new_s << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 1
//习题6-5：斯诺登的密码
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int compare(int m,int n)
{
	string s1 = to_string(m);
	string s2 = to_string(n);
	return s1 + s2 > s2 + s1;
}
void sort(int a[], int n)
{
	for (int i = 0;i < n-1;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			if (compare(a[i],a[j]))
			{
				int temp = a[i];a[i] = a[j];a[j] = temp;
			}
		}
	}
}//两个函数用来实现拼接数
int main()
{
	string s;int a[6] = { 0 }, b[6] = { 0 };
	string str[26]={ "a","one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen", "twenty","both","another","first","second","third"
	};
	int num[26] = { 1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,2,1,1,2,3 };//实现字符串到数值的映射
	for (int i = 0;i < 6;i++)
	{
		cin >> s;
		for (int j = 0;j < 26;j++)
		{
			if (str[j] == s)
				a[i] = num[j];
		}
		b[i] = a[i] * a[i] % 100;
	}
	sort(b, 6);string ans = "";//int sum=0,j=0;
	for (int i = 0;i <6;i++)
	{
		//直接拼接，用整型记录答案很麻烦
		ans += to_string(b[i]);
		//sum += b[5 - i] * pow(10, j);
		//if (b[5 - i] > 10)j++;
		//j++;
	}
	cout << ans << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_13 0
#if RUN_EXAMPLE_13 == 1
//习题6-6：你的飞碟在这儿
#include<iostream>
using namespace std;
int main()
{
	char s[26] ;int num[26];
	for (char c = 'A';c <= 'Z';c++)
	{
		s[c - 'A'] = c;
		num[c - 'A'] = c - 'A';
	}
	string s1;cin >> s1;long long sum1=1;
	for (int i = 0;i < s1.size();i++)
	{
		for (int j = 0;j < 26;j++)
			if (s1[i] == s[j])
				sum1 *= (num[j]+1);
	}
	sum1 = sum1 % 47;
	string s2;cin >> s2;long long sum2 = 1;
	for (int i = 0;i < s2.size();i++)
	{
		for (int j = 0;j < 26;j++)
			if (s2[i] == s[j])
				sum2 *= (num[j]+1);
	}
	sum2 = sum2 % 47;
	if (sum1 == sum2)cout << "GO" << endl;
	else cout << "STAY" << endl;
	return 0;
}
#endif
//由于这个映射关系规律性极强，故映射是多此一举的
//升级版如下
#if RUN_EXAMPLE_13 == 2
#include<iostream>
using namespace std;
int main()
{
	string s1, s2;cin >> s1 >> s2;
	long long sum1 = 1, sum2 = 1;
	for (char c : s1)sum1 *= c - 'A' + 1;//遍历容器，简介写法
	for (char c : s2)sum2 *= c - 'A' + 1;
	sum1 %= 47;sum2 %= 47;
	cout << (sum1 == sum2 ? "GO" : "STAY") << endl;
	return 0;
}
#endif
#define RUN_EXAMPLE_14 0
#if RUN_EXAMPLE_14== 0
//习题6-7：语句解析
#include<iostream>
using namespace std;
int main()
{
	int a = 0, b = 0, c = 0;
	string s;cin >> s;string str[10];
	int pos1 = 0;
	int pos2 = s.find(";");
	for(int i=0;;i++)//根据分号分割语句
	{
		 int num = 0;
		 str[i] = s.substr(pos1, pos2-pos1);//截取语句
		 pos1 = pos2+1;//左界限更新
		 pos2 = s.find(";", pos2+1);//右界限更新至下一个分号
		 if (str[i][3] >= '0' && str[i][3] <= '9')
			 num = str[i][3] - '0';
		 else switch (str[i][3])
		 {
		 case 'a':num = a;break;
		 case 'b':num = b;break;
		 case 'c':num = c;break;
		 }
		 switch (str[i][0])
		 {
		 case 'a':a = num;break;
		 case 'b':b = num;break;
		 case 'c':c = num;break;
		 }
		 if (pos2 == string::npos)//若右界限溢出，终止循环
			 break;
	}
	cout << a << " " << b << " " << c << endl;
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