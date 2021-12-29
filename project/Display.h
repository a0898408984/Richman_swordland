#pragma once
#include"InputHandler.h"
#include"Game.h"
class Game;

class Display
{
public:
	Display(Game*, InputHandler*);
	~Display();

	void display0(); // ��ܩҦ����A, �R��A
	void display1(); // ��U��l��(��l�ܤ�)
	void display2(int, int);  // �H�����ʮ� ��a �� b �ʵe
	void display3(); // �R�U�g�a(�ʵe
	void display4(); // �R�U�Фl(�ʵe
	void display5(); // �I�L���O(�ʵe
	void display6(); // �ǰe�ʵe
	void display7(); // ���ȥd�ʵe
	void display8(); // �[�J�L���ä�ʵe
	void display9(); // �[�J����ʵe
	void display10(); // �ʺ��ʵe
	void display11(int); // ��Фl�ʵe
	void display12(); // ���b�ʺ��ʵe
	void display13(); // �ƦW�ʵe

private:
	Game* ptrGame;
	InputHandler* ptrInput;
};

