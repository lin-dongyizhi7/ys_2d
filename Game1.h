#pragma once
//将功能实现放在Game.cpp内，其他类的返回值控制Game.cpp中的功能
#include "stdafx.h"

class Game {
public:
	// 预加载游戏文件
	static void Loadgame();
	// 游戏开始
	static void Start();
	// 监测游戏结束
	static int gameover;
	// 操作控制
	typedef struct charactermove {
		bool isa;
		bool isAA;
		bool isJUMP;
		bool ismovl;
		bool ismovr;
		bool isQ;
		bool isE;
		int LorR;//朝左为1，朝右为2
	}cmov;
	// 两个玩家的角色控制
	static cmov character1;
	static cmov character2;
private:
	// 保存两玩家选择的角色
	static int player_1;
	static int player_2;
	// 标志选角色函数运行次数，以达到重复使用来实现两个玩家选人的目的         
	static int flag_play;        
	static bool IsExiting();
	static void GameLoop();
	enum class GameState{Uninitialized,Exiting,ShowingMenu,Playing,Settinging,Intruduceing,Intruduce_a,Intruduce_b,Intruduce_c,Moreing,Music,Audio,GameStart,end};
	static GameState _gameState;
	static RenderWindow _mainWindow;
	static void ShowMenu();
	static void ShowMore();
	static void ShowIntruduce();
	static void ShowIntruduce_a();
	static void ShowIntruduce_b();
	static void ShowIntruduce_c();
	static void ShowSetting();
	static void ShowPlaying();
	static void Fight();
	static void end();
	static void Action1(Sprite& sprm, Sprite& spr1, Sprite& spr2, Sprite& spr3, Sprite& spr4);
	static void Action2(Sprite& sprm, Sprite& spr1, Sprite& spr2, Sprite& spr3, Sprite& spr4);
	static void cycle(Sprite sprmain, Sprite spr1, Sprite spr2, Sprite spr3, Sprite spr4);
};