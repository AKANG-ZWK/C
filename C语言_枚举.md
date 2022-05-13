### 枚举

```c
// 枚举类型
// 枚举类型里面的常量，就跟数字一样，但是也是需要初值的，默认是0开始，数值大小依次递增，也可以给它赋初值
// 枚举里面的成员名习惯上用大写，程序员之间的约定
enum Color
{
	RED = 10, // 默认情况下后面的值会依次递增1，自己赋值的话就另说了
	GREEN = 4,
	BULE = 3
};

enum Sex
{
	MALE,
	FEMAKE,
	SECRET
};

int main()
{
	enum Color c = RED;

	printf("%d\n", RED);
	printf("%d\n", GREEN);
	printf("%d\n", BULE);

	return 0;
}
```

### 枚举的应用

```c
// 枚举类型的应用
// 简单举个例子，代码没有写完
void menu()
{
	printf("********************************************\n");
	printf("***********    1 Add    2 Sub    ***********\n");
	printf("***********    3 Mul    4 Div    ***********\n");
	printf("***********        0 Exit        ***********\n");
	printf("********************************************\n");

}

enum Option
{
	Exit,
	Add,
	Sub,
	Mul,
	Div
};

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", input);

		// 枚举变量的好处就体现在下面的代码中，会让代码看起来更直观
		switch (input)
		{
		case Exit:
			exit(0);
		case Add:
			break;
		case Sub:
			break;
		case Mul:
			break;
		case Div:
			break;
		default:
			break;
		}
	} while (input);

	return 0;
}
```
