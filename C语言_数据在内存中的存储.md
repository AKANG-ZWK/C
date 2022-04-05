## 调试技巧

### 快捷键

- F5 ：调试    
- F10： 逐过程调试    
- F11：逐语句调试     
- Ctrl + F5：直接运行不调试      
- Shift + F5：结束调试
- F9：添加断点，断点处右键，可以设置条件

### 窗口

**调用堆栈**：对于复杂代码，调用堆栈可以看清楚代码逻辑

**内存监视**：可以查看变量在内存中的十六进制值

**监视**：可以添加变量，监视变量值的变化



```c
// 调试用例，刚开始不写 ret = 1 调试发现问题
// 调试就是一步一步看代码运行，当程序调试时，内心得清楚代码下一步的结果，心中要有数

int main()
{
	int n = 0;
	scanf("%d", &n);

	int ret = 1;
	int i = 0;
	int j = 0;
	int sum = 0;

	for (j = 1; j <= n; j++)
	{
		ret = 1;
		for (i = 1; i <= j; i++)
		{
			ret *= i;
		}
		sum += ret;
	}

	printf("sum = %d", sum);

	return 0;
}
```

### 一个错误程序

```c
/*内存划分:  栈区 - 局部变量、函数参数
            堆区 - 动态内存分配
			静态区 - 静态变量、全局变量

  栈区使用习惯：先使用高地址空间，再使用低地址空间！
  数组：随着下标的增长，地址空间是由低到高变化的！

  程序运行时，先产生i压入栈中，再产生数组
  arr[12] <==> *(arr + 12) 

*/

int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 0-9 越界访问
	// 陷入死循环：i的地址与arr[12]地址一样，当循环到i=12时，会将i的值置为0，因此永远跳不出循环
	// 可以调试一下看看
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}

	return 0;
}
```

### 关于代码优化

```c
// 关于代码优化
// 字符串拷贝函数优化
char* my_strcpy(char* dest, const char* src)
{
	/*while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;*/

	// 上面代码的高端写法
	char* ret = dest; // 记录起始位置
	assert(dest != NULL); // 断言，如果括号里的表达式满足，程序运行时会反馈
	assert(src != NULL); 

	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "hello";
	char arr2[20] = { 0 };
	
	/*char* p = NULL; // 这两行用来测试assert
    my_strcpy(p, arr1);*/

	printf("%s\n", my_strcpy(arr2, arr1));

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

// 求字符串长度的高端代码

int my_strlen(const char* str) // 位置1
{
	int count = 0;
	assert(str != NULL); // 位置2

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char arr[] = "abc";
	int len = my_strlen("abc");
	printf("%d", len);

	return 0;
}
```

