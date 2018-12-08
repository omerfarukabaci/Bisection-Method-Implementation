#include <stdio.h>

float equation(int parameters[], float point);
void findRoots(int parameters[]);
float bisection(int parameters[], float num1, float num2);

int main(void)
{
	int param[5];
	unsigned int i;
	
	for(i=0 ; i<5 ; i++)
		scanf("%d", &param[i]);
		
	printf("Entered equation: %dx^2 + %dx + %d\n", param[0], param[1], param[2]);
	printf("Domain: %d, %d\n", param[3], param[4]);
	
	findRoots(param);
	
	getchar();
	
	return 0;
	
}

float equation(int parameters[], float point)
{
	float result = (parameters[0] * point) * point + parameters[1] * point + parameters[2];
	
	return result;
}

float bisection(int parameters[], float num1, float num2)
{
	float root, abs_temp;
	
	root = (num1+num2)/2;
	
	if (equation(parameters, root)<0)
		abs_temp = -equation(parameters,root);
	else
		abs_temp = equation(parameters,root);
	
	if(abs_temp < 0.001)
		return root;
	else if(equation(parameters, root)*equation(parameters, num1) < 0)
		return bisection(parameters, num1, root);
	else if(equation(parameters, root)*equation(parameters, num1) > 0)
		return bisection(parameters, root, num2);
	
}

void findRoots(int parameters[])
{
	float start, end, middle = 0, i, root1, root2;
	int rootCounter = 0;
	
	start = parameters[3];
	end = parameters[4];
	
	for(i = start ; i<=end ; i+=0.5)
		{
			if ((equation(parameters, i) * equation(parameters, start)) < 0)
			{	
				middle = i;
				rootCounter++;
				break;
			}
			else if((equation(parameters, i) * equation(parameters, start)) == 0)
			{
				middle = i + 0.5;
				start -= 0.5;
				rootCounter++;
				break;
			}
		}
		
	for(i = middle; i<=end ; i+=0.5)
		{
			if ((equation(parameters, i) * equation(parameters, middle)) < 0)
			{			
				end = i;
				rootCounter++;
				break;
			}
			else if((equation(parameters, i) * equation(parameters, middle)) == 0)
			{
				end = i + 0.5;
				rootCounter++;
				break;
			}
		}
		
	if(rootCounter==2)
		printf("Roots: x=%.3f, x=%.3f\n", bisection(parameters, start, middle), bisection(parameters, end, middle));
	else if(rootCounter==1)
		printf("Root: x=%.3f\n", bisection(parameters, start, middle));
	else if(rootCounter==0)
		printf("No roots found\n");
		
	getchar();

	return;
}
