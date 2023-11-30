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
	printf("                                         Made by 백종욱\n");
	printf("\n        *미니게임월드에 오신 것을 환영합니다*        \n");
	printf("*한 개의 미니게임을 클리어 할 때마다 메달이 주어집니다*\n");
	printf("* 3개의 메달을 모두 모으시면 마지막 스테이지가 열립니다*\n");
	printf(" *마지막 스테이지를 클리어 하시면 게임이 클리어됩니다* \n");
	printf("            *종료하시려면 0을 눌러주세요*            \n");
	printf("            *계속하시려면 1을 눌러주세요*            \n");
	printf("\n====================Mini Game World====================\n");

	do
	{
		scanf_s("%d", &startgame);

		if (startgame == 0)
		{
			printf("게임을 종료합니다\n");
			break;
		}

		else if (startgame == 1)
		{
			system("cls");
			mainmenu();
		}

		else
			printf("올바른 번호를 입력해주세요!\n");
	} while (startgame != 1);

	return 0;
}

void mainmenu()
{
	int select;
	int gameover = 0;

	printf("====================게임 선택====================\n");
	printf("1.가위바위보\n");
	printf("2.연타게임\n");
	printf("3.흑과 백\n");
	printf("4.FINAL STAGE\n");
	printf("5.지금까지의 메달 확인\n");
	printf("0.게임 종료\n");
	printf("====================게임 선택====================\n");

	while (gameover != 1)
	{
		scanf_s("%d", &select);

		switch (select)
		{
			case 0:
				printf("게임을 종료합니다\n");
				gameover++;

				break;
		
			case 1:
				if (clear_RSP == 1)
					printf("이 게임은 이미 클리어하셨습니다\n");

				else
				{
					RSP();
					gameover++;
				}

				break;

			case 2:
				if (clear_roll == 1)
					printf("이 게임은 이미 클리어하셨습니다\n");

				else
				{
					roll();
					gameover++;
				}

				break;

			case 3:
				if (clear_BAW == 1)
					printf("이 게임은 이미 클리어하셨습니다\n");

				else
				{
					BAW();
					gameover++;
				}

				break;

			case 4:
				if (medal != 3)
					printf("아직 메달의 개수가 부족합니다\n");

				else
				{
					BOSS();
					gameover++;

					if (clear_BOSS == 1)
					{
						system("cls");
						printf("축하합니다! 게임을 모두 클리어하셨습니다!\n");
					}
				}

				break;

			case 5:
				printf("지금까지 획득한 메달 개수는 %d개입니다\n", medal);
				break;

			default :
				printf("번호에 없는 게임을 선택하셨습니다!\n");
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

	printf("====================가위바위보====================\n");
	printf("     *가위, 바위, 보 중 낼 것을 선택하십시오*      \n");
	printf("       *게임은 총 3판 2선승제로 진행됩니다*        \n");
	printf("*컴퓨터와의 대결에서 승리하면 게임이 클리어됩니다*\n");
	printf("====================가위바위보====================\n");

	while ((win != 2) && (lose != 2))
	{
		printf("\n현재 이긴 횟수 : %d\n", win);
		printf("현재 진 횟수 : %d\n", lose);
		
		printf("1.가위\n");
		printf("2.바위\n");
		printf("3.보\n");
		
		while (1)
		{
			scanf_s("%d", &user);

			system("cls");

			printf("당신이 낸 것 : ");
			if (user == 1)
			{
				printf("가위\n");
				break;
			}

			else if (user == 2)
			{
				printf("바위\n");
				break;
			}

			else if (user == 3)
			{
				printf("보\n");
				break;
			}

			else
				printf("올바른 값을 입력해주세요!\n");
		}

		com = rand() % 3 + 1;
		
		printf("컴퓨터가 낸 것 : ");
		if (com == 1)
			printf("가위\n");

		else if (com == 2)
			printf("바위\n");

		else if (com == 3)
			printf("보\n");

		if (((user == 1) && (com == 3)) || ((user == 2) && (com == 1)) || ((user == 3) && (com == 2)))
		{
			printf("컴퓨터와의 승부에서 승리하였습니다!\n");
			win++;
		}

		else if (((user == 1) && (com == 2)) || ((user == 2) && (com == 3)) || ((user == 3) && (com == 1)))
		{
			printf("컴퓨터와의 승부에서 패배하였습니다!\n");
			lose++;
		}

		else
			printf("비겼습니다!\n");
	}

	if (win == 2)
	{
		printf("\n축하합니다! 가위바위보 게임을 클리어하였습니다!\n");
		clear_RSP++;

		printf("보상으로 메달 1개를 드립니다\n");
		medal++;

		printf("계속하시려면 1을 입력해주세요\n");
		printf("종료하시려면 아무 키나 입력해주세요\n");
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

	printf("====================연타게임====================\n");
	printf("*스페이스바를 주어진 횟수만큼 최대한 빨리 누르세요*\n");
	printf("       *게임은 총 3판 2선승제로 진행됩니다*        \n");
	printf("*컴퓨터에게 승리할 때마다 컴퓨터는 더 강해집니다*\n");
	printf("*컴퓨터와의 대결에서 승리하면 게임이 클리어됩니다*\n");
	printf("====================연타게임====================\n\n");

	while ((win != 2) && (lose != 2))
	{
		if (win == 0)
			com_time = 150;

		else
			com_time = 130;

		printf("현재 이긴 횟수 : %d\n", win);
		printf("현재 진 횟수 : %d\n", lose);
		printf("스페이스바를 30회 입력하세요\n");
		printf("한 번 입력하는 순간 시작됩니다\n");

		printf("\n당신 : ");

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
		printf("\n%g초 걸렸습니다\n", time_gap);

		printf("\n컴퓨터 : ");
		
		for (int i = 1; i <= 30; i++)
		{
			if (i == 1)
				start = clock();
			
			printf("%d ", i);

			Sleep(com_time);
		}

		end = clock();

		double com_time_gap = (double)(end - start) / CLOCKS_PER_SEC;
		printf("\n%g초 걸렸습니다\n", com_time_gap);

		if (time_gap < 2.5)
		{
			lose++;
			printf("\n반칙입니다! 패배로 처리됩니다\n");
			printf("준비가 되셨다면 1을 입력해주세요\n");

			while (1)
			{
				scanf_s("%d", &select);

				if (select == 1)
					break;
				else
					printf("올바른 값을 입력해주세요!\n");
			}

			system("cls");
		}

		else if (time_gap < com_time_gap)
		{
			win++;
			printf("\n컴퓨터와의 승부에서 승리하였습니다!\n");
			printf("준비가 되셨다면 1을 입력해주세요\n");

			while (1)
			{
				scanf_s("%d", &select);

				if (select == 1)
					break;
				else
					printf("올바른 값을 입력해주세요!\n");
			}

			system("cls");
		}

		else
		{
			lose++;
			printf("\n컴퓨터와의 승부에서 패배하였습니다!\n");
			printf("준비가 되셨다면 1을 입력해주세요\n");

			while (1)
			{
				scanf_s("%d", &select);

				if (select == 1)
					break;
				else
					printf("올바른 값을 입력해주세요!\n");
			}

			system("cls");
		}
	}

	if (win == 2)
	{
		printf("축하합니다! 연타게임을 클리어하였습니다!\n");
		clear_roll++;

		printf("보상으로 메달 1개를 드립니다\n");
		medal++;

		printf("계속하시려면 1을 입력해주세요\n");
		printf("종료하시려면 아무 키나 입력해주세요\n");
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

	printf("============================흑과 백=============================\n");
	printf("   당신은 0부터 8까지 타일 중 하나를 선택하여 낼 수 있습니다   \n");
	printf("    컴퓨터 또한 0부터 8까지 타일 중 하나를 선택하여 냅니다    \n");
	printf("당신과 컴퓨터가 낸 타일중, 더 높은 숫자를 가진 사람이 승리합니다\n");
	printf("          한 번 낸 타일은 다시 재사용이 불가능합니다          \n");
	printf("   컴퓨터 낸 타일은 알 수 없는 대신, 그 타일이 홀수면 백색,   \n");
	printf("             그 타일이 짝수면 흑색으로 알려줍니다             \n");
	printf("     총 9번의 게임이 진행되며 선 플레이어는 돌아가며 됩니다    \n");
	printf("       컴퓨터와의 대결에서 승리하면 게임이 클리어됩니다       \n");
	printf("============================흑과 백=============================\n\n");

	for(i = 0; i < 9; i++)
	{
		printf("현재 스코어\n");
		printf("당신 : 컴퓨터 = %d : %d\n\n", win, lose);

		if (turn % 2 != 0)
		{
			printf("당신이 먼저 제시할 차례입니다\n");
			userturn(&user, user_tile, used_user_tile);
			comturn(&com, com_tile, used_com_tile);
		}

		else
		{
			printf("컴퓨터가 먼저 제시할 차례입니다\n");
			comturn(&com, com_tile, used_com_tile);
			userturn(&user, user_tile, used_user_tile);
		}

		printf("\n결과를 보려면 1을 입력해주세요\n");

		while (1)
		{
			scanf_s("%d", &select);

			if (select == 1)
				break;
			else
				printf("올바른 값을 입력해주세요!\n");
		}

		system("cls");

		if (user > com)
		{
			printf("당신의 승리\n\n");
			win++;
		}

		else if (user < com)
		{
			printf("컴퓨터의 승리\n\n");
			lose++;
		}

		else
			printf("비겼습니다\n\n");

		turn++;
	}

	if (win > lose)
	{
		system("cls");

		printf("축하합니다! 흑과 백을 클리어하였습니다!\n");
		clear_BAW++;

		printf("보상으로 메달 1개를 드립니다\n");
		medal++;

		printf("계속하시려면 1을 입력해주세요\n");
		printf("종료하시려면 아무 키나 입력해주세요\n");
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

		printf("비겼습니다. 한번 더 플레이합니다\n");
		printf("계속하려면 1을 입력해주세요\n");

		while (1)
		{
			scanf_s("%d", &select);

			if (select == 1)
				break;
			else
				printf("올바른 값을 입력해주세요!\n");
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
	printf("\n현재 당신의 타일 : \n");

	for (int j = 0; j < 9; j++)
		printf("%d ", user_tile[j]);

	printf("\n\n낼 타일의 숫자를 입력해주십시오 : ");

	while (1)
	{
		scanf_s("%d", &(*user));

		if (*user == used_user_tile[*user])
			printf("그 타일은 이미 사용했습니다!\n");

		else if (*user >= 0 && *user <= 8) 
		{
			used_user_tile[*user] = *user;
			break;
		}

		else
			printf("올바른 숫자를 입력해주세요!\n");
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
		printf("\n당신이 제시한 타일의 색은 *백색*입니다\n");

	else
		printf("\n당신이 제시한 타일의 색은 *흑색*입니다\n");
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
		printf("\n컴퓨터가 제시한 타일의 색은 *백색*입니다\n");

	else
		printf("\n컴퓨터가 제시한 타일의 색은 *흑색*입니다\n");
}

void BOSS()
{
	system("cls");

	Queue* queue = malloc(sizeof(Queue)); //큐 구조체 변수 선언
	queue->front = NULL; //큐에서 front를 초기화
	queue->rear = NULL; //큐에서 rear를 초기화

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
		printf("  *게임 타일*  \n");

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				printf("%3d", number[i][j]);
			printf("\n");
		}

		printf("\n도착 지점까지 %d칸 남았고,\n", torear);
		printf("\n탈락 지점까지 %d칸 남았습니다\n", tofront);

		printf("\n당신이 찾아야 할 다음 타일 : %c\n", you->data);

		printf("\n열어볼 타일의 번호를 입력하세요 : ");
		scanf_s("%d", &select);

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (select == number[i][j])
				{
					printf("\n%d 번 타일의 문자는 %c 입니다\n", number[i][j], alphabet[i][j]);
					
					if (alphabet[i][j] == you->data)
					{
						printf("\n맞추었습니다 한 칸 앞으로 전진합니다\n\n");
						you = you->next;
						torear--;
					}

					else
					{
						printf("\n틀렸습니다 컨베이어벨트가 한 칸 후진합니다\n");
						Enqueue(queue, rand() % 16 + 65);
						Dequeue(queue);
						torear++;
					}

					tofront = 19 - torear;

					printf("\n계속하시려면 1을 입력해주세요\n");

					while (1)
					{
						scanf_s("%d", &select);

						if (select == 1)
							break;
						else
							printf("올바른 값을 입력해주세요!\n");
					}

					system("cls");
				}
			}
	    }

		if (torear == 0)
		{
			system("cls");

			printf("축하합니다! 같은 그림 찾기를 클리어하였습니다!\n");
			clear_BOSS++;

			printf("계속하시려면 1을 입력해주세요\n");
			printf("종료하시려면 아무 키나 입력해주세요\n");
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
	Node* newNode = malloc(sizeof(Node)); //노드 생성
	newNode->data = data; //새로운 노드에 데이터를 저장
	newNode->next = NULL; //새로운 노드의 다음 노드는 없다 = 새 노드가 가장 아래에 배치됨

	if (empty(queue) == 1) //큐가 비어있다면
	{
		queue->front = newNode; //큐의 앞(꼭대기)노드는 새로운 노드이다 
		queue->rear = newNode;//큐의 뒤(맨 아래) 노드는 새로운 노드이다 
	}

	else //아니라면
	{
		queue->rear->next = newNode; //원래 큐의 뒤(맨 아래) 노드의 다음 노드는 새로운 노드이다
		queue->rear = newNode;//큐의 뒤(맨 아래) 노드는 새로운 노드이다 
	}
}

void Dequeue(Queue* queue)
{
	Node* newNode = malloc(sizeof(Node)); //노드 생성

	newNode = queue->front; //새로운 노드를 front노드로 설정
	queue->front = newNode->next; //기존의 front을 새 노드의 next로 설정

	free(newNode); //front가 된 새 노드의 할당 해제
}

int empty(Queue* queue)
{
	if (queue->front == NULL) //만약 front가 널값을 가진다면,
		return 1; //true반환

	else //아니면
		return 0; //false반환
}