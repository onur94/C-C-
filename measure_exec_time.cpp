#include <iostream>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

struct timeval diff, start, finish;

int main()
{
	gettimeofday(&start, NULL);

	sleep(1);

	gettimeofday(&finish, NULL);
	diff.tv_sec = finish.tv_sec - start.tv_sec;
	diff.tv_usec = finish.tv_usec - start.tv_usec;
	cout << "Time taken: " << diff.tv_sec*1000000 + diff.tv_usec << "us" << endl;

	return 0;
}
