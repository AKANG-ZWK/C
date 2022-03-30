- 判断一个数是不是自幂数

  ```c
  // 判断一个数是不是自幂数
  
  int main()
  {
  	int i = 0;
  
  	for (i = 0; i <= 100000; i++)
  	{
  		// 判断i是不是自幂数
  		// 1.计算i的位数
  		int tmp = i;
  		int count = 1;
  		int sum = 0;
  		while (tmp /= 10)
  		{
  			count++;
  		}
  		// 2.获得i的每一位，计算每一位的n次方之和
  		tmp = i;
  		while (tmp)
  		{
  			sum += pow(tmp % 10, count);
  			tmp /= 10;
  		}
  		// 3.比较打印
  		if (i == sum)
  		{
  			printf("%d ", i);
  		}
  	}
  
  	return 0;
  }
  ```