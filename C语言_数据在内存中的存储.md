# C语言_进阶

## 数据在内存中的存储

### 基本的数据类型

#### 整型家族

- char     一般情况下定义一个char，是否是有符号的，取决于编译器
  - unsigned char
  - signed char
- short    短整型，int可以省略，一般情况下定义一个short，是有符号的
  - unsigned short [int]  
  - signed short [int]
- int
  - unsigned int
  - signed int
- long    长整型，int可以省略，一般情况下定义一个long，是有符号的
  - unsigned long [int]
  - signed long [int]  

#### 浮点数家族

- float   单精度浮点数
- double   双精度浮点数

#### 构造类型

```c
> 数组类型
> 结构体类型 struct
> 枚举类型 enum
> 联合类型 union  
```

#### 指针类型

```c
int *pi;
char *pc;
float* pf;
void* pv;  
```

#### 空类型

- void 表示空类型（无类型）
- 通常应用于函数的返回类型、函数的参数、指针类型  

### 数据在内存中的存储

> C语言中，数据以二进制存储在内存中，VS编译器为了方便，以十六进制展示数据

> 原码 - 有符号数，直接根据正负直观地写出二进制序列
>
> 反码 - 原码的符号位不变，其他为按位取反  
>
> 补码 - 反码的二进制的最低位+1
>
> **注意：正数就是正数，不存在反码和补码，反码补码的概念提出是为了解决减法问题的**

### 类型的范围

- char   [-128,127]  1000 0000表示-128
- unsigned char   [0,255]

- ......
