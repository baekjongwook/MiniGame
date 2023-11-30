#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;

void mainmenu();
void RSP();
void roll();
void BAW();
void userturn(int* user, int user_tile[], int used_user_tile[]);
void comturn(int* com, int com_tile[], int used_com_tile[]);
void BOSS();
void Enqueue(Queue* queue, int data);
void Dequeue(Queue* queue);
int empty(Queue* queue);

int medal = 0;
int clear_RSP = 0;
int clear_roll = 0;
int clear_BAW = 0;
int clear_BOSS = 0;

int main()
{
	int startgame;

	printf("====================Mini Game World====================\n");
	printf("                                         Made by ������\n");
	printf("\n        *�̴ϰ��ӿ��忡 ���� ���� ȯ���մϴ�*        \n");
	printf("*�� ���� �̴ϰ����� Ŭ���� �� ������ �޴��� �־����ϴ�*\n");
	printf("* 3���� �޴��� ��� �����ø� ������ ���������� �����ϴ�*\n");
	printf(" *������ ���������� Ŭ���� �Ͻø� ������ Ŭ����˴ϴ�* \n");
	printf("            *�����Ͻ÷��� 0�� �����ּ���*            \n");
	printf("            *����Ͻ÷��� 1�� �����ּ���*            \n");
	printf("\n====================Mini Game World====================\n");

	do
	{
		scanf_s("%d", &startgame);

		if (startgame == 0)
		{
			printf("������ �����մϴ�\n");
			break;
		}

		else if (startgame == 1)
		{
			system("cls");
			mainmenu();
		}

		else
			printf("�ùٸ� ��ȣ�� �Է����ּ���!\n");
	} while (startgame != 1);

	return 0;
}

void mainmenu()
{
	int select;
	int gameover = 0;

	printf("====================���� ����====================\n");
	printf("1.����������\n");
	printf("2.��Ÿ����\n");
	printf("3.��� ��\n");
	printf("4.FINAL STAGE\n");
	printf("5.���ݱ����� �޴� Ȯ��\n");
	printf("0.���� ����\n");
	printf("====================���� ����====================\n");

	while (gameover != 1)
	{
		scanf_s("%d", &select);

		switch (select)
		{
			case 0:
				printf("������ �����մϴ�\n");
				gameover++;

				break;
		
			case 1:
				if (clear_RSP == 1)
					printf("�� ������ �̹� Ŭ�����ϼ̽��ϴ�\n");

				else
				{
					RSP();
					gameover++;
				}

				break;

			case 2:
				if (clear_roll == 1)
					printf("�� ������ �̹� Ŭ�����ϼ̽��ϴ�\n");

				else
				{
					roll();
					gameover++;
				}

				break;

			case 3:
				if (clear_BAW == 1)
					printf("�� ������ �̹� Ŭ�����ϼ̽��ϴ�\n");

				else
				{
					BAW();
					gameover++;
				}

				break;

			case 4:
				if (medal != 3)
					printf("���� �޴��� ������ �����մϴ�\n");

				else
				{
					BOSS();
					gameover++;

					if (clear_BOSS == 1)
					{
						system("cls");
						printf("�����մϴ�! ������ ��� Ŭ�����ϼ̽��ϴ�!\n");
					}
				}

				break;

			case 5:
				printf("���ݱ��� ȹ���� �޴� ������ %d���Դϴ�\n", medal);
				break;

			default :
				printf("��ȣ�� ���� ������ �����ϼ̽��ϴ�!\n");
				break;
		};
	}
}

