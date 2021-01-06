# 游戏引擎初识

==前期准备==：

**[YZKGame引擎、VS 2012下载地址](http://rp.youzack.com/index.html)**

- 资源内还包含有各种素材
- 这是一个可以用C语言编程的简单游戏引擎。

## 0x01 什么是像素

- 像素是计算机中文字、图像显示的基本单位，像素又称像素点。例如，1024x768分辨率，指的是屏幕横向有1024个像素点，纵向有768个像素点。

## 0x02 游戏窗口坐标系

- 与数学中的坐标系相同，坐标是相对位置，依据2D、3D等可有不同的坐标轴，常见的是平面的（X，Y）坐标。

​      **[不同的坐标系](https://blog.csdn.net/liu_yude/article/details/45194813)**

## 0x03 如何渲染图形

- **矩形** 

   在二维坐标系中描述一个矩形需要3个条件：**矩形左下角坐标、矩形高度像素值、矩形宽度像素值**

  **例如：**可以这样描述，某矩形的左下角坐标为(100,0)，高度为200像素，宽度为300像素。

  **[更多关于图形渲染](https://blog.csdn.net/u012999985/article/details/79090657?ops_request_misc=%25257B%252522request%25255Fid%252522%25253A%252522160930891416780304638853%252522%25252C%252522scm%252522%25253A%25252220140713.130102334.pc%25255Fall.%252522%25257D&request_id=160930891416780304638853&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-1-79090657.pc_search_result_cache&utm_term=%E6%B8%B8%E6%88%8F%E5%BC%80%E5%8F%91%E6%8F%8F%E8%BF%B0%E5%9B%BE%E5%BD%A2)**

## 0x04 什么是图层

- 图层就是将**文字、图片等元素进行分层**，叠加显示出最终的效果。本文的游戏引擎可以显示的元素共有4种：**背景颜色、图片、动作元素（精灵）、文字**，当多种元素同时出现时，就会组合在一起叠加显示。
- [![sphBp6.png](https://s3.ax1x.com/2021/01/03/sphBp6.png)](https://imgchr.com/i/sphBp6)

## 0x05 核心函数介绍

####  **1.pauseGame设置游戏暂停时间函数**

```c
//函数原型
void pauseGame(int millSeconds)
//函数参数：millSeconds 游戏程序暂停时长，以毫秒为单位，1000毫秒等于1秒。
```

- **例：**

```c
#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	pauseGame(10000);  //游戏暂停时间为10秒，阻塞程序后面的代码不会执行
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}
```

#### 2.setGameSize设置窗口尺寸函数

```c
//函数原型
void setGameSize(int with,int height)
//函数参数：width: 窗口宽度  height:窗口高度
```

- **例：**

```c
//上略
void gameMain(void)
{
	setGameSize(300,200); //设置游戏窗口宽度300像素，高200像素
	pauseGame(10000);  
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}
```
## 0x06 文本函数介绍

|                函数名                |                   函数原型                    |                  函数参数                  |
| :----------------------------------: | :-------------------------------------------: | :----------------------------------------: |
|     setGameTile 设置窗口标题函数     |         void setGameTile(char* title)         |              “文字” 标题内容               |
|       craeteText 创建文本函数        |    void craeteText(int txtNum, char* text)    |         文本元素编号、文本显示内容         |
| setTextPosition 设置文本显示位置函数 | void setTextPosition(int txtNum,int x, int y) | 文本元素编号、文本元素x坐标、文本元素y坐标 |
| setTextFontSize 设置文本文字大小函数 |  void setTextFontSize(int txtNum, int size)   |  文本元素编号、文本文字大小（单位为像素）  |
|       setText 修改文本内容函数       |     void setText(int txtNum, char* text)      |     被修改的文本元素编号、新的文本内容     |
|        hideText 隐藏文本函数         |           void hideText(int txtNum)           |              被隐藏的文本编号              |
|        showText 显示文本函数         |           void showText(int txtNum)           |              被显示的文本编号              |

## 0x07 图形函数介绍

图形一般有固定支持的格式、和存储位置，本游戏引擎的图片存储位置在image文件夹，只支持png格式


|                函数名                 |                  函数原型                   |                  函数参数                  |
| :-----------------------------------: | :-----------------------------------------: | :----------------------------------------: |
|       craeteImage 创建图片函数        |  void craeteImage(int num, char* imgName)   | 被创建的图片编号、**包括后缀的图片全名称** |
| setImagePosition 设置图片显示位置函数 | void setImagePosition(int Num,int x, int y) | 图片元素编号、图片元素x坐标、图片元素y坐标 |
|    setImageSource 修改文本内容函数    | void setImageSource(int Num, char* imgName) |     被修改的图片元素编号、新的图片内容     |
|        hideImage 隐藏文本函数         |           void hideImage(int Num)           |              被隐藏的图片编号              |
|        showImage 显示文本函数         |           void showImage(int Num)           |              被显示的图片编号              |

## 0x08 动作元素函数介绍

必须先将完整的动作元素图片放置指定文件夹，并对每种动作分类放置不同的文件夹

|                 函数名                 |                      函数原型                      |            函数参数            |
| :------------------------------------: | :------------------------------------------------: | :----------------------------: |
|       craeteSprite 创建文本函数        |    void craeteSprite(int Num, char* SpriteName)    |       元素编号、元素名称       |
|   playSpriteAnimate播放元素动作函数    | void playSpriteAnimate(int num,char * animateName) |   元素编号、要播放的动作名称   |
| setSpritePosition 设置元素显示位置函数 |    void setSpritePosition(int Num,int x, int y)    | 元素编号、元素x坐标、元素y坐标 |
|        hideSprite 隐藏文本函数         |              void hideSprite(int Num)              |        被隐藏的元素编号        |
|        showSprite 显示文本函数         |              void showSprite(int Num)              |        被显示的元素编号        |
|    setSpriteFlipX元素在X轴翻转函数     |     void setSpriteFlipX(int num,BOOL isFlipx)      |       元素编号、是否翻转       |
|    setSpriteFlipY元素在Y轴翻转函数     |     void setSpriteFlipY(int num,BOOL isFlipx)      |       元素编号、是否翻转       |
|    getSpriteHeight获取精灵高度函数     |           void getSpriteHeight(int num)            |            元素编号            |
|     getSpriteWidth获取精灵宽度函数     |          void getgetSpriteWidth(int num)           |            元素编号            |

###  ==YZKgame_API==

```c
#ifndef YZKGAME_H
#define YZKGAME_H

#ifdef YZKGAME_EXPORTS //dll项目中在“预处理器定义”中定义了YZKGAME_EXPORTS，这样YZKGAME_API就是声明函数导出。对于使用者来讲由于没定义YZKGAME_EXPORTS，所以就是声明函数导入
#define YZKGAME_API __declspec(dllexport)
#else
#define YZKGAME_API __declspec(dllimport)
#endif

#ifndef __BOOL__
#define __BOOL__
typedef int                 BOOL;
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#define RP_KEY_F1			1
#define RP_KEY_F2			2
#define RP_KEY_F3			3
#define RP_KEY_F4			4
#define RP_KEY_F5			5
#define RP_KEY_F6			6
#define RP_KEY_F7			7
#define RP_KEY_F8			8
#define RP_KEY_F9			9
#define RP_KEY_F10			10
#define RP_KEY_F11			11
#define RP_KEY_F12			12
#define RP_KEY_LEFT			100
#define RP_KEY_UP			101
#define RP_KEY_RIGHT			102
#define RP_KEY_DOWN			103
#define RP_KEY_PAGE_UP		104
#define RP_KEY_PAGE_DOWN		105
#define RP_KEY_HOME			106
#define RP_KEY_END			107
#define RP_KEY_INSERT			108

YZKGAME_API int getRPGameVersion();
YZKGAME_API void setGameSize(int width, int height);
YZKGAME_API int getGameWidth();
YZKGAME_API int getGameHeight();
YZKGAME_API void setViewPortPosition(int x, int y);//设置视口的左下角坐标
YZKGAME_API int getViewPortPositionY();//获取视口的坐标X
YZKGAME_API int getViewPortPositionX();//获取视口的坐标Y

YZKGAME_API int getMousePositionX();//获取鼠标的当前位置X（以左下角为原点）
YZKGAME_API int getMousePositionY();//获取鼠标的当前位置Y（以左下角为原点）
YZKGAME_API BOOL isMouseLeftButtonDown();//判断鼠标左键是否按下
YZKGAME_API void showMouseCursor();//显示鼠标指针
YZKGAME_API void hideMouseCursor();//隐藏鼠标指针


YZKGAME_API void clearGameUI();//清理游戏界面
YZKGAME_API void setBgColor(float red, float green, float b);//设置游戏背景颜色
YZKGAME_API void pauseGame(int millSeconds);
YZKGAME_API void setGameTitle(char* title);
YZKGAME_API void playSound(char* soundName, BOOL repeat);
YZKGAME_API void closeSound(char* soundName);
YZKGAME_API int getPressedKeyCode();//此方法不推荐使用，请使用getPressedNormalKeyCode或者getPressedSpecialKeyCode
YZKGAME_API int getPressedNormalKeyCode();
YZKGAME_API int getPressedSpecialKeyCode();
YZKGAME_API void asyncRun(void(*gameThread)(void *), void* argList);
YZKGAME_API void onNormalKeyUp(void(*func)(unsigned char key));//只能调用一次
YZKGAME_API void onSpecialKeyUp(void(*func)(int key));//只能调用一次


YZKGAME_API void rpInit(void(*gameMain)(void));

YZKGAME_API void createText(int txtNum, char* text);
YZKGAME_API void setText(int txtNum, char* text);
YZKGAME_API void setTextPosition(int txtNum, int x, int y);
YZKGAME_API void setTextColor(int txtNum, float r, float g, float b);
YZKGAME_API void setTextFontSize(int txtNum, int size);
YZKGAME_API void hideText(int num);
YZKGAME_API void showText(int num);
YZKGAME_API int getTextX(int num);
YZKGAME_API int getTextY(int num);
YZKGAME_API BOOL isTextVisible(int num);
YZKGAME_API BOOL isValidText(int num);

YZKGAME_API void setResourcesDir(char* dir);//修改默认的资源路径，默认和当前进程exe同级目录下，给python、java等语言绑定使用

YZKGAME_API void createImage(int num, char* filePath);
YZKGAME_API void setImagePosition(int num, int x, int y);
YZKGAME_API void setImageSource(int num, char* imgName);
YZKGAME_API void showImage(int num);
YZKGAME_API void hideImage(int num);
YZKGAME_API int getImageX(int num);
YZKGAME_API int getImageY(int num);
YZKGAME_API int getImageWidth(int num);
YZKGAME_API int getImageHeight(int num);
YZKGAME_API BOOL isImageVisible(int num);
YZKGAME_API BOOL isValidImage(int num);

YZKGAME_API void createSprite(int num, char* spriteName);
YZKGAME_API void setSpritePosition(int num, int x, int y);
YZKGAME_API void playSpriteAnimate(int num, char* animateName);
YZKGAME_API void setSpriteRepeatPlay(int num, BOOL isRepeat);
YZKGAME_API void setSpriteFlipX(int num, BOOL isFlipX);
YZKGAME_API void setSpriteFlipY(int num, BOOL isFlipY);
YZKGAME_API void hideSprite(int num);
YZKGAME_API void showSprite(int num);
YZKGAME_API int getSpriteX(int num);//易错，不是调用一次就翻转一次
YZKGAME_API int getSpriteY(int num);
YZKGAME_API int getSpriteWidth(int num);
YZKGAME_API int getSpriteHeight(int num);
YZKGAME_API BOOL isSpriteVisible(int num);
YZKGAME_API BOOL isValidSprite(int num);

YZKGAME_API void alert(char* msg,...);
YZKGAME_API BOOL confirm(char* format, ...);

#endif /* YZKGAME_H */
```

## 0x09 倒计时、秒表实现

在补充



## 0x10 实际运用

#### 1.来回跑动的精灵：

```c
#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	int titileText=0;					//编译时要求所有的变量定义要在最开头
	int singleText=1;
	int doubleText=2;
	int demoText=3;
	int x=480 , y =10;
	int image_x=0;
	int font=30;
	int spriteNum = 0;
	int i;
	int fornt = 40;
	int p = 1;
	setGameTitle("C语言游戏引擎");        //显示框的标题
	setGameSize(1200, 675);             //显示框的大小

	createImage(0,"back.png");			//定义背景图
	setImagePosition(0,image_x,0);		//定义背景图的位置
	
	createText(titileText,"算数游戏");		//定义内容文本
	setTextPosition(titileText,x,400);		//定义ni位置
	for(i = 0 ; i < 10 ; i++)				//使得标题逐渐变大
	{   fornt = fornt + 2 ;
		setTextFontSize(titileText,fornt);
		pauseGame(100);
	}
	createText(singleText,"1 单人游戏");
	setTextPosition(singleText,x,340);
	setTextFontSize(singleText,font);

	createText(doubleText,"2 排行榜");ni
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
```

##### 效果图：

[![s9SOpT.png](https://s3.ax1x.com/2021/01/03/s9SOpT.png)](https://imgchr.com/i/s9SOpT)

#### 2.桌面弹球：

```c
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
```

##### 效果图：

[![s9SjcF.png](https://s3.ax1x.com/2021/01/03/s9SjcF.png)](https://imgchr.com/i/s9SjcF)

#### 3.吃金币

- 游戏要求： (1)加载游戏背景图片、创建 1 个 mario 精灵、8 个金币精灵 

​                           (2)控制精灵移动，当 mario 碰到金币时，金币消失，达到吃金币的效果。 

- 需要做的内容：背景图、金币、人物移动、吃金币动作、金币计数、吃炸弹游戏结束

```c
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
}
int main(void)
{
	rpInit(gameMain);
	return 0;
}
```

##### 效果图：

[![s9SvX4.png](https://s3.ax1x.com/2021/01/03/s9SvX4.png)](https://imgchr.com/i/s9SvX4)

## 0x11 算数游戏

```c
正在制作
```

