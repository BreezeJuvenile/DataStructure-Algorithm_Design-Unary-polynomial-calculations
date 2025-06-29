#include "operations.h"

/**
/**
* @Description 多项式运算总处理
*
* @param Polynomial* polyA 多项式A
* @param Polynomial* polyB 多项式B
* @param Polynomial* resPoly 结果多项式
* @param Polynomial* remaindPoly 余数多项式
* @return void
*/
void OP_Process(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly, Polynomial* remaindPoly, Operations op)
{
	switch (op)
	{
	case ADDition:			// 加法
		printf("加法运算如下：\n");
		OP_AddPoly(polyA, polyB, resPoly);
		break;
	case SUBTRATION:		// 减法
		printf("减法运算如下：\n");
		OP_SubPoly(polyA, polyB, resPoly);
		break;
	case MULTIPLICATION:	// 乘法
		printf("乘法运算如下：\n");
		OP_MultiPoly(polyA, polyB, resPoly);
		break;
	case DIVISION:			// 除法
		printf("除法运算如下：\n");
		OP_DiviPoly(polyA, polyB, resPoly, remaindPoly);
		break;
	case INCLUDE_FOUR:		// 四种同时计算
		break;
	default:
		break;
	}
}


/**
* @Description 多项式加法
* 
* @param Polynomial* polyA 多项式A
* @param Polynomial* polyB 多项式B
* @param Polynomial* resPoly 结果多项式
* @return void
*/
void OP_AddPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly)
{
	// 判断各多项式是否非空
	if (polyA->length == 0)
	{
		printf("异常：多项式A不含任意项！\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("异常：多项式B不含任意项！\n");
		return;
	}

	int i = 0, j = 0, k = 0;
	double tmpSum = 0.0;
	while (i < polyA->length && j < polyB->length)
	{
		// 依次比较各项指数, 较大者给结果多项式，标志后移
		if (polyA->terms[i].exp > polyB->terms[j].exp)
		{
			resPoly->terms[k++] = polyA->terms[i++];
		}
		else if (polyA->terms[i].exp < polyB->terms[j].exp)
		{
			resPoly->terms[k++] = polyB->terms[j++];
		}
		else	// 若指数相等则系数相加，配合指数给结果多项式
		{
			// 系数相加可能为0，故暂存
			tmpSum = polyA->terms[i].coef + polyB->terms[j].coef;

			if (tmpSum != 0)
			{
				resPoly->terms[k].coef = tmpSum;
				resPoly->terms[k].exp = polyA->terms[i].exp;
				k++;
			}
			else
			{
				// 两项抵消，结果多项式的指数和系数均清零
				resPoly->terms[k].coef = 0;
				resPoly->terms[k].exp = 0;
			}
			i++; j++;
		}
	}

	// 剩余项依次给结果多项式
	while (i < polyA->length)
	{
		resPoly->terms[k++] = polyA->terms[i++];
	}
	while (j < polyB->length)
	{
		resPoly->terms[k++] = polyB->terms[j++];
	}

	resPoly->length = k;
}

/**
* @Description 多项式减法
*
* @param Polynomial* polyA 多项式A
* @param Polynomial* polyB 多项式B
* @param Polynomial* resPoly 结果多项式
* @return void
*/
void OP_SubPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly)
{
	// 判断各多项式是否非空
	if (polyA->length == 0)
	{
		printf("异常：多项式A不含任意项！\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("异常：多项式B不含任意项！\n");
		return;
	}

	// 减法相当于是一种特殊的加法
	// 减法 = 减数 + 被减数的相反数

	// 被减数处理
	Polynomial oppositePoly = *polyB;
	for (int i = 0; i < oppositePoly.length; i++)
	{
		oppositePoly.terms[i].coef = -oppositePoly.terms[i].coef;
	}

	// 转变为加法计算
	OP_AddPoly(polyA, &oppositePoly, resPoly);
}

/**
* @Description 多项式中进行合并同类项
*
* @param Polynomial* poly 多项式
* @return void
*/
void OP_MergeTerms(Polynomial* poly)
{
	// 判断多项式是否非空
	if (poly->length == 0)
	{
		printf("异常：多项式A不含任意项！\n");
		return;
	}

	// 给多项式进行降序排列，方便合并项
	AUX_BubbleSort(poly);

	// 仅一项时不必合并
	if (poly->length == 1)	return;

	// 暂存陆续合并后的项
	Polynomial tmpPoly;
	Poly_Init(&tmpPoly);

	int k = 0;
	tmpPoly.terms[k] = poly->terms[0];
	tmpPoly.length = 1;

	// 与后项进行比较，指数相同则系数相加
	for (int i = 1; i < poly->length; i++)
	{
		if (tmpPoly.terms[k].exp == poly->terms[i].exp)
		{
			tmpPoly.terms[k].coef += poly->terms[i].coef;

			// 系数和为0时不计入暂存多项式
			if (tmpPoly.terms[k].coef == 0)
			{
				// 消去系数为0后的项
				tmpPoly.length--;
				k--;
			}
		}
		else
		{
			// 与后项指数不等，则后项插入暂存式末尾，并计数
			k++;
			tmpPoly.terms[k] = poly->terms[i];
			tmpPoly.length++;
		}
	}

	// 最后将合并后的多项式赋给原多项式
	*poly = tmpPoly;
}

/**
* @Description 多项式乘法
*
* @param Polynomial* polyA 多项式A
* @param Polynomial* polyB 多项式B
* @param Polynomial* resPoly 结果多项式
* @return void
*/
void OP_MultiPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly)
{
	// 判断各多项式是否非空
	if (polyA->length == 0)
	{
		printf("异常：多项式A不含任意项！\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("异常：多项式B不含任意项！\n");
		return;
	}

	// 各个项的系数相乘、指数相加，最后合并同类项
	Polynomial midPoly; 
	int k = 0;
	for (int i = 0; i < polyA->length; i++)
	{
		for (int j = 0; j < polyB->length; j++)
		{
			// 单项相乘
			// 乘数含0时，结果为0则将首项变0
			if (i == polyA->length - 1 && j == polyB->length - 1 && k == 0)
			{
				midPoly.terms[k].coef = 0;
				midPoly.terms[k].exp = 0;
				k = 1;
			}
			if (polyA->terms[i].coef * polyB->terms[j].coef == 0)
			{
				continue;
			}
			midPoly.terms[k].coef = polyA->terms[i].coef * polyB->terms[j].coef;
			midPoly.terms[k].exp = polyA->terms[i].exp + polyB->terms[j].exp;
			k++;

			// 不可超过项的最大数量
			if (k > _SIZE_MAX)
			{
				printf("异常：乘法运算产生的项数超过最大数量！\n");
				return;
			}
		}
	}
	midPoly.length = k;

	// 合并同类项
	OP_MergeTerms(&midPoly);
	*resPoly = midPoly;
}

/**
* @Description 多项式除法
*
* @param Polynomial* polyA 多项式A
* @param Polynomial* polyB 多项式B
* @param Polynomial* resPoly 结果多项式
* @param Polynomial* remaindPoly 余数多项式
* @return void
*/
void OP_DiviPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly, Polynomial* remaindPoly)
{
	// 判断各多项式是否非空
	if (polyA->length == 0)
	{
		printf("异常：多项式A不含任意项！\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("异常：多项式B不含任意项！\n");
		return;
	}

	// 模拟“长除法”进行多项式除法求商和余数

	// 记录一下被除数
	Polynomial tmpPolyA = *polyA;
	Polynomial tmpTerms; Poly_Init(&tmpTerms);
	Polynomial tmpPoly; Poly_Init(&tmpPoly);
	Polynomial tmpResPoly; Poly_Init(&tmpResPoly);
	int isDiv = 1;

	// 被除式和除时都为0时商和余数都为0
	if ((tmpPolyA.terms[0].coef == 0 && tmpPolyA.length == 1) || polyB->terms[0].coef == 0)
	{
		resPoly->length = 1; resPoly->terms[0].coef = 0; resPoly->terms[0].exp = 0;
		remaindPoly->length = 1; remaindPoly->terms[0].coef = 0; remaindPoly->terms[0].exp = 0;
	}


	while (1)
	{
		// 1. 被除数与除数的次数最高项作除法
		// 前提：被除数的最高次>=除数的最高次,除式最高次大于被除式时，商为0，余式为被除式
		if (tmpPolyA.terms[0].exp < polyB->terms[0].exp)
		{
			resPoly->length = 1; resPoly->terms[0].coef = 0; resPoly->terms[0].exp = 0;
			*remaindPoly = *polyA;
			return;
		}
		// 系数相除、指数相减
		tmpTerms.terms[tmpTerms.length].coef = tmpPolyA.terms[0].coef / polyB->terms[0].coef;
		tmpTerms.terms[tmpTerms.length].exp = tmpPolyA.terms[0].exp - polyB->terms[0].exp;
		tmpTerms.length++;

		// 2. 暂存项与除数相乘，暂存多项式
		for (int i = 0; i < polyB->length; i++)
		{
			// 相乘暂存多项式的项数不可超过项数最大值
			if (tmpPoly.length >= _SIZE_MAX)
			{
				printf("异常：项数超过最大数量！\n");
				return;
			}

			tmpPoly.terms[tmpPoly.length].coef = tmpTerms.terms[tmpTerms.length - 1].coef * polyB->terms[i].coef;
			tmpPoly.terms[tmpPoly.length].exp = tmpTerms.terms[tmpTerms.length - 1].exp + polyB->terms[i].exp;
			tmpPoly.length++;
		}
		// 合并同类项
		OP_MergeTerms(&tmpPoly);

		/*printf("暂存项为：\n");
		Poly_Print(&tmpTerms);
		printf("暂存多项式为：\n");
		Poly_Print(&tmpPoly);*/

		// 3. 被除式与暂存多项式作减法，暂存结果多项式
		OP_SubPoly(&tmpPolyA, &tmpPoly, &tmpResPoly);

		/*printf("暂存结果多项式为：\n");
		Poly_Print(&tmpResPoly);*/

		// 更新被除数
		if (tmpResPoly.terms[0].exp >= polyB->terms[0].exp)
		{
			tmpPolyA = tmpResPoly;
			/*printf("新的被除多项式为：\n");
			Poly_Print(&tmpPolyA);*/

			// 清空暂存多项式
			tmpPoly.length = 0;
		}
		else
		{
			break;
		}
	}
	// 除法结束，暂存结果多项式即为此次除法的余数
	*remaindPoly = tmpResPoly;
	if (remaindPoly->length == 0)
	{
		// 余数为0，项数置1，避免报错余数式不存在
		remaindPoly->length = 1;
	}
	*resPoly = tmpTerms;
}
