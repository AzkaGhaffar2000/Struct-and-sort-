
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

struct Movie
{
	char title[50];
	char director[50];
	int length;
	int year;
}temp;

void Display(int m, struct Movie *movie, int sort);

int main()
{
	char ch;
	
	do{
	int i, m, sort;
	char junk[2];
	struct Movie *film[10];
	
	printf("Enter the amount of movies you are going to input, no more than 10: ");
	scanf("%d", &m);
	
	for (i = 0; i < m; i++)
	{
		fgets(junk, 2, stdin);
		film[i] = (struct Movie *)malloc(sizeof(struct Movie));
		printf("Enter the movie title: ");
		fgets(film[i]->title, sizeof(film[i]->title),stdin);
		printf("Enter the name of director: ");
		fgets(film[i]->director, sizeof(film[i]->director),stdin);
		printf("Enter the movie length in minutes: ");
		scanf("%d", &film[i]->length);
		printf("Enter the year it was released: ");
		scanf("%d", &film[i]->year);
		fgets(junk, 2, stdin);
		printf("\nHow would you like to sort it: By title-enter 1, By Director-enter 2,");
		printf("\nBy length-enter 3, By Year-enter 4? ");
		scanf("%d", &sort);
		Display(m, film[i], sort);
	}
	printf("Repeat or Continue Y/N: ");
	scanf(" %c", &ch);
	}
	while (ch == 'y' || ch == 'Y');

}

void Display(int m, struct Movie *movie, int sort)
{
	int i, j;
	if (sort == 1)
	{
	for (i = 0; i < m; i++)
		{
		printf("Title: %s\n", movie->title);
		printf("Director: %s\n", movie->director);
   		printf("Length in minutes: %d\n", movie->length);
   		printf("Year: %d\n", movie->year);
   		}
		for (i = 0; i < m-1; i++)
		{
			for (j = 0; j < m - i -1; j++)
			{
				if (strcmp(movie[j].title, movie[j + 1].title) > 0)
				{
					temp = movie[j];
					movie[j] = movie[j + 1];
					movie[j + 1] = temp;
				}
			}
		}
	}
   	if (sort == 2) 
	{ 
		for (i = 0; i < m; i++)
		{
		printf("Director: %s\n", movie->director);
		printf("Title: %s\n", movie->title);
   		printf("Length in minutes: %d\n", movie->length);
   		printf("Year: %d\n", movie->year);
   		}
   		for (i = 0; i < m-1; i++)
		{
			for (j = 0; j < m - i -1; j++)
			{
				if (strcmp(movie[j].director, movie[j + 1].director) > 0)
				{
					temp = movie[j];
					movie[j] = movie[j + 1];
					movie[j + 1] = temp;
				}
			}
		}
   	}
   	if (sort == 3) 
	{ 
		for (i = 0; i < m; i++)
		{
		printf("Length in minutes: %d\n", movie->length);
		printf("\nTitle: %s\n", movie->title);
   		printf("Director: %s\n", movie->director);
   		printf("Year: %d\n", movie->year);
   		}
   		for (i = 0; i < m-1; i++)
		{
			for (j = 0; j < m - i -1; j++)
			{
				if (movie[j].length > movie[j + 1].length)
				{
					temp = movie[j];
					movie[j] = movie[j + 1];
					movie[j + 1] = temp;
				}
			}
		}
   	}
   	if (sort == 4) 
	{ 
		for (i = 0; i < m; i++)
		{
		printf("Year: %d\n", movie->year);
		printf("\nTitle: %s\n", movie->title);
   		printf("Director: %s\n", movie->director);
   		printf("Length in minutes: %d\n", movie->length);
   		}
   		for (i = 0; i < m-1; i++)
		{
			for (j = 0; j < m - i -1; j++)
			{
				if (movie[j].year > movie[j + 1].year) 
				{
					temp = movie[j];
					movie[j] = movie[j + 1];
					movie[j + 1] = temp;
				}
			}
		}
   	}
}