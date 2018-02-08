#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

//Version :Alpha
/**
1����Ʒ�ṹ-���ơ����ۡ������������
2����ҽṹ-��š����ơ����롢��Ǯ������
3�������ṹ-��ұ�š���Ʒ��10����������������������
*/

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

int proLength = 0;
int playersLength = 0;

void init();
void showProducts();
void showPlayers();

/**
	���׺���
	����1�����뽻�׵����ָ�룬ָ��Ϊ�˷����޸Ľ��׺�Ľ����
	����2����ҹ������ƷID
*/
void trade(Player *player,int proId);

int main()
{
	//1����ʼ��
	init();
	printf("*************����ǰ***************\n");
	//2����ӡ����
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
	printf("*************���׺�***************\n");
	showProducts();
	printf("\n\n");
	showPlayers();
	system("pause");
	return 0;
}

void init() {

	static Product productArray[] = {
		{ 1,"˫�����鿨",3000,10,"˫��666" },
		{ 2,"���õĵ���",5000,8,"ֻ��Զ�۲������� ��" },
		{ 3,"���������",8000,10,"����ר��" },
		{ 4,"�޼�����",13000,5,"��ǹ���룬ˮ����" },
		{ 5,"ֱ��һ����",83000,10,"�����Ժ����ٳԡ�����" }
	};
	proLength = sizeof(productArray) / sizeof(Product);
	pro = productArray;
	static Player playerArray[] = {
		{ 1,"Franco Zhang","123456",.gold = 5000000.0,.bag.max = 8 },
		{ 2,"Fantasy","123456" ,.gold = 50.0,.bag.max = 8 },
		{ 3,"Ԫʼ����֮ͽ","123456" ,.gold = 120.0,.bag.max = 8 },
		{ 4,"�Ǻ�","123456" ,.gold = 500.0,.bag.max = 8 }
	};
	playersLength = sizeof(playerArray) / sizeof(Player);
	players = playerArray;
}

void showProducts() {
	int i;
	if (pro == NULL) return;
	printf("���\t\t����\t\t����\t\t���\t\t��Ʒ����\n");
	for (i = 0; i < proLength; i++)
	{
		printf("%d\t\t%s\t\t%.2lf\t\t%d\t\t%s\n", pro[i].id, pro[i].name, pro[i].price, pro[i].stock, pro[i].desc);
	}
}
void showPlayers() {
	int i,j;
	if (players == NULL) return;
	printf("���\t\t�������\t\t���\n");
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
	//�жϣ���Ʒ��桢��ҽ������ҿռ乻����

	int i;
	Product *tradePro = NULL; //Ҫ�������Ʒ
	for (i = 0; i < proLength; i++)
	{
		if (proId == pro[i].id)
		{
			tradePro = &pro[i]; //��ΪtradePro = pro + i;
			break;
		}
	}
	if (tradePro->stock <= 0)
	{
		printf("������û���������̵걻����ˣ�����\n");
		return;
	}
	if (player->gold < tradePro->price)
	{
		printf("���������𣡣���\n");
		return;
	}
	if (player->bag.count >= player->bag.max && player->bag.max != 0)
	{
		printf("��������������ʧ�ܣ�����\n");
		return;
	}

	//�������������н���
	//1����Ʒ��� -1
	tradePro->stock--;
	//2����ҽ�� - ��Ʒ����
	player->gold -= tradePro->price;
	//3����ұ�����������
	//�ж���ұ������Ƿ����и���Ʒ
	//��û������ӵ�����
	//���У�����Ʒ���� +1
	for  (i = 0; i < player->bag.count; i++)
	{
		if (proId == player->bag.products[i].id) {
			player->bag.products[i].stock++;
			break;
		}
	}
	if (i == player->bag.count)
	{
		//�򱳰����д���һ����Ʒ
		player->bag.products[player->bag.count].id = tradePro->id;
		player->bag.products[player->bag.count].price = tradePro->price;
		player->bag.products[player->bag.count].stock = 1;
		strcpy(player->bag.products[player->bag.count].name,tradePro->name);
		strcpy(player->bag.products[player->bag.count].desc, tradePro->desc);
		player->bag.count++;
	}
}