#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <cstdio>

#include <list>

using namespace sf;
using namespace std;
// ����ͼƬ������ȡ���н�ɫ�����ֵ���������ȡ��
const int max_a = 8;
const int max_AA = 11;
const int max_E = 11;
const int max_JUMP = 8;
const int max_mov = 12;
const int max_Q = 15;
const int max_role = 3;
// �洢����ͼƬ�Ľṹ�壬ȫ�ֱ���
typedef struct roletexture {
	Texture standleft;
	Texture standright;
	Texture al[max_a];
	Texture ar[max_a];
	Texture AAl[max_AA];
	Texture AAr[max_AA];
	Texture El[max_E];
	Texture Er[max_E];
	Texture JUMPl[max_JUMP];
	Texture JUMPr[max_JUMP];
	Texture movl[max_mov];
	Texture movr[max_mov];
	Texture Q[max_Q];
}rol;
// ��ɫ���ԣ����ƶ��󣬽�ɫģ�͵������ƣ���Ϊ�Ѿ���Fight()����������
typedef struct jueseshuxing {
	int xueliang;
	int gongji;
}jssx;