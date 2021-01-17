#include<yzkgame.h>
#include<stdio.h>
#include<stdlib.h>
#pragma comment(linker,"/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")
void gameMain(void)
{
	int coinNums[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; //��ұ������
	int coinXs[]={110,210,130,340,250,160,170,280,1000,400,800,700,500,1100,900,700,800,950,850,750,1700,1210,1300,1340,1250,1600,1900,1800,1680,1750};//��� x ��������
	int coinYs[]={88,117,18,181,200,204,301,350,300,400,600,580,550,300,100,200,300,230,402,10,88,117,18,181,200,204,301,350,300,400}; //��� y ��������
	
	int bombNums[ ]={100,101,102,103,104}; //ը��������
	int bombXs[ ]={299,17,118,181,50}; //ը������x����
	int bombYs[ ]={110,200,155,340,299}; //ը������y����
	
	int imageNum=0; //����ͼƬ���
	int marioNum=0; //mario ������
	int i;
	int key = 0;
	int size=sizeof(coinNums)/sizeof(int);
	int bombSize=sizeof(bombNums)/sizeof(int);
	int marioX=0; //mario ���� x ����
	int marioY=0; //mario ���� y ����
	int scoreCoinNum=1; //�������ͼƬ���
	int scoreTxt=0; //�����ı����
	int count=0; //���Ե��Ľ�Ҽ���

	setGameSize(1921,639);
	createImage(imageNum,"��Ƭ�ݵ�.png");
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
		int coinNum=coinNums[i]; //��ȡ��ұ��
		int coinX=coinXs[i]; //��ȡ��� x ����
		int coinY=coinYs[i]; //��ȡ��� y ����
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
			marioY++; //y ����� 1
		}
		else if(RP_KEY_DOWN==key)
		{
			marioY--; //y ����� 1
		}
		else if(RP_KEY_LEFT==key)
		{
			marioX--; //x ����� 1
			setSpriteFlipX(marioNum,FALSE);
		}
		else if(RP_KEY_RIGHT==key)
		{
			marioX++; //x ����� 1
			setSpriteFlipX(marioNum,TRUE);
		}
		setSpritePosition(marioNum,marioX,marioY); //���� mario ��ʾλ��

		for (i=0;i<size;i++) //�������
		{
			int coinNum=coinNums[i]; //��ȡ��ұ��
			int coinX=coinXs[i]; //��ȡ��� x ������
			int coinY=coinYs[i]; //��ȡ��� y ������
			int dist=(coinX-marioX)*(coinX-marioX)+(coinY-marioY)*(coinY-marioY);

			if (dist<600&&isSpriteVisible(coinNum)) //����ƽ��ֵ�Ƿ�С�� 600  �ͽ���Ƿ�����
			{
				char text[10]={0}; //�����ַ����飬����Ϊ 10
				count++;           //���Ե��Ľ�Ҽ����� 1
				sprintf(text,"X%d",count);//�޸ķ����ı�����
				setText(scoreTxt,text);    //���´��ڷ����ı���ʾ
				hideSprite(coinNum);     //���ؽ��
			}
		
		}
		for (i=0;i<bombSize;i++) //����ը�����
		{
			int bombX=bombXs[i]; //��ȡը��x����
			int bombY=bombYs[i]; //��ȡը��y����
			int dist=(bombX-marioX)*(bombX-marioX)+(bombY-marioY)*(bombY-marioY);
			if (dist<100) //ը���뾫������Ƿ�С��100
			{
				exit(0); //������Ϸ
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
