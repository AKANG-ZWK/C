# C语言

## 指针-初级

##### 数据类型的本质是为了合理利用内存



##### 编号（地址）：内存中每一个字节分配一个号码，定义一个变量专门来存放上面的号码（地址）

```c
void test()
{
    int num = 100;
    // &:取变量的地址
    // &num 代表标量num的起始地址
    printf("%p\n",&num);

    // 需求：定义一个指针变量 保存num的地址
    // 在定义的时候： *说明p是指针变量 而不是普通变量
    int *p = NULL;
    printf("sizeof(p)=%d\n",sizeof(p));

    // num的地址 与p建立关系
    p = &num;
    printf("num = %d \n",num);
    // 使用中：*p表示取p保存的地址编号 对应的空间内容
    printf("*p = %d\n",*p);
}

```



##### 指针变量

```c
void test1()
{
    int num = 10;
    
    // 指针变量两种类型： 自身的类型  指向的类型
    
    // 自身的类型：在指针变量定义的时候 将变量名拖黑 剩下啥类型 指针变量就是啥类型
    //    p就是int*类型
   
    // 指向的类型：在指针变量定义的时候 将变量名和离他最近的一个*一起拖黑 剩下啥类型 指针变量指向的类型就是啥类型   p指向的类型就是int类型
    
    // 指针变量指向的类型的作用：决定了指针变量，所取内容的宽度；决定了指针变量+1跳过的单位跨度
    
    int *p = NULL;
    // 指针变量的跨度
    printf("&num  %u\n",&num);
    printf("p  %u\n",p);
    printf("p+1  %u\n",p+1);
}

void test2()
{
    int num = 0x01020304;
    
    int *p1 = &num;
    printf("*p1 = %#x\n",*p1); // 0x01020304
    
    short *p2 = &num;
    printf("*p2 = %#x",*p2); // 0x0304
    
    char *p3 = &num;
    printf("*p3 = %#x",*p3); // 0x04
    
    short *p4 = &num;
    p4 += 1;
    printf("*p4 = %#x",*p4); // 0x0102
}
```





<img src="C:\Users\AKANG\AppData\Roaming\Typora\typora-user-images\image-20220114121648174.png" alt="image-20220114121648174" style="zoom:50%;" />



##### 野指针

​		概念：野指针就是指针指向的位置是不可知的（随机的、不确定的、没有明确限制的）

​		形成原因：1.指针未初始化（不初始化的话指针指向一个随机的地址）   2.指针越界访问（一般是数组）  3.指针指向空间释放（指向一个局部变量的地址，如果地址被使用，则不能返回想要的值）

​		如何规避野指针？

​          1. 指针初始化  

​          2. 小心指针越界指针指向空间释放及时置NULL

​		  3. 指针使用之前检查有效性



##### 指针运算

```c
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start; // 指针运算
}

int main()
{
	//test01();
	//test02();
	test03();

	char arr[] = "bit";
	int len = my_strlen(arr);
	printf("%d \ n", len);
	return 0;
}
```



##### 指针与数组

```c
int main()
{
	// 数组名是首元素地址，但是这个地址指的是整个数组
	int arr[10] = { 0 };
	printf("%p\n", arr); // 008FF960
	printf("%p\n", arr+1); // 008FF964

	printf("%p\n", &arr[0]); // 008FF960
	printf("%p\n", &arr[0]+1); // 008FF964 

	printf("%p\n", &arr); // 008FF960 
	printf("%p\n", &arr+1); //  008FF988
}
// 可以用指针来访问数组
```



##### 二级指针

```c
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa; // ppa就是二级指针

	**ppa = 20;
	printf("%d\n", **ppa);
	printf("%d\n", a);
	return 0;
}
```



<img src="C:\Users\AKANG\iCloudDrive\Windows桌面\截图\PNG图像 9.png" alt="PNG图像 9" style="zoom: 50%;" />



##### 指针数组

```c
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	// 整型数组 - 存放整型
	// 字符数组 - 存放字符
	// 指针数组 - 存放指针
	
	int* arr[3] = { &a,&b,&c };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d\n",*(arr[i]));
	}
	return 0;
}
```



## 指针-进阶

##### 字符数组

