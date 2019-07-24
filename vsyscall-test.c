#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int
vsyscall_gettimeofday (struct timeval *tv, struct timezone *tz)
{
  __asm__ ("movq %0, %%rax\n"
	   "callq *%%rax"
	   : : "i" (0xffffffffff600000) : "%rax");
}

int
main (void)
{
  struct timeval tv;
  struct timezone tz;
  vsyscall_gettimeofday (&tv, &tz);
  printf ("The current time is: %ld.%6ld\n", tv.tv_sec, tv.tv_usec);
  return 0;
}
