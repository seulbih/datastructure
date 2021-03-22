#include <stdio.h>

struct student1{ //구조체 선언
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
	printf("\n[----- [황슬비] [2018032027] -----]\n\n");

	struct student1 st1 = {'A', 100, 'A'};
	//구조체 선언, 앞에서 typedef안써서 선언하면서 struct명시해줌
	//lastName='A', studentId=100, grade='A' 대입

	printf("st1.lastName = %c\n", st1.lastName);
	printf("st1.studentId = %d\n",st1.studentId);
	printf("st1.grade = %c\n\n",st1.grade);


	student2 st2 = {'B', 200, 'B'};
	//구조체 선언, 앞에서 typedef써서 선언하면서 struct명시하지 않아도 됨.
	//lastName='A', studentId=100, grade='A' 대입
	printf("st2.lastName = %c\n",st2.lastName);
	printf("st2.studentId = %d\n",st2.studentId);
	printf("st2.grade = %c\n\n",st2.grade);

	student2 st3;

	st3=st2; //구조치환, st3에 st2의 정보 넣음

	printf("st3.lastName = %c\n",st3.lastName);
	printf("st3.studentId = %d\n",st3.studentId);
	printf("st3.grade = %c\n",st3.grade);



	 if(st3==st2) //전체구조체의 동등성검사 불가능, 구조체 내 멤버들끼리 비교해야함.
		 printf("equal\n");
	 else
		 printf("not equal\n");


	return 0;
}
