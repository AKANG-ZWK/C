## 指针-初级

### 指针运算

```c
// 指针运算

int main()
{
	char ch[5] = { 'a','b','c' };
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 指针-指针得到的是指针之间元素的个数 指针相减的前提是：两指针都是值相同一片区域
	printf("%d\n", &arr[9] - &arr[0]); //输出9

}
```



## 结构体

### 结构体的声明

```c
// 结构体，声明
// 结构体的成员可以是标量、数组、指针、其他结构体等

struct Book
{
	char name[20]; // 书名
	short price; // 价格
}b4,b5,b6; // 全局变量，不建议使用

typedef struct Book
{
	char name[20]; // 书名
	short price; // 价格
}Book; // 也是创建一个类型，这块的Book指的是一个类型

int main()
{
	// 结构体类型创建结构体变量
	struct Book b1; // 创建一本书
	struct Book b2; // 创建一本书
	struct Book b3; // 创建一本书
	Book b4;

	// 字符串拷贝
	// 把“C语言”拷贝到name数组中
	strcpy(b1.name, "C语言");
	b1.price = 55;
	printf("%s %d ", b1.name, b1.price);
    
    return 0;
}
```

```c
struct C
{
	int a;
	char c;
};

struct S
{
	int a;
	char arr[20];
	int* p;
	struct C sc;
};

int main()
{
	struct C c = { 20,'w' };
	struct S s = { 100 ,"hehe",NULL,{33,'Q'} };
	printf("%d %c \n", c.a, c.c);
	printf("%d %s %p %d %c\n", s.a, s.arr, s.p, s.sc.a, s.sc.c);
}
```

### 结构体访问

```c
// 结构体访问

struct Stu
{
	char name[20];
	int age;
};

void print1(struct Stu stu) // 每次传值需要拷贝一次对象，占用内存大
{
	printf("%s %d\n", stu.name, stu.age);
}

void print2(struct Stu* ps) // 此方法传值最佳，系统开销少
{
	printf("%s %d", ps->name, ps->age);
}

int main()
{
	struct Stu s = { "张三", 20 };

	print1(s);
	print2(&s);
	return 0;
}
```