void RSP()
{
	system("cls");

	int user, com, select;
	int win = 0, lose = 0;

	srand((unsigned)time(NULL));

	printf("====================����������====================\n");
	printf("     *����, ����, �� �� �� ���� �����Ͻʽÿ�*      \n");
	printf("       *������ �� 3�� 2�������� ����˴ϴ�*        \n");
	printf("*��ǻ�Ϳ��� ��ῡ�� �¸��ϸ� ������ Ŭ����˴ϴ�*\n");
	printf("====================����������====================\n");

	while ((win != 2) && (lose != 2))
	{
		printf("\n���� �̱� Ƚ�� : %d\n", win);
		printf("���� �� Ƚ�� : %d\n", lose);
		
		printf("1.����\n");
		printf("2.����\n");
		printf("3.��\n");
		
		while (1)
		{
			scanf_s("%d", &user);

			system("cls");

			printf("����� �� �� : ");
			if (user == 1)
			{
				printf("����\n");
				break;
			}

			else if (user == 2)
			{
				printf("����\n");
				break;
			}

			else if (user == 3)
			{
				printf("��\n");
				break;
			}

			else
				printf("�ùٸ� ���� �Է����ּ���!\n");
		}

		com = rand() % 3 + 1;
		
		printf("��ǻ�Ͱ� �� �� : ");
		if (com == 1)
			printf("����\n");

		else if (com == 2)
			printf("����\n");

		else if (com == 3)
			printf("��\n");

		if (((user == 1) && (com == 3)) || ((user == 2) && (com == 1)) || ((user == 3) && (com == 2)))
		{
			printf("��ǻ�Ϳ��� �ºο��� �¸��Ͽ����ϴ�!\n");
			win++;
		}

		else if (((user == 1) && (com == 2)) || ((user == 2) && (com == 3)) || ((user == 3) && (com == 1)))
		{
			printf("��ǻ�Ϳ��� �ºο��� �й��Ͽ����ϴ�!\n");
			lose++;
		}

		else
			printf("�����ϴ�!\n");
	}

	if (win == 2)
	{
		printf("\n�����մϴ�! ���������� ������ Ŭ�����Ͽ����ϴ�!\n");
		clear_RSP++;

		printf("�������� �޴� 1���� �帳�ϴ�\n");
		medal++;

		printf("����Ͻ÷��� 1�� �Է����ּ���\n");
		printf("�����Ͻ÷��� �ƹ� Ű�� �Է����ּ���\n");
		scanf_s("%d", &select);


		if (select == 1)
		{
			system("cls");
			mainmenu();
		}
	}

	else
		printf("\nGAME OVER!\n");
}

