#include "Game.h"
#include <math.h>
rol ROLE[max_role];
Music out[3];
Music e[3];
Music q[3];
Music music[3];
Time t = milliseconds(3000);
Time t1 = milliseconds(50);
Time t2 = milliseconds(20);
// 游戏预加载
void Game::Loadgame(void) {
	RenderWindow awindow;
	awindow.create(VideoMode(1600, 900), "JUSTWAIT");
	Texture tex_wait;
	Sprite spr_wait;
	tex_wait.loadFromFile("images/waiting.jpg");
	spr_wait.setTexture(tex_wait);
	spr_wait.setScale(Vector2f(0.83, 0.83));
	awindow.draw(spr_wait);
	awindow.display();
	// 载入所有角色的图片
	// KQ
	ROLE[0].standleft.loadFromFile("images/model/KQ/KQL.png");  // L
	ROLE[0].standright.loadFromFile("images/model/KQ/KQR.png"); // R
	// KQal
	ROLE[0].al[0].loadFromFile("images/model/KQ/a/L/1.png");
	ROLE[0].al[1].loadFromFile("images/model/KQ/a/L/2.png");
	ROLE[0].al[2].loadFromFile("images/model/KQ/a/L/3.png");
	ROLE[0].al[3].loadFromFile("images/model/KQ/a/L/4.png");
	ROLE[0].al[4].loadFromFile("images/model/KQ/a/L/5.png");
	// KQar
	ROLE[0].ar[0].loadFromFile("images/model/KQ/a/R/1.png");
	ROLE[0].ar[1].loadFromFile("images/model/KQ/a/R/2.png");
	ROLE[0].ar[2].loadFromFile("images/model/KQ/a/R/3.png");
	ROLE[0].ar[3].loadFromFile("images/model/KQ/a/R/4.png");
	ROLE[0].ar[4].loadFromFile("images/model/KQ/a/R/5.png");
	// KQAAl
	ROLE[0].AAl[0].loadFromFile("images/model/KQ/AA/L/1.png");
	ROLE[0].AAl[1].loadFromFile("images/model/KQ/AA/L/2.png");
	ROLE[0].AAl[2].loadFromFile("images/model/KQ/AA/L/3.png");
	ROLE[0].AAl[3].loadFromFile("images/model/KQ/AA/L/4.png");
	ROLE[0].AAl[4].loadFromFile("images/model/KQ/AA/L/5.png");
	ROLE[0].AAl[5].loadFromFile("images/model/KQ/AA/L/6.png");
	ROLE[0].AAl[6].loadFromFile("images/model/KQ/AA/L/7.png");
	ROLE[0].AAl[7].loadFromFile("images/model/KQ/AA/L/8.png");
	ROLE[0].AAl[8].loadFromFile("images/model/KQ/AA/L/9.png");
	ROLE[0].AAl[9].loadFromFile("images/model/KQ/AA/L/10.png");
	ROLE[0].AAl[10].loadFromFile("images/model/KQ/AA/L/11.png");
	// KQAAr
	ROLE[0].AAr[0].loadFromFile("images/model/KQ/AA/R/1.png");
	ROLE[0].AAr[1].loadFromFile("images/model/KQ/AA/R/2.png");
	ROLE[0].AAr[2].loadFromFile("images/model/KQ/AA/R/3.png");
	ROLE[0].AAr[3].loadFromFile("images/model/KQ/AA/R/4.png");
	ROLE[0].AAr[4].loadFromFile("images/model/KQ/AA/R/5.png");
	ROLE[0].AAr[5].loadFromFile("images/model/KQ/AA/R/6.png");
	ROLE[0].AAr[6].loadFromFile("images/model/KQ/AA/R/7.png");
	ROLE[0].AAr[7].loadFromFile("images/model/KQ/AA/R/8.png");
	ROLE[0].AAr[8].loadFromFile("images/model/KQ/AA/R/9.png");
	ROLE[0].AAr[9].loadFromFile("images/model/KQ/AA/R/10.png");
	ROLE[0].AAr[10].loadFromFile("images/model/KQ/AA/R/11.png");
	// KQEl
	ROLE[0].El[0].loadFromFile("images/model/KQ/E/L/1.png");
	ROLE[0].El[1].loadFromFile("images/model/KQ/E/L/2.png");
	ROLE[0].El[2].loadFromFile("images/model/KQ/E/L/3.png");
	ROLE[0].El[3].loadFromFile("images/model/KQ/E/L/4.png");
	ROLE[0].El[4].loadFromFile("images/model/KQ/E/L/5.png");
	ROLE[0].El[5].loadFromFile("images/model/KQ/E/L/6.png");
	ROLE[0].El[6].loadFromFile("images/model/KQ/E/L/7.png");
	ROLE[0].El[7].loadFromFile("images/model/KQ/E/L/8.png");
	ROLE[0].El[8].loadFromFile("images/model/KQ/E/L/9.png");
	ROLE[0].El[9].loadFromFile("images/model/KQ/E/L/10.png");
	ROLE[0].El[10].loadFromFile("images/model/KQ/E/L/11.png");
	// KQEr
	ROLE[0].Er[0].loadFromFile("images/model/KQ/E/R/1.png");
	ROLE[0].Er[1].loadFromFile("images/model/KQ/E/R/2.png");
	ROLE[0].Er[2].loadFromFile("images/model/KQ/E/R/3.png");
	ROLE[0].Er[3].loadFromFile("images/model/KQ/E/R/4.png");
	ROLE[0].Er[4].loadFromFile("images/model/KQ/E/R/5.png");
	ROLE[0].Er[5].loadFromFile("images/model/KQ/E/R/6.png");
	ROLE[0].Er[6].loadFromFile("images/model/KQ/E/R/7.png");
	ROLE[0].Er[7].loadFromFile("images/model/KQ/E/R/8.png");
	ROLE[0].Er[8].loadFromFile("images/model/KQ/E/R/9.png");
	ROLE[0].Er[9].loadFromFile("images/model/KQ/E/R/10.png");
	ROLE[0].Er[10].loadFromFile("images/model/KQ/E/R/11.png");
	// KQJUMPl
	ROLE[0].JUMPl[0].loadFromFile("images/model/KQ/JUMP/L/1.png");
	ROLE[0].JUMPl[1].loadFromFile("images/model/KQ/JUMP/L/2.png");
	ROLE[0].JUMPl[2].loadFromFile("images/model/KQ/JUMP/L/3.png");
	ROLE[0].JUMPl[3].loadFromFile("images/model/KQ/JUMP/L/4.png");
	ROLE[0].JUMPl[4].loadFromFile("images/model/KQ/JUMP/L/5.png");
	ROLE[0].JUMPl[5].loadFromFile("images/model/KQ/JUMP/L/6.png");
	ROLE[0].JUMPl[6].loadFromFile("images/model/KQ/JUMP/L/7.png");
	ROLE[0].JUMPl[7].loadFromFile("images/model/KQ/JUMP/L/8.png");
	// KQJUMPr
	ROLE[0].JUMPr[0].loadFromFile("images/model/KQ/JUMP/R/1.png");
	ROLE[0].JUMPr[1].loadFromFile("images/model/KQ/JUMP/R/2.png");
	ROLE[0].JUMPr[2].loadFromFile("images/model/KQ/JUMP/R/3.png");
	ROLE[0].JUMPr[3].loadFromFile("images/model/KQ/JUMP/R/4.png");
	ROLE[0].JUMPr[4].loadFromFile("images/model/KQ/JUMP/R/5.png");
	ROLE[0].JUMPr[5].loadFromFile("images/model/KQ/JUMP/R/6.png");
	ROLE[0].JUMPr[6].loadFromFile("images/model/KQ/JUMP/R/7.png");
	ROLE[0].JUMPr[7].loadFromFile("images/model/KQ/JUMP/R/8.png");
	// KQmovl
	ROLE[0].movl[0].loadFromFile("images/model/KQ/MOV/L/1.png");
	ROLE[0].movl[1].loadFromFile("images/model/KQ/MOV/L/2.png");
	ROLE[0].movl[2].loadFromFile("images/model/KQ/MOV/L/3.png");
	ROLE[0].movl[3].loadFromFile("images/model/KQ/MOV/L/4.png");
	ROLE[0].movl[4].loadFromFile("images/model/KQ/MOV/L/5.png");
	ROLE[0].movl[5].loadFromFile("images/model/KQ/MOV/L/6.png");
	ROLE[0].movl[6].loadFromFile("images/model/KQ/MOV/L/7.png");
	ROLE[0].movl[7].loadFromFile("images/model/KQ/MOV/L/8.png");
	ROLE[0].movl[8].loadFromFile("images/model/KQ/MOV/L/9.png");
	// KQmovr
	ROLE[0].movr[0].loadFromFile("images/model/KQ/MOV/R/1.png");
	ROLE[0].movr[1].loadFromFile("images/model/KQ/MOV/R/2.png");
	ROLE[0].movr[2].loadFromFile("images/model/KQ/MOV/R/3.png");
	ROLE[0].movr[3].loadFromFile("images/model/KQ/MOV/R/4.png");
	ROLE[0].movr[4].loadFromFile("images/model/KQ/MOV/R/5.png");
	ROLE[0].movr[5].loadFromFile("images/model/KQ/MOV/R/6.png");
	ROLE[0].movr[6].loadFromFile("images/model/KQ/MOV/R/7.png");
	ROLE[0].movr[7].loadFromFile("images/model/KQ/MOV/R/8.png");
	ROLE[0].movr[8].loadFromFile("images/model/KQ/MOV/R/9.png");
	// KQQ
	ROLE[0].Q[0].loadFromFile("images/model/KQ/Q/1.png");
	ROLE[0].Q[1].loadFromFile("images/model/KQ/Q/2.png");
	ROLE[0].Q[2].loadFromFile("images/model/KQ/Q/3.png");
	ROLE[0].Q[3].loadFromFile("images/model/KQ/Q/4.png");
	ROLE[0].Q[4].loadFromFile("images/model/KQ/Q/5.png");
	ROLE[0].Q[5].loadFromFile("images/model/KQ/Q/6.png");
	ROLE[0].Q[6].loadFromFile("images/model/KQ/Q/7.png");
	ROLE[0].Q[7].loadFromFile("images/model/KQ/Q/8.png");
	ROLE[0].Q[8].loadFromFile("images/model/KQ/Q/9.png");
	ROLE[0].Q[9].loadFromFile("images/model/KQ/Q/10.png");
	ROLE[0].Q[10].loadFromFile("images/model/KQ/Q/11.png");
	ROLE[0].Q[11].loadFromFile("images/model/KQ/Q/12.png");
	ROLE[0].Q[12].loadFromFile("images/model/KQ/Q/13.png");
	ROLE[0].Q[13].loadFromFile("images/model/KQ/Q/14.png");
	ROLE[0].Q[14].loadFromFile("images/model/KQ/Q/15.png");
	// DLK
	ROLE[1].standleft.loadFromFile("images/model/DLK/DLKL.png");  // L
	ROLE[1].standright.loadFromFile("images/model/DLK/DLKR.png"); // R
	// DLKal
	ROLE[1].al[0].loadFromFile("images/model/DLK/a/L/1.png");
	ROLE[1].al[1].loadFromFile("images/model/DLK/a/L/2.png");
	ROLE[1].al[2].loadFromFile("images/model/DLK/a/L/3.png");
	ROLE[1].al[3].loadFromFile("images/model/DLK/a/L/4.png");
	ROLE[1].al[4].loadFromFile("images/model/DLK/a/L/5.png");
	ROLE[1].al[5].loadFromFile("images/model/DLK/a/L/6.png");
	ROLE[1].al[6].loadFromFile("images/model/DLK/a/L/7.png");
	// DLKar
	ROLE[1].ar[0].loadFromFile("images/model/DLK/a/R/1.png");
	ROLE[1].ar[1].loadFromFile("images/model/DLK/a/R/2.png");
	ROLE[1].ar[2].loadFromFile("images/model/DLK/a/R/3.png");
	ROLE[1].ar[3].loadFromFile("images/model/DLK/a/R/4.png");
	ROLE[1].ar[4].loadFromFile("images/model/DLK/a/R/5.png");
	ROLE[1].ar[5].loadFromFile("images/model/DLK/a/R/6.png");
	ROLE[1].ar[6].loadFromFile("images/model/DLK/a/R/7.png");
	// DLKAAl
	ROLE[1].AAl[0].loadFromFile("images/model/DLK/AA/L/1.png");
	ROLE[1].AAl[1].loadFromFile("images/model/DLK/AA/L/2.png");
	ROLE[1].AAl[2].loadFromFile("images/model/DLK/AA/L/3.png");
	ROLE[1].AAl[3].loadFromFile("images/model/DLK/AA/L/4.png");
	ROLE[1].AAl[4].loadFromFile("images/model/DLK/AA/L/5.png");
	ROLE[1].AAl[5].loadFromFile("images/model/DLK/AA/L/6.png");
	ROLE[1].AAl[6].loadFromFile("images/model/DLK/AA/L/7.png");
	ROLE[1].AAl[7].loadFromFile("images/model/DLK/AA/L/8.png");
	ROLE[1].AAl[8].loadFromFile("images/model/DLK/AA/L/9.png");
	ROLE[1].AAl[9].loadFromFile("images/model/DLK/AA/L/10.png");
	// DLKAAr
	ROLE[1].AAr[0].loadFromFile("images/model/DLK/AA/R/1.png");
	ROLE[1].AAr[1].loadFromFile("images/model/DLK/AA/R/2.png");
	ROLE[1].AAr[2].loadFromFile("images/model/DLK/AA/R/3.png");
	ROLE[1].AAr[3].loadFromFile("images/model/DLK/AA/R/4.png");
	ROLE[1].AAr[4].loadFromFile("images/model/DLK/AA/R/5.png");
	ROLE[1].AAr[5].loadFromFile("images/model/DLK/AA/R/6.png");
	ROLE[1].AAr[6].loadFromFile("images/model/DLK/AA/R/7.png");
	ROLE[1].AAr[7].loadFromFile("images/model/DLK/AA/R/8.png");
	ROLE[1].AAr[8].loadFromFile("images/model/DLK/AA/R/9.png");
	ROLE[1].AAr[9].loadFromFile("images/model/DLK/AA/R/10.png");
	// DLKEl
	ROLE[1].El[0].loadFromFile("images/model/DLK/E/L/1.png");
	ROLE[1].El[1].loadFromFile("images/model/DLK/E/L/2.png");
	ROLE[1].El[2].loadFromFile("images/model/DLK/E/L/3.png");
	ROLE[1].El[3].loadFromFile("images/model/DLK/E/L/4.png");
	ROLE[1].El[4].loadFromFile("images/model/DLK/E/L/5.png");
	ROLE[1].El[5].loadFromFile("images/model/DLK/E/L/6.png");
	// DLKEr
	ROLE[1].Er[0].loadFromFile("images/model/DLK/E/R/1.png");
	ROLE[1].Er[1].loadFromFile("images/model/DLK/E/R/2.png");
	ROLE[1].Er[2].loadFromFile("images/model/DLK/E/R/3.png");
	ROLE[1].Er[3].loadFromFile("images/model/DLK/E/R/4.png");
	ROLE[1].Er[4].loadFromFile("images/model/DLK/E/R/5.png");
	ROLE[1].Er[5].loadFromFile("images/model/DLK/E/R/6.png");
	// DLKJUMPl
	ROLE[1].JUMPl[0].loadFromFile("images/model/DLK/JUMP/L/1.png");
	ROLE[1].JUMPl[1].loadFromFile("images/model/DLK/JUMP/L/2.png");
	ROLE[1].JUMPl[2].loadFromFile("images/model/DLK/JUMP/L/3.png");
	ROLE[1].JUMPl[3].loadFromFile("images/model/DLK/JUMP/L/4.png");
	ROLE[1].JUMPl[4].loadFromFile("images/model/DLK/JUMP/L/5.png");
	ROLE[1].JUMPl[5].loadFromFile("images/model/DLK/JUMP/L/6.png");
	ROLE[1].JUMPl[6].loadFromFile("images/model/DLK/JUMP/L/7.png");
	ROLE[1].JUMPl[7].loadFromFile("images/model/DLK/JUMP/L/8.png");
	// DLKJUMPr
	ROLE[1].JUMPr[0].loadFromFile("images/model/DLK/JUMP/R/1.png");
	ROLE[1].JUMPr[1].loadFromFile("images/model/DLK/JUMP/R/2.png");
	ROLE[1].JUMPr[2].loadFromFile("images/model/DLK/JUMP/R/3.png");
	ROLE[1].JUMPr[3].loadFromFile("images/model/DLK/JUMP/R/4.png");
	ROLE[1].JUMPr[4].loadFromFile("images/model/DLK/JUMP/R/5.png");
	ROLE[1].JUMPr[5].loadFromFile("images/model/DLK/JUMP/R/6.png");
	ROLE[1].JUMPr[6].loadFromFile("images/model/DLK/JUMP/R/7.png");
	ROLE[1].JUMPr[7].loadFromFile("images/model/DLK/JUMP/R/8.png");
	// DLKMOVl
	ROLE[1].movl[0].loadFromFile("images/model/DLK/MOV/L/1.png");
	ROLE[1].movl[1].loadFromFile("images/model/DLK/MOV/L/2.png");
	ROLE[1].movl[2].loadFromFile("images/model/DLK/MOV/L/3.png");
	ROLE[1].movl[3].loadFromFile("images/model/DLK/MOV/L/4.png");
	ROLE[1].movl[4].loadFromFile("images/model/DLK/MOV/L/5.png");
	ROLE[1].movl[5].loadFromFile("images/model/DLK/MOV/L/6.png");
	ROLE[1].movl[6].loadFromFile("images/model/DLK/MOV/L/7.png");
	ROLE[1].movl[7].loadFromFile("images/model/DLK/MOV/L/8.png");
	ROLE[1].movl[8].loadFromFile("images/model/DLK/MOV/L/9.png");
	ROLE[1].movl[9].loadFromFile("images/model/DLK/MOV/L/10.png");
	ROLE[1].movl[10].loadFromFile("images/model/DLK/MOV/L/11.png");
	ROLE[1].movl[11].loadFromFile("images/model/DLK/MOV/L/12.png");
	// DLKMOVr
	ROLE[1].movr[0].loadFromFile("images/model/DLK/MOV/R/1.png");
	ROLE[1].movr[1].loadFromFile("images/model/DLK/MOV/R/2.png");
	ROLE[1].movr[2].loadFromFile("images/model/DLK/MOV/R/3.png");
	ROLE[1].movr[3].loadFromFile("images/model/DLK/MOV/R/4.png");
	ROLE[1].movr[4].loadFromFile("images/model/DLK/MOV/R/5.png");
	ROLE[1].movr[5].loadFromFile("images/model/DLK/MOV/R/6.png");
	ROLE[1].movr[6].loadFromFile("images/model/DLK/MOV/R/7.png");
	ROLE[1].movr[7].loadFromFile("images/model/DLK/MOV/R/8.png");
	ROLE[1].movr[8].loadFromFile("images/model/DLK/MOV/R/9.png");
	ROLE[1].movr[9].loadFromFile("images/model/DLK/MOV/R/10.png");
	ROLE[1].movr[10].loadFromFile("images/model/DLK/MOV/R/11.png");
	ROLE[1].movr[11].loadFromFile("images/model/DLK/MOV/R/12.png");
	// DLKQ
	ROLE[1].Q[0].loadFromFile("images/model/DLK/Q/1.png");
	ROLE[1].Q[1].loadFromFile("images/model/DLK/Q/2.png");
	ROLE[1].Q[2].loadFromFile("images/model/DLK/Q/3.png");
	ROLE[1].Q[3].loadFromFile("images/model/DLK/Q/4.png");
	ROLE[1].Q[4].loadFromFile("images/model/DLK/Q/5.png");
	ROLE[1].Q[5].loadFromFile("images/model/DLK/Q/6.png");
	ROLE[1].Q[6].loadFromFile("images/model/DLK/Q/7.png");
	ROLE[1].Q[7].loadFromFile("images/model/DLK/Q/8.png");
	ROLE[1].Q[8].loadFromFile("images/model/DLK/Q/9.png");
	ROLE[1].Q[9].loadFromFile("images/model/DLK/Q/10.png");
	// HT
	ROLE[2].standleft.loadFromFile("images/model/HT/HTL.png");  // L
	ROLE[2].standright.loadFromFile("images/model/HT/HTR.png"); // R
	// HTl
	ROLE[2].al[0].loadFromFile("images/model/HT/a/L/1.png");
	ROLE[2].al[1].loadFromFile("images/model/HT/a/L/2.png");
	ROLE[2].al[2].loadFromFile("images/model/HT/a/L/3.png");
	ROLE[2].al[3].loadFromFile("images/model/HT/a/L/4.png");
	ROLE[2].al[4].loadFromFile("images/model/HT/a/L/5.png");
	ROLE[2].al[5].loadFromFile("images/model/HT/a/L/6.png");
	ROLE[2].al[6].loadFromFile("images/model/HT/a/L/7.png");
	ROLE[2].al[7].loadFromFile("images/model/HT/a/L/8.png");
	// HTar
	ROLE[2].ar[0].loadFromFile("images/model/HT/a/R/1.png");
	ROLE[2].ar[1].loadFromFile("images/model/HT/a/R/2.png");
	ROLE[2].ar[2].loadFromFile("images/model/HT/a/R/3.png");
	ROLE[2].ar[3].loadFromFile("images/model/HT/a/R/4.png");
	ROLE[2].ar[4].loadFromFile("images/model/HT/a/R/5.png");
	ROLE[2].ar[5].loadFromFile("images/model/HT/a/R/6.png");
	ROLE[2].ar[6].loadFromFile("images/model/HT/a/R/7.png");
	ROLE[2].ar[7].loadFromFile("images/model/HT/a/R/8.png");
	// HTAAl
	ROLE[2].AAl[0].loadFromFile("images/model/HT/AA/L/1.png");
	ROLE[2].AAl[1].loadFromFile("images/model/HT/AA/L/2.png");
	ROLE[2].AAl[2].loadFromFile("images/model/HT/AA/L/3.png");
	ROLE[2].AAl[3].loadFromFile("images/model/HT/AA/L/4.png");
	ROLE[2].AAl[4].loadFromFile("images/model/HT/AA/L/5.png");
	// HTAAr
	ROLE[2].AAr[0].loadFromFile("images/model/HT/AA/R/1.png");
	ROLE[2].AAr[1].loadFromFile("images/model/HT/AA/R/2.png");
	ROLE[2].AAr[2].loadFromFile("images/model/HT/AA/R/3.png");
	ROLE[2].AAr[3].loadFromFile("images/model/HT/AA/R/4.png");
	ROLE[2].AAr[4].loadFromFile("images/model/HT/AA/R/5.png");
	// HTEl
	ROLE[2].El[0].loadFromFile("images/model/HT/E/L/1.png");
	ROLE[2].El[1].loadFromFile("images/model/HT/E/L/2.png");
	ROLE[2].El[2].loadFromFile("images/model/HT/E/L/3.png");
	ROLE[2].El[3].loadFromFile("images/model/HT/E/L/4.png");
	ROLE[2].El[4].loadFromFile("images/model/HT/E/L/5.png");
	ROLE[2].El[5].loadFromFile("images/model/HT/E/L/6.png");
	ROLE[2].El[6].loadFromFile("images/model/HT/E/L/7.png");
	// HTEr
	ROLE[2].Er[0].loadFromFile("images/model/HT/E/R/1.png");
	ROLE[2].Er[1].loadFromFile("images/model/HT/E/R/2.png");
	ROLE[2].Er[2].loadFromFile("images/model/HT/E/R/3.png");
	ROLE[2].Er[3].loadFromFile("images/model/HT/E/R/4.png");
	ROLE[2].Er[4].loadFromFile("images/model/HT/E/R/5.png");
	ROLE[2].Er[5].loadFromFile("images/model/HT/E/R/6.png");
	ROLE[2].Er[6].loadFromFile("images/model/HT/E/R/7.png");
	// HTJUMPl
	ROLE[2].JUMPl[0].loadFromFile("images/model/HT/JUMP/L/1.png");
	ROLE[2].JUMPl[1].loadFromFile("images/model/HT/JUMP/L/2.png");
	ROLE[2].JUMPl[2].loadFromFile("images/model/HT/JUMP/L/3.png");
	ROLE[2].JUMPl[3].loadFromFile("images/model/HT/JUMP/L/4.png");
	ROLE[2].JUMPl[4].loadFromFile("images/model/HT/JUMP/L/5.png");
	ROLE[2].JUMPl[5].loadFromFile("images/model/HT/JUMP/L/6.png");
	ROLE[2].JUMPl[6].loadFromFile("images/model/HT/JUMP/L/7.png");
	ROLE[2].JUMPl[7].loadFromFile("images/model/HT/JUMP/L/8.png");
	// HTJUMPr
	ROLE[2].JUMPr[0].loadFromFile("images/model/HT/JUMP/R/1.png");
	ROLE[2].JUMPr[1].loadFromFile("images/model/HT/JUMP/R/2.png");
	ROLE[2].JUMPr[2].loadFromFile("images/model/HT/JUMP/R/3.png");
	ROLE[2].JUMPr[3].loadFromFile("images/model/HT/JUMP/R/4.png");
	ROLE[2].JUMPr[4].loadFromFile("images/model/HT/JUMP/R/5.png");
	ROLE[2].JUMPr[5].loadFromFile("images/model/HT/JUMP/R/6.png");
	ROLE[2].JUMPr[6].loadFromFile("images/model/HT/JUMP/R/7.png");
	ROLE[2].JUMPr[7].loadFromFile("images/model/HT/JUMP/R/8.png");
	// HTmovl
	ROLE[2].movl[0].loadFromFile("images/model/HT/MOV/L/1.png");
	ROLE[2].movl[1].loadFromFile("images/model/HT/MOV/L/2.png");
	ROLE[2].movl[2].loadFromFile("images/model/HT/MOV/L/3.png");
	ROLE[2].movl[3].loadFromFile("images/model/HT/MOV/L/4.png");
	ROLE[2].movl[4].loadFromFile("images/model/HT/MOV/L/5.png");
	ROLE[2].movl[5].loadFromFile("images/model/HT/MOV/L/6.png");
	ROLE[2].movl[6].loadFromFile("images/model/HT/MOV/L/7.png");
	ROLE[2].movl[7].loadFromFile("images/model/HT/MOV/L/8.png");
	ROLE[2].movl[8].loadFromFile("images/model/HT/MOV/L/9.png");
	ROLE[2].movl[9].loadFromFile("images/model/HT/MOV/L/10.png");
	ROLE[2].movl[10].loadFromFile("images/model/HT/MOV/L/11.png");
	ROLE[2].movl[11].loadFromFile("images/model/HT/MOV/L/12.png");
	// HTmovr
	ROLE[2].movr[0].loadFromFile("images/model/HT/MOV/R/1.png");
	ROLE[2].movr[1].loadFromFile("images/model/HT/MOV/R/2.png");
	ROLE[2].movr[2].loadFromFile("images/model/HT/MOV/R/3.png");
	ROLE[2].movr[3].loadFromFile("images/model/HT/MOV/R/4.png");
	ROLE[2].movr[4].loadFromFile("images/model/HT/MOV/R/5.png");
	ROLE[2].movr[5].loadFromFile("images/model/HT/MOV/R/6.png");
	ROLE[2].movr[6].loadFromFile("images/model/HT/MOV/R/7.png");
	ROLE[2].movr[7].loadFromFile("images/model/HT/MOV/R/8.png");
	ROLE[2].movr[8].loadFromFile("images/model/HT/MOV/R/9.png");
	ROLE[2].movr[9].loadFromFile("images/model/HT/MOV/R/10.png");
	ROLE[2].movr[10].loadFromFile("images/model/HT/MOV/R/11.png");
	ROLE[2].movr[11].loadFromFile("images/model/HT/MOV/R/12.png");
	// HTQ
	ROLE[2].Q[0].loadFromFile("images/model/HT/Q/1.png");
	ROLE[2].Q[1].loadFromFile("images/model/HT/Q/2.png");
	ROLE[2].Q[2].loadFromFile("images/model/HT/Q/3.png");
	ROLE[2].Q[3].loadFromFile("images/model/HT/Q/4.png");
	ROLE[2].Q[4].loadFromFile("images/model/HT/Q/5.png");
	ROLE[2].Q[5].loadFromFile("images/model/HT/Q/6.png");
	ROLE[2].Q[6].loadFromFile("images/model/HT/Q/7.png");
	ROLE[2].Q[7].loadFromFile("images/model/HT/Q/8.png");
	ROLE[2].Q[8].loadFromFile("images/model/HT/Q/9.png");
	ROLE[2].Q[9].loadFromFile("images/model/HT/Q/10.png");
	ROLE[2].Q[10].loadFromFile("images/model/HT/Q/11.png");
	ROLE[2].Q[11].loadFromFile("images/model/HT/Q/12.png");
	ROLE[2].Q[12].loadFromFile("images/model/HT/Q/13.png");
	ROLE[2].Q[13].loadFromFile("images/model/HT/Q/14.png");
	ROLE[2].Q[14].loadFromFile("images/model/HT/Q/15.png");
	awindow.close();

	//载入语音，音乐
	music[0].openFromFile("music/music1.wav");
	music[0].setLoop(true);
	music[1].openFromFile("music/music2.wav");
}
// 游戏初始化
void Game::Start(void) {
	if (_gameState != GameState::Uninitialized) {
		return;
	}
	gameover = 0;
	_mainWindow.create(VideoMode(1600, 900), "Genshin_Impact");
	_gameState = Game::GameState::ShowingMenu;
	flag_play = 0;              // 初始化，意为未完成第一次选角色
	player_1 = -1;
	player_2 = -1;               // 还未选择
	while (!IsExiting()) {
		GameLoop();
	}
	_mainWindow.close();
}

