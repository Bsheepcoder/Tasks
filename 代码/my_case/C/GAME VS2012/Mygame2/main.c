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
	setGameTitle("桌面弹球");
	setGameSize(1200, 675);

	createImage(0,"back.png");
	setImagePosition(0,image_x,0);

	createSprite(spriteNum,"ball1");
	setSpritePosition(spriteNum,x,y);

	playSpriteAnimate(spriteNum,"rotate");
	
	while(1)
	{
		if(x+getSpriteWidth(spriteNum)>=gameWidth)  //是否碰撞右边界
		{
			vx = -vx;
		}
		else if(x<=0)  //是否碰撞左边界
		{
			vx = -vx;        
		}else if (y + getSpriteHeight(spriteNum)>=gameHight)  //是否碰撞上边界
		{
			vy = -vy;
		}else if(y<=0)   //是否碰撞下边界
		{ 
	 		vy = -vy;    
		}
		x=x+vx;       //计算小球x坐标
		y=y+vy;       //计算小球y坐标
		setSpritePosition(spriteNum,x,y);  //设置小球显示位置
		pauseGame(10);
	}
	//pauseGame(100000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}