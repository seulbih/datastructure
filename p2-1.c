#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
float sum(float list[], int n);
float input[MAX_SIZE], answer;

void main(void) {
	printf("[----- [Ȳ����] [2018032027] -----]\n\n");
	int i;
	for(i=0; i<MAX_SIZE; i++)
		input[i]=i; //�� �ε����� �ش��ϴ� �� 0~99���� ����
	answer = sum(input, MAX_SIZE); //sum �Լ��� for������ ���� ����Ʈ�� �������� MAX_SIZE ����
	printf("The sum is : %f\n", answer);
}

float sum(float list[], int n){
	int i;
	float tempsum = 0; //�ʱ�ȭ
	for(i=0;i<n;i++)
		tempsum += list[i]; //list[0]���� list[n-1]���� ��� ���ϱ�(1~99)
	return tempsum;
}
