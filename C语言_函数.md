## 函数

```c
// 交换两个数字的函数 
// 需要注意的点：形参 生命周期 指针

void swap(int* px, int* py)
{
	int tmp = *py;
	*py = *px;
	*px = tmp;
}

int main()
{
	int x = 0;
	int y = 0;

	printf("请输入两个数字：  ");
	scanf("%d%d", &x, &y);

	swap(&x, &y);

	printf("%d %d\n", x, y);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

int is_leap_year(int x)
{
	return ((x % 400 == 0) || (x % 100 != 0) && (x % 4 == 0));
}

int main()
{
	int y = 0;
	for (y = 1000; y <= 2000; y++)
	{
		if (is_leap_year(y) == 1)
		{
			printf("%d  ", y);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	// 链式访问
	printf("%d", printf("%d", printf("%d", 43))); // 输出4321
	// printf函数返回值是 打印的个数

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////


```



### 递归函数（写博客）

> **什么是递归**？
> 程序调用自身的编程技巧称为递归（ recursion）。 递归做为一种算法在程序设计语言中广泛应用。 一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。 递归的主要思考方式在于：把大事化小。
>
> **递归的两个必要条件**
> 存在限制条件，当满足这个限制条件的时候，递归便不再继续。
> 每次递归调用之后越来越接近这个限制条件。
>
> **递归可能导致栈溢出,尽量使用迭代的方式来解决问题**



#### 把一个数倒过来

```c
// 把一个数倒过来

void print(int n)
{
	if (n > 9)
	{
		print(n / 10); // 一直调用函数到头，然后一层一层返回
	}
	printf("%d ", n % 10);
}

int main()
{
	unsigned int num = 0;
	scanf("%d", &num);
	print(num);

	return 0;
}
```



#### 求字符串长度

```c
// 递归求字符串长度
int my_strlen(char* str)
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
	{
		return 0;
	}

}

int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d ", len);

	return 0;
}
```



#### 计算斐波那契数

```c
// 计算斐波那契数
int Fibo2(int n) // 循环的方法
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int Fibo1(int n)  // 递归的方法
{
	if (n < 3)
	{
		return 1;
	}
	else
	{
		return Fibo1(n - 1) + Fibo1(n - 2);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	/*int ret_1 = Fibo1(n);
	printf("%d ", ret_1);*/

	int ret_2 = Fibo2(n);
	printf("%d ", ret_2);

	return 0;
}
```



#### 汉诺塔

```c
// 汉诺塔

void move(int n, char a, char b, char c)
{
	if (n == 1)
		printf("\t%c->%c\n", a, c);    //当n只有1个的时候直接从a移动到c 
	else
	{
		move(n - 1, a, c, b);            //把a的n-1个盘子通过c移动到b 
		printf("\t%c->%c\n", a, c);   //把a的最后1个盘(最大的盘)移动到c 
		move(n - 1, b, a, c);            //把b上面的n-1个盘通过a移动到c 
	}
}

main()
{
	int n;
	printf("请输入要移动的块数：");
	scanf("%d", &n);
	move(n, 'a', 'b', 'c');
}
```



#### 逆序字符串

```c
// 用递归的方式逆序字符串
void reverse(char* arr)
{
	char tmp = arr[0];
	int len = strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (strlen(arr + 1) > 1)
		reverse(arr + 1);
	arr[len - 1] = tmp;
}

int main()
{
	char arr[] = "abcdef";
	reverse(arr);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

// 常规方法逆序字符串
void reverse(char* arr)
{
	int len = strlen(arr);
	char tmp = 0;
	int left = 0;
	int right = len - 1;

	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcdefghi";
	
	reverse(arr);
	printf("%s", arr);

	return 0;
}
```



#### 计算一个数每位数字之和

```c
// 用递归计算一个数各个位数字之和
int DigitSum(int n)
{
	// 分析：用拆分的方式分析递归逻辑
	// DigitSum(1234) =            DigitSum(123)          +  1234%10
	//				  =      DigitSum(12)   + 123%10      +  1234%10
	//				  = DigitSum(1) + 12%10 + 123%10   +     1234%10
	//
	//
	int sum = 0;
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	else
	{
		return n;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	int ret = DigitSum(n);
	printf("%d", ret);
	return 0;
}
```

#### 计算一个数的n次方

```c
// 递归计算一个数的n次方
double pow(int num, int k)
{
	if (0 == k)
	{
		return 1.0;
	}
	else if (k > 0)
	{
		return (double)num * pow(num, k - 1);
	}
	else
	{
		return 1.0 / pow(num, -k);
	}
}

int main()
{
	int num = 0, k = 0;
	scanf("%d %d", &num, &k);

	double ret = pow(num, k);

	printf("%lf", ret);
}
```

