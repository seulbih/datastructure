
#include <stdio.h>
#include <stdlib.h>

void main() {
	printf("[----- [황슬비] [2018032027] -----]\n\n");
	int list[5]; //int형 배열 선언
	int *plist[5];//int형 포인트 배열 선언

	list[0] = 10;
	list[1] = 11;

	plist[0] = (int*)malloc(sizeof(int));

	printf("list[0] = %d\n", list[0]); //list[0]의 값 출력 : 10
	printf("address of list = %p\n", list); //list 값 출력 (=list주소)
	printf("address of list[0] = %p\n", &list[0]); //list[0]의 주소 출력
	printf("address of list+0 = %p\n", list+0); //list +0값 출력(=list[0]의 주소)

	printf("address of list+1 = %p\n", list+1); //list+1 값 출력(=list[1]의 주소)
	printf("address of list+2 = %p\n", list+2); //list+2값 출력(=list[2]의 주소)
	printf("address of list+3 = %p\n", list+3); //list+3 값 출력(=list[3]의 주소)
	printf("address of list+4 = %p\n", list+4); //list+4 값 출력(=list[4]의 주소)
	printf("address of list[4] = %p\n", &list[4]); //list[4]의 주소 출력


	free(plist[0]);
}
