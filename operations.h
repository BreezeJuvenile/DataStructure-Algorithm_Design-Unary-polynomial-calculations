#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include "polynomial.h"
#include "auxiliary.h"

// 枚举运算规则
typedef enum
{
	ADDition = 1,		// 默认加法
	SUBTRATION,
	MULTIPLICATION,
	DIVISION,
	INCLUDE_FOUR
}Operations;

void OP_Process(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly, Polynomial* remaindPoly, Operations op);
void OP_AddPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly);
void OP_SubPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly);
void OP_MultiPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly);
void OP_MergeTerms(Polynomial* poly);
void OP_DiviPoly(Polynomial* polyA, Polynomial* polyB, Polynomial* resPoly, Polynomial* RemaindPoly);

#endif
