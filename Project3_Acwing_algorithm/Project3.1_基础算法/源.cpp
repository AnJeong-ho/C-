#define RUN_EXAMPLE_1 0
//——————————————————————————————再遇快速排序

//中心思想：分治
//步骤：
//1.确定分界点：左边界l, 右边界r，终点(l + r) / 2
//2.调整范围:取其中一个数x，分成两个范围，左范围 <= x, 右范围 >= x
//3.递归处理左右两段


//实现方法
//简单版：新开数组a, b
#if RUN_EXAMPLE_1==1
#define max_ 100
int q[max_];
int a[max_], b[max_];
void quick_sort(int l, int r)
{
    if (l >= r)return;
    int len_a = 0, len_b = 0;
    int x = q[(l + r) / 2];
    for (int i = l;i <= r;i++)
    {
        if (q[i] <= x)a[len_a++] = q[i];
        else b[len_b++] = q[i];
    }
    for (int i = 0;i < len_a;i++)q[l + i] = a[i];
    for (int i = 0;i < len_b;i++)q[l + len_a + i] = b[i];
    quick_sort(l, l + len_a - 1);
    quick_sort(l + len_a, r);
}
#endif
//优雅版：使用游标i，j
//i从l出发，向右平移，直到指向的数大于等于x
//j从r出发，向左平移，直到指向的数小于等于x
//i, j指向的数swap, 继续出发
//直到i和j相遇
#if RUN_EXAMPLE_1==2
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int n;
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;//先移动，再判断
    while (i < j)
    {
        do i++;while (q[i] < x);
        do j--;while (q[j] > x);
        if (i < j)swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);//这里用j的话，x不能取到有边界，由于(l+r)/2向下取整，所以是适合的
}
int main()
{
    scanf("%d", &n);
    for (int i = 0;i < n;i++)scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0;i < n;i++)printf("%d ", q[i]);

    return 0;
}
#endif
#if RUN_EXAMPLE_1 == 3
//快速选择
int a[100010];
int find_k(int a[], int l, int r, int k)
{
    if (l == r)return a[l];
    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while (i < j)
    {
        do i++;while (a[i] < x);
        do j--;while (a[j] > x);
        if (i < j)
        {
            int temp = a[i];a[i] = a[j];a[j] = temp;
        }
    }
    int sl = j - l + 1;
    if (k <= sl)return find_k(a, l, j, k);
    return find_k(a, j + 1, r, k - sl);
}
int main()
{
    int n, k;scanf("%d%d", &n, &k);
    for (int i = 0;i < n;i++)scanf("%d", &a[i]);
    printf("%d", find_k(a, 0, n - 1, k));
    return 0;
}
#endif

#define RUN_EXAMPLE_2 0
//——————————————————————————————归并排序

//中心思想 : 分治
//步骤：
//1.确定分界点：mid = (l + r) / 2，这里是下标而非数值
//2.递归排序left，right
//3.归并：合二为一两个指针分别指向两段最小值，二者比较，最小值入新数组，达成合并目的

#if RUN_EXAMPLE_2==1
const int N = 1e6 + 10;
int q[N], tmp[N];
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] < q[j])tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while (i <= mid)tmp[k++] = q[i++];
    while (j <= r)tmp[k++] = q[j++];
    for (int i = l, k = 0;i <= r;i++, k++)q[i] = tmp[k];
}
#endif
#if RUN_EXAMPLE_2==2
//逆序对数量
#include<iostream>
using namespace std;
#define max_ 1000010
int a[max_];long long ans = 0;
void count_inversion(int a[], int l, int r)
{
    if (l >= r)return;
    int mid = (l + r) / 2;
    count_inversion(a, l, mid);
    count_inversion(a, mid + 1, r);
    int tmp[max_], i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (a[j] < a[i])
        {
            tmp[k++] = a[j++];
            ans += mid + 1 - i;
        }
        else tmp[k++] = a[i++];
    }
    while (i <= mid)
    {
        tmp[k++] = a[i++];
    }
    while (j <= r)
    {
        tmp[k++] = a[j++];
    }
    for (int i = l, k = 0;i <= r;i++, k++)
    {
        a[i] = tmp[k];
    }
}
int main()
{
    int n;cin >> n;
    for (int i = 0;i < n;i++)cin >> a[i];
    count_inversion(a, 0, n - 1);
    cout << ans << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_3 0
//——————————————————————————————二分法

//————————————————————整数二分

#if RUN_EXAMPLE_3==1
//——————————模板一：找左边界

bool check(int n)
{
    //......
}
int main()
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
}
#endif
//——————————模板二：找右边界
#if RUN_EXAMPLE_3==2
bool check(int n)
{
    //......
}
int main()
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = r + l + 1 >> 1;
        if (check(mid))l = mid;
        else r = mid - 1;
    }
}
#endif
//——————————实例：对一个长度为n的升序数组查询m次，输出元素k的起始位置和终止位置
#if RUN_EXAMPLE_3==3
#include<iostream>
using namespace std;

