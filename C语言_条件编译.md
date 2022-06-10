#### 条件编译

有条件的编译代码

```c
#define zhangsan 0

int main()
{
#if defined(zhangsan)
	printf("zhangsan\n");
#endif

#if !defined(zhangsan)
	printf("zhangsan\n");
#endif


#ifdef zhangsan
	printf("zhangsan\n");
#endif

#ifndef zhangsan
	printf("zhangsan\n");
#endif

	return 0;
}
```

#### 头文件包含

1. #include<stdio.h>

尖括号从标准库位置开始寻找头文件，找不到就报错

   2.#include " "

双引号索引优先从源文件位置寻找，找不到去标准位置找，再找不到就报错

#### 避免重复包含头文件

```c
// 方式1

#ifndef __TESTH__
#define __TESTH__

// 头文件内容

#endif
—————————————————————————————————————————————————————————————————————————————————————————
// 方式2
#pragma once
// 头文件内容
```

#### offsetof宏

```c
// offsetof(类型名，成员名) - 结构体成员距离0位置的偏移量

struct S 
{
	char name[20]; // 0-19
	int age; // 20-23
	char sex; // 24 目前内存使用了0-24 共25，最大对齐数为4，所以总内存为28
};

#define Offsetof(sn, mn) (int)&(((sn*)0)->mn)
int main()
{
	printf("%d ", offsetof(struct S, name));
	printf("%d ", offsetof(struct S, age));
	printf("%d ", offsetof(struct S, sex));
	printf("%d", sizeof(struct S));
	printf("\n");

	// 自己定义宏Offsetoff
	printf("%d ", Offsetof(struct S, name));
	printf("%d ", Offsetof(struct S, age));
	printf("%d ", Offsetof(struct S, sex));
	printf("%d", sizeof(struct S));

	return 0;
}
```

```c
// 关于计算结构体成员地址偏移字节数的宏的写法来源

struct S
{
	char name[20];
	int age;
	char sex;
};

int main()
{
	// 将0地址强制转换为struct S*类型，然后访问age成员，其实就是在0地址的基础上再加上age的地址偏移，转换成int就是偏移字节数
	printf("%p\n", (struct S*)0);
	printf("%p\n", &(((struct S*)0)->age));

    return 0;
}
```
