#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000

int main()
{
	char words[MAX_NUM_WORDS][MAX_WORD_LEN]; 
	int num_words = 0;						 
	char filename[50];
	printf("Enter file name  ");
	scanf("%s", filename);


	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("file doesnt exists\n");
		exit(1);
	}

	
	while (fscanf(fp, "%s", words[num_words]) == 1)
	{
		num_words++;
		if (num_words == MAX_NUM_WORDS)
		{
			printf("owerflow (%d)\n", MAX_NUM_WORDS);
			break;
		}
	}


	fclose(fp);


	struct Number
	{
		char name[50];
		int value;
	};
	struct String
	{
		char name[50];
		char value[150];
	};
	
	signed int result = 0;
	signed int num_operand1 = 0;
	signed int num_operand2 = 0;
	int integer_length = 0;
	int string_length = 0;

	for (int i = 0; i < num_words; ++i)
	{
		if (strcmp(words[i], "int") == 0)
		{
			integer_length++;
		}
		else if (strcmp(words[i], "str") == 0)
		{
			string_length++;
		}
	}

	struct Number number[integer_length];
	struct String string[string_length];

	for (int i = 0; i < num_words; i++)
	{
		if (strcmp(words[i], "int") == 0)
		{
			strcpy(number[i].name, words[i + 1]);
			number[i].value = atoi(words[i + 2]);
			
		}
		else if (strcmp(words[i], "str") == 0)
		{
			strcpy(string[i].name, words[i + 1]);
			strcpy(string[i].value, words[i + 2]);
			
		}
	}

	for (int i = 0; i < num_words; i++)
	{
		for (int j = 0; j < num_words; j++)
		{
			if (strcmp(words[i], "log") == 0)
			{
				if (strcmp(words[i + 1], number[j].name) == 0)
				{

					num_operand1 = number[j].value;
				}
				if (strcmp(words[i + 3], number[j].name) == 0)
				{
					num_operand2 = number[j].value;
				}
			}
		}
	}

	for (int i = 0; i < num_words; i++)
	{
		if (strcmp(words[i], "log") == 0 && strcmp(words[i + 2], "+") == 0)
		{
			result = num_operand1 + num_operand2;
			printf("%d\n", result);
			result = 0;
		}
		else if (strcmp(words[i], "log") == 0 && strcmp(words[i + 2], "-") == 0)
		{
			result = num_operand1 - num_operand2;
			printf("%d\n", result);
			result = 0;
		}
		else if (strcmp(words[i], "log") == 0 && strcmp(words[i + 2], "*") == 0)
		{
			result = num_operand1 * num_operand2;
			printf("%d\n", result);
			result = 0;
		}
		else if (strcmp(words[i], "log") == 0 && strcmp(words[i + 2], "/") == 0)
		{
			result = num_operand1 / num_operand2;
			printf("%d\n", result);
			result = 0;
		}
	}

	return 0;
}
