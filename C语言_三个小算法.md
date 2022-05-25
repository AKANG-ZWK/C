### 联合体、大小端

```c
// 涉及到大小端、数组的存储方式
int main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;
	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;
	printf("%x\n", a.k);

	return 0;
}
```

### 输出字符串中数字的值

```c
// 将字符串中的数字的值输出

enum State
{
	VALID,
    INVALID

}state = INVALID;

int my_atoi(const char* str)
{
	int flag = 1;
	state = INVALID;

	// 判断是否为空指针
	if (str == NULL)
		return 0; 
	// 判断是否是空字符串
	if (*str == '\0')
		return 0;

	// 空白字符处理
	while (isspace(*str))
	{
		str++;
	}
	// 判断正负号
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}

	// 正常数字处理
	long long ret = 0;
	while (*str)
	{
		if (isdigit(*str) == 0)
		{
			break;
		}
		else
		{
			ret = ret * 10 + flag * (*str - '0');
			if (ret > INT_MAX || ret < INT_MIN)
			{
				ret = 0;
				return (int)ret;
			}
			str++;
		}
	}
	if (*str == '\0')
	{
		state = VALID;
		return (int)ret;
	}

	return (int)ret;
}

int main()
{
	char* p = "012345";
	int ret = my_atoi(p);
	if (state == VALID)
	{
		printf("%d\n", ret);
	}

	return 0;
}
```
