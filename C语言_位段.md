#### 位段

```c
// 位段

struct A
{
	// 以4字节位单位开辟空间，然后分配给下面的变量，不够了再开辟4个字节再分配
	int _a : 2; // 后面的2指的是bit位
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

int main()
{
	printf("%d\n", sizeof(struct A));

	return 0;
}
```

##### 内存开辟方式

```c
struct S
{
	char _a : 3; 
	// 先开辟一个字节 _a需要3个bit位  00000  000   剩5个
	char _b : 4;
	// _b需要4个bit位 0 0000 000   剩1个 
	char _c : 5;
	// _c需要5个，不够了，上面剩的字节浪费掉，再开辟一个字节 000 00000 剩3个
	char _d : 4;
	// _d需要4个，不够了，上面剩的字节浪费掉，再开辟一个字节 0000 0000 剩4个
	
	// 一共开辟了3个字节
};

int main()
{
	struct S s = { 0 };
	s._a = 10;
	s._b = 12;
	s._c = 3;
	s._d = 4;
	printf("%d", sizeof(struct S));
	
	return 0;
}
```

<img src="C:\Users\AKANG\AppData\Roaming\Typora\typora-user-images\image-20220428121849320.png" alt="image-20220428121849320" style="zoom: 40%;" />

**位段虽然比结构体节省空间，但使用规则并不明确，不具备跨平台性，使用起来需要很谨慎，最好别用位段。**

##### 位段的应用——网络传输协议

![image-20220428123335705](C:\Users\AKANG\AppData\Roaming\Typora\typora-user-images\image-20220428123335705.png)
