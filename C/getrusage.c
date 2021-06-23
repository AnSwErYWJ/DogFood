/*************************************************************************
	> File Name: getrusage.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 23 Jun 2021 02:48:03 PM CST
 ************************************************************************/

#include <stdio.h>

/* include for getrusage */
#ifndef _WIN32
#include <sys/time.h>
#include <sys/resource.h>
#endif

static void print_rusage() {
#ifndef _WIN32
	int ret;

	struct rusage usage;
    ret = getrusage(RUSAGE_SELF, &usage);
	if (0 != ret) {
		printf("getrusage failed\n");
		goto end;
	}

	printf("%s: %.3fms\n", "ru_utime", (usage.ru_utime.tv_sec * 1000.0 + usage.ru_utime.tv_usec / 1000.0));
	printf("%s: %.3fms\n", "ru_stime", (usage.ru_stime.tv_sec * 1000.0 + usage.ru_stime.tv_usec / 1000.0));
	printf("%s: %.3fM\n", "ru_maxrss", (usage.ru_maxrss / 1024.0));
	printf("%s: %ld\n", "ru_ixrss", usage.ru_ixrss);
	printf("%s: %ld\n", "ru_idrss", usage.ru_idrss);
	printf("%s: %ld\n", "ru_isrss", usage.ru_isrss);
	printf("%s: %ld\n", "ru_minflt", usage.ru_minflt);
	printf("%s: %ld\n", "ru_majflt", usage.ru_majflt);
	printf("%s: %ld\n", "ru_nswap", usage.ru_nswap);
	printf("%s: %ld\n", "ru_inblock", usage.ru_inblock);
	printf("%s: %ld\n", "ru_oublock", usage.ru_oublock);
	printf("%s: %ld\n", "ru_msgsnd", usage.ru_msgsnd);
	printf("%s: %ld\n", "ru_msgrcv", usage.ru_msgrcv);
	printf("%s: %ld\n", "ru_nsignals", usage.ru_nsignals);
	printf("%s: %ld\n", "ru_nvcsw", usage.ru_nvcsw);
	printf("%s: %ld\n", "ru_nivcsw", usage.ru_nivcsw);

#endif

end:
	return;
}

int main(void) {

	print_rusage();

	return 0;
}