#include <stdio.h>
void print1(int *ptr, int rows);

int main() {
	printf("\n[----- [황슬비] [2018032027] -----]\n\n");

	int one[]={0, 1, 2, 3, 4}; //one이라는 배열에 1,2,3,4 대입
	printf("one[0] = %d\n", one[0]); //one[0]의 값 출력 : 0
	printf("one = %p\n", one); //one의 값 출력
	printf("&one = %p\n", &one); //one의 주소 출력
	printf("&one[0] = %p\n", &one[0]); //one[0]의 주소 출력
	//one = &one = &one[0]
	print1(&one[0], 5);
	return 0;
}
void print1(int *ptr, int rows){
	int i;
	printf("\nAddress Contents\n");
	for(i=0; i<rows; i++)
		printf("%p %5d\n", ptr+i, *(ptr+i)); //포인터가 가리키고있는 곳의 주소, 배열값 출력
	//ptr+1 = &one[0]+1=one+1
}