```c
int main()
{
	char arr[] = "abcef";
	char* pc = arr;
	printf("%s\n", arr); // 输出：abcdef
	printf("%s\n", pc); // 输出：abcdef
	printf("%c\n", *pc); // 输出：a
	printf("%d\n", *pc); // 输出：97
	// *pc指向的是数组的首元素 pc是数组的地址 %s的输出方式是从当前地址一直往后输出，直到出现'\0'
	return 0;

}
////////////////////////////////////////////
int main() // 输出hehe
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	char* p1 = "abcdef"; // 常量字符串，不能被修改，因此内存里面存一份就可以
	char* p2 = "abcdef";
	if (p1 == p2) 
	{
		printf("hehe");
	}
	else
	{
		printf("haha");
	}
	return 0;
}
```



#####  指针数组

```c
// 指针数组是数组，用来存放指针的
int main()
{
	/*
	int arr[10] = { 0 }; // 整型数组
	char ch[5] = { 0 }; // 字符数组
	int* parr[4]; // 存放整型指针的数组 - 指针数组
	char* pch[5]; // 存放字符指针的数组 - 指针数组

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int* arr1[4] = { &a,&b,&c,&d }; // 指针数组
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", *(arr1[i]));
	}
    */

	// 指针数组的应用
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };

	int* parr[] = { &arr1,&arr2,&arr3 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));
		}
		printf("\n");
	}
	return 0;
}
```



##### 数组指针

```c
// 数组指针是指针
int *p1[10];
int (*p2)[10];
// p1,p2分别是什么？
// 解释：[]的优先级高于*，p1先和[]结合成一个数组，因此p1是一个指针数组，数组里面存储的是整型指针
//      p2先和*组合成一个指针，指向的是一个大小为10的数组，因此是一个数组指针
//////////////////////////////////////////////////////////////////////////////////

// 数组指针
int main()
{
	int* p = NULL; // p是整型指针 - 指向整型的指针 - 可以存放整型的地址
	char* pc = NULL; // pc是字符指针 - 指向字符的指针 - 可以存放字符的地址
	// 数组指针 - 指向数组的指针 - 可以存放数组的地址
	// int arr[10] = { 0 }; // arr - 首元素地址  &arr - 数组的地址

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int (*p)[10]=&arr; // 数组的地址
	// 上面的p就是数组指针
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* arr[5];
	char* (*pa)[5] = &arr;

	int arr2[10] = { 0 };
	int(*pa2)[10] = &arr2;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////

// 遍历二维数组
// 参数是数组的形式
void print1(int arr[3][5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

// 参数是指针的形式
void print2(int (*parr)[5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", (*(parr + i))[j]); // a[j] <==> *(a+j)  
			// (*(parr+i))[j] <==> *(*(parr+i)+j)
			// *(parr + i)[j] <==> **(parr+i+j)
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print1(arr, 3, 5);
	print2(arr, 3, 5);
	return 0;
}
```

```c
// 总结整理
int arr[5]; // arr是一个5个元素的整型数组
int*parr[10]; // parr是一个数组，数组有10个元素，每个元素的类型是int*，parr是指针数组
int (*parr)[10]; // parr是一个指针，指向的类型是一个数组，数组大小是10，每个元素是int，parr是数组                  // 指针
int (*parr[10])[5]; 
// parr是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指向的数组有5个元素，每个元素是
// 一个int
```

<img src="C:\Users\AKANG\iCloudDrive\Windows桌面\截图\PNG图像 10.png" alt="PNG图像 10" style="zoom:50%;" />



##### 数组参数、指针参数

```c
// 在写代码时难免要把【数组】或者【指针】传递给函数，那函数的参数该如何设计呢？

// 一维数组传参
void test(int arr[])
{}

void test(int arr[10])
{}

void test(int* arr)
{}

void test2(int* arr[20])
{}

void test2(int **arr)
{}

int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };
	test(arr);
	test2(arr);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////

// 二维数组传参
void test(int arr[3][5])
{}

void test1(int arr[][5]) // 可以省略行，不能省略列
{}

//void test2(int** arr) // error
//{}

void test2(int(*arr)[5])
{}

int main()
{
	int arr[3][5] = { 0 };
	test(arr); // 二维数组传参
	test1(arr);
	test2(arr);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////

// 指针传参

// 一级指针传参

void print(int* p, int sz)
{
	printf("%d\n", sz);
	for (int i = 0; i < sz - 1; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]); // 数组的大小
	// 一级指针p传给函数
	print(p, sz);

	return 0;
}
```



##### 函数指针

