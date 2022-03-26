### 两个int数字比特位不同个数

```c
// 比较两个int型数字的比特位不同个数

int Get_Diff_Bit1(int a, int b)
{
	// 思想:用1与某个数字，可以得到这个数字比特位的最后一位数字
	// 所以我们可以把这个数组每个比特位的数字给他移到最后一位，跟1与一下，就可以得到他的所有位数字
	int count = 0;
	int i = 0;
	while (i < 32)
	{
		if (((a >> i) & 1) != ((b >> i) & 1))
			count++;

		i++;
	}
	return count;
}

int Get_Diff_Bit2(int a, int b)
{
	// 思想:a^b后，比特位相同为0，不同为1，所以只需要计算a^b后比特位为1的个数

	int count = 0;
	int i = 0;
	int tmp = a ^ b;

	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	return count;
}

int main()
{
	int a = 0, b = 0;
	printf("请输入两个数字:>");
	scanf("%d%d", &a, &b);

	int sum1 = Get_Diff_Bit1(a, b);
	int sum2 = Get_Diff_Bit2(a, b);
	printf("%d与%d不同位的个数为：%d  %d", a, b, sum1,sum2);

	return 0;
}
```

### 