void roll()
{
	system("cls");

	clock_t start, end;
	int win = 0, lose = 0;
	int select, com_time;
	char space;

	printf("====================��Ÿ����====================\n");
	printf("*�����̽��ٸ� �־��� Ƚ����ŭ �ִ��� ���� ��������*\n");
	printf("       *������ �� 3�� 2�������� ����˴ϴ�*        \n");
	printf("*��ǻ�Ϳ��� �¸��� ������ ��ǻ�ʹ� �� �������ϴ�*\n");
	printf("*��ǻ�Ϳ��� ��ῡ�� �¸��ϸ� ������ Ŭ����˴ϴ�*\n");
	printf("====================��Ÿ����====================\n\n");

	while ((win != 2) && (lose != 2))
	{
		if (win == 0)
			com_time = 150;

		else
			com_time = 130;

		printf("���� �̱� Ƚ�� : %d\n", win);
		printf("���� �� Ƚ�� : %d\n", lose);
		printf("�����̽��ٸ� 30ȸ �Է��ϼ���\n");
		printf("�� �� �Է��ϴ� ���� ���۵˴ϴ�\n");

		printf("\n��� : ");

		for (int i = 1; i <= 30; i++)
		{
			space = _getch();

			if (space == 32)
			{
				printf("%d ", i);

				if (i == 1)
					start = clock();
			}
		}

		end = clock();

		double time_gap = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n%g�� �ɷȽ��ϴ�\n", time_gap);

		printf("\n��ǻ�� : ");
		
		for (int i = 1; i <= 30; i++)
		{
			if (i == 1)
				start = clock();
			
			printf("%d ", i);

			Sleep(com_time);
		}

		end = clock();

		double com_time_gap = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n%g�� �ɷȽ��ϴ�\n", com_time_gap);

		if (time_gap < 2.5)
		{
			lose++;
			printf("\n��Ģ�Դϴ�! �й�� ó���˴ϴ�\n");
			printf("�غ� �Ǽ̴ٸ� 1�� �Է����ּ���\n");

			while (1)
			{
				scanf_s("%d", &select);

				if (select == 1)
					break;
				else
					printf("�ùٸ� ���� �Է����ּ���!\n");
			}

			system("cls");
		}

		else if (time_gap < com_time_gap)
		{
			win++;
			printf("\n��ǻ�Ϳ��� �ºο��� �¸��Ͽ����ϴ�!\n");
			printf("�غ� �Ǽ̴ٸ� 1�� �Է����ּ���\n");

			while (1)
			{
				scanf_s("%d", &select);

				if (select == 1)
					break;
				else
					printf("�ùٸ� ���� �Է����ּ���!\n");
			}

			system("cls");
		}

		else
		{
			lose++;
			printf("\n��ǻ�Ϳ��� �ºο��� �й��Ͽ����ϴ�!\n");
			printf("�غ� �Ǽ̴ٸ� 1�� �Է����ּ���\n");

			while (1)
			{
				scanf_s("%d", &select);

				if (select == 1)
					break;
				else
					printf("�ùٸ� ���� �Է����ּ���!\n");
			}

			system("cls");
		}
	}

	if (win == 2)
	{
		printf("�����մϴ�! ��Ÿ������ Ŭ�����Ͽ����ϴ�!\n");
		clear_roll++;

		printf("�������� �޴� 1���� �帳�ϴ�\n");
		medal++;

		printf("����Ͻ÷��� 1�� �Է����ּ���\n");
		printf("�����Ͻ÷��� �ƹ� Ű�� �Է����ּ���\n");
		scanf_s("%d", &select);

		if (select == 1)
		{
			system("cls");
			mainmenu();
		}
	}

	else
		printf("\nGAME OVER!\n");
}

