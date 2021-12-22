#pragma once
//������ʵ�ַ���Game.cpp�ڣ�������ķ���ֵ����Game.cpp�еĹ���
#include "stdafx.h"

class Game {
public:
	// Ԥ������Ϸ�ļ�
	static void Loadgame();
	// ��Ϸ��ʼ
	static void Start();
	// �����Ϸ����
	static int gameover;
	// ��������
	typedef struct charactermove {
		bool isa;
		bool isAA;
		bool isJUMP;
		bool ismovl;
		bool ismovr;
		bool isQ;
		bool isE;
		int LorR;//����Ϊ1������Ϊ2
	}cmov;
	// ������ҵĽ�ɫ����
	static cmov character1;
	static cmov character2;
private:
	// ���������ѡ��Ľ�ɫ
	static int player_1;
	static int player_2;
	// ��־ѡ��ɫ�������д������Դﵽ�ظ�ʹ����ʵ���������ѡ�˵�Ŀ��         
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