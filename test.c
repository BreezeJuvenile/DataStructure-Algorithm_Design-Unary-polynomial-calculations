#include "polynomial.h"
#include "auxiliary.h"
#include "operations.h"

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);


// 功能测试_排序
void test1(void)
{
	Polynomial polyA;

	Poly_Init(&polyA);

	Poly_Create(&polyA);

	// 冒泡排序
	AUX_BubbleSort(&polyA);

	Poly_Print(&polyA);
}

// 加法测试
void test2(void)
{
	Polynomial polyA, polyB, resPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly);

	printf("加数A\n");
	Poly_Create(&polyA);
	printf("加数B\n");
	Poly_Create(&polyB);

	// 冒泡排序
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	Poly_Print(&polyA); Poly_Print(&polyB);

	// 加法运算的结果
	OP_Process(&polyA, &polyB, &resPoly, NULL, ADDition);

	// 输出结果
	printf("相加结果如下：\n");
	Poly_Print(&resPoly);
}

// 减法测试
void test3(void)
{
	Polynomial polyA, polyB, resPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly);

	printf("减数A\n");
	Poly_Create(&polyA);
	printf("被减数B\n");
	Poly_Create(&polyB);

	// 冒泡排序
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	Poly_Print(&polyA); Poly_Print(&polyB);

	// 减法运算的结果
	OP_Process(&polyA, &polyB, &resPoly, NULL, SUBTRATION);

	// 输出结果
	printf("相减结果如下：\n");
	Poly_Print(&resPoly);
}

// 功能测试_合并同类项
void test4(void)
{
	Polynomial polyA;

	Poly_Init(&polyA);

	Poly_Create(&polyA);

	printf("原多项式如下：\n");
	Poly_Print(&polyA);

	// 合并同类项
	OP_MergeTerms(&polyA);

	printf("合并同类项后：\n");
	Poly_Print(&polyA);
}

// 乘法测试
void test5(void)
{
	Polynomial polyA, polyB, resPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly);

	printf("乘数A\n");
	Poly_Create(&polyA);
	printf("乘数B\n");
	Poly_Create(&polyB);

	// 冒泡排序
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	Poly_Print(&polyA); Poly_Print(&polyB);

	// 乘法运算的结果
	OP_Process(&polyA, &polyB, &resPoly, NULL, MULTIPLICATION);

	// 输出结果
	printf("相乘结果如下：\n");
	Poly_Print(&resPoly);
}

// 除法测试
void test6(void)
{
	Polynomial polyA, polyB, resPoly, remaidPoly;

	Poly_Init(&polyA); Poly_Init(&polyB); Poly_Init(&resPoly); Poly_Init(&remaidPoly);

	printf("被除多项式A\n");
	Poly_Create(&polyA);
	printf("除数多项式B\n");
	Poly_Create(&polyB);

	// 冒泡排序
	AUX_BubbleSort(&polyA); AUX_BubbleSort(&polyB);

	printf("被除多项式A：\n");
	printf("\t");
	Poly_Print(&polyA);

	printf("除数多项式B：\n");
	printf("\t");
	Poly_Print(&polyB);

	// 除法运算的结果
	OP_Process(&polyA, &polyB, &resPoly, &remaidPoly, DIVISION);

	// 输出结果
	printf("相除结果如下：\n");
	printf("\t商式为：");
	Poly_Print(&resPoly);
	printf("\t余数式为：");
	Poly_Print(&remaidPoly);
}

