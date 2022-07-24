#include "so_long.h"
#include <signal.h>
#include <time.h>

int main(void)
{
	printf("time = %d\n", (unsigned int)time(NULL));
}