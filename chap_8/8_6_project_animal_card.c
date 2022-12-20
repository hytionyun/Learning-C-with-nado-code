#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5]; //5장씩 4줄, 전역변수로 설정
char * strAnimal[10]; //동물 이름 배열
void initArray(); //배열에 모두 같은 수를 넣어주는 함수(카드의 뒷면은 모두 동일)
void initAnimalName(); //선언한 배열(strAnimal)에 동물 이름 저장
void suffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int checkAnimal[4][5]; //카드 뒷면, 앞면 확인 배열 선언
int foundAllAnimals(); //모든 동물을 다 찾았는지 알아내는 (checkAnimal[x][y] ==0 (뒤집히지 않음)없는지 확인)

int main (void){
	initArray();
	initAnimalName();
	suffleAnimal();
	srand(time(NULL)); // 난수 초기화
	int failCount = 0; //총 실패 횟수 선언 및 초기화
	while(1) { //게임이 끝날 때 까지 카드 지도, 문제는 계속 보여줘야 함
		int select1 = 0;
		int select2 = 0;
		printAnimals(); //카드 지도 출력 함수
		printQuestion(); //문제 출력 함수 
		//사용자의 카드 뽑기
		printf("카드 두 장을 고르세요(중복불가)\n");
		scanf("%d %d", &select1, &select2);
		if (select1 == select2) {
			continue; //같은 카드 선택 시 무효 처리 (반복문 시작 지점으로 돌아가기)
		}
		//입력받은 카드 번호를 x, y  좌표로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);
		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0 ) && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])){
			//두 카드가 모두 뒷면이고 같은 동물인 경우 
			printf("\n\n빙고! %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		} else {
			printf("\n\n땡! 서로 다른 동물 카드거나 이미 뒤집힌 카드입니다.\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n");
			failCount++; //실패 횟수 1 증가
		}
		if (foundAllAnimals() == 1){
			//모든 동물을 찾았는지 여부, 1: 참, 0: 거짓
			printf("\n\n축하합니다! 모든 동물을 찾았습니다!\n\n");
			printf("\n\n총 %d번 실패했습니다!\n\n", failCount);
			break;
		}
	}
	return 0;
}

void initArray(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			arrayAnimal[i][j] = -1 ;
		}
	}
}

void initAnimalName(){
	//strAnimal 배열의 인덱스는 각 동물 이름을 나타내는 번호로 쓰임 (0 == 원숭이, 9 == 호랑이...)
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void suffleAnimal(){
	for(int i = 0; i < 10; i++){ //이를 10번 반복
		for(int j = 0; j < 2; j++){ //동물 이름 카드 지도에 배치하는 작업 2번 반복
			int pos = getEmptyPosition();//..이때 카드 지도에서 빈공간 찾아야 하는데 이는 함수로 작성 (pos 변수에 할당)
			//카드 지도에서 빈공간 찾아 해당 위치 반환 (반환값 : 0~19의 지도 번호 중 빈공간 찾음)
			int x = conv_pos_x(pos); //2차원 배열은 x, y 좌표로 볼 수 있으므로 반환값을 인덱스로 환산해줄거임
			int y = conv_pos_y(pos);
			arrayAnimal[x][y] = i; //-1, -1 이었던 카드에 동물 이름 부여
		}
	}
}

int getEmptyPosition(){ //빈공간 번호를 반환해줄거임. 이는 arrayAnimal 배열에 빈공간 없을때까지 작동하는 무한루프
	//카드 배열 빈 공간 찾는 방법 : (1행)0~4/(2행)5~9/(...)10~14/(4행)15~19인 2차원 배열에 표의 칸마다 번호 붙여줌 -> 이 중 번호 하나 뽑아(rand함수 사용 -> 나온 숫자는 randPos 변수에 할당) 카드 지도에서 비었는지 확인(처음에 -1로 초기화해줬으므로 이를 검증)
	while (1){
		int randPos = rand() % 20; //무작위로 뽑은 카드 번호 반환(0~19)
		int x = conv_pos_x(randPos); //반환한 카드 번호 -> x좌표로 변환
		int y = conv_pos_y(randPos); //반환한 카드 번호 -> y좌표로 변환
		if (arrayAnimal[x][y] == -1){ //해당 위치가 비었는지 확인
			return randPos; //공간이 비었으면 공간 번호 반환
			// 이러한 반복 작업(x, y 좌표 구하기)을 줄이려면 반환형을 int가 아닌 구조체를 사용해야 합니다.
			// 그치만 아직 구조체를 배우지 않아서(현재 8단원, 다음 단원에서 배움) 여기서는 int를 넘기는 방식으로 작업했습니다.
		}

	}
}

//카드 섞기의 마지막 단계 : conv_pos_y, conv_pos_x 함수 정의
int conv_pos_x(int x){ //무작위로 뽑은 빈고간 번호를 좌표로 바꾸는 역할을 함
						//x좌표 == 빈공간 / 5, y좌표 == 빈공간 % 5
	return x / 5;
}
int conv_pos_y(int y){
	return y % 5;
}

//카드 뒤집어 보여주고 사용자에게 정답 입력받는 부분
//게임 시작 후 잠시동안 공간 지도를 출력해 어느 위치에 어떤 동물이 있는지 보여주기 : arrayAnimal에 동물 이름 배치했으므로 이 배열 값 출력
void printAnimals(){
	printf("\n============동물 위치를 보여줍니다.==============\n");
	//카드 뒤집기를 구현하기 어려우니 카드 뒷면을 공간 지도에 표시된 번호로 표시
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n===========================================\n");
	printQuestion();//번호를 골랐을 때 서로 일치하면 (앞면) 동물 이름을 표시, 아니면 그대로 (뒷면) 공간 번호 표시하기	
	
}

void printQuestion(){
	printf("\n====================문제====================\n");
	int seq = 0; //카드뒷면 번호를 담을 변수가 필요함
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			if (checkAnimal[i][j] != 0){ //해당 위치의 카드 앞뒷면 확인하는 배열(전역변수), checkAnimal 배열의 요소 값이 1이면 짝을 맞춘 상태고 0이면 짝을 맞추지 못한 상태임.
			//배열을 전역변수로 선언하면 모든 요소가 0(뒷면)으로 초기화되므로 따로 초기화할 필요는 없다.
			//카드가 앞면이면,
				printf("%8s", strAnimal[arrayAnimal[i][j]]); //동물이름 출력
		}	else { //뒷면이면
			printf("%8d", seq); //0 ~ 19 까지 증가하는 카드 뒷면 번호를 출력
		}
			seq++; //다음 카드로 넘어가기
		}
		printf("\n");
	}
}

int foundAllAnimals(){
	//카드 20장을 모두 확인해야 함.
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			if (checkAnimal[i][j] == 0){
				return 0; //뒤집지 않은 카드가 있음
			}
		}
	}
	return 1; //모든 카드 뒤집음
}