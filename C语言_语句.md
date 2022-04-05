## 分支语句和循环语句

### 分支语句

```c
// 一个坑。。。

int main()
{
	// 悬空else 代码没有对齐，所以会有迷惑作用

	int a = 0;
	int b = 2;

	if (a == 1)
		if (b == 2)
			printf("hehe\n");
	else
		printf("haha\n");

	return 0;
}
```



### while循环中的continue和break

```c
int main()
{
	int i = 1;
	while (i<=10)
	{
		if (5 == i)
		{
			break; // i = 5时，break直接终止while循环
            // continue; // i = 5时，continue会跳过后面的代码，进入while条件判断处，i不会增加，因此程序永远死在这块。
		}
		printf("%d ", i);
		i++;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
    // 处理缓冲区多余字符
	while (getchar() != '\n')
	{
		;
	}
```

> **总结: continue在while循环中的作用就是：**
> continue是用于终止本次循环的，也就是本次循环中continue后边的代码不会再执行，而是直接
> 跳转到while语句的判断部分。进行下一次循环的入口判断  

> **总结： break在while循环中的作用：**
> 其实在循环中只要遇到break，就停止后期的所有的循环，直接终止循环。 所以：while中的
> break是用于永久终止循环的  

