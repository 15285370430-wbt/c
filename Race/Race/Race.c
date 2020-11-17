#include<stdio.h>

int main() {
	int A = 1;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;

	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if (((B == 2) + (A == 3)) == 1 && ((B == 2) + (E == 4)) == 1 && ((C == 1) + (D == 2)) == 1
							&& ((C == 5) + (D == 3)) == 1 && ((E == 4) + (A == 1)) == 1) {
							if (A*B*C*D*E == 120) {
								printf("%d %d %d %d %d", A, B, C, D, E);
							}
						}
					}
				}
			}
		}

	}
	return 0;
}