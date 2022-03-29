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