#include <stdio.h>
#include <string.h>

#pragma once

/**
商品结构
*/
typedef struct _product {
	int id;         //唯一ID
	char name[50];   //名称
	double price;    //单价
	int stock;       //库存量，背包中则表示叠加数量
	char desc[200];  //功能描述
}Product;

/**
背包结构
*/
typedef struct _bag {
	int playerId;       //所属玩家ID
	int count;          //当前道具数量
	int max;            //最大数量
	Product products[8]; //道具数组
} Bag;


/**
玩家结构
*/
typedef struct _player {
	int id;             //玩家ID
	char name[50];       //名字
	char password[50];   //密码
	Bag bag;            //玩家背包
	double gold;         //金币
	double sysee;        //元宝
} Player;


Product *pro;
Player *players;

int proLength;
int playersLength;

void init();
void showProducts();
void showPlayers();

/**
交易函数
参数1：参与交易的玩家指针，指针为了方便修改交易后的金币数
参数2：玩家购买的商品ID
*/
void trade(Player *player, int proId);