#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
using namespace std;

void startView(); // 시작화면
void cardShuffle(); // 카드를 섞어줄 함수
void gamePlay(); // 진행화면
void endPage(); // 종료화면
void startView2();




char *card[52] = { "◆A", "◆2", "◆3", "◆4", "◆5", "◆6", "◆7", "◆8", "◆9", "◆10", "◆J", "◆Q", "◆K",
"♣A", "♣2", "♣3", "♣4", "♣5", "♣6", "♣7", "♣8", "♣9", "♣10", "♣J", "♣Q", "♣K",
"♠A", "♠2", "♠3", "♠4", "♠5", "♠6", "♠7", "♠8", "♠9", "♠10", "♠J", "♠Q", "♠K",
"♥A", "♥2", "♥3", "♥4", "♥5", "♥6", "♥7", "♥8", "♥9", "♥10", "♥J", "♥Q", "♥K" };

int cardResult[52];                  // 실질적인 하이 로우 세븐을 처리할 값을 저장할 배열
int money = 3000000;          // 보유 금액
int remainCard = 0;  // 진행하며 남은 카드를 확인할 변수
int inputKey;  // 첫화면에서 Enter 키를 입력을 받아야 다음을 진행하기 위해 사용된 변수로 사용되고 이후 하이로우세븐을 지정할 변수 ( Num1키 49 , Num2키 50 , Num3키 51 , ESC키 27)
int stage = 0;  // 스테이지 진행 및 보여줄 카드 확인을 위한 변수
int bMoney = 0;  // 배팅 금액

void main()

{
	//   카드 52장  
	//       하이 금액 * 2
	//       로우 금액 * 2
	//       세븐 금액 * 7
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
//스토리 적기
void startView2() {
	cout << endl;
	cout << "못난 아들을 둔 어머니가 암에 걸리셨다." << endl;
	cout << "못난 아들이 할 줄 아는 것이라고는 도박밖에 없다." << endl;
	cout << "그 중에서도 하이로우에서 몇 번 이름을 날린 적이 있다." << endl;
	cout << "아들은 어머니를 위해 중국에서 열리는 하이로우 페스티벌에 참가하게 된다." << endl;
	cout << "가진 것이라고는 300만원이지만 하나 밖에 없는 어머니의 수술비를 갚기 위해" << endl;
	cout << "아들은 먼 길을 떠난다." << endl;
	cout << "아들이 따야되는 돈은 7억원." << endl;
	cout << "과연 아들의 운명은?" << endl;
	while (1) {
		inputKey = _getch();
		if (inputKey == 32)			// SpaceBar 아스키코드
			break;
		else if (inputKey == 13)	// Enter 아스키코드
			break;
	}
}

void startView() {
	cout << endl;
	cout << " ┌──── HIGH & LOW 7 ────┐" << endl;
	cout << " │                              │" << endl;
	cout << " │                              │" << endl;
	cout << " │      G A M E  S T A R T      │" << endl;
	cout << " │                              │" << endl;
	cout << " │  P r e s s  S p a c e B a r  │" << endl;
	cout << " │                              │" << endl;
	cout << " │                              │" << endl;
	cout << " └───────────────┘" << endl;
	while (1) {
		inputKey = _getch();
		if (inputKey == 32)
			break;
	}
}

void cardShuffle() {
	int nNum1, nNum2; // 랜덤 숫자를 받을 변수
	if (remainCard == 0)
	{
		// 섞을 카드를 새로운 배열에 일단 초기화
		// 아래 if문은 해당 하이로우세븐을 구분할 값을 배열에 초기화
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

		// 카드 섞기
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
		cout << "★★★★★★★★★★★★★★★★★★★★★★★" << endl;
		cout << "판돈이 10배 입니다. 여기서 한 방을 노리십시오." << endl;
		cout << "★★★★★★★★★★★★★★★★★★★★★★★" << endl;
	}
	if (52 - remainCard == 10) {
		cout << "★★★★★★★★★★★★★★★★★★★★★★★" << endl;
		cout << "판돈이 10배 입니다. 여기서 한 방을 노리십시오." << endl;
		cout << "★★★★★★★★★★★★★★★★★★★★★★★" << endl;
	}
	if (52 - remainCard == 15) {
		cout << "★★★★★★★★★★★★★★★★★★★★★★★" << endl;
		cout << "판돈이 10배 입니다. 여기서 한 방을 노리십시오." << endl;
		cout << "★★★★★★★★★★★★★★★★★★★★★★★" << endl;
	}
	cout << " ┌──── HIGH & LOW 7 ────┐" << endl;
	if (remainCard > 9) {
		cout << " │  [  ?  ]       남은카드 : " << remainCard << " │" << endl;
	}
	else {
		cout << " │  [  ?  ]       남은카드 :  " << remainCard << " │" << endl;
	}
	cout << " │                              │" << endl;

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
	cout << " │                              │" << endl;
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
	cout << " │                              │" << endl;

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
	cout << " │                              │" << endl;
	cout << " │ 1. HIGH    2. LOW   3. SAME │" << endl;
	cout << " └───────────────┘" << endl;
	cout << " 배팅을 종료하시려면 ESC 키를 입력하세요" << endl;
	cout << " HIGH, LOW, SAME 을 선택하세요 ( 1, 2, 3 )" << endl;
	cout << " 보유 금액 : " << money << endl;

	while (1) {
		inputKey = _getch();
		if (inputKey == 49 || inputKey == 50 || inputKey == 51 || inputKey == 27)
			break;
	}
	if (inputKey == 49 || inputKey == 50 || inputKey == 51) {
		cout << " 배팅금액을 입력하세요 : ";
		cin >> bMoney;
		while (money < bMoney && bMoney > 0) {
			cout << " 배팅금액이 보유금액을 넘을 수 없습니다 " << endl;
			cout << " 배팅금액을 입력하세요 : ";
			cin >> bMoney;
		}
		int select = 0;  // 하이 로우 세븐 계산 변수
						 // 하이 로우 세븐 중 선택한 값을 선택
		if (inputKey == 49) {
			select = 1;
		}
		else if (inputKey == 50) {
			select = 2;
		}
		else {
			select = 3;
		}
		// 보유금액에서 배팅한 금액만큼 빼준다
		money -= bMoney;
		// 배팅에 성공 여부에 따른 계산 처리
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
		cout << " =========== 게임 종료 ===========" << endl;
		cout << "          파산하였습니다." << endl;
		cout << "          어머니는 돌아가셨습니다." << endl;
		system("pause");
	}
	else if (money >= 700000000) {
		cout << " =========== 게임 종료 ===========" << endl;
		cout << "아들이 " << money << "만큼 벌었습니다" << endl;
		cout << "아들이 어머니를 살렸습니다. 축하드립니다" << endl;
		system("pause");
		
	}
	else {
		cout << " =========== 게임 종료 ===========" << endl;
		cout << "      보유 금액 : " << money << endl;
		cout << "      어머니는 돌아가셨습니다." << endl;
		system("pause");
	}
}
