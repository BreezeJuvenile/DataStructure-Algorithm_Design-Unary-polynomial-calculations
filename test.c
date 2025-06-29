#include "polynomial.h"
#include "auxiliary.h"
#include "operations.h"

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);


// ���ܲ���_����
void test1(void)
{
	Polynomial polyA;

	Poly_Init(&polyA);

	Poly_Create(&polyA);

	// ð������
	AUX_BubbleSort(&polyA);

	Poly_Print(&polyA);
}

// �ӷ�����
void test2(void)
{
	Polynomial polyA, polyB, resPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly);

	printf("����A\n");
	Poly_Create(&polyA);
	printf("����B\n");
	Poly_Create(&polyB);

	// ð������
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	Poly_Print(&polyA); Poly_Print(&polyB);

	// �ӷ�����Ľ��
	OP_Process(&polyA, &polyB, &resPoly, NULL, ADDition);

	// ������
	printf("��ӽ�����£�\n");
	Poly_Print(&resPoly);
}

// ��������
void test3(void)
{
	Polynomial polyA, polyB, resPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly);

	printf("����A\n");
	Poly_Create(&polyA);
	printf("������B\n");
	Poly_Create(&polyB);

	// ð������
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	Poly_Print(&polyA); Poly_Print(&polyB);

	// ��������Ľ��
	OP_Process(&polyA, &polyB, &resPoly, NULL, SUBTRATION);

	// ������
	printf("���������£�\n");
	Poly_Print(&resPoly);
}

// ���ܲ���_�ϲ�ͬ����
void test4(void)
{
	Polynomial polyA;

	Poly_Init(&polyA);

	Poly_Create(&polyA);

	printf("ԭ����ʽ���£�\n");
	Poly_Print(&polyA);

	// �ϲ�ͬ����
	OP_MergeTerms(&polyA);

	printf("�ϲ�ͬ�����\n");
	Poly_Print(&polyA);
}

// �˷�����
void test5(void)
{
	Polynomial polyA, polyB, resPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly);

	printf("����A\n");
	Poly_Create(&polyA);
	printf("����B\n");
	Poly_Create(&polyB);

	// ð������
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	Poly_Print(&polyA); Poly_Print(&polyB);

	// �˷�����Ľ��
	OP_Process(&polyA, &polyB, &resPoly, NULL, MULTIPLICATION);

	// ������
	printf("��˽�����£�\n");
	Poly_Print(&resPoly);
}

// ��������
void test6(void)
{
	Polynomial polyA, polyB, resPoly, remaidPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly); Poly_Init(&remaidPoly);

	printf("��������ʽA\n");
	Poly_Create(&polyA);
	printf("��������ʽB\n");
	Poly_Create(&polyB);

	// ð������
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	printf("��������ʽA��\n");
	printf("\t");
	Poly_Print(&polyA);

	printf("��������ʽB��\n");
	printf("\t");
	Poly_Print(&polyB);

	// ��������Ľ��
	OP_Process(&polyA, &polyB, &resPoly, &remaidPoly, DIVISION);

	// ������
	printf("���������£�\n");
	printf("\t��ʽΪ��");
	Poly_Print(&resPoly);
	printf("\t����ʽΪ��");
	Poly_Print(&remaidPoly);
}

