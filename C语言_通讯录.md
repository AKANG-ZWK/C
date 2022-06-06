### 通讯录

```c
#define _CRT_SECURE_NO_WARNINGS 1

// 头文件 类型声明 函数声明

#include <stdio.h>
#include <string.h>


#define MAX 1000

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 12
#define MAX_QQ 12
#define MAX_SEX 12


// 人 
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

// 通讯录
typedef struct contact
{
	PeoInfo data[MAX];
	int sz; // 通讯录中的有效人数
}Contact;

// 添加一个人信息
void add_contact(Contact* pc);

// 显示通讯录中的信息
void show_contact(Contact* pc);

// 删除指定的联系人
void del_contact(Contact* pc);

// 查找指定联系人
void search_contact(Contact* pc);

// 修改指定联系人
void modify_contact(Contact* pc);

// 按照姓名对联系人排序

void sort_contact(Contact* pc);
```

```c
#include "contact.h"

void add_contact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("\n通讯录已满！\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->sz].name);

		printf("请输入电话:>");
		scanf("%s", pc->data[pc->sz].tele);

		printf("请输入地址:>");
		scanf("%s", pc->data[pc->sz].addr);

		printf("请输入QQ:>");
		scanf("%s", pc->data[pc->sz].qq);

		printf("请输入性别:>");
		scanf("%s", pc->data[pc->sz].sex);

		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pc->sz].age));

		pc->sz++;
		printf("\n添加成功\n");
	}
}

void show_contact(Contact* pc)
{
	printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "QQ", "性别");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[i].name, 
			pc->data[i].tele,
			pc->data[i].addr, 
			pc->data[i].age, 
			pc->data[i].qq, 
			pc->data[i].sex );
	}
}

static int find_peo_by_name(Contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i; // 找到了，返回下标
		}
	}
	return -1; // 找不到
}

void del_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入名字:>");
	scanf("%s", name);

	if (pc->sz == 0)
	{
		printf("\n抱歉，通讯录为空\n");
	}
	else
	{
		// 1.找到指定联系人的位置
		int pos = find_peo_by_name(pc, name);
		if (pos == -1)
		{
			printf("\n删除的人不在通讯录中\n");
		}
		else
		{
			// 2.删除
			// 注意：删除最后一项时这块并不会进入下面的循环，而是直接给数组大小-1，我们就看不到最后一项了
			// 除了最后一项，删除其它项时，依次用后面的项覆盖他
			for (int j = pos; j < pc->sz - 1; j++) 
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("\n删除成功\n");
		}
	}
}

void search_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);

	int pos = find_peo_by_name(pc, name);

	if (pos == -1)
	{
		printf("\n查无此人！\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "QQ", "性别");
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}

void modify_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("\n请输入要修改人的名字:>");
	scanf("%s", name);

	int pos = find_peo_by_name(pc, name);

	if (pos == -1)
	{
		printf("\n查无此人！\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);

		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);

		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("请输入新的QQ:>");
		scanf("%s", pc->data[pos].qq);

		printf("请输入新性别:>");
		scanf("%s", pc->data[pos].sex);

		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));

		printf("\n修改成功\n");
	}
}

void sort_contact(Contact* pc)
{
	for (int i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1; // 1表示假设已经有序
		for (int j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}
```

```c
#include "contact.h"

void menu()
{
	printf("\n*******************************************\n");
	printf("********  1. add       2. del     *********\n");
	printf("********  3. search    4. modify  *********\n");
	printf("********  5. sort      6. show    *********\n");
	printf("********         0. exit          *********\n");
	printf("*******************************************\n");

}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

void test()
{
	Contact con = {0};
	
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case EXIT:
			printf("退出通讯录！\n");
			exit(0);
		default :
			printf("选择错误！\n");
			break;
		}

	} while (input);
}

int main()
{
	test();

	return 0;
}
```

### 动态开辟内存的通讯录

```c
#define _CRT_SECURE_NO_WARNINGS 1

// 头文件 类型声明 函数声明

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_MAX 3 // 通讯录默认容量
#define INC 2  // 默认容量增长因子

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 12
#define MAX_QQ 12
#define MAX_SEX 12


// 人 
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

// 通讯录
typedef struct contact
{
	PeoInfo* data;
	int sz; // 通讯录中的有效人数
	int capacity; // 通讯录当前容量
}Contact;

// 初始化通讯录
void init_contact(Contact* pc);

// 添加一个人信息
void add_contact(Contact* pc);

// 显示通讯录中的信息
void show_contact(Contact* pc);

// 删除指定的联系人
void del_contact(Contact* pc);

// 查找指定联系人
void search_contact(Contact* pc);

// 修改指定联系人
void modify_contact(Contact* pc);

// 按照姓名对联系人排序
void sort_contact(Contact* pc);

// 销毁通讯录
void destroy_contact(Contact* pc);
```

