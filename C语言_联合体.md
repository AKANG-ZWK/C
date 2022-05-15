### 联合体/共用体

```c
// 联合体/共用体  -  里面的成员同一时间我们只能用一个

union Un
{
	char c; // 4
	int i; // 1
};

union U
{
	// 也是需要对齐的
	short s[7]; // 14
	int i; // 4
};

int main()
{
	union Un u = { 0 };
	printf("%d\n", sizeof(u));
	printf("%p\n", &u);
	printf("%p\n", &(u.c));
	printf("%p\n", &(u.i));
	printf("%d\n", sizeof(U));
	return 0;
}
```
