#include <stdio.h>

int main() {
	int N = 0, M = 0, cnt =1;
	int area[2] = { 0,1 }, areasize[50][50] = { 0, };
	int pos[3] = { 0, };

	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &pos[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%d", &areasize[i][j]);
		}
	}
	while (1)
	{
		int k = 0;
		switch (pos[2])
		{
		case 0:
			if (areasize[pos[0] - 1][pos[1]] == 0)
			{
				areasize[pos[0]][pos[1]] = 1;
				pos[0]--;
				cnt++;
			}
			else if (k==4)
			{
				break;
			}
			else
			{
				pos[2]++;
				k++;
			}
			continue;
		case 1:
			if (areasize[pos[0]][pos[1]+1] == 0)
			{
				areasize[pos[0]][pos[1]] = 1;
				pos[1]++;
				cnt++;
			}
			else if (k == 4)
			{
				break;
			}
			else
			{
				pos[2]++;
				k++;
			}
			continue;
		case 2:
			if (areasize[pos[0]+1][pos[1]] == 0)
			{
				areasize[pos[0]][pos[1]] = 1;
				pos[0]++;
				cnt++;
			}
			else if (k == 4)
			{
				break;
			}
			else
			{
				pos[2]++;
				k++;
			}
			continue;
		case 3:
			if (areasize[pos[0]][pos[1] - 1] == 0)
			{
				areasize[pos[0]][pos[1]] = 1;
				pos[1]--;
				cnt++;
			}
			else if (k == 4)
			{
				break;
			}
			else
			{
				pos[2]++;
				k++;
			}
			continue;
		default:
			break;
		}
		break;
	}	
	printf("%d", cnt);
}