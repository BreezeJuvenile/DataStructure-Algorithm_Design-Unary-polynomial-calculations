#include "operations.h"

/**
/**
* @Description ����ʽ�����ܴ���
*
* @param Polynomial* polyA ����ʽA
* @param Polynomial* polyB ����ʽB
* @param Polynomial* resPoly �������ʽ
* @param Polynomial* remaindPoly ��������ʽ
* @return void
*/
void OP_Process(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly, Polynomial* remaindPoly, Operations op)
{
	switch (op)
	{
	case ADDition:			// �ӷ�
		printf("�ӷ��������£�\n");
		OP_AddPoly(polyA, polyB, resPoly);
		break;
	case SUBTRATION:		// ����
		printf("�����������£�\n");
		OP_SubPoly(polyA, polyB, resPoly);
		break;
	case MULTIPLICATION:	// �˷�
		printf("�˷��������£�\n");
		OP_MultiPoly(polyA, polyB, resPoly);
		break;
	case DIVISION:			// ����
		printf("�����������£�\n");
		OP_DiviPoly(polyA, polyB, resPoly, remaindPoly);
		break;
	case INCLUDE_FOUR:		// ����ͬʱ����
		break;
	default:
		break;
	}
}


/**
* @Description ����ʽ�ӷ�
* 
* @param Polynomial* polyA ����ʽA
* @param Polynomial* polyB ����ʽB
* @param Polynomial* resPoly �������ʽ
* @return void
*/
void OP_AddPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly)
{
	// �жϸ�����ʽ�Ƿ�ǿ�
	if (polyA->length == 0)
	{
		printf("�쳣������ʽA���������\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("�쳣������ʽB���������\n");
		return;
	}

	int i = 0, j = 0, k = 0;
	double tmpSum = 0.0;
	while (i < polyA->length && j < polyB->length)
	{
		// ���αȽϸ���ָ��, �ϴ��߸��������ʽ����־����
		if (polyA->terms[i].exp > polyB->terms[j].exp)
		{
			resPoly->terms[k++] = polyA->terms[i++];
		}
		else if (polyA->terms[i].exp < polyB->terms[j].exp)
		{
			resPoly->terms[k++] = polyB->terms[j++];
		}
		else	// ��ָ�������ϵ����ӣ����ָ�����������ʽ
		{
			// ϵ����ӿ���Ϊ0�����ݴ�
			tmpSum = polyA->terms[i].coef + polyB->terms[j].coef;

			if (tmpSum != 0)
			{
				resPoly->terms[k].coef = tmpSum;
				resPoly->terms[k].exp = polyA->terms[i].exp;
				k++;
			}
			else
			{
				// ����������������ʽ��ָ����ϵ��������
				resPoly->terms[k].coef = 0;
				resPoly->terms[k].exp = 0;
			}
			i++; j++;
		}
	}

	// ʣ�������θ��������ʽ
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
* @Description ����ʽ����
*
* @param Polynomial* polyA ����ʽA
* @param Polynomial* polyB ����ʽB
* @param Polynomial* resPoly �������ʽ
* @return void
*/
void OP_SubPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly)
{
	// �жϸ�����ʽ�Ƿ�ǿ�
	if (polyA->length == 0)
	{
		printf("�쳣������ʽA���������\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("�쳣������ʽB���������\n");
		return;
	}

	// �����൱����һ������ļӷ�
	// ���� = ���� + ���������෴��

	// ����������
	Polynomial oppositePoly = *polyB;
	for (int i = 0; i < oppositePoly.length; i++)
	{
		oppositePoly.terms[i].coef = -oppositePoly.terms[i].coef;
	}

	// ת��Ϊ�ӷ�����
	OP_AddPoly(polyA, &oppositePoly, resPoly);
}

/**
* @Description ����ʽ�н��кϲ�ͬ����
*
* @param Polynomial* poly ����ʽ
* @return void
*/
void OP_MergeTerms(Polynomial* poly)
{
	// �ж϶���ʽ�Ƿ�ǿ�
	if (poly->length == 0)
	{
		printf("�쳣������ʽA���������\n");
		return;
	}

	// ������ʽ���н������У�����ϲ���
	AUX_BubbleSort(poly);

	// ��һ��ʱ���غϲ�
	if (poly->length == 1)	return;

	// �ݴ�½���ϲ������
	Polynomial tmpPoly;
	Poly_Init(&tmpPoly);

	int k = 0;
	tmpPoly.terms[k] = poly->terms[0];
	tmpPoly.length = 1;

	// �������бȽϣ�ָ����ͬ��ϵ�����
	for (int i = 1; i < poly->length; i++)
	{
		if (tmpPoly.terms[k].exp == poly->terms[i].exp)
		{
			tmpPoly.terms[k].coef += poly->terms[i].coef;

			// ϵ����Ϊ0ʱ�������ݴ����ʽ
			if (tmpPoly.terms[k].coef == 0)
			{
				// ��ȥϵ��Ϊ0�����
				tmpPoly.length--;
				k--;
			}
		}
		else
		{
			// �����ָ�����ȣ����������ݴ�ʽĩβ��������
			k++;
			tmpPoly.terms[k] = poly->terms[i];
			tmpPoly.length++;
		}
	}

	// ��󽫺ϲ���Ķ���ʽ����ԭ����ʽ
	*poly = tmpPoly;
}

/**
* @Description ����ʽ�˷�
*
* @param Polynomial* polyA ����ʽA
* @param Polynomial* polyB ����ʽB
* @param Polynomial* resPoly �������ʽ
* @return void
*/
void OP_MultiPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly)
{
	// �жϸ�����ʽ�Ƿ�ǿ�
	if (polyA->length == 0)
	{
		printf("�쳣������ʽA���������\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("�쳣������ʽB���������\n");
		return;
	}

	// �������ϵ����ˡ�ָ����ӣ����ϲ�ͬ����
	Polynomial midPoly; 
	int k = 0;
	for (int i = 0; i < polyA->length; i++)
	{
		for (int j = 0; j < polyB->length; j++)
		{
			// �������
			// ������0ʱ�����Ϊ0�������0
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

			// ���ɳ�������������
			if (k > _SIZE_MAX)
			{
				printf("�쳣���˷���������������������������\n");
				return;
			}
		}
	}
	midPoly.length = k;

	// �ϲ�ͬ����
	OP_MergeTerms(&midPoly);
	*resPoly = midPoly;
}

/**
* @Description ����ʽ����
*
* @param Polynomial* polyA ����ʽA
* @param Polynomial* polyB ����ʽB
* @param Polynomial* resPoly �������ʽ
* @param Polynomial* remaindPoly ��������ʽ
* @return void
*/
void OP_DiviPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly, Polynomial* remaindPoly)
{
	// �жϸ�����ʽ�Ƿ�ǿ�
	if (polyA->length == 0)
	{
		printf("�쳣������ʽA���������\n");
		return;
	}
	if (polyB->length == 0)
	{
		printf("�쳣������ʽB���������\n");
		return;
	}

	// ģ�⡰�����������ж���ʽ�������̺�����

	// ��¼һ�±�����
	Polynomial tmpPolyA = *polyA;
	Polynomial tmpTerms; Poly_Init(&tmpTerms);
	Polynomial tmpPoly; Poly_Init(&tmpPoly);
	Polynomial tmpResPoly; Poly_Init(&tmpResPoly);
	int isDiv = 1;

	// ����ʽ�ͳ�ʱ��Ϊ0ʱ�̺�������Ϊ0
	if ((tmpPolyA.terms[0].coef == 0 && tmpPolyA.length == 1) || polyB->terms[0].coef == 0)
	{
		resPoly->length = 1; resPoly->terms[0].coef = 0; resPoly->terms[0].exp = 0;
		remaindPoly->length = 1; remaindPoly->terms[0].coef = 0; remaindPoly->terms[0].exp = 0;
	}


	while (1)
	{
		// 1. ������������Ĵ��������������
		// ǰ�᣺����������ߴ�>=��������ߴ�,��ʽ��ߴδ��ڱ���ʽʱ����Ϊ0����ʽΪ����ʽ
		if (tmpPolyA.terms[0].exp < polyB->terms[0].exp)
		{
			resPoly->length = 1; resPoly->terms[0].coef = 0; resPoly->terms[0].exp = 0;
			*remaindPoly = *polyA;
			return;
		}
		// ϵ�������ָ�����
		tmpTerms.terms[tmpTerms.length].coef = tmpPolyA.terms[0].coef / polyB->terms[0].coef;
		tmpTerms.terms[tmpTerms.length].exp = tmpPolyA.terms[0].exp - polyB->terms[0].exp;
		tmpTerms.length++;

		// 2. �ݴ����������ˣ��ݴ����ʽ
		for (int i = 0; i < polyB->length; i++)
		{
			// ����ݴ����ʽ���������ɳ����������ֵ
			if (tmpPoly.length >= _SIZE_MAX)
			{
				printf("�쳣�������������������\n");
				return;
			}

			tmpPoly.terms[tmpPoly.length].coef = tmpTerms.terms[tmpTerms.length - 1].coef * polyB->terms[i].coef;
			tmpPoly.terms[tmpPoly.length].exp = tmpTerms.terms[tmpTerms.length - 1].exp + polyB->terms[i].exp;
			tmpPoly.length++;
		}
		// �ϲ�ͬ����
		OP_MergeTerms(&tmpPoly);

		/*printf("�ݴ���Ϊ��\n");
		Poly_Print(&tmpTerms);
		printf("�ݴ����ʽΪ��\n");
		Poly_Print(&tmpPoly);*/

		// 3. ����ʽ���ݴ����ʽ���������ݴ�������ʽ
		OP_SubPoly(&tmpPolyA, &tmpPoly, &tmpResPoly);

		/*printf("�ݴ�������ʽΪ��\n");
		Poly_Print(&tmpResPoly);*/

		// ���±�����
		if (tmpResPoly.terms[0].exp >= polyB->terms[0].exp)
		{
			tmpPolyA = tmpResPoly;
			/*printf("�µı�������ʽΪ��\n");
			Poly_Print(&tmpPolyA);*/

			// ����ݴ����ʽ
			tmpPoly.length = 0;
		}
		else
		{
			break;
		}
	}
	// �����������ݴ�������ʽ��Ϊ�˴γ���������
	*remaindPoly = tmpResPoly;
	if (remaindPoly->length == 0)
	{
		// ����Ϊ0��������1�����ⱨ������ʽ������
		remaindPoly->length = 1;
	}
	*resPoly = tmpTerms;
}
