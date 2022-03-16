## 初识C语言



### 变量的作用域和生命周期

**作用域：**作用域（scope），程序设计概念，通常来说，一段程序代码中所用到的名字并不总是有效/可用
的，而限定这个名字的可用性的代码范围就是这个名字的作用域。  

1. 局部变量的作用域是变量所在的局部范围。  
2. 全局变量的作用域是整个工程。

**生命周期：**变量的生命周期指的是变量的创建到变量的销毁之间的一个时间段  

1. 局部变量的生命周期是：进入作用域生命周期开始，出作用域生命周期结束。
2. 全局变量的生命周期是：整个程序的生命周期。  



### 常量

C语言中的常量和变量的定义的形式有所差异。

C语言中的常量分为以下以下几种：  

1. 字面常量

2. const修饰的常变量

3. #define定义的标识符常量

4. 枚举常量

   ```c
   // 常量
   // 举例
   enum Sex
   {
   	MALE,
   	FEMALE,
   	SECRET
   };
   // 括号中的MALE,FEMALE,SECRET是枚举常量
   int main()
   {
   	3.14;//字面常量
   	1000;//字面常量
   	const float pai = 3.14f; // const 修饰的常量
   	int pai = 5.14; // ok?
   #define MAX 100  // #define的标识符常量
   	return 0;
   }
   ```

   - 变量的定义和使用
     - 全局变量

     - static静态全局变量
     - 局部变量
     - static静态局部变量

   - 变量的内存分布
     - data和bss数据段
     - heap栈
     - stack栈

   - 变量的作用域和生命周期
     - 全局变量。整个工程都可以访问，整个程序运行的生命周期。
     - static静态全局变量。当前文件可以访问，整个程序运行的生命周期。
     - 局部变量。函数内部可以访问（函数两个{}之间的范围），函数运行的生命周期。
     - static静态局部变量。函数内部可以访问（函数两个{}之间的范围），整个程序运行的生命周期。

   ![image-20211216115236795](C:\Users\AKANG\AppData\Roaming\Typora\typora-user-images\image-20211216115236795.png)

### 字符串

```c
// 字符串

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = { 'a','b','c','d','e','f' };
	char arr3[] = { 'a','b','c','d','e','f', '\0' };
	// %s 是打印字符串

	printf("%s\n", arr1);
	printf("%s\n", arr2); // %s输出的时候找到'\0'才停
	printf("%s\n", arr3);

	printf("%d\n", strlen(arr1)); // 输出 6
	printf("%d\n", strlen(arr2)); // 输出随机值。没有'\0'，所以无法计算长度
	printf("%d\n", strlen(arr3)); // 输出 6。 '\0'是字符串结束的标志，不算长度

	printf("%d\n", sizeof(arr1)); // 输出 7
	printf("%d\n", sizeof(arr2)); // 输出 6
	printf("%d\n", sizeof(arr3)); // 输出 7 

	// strlen()计算字符串的长度
    // sizeof()计算所占内存大小

	return 0;
}
```



### 转义字符

```c
int main()
{
	printf("c:\code\test.c \n");
	printf("c:\\code\\test.c \n"); // 想要输出这个路径，得用'\'进行转义
	
	printf("%c\n",'\101'); // 转义后101是八进制数，对应ASCII码值为65的字符
	printf("%c\n",'\x5f'); // '\x'表示把后面的数字转换为16进制数
	printf("%d\n",strlen("C:\test\328\test.c")); // 14 里面的8不是八进制，故当成字符
	
	return 0;
}
```



### 按位与、或、异或

```c
// 按位与、或、异或
int main()
{
	int a = 3; // 最后一个字节 0000 0011
	int b = 5; // 最后一个字节 0000 0101  
	int c = a & b; // & 按位与 有一个假就为假			 0000 0001
	int d = a | b; // | 按位或 有一个真就为真			 0000 0111
	int e = a ^ b; // ^ 按位异或 相异即为1 相同即为0  	0000 0110
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);

	return 0;
}
```



### 按位取反~

```c
// ~ 按位取反

int main()
{
	int a = 0;
	// 0000 0000 0000 0000 0000 0000 0000 0000  0原码
	// 	   按位取反
	// 
	// 	   正数：补码 == 原码，
	//     负数补码：符号位不变，反码+1
	//     负数原码：补码-1，符号位不变，再取反
	// 	   负数反码：原码基础上，符号位不变，其他位取反；补码基础上-1
	// 1111 1111 1111 1111 1111 1111 1111 1111  -1的补码 
	// 1111 1111 1111 1111 1111 1111 1111 1110  -1的反码
	// 1000 0000 0000 0000 0000 0000 0000 0001  -1的原码
	printf("%d \n", ~a);
	printf("%d", a);

	return 0;
}
```



### static关键字

```c
// static 关键字
// 1.static可以修饰局部变量，改变生命周期，和程序声明周一样长
// 2.static可以修饰全局变量，改变全局变量的作用域，这个变量只能在自己的源文件中使用
// 3.static可以修饰函数，改变函数的使用范围，函数也只能在自己的源文件中使用

void test()
{
	// int a = 1; // 每次调用完函数a就被销毁
	static int a = 1; // 函数调用完之后保留a的值
	a++;
	printf("%d ", a);
}

int main()
{
	int i = 0;

	while (i < 10)
	{
		test();
		i++;
	}
	return 0;
}
```



### define定义宏和符号常量

```c
// define 定义符号常量和宏

#define MAX 100  // 定义符号常量

#define ADD(X,Y) ((X)+(Y)) // 定义加法的宏

int main()
{
	int a = MAX;
	printf("%d \n", a);

	int sum = ADD(3, 5);
	printf("%d\n", sum);

	return 0;
}
```



### 结构体

```c
// 结构体

struct Stu
{
	char name[20];
	int age;
};

int main()
{
	struct Stu s1 = { "张三",20 };
	struct Stu* ps = &s1;

	printf("%s %d\n", s1.name, s1.age);
	printf("%s %d\n", ps->name, ps->age);
	return 0;
}
```

