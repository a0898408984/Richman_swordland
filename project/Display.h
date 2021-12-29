#pragma once
#include"InputHandler.h"
#include"Game.h"
class Game;

class Display
{
public:
	Display(Game*, InputHandler*);
	~Display();

	void display0(); // 顯示所有狀態, 靜止狀態
	void display1(); // 骰下骰子後(骰子變化)
	void display2(int, int);  // 人物移動時 由a 到 b 動畫
	void display3(); // 買下土地(動畫
	void display4(); // 買下房子(動畫
	void display5(); // 付過路費(動畫
	void display6(); // 傳送動畫
	void display7(); // 任務卡動畫
	void display8(); // 加入微笑棺木動畫
	void display9(); // 加入血盟動畫
	void display10(); // 監獄動畫
	void display11(int); // 賣房子動畫
	void display12(); // 仍在監獄動畫
	void display13(); // 排名動畫

private:
	Game* ptrGame;
	InputHandler* ptrInput;
};

