#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define _CRT_SECURE_NO_WARNINGS -1
#include <stdio.h>
#include <stdlib.h>

#define _SIZE_MAX	100

/**
 * @Description 项结构体定义
 *
 */
typedef struct
{
	double coef;		// 常系数
	int exp;			// 指数
}Term;

/**
 * @Description 多项式结构体数组定义
 *
 */
typedef struct
{
	Term terms[_SIZE_MAX];		// 多项式数组
	int length;					// 多项式长度
}Polynomial;


// ========================= 函数接口定义 =============================

// 多项式数组初始化
void Poly_Init(Polynomial* poly);
// 多项式创建
void Poly_Create(Polynomial* poly);
// 多项式的打印
void Poly_Print(Polynomial* poly);


// ===================================================================


#endif