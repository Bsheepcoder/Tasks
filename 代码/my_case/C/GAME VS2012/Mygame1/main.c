#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	int titileText=0;
	int singleText=1;
	int doubleText=2;
	int demoText=3;
	int x=480 ,y =10;
	int image_x=0;
	int font=30;
	int spriteNum = 0;
	int i;
	int fornt = 40;
	int p = 1;
	setGameTitle("C语言游戏引擎");   //显示框的标题
	setGameSize(1200, 675);    //显示框的大小

	createImage(0,"back.png");
	setImagePosition(0,image_x,0);
	
	createText(titileText,"算数游戏");
	setTextPosition(titileText,x,400);
	for(i = 0 ; i < 10 ; i++)
	{   fornt = fornt + 2 ;
		setTextFontSize(titileText,fornt);
		pauseGame(100);
	}
	createText(singleText,"1 单人游戏");
	setTextPosition(singleText,x,340);
	setTextFontSize(singleText,font);

	createText(doubleText,"2 排行榜");
	setTextPosition(doubleText,x,280);
	setTextFontSize(doubleText,font);

	createText(demoText,"3 更多");
	setTextPosition(demoText,x,220);
	setTextFontSize(demoText,font);
	
	x = 1000;
	createSprite(spriteNum,"boy");
	setSpritePosition(spriteNum,x,y);

	playSpriteAnimate(spriteNum,"jump");
	pauseGame(1000);
	playSpriteAnimate(spriteNum,"fly");
	pauseGame(2000);
	while (1)
	{   if(p)  
		{
			if(x != 0 )
			{
		        x = x-10 ;
				setSpritePosition(spriteNum,x,y);
				playSpriteAnimate(spriteNum,"walk");
				pauseGame(170);
			}else{
				setSpriteFlipX(spriteNum,TRUE);
				pauseGame(80);
				p = 0 ;
			}
		}else
		{
			if(x != 1180 )
			{
		        x = x+10 ;
				setSpritePosition(spriteNum,x,y);
				playSpriteAnimate(spriteNum,"walk");
				pauseGame(170);
			}else{
				setSpriteFlipX(spriteNum,FALSE);
				pauseGame(1);
				p = 1 ;
			}
		}
		
	}
	pauseGame(100000);
}


int main(void)
{
	rpInit(gameMain);
	return 0;
}

