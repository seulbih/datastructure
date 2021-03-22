#include <stdio.h>

struct student{ //구조체 선언
	char lastName[13]; //13bytes
	int studentId; //4bytes
	short grade; //2bytes
};
 // 총 19bytes
int main() {
	printf("\n[----- [황슬비] [2018032027] -----]\n\n");

	struct student pst;
	printf("size of student = %ld\n", sizeof(struct student)); //24bytes 출력
	//4bytes단위로 메모리 확보, lastName[13] => 13bytes 차지, 남은 3bytes padding
	//studentId = int형으로 4bytes차지, padding X
	//grade = short형으로 2byte차지, 남은 2bytes padding
	//총 5bytes padding => 19bytes + 5bytes = 24bytes
	printf("size of int = %ld\n", sizeof(int));
	printf("size of short = %ld\n", sizeof(short));

	return 0;
}