void BAW()
{
	system("cls");

	int i;
	int user, com, select;
	int turn = 1;
	int user_tile[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int com_tile[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int used_user_tile[9];
	int used_com_tile[9];
	int win = 0, lose = 0;

	srand((unsigned)time(NULL));

	printf("============================��� ��=============================\n");
	printf("   ����� 0���� 8���� Ÿ�� �� �ϳ��� �����Ͽ� �� �� �ֽ��ϴ�   \n");
	printf("    ��ǻ�� ���� 0���� 8���� Ÿ�� �� �ϳ��� �����Ͽ� ���ϴ�    \n");
	printf("��Ű� ��ǻ�Ͱ� �� Ÿ����, �� ���� ���ڸ� ���� ����� �¸��մϴ�\n");
	printf("          �� �� �� Ÿ���� �ٽ� ������ �Ұ����մϴ�          \n");
	printf("   ��ǻ�� �� Ÿ���� �� �� ���� ���, �� Ÿ���� Ȧ���� ���,   \n");
	printf("             �� Ÿ���� ¦���� ������� �˷��ݴϴ�             \n");
	printf("     �� 9���� ������ ����Ǹ� �� �÷��̾�� ���ư��� �˴ϴ�    \n");
	printf("       ��ǻ�Ϳ��� ��ῡ�� �¸��ϸ� ������ Ŭ����˴ϴ�       \n");
	printf("============================��� ��=============================\n\n");

	for(i = 0; i < 9; i++)
	{
		printf("���� ���ھ�\n");
		printf("��� : ��ǻ�� = %d : %d\n\n", win, lose);

		if (turn % 2 != 0)
		{
			printf("����� ���� ������ �����Դϴ�\n");
			userturn(&user, user_tile, used_user_tile);
			comturn(&com, com_tile, used_com_tile);
		}

		else
		{
			printf("��ǻ�Ͱ� ���� ������ �����Դϴ�\n");
			comturn(&com, com_tile, used_com_tile);
			userturn(&user, user_tile, used_user_tile);
		}

		printf("\n����� ������ 1�� �Է����ּ���\n");

		while (1)
		{
			scanf_s("%d", &select);

			if (select == 1)
				break;
			else
				printf("�ùٸ� ���� �Է����ּ���!\n");
		}

		system("cls");

		if (user > com)
		{
			printf("����� �¸�\n\n");
			win++;
		}

		else if (user < com)
		{
			printf("��ǻ���� �¸�\n\n");
			lose++;
		}

		else
			printf("�����ϴ�\n\n");

		turn++;
	}

	if (win > lose)
	{
		system("cls");

		printf("�����մϴ�! ��� ���� Ŭ�����Ͽ����ϴ�!\n");
		clear_BAW++;

		printf("�������� �޴� 1���� �帳�ϴ�\n");
		medal++;

		printf("����Ͻ÷��� 1�� �Է����ּ���\n");
		printf("�����Ͻ÷��� �ƹ� Ű�� �Է����ּ���\n");
		scanf_s("%d", &select);

		if (select == 1)
		{
			system("cls");
			mainmenu();
		}
	}

	else if (win == lose)
	{
		system("cls");

		printf("�����ϴ�. �ѹ� �� �÷����մϴ�\n");
		printf("����Ϸ��� 1�� �Է����ּ���\n");

		while (1)
		{
			scanf_s("%d", &select);

			if (select == 1)
				break;
			else
				printf("�ùٸ� ���� �Է����ּ���!\n");
		}

		BAW();
	}

	else
	{
		system("cls");
		printf("\nGAME OVER!\n");
	}
}

void userturn(int *user, int user_tile[], int used_user_tile[])
{
	printf("\n���� ����� Ÿ�� : \n");

	for (int j = 0; j < 9; j++)
		printf("%d ", user_tile[j]);

	printf("\n\n�� Ÿ���� ���ڸ� �Է����ֽʽÿ� : ");

	while (1)
	{
		scanf_s("%d", &(*user));

		if (*user == used_user_tile[*user])
			printf("�� Ÿ���� �̹� ����߽��ϴ�!\n");

		else if (*user >= 0 && *user <= 8) 
		{
			used_user_tile[*user] = *user;
			break;
		}

		else
			printf("�ùٸ� ���ڸ� �Է����ּ���!\n");
	}

	for (int j = 0; j < 9; j++)
	{
		if (*user == user_tile[j])
		{
			user_tile[j] = -1;
			break;
		}
	}

	if (*user % 2 != 0)
		printf("\n����� ������ Ÿ���� ���� *���*�Դϴ�\n");

	else
		printf("\n����� ������ Ÿ���� ���� *���*�Դϴ�\n");
}

void comturn(int *com, int com_tile[], int used_com_tile[])
{
	while (1)
	{
		*com = rand() % 9;

		if (*com != used_com_tile[*com]);
		{
			used_com_tile[*com] = *com;
			break; 
		}
	}

	for (int j = 0; j < 9; j++)
	{
		if (*com == com_tile[j])
		{
			com_tile[j] = -1;
			break;
		}
	}

	if (*com % 2 != 0)
		printf("\n��ǻ�Ͱ� ������ Ÿ���� ���� *���*�Դϴ�\n");

	else
		printf("\n��ǻ�Ͱ� ������ Ÿ���� ���� *���*�Դϴ�\n");
}

void BOSS()
{
	system("cls");

	Queue* queue = malloc(sizeof(Queue)); //ť ����ü ���� ����
	queue->front = NULL; //ť���� front�� �ʱ�ȭ
	queue->rear = NULL; //ť���� rear�� �ʱ�ȭ

	int number[4][4];
	char alphabet[4][4];
	int i, j, select;
	int tofront = 9, torear = 10;
	int count = 1;

	srand((unsigned)time(NULL));

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			number[i][j] = count;
			count++;
		}
	}

	count = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			alphabet[i][j] = count + 65;
			count++;
		}
	}

	for (int i = 0; i < 100; i++) 
	{     
		int randNum1 = rand() % 4;
		int randNum2 = rand() % 4;
		int randNum3 = rand() % 4;
		int randNum4 = rand() % 4;

		int temp;

		temp = alphabet[randNum1][randNum2];

		alphabet[randNum1][randNum2] = alphabet[randNum3][randNum4];

		alphabet[randNum3][randNum4] = temp;
	}

	for(i = 0; i < 20; i++)
		Enqueue(queue, rand() % 16 + 65);

	Node* you = queue->front;

	for (i = 0; i < 9; i++)
		you = you->next;

	while (1)
	{
		printf("  *���� Ÿ��*  \n");

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				printf("%3d", number[i][j]);
			printf("\n");
		}

		printf("\n���� �������� %dĭ ���Ұ�,\n", torear);
		printf("\nŻ�� �������� %dĭ ���ҽ��ϴ�\n", tofront);

		printf("\n����� ã�ƾ� �� ���� Ÿ�� : %c\n", you->data);

		printf("\n��� Ÿ���� ��ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &select);

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (select == number[i][j])
				{
					printf("\n%d �� Ÿ���� ���ڴ� %c �Դϴ�\n", number[i][j], alphabet[i][j]);
					
					if (alphabet[i][j] == you->data)
					{
						printf("\n���߾����ϴ� �� ĭ ������ �����մϴ�\n\n");
						you = you->next;
						torear--;
					}

					else
					{
						printf("\nƲ�Ƚ��ϴ� �����̾Ʈ�� �� ĭ �����մϴ�\n");
						Enqueue(queue, rand() % 16 + 65);
						Dequeue(queue);
						torear++;
					}

					tofront = 19 - torear;

					printf("\n����Ͻ÷��� 1�� �Է����ּ���\n");

					while (1)
					{
						scanf_s("%d", &select);

						if (select == 1)
							break;
						else
							printf("�ùٸ� ���� �Է����ּ���!\n");
					}

					system("cls");
				}
			}
	    }

		if (torear == 0)
		{
			system("cls");

			printf("�����մϴ�! ���� �׸� ã�⸦ Ŭ�����Ͽ����ϴ�!\n");
			clear_BOSS++;

			printf("����Ͻ÷��� 1�� �Է����ּ���\n");
			printf("�����Ͻ÷��� �ƹ� Ű�� �Է����ּ���\n");
			scanf_s("%d", &select);

			if (select == 1)
			{
				system("cls");
				mainmenu();
			}

			break;
		}

		else if (tofront == 0)
		{
			system("cls");
			printf("GAME OVER!\n");

			break;
		}
	}
}