const int N = 100010;
int q[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);  // 输入数组长度和查询次数

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    while (m--)
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }

        if (q[l] != x)
        {
            printf("-1 -1\n");
            continue;
        }

        printf("%d ", l);

        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] <= x) l = mid;
            else r = mid - 1;
        }

        printf("%d\n", l);
    }

    return 0;
}
#endif
//————————————————————浮点数二分
//求浮点数开平方
#define RUN_EXAMPLE_4 0
#if RUN_EXAMPLE_4 == 1
#include<iostream>
using namespace std;
int main()
{
    double x;
    cin >> x;
    double l = 0, r = x;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid > x)r = mid;
        else l = mid;
    }
    printf("%f", l);
    return 0;
}
#endif
//——————————————————————————————再遇高精度
//大整数是C++特有，笔试偶尔会出现
//第一种，两个大整数相加
//第二种，大整数相减
//第三种，大整数乘小整数
//第四种，大整数除以小整数
//存储方式：用整型数组
//从a[0]开始记录个位，以此类推，方便进位
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 1
//高精度减法
#include<iostream>
#include<vector>
using namespace std;
bool isA(vector<int>& A, vector<int>& B)
{
    if (A.size() != B.size())return A.size() > B.size();
    for (int i = A.size() - 1;i >= 0;i--)
        if (A[i] != B[i])return A[i] > B[i];
    return true;
}
vector<int> sub(vector<int>& A, vector<int>& B)
{
    if (!isA(A, B))return sub(B, A);
    int t = 0;vector<int> C;
    for (int i = 0;i < A.size();i++)
    {
        t = A[i] - t;
        if (i < B.size())t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0)C.pop_back();//减法注意去掉前导零
    return C;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1;i >= 0;i--)A.push_back(a[i]-'0');
    for (int i = b.size() - 1;i >= 0;i--)B.push_back(b[i]-'0');
    auto C = sub(A, B);
    if (isA(A, B))
    {
        for (int i = C.size() - 1;i >= 0;i--)cout << C[i];
    }
    else
    {
        cout << "-";
        for (int i = C.size() - 1;i >= 0;i--)cout << C[i];
    }
    return 0;
}
#endif
#if RUN_EXAMPLE_5 == 2
//高精度加法
#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0;i < A.size() || i < B.size();i++)
    {
        if (i < A.size())t += A[i];
        if (i < B.size())t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t > 0)C.push_back(1);//加法注意最后的进位
    return C;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1;i >= 0;i--)A.push_back(a[i] - '0');
    for (int i = b.size() - 1;i >= 0;i--)B.push_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1;i >= 0;i--)cout << C[i];
    return 0;
}
#endif
#if RUN_EXAMPLE_5 == 3
//高精度乘法
#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int>& A, int b)
{
    int t = 0;vector<int> C;
    for (int i = 0;i < A.size() || t;i++)
    {
        if(t<A.size())t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
int main()
{
    string a;int b;cin >> a >> b;
    vector<int> A;
    for (int i = a.size()-1;i >= 0;i--)A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for (int i = C.size() - 1;i >= 0;i--)cout << C[i];
    return 0;
}
#endif
#define RUN_EXAMPLE_5 0
#if RUN_EXAMPLE_5 == 4
//高精度除法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dec(vector<int>A, int b, int& r)
{
    r = 0;vector<int> C;
    for (int i = A.size() - 1;i >= 0;i--)
    {
        r = r * 10 + A[i];//余数到下一位*10
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());//注意反转
    while (C.size() > 1 && C.back() == 0)C.pop_back();//去除前导0
    return C;
}
int main()
{
    string a;int b;cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1;i >= 0;i--)A.push_back(a[i] - '0');
    int r;
    auto C = dec(A, b,r);
    for (int i = C.size() - 1;i >= 0;i--)cout << C[i]<<" ";
    cout << r << endl;
    return 0;
}
#endif
#if RUN_EXAMPLE_5 == 5
//大整数类
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
#define max_ 1000010

struct Bigint
{
    int a[max_];
    int len;

    // 添加构造函数初始化
    Bigint() {
        for (int i = 0;i < max_;i++) a[i] = 0;
        len = 1;
    }

    void flatten()
    {
        for (int i = 0;i < len;i++)
        {
            if (a[i] >= 10)
            {
                a[i + 1] += a[i] / 10;
                a[i] %= 10;
            }
        }
        // 处理最高位的进位
        while (a[len] != 0) len++;
        // 去除前导0（至少保留1位）
        while (len > 1 && a[len - 1] == 0) len--;
    }
};

Bigint operator+(const Bigint& b1, const Bigint& b2)
{
    Bigint ans;
    // 结果的长度至少是最大长度，最多是最大长度+1
    ans.len = max(b1.len, b2.len) + 1;

    // 清零所有相关位置
    for (int i = 0;i < ans.len;i++)
    {
        ans.a[i] = 0;
    }

    // 对应位相加
    for (int i = 0;i < max(b1.len, b2.len);i++)
    {
        ans.a[i] = b1.a[i] + b2.a[i];
    }

    // 处理进位
    ans.flatten();
    return ans;
}

istream& operator>>(istream& is, Bigint& b)
{
    string s;
    is >> s;
    b.len = s.size();
    for (int i = 0;i < b.len;i++)
    {
        b.a[i] = s[b.len - 1 - i] - '0';
    }
    return is;
}

ostream& operator<<(ostream& os, const Bigint& b)
{
    for (int i = b.len - 1;i >= 0;i--)
    {
        os << b.a[i];
    }
    return os;
}

int main()
{
    Bigint a, b;
    cin >> a >> b;
    cout << (a + b) << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_6 0
//——————————————————————————————再遇前缀和
//Si表示为前i个和
//如何求Si
//S[0]=0;
//S[i]=S[i-1]+a[i];
//Si的作用是什么
//快速求数组中一段的和以降低时间复杂度
//base-1
#if RUN_EXAMPLE_6 == 1
//一维前缀和
#include<iostream>
using namespace std;
#define max_ 100010
int a[max_], S[max_];
int main()
{
    int n, m;cin >> n >> m;
    for (int i = 1;i <= n;i++)cin >> a[i];
    for (int i = 1;i <= n;i++)S[i] = S[i - 1] + a[i];
    while (m--)
    {
        int l, r;cin >> l >> r;
        cout << (S[r] - S[l - 1]) << endl;

    }
}
#endif
#if RUN_EXAMPLE_6 == 2
//二维前缀和
//S[x,y]是[0,0]到[x,y]围起来的面积
//(x1,y1)与(x2,y2)围起来的面积：
//S[x1,y1]-S[x1-1,y2-1]-S[x2-1,y1-1]+S[x2-1,y2-1]
//如何求S
//S[i,j]=S[i-1,j]+S[i,j-1]-S[i-1,j-1]+a[i,j]
#include<iostream>
using namespace std;
#define max_ 1010
int a[max_][max_], S[max_][max_];
int main()
{
    int n, m, q;cin >> n >> m >> q;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> a[i][j];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1]) << endl;
        //类比于a[i]-a[j-1]
    }
    return 0;
}
#endif
#define RUN_EXAMPLE_7 0
//——————————————————————————————再遇差分
//若[l,r]段+c
//只需在差分数组的b[l]+=c,之后的点就+c了,再令b[r+1]-=c,这之后的数抵消，没变
//二维差分
#if RUN_EXAMPLE_7 == 1
#include<iostream>
using namespace std;
#define max_ 1010
int a[max_][max_], b[max_][max_];
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    int n, m, q;cin >> n >> m >> q;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            cin >> a[i][j];insert(i, j, i, j, a[i][j]);
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];//前缀和
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
#endif
#define RUN_EXAMPLE_8 0
//——————————————————————————————双指针
//核心思想，将for(int i=0;i<n;i++){for(int j=0;j<m;j++){}}优化到O(n);
#if RUN_EXAMPLE_8 == 1
//分割单词
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char s[200];
    fgets(s, sizeof(s), stdin);
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        int j = i;
        while (j < n && s[j] != ' ')j++;
        for (int k = i;k < j;k++)printf("%c", s[k]);
        i = j;
        printf("\n");
    }
    return 0;

}
#endif
#if RUN_EXAMPLE_8 == 2
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char s[200];
    fgets(s, sizeof(s), stdin);
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] != ' ')printf("%c", s[i]);
        else
        {
            printf("\n");
            continue;
        }
    }
}
#endif
#if RUN_EXAMPLE_8 == 3
//最大连续子序列
#define max_ 100010
#include<iostream>
#include<cmath>
using namespace std;
int s[max_], a[max_];
int n;
int main()
{
    cin >> n;
    for (int i = 0;i < n;i++)cin >> a[i];
    int res = 0;
    for (int i = 0,j=0;i < n;i++)
    {
        s[a[i]]++;
        while (s[a[i]] > 1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
#endif
#if RUN_EXAMPLE_8 == 4
//指针相向而行
#include<iostream>
using namespace std;
#define max_ 100010
int a[max_], b[max_];
int main()
{
    int n, m, x;cin >> n >> m >> x;
    for (int i = 0;i < n;i++)cin >> a[i];
    for (int i = 0;i < m;i++)cin >> b[i];
    for (int i = 0, j = m - 1;i < n && j >= 0;)//i从头出发，j从尾出发
    {
        if (a[i] + b[j] == x) { cout << i << " " << j;return 0; }
        else if (a[i] + b[j] > x) { j--;continue; }
        else { i++;continue; }
    }
    return 0;
}
#endif
#if RUN_EXAMPLE_8 == 5
//判断子序列
#include<iostream>
using namespace std;
#define max_ 100010
int a[max_], b[max_];
int main()
{
    int n, m;cin >> n >> m;
    for (int i = 0;i < n;i++)cin >> a[i];
    for (int i = 0;i < m;i++)cin >> b[i];
    int j = 0;
    for (int i = 0;i < m && j < n;i++)
    {
        if (b[i] == a[j])j++;
    }
    if (j == n)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
#endif
#define RUN_EXAMPLE_9 0
//——————————————————————————————再遇位运算
//查看第k位是几
//n>>k&1
#if RUN_EXAMPLE_9 == 1
#include<iostream>
using namespace std;
int main()
{
    int n = 10;
    for (int k = 3;k >= 0;k--)cout << (n >> k & 1);
    return 0;
}
#endif
#if RUN_EXAMPLE_9 == 2
//lowbit(x)返回x的最后一位1
//x&-x等价于x与x取反+1，-x是x的补码
//应用：x里面有多少个1
#include<iostream>
using namespace std;
int lowbit(int x)
{
    return x & -x;
}
int main()
{
    int x;cin >> x;
    int res = 0;
    while (x)
        x -= lowbit(x), res++;
    cout << res;
    return 0;
}
#endif
#define RUN_EXAMPLE_10 0
//——————————————————————————————离散化
//离散化的本质是建立了一段数列到自然数之间的映射关系（value -> index)，
//通过建立新索引，来缩小目标区间，使得可以进行一系列连续数组可以进行的操作比如二分，前缀和等…
//离散化首先要求对数组进行排序，去重，去重操作由unique函数进行，返回不重复元素的尾端
/*vector<int>::iterator unique(vector<int>&a)
* {
*     int j=0;
*     for(int i=0;i<a.size();i++)
*     {
*         if(!i||a[i]!=a[i-1])a[j++]=a[i];
*     }
*     return a.begin()+j;
* }
* 
*/
#if RUN_EXAMPLE_10 == 1
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define max_ 300010
typedef pair<int, int> PII;
int n, m;//插入n个数，进行m次查询
int a[max_], s[max_];//数组a记录离散化之后的值
vector<int> alls;//存入所有被涉及的下标，以完成离散化映射，包括区间下标
vector<PII> add, query;//add存入新增的数，query存入下标区间
int find(int x)//在下标数组alls中找到映射
{
    int l = 0, r = alls.size()-1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)r = mid;
        else l = mid + 1;
    }
    return r + 1;//base-1，便于求前缀和
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        int x, c;//x为旧下标，c为数值
        cin >> x >> c;
        add.push_back({ x,c });//存值

        alls.push_back(x);//存下标
    }
    for (int i = 0;i < m;i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({ l,r });
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;//有可能在同一位置多次插入
    }
    for (int i = 1;i <= alls.size();i++)s[i] = s[i - 1] + a[i];
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
#endif
#define RUN_EXAMPLE_11 0
//——————————————————————————————区间合并
//按区间左端点排序
//扫描整个区间，把可能有交集的区间合并
#if RUN_EXAMPLE_11 == 1
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
typedef pair<int, int> PII;
vector<PII> a;
void merge(vector<PII>& a)
{
    vector<PII> t;
    sort(a.begin(), a.end());
    int st = -2e9, end = -2e9;
    for (auto item : a)
    {
        if (end < item.first)
        {
            if (st != -2e9)t.push_back({ st,end });
            st = item.first;
            end = item.second;
        }
        else end = max(end, item.second);
    }
    if (st != -2e9)t.push_back({ st,end });
    a = t;
}
int main()
{
    int n;cin >> n;
    while (n--)
    {
        int l, r;cin >> l >> r;
        a.push_back({ l,r });
    }
    merge(a);
    cout << a.size() << endl;
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

