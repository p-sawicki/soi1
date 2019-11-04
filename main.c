#include "stdio.h"
#include "stdlib.h"
#include "/usr/include/lib.h"
#include "/usr/include/minix/type.h"
int getprocnr( int id){
	int ret = 0;
	message m;
	m.m1_i1 = id;
	ret = _syscall(MM, GETPROCNR, &m);
	return ret;
}
int main(int argc, char *argv[]){
	int i = 0;
	int j = 0;
	int ret = 0;
	if(argc < 2)
		return 1;
	i = atoi(argv[1]);
	for(j = i; j < i + 11; ++j){
		ret = getprocnr(j);
		if(ret < 0)
			printf("PID %d not found, error %d\n", j, ret);
		else
			printf("PID %d indexed at %d\n", j, ret);
	}
}
