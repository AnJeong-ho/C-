#define RUN_EXAMPLE_1 0
#if RUN_EXAMPLE_1 == 1
#include<iostream>
using namespace std;
int main()
{
    int L;
    cin >> L;
    if (L == 0)
        printf("Today,I ate 0 apples.");
    else
        for (int i = 1; i <= L; i++)
        {
            printf("Today,I ate %d apple", i);
            if (i > 1)
                printf("s");
            printf(".\n");
        }
    return 0;
}
#endif

#define RUN_EXAMPLE_2 0
#if RUN_EXAMPLE_2 == 1
#include<iostream>
using namespace std;
int main()
{
    int n, temp, min;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> temp;//可以允许循环输入同一变量进行更新以避免使用数组
        if (i == 0)min = temp;
        else if (min > temp)min = temp;
    }
    cout << min << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_3 0
#if RUN_EXAMPLE_3 == 1
//分类平均
int main()
{
    /*原算法：
    int n, k;cin >> n >> k;
    double sum1=0, sum2=0;
    int a,num1=0,num2=0;
    for (int i = 0;i < n;i++)
    {
        cin >> a;//依旧不用数组，循环更新
        if (a % k == 0)
        {
            sum1 += a;num1++;
        }
        else
        {
            sum2 += a;num2++;
        }
    }
    double ave1, ave2;//看似简单，但是要考虑分母为0的情况！
    if (num1 == 0)ave1 = 0;
    else ave1 = sum1 / num1;
    if (num2 == 0)ave2 = 0;
    else ave2 = sum2 / num2;
    printf("%.1f %.1f", ave1, ave2);
    return 0;*/
    //要求1~n内k的倍数之和，不用输入，按数学原理直接求和
    int n, k;cin >> n >> k;
    int Anum=0, Bnum=0;
    for (int i = k;i <= n;i += k)
    {
        Anum += i;
    }
    Bnum = n * (n + 1) / 2-Anum;
    printf("%.1f %.1f", 1.0 * Anum / (n / k), 1.0 * Bnum / (n - n / k));
    return 0;
}
#endif
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
#include<iostream>
using namespace std;
//一尺之棰
int main()
{
    int a, days=0;cin >> a;
    while (a > 1)
    {
        days++;a /= 2;
    }
    cout << days;
    return 0;
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//猜数游戏
#include<iostream>
using namespace std;
int main()
{
    int num;cin >> num;
    int a;
    while (1)
    {
        cin >> a;
        if (a > num)cout << "Too large\n";
        else if (a < num)cout << "Too small\n";
        else if (a == num)
        {
            cout << "You are right!!\n";
            break;
        }
    }
}
#endif
#if RUN_EXAMPLE_5 == 2
//如何让计算机产生一个随机数？
//rand()可以产生一个0到RAND_MAX的整数，这是一个常数，与编译系统有关.需要引入如下头文件
#include<cstdlib>
//如何产生0到a的随机数呢？模a+1即可
//如何产生a到b的随机数呢？模b-a+1再+a即可
#include<iostream>
using namespace std;
int main()
{
    cout << rand();
    return 0;
}
#endif
//无论执行多少次，输出的结果都是一样的，这由随机数的生成特性导致，喂给它当前的时间是比较好的选择

#if RUN_EXAMPLE_5 ==3
//在rand()之前，设置srand()的参数设为time(0)
//需要引入如下头文件
#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
    srand(time(0));
    int num = rand()%100+1;
    int a;
    while (1)
    {
        cin >> a;
        if (a > num)cout << "Too large\n";
        else if (a < num)cout << "Too small\n";
        else if (a == num)
        {
            cout << "You are right!!\n";
            break;
        }
    }
    return 0;
}
#endif
#define RUN_EXAMPLE_6 0
#if RUN_EXAMPLE_6 == 1
//数字直角三角型
#include<iostream>
using namespace std;
void f(int a)
{
    if (a < 10)cout << 0 << a;
    else cout << a;
}
int main()
{
    int n;cin >> n; int j=1;
    for (int i = 0;i < n;i++)
    {
        for (int a=0;a<n-i;a++)
        {
            f(j);j++;
        }
        printf("\n");
    }
    return 0;
}
#endif
#define RUN_EXAMPLE_7 0
#if RUN_EXAMPLE_7 == 1
//阶乘之和
#include<iostream>
using namespace std;
int f(int n)
{
    int sum = 1;
    for (int i = 1;i <= n;i++)
    {
        sum *= i;
    }
    return sum;
}
int main()
{
    int n;cin >> n;int sum=0;
    for (int i = 1;i <= n;i++)
    {
        sum += f(i);
    }
    cout << sum << endl;
    return 0;
}
#endif
#if RUN_EXAMPLE_7 == 2
#include<iostream>
using namespace std;
//递推算法
int main()
{
    int n;cin >> n;int sum = 0;
    int a=1;
    for (int i = 1;i <= n;i++)
    {
        sum += a;
        a = a * (i + 1);
    }
    cout << sum << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_8 0
#if RUN_EXAMPLE_8 == 1
//计数问题
#include<iostream>
using namespace std;
int f(int n, int k)
{
    int temp, sum = 0;
    while(n!=0)
    {
        temp = n % 10;
        n /= 10;
        if (temp == k)sum++;
        //if (n == 0)break;完全可以放到while()内部
    }
    return sum;

}
int main()
{
    int num,x;cin >> num>>x;
    int sum = 0;
    for (int i = 1;i <= num;i++)
    {
        sum += f(i,x);
    }
    cout << sum << endl;
}
#endif
#define RUN_EXAMPLE_9 0
#if RUN_EXAMPLE_9 == 1
//级数求和
#include<iostream>
using namespace std;
int main()
{
    double S = 0;int k;cin >> k;int i = 1;
    while (S<=k)//浮点数可以与整型相比较
    {
        S += (1.0 / i);//注意1.0！！！
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_10 0
#if RUN_EXAMPLE_10 == 1
//金币
#include<iostream>
using namespace std;
int main()
{
    int sum=0, day;cin >> day;
    int i=1, j=0;
        while (j+i <= day)
        {
            j += i;
            sum += i*i;
            i++;
        }
        sum += ((day - j) * i);
        cout << sum << endl;
        
    return 0;
}
#endif
#define RUN_EXAMPLE_11 0
#if RUN_EXAMPLE_11 == 1
//数列求和
#include<iostream>
using namespace std;
int sum(int k)
{
    if (k == 1)return 1;
    return sum(k - 1) + k;
}
int main()
{
    int n;cin >> n;
    cout << sum(n) << endl;
    return 0;
}
#endif
#if RUN_EXAMPLE_11 == 2
#include<iostream>
using namespace std;
int main()
{
    int sum = 0;int n;cin >> n;
    for (int i = 1;i <= n;i++)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
#endif
#if RUN_EXAMPLE_11 == 3
//关于++表达式
#include<iostream>
using namespace std;
int main()
{
    int s1 = 0, s2 = 0, i1 = 1, i2 = 1;
    s1 += i1++;
    s2 += ++i2;
    cout << i1 << " " << i2 << " " << s1 << " " << s2;//2 2 1 2

}
#endif
//要避免在同一表达式中多次对同一变量进行自增自减操作，或自增自减后赋值给同一变量，以免造成混乱
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 1
//数列求和(2)
//从0.1加到n-0.1
#include<iostream>
using namespace std;
int main()
{
    int s = 0, n;cin >> n;
    for (int i = 1;i < 10 * n;i++)
    {
        s += i;
    }
    double sum = 0.1 * s;
    cout << sum << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_12 0
#if RUN_EXAMPLE_12 == 2
//用浮点数作为判断条件，慎用
#include<iostream>
using namespace std;
int main()
{
    int n;double sum = 0;cin >> n;
    for (double i = 0.1;/*i != n,会死循环*//*i<n，会产生累加延迟*/i+0.01<n;i += 0.1)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
#endif

#define RUN_EXAMPLE_13 0
#if RUN_EXAMPLE_13 == 1
//质数口袋
#include<iostream>
using namespace std;
bool isValid(int n)
{
    if (n < 2)return false;
    else if (n < 4)return true;
    else
    for (int i = 2;i*i<=n;i++)
    {
        if (n % i == 0)return false;
    }
    return true;
}
int main()
{
    int sum = 0;int L;cin >> L;int num = 0;
    for (int i = 2;/*sum <= L*/;i++)
    {
        if (isValid(i))
        {
            if (sum + i > L)break;//在这里处理更好，即使弹出否则多加一项
            sum += i;cout << i << " ";
            num++;
        }
    }
}
#endif
#define RUN_EXAMPLE_14 0
#if RUN_EXAMPLE_14 == 1
//回文质数
#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if (n < 2)return false;
    else if (n < 4)return true;
    else
        for (int i = 2;i * i <= n;i++)
        {
            if (n % i == 0)return false;
        }
    return true;
}
bool isHui(int n)
{
    int len = 0;int temp=n;
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }
    int a[10];temp = n;
    for (int j = 1;j <= len;j++)
    {
        a[j] = temp % 10;
        temp /= 10;

    }
    for (int j = 1;j <= len / 2;j++)
    {
        if (a[j] != a[len + 1 - j])return false;
    }
    return true;


}
int main()
{
    int a, b;cin >> a >> b;
    for (int i = a;i <= b;i++)
    {
        if (isHui(i) && isPrime(i))cout << i << endl;
    }

}
#endif
#define RUN_EXAMPLE_15 0
#if RUN_EXAMPLE_15 == 1
//习题4-2
//小玉在游泳
#include<iostream>
using namespace std;
int main()
{
    double l = 2, sum=0, x;cin >> x;
    int i = 0;
    //while (i++)//错，先判断i是否为0，若为0根本不会进入循环
    //while(++i)//对
    while(x>=sum)
    {
        sum += l;
        l *= 0.98;
        //if (sum > x)break;上升到条件判断
        i++;
    }
    cout << i << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_16 0
#if RUN_EXAMPLE_16 == 1
//数字反转
#include<iostream>
using namespace std;
/*bool isNegative(int m)
{
    if (m < 0)return true;
    return false;
}
*/
//直接用n<0代替
int main()
{
    int a[10];int n;cin >> n;
    int temp = n>0?n:-n;int i = 0;
    while (temp > 0)
    {
        a[i] = temp % 10;
        temp /= 10;
        i++;
    }
    int num = 0;int weight = 1;
    while (i--)
    {
      
        num += a[i] * weight;
        weight *= 10;
    }
    cout <<( n>0?num:-num) << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_17 0
#if RUN_EXAMPLE_17 == 1
//习题4-4
//斐波那契数列
#include<iostream>
using namespace std;
int f(int n)
{
    if (n <= 2)return 1;
    return f(n - 1) + f(n - 2);
}
int main()
{
    int n;cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cout <<f(i) << " ";
    }
    return 0;
}
#endif//时间复杂度较大
//可用动态规划或数组规划或迭代解决
//下面用迭代法解决
#define RUN_EXAMPLE_17 0
#if RUN_EXAMPLE_17 == 2
#include<iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    int a = 1, b = 1;
    if (n == 1)cout << a;
    if (n >= 2)cout << a << " " << b<<" ";
    for (int i = 3;i <= n;i++)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}
#endif
#define RUN_EXAMPLE_18 0
#if RUN_EXAMPLE_18 == 1
//求极差
//规定了整数范围[0,1000]
//否则要用第一个数初始化
#include<iostream>
using namespace std;
int main()
{
    int n, max=0, min=1000;
    cin >> n;int temp;
    for (int i = 0;i < n;i++)
    {
        cin >> temp;
        if (temp > max)max = temp;
        if (temp < min)min = temp;
    }
    cout << max - min << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_19 0
#if RUN_EXAMPLE_19 == 1
//最长连号
bool isHave(int a[],int n, int k)//最大是a[n-1]
{
    if (k == 1)return true;
    for (int i = 0;i <= n - k;i++)
    {
        for (int j = i + 1;j <= i + k - 1;j++)
        {
            if (a[j] != a[j - 1] + 1)break;
            if (j == i + k - 1)return  true;
        }
        for (int j = i + 1;j <= i + k - 1;j++)
        {
            if (a[j] != a[j - 1] - 1)break;
            if (j == i + k - 1)return true;
        }
    }
    return false;
}
#include<iostream>
using namespace std;
int main()
{
    int x;cin >> x;
    int a[20];
    int i = 0, temp = x;
    while (temp > 0)
    {
        a[i] = temp % 10;
        temp /= 10;
        i++;
    }
    int k = 0;
    while (isHave(a,i,k+1))
    {
        k++;
    }
    cout << k << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_20 0
#if RUN_EXAMPLE_20 == 1
//质因数分解
#include<iostream>
using namespace std;
bool isPrime(int n)
{
    if (n < 2)return false;
    else if (n < 4)return true;
    else
        for (int i = 2;i * i <= n;i++)
        {
            if (n % i == 0)return false;
        }
    return true;
}
int main()
{
    int n;cin >> n;//已知n为两质数乘积
    for (int i = 2;i * i <= n;i++)
    {
        //if (!isPrime(i))continue;//因为题目说 "n 是两个质数的乘积"，所以第一个能整除 n 的 i 一定是质数，不需要额外判断！
        if (n % i == 0)cout << n / i << endl;
    }
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


