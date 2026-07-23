//————————————————————数组实现栈
#include<iostream>
#include<assert.h>
using namespace std;
const int maxsize = 1e4 + 10;
template<class T>//模板类型
class Stack
{
public:
	bool empty() { return top == -1; }//栈中未分配空间的话，top指针位置是-1
	bool full() { return top == maxsize - 1; }//由于存储空间是从0开始的，故末尾是maxsize-1
	void push(T k) { assert(!full());A[++top] = k; }//压栈
	T pop()/*删除*/ { assert(!empty());return A[top--]; }//返回被弹出的数
	T peek()/*查看*/ { assert(!empty());return A[top]; }
private:
	T A[maxsize];
	int top = -1;
};

//————————————————————进制转换
//由于把十进制转换成其他进制，余数正好符合压栈顺序，故可用栈实现进制转换
#include<math.h>
//用到结构体
string ConvertToBase7(int n)
{
	if (n == 0)return 0;
	Stack<int> s;
	string ans = (n > 0 ? "" : "-");
	n = abs(n);
	while (n > 0)
	{
		s.push(n % 7);
		n /= 7;
	}
	while (!s.empty())
	{
		ans += s.pop() + '0';
	}
	return ans;
}
//不用结构体，现场创造
string convertToBase7(int n)
{
	if (n == 0)return 0;
	int stack[110], top = -1;
	string ans = (n > 0 ? "" : "-");
	n = abs(n);
	while (n > 0)
	{
		stack[++top] = n % 7;
		n /= 7;
	}
	while (top != -1)
	{
		ans += stack[top--]+'0';
	}
	return ans;
}
//如果要转的进制>10
//创建字符数组  char digit[]={ '0','1','2', '3', '4', '5', '6’,'7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', };
/*
* 将while (n > 0)
	{
		s.push(n % 7);
		n /= 7;
	}
	改为while(n>0)
	{
	     s.push(digit[n%K]);
		 n/=K;
*/

//————————————————————括号匹配
// 若只有一种括号，遇到左括号+1，右括号-1，结果==0即可
//用字符数组pair完成括号匹配，如下
//pair['(']=')';pair['[']=']';pair['{']='}';
//遇到左括弧，压栈，遇到右括弧，若匹配失败，返回假
bool isVaild(string s)
{
	int n = s.size();
	Stack <char> bracket;
	char pair[150] = { 0 };
	pair['('] = ')';pair['['] = ']';pair['{'] = '}';
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			bracket.push(s[i]);//压栈
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')//添加else可以减少不必要的运算
		{
			if (bracket.empty())return 0;
			char c = bracket.pop();//弹出左括号
			if (pair[c] != s[i])
				return 0;
		}
	}
	/*if (bracket.empty())
		return 1;
	else return 0;*/
	//更直接的:
	return bracket.empty();
}
//——————————拓展：加上嵌套顺序为{ → [ → ( → <
bool isVaild_new(string s)
{
	int n = s.size();
	char pair[150] = { 0 };
	pair['('] = ')';pair['['] = ']';pair['{'] = '}';pair['<'] = '>';
	Stack<char> bracket;
	int sign[4] = { 0 };
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '{')
		{
			if (sign[0] == 0 && sign[1] == 0 && sign[2] == 0)
			{
				bracket.push(s[i]);
				sign[3]++;
			}
			else return 0;
		}//}压栈时，必须保证左侧没有低级括号或者括号已经被抵消，这是拓展与基础的不同之处，关键在于sign[]的运用
		else if (s[i] == '[')
		{
			if (sign[0] == 0 && sign[1] == 0)
			{
				bracket.push(s[i]);
				sign[2]++;
			}
			else return 0;
		}
		else if (s[i] == '(')
		{
			if (sign[0] == 0)
			{
				bracket.push(s[i]);
				sign[1]++;
			}
			else return 0;
		}
		else if (s[i] == '<')
		{
			bracket.push(s[i]);
			sign[0]++;
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}'||s[i]=='>')//添加else可以减少不必要的运算
		{
			if (bracket.empty())return 0;
			char c = bracket.pop();//弹出左括号
			if (pair[c] != s[i])
				return 0;
			else switch (s[i])
			{
			case '>':sign[0]--;break;
			case ')':sign[1]--;break;
			case ']':sign[2]--;break;
			case '}':sign[3]--;break;
			}
		}
	}
	return bracket.empty();

}


