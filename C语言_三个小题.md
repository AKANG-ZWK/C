### 打印菱形

```c
// 打印菱形

#define N 10 // 这个是菱形的偏移值，越大菱形越靠近中间

int main()
{
	int n = 0;
	printf("请输入行数(奇数):>");
	scanf("%d", &n);

	// 打印上半部分
	for (int i = 0; i < n / 2 +1; i++)
	{
		for (int j = 0; j < n / 2 - i + N; j++)
		{
			printf(" ");
		}

		for (int j = 0; j < 2 * (i + 1) - 1; j++)
		{
			printf("*");
		}

		printf("\n");

	}

	// 打印下半部分
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < i + 1 + N; j++)
		{
			printf(" ");
		}

		for (int j = 0; j < 2 * (n / 2 - i) -1; j++)
		{
			printf("*");
		}

		printf("\n");
	}
    
	return 0;
}
```

### 喝饮料

```c
// 一元能买一瓶饮料，两个空瓶可以兑换一瓶饮料，20元能和几瓶饮料？

int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;

	printf("请输入钱数:>");
	scanf("%d", &money);

	total += money;
	empty = money;

	while (empty >= 2)
	{
		total += empty / 2;
		// 盘点手里空瓶
		empty = empty / 2 + empty % 2;
	}

	printf("喝了%d瓶", total);

	return 0;
}
```

### 奇数放在偶数后

```c
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得数组中所有的奇数位于数组的前半部分
// 所有的偶数位于数组的后半部分

void move_arr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		for (int j = i+1; j < sz; j++)
		{
			if (arr[i] % 2 == 0)
			{
				if (arr[j] % 2 != 0)
				{
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
}

int main()
{
	int arr[] = { 2, 1, 3, 5, 7, 9 ,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	move_arr(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
```

