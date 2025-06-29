#include "polynomial.h"

// 多项式数组初始化
void Poly_Init(Polynomial* poly)
{
	poly->length = 0;
}

// 多项式创建（本程序直接用户输入得）
void Poly_Create(Polynomial* poly)
{
	// 输入多项式的项数
	int len = 0;
	printf("请输入多项式的长度：(注：零多项式的项数为1)");
	scanf("%d", &len);

	// 判断长度是否合法
	if (len > _SIZE_MAX)
	{
		printf("错误，多项式长度超过最大长度！\n");
		return;
	}

	// 输入多项式各个项
	printf("请输如各个项（如3x^2，则输入3 2即可，注:零多项式填0 0）\n");
	for (int i = 0; i < len; i++)
	{
		printf("\t第%d项：", i + 1);
		scanf("%lf %d", &poly->terms[poly->length].coef, &poly->terms[poly->length].exp);

		// 输入的系数为0，指数非零时，不记录
		if (poly->terms[i].coef == 0 && poly->terms[i].exp != 0)
		{
			continue;
		}

		poly->length++;
	}
	printf("多项式创建成功！\n\n");
}

// 多项式的打印
void Poly_Print(Polynomial* poly)
{
	// 判断多项式是否非空
	if (poly->length == 0)
	{
		printf("该多项式不含任何项，异常！\n");
		return;
	}

	// 打印出输入多项式
	for (int i = 0; i < poly->length; i++)
	{
		// 符号处理
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
			printf("出现零项！！！\n");
		}*/

		// 常系数处理
		double absCoef = poly->terms[i].coef >= 0 ? poly->terms[i].coef : -poly->terms[i].coef;
		// 系数不为1或指数为0时，显示系数
		if ((poly->terms[i].coef != 1 && poly->terms[i].coef != -1) 
			|| poly->terms[i].exp == 0)
		{
			printf("%.2lf", absCoef);
		}
		
		// 指数处理
		if (poly->terms[i].exp != 0)	// 指数非0时，显示x
		{
			printf("x");
			if (poly->terms[i].exp > 1)	// 指数大于1，显示x^exp
			{
				printf("^%d", poly->terms[i].exp);
			}
			else if(poly->terms[i].exp < 0)		// 指数为负数，显示x^(exp)
			{
				printf("^(%d)", poly->terms[i].exp);
			}
		}
	}

	printf("\n");
}


