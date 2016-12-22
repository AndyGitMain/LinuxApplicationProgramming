


#include <stdio.h>
#include <time.h>


void getTime(time_t *mytime);

int main()
{
	time_t mytime;
	strucqt tm *mytm;	

	getTime(&mytime);

	printf("%s\n", ctime(&mytime));

	mytm = localtime(&mytime);

	printf("Year : %d\n", 1900 + mytm->tm_year);
	printf("Month: %d\n", 1 + mytm->tm_mon);
	printf("Day  : %d\n", mytm->tm_mday);
	printf("DST  : %d\n", mytm->tm_isdst);
	return 0;
}


void getTime(time_t *mytime)
{
	*mytime = time(NULL);
}