```c
// 数组指针 - 是指向数组的指针
// 函数指针 - 是指向函数的指针 - 存放函数地址的指针

int Add(int x, int y)
{
	int z = 0;
	z = x + y;

	return z;
}

void Print(char* str)
{
	printf("%s\n",str);
}

int main()
{
	int a = 10;
	int b = 20;

	printf("%d\n", Add(a, b));

	// &函数名 和 函数名 都是函数的地址
	printf("%p\n", &Add);
	printf("%p\n", Add);

	int (*pa)(int, int) = Add; // 用指针调用函数
	printf("%d\n", (pa)(3, 3));
	printf("%d\n", (*pa)(3, 3));
	printf("%d\n", (**pa)(3, 3));
	printf("%d\n", (***pa)(3, 3));
	// 以上四种写法是一样的，一般用前两种

	void (*p)(char*) = Print;
	(*p)("abcdef");

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

int main()
{
	(*(void (*)())0)(); // 调用0处的函数
	// 强制类型转换：(type_name) expression
	// void(*)()是函数指针类型，(void (*)())0 是将0强制类型转换成函数指针类型 0就是一个函数的地址

	void (*signal(int, void(*)(int)))(int);
	// signal是一个函数声明
	// signal函数的参数有2个，第一个是int。第二个是函数指针，该函数指针指向函数的参数是int，
    // 返回类型是void,signal函数的返回类型也是一个指针：该函数指针指向的函数参数是int，
	// 返回类型是void
	
	return 0;
}

```



##### 函数指针数组

```c
// 把函数地址存在一个数组中，那这个数组就叫函数指针数组
// 函数指针数组定义方式     int (*parr[])()
// 用途：转移表

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	// 指针数组
	int* arr[5];
	int (*pa)(int, int) = Add;

	int (*parr[4])(int, int) = {Add,Sub,Mul,Div}; // 函数指针数组-转移表

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](2, 3));
	}

	char* my_strcpy(char* dest, const char* src);
	// 1.写一个函数指针pf，能够指向my_strcpy
    char* (*pf)(char*, const char*) = my_strcpy;

	// 2.写一个函数指针数组pfArr，能够存放4和my_strcpy函数地址
	char* (*pfArr[4])(char*, const char*) = {0};

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////


// 计算器
void menu()
{
	printf("**************************\n");
	printf("**  1. add      2. sub  **\n");
	printf("**  3. mul      4. div  **\n");
	printf("**  5. xor      0. exit **\n");
	printf("**************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int Xor(int x, int y)
{
	return x ^ y;
}

int main() // 函数指针数组写法，增加运算之后代码不会变长
{
	int input = 0;
	int x = 0;
	int y = 0;
	int (*parr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor};
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		if (input >= 1 && input <= 6)
		{
			printf("请输入两个操作数：");
			scanf("%d%d", &x, &y);
			int ret = parr[input](x, y);
			printf("%d\n", ret);
		}
		else if (0 == input)
		{
			printf("退出\n");
			break;
		}
		else
		{
			printf("输入错误！");
			break;
		}


	} while (input);

	return 0;
}
/*
int main() // 传统写法如果运算变多，代码会变长
{
	int input = 0;
	
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("请输入两个操作数！");
			scanf("%d%d", &x, &y);
			printf("%d\n\n", Add(x, y));
			break;
		case 2:
			printf("请输入两个操作数！");
			scanf("%d%d", &x, &y);
			printf("%d\n\n", Sub(x, y));
			break;
		case 3:
			printf("请输入两个操作数！");
			scanf("%d%d", &x, &y);
			printf("%d\n\n", Mul(x, y));
			break;
		case 4:
			printf("请输入两个操作数！");
			scanf("%d%d", &x, &y);
			printf("%d\n\n", Div(x, y));
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误！");
			break;
		}
	} while (input);

	return 0;
}
*/
```

##### 指向函数指针数组的指针

```c
// 指向函数指针数组的指针是一个 指针 指针指向一个数组，数组里面的元素都是 函数指针

int main()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr; // 取出数组的地址

	int (*pf)(int, int); // 函数指针
	int (*pfArr[4])(int, int); // pfArr是一个数组-函数指针数组
	
	// ppfArr是一个指向【函数指针数组】的指针 
	int (*(*ppfArr)[4])(int, int) = &pfArr;
	// ppfArr 是一个数组指针，指针指向的数组有4个元素
	// 指向的数组的每个元素的类型时一个函数指针 int(*)(int, int)

	return 0;
}
```



