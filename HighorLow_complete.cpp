#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
using namespace std;

void startView(); // ����ȭ��
void cardShuffle(); // ī�带 ������ �Լ�
void gamePlay(); // ����ȭ��
void endPage(); // ����ȭ��
void startView2();




char *card[52] = { "��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K",
"��A", "��2", "��3", "��4", "��5", "��6", "��7", "��8", "��9", "��10", "��J", "��Q", "��K" };

int cardResult[52];                  // �������� ���� �ο� ������ ó���� ���� ������ �迭
int money = 3000000;          // ���� �ݾ�
int remainCard = 0;  // �����ϸ� ���� ī�带 Ȯ���� ����
int inputKey;  // ùȭ�鿡�� Enter Ű�� �Է��� �޾ƾ� ������ �����ϱ� ���� ���� ������ ���ǰ� ���� ���̷ο켼���� ������ ���� ( Num1Ű 49 , Num2Ű 50 , Num3Ű 51 , ESCŰ 27)
int stage = 0;  // �������� ���� �� ������ ī�� Ȯ���� ���� ����
int bMoney = 0;  // ���� �ݾ�

void main()

{
	//   ī�� 52��  
	//       ���� �ݾ� * 2
	//       �ο� �ݾ� * 2
	//       ���� �ݾ� * 7
	srand((unsigned)time(NULL));
	startView2();
	startView();
	while (money > 0 && inputKey != 27) {
		cardShuffle();
		gamePlay();
		if (money >= 700000000) {
			return endPage();
		}
	}
	endPage();
}
//���丮 ����
void startView2() {
	cout << endl;
	cout << "���� �Ƶ��� �� ��Ӵϰ� �Ͽ� �ɸ��̴�." << endl;
	cout << "���� �Ƶ��� �� �� �ƴ� ���̶��� ���ڹۿ� ����." << endl;
	cout << "�� �߿����� ���̷ο쿡�� �� �� �̸��� ���� ���� �ִ�." << endl;
	cout << "�Ƶ��� ��Ӵϸ� ���� �߱����� ������ ���̷ο� �佺Ƽ���� �����ϰ� �ȴ�." << endl;
	cout << "���� ���̶��� 300���������� �ϳ� �ۿ� ���� ��Ӵ��� ������ ���� ����" << endl;
	cout << "�Ƶ��� �� ���� ������." << endl;
	cout << "�Ƶ��� ���ߵǴ� ���� 7���." << endl;
	cout << "���� �Ƶ��� �����?" << endl;
	while (1) {
		inputKey = _getch();
		if (inputKey == 32)			// SpaceBar �ƽ�Ű�ڵ�
			break;
		else if (inputKey == 13)	// Enter �ƽ�Ű�ڵ�
			break;
	}
}

void startView() {
	cout << endl;
	cout << " ���������� HIGH & LOW 7 ����������" << endl;
	cout << " ��                              ��" << endl;
	cout << " ��                              ��" << endl;
	cout << " ��      G A M E  S T A R T      ��" << endl;
	cout << " ��                              ��" << endl;
	cout << " ��  P r e s s  S p a c e B a r  ��" << endl;
	cout << " ��                              ��" << endl;
	cout << " ��                              ��" << endl;
	cout << " ����������������������������������" << endl;
	while (1) {
		inputKey = _getch();
		if (inputKey == 32)
			break;
	}
}

void cardShuffle() {
	int nNum1, nNum2; // ���� ���ڸ� ���� ����
	if (remainCard == 0)
	{
		// ���� ī�带 ���ο� �迭�� �ϴ� �ʱ�ȭ
		// �Ʒ� if���� �ش� ���̷ο켼���� ������ ���� �迭�� �ʱ�ȭ
		for (int i = 0; i < 52; i++) {
			if (i % 13 < 7) {
				cardResult[i] = 2;
			}
			else if (i % 13 == 7) {
				cardResult[i] = 3;
			}
			else {
				cardResult[i] = 1;
			}
		}

		// ī�� ����
		for (int i = 0; i < 1000; i++) {
			nNum1 = rand() % 52;
			nNum2 = rand() % 52;
			swap(card[nNum1], card[nNum2]);
			swap(cardResult[nNum1], cardResult[nNum2]);
		}
		remainCard = 51;
		stage = 0;

	}
}

