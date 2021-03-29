#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    setvbuf(stdout, NULL, _IONBF, 0); // Windows �� Eclipse�� Console â ���� �� ������ ���� ����
    setvbuf(stderr, NULL, _IONBF, 0);

    printf("[----- [Ȳ����]  [2018032027] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : "); //��� �� ���� �Է�
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col); //��� ����
    int** matrix_b = create_matrix(row, col); //��� ����
    int** matrix_a_t = create_matrix(col, row); //��� ����

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;} //��� ���� ����

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col) //2�����迭 ����, ���������� �̿�
{
	/* check pre conditions */
	if(row <= 0 || col <=0) { //��� ���� ũ�� ������ ���
	printf("Check the sizes of row and col!\n");
	return NULL;
	}

	int **matrix, i;
	matrix =(int**)malloc(row*sizeof(int*)); //rowX�̱������� ��ŭ ���� �Ҵ��Ͽ� matrix�� �ּҴ���

	for(i=0;i<row;i++)
		matrix[i] = (int*)malloc(col*sizeof(int)); //colX���������͸�ŭ ���� �Ҵ��Ͽ� matrix[i]�� �ּҴ���
	//&matrix[0][0]=*x // &matrix[0]=**x  ?

	fill_data(matrix,row,col);

	/* check post conditions */
	if(matrix == NULL) { //��Ļ��� ���� �� ���α׷� ����
		printf("Failed to crate matrix!\n");
		printf("Exit the program\n");
		return 0;
	}

	return matrix;
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return ;
		}

	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d\t", matrix[i][j]); //for�� �̿��Ͽ� ����� �� ���
		}
		printf("\n");
	}
	printf("\n\n");

	/* check post conditions */
	if(matrix == NULL) { //��Ļ��� ���н� ���α׷� ����
		printf("Failed to crate matrix!\n");
		printf("Exit the program\n");
		return ;
	}

}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return NULL;
		}

	int i;
	for(i=0; i<row; i++) //���ΰ��� �޸� ����
		free(matrix[i]);
	free(matrix); //���ΰ��� �޸� ����

	if (matrix == NULL)
		return 1; //�����۵�
	return -1; /* Not O.K */
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col) //0~19������ ���� ���� �� ��� ����
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return 0;
		}

	int i,j;
	for(i=0; i<row; i++){
		for(j=0; j<col;j++){
			matrix[i][j]=rand()%20; //������ ��Ŀ� ����
		}
	}

	/* check post conditions */
		if(matrix == NULL) {
			printf("Failed to crate matrix!\n");
			printf("Exit the program\n");
			return 0;
		}

	if (matrix != NULL)
		return 1;
	return -1; /* Not O.K */

}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return 0;
		}

	int **matrix_sum=0; //������������ matrix_sum �����ϰ� �ʱ�ȭ
	int i,j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){

			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j]; //����� ����
		}
	}

	print_matrix(matrix_sum, row, col);

	/* check post conditions */
		if(matrix_sum == NULL) {
			printf("Failed to crate matrix!\n");
			printf("Exit the program\n");
			return 0;
		}

	if (matrix_sum != NULL)
		return 1;
	return -1; /* Not O.K */

}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return 0;
		}

	int **matrix_sub=0; //������������ matrix_sub �����ϸ� �ʱ�ȭ
		int i,j;
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){ //����� ����
				matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j];
			}
		}
	 print_matrix(matrix_sub, row, col);
	 /* check post conditions */
	 		if(matrix_sub == NULL) {
	 			printf("Failed to crate matrix!\n");
	 			printf("Exit the program\n");
	 			return 0;
	 		}

	 	if (matrix_sub != NULL)
	 		return 1;
	 	return -1; /* Not O.K */
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return 1;
		}

	int i,j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			matrix_t[i][j]=matrix[j][i]; //����� ��ġ
		}
	}

	print_matrix(matrix_t, col, row);
	/* check post conditions */
			if(matrix_t == NULL) {
				printf("Failed to crate matrix!\n");
				printf("Exit the program\n");
				return 0;
			}

		if (matrix_t != NULL)
			return 1;
		return -1; /* Not O.K */
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
	/* check pre conditions */
		if(row <= 0 || col <=0) {
		printf("Check the sizes of row and col!\n");
		return 1;
		}

	int i,j,k;
	int **matrix_axt=0; //�����������ͺ��� �����ϸ� �ʱ�ȭ
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				for(k=0; k<row; k++){
					matrix_axt[i][j]=matrix_a[i][k]*matrix_t[k][j]; //����� �� ����
				}
			}
		}
		print_matrix(matrix_axt, row, col);

		/* check post conditions */
				if(matrix_axt == NULL) {
					printf("Failed to crate matrix!\n");
					printf("Exit the program\n");
					return 1;
				}

			if (matrix_axt != NULL)
				return 0;
			return -1; /* Not O.K */
}
