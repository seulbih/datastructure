#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
float sum(float list[], int n);
float input[MAX_SIZE], answer;

void main(void) {
	printf("[----- [황슬비] [2018032027] -----]\n\n");
	int i;
	for(i=0; i<MAX_SIZE; i++)
		input[i]=i; //각 인덱스에 해당하는 값 0~99까지 대입
	answer = sum(input, MAX_SIZE); //sum 함수에 for문에서 만든 리스트와 전역변수 MAX_SIZE 대입
	printf("The sum is : %f\n", answer);
}

float sum(float list[], int n){
	int i;
	float tempsum = 0; //초기화
	for(i=0;i<n;i++)
		tempsum += list[i]; //list[0]부터 list[n-1]까지 모두 더하기(1~99)
	return tempsum;
}