```c
#include "contact.h"

void init_contact(Contact* pc)
{
	pc->sz = 0;
	pc->capacity = DEFAULT_MAX;
	pc->data = (PeoInfo*)malloc(DEFAULT_MAX * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("init_contact::malloc");
		return;
	}
}


void add_contact(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		// 增加通讯录容量
		PeoInfo* ptr = realloc(pc->data, (pc->capacity + INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC;
			printf("增容成功！\n");
		}
		else
		{
			perror("add_contact::realloc");
			return;
		}
	}

	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);

	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);

	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	printf("请输入QQ:>");
	scanf("%s", pc->data[pc->sz].qq);

	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);

	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));

	pc->sz++;
	printf("\n添加成功\n");

}

void show_contact(Contact* pc)
{
	printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "QQ", "性别");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[i].name, 
			pc->data[i].tele,
			pc->data[i].addr, 
			pc->data[i].age, 
			pc->data[i].qq, 
			pc->data[i].sex );
	}
}

static int find_peo_by_name(Contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i; // 找到了，返回下标
		}
	}
	return -1; // 找不到
}

void del_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入名字:>");
	scanf("%s", name);

	if (pc->sz == 0)
	{
		printf("\n抱歉，通讯录为空\n");
	}
	else
	{
		// 1.找到指定联系人的位置
		int pos = find_peo_by_name(pc, name);
		if (pos == -1)
		{
			printf("\n删除的人不在通讯录中\n");
		}
		else
		{
			// 2.删除
			// 注意：删除最后一项时这块并不会进入下面的循环，而是直接给数组大小-1，我们就看不到最后一项了
			// 除了最后一项，删除其它项时，依次用后面的项覆盖他
			for (int j = pos; j < pc->sz - 1; j++) 
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("\n删除成功\n");
		}
	}
}

void search_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);

	int pos = find_peo_by_name(pc, name);

	if (pos == -1)
	{
		printf("\n查无此人！\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "QQ", "性别");
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}

void modify_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("\n请输入要修改人的名字:>");
	scanf("%s", name);

	int pos = find_peo_by_name(pc, name);

	if (pos == -1)
	{
		printf("\n查无此人！\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);

		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);

		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("请输入新的QQ:>");
		scanf("%s", pc->data[pos].qq);

		printf("请输入新性别:>");
		scanf("%s", pc->data[pos].sex);

		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));

		printf("\n修改成功\n");
	}
}

void sort_contact(Contact* pc)
{
	for (int i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1; // 1表示假设已经有序
		for (int j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}

void destroy_contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
```

```c
#include "contact.h"

void menu()
{
	printf("\n*******************************************\n");
	printf("********  1. add       2. del     *********\n");
	printf("********  3. search    4. modify  *********\n");
	printf("********  5. sort      6. show    *********\n");
	printf("********         0. exit          *********\n");
	printf("*******************************************\n");

}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

void test()
{
	Contact con = {0};
	
	// 初始化通讯录
	init_contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			destroy_contact(&con);
			sort_contact(&con);
			break;
		case EXIT:
			printf("退出通讯录！\n");
			exit(0);
		default :
			printf("选择错误！\n");
			break;
		}

	} while (input);
}

int main()
{
	test();

	return 0;
}
```

### 存储在文件中的通讯录

```c
#define _CRT_SECURE_NO_WARNINGS 1

// 头文件 类型声明 函数声明

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_MAX 3 // 通讯录默认容量
#define INC 2  // 默认容量增长因子

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 12
#define MAX_QQ 12
#define MAX_SEX 12


// 人 
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

// 通讯录
typedef struct contact
{
	PeoInfo* data;
	int sz; // 通讯录中的有效人数
	int capacity; // 通讯录当前容量
}Contact;

// 增容函数
void check_capacity(Contact* pc);

// 初始化通讯录
void init_contact(Contact* pc);

// 添加一个人信息
void add_contact(Contact* pc);

// 显示通讯录中的信息
void show_contact(Contact* pc);

// 删除指定的联系人
void del_contact(Contact* pc);

// 查找指定联系人
void search_contact(Contact* pc);

// 修改指定联系人
void modify_contact(Contact* pc);

// 按照姓名对联系人排序
void sort_contact(Contact* pc);

// 销毁通讯录
void destroy_contact(Contact* pc);

// 保存通讯录到文件
void save_contact(Contact* pc);

// 加载文件中的数据
void load_contact(Contact* pc);
```