//————————————————————表达式求值
//遇到运算符，弹出两个操作数，底层的在左，高层的在右
//后缀表达式与中缀表达式操作数出现顺序一样，运算符出现顺序就是实际的计算顺序。
//中缀表达式转后缀表达式：
// 手工方法：根据运算顺序补全括号，从里到外，移动运算符使之放在与之对应的右括号后面
//注意，不要重复移动两次，不要混淆
//调度场法：重点记忆规则：转换规则，求值规则

//————————————————————算法实现基本计数器
int readnum(string s, int n, int& i)//n为总长，i为总标尺，引用类型会继承变化
{
	int temp = 0;
	while (i < n && s[i] >= '0' && s[i] <= '9')
	{
		temp = temp * 10 + s[i] - '0';
		i++;
	}
	i--;//指向连续数值末位
	return temp;
}
void operation(Stack<int>& NUM, Stack<char>& OP)//引用类型会记录变化
{
	char c = OP.pop();
	int num1 = NUM.pop();
	int num2 = NUM.pop();
	if (c == '+')NUM.push(num1 + num2);
	else if (c == '-') NUM.push(num2 - num1);
	else if (c == '*')NUM.push(num2 * num1);
	else if (c == '/')NUM.push(num2 / num1);
}//一旦触发operation则OP弹出的一定是运算符
int calcute(string s)
{
	Stack<int> NUM;
	Stack<char> OP;
	int n = s.size();
	int Prior[120];
	Prior['+'] = 1;Prior['-'] = 1;Prior['*'] = 2;Prior['/'] = 2;
	for (int i = 0;i < n;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')NUM.push(readnum(s, n, i));//为什么readnum结束后i要指向连续数值末尾，因为每个for循环i会自动++
		else if (s[i] == '(')OP.push(s[i]);
		else if (s[i] == ')')
		{
			while (OP.peek() != '(')
				operation(NUM, OP);
			OP.pop();
		}
		else
		{
			while (!OP.empty() && OP.peek() != '(' && Prior[s[i]] >= Prior[OP.peek()])
				operation(NUM, OP);
			OP.push(s[i]);
		}

	}
		while (!OP.empty())operation(NUM, OP);
		return NUM.peek();
}


//————————————————————栈混洗

//——————————栈混洗甄别
bool check(int a[], int b[], int n)
{
	Stack<int> s;int k = 0;//k是数组a的游标
	for (int i = 0;i < n;i++)//i是数组b的游标
	{
		while (s.empty() || s.peek() != b[i])//前者决定起点，若为空，压入a的一个元素。后者检查栈顶
		{
			if (k < n)s.push(a[k++]);//压入a数组的元素直到栈顶满足，
			else return 0;//否则，返回假
		}
		s.pop();//到达了这步，说明满足了，弹出使底下的元素成为栈顶，继续检验
	}
	return 1;
}
//充要条件：对于出栈序列的任意左中右三个元素（不一定挨着），若满足大小中的数值关系，则一定为非法出栈序列

//——————————栈混洗总数
//将push看作'(',pop看作')',于是栈混洗总数问题演变为单括号匹配问题
//2n个括号，n个左括号，于是有C2n_n种排法
//但是前文的括号匹配可知，')'左侧必须有有效'('与之对应，假定序列非法，则设第一个非法位置')'为k,
//前k个括号必定右必左多一个，多出来的就在位置k，令k+1及以后的取反，左右互换，则对于整个序列而言，右比左多两个，于是右括号数量为n+1，左括号数量为n-1，这是一一对应的，充要的
//于是非法序列个数为C2n_(n-1)种，有效序列可求



//————————————————————栈扩容
//本质为栈内容的拷贝，地址是变了的
//在push函数中新增判别是否full以及应对情况
template <class T>
void Stack<T>::push(T k)
{
	if (full()) {
		T* B = new T[2 * size];
		for (int i = 0;i < size;i++)
			B[i] = A[i];//旧拷贝
		delete A;//清除栈区
		A = B;//指向替换
		size *= 2;
	}
		A[++top] = K;//本来的目的，没full也会执行
}
//一般采取容量倍增策略，均摊时间复杂度为O（1），若为容量递增策略，则均摊复杂度为O（n）




//——————————————————————————————————————递归与回溯