##### 回调函数

回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我么就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。

```c
void print(char* str) // print是回调函数
{
	printf("hehe:%s", str);
}

void test(void (*p)(char*))
{
	printf("test\n");
	p("bit");
}

int main()
{
	test(print);
}

////////////////////////////////////////////////////////////////////////////////////

// 计算器-利用回调函数对代码进行改进
void menu()
{
	printf("**************************\n");
	printf("**  1. add      2. sub  **\n");
	printf("**  3. mul      4. div  **\n");
	printf("**  5. xor      0. exit **\n");
	printf("**************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int Xor(int x, int y)
{
	return x ^ y;
}

void Calc(int (*pf)(int, int))
{
    int x = 0;
    int y = 0;
    printf("请输入两个操作数：");
    scanf("%d%d", &x, &y );
    printf("%d\n", pf(x, y));
}

int main() // 传统写法如果运算变多，代码会变长
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
                Calc(Add);
			break;
		case 2:
                Calc(Sub);
			break;
		case 3:
                Calc(Mul);
			break;
		case 4:
                Calc(Div);
			break;
        case 5:
                Calc(Xor);
		case 0:
			printf("退出!\n");
			break;
		default:
			printf("选择错误！");
			break;
		}
	} while (input);

	return 0;
}
```



##### 小总结

```c
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	// 指针数组
	int* arr[10];
	// 数组指针
	int* (*pa)[10] = &arr;
	// 函数指针
	int (*pAdd)(int, int) = Add;
	int sum = (*pAdd)(1, 2);
	printf("sum = %d\n", sum);
	// 函数指针的数组
	int(*pArr[5])(int, int);
	// 指向函数指针数组的指针
	int (*(*ppArr)[5])(int, int) = &pArr;

	return 0;
}
```



##### void*指针

```c
int main()
{
	int a = 10;
	int* pa = &a;

	void* p = &a;
	// void* 可以接受任何类型的地址
	// void* 类型指针不能进行解引用操作
	// void* 类型的指针不能进行加减整数的操作

	return 0;
}
```



##### 排序-冒泡 

```c
// 冒泡排序
// qsort库函数使用
// void qsort(void* base,size_t num,size_t width,int(__cdecl*compare)(const void*,const void*)); 
// 第一个参数：待排序数组的首元素地址
// 第二个参数：待排序数组的元素个数
// 第三个参数：待排序数组的每个元素的大小，单位：字节
// 第四个参数：是函数指针：比较两个元素的方法和所用函数的地址-这个函数使用者自己实现
//           函数指针的两个参数是：待比较的两个元素的地址
void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		// 一趟冒泡排序
	    // 每一趟会选出一个最大值放在最后面，因此当前趟不用和前一趟放好的值比较
		for (int j = 0; j < sz - 1 - i; j++)
		{
			int tmp = 0;
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 < *(float*)e2)
		return -1;
	else
		return 1;
}

struct Stu
{
	char name[20];
	int age;
};
int cmp_struct_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_struct_name(const void* e1, const void* e2)
{
	// 比较名字就是比较字符串
	// 字符串比较不能直接用><=来比较，应该用strcmp函数比较
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	int arr1[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	qsort(arr1, sz1, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int ssz = sizeof(s) / sizeof(s[0]);
	qsort(s, ssz, sizeof(s[0]), cmp_struct_age);
	qsort(s, ssz, sizeof(s[0]), cmp_struct_name);

    float f[] = { 2.0,3.0,9.0,1.0,5.0,7.0,6.0,8.0,0,4.0 };
	int fsz = sizeof(f) / sizeof(f[0]);
	qsort(f, fsz, sizeof(f[0]), cmp_float);
	for (int i = 0; i < fsz; i++)
	{
        printf("%f ", f[i]);
	}
	printf("\n");

	return 0;
}
```



##### MAX 排序-冒泡-qsort()实现 

