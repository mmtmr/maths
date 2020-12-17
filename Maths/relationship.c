#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//https://github.com/lalit-kaim/C-programs/blob/master/Reflexive%20Symmetric%20Transitive%20program.C

int reflexive(char A[30], char R[30][2], int n, int m)
{
	//printf("Hello\n");
	int i, k, flag = 0;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= m; i++)
		{
			if (A[k] == R[i][1])
			{
				if (A[k] == R[i][2]) flag = flag + 1;
			}

		}
	}
	if (flag == n) return 1;
	else return 0;
}
int symmetric(char A[30], char R[30][2], int n, int m)
{
	//printf("Hello\n");
	int i, j, k, flag = 0, exit, verify_a, verify_b;
	char a, b;
	for (i = 1; i <= m; i++)
	{
		exit = 1;
		verify_a = 0;
		verify_b = 0;
		for (k = 1; k <= n; k++)
		{
			//if (R[i][1] == A[k]) printf("R[%d][1] is %c and A is %c\n", i, R[i][1], A[k]);
			//if (R[i][2] == A[k]) printf("R[%d][2] is %c and A is %c\n", i, R[i][2], A[k]);
			if (R[i][1] == A[k]) verify_a = 1;
			if (R[i][2] == A[k]) verify_b = 1;

		}
		if ((verify_a != 1) || (verify_b != 1))
		{
			//printf("clear\n");
			return -1;
		}

		for (j = 1; j <= m; j++)
		{
			if ((R[j][1] == R[i][2]) && (R[j][2] == R[i][1]))
			{
				flag = flag + 1;
				exit = 0;
				//printf("(R[%d][1] == R[%d][2]) && (R[%d][2] == R[%d][1]) sucess\n", i, j, i, j);
			}
		}

		if (exit == 1)
		{
			printf("Since (%c,%c) does not exist for (%c,%c)\n", R[i][2], R[i][1], R[i][1], R[i][2]);
			return 0;
		}
	}

	
	if (flag >= 1) return flag;
	
}
int transitive(char A[30], char R[30][2], int n, int m)
{
	int i, j, k, x, flag = 0, exit, verify_a, verify_b, reflex=0;
	char a, b;
	//printf("Hello\n");

	//reflex = reflexive(A, R, n, m);
	//if (reflex == 1 && m > n) return 1;
	for (i = 1; i <= m; i++)
	{
		verify_a = 0;
		verify_b = 0;
		for (x = 1; x <= n; x++)
		{
			//if (R[i][1] == A[k]) printf("R[%d][1] is %c and A is %c\n", i, R[i][1], A[k]);
			//if (R[i][2] == A[k]) printf("R[%d][2] is %c and A is %c\n", i, R[i][2], A[k]);
			if (R[i][1] == A[x]) verify_a = 1;
			if (R[i][2] == A[x]) verify_b = 1;

		}
		if ((verify_a != 1) || (verify_b != 1))
		{
			//printf("clear\n");
			return -1;
		}

		for (j = 1; j <= m; j++)
		{
			if ((R[i][2] == R[j][1]) && (i != j))
			{
				exit = 1;
				
				for (k = 1; k <= m; k++)
				{
					if ((R[i][1] == R[k][1]) && (R[j][2] == R[k][2]))// && (i != k) && (j != k)
					{
						flag = flag + 1;
						exit = 0;
						//printf("(R[%d][1] == R[%d][1]) && (R[%d][2] == R[%d][2]) sucess\n", i, k, j, k);
					}
					else if (k == m && exit == 1)
					{
						printf("Since (%c,%c) does not exist for (%c,%c) and (%c,%c) \n", R[i][1], R[j][2], R[i][1], R[i][2], R[j][1], R[j][2]);
						return 0;
					}
				}
			}
			
		}
		//if (exit == 1) printf("flag is%d\n exit is%d\n)", flag, exit);
		//if(exit==1) printf("(R[%d][1] == R[%d][1]) && (R[%d][2] == R[%d][2])\n", i, k-1, j-1, k-1);
		//if (exit == 1) return 0;//not for equivalence
	}
	if (flag >= 1) return flag;
}
int equivalence(char A[30], char R[30][2], int n, int m)
{
	int reflex = 0, symm = 0, trans = 0, flag = 0;

	reflex = reflexive(A, R, n, m);
	if (reflex == 1) printf("This is reflexive!\n"); // && (n == m))
	//else printf("reflex is %d\n", reflex);
	else printf("This is not reflexive!\n");

	symm = symmetric(A, R, n, m);
	if (symm >= 1) printf("This is symmetric!\n");
	else if (symm == -1) printf("The elements in relation are not in the R set");
	else if (symm == 0) printf("This is not symmetric!\n");

	trans = transitive(A, R, n, m);
	if (trans >= 1) printf("This is transitive!\n");
	else if (trans == 0) printf("This is not transitive!\n");

	if ((reflex == 1) && (symm >= 1) && (trans >= 1))// &&(m>n)
		flag = 1;
	return flag;
}
int main()
{
	while (1) {
		char A[30], R[30][2];
		int n, m, i, j, reflex = 0, symm = 0, trans = 0, eq = 0, k, flag = 0;

		printf("enter the no. of elements in a set:");
		scanf("%d", &n);

		printf("enter the element of set (space to seperate):\n");
		for (i = 1; i <= n; i++)
			scanf("%s", &A[i]);

		printf("enter the no. of relation set:");
		scanf_s("%d", &m);

		printf("enter the pairs of relation set:\n");
		for (i = 1; i <= m; i++)
			for (j = 1; j <= 2; j++)
				scanf("%s", &R[i][j]);

		printf("The entered relation is: {");
		for (i = 1; i <= m; i++)
		{
			printf("(");
			for (j = 1; j <= 2; j++)
			{
				printf("%c", R[i][j]);
				if (j == 1) printf(",");
			}
			printf("),");
		}
		printf("\b}\n");

		eq = equivalence(A, R, n, m);
		if (eq == 1) printf("This is equivalence!\n");
		else if (eq == 0) printf("This is not equivalence!\n");
	}
}