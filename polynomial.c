#include "polynomial.h"

// ����ʽ�����ʼ��
void Poly_Init(Polynomial* poly)
{
	poly->length = 0;
}

// ����ʽ������������ֱ���û�����ã�
void Poly_Create(Polynomial* poly)
{
	// �������ʽ������
	int len = 0;
	printf("���������ʽ�ĳ��ȣ�(ע�������ʽ������Ϊ1)");
	scanf("%d", &len);

	// �жϳ����Ƿ�Ϸ�
	if (len > _SIZE_MAX)
	{
		printf("���󣬶���ʽ���ȳ�����󳤶ȣ�\n");
		return;
	}

	// �������ʽ������
	printf("������������3x^2��������3 2���ɣ�ע:�����ʽ��0 0��\n");
	for (int i = 0; i < len; i++)
	{
		printf("\t��%d�", i + 1);
		scanf("%lf %d", &poly->terms[poly->length].coef, &poly->terms[poly->length].exp);

		// �����ϵ��Ϊ0��ָ������ʱ������¼
		if (poly->terms[i].coef == 0 && poly->terms[i].exp != 0)
		{
			continue;
		}

		poly->length++;
	}
	printf("����ʽ�����ɹ���\n\n");
}

// ����ʽ�Ĵ�ӡ
void Poly_Print(Polynomial* poly)
{
	// �ж϶���ʽ�Ƿ�ǿ�
	if (poly->length == 0)
	{
		printf("�ö���ʽ�����κ���쳣��\n");
		return;
	}

	// ��ӡ���������ʽ
	for (int i = 0; i < poly->length; i++)
	{
		// ���Ŵ���
		if (poly->terms[i].coef > 0)
		{
			if (i != 0)
			{
				printf(" + ");
			}
			
		}
		else if (poly->terms[i].coef < 0)
		{
			printf(" - ");
		}
		/*else
		{
			printf("�����������\n");
		}*/

		// ��ϵ������
		double absCoef = poly->terms[i].coef >= 0 ? poly->terms[i].coef : -poly->terms[i].coef;
		// ϵ����Ϊ1��ָ��Ϊ0ʱ����ʾϵ��
		if ((poly->terms[i].coef != 1 && poly->terms[i].coef != -1) 
			|| poly->terms[i].exp == 0)
		{
			printf("%.2lf", absCoef);
		}
		
		// ָ������
		if (poly->terms[i].exp != 0)	// ָ����0ʱ����ʾx
		{
			printf("x");
			if (poly->terms[i].exp > 1)	// ָ������1����ʾx^exp
			{
				printf("^%d", poly->terms[i].exp);
			}
			else if(poly->terms[i].exp < 0)		// ָ��Ϊ��������ʾx^(exp)
			{
				printf("^(%d)", poly->terms[i].exp);
			}
		}
	}

	printf("\n");
}


