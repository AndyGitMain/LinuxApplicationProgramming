#include <stdio.h>


#define BUF_SIZE 1024

int main()
{
	int nNum;
	float fNum;
	char str[BUF_SIZE] = {""};
	char *pData;
	int ret;

	pData = "123";
	ret = sscanf(pData, "%d", &nNum);
	printf("ret = %d, nNum = %d\n", ret, nNum);

	pData = "123 123.456";
	ret = sscanf(pData, "%d %f", &nNum, &fNum);
	printf("ret = %d, nNum = %d, fNum = %f\n", ret, nNum, fNum);

	pData = "123 123.456 forum.linux.com";
	ret = sscanf(pData, "%d %f %s", &nNum, &fNum, str);
	printf("ret = %d, nNum = %d, fNum = %f, str = %s\n", ret, nNum, fNum, str);

	
	return 0;
}
