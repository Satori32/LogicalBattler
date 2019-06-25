#include <iostream>
#include <string>
#include <conio.h>
#include <thread>

#include "EscapeSequence.h"


int KeyHit() {
	if (_kbhit()) {
		return _getch();
	}

	return 0;
}

bool ShowTitle() {
	ESS::ClearShow();

	ESS::Locate(13, 8);
	std::cout << "論理バトラー！！α";

	ESS::Locate(13, 14);
	std::cout << "Hit key to next.";

	return _getch() == 27 ? false:true;
}

bool ShowGame() {
	ESS::ClearShow();

	std::cout << "突然だが、目の前に敵が現れた。" << std::endl;
	std::size_t i = 0;
	for ( i= 1; i < 60; i++) {
		std::cout << "どうしたい？" << std::endl;
		std::this_thread::sleep_for(std::chrono::nanoseconds(8000000000 / i));
		int k=KeyHit();
		if (!k) {
			std::cout << "まだまだくるぞ！" << std::endl;
		}
		else {
			std::cout << "限界だ！" << std::endl;
			break;
		}
		if (k == 27) { return false; }
	}

	std::cout << "敵は・・・どこだ・・・？？" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(4));
	ESS::ClearShow();

	std::cout << "おい。お前、" << i << "回たわむれたようだな。" << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "んで、どうなったんだ？" << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "うんうん。そうか。" << std::endl << std::endl;	
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "じゃあ帰るぞ。" << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));

	return true;
}

bool ShowEnd() {

	ESS::ClearShow();
	ESS::Locate(0, 0);

	std::cout << "今回のバトルはいかがでしたか？" << std::endl;
	std::cout << "楽しんでいただけたら幸いです。" << std::endl;
	std::cout << std::endl;
	std::cout << "自分で作りたかったら、これもどうぞ。" << std::endl;
	std::cout << "https://amzn.to/2NcueSs"<<std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(8));

	std::cout << "ではまた。" << std::endl;
	return true;
}

int main() {
	SetDisplayMode();

	ESS::HideCursor();

	if (!ShowTitle()) return 0;
	if (!ShowGame()) return 0;
	ESS::ShowCursor();
	ShowEnd();

	std::cout << std::endl << "copyright 2019. 焼き鳥." << std::endl;

	return 0;




}