```c
struct Stu
{
	char name[20];
	int age;
};

int cmp_struct_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_struct_name(const void* e1, const void* e2)
{
	// 比较名字就是比较字符串
	// 字符串比较不能直接用><=来比较，应该用strcmp函数比较
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}


int cmp_int(void* e1, void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void Swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{   // 逐个字符交换
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

// 实现bubble_sort函数的程序员不知道未来要比较的元素是什么类型
void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
{
	// 趟数
	for (int i = 0; i < sz; i++)
	{
		// 每一趟比较次数
		for (int j = 0; j < sz - 1 - i; j++)
		{
			// 两个元素比较
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				// 交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 使用bubble_sort函数的程序员一定知道自己排序的是什么数据，就应该知道怎么比较元素
	bubble_sort(arr, sz, sizeof(arr[0]),cmp_int);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}

void test2()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s)/sizeof(s[0]);
	bubble_sort(s,sz,sizeof(s[0]),cmp_struct_name);
}

int main()
{
	test1();
	test2();
	return 0;
}
```



##### 习题

```c
int main()
{
	// 一维数组
	// 
	// 数组名是首元素地址，但是有一下两个例外：
	// 1.sizeof(数组名) - 数组名表示整个数组
	// 2.&数组名 - 数组名表示整个数组 
	int a[] = { 1,2,3,4 };

	printf("整型数组\n");

	printf("%d\n", sizeof(a)); // 16 - sizeof(数组名)-计算的是数组的总大小-单位是字节 
	printf("%d\n", sizeof(a + 0)); // 4 - 数组名这里表示的是首元素的地址，a+0还是首元素的地址
	printf("%d\n", sizeof(*a)); // 4 - *a是首元素，首元素是个整型
	printf("%d\n", sizeof(a + 1)); // 4 - 数组名表示首元素地址，a+1表示第二个元素地址
	printf("%d\n", sizeof(a[1])); // 4 - 表示第二个元素的大小，还是整型
	printf("%d\n", sizeof(&a)); // 4  不管是谁的地址都是 4/8
	printf("%d\n", sizeof(*&a)); // 16 - &a表示数组地址，数组的地址解引用访问的数组，sizeof计算的是数组大小
	printf("%d\n", sizeof(&a + 1)); // 4 - 虽然跳过了一个数组，但还是一个地址
	printf("%d\n", sizeof(&a[0])); // 4 - 首元素地址
	printf("%d\n", sizeof(&a[0] + 1)); // 4 - 第二个元素地址

	// 字符数组

	char arr[] = { 'a','b','c','d','e','f' };

	printf("\n字符数组-sizeof\n");

	printf("%d\n", sizeof(arr)); // 6
	printf("%d\n", sizeof(arr + 0)); // 4
	printf("%d\n", sizeof(*arr)); // 1
	printf("%d\n", sizeof(arr[1])); // 1
	printf("%d\n", sizeof(&arr)); // 4
	printf("%d\n", sizeof(&arr + 1)); // 4
	printf("%d\n", sizeof(&arr[0] + 1)); // 4

	printf("\n字符数组-strlen\n");

	printf("%d\n", strlen(arr)); // 随机值
	printf("%d\n", strlen(arr + 0)); // 随机值
	//printf("%d\n", strlen(*arr)); // 写法错误
	//printf("%d\n", strlen(arr[1])); // 写法错误
	printf("%d\n", strlen(&arr)); // 随机值
	printf("%d\n", strlen(&arr + 1)); // 随机值-6
	printf("%d\n", strlen(&arr[0] + 1)); // 随机值-1

	return 0;
}
```



## 指针-TIPS

##### 传参

在 C 语言中，函数的参数传递方式有两种：值传递与地址传递。

###### 值传递

这种方式使用变量、常量、数组元素作为函数参数，实际是将实参的值复制到形参相应的存储单元中，即形参和实参分别占用不同的存储单元，这种传递方式称为“参数的值传递”或者“函数的传值调用”。

值传递的特点是单向传递，即主调函数调用时给形参分配存储单元，把实参的值传递给形参，在调用结束后，形参的存储单元被释放，而形参值的任何变化都不会影响到实参的值，实参的存储单元仍保留并维持数值不变。

###### 地址传递

这种方式使用数组名或者指针作为函数参数，传递的是该数组的首地址或指针的值，而形参接收到的是地址，即指向实参的存储单元，形参和实参占用相同的存储单元，这种传递方式称为“参数的地址传递”。

地址传递的特点是形参并不存在存储空间，编译系统不为形参数组分配内存。数组名或指针就是一组连续空间的首地址。因此在数组名或指针作函数参数时所进行的传送只是地址传送，形参在取得该首地址之后，与实参共同拥有一段内存空间，形参的变化也就是实参的变化。

##### 测试