void Enqueue(Queue* queue, int data)
{
	Node* newNode = malloc(sizeof(Node)); //��� ����
	newNode->data = data; //���ο� ��忡 �����͸� ����
	newNode->next = NULL; //���ο� ����� ���� ���� ���� = �� ��尡 ���� �Ʒ��� ��ġ��

	if (empty(queue) == 1) //ť�� ����ִٸ�
	{
		queue->front = newNode; //ť�� ��(�����)���� ���ο� ����̴� 
		queue->rear = newNode;//ť�� ��(�� �Ʒ�) ���� ���ο� ����̴� 
	}

	else //�ƴ϶��
	{
		queue->rear->next = newNode; //���� ť�� ��(�� �Ʒ�) ����� ���� ���� ���ο� ����̴�
		queue->rear = newNode;//ť�� ��(�� �Ʒ�) ���� ���ο� ����̴� 
	}
}

void Dequeue(Queue* queue)
{
	Node* newNode = malloc(sizeof(Node)); //��� ����

	newNode = queue->front; //���ο� ��带 front���� ����
	queue->front = newNode->next; //������ front�� �� ����� next�� ����

	free(newNode); //front�� �� �� ����� �Ҵ� ����
}

int empty(Queue* queue)
{
	if (queue->front == NULL) //���� front�� �ΰ��� �����ٸ�,
		return 1; //true��ȯ

	else //�ƴϸ�
		return 0; //false��ȯ
}