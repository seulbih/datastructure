#include <stdio.h>

struct student{ //����ü ����
	char lastName[13]; //13bytes
	int studentId; //4bytes
	short grade; //2bytes
};
 // �� 19bytes
int main() {
	printf("\n[----- [Ȳ����] [2018032027] -----]\n\n");

	struct student pst;
	printf("size of student = %ld\n", sizeof(struct student)); //24bytes ���
	//4bytes������ �޸� Ȯ��, lastName[13] => 13bytes ����, ���� 3bytes padding
	//studentId = int������ 4bytes����, padding X
	//grade = short������ 2byte����, ���� 2bytes padding
	//�� 5bytes padding => 19bytes + 5bytes = 24bytes
	printf("size of int = %ld\n", sizeof(int));
	printf("size of short = %ld\n", sizeof(short));

	return 0;
}