//————————————————————迷宫寻径
const int maxsize = 110;
int map[maxsize][maxsize];//地图，1为障碍
int vis[maxsize][maxsize] = { {0} };//标记走过的格子,1为走过的
int n, m;//迷宫的n行m列
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool feasible(int x, int y)//判断是否可走
{
	if (x>=0&&x < maxsize &&y>=0&& y < maxsize && map[x][y]==0 && vis[x][y]==0)
		return 1;
	else return 0;
}
void Print(int as[], int k)//打印路径，k为走过的距离
{
	for (int i = 0;i < k;i++)
	{
		printf("%d", as[i]);//return true;
	}
	printf("\n");
}
void find(int x, int y, int tx, int ty, int as[],int k)//后两个参数表明了所处位置，溯源递归用的
{
	//设置出口
	if (x == tx && y == ty) { Print(as, k);return; }
	vis[x][y] = 1;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if (feasible(nx, ny))
		{
			as[k] = i;
			find(nx, ny, tx, ty, as, k + 1);//注意不要改变k和x，y的值，因为每次循环都是原始值
		}
	}
	vis[x][y] == 0;//终止之后把所有走过的点清零以便找到所有可能的路线
}//若只要求找到一个路线，无需清零，要返回bool型，则
//if(find(nx,ny,tx,ty,as,k+1))return true;
//}retur false;
//回溯算法的基本框架：
//1）如果as已经是一个解，则打印并return [true]
//2）否则，猜测as[k]的可能取值
//可行则进。if(feasible())更新as，并find(k+1)
//不行则换，进入下一层循环
//换不了则退
//若只找一个解
//find()返回类型为bool型，if(feasible())更新as，if(find(k+1))return true;
//换不了则return false;
//初始调用find(1);


//————————————————————N皇后问题
void Print(int ans[], int n)
{
	for (int i = 1;i <= n;i++)
	{
		printf("%d", ans[i]);
	}
	printf("\n");
}
bool feasible(int ans[], int k, int i)//第k列是否可以放到第i行
{
	for (int j = 1;j <= k-1;j++)
	{
		if (ans[j] == i || abs(ans[j] - i) == abs(j - k))
			return false;
	}
	return true;
}
void Nqueen(int ans[],int n, int k)//填解数组的第k位
{
	if (k > n) { Print(ans, n);return; }
	for (int i = 1;i <= n;i++)
	{
		if (feasible(ans, k, i))
		{
			ans[k] = i;
			Nqueen(ans, n, k + 1);
		}
	}
}



//————————————————————快速幂
double pow(double a, long long n)//为了降低时间复杂度,依旧对半分
{
	if (a == 1 || n == 0)return 1;
	double b = pow(a, n/2);
	if (n % 2 == 1)return b * b * a;
	else return b * b;
}


//消除递归的方法

//1)尾递归转循环
//2）利用自定义栈解决
//————————————————————汉诺塔问题
//递归解法
void move(char A, char B)
{
	cout << A << "->" << B << endl;
}
void hanno(char A, char B,char C, int n)
{
	if (n == 1)move(A, C);
	else
	{
		hanno(A, C, B, n - 1);
		hanno(A, B, C, 1);
		hanno(B, A, C, n - 1);
	}
}
//自定义栈解法
//本质就是利用栈来存储运行顺序
struct Quad { int n;char A, B, C; };
class HnnoiStack
{
private:
	Quad H[maxsize];
	int top = -1;
public:
	bool empty() { return top == -1; }
	bool full() { return top == maxsize - 1; }
	void push(int n, char A, char B, char C)
	{
		assert(!full());top++;
		H[top].n = n;H[top].A = A;H[top].B = B;H[top].C = C;
	}
	void pop(int&n,char&A,char&B,char&C)
	{
		assert(!empty());
		n = H[top].n;A = H[top].A;B = H[top].B;C = H[top].C;
		top--;
	}
};
void hanno_NonRec(int n, char A, char B, char C)
{
	HnnoiStack s;
	s.push(n, A, B, C);
	while (!s.empty())
	{
		int n;char A, B, C;
		s.pop(n, A, B, C);//弹出内容实现嵌套
		if (n == 1)move(A, C);
		else//替代嵌套
		{
			s.push(n - 1, B, A, C);
			s.push(1, A, B, C);
			s.push(n - 1, A, C, B);
		}
	}
}





