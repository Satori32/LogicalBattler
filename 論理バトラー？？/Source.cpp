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
	std::cout << "�_���o�g���[�I�I��";

	ESS::Locate(13, 14);
	std::cout << "Hit key to next.";

	return _getch() == 27 ? false:true;
}

bool ShowGame() {
	ESS::ClearShow();

	std::cout << "�ˑR�����A�ڂ̑O�ɓG�����ꂽ�B" << std::endl;
	std::size_t i = 0;
	for ( i= 1; i < 60; i++) {
		std::cout << "�ǂ��������H" << std::endl;
		std::this_thread::sleep_for(std::chrono::nanoseconds(8000000000 / i));
		int k=KeyHit();
		if (!k) {
			std::cout << "�܂��܂����邼�I" << std::endl;
		}
		else {
			std::cout << "���E���I" << std::endl;
			break;
		}
		if (k == 27) { return false; }
	}

	std::cout << "�G�́E�E�E�ǂ����E�E�E�H�H" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(4));
	ESS::ClearShow();

	std::cout << "�����B���O�A" << i << "�񂽂�ނꂽ�悤���ȁB" << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "��ŁA�ǂ��Ȃ����񂾁H" << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "���񂤂�B�������B" << std::endl << std::endl;	
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "���Ⴀ�A�邼�B" << std::endl << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));

	return true;
}

bool ShowEnd() {

	ESS::ClearShow();
	ESS::Locate(0, 0);

	std::cout << "����̃o�g���͂������ł������H" << std::endl;
	std::cout << "�y����ł�����������K���ł��B" << std::endl;
	std::cout << std::endl;
	std::cout << "�����ō�肽��������A������ǂ����B" << std::endl;
	std::cout << "https://amzn.to/2NcueSs"<<std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(8));

	std::cout << "�ł͂܂��B" << std::endl;
	return true;
}

int main() {
	SetDisplayMode();

	ESS::HideCursor();

	if (!ShowTitle()) return 0;
	if (!ShowGame()) return 0;
	ESS::ShowCursor();
	ShowEnd();

	std::cout << std::endl << "copyright 2019. �Ă���." << std::endl;

	return 0;




}