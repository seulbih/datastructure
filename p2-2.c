#include <stdio.h>
void print1(int *ptr, int rows);

int main() {
	printf("\n[----- [Ȳ����] [2018032027] -----]\n\n");

	int one[]={0, 1, 2, 3, 4}; //one�̶�� �迭�� 1,2,3,4 ����
	printf("one[0] = %d\n", one[0]); //one[0]�� �� ��� : 0
	printf("one = %p\n", one); //one�� �� ���
	printf("&one = %p\n", &one); //one�� �ּ� ���
	printf("&one[0] = %p\n", &one[0]); //one[0]�� �ּ� ���
	//one = &one = &one[0]
	print1(&one[0], 5);
	return 0;
}
void print1(int *ptr, int rows){
	int i;
	printf("\nAddress Contents\n");
	for(i=0; i<rows; i++)
		printf("%p %5d\n", ptr+i, *(ptr+i)); //�����Ͱ� ����Ű���ִ� ���� �ּ�, �迭�� ���
	//ptr+1 = &one[0]+1=one+1
}
