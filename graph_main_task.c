#include <stdio.h>
#include <stdlib.h>
FILE* f;

int main(void)
{
	printf("Enter the amount of edge - vertex\n");
	int conn; // Svyazi
	int vert; // Vershini

	printf("Vvedite colichestvo svyazei: ");
	scanf("%d", &conn);
	printf("\n");
	printf("Vvedite colichestvo vershin: ");
	scanf("%d", &vert);

	int massive[conn][vert];

	// 0 - no connection
	// 1 - connection with other 1 vertex
	// 2 - loop connection
	for (int i = 0; i < conn; i++)
	{
		for (int j = 0; j < vert; j++)
		{
			printf("Zapolni massive: ");
			scanf("%d", &massive[i][j]);
		} 
	}
	
	f = fopen("graph.dot", "w");
	if (f == NULL)
		return 0;

	fprintf(f, "graph TimoGraf {\n");


	for (int i = 0; i < conn; i++)
	{
		int x1 = -1;
		int x2 = -1;

		for (int j = 0; j < vert; j++)
		{
			if (massive[i][j] == 1 && x1 == -1)
				x1 = j + 1;
			else if (massive[i][j] == 1 && x2 == -1)
				x2 = j + 1;
			else if (massive[i][j] == 2)
				x2 = x1 = j + 1;
		}
		
		if (x1 == -1)
			fprintf(f, "%d;\n", x2);
		else if (x2 == -1)
			fprintf(f, "%d;\n", x1);
		else
			fprintf(f, "%d — %d\n", x1, x2);

	}
	fprintf(f, "}");


	// finding loops and multiple edges
	if (vert > (0.5(vert - 1) * (vert - 2)))
		printf("The graph is connected");
	else
		printf("The graph is not connected");

	return 0;
}