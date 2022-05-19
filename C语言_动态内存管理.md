## 动态内存管理

### malloc函数

```c
// 动态内存开辟
// malloc函数：void* malloc( size_t size );
// 返回类型为void*类型，size是大小，单位是字节。
// 动态内存开辟的思路就是：使用malloc函数开辟size个字节的空间，我们定义指针类型来接收

int main()
{
	int*  p = (int*)malloc(10*sizeof(int));
	if (p == NULL) // 空间开辟失败返回空指针，开辟成功返回地址
	{
		perror("malloc");
	}
	else
	{
		int i = 0;
		for (i = 0; i < 25; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 25; i++)
		{
			printf("%d ", *(p + i));
		}
		// 回收-释放内存
		free(p); // free不能释放非动态开辟内存
		// 可以把p指向的内存释放，但是却不能把p里面存的地址改变，所以给他置为NULL
		p = NULL;
	}

	return 0;
}
```

### calloc函数

```c
// 内存开辟函数-calloc()函数
// void *calloc( size_t num, size_t size );
// 第一个参数是多少个元素，第二个参数是每个元素的大小
// calloc把初始化的每个字节初始化为0

int main()
{
	int* p = calloc(10, sizeof(int));
	if (p == NULL)
	{
		perror("calloc");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;

	return 0;
}
```

### realloc函数

```c
// realloc()函数是内存大小扩充函数
// void *realloc( void *memblock, size_t size );
// 第一个参数是要扩充内存的起始地址，第二个参数是扩充后的内存大小
// 扩充的两种情况：1.如果要扩充的地址后面有足够大的空间，就直接在源地址上扩充，函数返回值是原来的内存地址
//              2.如果不够，那就新开辟一块内存，然后返回新的地址

int main()
{
	int* p = malloc(10 * sizeof(int));

	if (p == NULL)
	{
		perror("malloc");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}

	int* ptr = realloc(p, 20 * sizeof(int));
	if (ptr == NULL)
	{
		perror("realloc");
		return 0;
	}
	else
	{
		p = ptr;
		ptr = NULL;
	}

	for (int i = 0; i < 20; i++)
	{
		p[i] = i + 1;
	}

	for (int i = 0; i < 20; i++)
	{
		printf("%d ", p[i]);
	}

	free(p);
	p = NULL;

	return 0;
}
```
