### 经典题3

```c
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str); // free之后虽然内存没有了，但是str还是指向那块内存的初始地址的，所以后面会覆盖前面的值

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();

	return 0;
}
```

![image-20220505225627682](C:\Users\AKANG\AppData\Roaming\Typora\typora-user-images\image-20220505225627682.png)

### C/C++程序内存分配的几个区域：

1. 栈区（stack）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些
   存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有
   限。 栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。

2. 堆区（heap）：一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。分配方式类似
   于链表

3. 数据段（静态区）（static）存放全局变量、静态数据。程序结束后由系统释放

4. 代码段：存放函数体（类成员函数和全局函数）的二进制代码。

   

   有了这幅图，我们就可以更好的理解在《C语言初识》中讲的static关键字修饰局部变量的例子了。
   实际上普通的局部变量是在**栈区**分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁。
   但是被static修饰的变量存放在**数据段（静态区）**，数据段的特点是在上面创建的变量，直到程序结束才销毁
   所以生命周期变长  

### 柔性数组

**柔性数组（flexible array）：** C 99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。  

```c
// 柔性数组
struct S
{
	int num;
	char arr[];
};

int main()
{
	struct S* p = malloc(sizeof(struct S)+6); // 增加6个单位
	p->num = 100;
	for (int i = 0; i < 6; i++)
	{
		p->arr[i] = 'a' + i;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("%c ", p->arr[i]);
	}

	struct S* ptr = malloc(p, 14); // 一共增加10个单位
	if (ptr != NULL)
	{
		p = ptr;
	}
	for (int i = 0; i < 10; i++)
	{
		p->arr[i] = 'x';
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", p->arr[i]);
	}

	free(p);
	p = NULL;

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

// 普通方案

// 对arr扩容
struct S2
{
	int num;
	char* arr;
};

int main()
{
	struct S2* ps = (struct S2*)malloc(sizeof(struct S2));
	ps->num = 100;
	ps->arr = (char*)malloc(6 * sizeof(char));
	for (int i = 0; i < 6; i++)
	{
		ps->arr[i] = 'a' + i;
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%c ", ps->arr[i]);
	}
	// 增容
	char* ptr = realloc(ps->arr, 10);
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	for (int i = 0; i < 10; i++)
	{
		ps->arr[i] = 'x';
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", ps->arr[i]);
	}

	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;

	return 0;
}
```
