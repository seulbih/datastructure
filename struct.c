#include <stdio.h>

struct student1{ //����ü ����
	char lastName;
	int studentId;
	char grade;
};
typedef struct{
	char lastName;
	int studentId;
	char grade;
} student2;

int main() {
	printf("\n[----- [Ȳ����] [2018032027] -----]\n\n");

	struct student1 st1 = {'A', 100, 'A'};
	//����ü ����, �տ��� typedef�ȽἭ �����ϸ鼭 struct�������
	//lastName='A', studentId=100, grade='A' ����

	printf("st1.lastName = %c\n", st1.lastName);
	printf("st1.studentId = %d\n",st1.studentId);
	printf("st1.grade = %c\n\n",st1.grade);


	student2 st2 = {'B', 200, 'B'};
	//����ü ����, �տ��� typedef�Ἥ �����ϸ鼭 struct������� �ʾƵ� ��.
	//lastName='A', studentId=100, grade='A' ����
	printf("st2.lastName = %c\n",st2.lastName);
	printf("st2.studentId = %d\n",st2.studentId);
	printf("st2.grade = %c\n\n",st2.grade);

	student2 st3;

	st3=st2; //����ġȯ, st3�� st2�� ���� ����

	printf("st3.lastName = %c\n",st3.lastName);
	printf("st3.studentId = %d\n",st3.studentId);
	printf("st3.grade = %c\n",st3.grade);



	 if(st3==st2) //��ü����ü�� ����˻� �Ұ���, ����ü �� ����鳢�� ���ؾ���.
		 printf("equal\n");
	 else
		 printf("not equal\n");


	return 0;
}
