
#include <stdio.h>
/* add_by_szx: c++中使用的显示类型转换reinterpret_cast */
int main(int argc, char **argv)
{
	double d = 100.1;
	int i = d;  // double转为int
	char *str = "100ask.taobao.com";
	int *p = reinterpret_cast<int *>(str); // char *转为int * 

	printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>(str), reinterpret_cast<unsigned int>(p));

	return 0;
}

