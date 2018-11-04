#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int i=-1;
long int power(long int num1, long int num2)
{
	long int res = num1, p;
	if(num2==0)
		return 1;
	else
	{	
		for(p=1;p<num2;p++)
		{
			res = res*num1;
		}
	}	
	return res;
}
void push(long int arr[], long int num)
{
	i++;
	arr[i] = num;
}
void pop(long int arr[])
{
	if(i==-1)
		printf("Error.\n");
	else	
		i--;
}
long int top(long int arr[])
{
	long int num;
	num = arr[i];
	return num;
}
int main()
{
	long int total=0, arr[1000], infix[1000], num1, num2, j=0, r=0, c=0, temp, res=0, k, q=0, len;
	char str[1000][1000], instr[10000], ch;
	scanf("%[^\n]%*c", instr);
	while(instr[j]!='\0')
	{
		ch = instr[j];
		if(isdigit(ch))
		{
			while(ch!=' ')
			{
				total = (total*10) + (ch-48);
				j++;
				ch = instr[j];
				
			}	
			push(arr, total);
			infix[q] = total;
			q=q+2;
			total=0;
			j++;
		}
		else if(ch!=' ')
		{
			num2 = top(arr);
			pop(arr);
			res = num2;
			num1 = top(arr);
			pop(arr);
			if(ch == '+')
			{
				res = (num1+num2);
				push(arr, res);
				
			}
			else if(ch == '*')
			{
				res = (num1*num2);
				push(arr, res);
			}
			else if(ch == '/')
			{
				res = (num1/num2);
				push(arr, res);
			}
			else if(ch == '-')
			{
				res = (num1-num2);
				push(arr, res);
			}
			else if(ch == '%')
			{
				res = (num1%num2);
				push(arr, res);
			}
			else if(ch == '^')
			{
				res = power(num1,num2);
				push(arr, res);
			}
			j++;				
		}
		else
			j++;
	}
	
	q=q-3;
	len = q+1;
	for(;q>=1;q=q-2)
	{
		infix[q]=-1;
	}
	q=0;
	//2nd traversal
	j=0;
	while(instr[j]!='\0')
	{
		ch = instr[j];
		if(isdigit(ch))
		{
			while(ch!=' ')
			{
				total = (total*10) + (ch-48);
				j++;
				ch = instr[j];
				
			}
			q=q+2;
			total=0;
			j++;
		}
		else if(ch!=' ')
		{
			len = q-3;
			for(;len>=1; len=len-2)
			{
				if(infix[len]==-1)
				{
					if(ch == '+')
					{
						infix[len]=-2;				
					}
					else if(ch == '*')
					{
						infix[len]=-3;
					}
					else if(ch == '/')
					{
						infix[len]=-4;
					}
					else if(ch == '-')
					{
						infix[len]=-5;
					}
					else if(ch == '%')
					{
						infix[len]=-6;
					}
					else if(ch == '^')
					{
						infix[len]=-7;
					}
					break;
				}	
			}
		j++;
		}
		else
			j++;
	}		
	len=q-2; 
	for(q=0;q<=len;q++)
	{
		if(infix[q]==-2)
		{
			printf("+");
		}
		else if(infix[q]==-3)
		{
			printf("*");
		}
		else if(infix[q]==-4)
		{
			printf("/");
		}
		else if(infix[q]==-5)
		{
			printf("-");
		}
		else if(infix[q]==-6)
		{
			printf("%%");
		}
		else if(infix[q]==-7)
		{
			printf("^");
		}
		else
			printf("%ld", infix[q]);
	}
	printf("\n");
	printf("%ld", res);
	return 0;
}
