### 作业

#### 计算阶乘

```c
// 计算阶乘

int main()
{
	int ret = 1;
	int sum = 0;
	int n = 0;
	printf("please enter a number!  ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
		sum += ret;
	}
	printf("%d\n", sum);

	return 0;
}

```



#### 折半查找

```c
// 折半查找

void find(int* arr, int sz, int x)
{
	int left = 0;
	int right = sz;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] > x)
		{
			right = middle - 1;
		}
		else if (arr[middle] < x)
		{
			left = middle + 1;
		}
		else
		{
			printf("找到了！ a[%d]=%d\n", middle, x);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到！");
	}
}

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]); // 这行代码不能写到函数里面去，因为数组传参的时候传的是数组首元素地址，并非整个数组。
	printf("输入要查找的数：");
	int x = 0;
	scanf("%d", &x);
	find(arr, sz, x);

	return 0;
}
```



#### 猜数字

```c
// 猜数字
void menu()
{
	printf("**************************************\n");
	printf("*********     1. play         ********\n");
	printf("*********     0. exit         ********\n");
	printf("**************************************\n");

}

void game()
{
	int guess = 0;
	// 1.生成随机数
	int ret = rand() % 100 + 1;
	// 2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了！\n");
		}
		else if (guess < ret)
		{
			printf("猜小了！\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL)); // 括号里设置不同的数，能产生不同的随机数
	int input = 0;

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("输入错误，请重新选择！");
			break;
		}
	} while (input);

	return 0;
}
```



#### 输三次密码

```c
// 输入三次密码

int main()
{
	int i = 0;

	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%d", password);

		if (strcmp(password, "123456") == 0)
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误，重新输入\n");
		}
	}
	if (i == 3)
	{
		printf("三次密码错误,将自动退出！");
	}

	return 0;
}
```



#### 字符串聚集

```c
// 字符向中间聚集

int main()
{
	char arr1[] = "Welcome to bit!!!!";
	char arr2[] = "##################";

	int left = 0;
	int right = strlen(arr1) - 1;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
		left++;
		right--;
	}
	printf("%s\n", arr2);

	return 0;
}
```



#### 关机程序

```c
// 关机程序
// 程序运行起来，就提示1分钟内关机，如果输入：我是猪，就取消关机！

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		printf("请注意，你的电脑在一分钟内关机，如果输入：我是猪，就取消关机！\n");
		scanf("%s", input);
		// 比较两个字符串 - strcmp
		if (strcmp(input, "我是猪")==0)
		{
			system("shutdown -a");
			printf("succes");
			break;
		}
	}
	return 0;
}
```



#### 求最大公约数

```c
// 求最大公约数

void ordinary(int x, int y) // 暴力求解方法
{
	int min = 0;
	if (x < y)
	{
		min = x;
	}
	else
	{
		min = y;
	}

	for (int i = min; i >= 1; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			printf("最大公约数为：%d", i);
			break;
		}
	}
}

void mutual(int x, int y) // 辗转相除法
{
	int z = 0;
	while (z = x % y)
	{
		x = y;
		y = z;
	}
	printf("最大公约数为：%d", y);
}

int main()
{
	ordinary(36, 18);
	mutual(36, 18);

	return 0;
}
```



#### 输出100~200之间的素数

```c
// 输出100~200之间的素数

int main()
{
	int count = 0;
	for (int i = 101; i <= 200; i += 2) // 100以上的偶数肯定不是素数
	{
		int flag = 1;
		// 判断i是否为素数 用2->根号i的数字去除
		int j = 0;
		// 如果一个数不是素数，那么它的平方根肯定大于等于最小的那个因子
		for ( j = 2; j <= sqrt(i); j++) 
		{
			if (i % j == 0)
			{
				flag = 0; // 标记不是素数
				break;
			}
		}
		if (1 == flag)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d", count);

	return 0;
}
```



#### 罗哥

```c
// 骂罗哥的两种方式

int main()
{
	int input = 1;
	while (input)
	{
		char arr1[] = "Luoge is a bitch! Fuck you!";
		char arr2[] = "###########################";

		int left = 0;
		int right = strlen(arr2) - 1;

		printf("请选择如何骂罗哥>: 1 动态  2 静态  0 退出\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			system("cls");
			while (left <= right)
			{
				printf("	动态骂罗哥！\n\n");
				arr2[left] = arr1[left];
				arr2[right] = arr1[right];
				printf("%s", arr2);
				Sleep(500);
				system("cls");
				left++;
				right--;
			}
			printf("\n\n	%s\n\n\n", arr2);
			
			break;
		case 2:
			system("cls");
			printf("	静态骂罗哥！\n\n");
			printf("\n\n");
			while (left <= right)
			{
				arr2[left] = arr1[left];
				arr2[right] = arr1[right];
				printf("%s\n", arr2);
				left++;
				right--;
			}
			printf("\n\n\n");
			break;
		}
	}
}
```

