#include "shop.h"
#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)
Product *pro;
Player *players;

int proLength = 0;
int playersLength = 0;

void init() {

	static Product productArray[] = {
		{ 1,"双倍经验卡",3000,10,"双击666" },
	{ 2,"糜烂的道袍",5000,8,"只可远观不可亵玩 ！" },
	{ 3,"生锈的铁剑",8000,10,"新手专用" },
	{ 4,"无极道袍",13000,5,"刀枪不入，水火不侵" },
	{ 5,"直升一级丹",83000,10,"吃了以后还想再吃。。。" }
	};
	proLength = sizeof(productArray) / sizeof(Product);
	pro = productArray;
	static Player playerArray[] = {
		{ 1,"Franco Zhang","123456",.gold = 5000000.0,.bag.max = 8 },
	{ 2,"Fantasy","123456" ,.gold = 50.0,.bag.max = 8 },
	{ 3,"元始天尊之徒","123456" ,.gold = 120.0,.bag.max = 8 },
	{ 4,"星河","123456" ,.gold = 500.0,.bag.max = 8 }
	};
	playersLength = sizeof(playerArray) / sizeof(Player);
	players = playerArray;
}

void showProducts() {
	int i;
	if (pro == NULL) return;
	printf("编号\t\t名称\t\t单价\t\t库存\t\t商品介绍\n");
	for (i = 0; i < proLength; i++)
	{
		printf("%d\t\t%s\t\t%.2lf\t\t%d\t\t%s\n", pro[i].id, pro[i].name, pro[i].price, pro[i].stock, pro[i].desc);
	}
}
void showPlayers() {
	int i, j;
	if (players == NULL) return;
	printf("编号\t\t玩家名称\t\t金币\n");
	for (i = 0; i < playersLength; i++)
	{
		printf("%d\t\t%s\t\t%.0lf", players[i].id, players[i].name, players[i].gold);
		for (j = 0; j < players[i].bag.count; j++)
		{
			printf("\t%s\t%d", players[i].bag.products[j].name, players[i].bag.products[j].stock);
		}
		printf("\n");
	}

}

void trade(Player *player, int proId) {
	//判断：商品库存、玩家金币余额、玩家空间够不够

	int i;
	Product *tradePro = NULL; //要购买的商品
	for (i = 0; i < proLength; i++)
	{
		if (proId == pro[i].id)
		{
			tradePro = &pro[i]; //即为tradePro = pro + i;
			break;
		}
	}
	if (tradePro->stock <= 0)
	{
		printf("地主家没有余粮，商店被买空了！！！\n");
		return;
	}
	if (player->gold < tradePro->price)
	{
		printf("你可真穷，买不起！！！\n");
		return;
	}
	if (player->bag.count >= player->bag.max && player->bag.max != 0)
	{
		printf("背包已满，交易失败！！！\n");
		return;
	}

	//满足条件，进行交易
	//1、商品库存 -1
	tradePro->stock--;
	//2、玩家金币 - 商品单价
	player->gold -= tradePro->price;
	//3、玩家背包道具增加
	//判断玩家背包中是否已有该商品
	//若没有则添加到背包
	//若有，该商品总数 +1
	for (i = 0; i < player->bag.count; i++)
	{
		if (proId == player->bag.products[i].id) {
			player->bag.products[i].stock++;
			break;
		}
	}
	if (i == player->bag.count)
	{
		//向背包当中创建一个商品
		player->bag.products[player->bag.count].id = tradePro->id;
		player->bag.products[player->bag.count].price = tradePro->price;
		player->bag.products[player->bag.count].stock = 1;
		strcpy(player->bag.products[player->bag.count].name, tradePro->name);
		strcpy(player->bag.products[player->bag.count].desc, tradePro->desc);
		player->bag.count++;
	}
}