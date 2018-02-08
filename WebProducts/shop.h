#include <stdio.h>
#include <string.h>

#pragma once

/**
��Ʒ�ṹ
*/
typedef struct _product {
	int id;         //ΨһID
	char name[50];   //����
	double price;    //����
	int stock;       //����������������ʾ��������
	char desc[200];  //��������
}Product;

/**
�����ṹ
*/
typedef struct _bag {
	int playerId;       //�������ID
	int count;          //��ǰ��������
	int max;            //�������
	Product products[8]; //��������
} Bag;


/**
��ҽṹ
*/
typedef struct _player {
	int id;             //���ID
	char name[50];       //����
	char password[50];   //����
	Bag bag;            //��ұ���
	double gold;         //���
	double sysee;        //Ԫ��
} Player;


Product *pro;
Player *players;

int proLength;
int playersLength;

void init();
void showProducts();
void showPlayers();

/**
���׺���
����1�����뽻�׵����ָ�룬ָ��Ϊ�˷����޸Ľ��׺�Ľ����
����2����ҹ������ƷID
*/
void trade(Player *player, int proId);