bool Game::IsExiting() {
	if (_gameState == Game::GameState::Exiting) {
		music[0].stop();
		music[1].stop();
		music[2].stop();
		return true;
	}
	else {
		return false;
	}
}
//游戏主体循环
void Game::GameLoop() {
	Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent)) {
		switch (_gameState)
		{
		case Game::GameState::Playing: {
			ShowPlaying();
			break;
		}
		case Game::GameState::Intruduceing: {
			ShowIntruduce();
			break;
		}
		case Game::GameState::Settinging: {
			ShowSetting();        
			break;
		}
		case Game::GameState::Moreing: {
			ShowMore();
			break;
		}
		case Game::GameState::ShowingMenu: {
			ShowMenu();           
			break;
		}
		case Game::GameState::Intruduce_a: {
			ShowIntruduce_a();
			break;
		}
		case Game::GameState::Intruduce_b: {
			ShowIntruduce_b();
			break;
		}
		case Game::GameState::Intruduce_c: {
			ShowIntruduce_c();
			break;
		}
		case Game::GameState::Music: {
			//在这里更改音乐，然后刷新设置界面
			ShowSetting();
			break;
		}
		case Game::GameState::Audio: {
			//在这里更改音效，然后刷新设置界面
			ShowSetting();
			break;
		}
		case Game::GameState::GameStart: {
			Fight();
			break;
		}
		case Game::GameState::end: {
			end();
			break;
		}
		}
	}
}
//主菜单界面
void Game::ShowMenu() {
	music[0].play();
	Texture image;
	image.loadFromFile("images/HomePage.png");
	Sprite sprite;
	sprite.setTexture(image);
	sprite.setScale(Vector2f(0.89, 0.89));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen() ){
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 717
					&& event.mouseButton.x < 884
					&& event.mouseButton.y > 387
					&& event.mouseButton.y < 428) {
					music[0].stop();
					music[1].play();
					_gameState = GameState::Playing;
					return;
				}
				if (event.mouseButton.x > 717
					&& event.mouseButton.x < 884
					&& event.mouseButton.y > 483
					&& event.mouseButton.y < 524) {
					_gameState = GameState::Intruduceing;
					return;
				}
				if (event.mouseButton.x > 717
					&& event.mouseButton.x < 884
					&& event.mouseButton.y > 579
					&& event.mouseButton.y < 620) {
					_gameState = GameState::Settinging;
					return;
				}
				if (event.mouseButton.x > 717
					&& event.mouseButton.x < 884
					&& event.mouseButton.y > 675
					&& event.mouseButton.y < 716) {
					_gameState = GameState::Moreing;
					return;
				}
				if (event.mouseButton.x > 717
					&& event.mouseButton.x < 884
					&& event.mouseButton.y > 771
					&& event.mouseButton.y < 812) {
					_mainWindow.close();
				}
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//介绍
void Game::ShowIntruduce() {
	Texture image;
	image.loadFromFile("images/about.png");
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.22, 1.22));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 25
					&& event.mouseButton.x < 103
					&& event.mouseButton.y > 23
					&& event.mouseButton.y < 66) {
					_gameState = GameState::ShowingMenu;
					return;
				}
				if (event.mouseButton.x > 16
					&& event.mouseButton.x < 268
					&& event.mouseButton.y > 137
					&& event.mouseButton.y < 282) {
					_gameState = GameState::Intruduce_a;
					return;
				}
				if (event.mouseButton.x > 16
					&& event.mouseButton.x < 268
					&& event.mouseButton.y > 378
					&& event.mouseButton.y < 523) {
					_gameState = GameState::Intruduce_b;
					return;
				}
				if (event.mouseButton.x > 16
					&& event.mouseButton.x < 268
					&& event.mouseButton.y > 619
					&& event.mouseButton.y < 764 ){
					_gameState = GameState::Intruduce_c;
						return;
				}
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//更多
void Game::ShowMore() {
	Texture image;
	image.loadFromFile("images/more.png");
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.22, 1.22));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen() ){
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 25
					&& event.mouseButton.x < 103
					&& event.mouseButton.y > 23
					&& event.mouseButton.y < 66) {
					_gameState = GameState::ShowingMenu;
					return;
				}
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//游戏介绍
void Game::ShowIntruduce_a() {
	Texture image;
	image.loadFromFile("images/aboutGame.png");
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.22, 1.22));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 25
					&& event.mouseButton.x < 103
					&& event.mouseButton.y > 23
					&& event.mouseButton.y < 66) {
					_gameState = GameState::Intruduceing;
					return;
				}
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//操作方法
void Game::ShowIntruduce_b() {
	Texture image;
	image.loadFromFile("images/aboutUse.png");
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.22, 1.22));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 25
					&& event.mouseButton.x < 103
					&& event.mouseButton.y > 23
					&& event.mouseButton.y < 66) {
					_gameState = GameState::Intruduceing;
					return;
				}
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//角色介绍
void Game::ShowIntruduce_c() {
	Texture image;
	image.loadFromFile("images/aboutCharacter.png");
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.22, 1.22));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 25
					&& event.mouseButton.x < 103
					&& event.mouseButton.y > 23
					&& event.mouseButton.y < 66) {
					_gameState = GameState::Intruduceing;
					return;
				}
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//设置界面
void Game::ShowSetting() {
	Texture image;
	image.loadFromFile("images/set.png");
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.36, 1.36));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 25
					&& event.mouseButton.x < 103
					&& event.mouseButton.y > 23
					&& event.mouseButton.y < 66) {
					_gameState = GameState::ShowingMenu;
					return;
				}
