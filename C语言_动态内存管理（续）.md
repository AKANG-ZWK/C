### 动态内存开辟常见错误

```c
// 动态开辟内存常见错误
/*
1. 对NULL指针解引用（动态开辟内存失败返回NULL）
2. 对动态开辟内存越界访问（开辟的内存不够，访问超范围）
3. 对于非动态开辟内存使用free
4. free动态开辟内存的一部分（动态开辟内存只能从起始位置释放）
5. 对同一块动态内存的多次释放
6. 忘记释放动态开辟的内存空间
*/
```

### 经典题1

```c
// 错误代码

void GetMemory(char* p) // 把NULL传递给p了
{
	p = (char*)malloc(100); // p拥有了一块空间，跟str没关系
}

void Test(void)
{
	char* str = NULL;
	// str是个空指针指向地址为0的位置，而这个位置是不能访问的，所以传递的时候其实传的是NULL
    GetMemory(str);
	strcpy(str, "hello, world");
	printf(str);
	free(str);
}

int main()
{
	Test();

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

// 改造代码 - 1
void GetMemory(char** p) 
{
	*p = (char*)malloc(100);
}

void Test(void)
{
	char* str = NULL;

	GetMemory(&str); 
	// 把str的地址传过去，然后解引用找到str，给它赋值；如果直接传str，str是空的，传了没用

	strcpy(str, "hello, world");
	printf(str);
	free(str);
}

int main()
{
	Test();

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

// 改造代码 - 2
char* GetMemory(char* p) 
{
	p = (char*)malloc(100);
	return p;
}

void Test(void)
{
	char* str = NULL;

	str = GetMemory(str);
	// 把str的地址传过去，然后解引用找到str，给它赋值；如果直接传str，str是空的，传了没用

	strcpy(str, "hello, world");
	printf(str);
	free(str);
}

int main()
{
	Test();

	return 0;
}
```

### 经典题2

```c
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
```

### 