```c
#include "contact.h"

void check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		// 增加通讯录容量
		PeoInfo* ptr = realloc(pc->data, (pc->capacity + INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC;
			printf("增容成功！\n");
		}
		else
		{
			perror("add_contact::realloc");
			return;
		}
	}
}

void load_contact(Contact* pc)
{
	PeoInfo tmp = { 0 }; // 临时空间

	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		perror("open file for reading");
		return 1;
	}
	// 加载数据
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		check_capacity(pc); // 检查容量够不够，不够的话增加
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	fclose(pfRead);
	pfRead = NULL;

}

void init_contact(Contact* pc)
{
	// 开辟空间
	pc->sz = 0;
	pc->capacity = DEFAULT_MAX;
	pc->data = (PeoInfo*)malloc(DEFAULT_MAX * sizeof(PeoInfo));
	if (pc->data == NULL )
	{
		perror("init_contact::malloc");
		return;
	}
	// 加载数据
	load_contact(pc);
}


void add_contact(Contact* pc)
{
	check_capacity(pc); // 检查容量够不够，不够的话增加容量

	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);

	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);

	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	printf("请输入QQ:>");
	scanf("%s", pc->data[pc->sz].qq);

	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);

	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));

	pc->sz++;
	printf("\n添加成功\n");

}

void show_contact(Contact* pc)
{
	printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "QQ", "性别");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[i].name, 
			pc->data[i].tele,
			pc->data[i].addr, 
			pc->data[i].age, 
			pc->data[i].qq, 
			pc->data[i].sex );
	}
}

static int find_peo_by_name(Contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i; // 找到了，返回下标
		}
	}
	return -1; // 找不到
}

void del_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入名字:>");
	scanf("%s", name);

	if (pc->sz == 0)
	{
		printf("\n抱歉，通讯录为空\n");
	}
	else
	{
		// 1.找到指定联系人的位置
		int pos = find_peo_by_name(pc, name);
		if (pos == -1)
		{
			printf("\n删除的人不在通讯录中\n");
		}
		else
		{
			// 2.删除
			// 注意：删除最后一项时这块并不会进入下面的循环，而是直接给数组大小-1，我们就看不到最后一项了
			// 除了最后一项，删除其它项时，依次用后面的项覆盖他
			for (int j = pos; j < pc->sz - 1; j++) 
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("\n删除成功\n");
		}
	}
}

void search_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);

	int pos = find_peo_by_name(pc, name);

	if (pos == -1)
	{
		printf("\n查无此人！\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "QQ", "性别");
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}

void modify_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("\n请输入要修改人的名字:>");
	scanf("%s", name);

	int pos = find_peo_by_name(pc, name);

	if (pos == -1)
	{
		printf("\n查无此人！\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);

		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);

		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("请输入新的QQ:>");
		scanf("%s", pc->data[pos].qq);

		printf("请输入新性别:>");
		scanf("%s", pc->data[pos].sex);

		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));

		printf("\n修改成功\n");
	}
}

void sort_contact(Contact* pc)
{
	for (int i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1; // 1表示假设已经有序
		for (int j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}

void destroy_contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void save_contact(Contact* pc)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		perror("open file for writing");
		return 1;
	}
	// 写数据
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;

}
```

```c
#include "contact.h"

void menu()
{
	printf("\n*******************************************\n");
	printf("********  1. add       2. del     *********\n");
	printf("********  3. search    4. modify  *********\n");
	printf("********  5. sort      6. show    *********\n");
	printf("********         0. exit          *********\n");
	printf("*******************************************\n");

}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

void test()
{
	Contact con = {0};
	
	// 初始化通讯录
	init_contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case EXIT:
			save_contact(&con);
			destroy_contact(&con);
			printf("退出通讯录！\n");
			exit(0);
		default :
			printf("选择错误！\n");
			break;
		}

	} while (input);
}

int main()
{
	test();

	return 0;
}
```
