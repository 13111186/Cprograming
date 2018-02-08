#include "shop.h"
#pragma warning(disable : 4996)

//Version :Beta
/**
1、商品结构-名称、单价、库存量、描述
2、玩家结构-编号、名称、密码、金钱、背包
3、背包结构-玩家编号、商品【10】、道具数量、最大道具数
*/

int main()
{
	//1、初始化
	init();
	printf("*************交易前***************\n");
	//2、打印数据
	showProducts();
	printf("\n\n");
	showPlayers();
	
	trade(&players[0], 3);
	trade(&players[0], 3);
	trade(&players[0], 3);
	trade(&players[0], 3);
	trade(&players[0], 3);

	trade(&players[0], 3);
	trade(&players[0], 3);
	trade(&players[0], 3);
	trade(&players[0], 3);

	trade(&players[0], 4);
	trade(&players[0], 5);
	printf("*************交易后***************\n");
	showProducts();
	printf("\n\n");
	showPlayers();
	system("pause");
	return 0;
}

