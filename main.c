#include "polynomial.h"
#include "auxiliary.h"
#include "operations.h"
//#include <stdbool.h>


void Calc_Output(Polynomial* resPoly, Polynomial* remaindPoly, Operations op);


int main(void)
{
	printf("\t===================== 一元多项式的运算 ====================\n\n");
	
	Polynomial polyA, polyB, resPoly, remaidPoly;
	int flag = 0;
	Operations op = ADDition;

	/* 1. 多项式的初始化 */
	Poly_Init(&polyA); 
	Poly_Init(&polyB);
	Poly_Init(&resPoly);
	Poly_Init(&remaidPoly);

	while (1)
	{
		/* 2. 多项式输入 */
		switch (flag)
		{
		case 0:
		{
			printf("---------------------- 多项式A ----------------------\n\n");
			Poly_Create(&polyA);
			printf("您输入的多项式A为：");
			Poly_Print(&polyA);
			printf("\n");

			int isRightA = 1;
			printf("请确认您输入的多项式A是否正确：（正确输1，错误输0）");
			scanf("%d", &isRightA);
			if (isRightA == 0)
			{
				printf("大意了哈，A输错了，那重新输入吧！\n");
				polyA.length = 0;
				continue;
			}
			flag++;
			AUX_BubbleSort(&polyA);
			break;
		}
		case 1:
		{
			printf("\n------------------ 多项式B ------------------\n");
			Poly_Create(&polyB);
			printf("您输入的多项式B为：");
			Poly_Print(&polyB);
			printf("\n");

			int isRightB = 1;
			printf("请确认您输入的多项式B是否正确：（正确按1，错误按0）");
			scanf("%d", &isRightB);
			if (isRightB == 0)
			{
				printf("大意了哈，B输错了，那重新输入吧！\n");
				polyB.length = 0;
				continue;
			}
			flag++;
			AUX_BubbleSort(&polyB);
			break;
		}
		default:
			break;
		}
		
		if (flag % 2 == 0)	break;
	}

	while (1)
	{
		printf("\n-------------------- 运算部分 --------------------\n\n");
		/* 3. 选择运算法则（含+ - x /） */
		printf("请选择您想进行的运算：（加法按1，减法按2，乘法按3，除法按4，四种均进行按5）");
		scanf("%d", &op);
		printf("\n");

		/* 4. 执行并输出运算结果 */
		if (op == 5)
		{
			for (int i = 1; i < op; i++)
			{
				OP_Process(&polyA, &polyB, &resPoly, &remaidPoly, i);
				Calc_Output(&resPoly, &remaidPoly, i);
			}
		}
		else
		{
			OP_Process(&polyA, &polyB, &resPoly, &remaidPoly, op);
			Calc_Output(&resPoly, &remaidPoly, op);
		}
		printf("\n");

		int isCalc = 0;
		printf("您还想对这俩式子进行运算吗？(想则按1，退出则按0)  ");
		scanf("%d", &isCalc);
		if (isCalc == 1)
		{
			printf("看来您还对运算意犹未尽呢，那就继续！\n\n");
		}
		else
		{
			printf("\n============ 感谢您的使用，欢迎下次再来！==============\n");
			return 0;
		}
	}
		
	
	return 0;
}

// 输出运算结果
void Calc_Output(Polynomial* resPoly, Polynomial* remaindPoly, Operations op)
{
	switch (op)
	{
	case ADDition:
	case SUBTRATION:
	case MULTIPLICATION:
		Poly_Print(resPoly);
		break;
	case DIVISION:
		printf("\t商式为：");
		Poly_Print(resPoly);
		printf("\t余数式为：");
		Poly_Print(remaindPoly);
		break;
	default:
		break;
	}
}
