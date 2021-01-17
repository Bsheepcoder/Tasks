#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	int image_x = 0;
	int spriteNum = 0;
	int x = 100 ,y = 50;
	int vx = -2 ,vy = 2;
	int gameHight = 675, gameWidth = 1200;
	setGameTitle("���浯��");
	setGameSize(1200, 675);

	createImage(0,"back.png");
	setImagePosition(0,image_x,0);

	createSprite(spriteNum,"ball1");
	setSpritePosition(spriteNum,x,y);

	playSpriteAnimate(spriteNum,"rotate");
	
	while(1)
	{
		if(x+getSpriteWidth(spriteNum)>=gameWidth)  //�Ƿ���ײ�ұ߽�
		{
			vx = -vx;
		}
		else if(x<=0)  //�Ƿ���ײ��߽�
		{
			vx = -vx;        
		}else if (y + getSpriteHeight(spriteNum)>=gameHight)  //�Ƿ���ײ�ϱ߽�
		{
			vy = -vy;
		}else if(y<=0)   //�Ƿ���ײ�±߽�
		{ 
	 		vy = -vy;    
		}
		x=x+vx;       //����С��x����
		y=y+vy;       //����С��y����
		setSpritePosition(spriteNum,x,y);  //����С����ʾλ��
		pauseGame(10);
	}
	//pauseGame(100000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}