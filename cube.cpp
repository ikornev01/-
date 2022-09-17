#include <stdio.h>
// реализовать переход через метку к опред. фрагментам кода
// попробовать занулять dont_move после каждого движения
int b = 2;
int flag = 0, dont_move = 0;
int static cnt = 0;
// k = 0 - на нас, k = 1 - вниз, k = -1 - вверх, k = 11 - влево, k = -11 - вправо
void cube(int a[10][10], int n, int k, int i, int j) 
{
//		cnt++;	
		int back = k;
		if (j == (n-1)) dont_move = 1; //уперлись в правую границу, движение вниз невозможно
		else dont_move = 0;
		if (i == (n-1)) goto not_left;
//		printf(" a[%d][%d] = %d, k = %d\n", i,j,a[i][j],k);
		if (dont_move != 1)
		if (i < (n - 1) && a[i+1][j] == 0 && k != 1 ) // можно ли пойти вниз
		{
			a[i+1][j] = b; 
			b++;
			if (k == 0)
				cube(a, n, k = 1, i+1, j); 
			else if (k == -1) 
				cube(a, n, k = 0, i+1, j);
			else 
				cube(a, n, k, i+1, j);
			
			if (flag == 0) {
			a[i+1][j] = 0; 
			k = back;
			b--;
			}
		}
		if (j > 0 && a[i][j-1] == 0 && k != 11) //можно ли пойти влево
		{
			a[i][j-1] = b;
			b++;
			if (k == 0)
				cube(a, n, k = 11, i, j-1);
			else if (k == -11) 
				cube(a, n, k = 0, i, j - 1);
			else cube(a, n, k, i, j - 1);
			
			if (flag == 0) {
				b--;
				a[i][j-1] = 0;
				k = back;
			}
		}
		not_left:
		if (i > 0 && a[i-1][j] == 0 && k != -1) //можно ли пойти вверх
		{
			
			a[i-1][j] = b;
			b++;
			if (a[0][n - 1] == n*n) {
			
			flag = 1;
//			printf("count = %d\n", cnt);
		
			}
			if (k == 0) 
				cube(a, n, k = -1, i-1, j);
			else if (k == 1)
				cube(a, n, k = 0, i-1, j);
			else 
				cube(a, n, k, i-1, j);
			
			if (flag == 0) {
				b--;
				a[i-1][j] = 0;
				k = back;
			}
		}
		
		if (j < (n - 1) && a[i][j+1] == 0 && k != -11) //можно ли пойти вправо
		{
		
			a[i][j+1] = b;
			b++;
			if (a[0][n-1] == n*n) {
			
			flag = 1;
//			printf("count = %d\n", cnt);
		
			}
			if (k == 0)	
				cube(a, n, k = -11, i, j+1);
			else if (k == 11) 
				cube(a, n, k = 0, i, j+1);
			else 
				cube(a, n, k, i, j+1);
			
			if (flag == 0) {
				b--;
				a[i][j + 1] = 0;
				k = back;
			}
		}	
}

int main() {
	int i, n = 9, j, k = 0;
	printf("N = %d\nProcessing...\n", n);

	int a[10][10];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
	a[0][0] = 1;
	
	i = 0; j = 0;
	cube(a, n, k, i, j);
	if (a[0][n-1] == 0)  printf("Net puti pri zadannom N");
	else
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) printf("%3d ", a[i][j]);
			printf("\n");
		}
}