void gamePlay() {
	system("cls");
	cout << endl;
	cout << "Stage : " << 52 - remainCard << endl;
	if (52 - remainCard == 5) {
		cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
		cout << "�ǵ��� 10�� �Դϴ�. ���⼭ �� ���� �븮�ʽÿ�." << endl;
		cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
	}
	if (52 - remainCard == 10) {
		cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
		cout << "�ǵ��� 10�� �Դϴ�. ���⼭ �� ���� �븮�ʽÿ�." << endl;
		cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
	}
	if (52 - remainCard == 15) {
		cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
		cout << "�ǵ��� 10�� �Դϴ�. ���⼭ �� ���� �븮�ʽÿ�." << endl;
		cout << "�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�" << endl;
	}
	cout << " ���������� HIGH & LOW 7 ����������" << endl;
	if (remainCard > 9) {
		cout << " ��  [  ?  ]       ����ī�� : " << remainCard << " ��" << endl;
	}
	else {
		cout << " ��  [  ?  ]       ����ī�� :  " << remainCard << " ��" << endl;
	}
	cout << " ��                              ��" << endl;

	if (stage - 1 >= 0) {
		cout << "     [ " << card[stage - 1] << " ]";
	}
	else {
		cout << "     [     ]";
	}
	if (stage - 2 >= 0) {
		cout << "   [ " << card[stage - 2] << " ]";
	}
	else {
		cout << "   [     ]";
	}
	if (stage - 3 >= 0) {
		cout << "   [ " << card[stage - 3] << " ]" << endl;
	}
	else {
		cout << "   [     ]" << endl;
	}
	cout << " ��                              ��" << endl;
	if (stage - 4 >= 0) {
		cout << "     [ " << card[stage - 4] << " ]";
	}
	else {
		cout << "     [     ]";
	}
	if (stage - 5 >= 0) {
		cout << "   [ " << card[stage - 5] << " ]";
	}
	else {
		cout << "   [     ]";
	}
	if (stage - 6 >= 0) {
		cout << "   [ " << card[stage - 6] << " ]" << endl;
	}
	else {
		cout << "   [     ]" << endl;
	}
	cout << " ��                              ��" << endl;

	if (stage - 7 >= 0) {
		cout << "     [ " << card[stage - 7] << " ]";
	}
	else {
		cout << "     [     ]";
	}
	if (stage - 8 >= 0) {
		cout << "   [ " << card[stage - 8] << " ]";
	}
	else {
		cout << "   [     ]";
	}
	if (stage - 9 >= 0) {
		cout << "   [ " << card[stage - 9] << " ]" << endl;
	}
	else {
		cout << "   [     ]" << endl;
	}
	cout << " ��                              ��" << endl;
	cout << " �� 1. HIGH    2. LOW   3. SAME ��" << endl;
	cout << " ����������������������������������" << endl;
	cout << " ������ �����Ͻ÷��� ESC Ű�� �Է��ϼ���" << endl;
	cout << " HIGH, LOW, SAME �� �����ϼ��� ( 1, 2, 3 )" << endl;
	cout << " ���� �ݾ� : " << money << endl;

	while (1) {
		inputKey = _getch();
		if (inputKey == 49 || inputKey == 50 || inputKey == 51 || inputKey == 27)
			break;
	}
	if (inputKey == 49 || inputKey == 50 || inputKey == 51) {
		cout << " ���ñݾ��� �Է��ϼ��� : ";
		cin >> bMoney;
		while (money < bMoney && bMoney > 0) {
			cout << " ���ñݾ��� �����ݾ��� ���� �� �����ϴ� " << endl;
			cout << " ���ñݾ��� �Է��ϼ��� : ";
			cin >> bMoney;
		}
		int select = 0;  // ���� �ο� ���� ��� ����
						 // ���� �ο� ���� �� ������ ���� ����
		if (inputKey == 49) {
			select = 1;
		}
		else if (inputKey == 50) {
			select = 2;
		}
		else {
			select = 3;
		}
		// �����ݾ׿��� ������ �ݾ׸�ŭ ���ش�
		money -= bMoney;
		// ���ÿ� ���� ���ο� ���� ��� ó��
		if (cardResult[stage] == select) {
			if (select == 1 || select == 2) {
				money = money + (bMoney * 2);
			}
			else {
				money = money + (bMoney * 7);
			}
		}
		if (stage == 4) {
			if (cardResult[stage] == select) {
				if (select == 1 || select == 2) {
					money = money + (bMoney * 10);
				}
				else {
					money = money + (bMoney * 70);
				}
			}
		}
		if (stage == 9) {
			if (cardResult[stage] == select) {
				if (select == 1 || select == 2) {
					money = money + (bMoney * 10);
				}
				else {
					money = money + (bMoney * 70);
				}
			}
		}
		if (stage == 14) {
			if (cardResult[stage] == select) {
				if (select == 1 || select == 2) {
					money = money + (bMoney * 10);
				}
				else {
					money = money + (bMoney * 70);
				}
			}
		}
		stage++;
		remainCard--;
	}
}

void endPage() {
	if (money == 0) {
		cout << " =========== ���� ���� ===========" << endl;
		cout << "          �Ļ��Ͽ����ϴ�." << endl;
		cout << "          ��Ӵϴ� ���ư��̽��ϴ�." << endl;
		system("pause");
	}
	else if (money >= 700000000) {
		cout << " =========== ���� ���� ===========" << endl;
		cout << "�Ƶ��� " << money << "��ŭ �������ϴ�" << endl;
		cout << "�Ƶ��� ��Ӵϸ� ��Ƚ��ϴ�. ���ϵ帳�ϴ�" << endl;
		system("pause");
		
	}
	else {
		cout << " =========== ���� ���� ===========" << endl;
		cout << "      ���� �ݾ� : " << money << endl;
		cout << "      ��Ӵϴ� ���ư��̽��ϴ�." << endl;
		system("pause");
	}
}
