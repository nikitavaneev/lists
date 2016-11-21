// lists.cpp: определяет точку входа для консольного приложения.
//


#include <stdio.h>
struct node
{
	char s;
	node *next;
};

void Add(node **d, char s)
{
	node *a = new node;
	a->next = *d;
	a->s = s;
	*d = a;
}

bool isCorrect(char *stroka)
{
	node *d = 0;
	for (int i = 0; stroka[i] != 0; i++)
		if ((stroka[i] == '(') || (stroka[i] == '{') || (stroka[i] == '['))
			Add(&d, stroka[i]);
		else
		{
			if ((d->s != '(') && (stroka[i] == ')'))
				return false;
			if ((d->s != '[') && (stroka[i] == ']'))
				return false;
			if ((d->s != '{') && (stroka[i] == '}'))
				return false;
			d = d->next;
		}
	if (d == 0)
		return true;
	else
		return false;
}

void res(char *stroka)
{
	if (isCorrect(stroka) == true)
		printf("%s:true\n", stroka);
	else
		printf("%s:false\n", stroka);
}

void main()
{
	char stroka[1] = "";
	char stroka1[3] = "((";
	char stroka2[3] = "()";
	char stroka3[5] = "[](]";
	char stroka4[7] = "{[()]}";
	char stroka5[6] = "[{)))";
	char stroka6[7] = "[]{}()";
	char stroka7[3] = "[}";
	char stroka8[5] = "([)]";
	char stroka9[7] = "{[]()}";
	res(stroka);
	res(stroka1);
	res(stroka2);
	res(stroka3);
	res(stroka4);
	res(stroka5);
	res(stroka6);
	res(stroka7);
	res(stroka8);
	res(stroka9);
	getchar();
}