// 暂不设置该项功能，返回Nothing
				/*if (event.mouseButton.x > 16
					&& event.mouseButton.x < 268
					&& event.mouseButton.y > 137
					&& event.mouseButton.y < 282) {
					_gameState = GameState::Music;
					return;
				}
				if (event.mouseButton.x > 16
					&& event.mouseButton.x < 268
					&& event.mouseButton.y > 378
					&& event.mouseButton.y < 523) {
					_gameState = GameState::Audio;
					return;
				}*/
			}
			else if (event.type == Event::Closed) {
				_mainWindow.close();
			}
		}
	}
}
//开始
void Game::ShowPlaying() {
	int c[3];                                 // 判断选择的是哪一个角色
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	Texture image;
	if (flag_play == 0) {
		image.loadFromFile("images/character_1.png"); 
	}
	if (flag_play == 1) {
		image.loadFromFile("images/character_2.png");     // 两个玩家选择角色当然要有点不同，至少要改改提示语
	}
	Sprite sprite(image);
	sprite.setScale(Vector2f(1.22, 1.22));

	_mainWindow.clear();
	_mainWindow.draw(sprite);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 207
					&& event.mouseButton.x < 447
					&& event.mouseButton.y > 238                  
					&& event.mouseButton.y < 598) {
					c[0] = 1;
					c[1] = 0;
					c[2] = 0;
					out[0].openFromFile("sound/KQ1.wav");
					out[0].play();
				}
				if (event.mouseButton.x > 679
					&& event.mouseButton.x < 919
					&& event.mouseButton.y > 238
					&& event.mouseButton.y < 598) {
					c[0] = 0;
					c[1] = 1;
					c[2] = 0;
					out[1].openFromFile("sound/DLK1.wav");
					out[1].play();
				}
				if (event.mouseButton.x > 1151
					&& event.mouseButton.x < 1391
					&& event.mouseButton.y > 238
					&& event.mouseButton.y < 598) {
					c[0] = 0;
					c[1] = 0;
					c[2] = 1;
					out[2].openFromFile("sound/HT1.wav");
					out[2].play();
				}
				if (event.mouseButton.x > 629                               // 确定按钮
					&& event.mouseButton.x < 972
					&& event.mouseButton.y > 755
					&& event.mouseButton.y < 827) {
					if (c[0] == 1 || c[1] == 1 || c[2] == 1) {
						if (flag_play == 0) {                               // 第一次进入
							flag_play = 1;
							for (int i = 0; i < 3; i++) {
								if (c[i] == 1) {
									player_1 = i + 1;
								}
							}
							_gameState = GameState::Playing;
							return;
						}
						if (flag_play == 1) {
							flag_play = 0;
							for (int i = 0; i < 3; i++) {
								if (c[i] == 1) {
									player_2 = i + 1;
								}
							}
							_gameState = GameState::GameStart;              // 第二次进入，开始游戏
							return;
						}
					}
				}
			}
			else if (event.type == Event::Closed) {
				music[2].stop();
				_mainWindow.close();
			}
		}
	}
}
//结束
void Game::end() {
	music[2].stop();
	Texture end;
	Sprite sprmain;
	end.loadFromFile("images/end.png");
	sprmain.setTexture(end);
	_mainWindow.clear();
	_mainWindow.draw(sprmain);
	_mainWindow.display();

	Event event;
	while (_mainWindow.isOpen()) {
		while (_mainWindow.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.x > 693
					&& event.mouseButton.x <913 
					&& event.mouseButton.y > 435
					&& event.mouseButton.y < 503) {
					_gameState = GameState::ShowingMenu;
					return;
				}
				if (event.mouseButton.x > 693
					&& event.mouseButton.x < 913
					&& event.mouseButton.y > 544
					&& event.mouseButton.y < 612) {
					_gameState = GameState::Exiting;
					return;
				}
				else continue;
			}
		}
	}
}
void Game::cycle(Sprite sprmain, Sprite spr1, Sprite spr2, Sprite spr3, Sprite spr4) {
	_mainWindow.clear();
	_mainWindow.draw(sprmain);
	_mainWindow.draw(spr1);
	_mainWindow.draw(spr2);
	_mainWindow.draw(spr3);
	_mainWindow.draw(spr4);
	_mainWindow.display();
}
void Game::Fight() {
	music[1].stop();
	music[2].openFromFile("music/music3.wav");
	music[2].play();
	_mainWindow.clear();
	Texture texmain;
	Texture tex_1;
	Texture tex_2;
	Sprite sprmain;
	Sprite spr_1;
	spr_1.setTextureRect(IntRect(0, 0, 2160, 1215));
	spr_1.setScale(Vector2f(0.74, 0.74));
	Sprite spr_2;
	spr_2.setTextureRect(IntRect(0, 0, 2160, 1215));
	spr_2.setScale(Vector2f(0.74, 0.74));
	texmain.loadFromFile("images/nantianmen.jpg");
	sprmain.setTexture(texmain);
	if (player_1 == 1) {
		spr_1.setTexture(ROLE[0].standright);
	}
	else if (player_1 == 2) {
		spr_1.setTexture(ROLE[1].standright);
	}
	else if (player_1 == 3) {
		spr_1.setTexture(ROLE[2].standright);
	}
	if (player_2 == 1) {
		spr_2.setTexture(ROLE[0].standleft);
	}
	else if (player_2 == 2) {
		spr_2.setTexture(ROLE[1].standleft);
	}
	else if (player_2 == 3) {
		spr_2.setTexture(ROLE[2].standleft);
	}

	// 将角色的中心点设置为中心，原来是左上角	
	spr_1.setOrigin(Vector2f(spr_1.getPosition().x + spr_1.getGlobalBounds().width / 2, spr_1.getPosition().y + spr_1.getGlobalBounds().height / 2));
	spr_2.setOrigin(Vector2f(spr_2.getPosition().x + spr_2.getGlobalBounds().width / 2, spr_2.getPosition().y + spr_2.getGlobalBounds().height / 2));
	spr_1.setPosition(Vector2f(700, 888));
	spr_2.setPosition(Vector2f(1900, 888));

	Sprite spr3, spr4; Texture red;
	red.loadFromFile("images/red.png");
	spr3.setTextureRect(IntRect(0, 0, 700, 40));
	spr4.setTextureRect(IntRect(0, 0, 700, 40));
	spr3.setTexture(red);
	spr4.setTexture(red);
	spr3.setPosition(Vector2f(0, 70));
	spr4.setPosition(Vector2f(900, 70));
	// 事件监测来改变一些值，联合所选角色来改变游戏状态
	Game::character1.isa = false;
	Game::character1.isAA = false;
	Game::character1.isJUMP = false;
	Game::character1.ismovl = false;
	Game::character1.ismovr = false;
	Game::character1.isQ = false;
	Game::character1.isE = false;
	Game::character1.LorR = 2;
	Game::character2.isa = false;
	Game::character2.isAA = false;
	Game::character2.isJUMP = false;
	Game::character2.ismovl = false;
	Game::character2.ismovr = false;
	Game::character2.isQ = false;
	Game::character2.isE = false;
	Game::character2.LorR = 1;
	Event event;
	while (_mainWindow.isOpen()) {
		cycle(sprmain, spr_1, spr_2, spr3, spr4);
		if (spr3.getTextureRect().width <= 0 || spr4.getPosition().x >= 1600) {
			_gameState = GameState::end;
			return;
		}
		//cout << spr3.getTextureRect().width << spr3.getPosition().x << endl;
		//cout << spr4.getTextureRect().width << spr4.getPosition().x << '\n' << endl;
		// 在这里来实现其它函数		
		Action1(sprmain, spr_1, spr_2, spr3, spr4);
		Action2(sprmain, spr_1, spr_2, spr3, spr4);		
		while (_mainWindow.pollEvent(event)) {
			// 在里面来更改参数
			if (event.type == Event::Closed) {
				_mainWindow.close();
			}
			else if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::A:
					character1.ismovl = true;
					break;
				case Keyboard::D:
					character1.ismovr = true;
					break;
				case Keyboard::W:
					character1.isJUMP = true;
					break;
				case Keyboard::J:
					character1.isa = true;
					break;
				case Keyboard::K:
					character1.isAA = true;
					break;
				case Keyboard::U:
					character1.isQ = true;
					break;
				case Keyboard::I:
					character1.isE = true;
					break;
				case Keyboard::Left:
					character2.ismovl = true;
					break;
				case Keyboard::Right:
					character2.ismovr = true;
					break;
				case Keyboard::Up:
					character2.isJUMP = true;
					break;
				case Keyboard::Numpad1:
					character2.isa = true;
					break;
				case Keyboard::Numpad2:
					character2.isAA = true;
					break;
				case Keyboard::Numpad4:
					character2.isQ = true;
					break;
				case Keyboard::Numpad5:
					character2.isE = true;
					break;
				default:
					break;
				}
			}
			else if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::A:
					character1.ismovl = false;
					break;
				case Keyboard::D:
					character1.ismovr = false;
					break;
				case Keyboard::W:
					character1.isJUMP = false;
					break;
				case Keyboard::J:
					character1.isa = false;
					break;
				case Keyboard::K:
					character1.isAA = false;
					break;
				case Keyboard::U:
					character1.isQ = false;
					break;
				case Keyboard::I:
					character1.isE = false;
					break;
				case Keyboard::Left:
					character2.ismovl = false;
					break;
				case Keyboard::Right:
					character2.ismovr = false;
					break;
				case Keyboard::Up:
					character2.isJUMP = false;
					break;
				case Keyboard::Numpad1:
					character2.isa = false;
					break;
				case Keyboard::Numpad2:
					character2.isAA = false;
					break;
				case Keyboard::Numpad4:
					character2.isQ = false;
					break;
				case Keyboard::Numpad5:
					character2.isE = false;
					break;
				default:
					break;
				}
			}
		}
	}
}

