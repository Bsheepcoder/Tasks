#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("µ¹¼ÆÊ±");
	setGameSize(338, 338);
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}