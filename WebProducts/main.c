#include "shop.h"
#pragma warning(disable : 4996)

//Version :Beta
/**
1����Ʒ�ṹ-���ơ����ۡ������������
2����ҽṹ-��š����ơ����롢��Ǯ������
3�������ṹ-��ұ�š���Ʒ��10����������������������
*/

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