bool boom(Sprite& spr1, Sprite& spr2, double d) {
	double x1 = spr1.getPosition().x;
	double x2 = spr2.getPosition().y;
	if (abs(x1 - x2) < d)
		return true;
	else
		return false;
}

void Game::Action1(Sprite& sprm, Sprite& spr1, Sprite& spr2, Sprite& spr3, Sprite& spr4) {
	// 玩家1
	int p1 = player_1;
	Clock clock1;
	int i = -1, j = -1;
	int x0 = 0, y0 = 0;
	if (character1.ismovl == true) {
		character1.LorR = 1;
		spr1.setTexture(ROLE[p1 - 1].movl[0]);
		if (p1 == 1) {
			for (i = 1; i < 9;i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr1.setTexture(ROLE[0].movl[i]);
				if (spr1.getPosition().x > 600) {
					spr1.setPosition(spr1.getPosition().x - 10, spr1.getPosition().y);
				}

			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			for (int i = 1; i < 12; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr1.setTexture(ROLE[p1 - 1].movl[i]);
				if (spr1.getPosition().x > 600) {
					spr1.setPosition(spr1.getPosition().x - 10, spr1.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		spr1.setTexture(ROLE[p1 - 1].standleft);
		cycle(sprm, spr1, spr2, spr3, spr4);
	}
	if (character1.ismovr == true) {
		character1.LorR = 2;
		spr1.setTexture(ROLE[p1 - 1].movr[0]);
		if (p1 == 1) {
			for (i = 1; i < 9; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr1.setTexture(ROLE[p1 - 1].movr[i]);

				if (spr1.getPosition().x < 2000) {
					spr1.setPosition(spr1.getPosition().x + 10, spr1.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			for (i = 1; i < 12; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr1.setTexture(ROLE[p1 - 1].movr[i]);
				
				if (spr1.getPosition().x < 2000) {
					spr1.setPosition(spr1.getPosition().x + 10, spr1.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		spr1.setTexture(ROLE[p1 - 1].standright);
		cycle(sprm, spr1, spr2, spr3, spr4);
	}
	if (character1.isJUMP == true) {
		i = j = 0;
		if (character1.LorR == 1)
		{
			if (p1 == 2) {
				spr1.setTexture(ROLE[1].JUMPl[i]);
				clock1.restart();
				while (i < 8) {
					i = clock1.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr1.setTexture(ROLE[1].JUMPl[i]);
						x0 = ROLE[1].JUMPl[i].getSize().x;
						y0 = ROLE[1].JUMPl[i].getSize().y;
						if (i < 3) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y - 210);
						}
						else if (i < 5) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y + 210);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			else {
				spr1.setTexture(ROLE[p1 - 1].JUMPl[i]);
				clock1.restart();
				while (i < 8) {
					i = clock1.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr1.setTexture(ROLE[p1 - 1].JUMPl[i]);
						x0 = ROLE[p1 - 1].JUMPl[i].getSize().x;
						y0 = ROLE[p1 - 1].JUMPl[i].getSize().y;
						//cout << x0 << '\t' << y0 << endl;
						if (i < 4) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y - 140);
						}
						else if (i < 7) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y + 140);
						}
						else if (i < 8) {
						}
						//cout << spr1.getPosition().x << '\t' << spr1.getPosition().y << endl;
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			spr1.setTexture(ROLE[p1 - 1].standleft);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			if (p1 == 2) {
				spr1.setTexture(ROLE[1].JUMPr[i]);
				clock1.restart();
				while (i < 8) {
					i = clock1.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr1.setTexture(ROLE[1].JUMPr[i]);
						x0 = ROLE[1].JUMPr[i].getSize().x;
						y0 = ROLE[1].JUMPr[i].getSize().y;
						if (i < 3) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y - 210);
						}
						else if (i < 5) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y + 210);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			else {
				spr1.setTexture(ROLE[p1 - 1].JUMPr[i]);
				clock1.restart();
				while (i < 8) {
					i = clock1.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr1.setTexture(ROLE[p1 - 1].JUMPr[i]);
						x0 = ROLE[p1 - 1].JUMPr[i].getSize().x;
						y0 = ROLE[p1 - 1].JUMPr[i].getSize().y;
						if (i < 4) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y - 140);
						}
						else if (i < 7) {
							spr1.setPosition(spr1.getPosition().x, spr1.getPosition().y + 140);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			spr1.setTexture(ROLE[p1 - 1].standright);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		character1.isJUMP = false;
	}
	if (character1.isa == true) {
		i = j = -1;
		if (character1.LorR == 2) {
			if (p1 == 1) {
				clock1.restart();
				while (i < 5) {
					i = clock1.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 5)
					{
						spr1.setTexture(ROLE[0].ar[i]);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width -12, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x + 12, 70));
				}
			}
			else if (p1 == 2) {
				clock1.restart();
				while (i < 7) {
					i = clock1.getElapsedTime().asMilliseconds() / 100;
					if (i != j && i < 7)
					{
						spr1.setTexture(ROLE[1].ar[i]);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 16, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x + 16, 70));
				}
			}
			else if (p1 == 3) {
				clock1.restart();
				while (i < 8) {
					i = clock1.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 8)
					{
						spr1.setTexture(ROLE[2].ar[i]);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1500)) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 24, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x + 24, 70));
				}
			}
			spr1.setTexture(ROLE[p1 - 1].standright);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			if (p1 == 1) {
				clock1.restart();
				while (i < 5) {
					i = clock1.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 5)
					{
						spr1.setTexture(ROLE[0].al[i]);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width -12, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x + 12, 70));
				}
			}
			else if (p1 == 2) {
				clock1.restart();
				while (i < 7) {
					i = clock1.getElapsedTime().asMilliseconds() / 100;
					if (i != j && i < 7)
					{
						spr1.setTexture(ROLE[1].al[i]);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 16, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x + 16, 70));
				}
			}
			else if (p1 == 3) {
				clock1.restart();
				while (i < 8) {
					i = clock1.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 8)
					{
						spr1.setTexture(ROLE[2].al[i]);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1500)) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 24, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x + 24, 70));
				}
			}
			spr1.setTexture(ROLE[p1 - 1].standleft);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		character1.isa = false;
	}
	if (character1.isAA == true) {
		i = j = -1;
		if (p1 == 1) {
			clock1.restart();
			while (i < 11) {
				i = clock1.getElapsedTime().asMilliseconds() / 60;
				if (i != j && i < 11) {
					if (character1.LorR == 2) spr1.setTexture(ROLE[0].AAr[i]);
					spr1.setTexture(ROLE[0].AAl[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1500)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 36, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 36, 70));
			}
		}
		else if (p1 == 2) {
			clock1.restart();
			while (i < 10) {
				i = clock1.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 10) {
					if (character1.LorR == 2) spr1.setTexture(ROLE[1].AAr[i]);
					spr1.setTexture(ROLE[1].AAl[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1500)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 24, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 24, 70));
			}
		}
		else if (p1 == 3) {
			clock1.restart();
			while (i < 5) {
				i = clock1.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 5) {
					if (character1.LorR == 2) spr1.setTexture(ROLE[2].AAr[i]);
					spr1.setTexture(ROLE[2].AAl[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1800)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 42, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 42, 70));
			}
		}
		if (character1.LorR == 2) spr1.setTexture(ROLE[p1 - 1].standright);
		else spr1.setTexture(ROLE[p1 - 1].standleft);
		cycle(sprm, spr1, spr2, spr3, spr4);
		character1.isAA = false;
	}
	if (character1.isE == true) {
		i = j = -1;
		if (p1 == 1) {
			e[0].openFromFile("sound/KQ2.wav");
			e[0].play();
			clock1.restart();
			while (i < 11) {
				i = clock1.getElapsedTime().asMilliseconds() / 60;
				if (i != j && i < 11) {
					if (character1.LorR == 2)	spr1.setTexture(ROLE[0].Er[i]);
					else spr1.setTexture(ROLE[0].El[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1800)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 60, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 60, 70));
			}
		}
		else if (p1 == 2) {
			e[1].openFromFile("sound/DLK2.wav");
			e[1].play();
			clock1.restart();
			while (i < 6) {
				i = clock1.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 6) {
					if (character1.LorR == 2)	spr1.setTexture(ROLE[1].Er[i]);
					else spr1.setTexture(ROLE[1].El[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1500)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 48, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 48, 70));
			}
		}
		else {
			e[2].openFromFile("sound/HT2.wav");
			e[2].play();
			clock1.restart();
			while (i < 7) {
				i = clock1.getElapsedTime().asMilliseconds() / 60;
				if (i != j && i < 7) {
					if (character1.LorR == 2)	spr1.setTexture(ROLE[2].Er[i]);
					else spr1.setTexture(ROLE[2].El[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 500)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 12, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 12, 70));				
			}
			spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width * 0.7, 40));
		}
		if (character1.LorR == 2) spr1.setTexture(ROLE[p1 - 1].standright);
		else spr1.setTexture(ROLE[p1 - 1].standleft);
		cycle(sprm, spr1, spr2, spr3, spr4);
		character1.isE = false;
	}
	if (character1.isQ == true) {
		x0 = spr1.getPosition().x;
		y0 = spr1.getPosition().y;
		i = j = -1;
		if (p1 == 1) {
			q[0].openFromFile("sound/KQ3.wav");
			q[0].play();
			clock1.restart();
			while (i < 15) {
				i = clock1.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 15) {
					spr1.setTexture(ROLE[0].Q[i], false);
					spr1.setPosition(800, 450);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 4000)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 120, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 120, 70));
			}
		}
		else if (p1 == 2) {
			q[1].openFromFile("sound/DLK3.wav");
			q[1].play();
			clock1.restart();
			while (i < 10) {
				i = clock1.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 10) {
					spr1.setTexture(ROLE[1].Q[i], false);
					spr1.setPosition(800, 450);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 3000)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 90, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 90, 70));
			}
		}
		else {
			q[2].openFromFile("sound/HT3.wav");
			q[2].play();
			clock1.restart();
			while (i < 15) {
				i = clock1.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 15) {
					spr1.setTexture(ROLE[2].Q[i], false);
					spr1.setPosition(800, 450);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 800)) {
				spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width - 150, 40));
				spr4.setPosition(Vector2f(spr4.getPosition().x + 150, 70));
				if (spr3.getTextureRect().width < 450) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width + 100, 40));
				else spr3.setTextureRect(IntRect(0, 0, 600, 40));
			}
		}
		if (character1.LorR == 2) spr1.setTexture(ROLE[p1 - 1].standright);
		else spr1.setTexture(ROLE[p1 - 1].standleft);
		spr1.setPosition(x0, y0);
		cycle(sprm, spr1, spr2, spr3, spr4);
		character1.isQ = false;
	}
}
void Game::Action2(Sprite& sprm, Sprite& spr1, Sprite& spr2, Sprite& spr3, Sprite& spr4) {
	// 玩家2
	int p2 = player_2;
	Clock clock2;
	int i = -1, j = -1;
	int x0 = 0, y0 = 0;
	if (character2.ismovl == true) {
		character2.LorR = 1;
		spr2.setTexture(ROLE[p2 - 1].movl[0]);
		if (p2 == 1) {
			for (int i = 1; i < 9; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr2.setTexture(ROLE[0].movl[i]);
				spr1.getTextureRect();
				if (spr2.getPosition().x > 600) {
					spr2.setPosition(spr2.getPosition().x - 10, spr2.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			for (int i = 1; i < 12; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr2.setTexture(ROLE[p2 - 1].movl[i]);
				spr1.getTextureRect();
				if (spr2.getPosition().x > 600) {
					spr2.setPosition(spr2.getPosition().x - 10, spr2.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		spr2.setTexture(ROLE[p2 - 1].standleft);
		cycle(sprm, spr1, spr2, spr3, spr4);
	}
	if (character2.ismovr == true) {
		character2.LorR = 2;
		spr2.setTexture(ROLE[p2 - 1].movl[0]);
		if (p2 == 1) {
			for (int i = 1; i < 9; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr2.setTexture(ROLE[0].movr[i]);
				spr1.getTextureRect();
				if (spr2.getPosition().x < 2000) {
					spr2.setPosition(spr2.getPosition().x + 10, spr2.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			for (int i = 1; i < 12; i++) {
				cycle(sprm, spr1, spr2, spr3, spr4);
				spr2.setTexture(ROLE[p2 - 1].movr[i]);
				spr1.getTextureRect();
				if (spr2.getPosition().x < 2000) {
					spr2.setPosition(spr2.getPosition().x + 10, spr2.getPosition().y);
				}
			}
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		spr2.setTexture(ROLE[p2 - 1].standright);
		cycle(sprm, spr1, spr2, spr3, spr4);
	}
	if (character2.isJUMP == true) {
		i = j = 0;
		if (character2.LorR == 1)
		{
			if (p2 == 2) {
				spr2.setTexture(ROLE[1].JUMPl[i]);
				clock2.restart();
				while (i < 8) {
					i = clock2.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr2.setTexture(ROLE[1].JUMPl[i]);
						x0 = ROLE[1].JUMPl[i].getSize().x;
						y0 = ROLE[1].JUMPl[i].getSize().y;
						if (i < 3) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y - 210);
						}
						else if (i < 5) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y + 210);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			else {
				clock2.restart();
				while (i < 8) {
					i = clock2.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr2.setTexture(ROLE[p2 - 1].JUMPl[i]);
						x0 = ROLE[p2 - 1].JUMPl[i].getSize().x;
						y0 = ROLE[p2 - 1].JUMPl[i].getSize().y;
						if (i < 4) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y - 140);
						}
						else if (i < 7) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y + 140);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			spr2.setTexture(ROLE[p2 - 1].standleft);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			if (p2 == 2) {
				spr2.setTexture(ROLE[1].JUMPr[i]);
				clock2.restart();
				while (i < 8) {
					i = clock2.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr2.setTexture(ROLE[1].JUMPr[i]);
						x0 = ROLE[1].JUMPr[i].getSize().x;
						y0 = ROLE[1].JUMPr[i].getSize().y;
						if (i < 3) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y - 210);
						}
						else if (i < 5) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y + 210);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			else {
				clock2.restart();
				while (i < 8) {
					i = clock2.getElapsedTime().asMilliseconds() / 80;
					if (i != j && i < 8) {
						cycle(sprm, spr1, spr2, spr3, spr4);
						spr2.setTexture(ROLE[p2 - 1].JUMPr[i]);
						x0 = ROLE[p2 - 1].JUMPr[i].getSize().x;
						y0 = ROLE[p2 - 1].JUMPr[i].getSize().y;
						if (i < 4) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y - 140);
						}
						else if (i < 7) {
							spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y + 140);
						}
						else if (i < 8) {
						}
						j = i;
					}
					else continue;
				}
				cycle(sprm, spr1, spr2, spr3, spr4);
			}
			spr2.setTexture(ROLE[p2 - 1].standleft);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		character2.isJUMP = false;
	}
	if (character2.isa == true) {
		i = j = -1;
		if (character2.LorR == 2) {
			if (p2 == 1) {
				clock2.restart();
				while (i < 5) {
					i = clock2.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 5)
					{
						spr2.setTexture(ROLE[0].ar[i]);
						x0 = ROLE[0].ar[i].getSize().x;
						y0 = ROLE[0].ar[i].getSize().y;
						spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 12, 40));
			}
			else if (p2 == 2) {
				clock2.restart();
				while (i < 7) {
					i = clock2.getElapsedTime().asMilliseconds() / 100;
					if (i != j && i < 7)
					{
						spr2.setTexture(ROLE[1].ar[i]);
						x0 = ROLE[1].ar[i].getSize().x;
						y0 = ROLE[1].ar[i].getSize().y;
						spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 16, 40));
			}
			else if (p2 == 3) {
				clock2.restart();
				while (i < 8) {
					i = clock2.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 8)
					{
						spr2.setTexture(ROLE[2].ar[i]);
						x0 = ROLE[2].ar[i].getSize().x;
						y0 = ROLE[2].ar[i].getSize().y;
						spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1500)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 24, 40));
			}
			spr2.setTexture(ROLE[p2 - 1].standright);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		else {
			if (p2 == 1) {
				clock2.restart();
				while (i < 5) {
					i = clock2.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 5)
					{
						spr2.setTexture(ROLE[0].al[i]);
						x0 = ROLE[0].al[i].getSize().x;
						y0 = ROLE[0].al[i].getSize().y;
						spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width * 0.98, 40));
			}
			else if (p2 == 2) {
				clock2.restart();
				while (i < 7) {
					i = clock2.getElapsedTime().asMilliseconds() / 100;
					if (i != j && i < 7)
					{
						spr2.setTexture(ROLE[1].al[i]);
						x0 = ROLE[1].al[i].getSize().x;
						y0 = ROLE[1].al[i].getSize().y;
						spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1200)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width * 0.97, 40));
			}
			else if (p2 == 3) {
				clock2.restart();
				while (i < 8) {
					i = clock2.getElapsedTime().asMilliseconds() / 60;
					if (i != j && i < 8)
					{
						spr2.setTexture(ROLE[2].al[i]);
						x0 = ROLE[2].al[i].getSize().x;
						y0 = ROLE[2].al[i].getSize().y;
						spr2.setPosition(spr2.getPosition().x, spr2.getPosition().y);
						cycle(sprm, spr1, spr2, spr3, spr4);
						j = i;
					}
					else continue;
				}
				if (boom(spr1, spr2, 1500)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width * 0.96, 40));
			}
			spr2.setTexture(ROLE[p2 - 1].standleft);
			cycle(sprm, spr1, spr2, spr3, spr4);
		}
		character2.isa = false;
	}
	if (character2.isAA == true) {
		i = j = -1;
		if (p2 == 1) {
			clock2.restart();
			while (i < 11) {
				i = clock2.getElapsedTime().asMilliseconds() / 60;
				if (i != j && i < 11) {
					if (character2.LorR == 2) spr2.setTexture(ROLE[0].AAr[i]);
					else spr2.setTexture(ROLE[0].AAl[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1500)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 36, 40));
		}
		else if (p2 == 2) {
			clock2.restart();
			while (i < 10) {
				i = clock2.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 10) {
					if (character2.LorR == 2) spr2.setTexture(ROLE[1].AAr[i]);
					else spr2.setTexture(ROLE[1].AAl[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1500)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 24, 40));
		}
		else if (p2 == 3) {
			clock2.restart();
			while (i < 5) {
				i = clock2.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 5) {
					if (character2.LorR == 2) spr2.setTexture(ROLE[2].AAr[i]);
					else spr2.setTexture(ROLE[2].AAl[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1800)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 42, 40));
		}
		if (character2.LorR == 2)spr2.setTexture(ROLE[p2 - 1].standright);
		else spr2.setTexture(ROLE[p2 - 1].standleft);
		cycle(sprm, spr1, spr2, spr3, spr4);
		character2.isAA = false;
	}
	if (character2.isE == true) {
		i = j = -1;
		if (p2 == 1) {
			e[0].openFromFile("sound/KQ2.wav");
			e[0].play();
			clock2.restart();
			while (i < 11) {
				i = clock2.getElapsedTime().asMilliseconds() / 60;
				if (i != j && i < 11) {
					if (character2.LorR == 2)	spr2.setTexture(ROLE[0].Er[i]);
					else spr2.setTexture(ROLE[0].El[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1800)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 60, 40));
		}
		else if (p2 == 2) {
			e[1].openFromFile("sound/DLK2.wav");
			e[1].play();
			clock2.restart();
			while (i < 6) {
				i = clock2.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 6) {
					if (character2.LorR == 2)	spr2.setTexture(ROLE[1].Er[i]);
					else spr2.setTexture(ROLE[1].El[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 1500)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 48, 40));
		}
		else {
			e[2].openFromFile("sound/HT2.wav");
			e[2].play();
			clock2.restart();
			while (i < 7) {
				i = clock2.getElapsedTime().asMilliseconds() / 60;
				if (i != j && i < 7) {
					if (character2.LorR == 2)	spr2.setTexture(ROLE[2].Er[i]);
					else spr2.setTexture(ROLE[2].El[i]);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 500)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 12, 40));
			spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width * 0.7, 40));
			spr4.setPosition(Vector2f(spr4.getPosition().x + spr4.getTextureRect().width * 0.3, 70));
		}
		if (character2.LorR == 2) spr2.setTexture(ROLE[p2 - 1].standright);
		else spr2.setTexture(ROLE[p2 - 1].standleft);
		cycle(sprm, spr1, spr2, spr3, spr4);
		character2.isE = false;
	}
	if (character2.isQ == true) {
		x0 = spr2.getPosition().x;
		y0 = spr2.getPosition().y;
		i = j = -1;
		if (p2 == 1) {
			q[0].openFromFile("sound/KQ3.wav");
			q[0].play();
			clock2.restart();
			while (i < 15) {
				i = clock2.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 15) {
					spr2.setTexture(ROLE[0].Q[i], false);
					spr2.setPosition(800, 450);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 4000)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 120, 40));
		}
		else if (p2 == 2) {
			q[1].openFromFile("sound/DLK3.wav");
			q[1].play();
			clock2.restart();
			while (i < 10) {
				i = clock2.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 10) {
					spr2.setTexture(ROLE[1].Q[i], false);
					spr2.setPosition(800, 450);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 3000)) spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 90, 40));
		}
		else {
			q[2].openFromFile("sound/HT3.wav");
			q[2].play();
			clock2.restart();
			while (i < 15) {
				i = clock2.getElapsedTime().asMilliseconds() / 100;
				if (i != j && i < 15) {
					spr2.setTexture(ROLE[2].Q[i], false);
					spr2.setPosition(800, 450);
					cycle(sprm, spr1, spr2, spr3, spr4);
					j = i;
				}
				else continue;
			}
			if (boom(spr1, spr2, 800)) {
				spr3.setTextureRect(IntRect(0, 0, spr3.getTextureRect().width - 150, 40));
				if (spr4.getTextureRect().width < 450) {
					spr4.setTextureRect(IntRect(0, 0, spr4.getTextureRect().width + 150, 40));
					spr4.setPosition(Vector2f(spr4.getPosition().x - 100, 70));
				}
				else {
					spr4.setTextureRect(IntRect(0, 0, 600, 40));
					spr4.setPosition(Vector2f(950, 70));
				}
			}
		}
		if (character2.LorR == 2) spr2.setTexture(ROLE[p2 - 1].standright);
		else spr2.setTexture(ROLE[p2 - 1].standleft);
		spr2.setPosition(x0, y0);
		cycle(sprm, spr1, spr2, spr3, spr4);
		character2.isQ = false;
	}
}
Game::cmov Game::character1;
Game::cmov Game::character2;
int Game::gameover;
int Game::player_1;
int Game::player_2;
int Game::flag_play;
Game::GameState Game::_gameState = GameState::Uninitialized;
RenderWindow Game::_mainWindow;