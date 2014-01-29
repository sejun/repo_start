#include <stdio.h>
#include <signal.h>

void catchint(int signo)
{
	printf("\ncatchint:returning\n");
}

void main()
{
	static struct sigaction act;

	// catchint를 선언한다. 후에 핸들러로 사용된다.
	void catchint(int);

	// SIGINT를 수신했을 때 취해질 행동을 지정한다.
	act.sa_handler = catchint;

	// 완전히 찬 마스크를 하나 생성한다.
	sigfillset(&(act.sa_mask));

	sigaction(SIGINT, &act, NULL);

	printf("sleep call #1\n");
	sleep(1);
	printf("sleep call #2\n");
	sleep(1);
	printf("sleep call #3\n");
	sleep(1);
	printf("sleep call #4\n");
	sleep(1);

}

