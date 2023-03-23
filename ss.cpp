	#include <conio.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <time.h>

	typedef struct had
	{
		int x, y;
		char z;
	}HAD;

	typedef struct fruit
	{
		int x;
		int y;
		char z;
	}FRUIT;

	void draw(HAD h[], int n, int cas, FRUIT f)
	{
		int z = 0;
		int i, j;
		char m[10][10];
		
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				z = 0;
				for (int k = 0; k < n; k++) {
					if (h[k].x == i && h[k].y == j) { printf("%c ", h[k].z); z = 1; };
				}
				if (z == 1) continue;
				if (f.x == i && f.y == j) { printf("%c ", f.z); continue; };
				
				if (i == 0 || i == 9 || j == 9 || j == 0) m[i][j] = '#';
				else m[i][j] = ' ';
				printf("%c ", m[i][j]);
			}
			printf("\n");
		}
		printf("\nCas: %i Ovoci: %i", cas, n-1);
		printf("\nPress x pre vychodu");
		if (h[0].x == 0 || h[0].x == 9 || h[0].y == 0 || h[0].y == 9) { system("cls"); printf("\nZjedli ste %i ovocia!", n-1); exit(0);}
	}

	void input(HAD h[], int n, FRUIT f)
	{
		int zn, x, y, xt, yt;
		x = h[0].x;
		y = h[0].y;
		zn = getch();
		switch (zn)
		{
		case 'w': 
			h[0].x--;
			break;
		case 'a':
			h[0].y--;
			break;
		case 'd':
			h[0].y++;
			break;
		case 's':
			h[0].x++;
			break;
		case 'x':
			system("cls");
			printf("\nZjedli ste %i ovocia!", n-1);
			exit(0);
			break;
		}
		for (int i = 0; i < n; i++)
		{
			if (i == 0) continue;
			xt = h[i].x;
			yt = h[i].y;
			h[i].x = x;
			h[i].y = y;
			x = xt;
			y = yt;
		}
	}

	main()
	{
		srand(time(0));
		clock_t start, end;	
		start = clock();
		int i, n = 1, cas = 0;
		HAD h[100];
		FRUIT f;
		h[0].x = 4;
		h[0].y = 4;
		h[0].z = 'S';
		f.x = 2;
		f.y = 3;
		f.z = 'f';
		while (cas < 30) {
			draw(h, n, cas, f);
			input(h, n, f);
			system("cls");
			if (f.x == h[0].x && f.y == h[0].y) {
				f.x = rand() % 8 + 1; f.y = rand() % 8 + 1;
				for (int k = 0; k < n; k++) {
					if (h[k].x == f.x && h[k].y == f.y) { f.x = rand() % 8 + 1; f.y = rand() % 8 + 1; };
				}
				n++;
				h[n - 1].z = rand()%200;
			};
			end = clock();
			cas = (end - start) / (double)(CLOCKS_PER_SEC);
		}

		printf("\nZjedli ste %i ovocia!", n-1);
	}
