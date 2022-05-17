### 杨氏矩阵中找一个数

```c
// 在杨氏矩阵中找一个数 返回型参数设计

find_num(int arr[][3], int* px, int* py, int n)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y] == n)
		{
			*px = x;
			*py = y;

			return 1;
		}
		else if (arr[x][y] > n)
			y--;
		else if (arr[x][y] < n)
			x++;
	}
	*px = -1;
	*py = -1;

	return 0;
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3;
	int y = 3;
	int ret = find_num(arr, &x, &y, 3);
	if (ret == 1)
	{
		printf("找到了！\n");
		printf("x=%d, y=%d\n", x, y);
	}
	else
	{
		printf("x=%d, y=%d\n", x, y);
		printf("找不到！\n");
	}
}
```
