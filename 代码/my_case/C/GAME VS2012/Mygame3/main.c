#include<yzkgame.h>
#include<stdio.h>
#include<stdlib.h>
#pragma comment(linker,"/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")
void gameMain(void)
{
	int coinNums[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; //金币编号数组
	int coinXs[]={110,210,130,340,250,160,170,280,1000,400,800,700,500,1100,900,700,800,950,850,750,1700,1210,1300,1340,1250,1600,1900,1800,1680,1750};//金币 x 坐标数组
	int coinYs[]={88,117,18,181,200,204,301,350,300,400,600,580,550,300,100,200,300,230,402,10,88,117,18,181,200,204,301,350,300,400}; //金币 y 坐标数组
	
	int bombNums[ ]={100,101,102,103,104}; //炸弹精灵编号
	int bombXs[ ]={299,17,118,181,50}; //炸弹精灵x坐标
	int bombYs[ ]={110,200,155,340,299}; //炸弹精灵y坐标
	
	int imageNum=0; //背景图片编号
	int marioNum=0; //mario 精灵编号
	int i;
	int key = 0;
	int size=sizeof(coinNums)/sizeof(int);
	int bombSize=sizeof(bombNums)/sizeof(int);
	int marioX=0; //mario 精灵 x 坐标
	int marioY=0; //mario 精灵 y 坐标
	int scoreCoinNum=1; //分数金币图片编号
	int scoreTxt=0; //分数文本编号
	int count=0; //被吃掉的金币计数

	setGameSize(1921,639);
	createImage(imageNum,"大片草地.png");
	createSprite(marioNum,"mario");
	playSpriteAnimate(marioNum,"walk");
	setSpriteFlipX(marioNum,TRUE);
	createImage(scoreCoinNum,"coin.png");
	setImagePosition(scoreCoinNum,1700,550);
	createText(scoreTxt,"X0");
	setTextPosition(scoreTxt,1800,575);
	setTextFontSize(scoreTxt,40); 

	for (i=0;i<size;i++) 
	{
		int coinNum=coinNums[i]; //获取金币编号
		int coinX=coinXs[i]; //获取金币 x 坐标
		int coinY=coinYs[i]; //获取金币 y 坐标
		createSprite(coinNum,"coin");
		playSpriteAnimate(coinNum,"rotate");
		setSpritePosition(coinNum,coinX,coinY);
	}

	for (i=0;i<bombSize;i++)
	{
		int bombNum=bombNums[i];
		int bombX=bombXs[i];
		int bombY=bombYs[i];
		createSprite(bombNum,"bomb");
		playSpriteAnimate(bombNum,"laser");
		setSpritePosition(bombNum,bombX,bombY);
	}

	while (1)
	{
		int key=getPressedKeyCode();
		if(RP_KEY_UP==key)
		{
			marioY++; //y 坐标加 1
		}
		else if(RP_KEY_DOWN==key)
		{
			marioY--; //y 坐标减 1
		}
		else if(RP_KEY_LEFT==key)
		{
			marioX--; //x 坐标减 1
			setSpriteFlipX(marioNum,FALSE);
		}
		else if(RP_KEY_RIGHT==key)
		{
			marioX++; //x 坐标加 1
			setSpriteFlipX(marioNum,TRUE);
		}
		setSpritePosition(marioNum,marioX,marioY); //设置 mario 显示位置

		for (i=0;i<size;i++) //遍历金币
		{
			int coinNum=coinNums[i]; //获取金币编号
			int coinX=coinXs[i]; //获取金币 x 轴坐标
			int coinY=coinYs[i]; //获取金币 y 轴坐标
			int dist=(coinX-marioX)*(coinX-marioX)+(coinY-marioY)*(coinY-marioY);

			if (dist<600&&isSpriteVisible(coinNum)) //距离平方值是否小于 600  和金币是否被隐藏
			{
				char text[10]={0}; //定义字符数组，长度为 10
				count++;           //被吃掉的金币计数加 1
				sprintf(text,"X%d",count);//修改分数文本内容
				setText(scoreTxt,text);    //更新窗口分数文本显示
				hideSprite(coinNum);     //隐藏金币
			}
		
		}
		for (i=0;i<bombSize;i++) //遍历炸弹编号
		{
			int bombX=bombXs[i]; //获取炸弹x坐标
			int bombY=bombYs[i]; //获取炸弹y坐标
			int dist=(bombX-marioX)*(bombX-marioX)+(bombY-marioY)*(bombY-marioY);
			if (dist<100) //炸弹与精灵距离是否小于100
			{
				exit(0); //结束游戏
			}
		}

			pauseGame(5);
	}
	pauseGame(10000);
}
int main(void)
{
	rpInit(gameMain);
	return 0;
}
