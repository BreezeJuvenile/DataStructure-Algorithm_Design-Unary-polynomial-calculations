#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define _CRT_SECURE_NO_WARNINGS -1
#include <stdio.h>
#include <stdlib.h>

#define _SIZE_MAX	100

/**
 * @Description ��ṹ�嶨��
 *
 */
typedef struct
{
	double coef;		// ��ϵ��
	int exp;			// ָ��
}Term;

/**
 * @Description ����ʽ�ṹ�����鶨��
 *
 */
typedef struct
{
	Term terms[_SIZE_MAX];		// ����ʽ����
	int length;					// ����ʽ����
}Polynomial;


// ========================= �����ӿڶ��� =============================

// ����ʽ�����ʼ��
void Poly_Init(Polynomial* poly);
// ����ʽ����
void Poly_Create(Polynomial* poly);
// ����ʽ�Ĵ�ӡ
void Poly_Print(Polynomial* poly);


// ===================================================================


#endif