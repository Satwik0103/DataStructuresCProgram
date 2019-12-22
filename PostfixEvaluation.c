#include<string.h>
#include"stacks.h"

int Prcd(char x,char y)
{
    if(x=='^'||x=='*'||x=='/'||x=='%')
    {
        if(y=='^')
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        if(x=='+'||x=='-')
        {
            if(y=='+'||y=='-')
            {
                return TRUE;
            }
            else
                return FALSE;
        }
    }
}

int evaluate(int op1,int op2,char op)
{   int i;
    switch(op)
    {
        case '+': return(op1+op2);
        //break;
        case '-': return(op1-op2);
        //break;
        case '*': return(op1*op2);
        //break;
        case '/': return(op1/op2);
        //break;
        case '%': return(op1%op2);
        //break;
        case '^':for(i=1;i<=op2;i++)
                return(op1*op1);
         //       break;
    }
}

int PostfixE(char postfix[])
{
    int opd1,opd2,i=0,value,x;
    char symbol;

    while(postfix[i]!='\0')
    {
         symbol=postfix[i];
         if (symbol>47&&symbol<58)
         {
            Push(symbol-48);
         }
         else
         {
                opd2=Pop();
                opd1=Pop();
                value=evaluate(opd1,opd2,symbol);
                Push(value);
         }
         i++;
    }
    x=Pop();
    for(i=0;postfix[i]!='\0';i++)
    {
        printf("%d",postfix[i]);
    }
}
int PrefixE(char prefix[])
{
    int opd1,opd2,i=0,value,x;
    char symbol;
    reverse(prefix);
    while(prefix[i]!='\0')
    {
         symbol=prefix[i];
         if (symbol>47&&symbol<58)
         {
            Push(symbol-48);
         }
         else
         {
                opd1=Pop();
                opd2=Pop();
                value=evaluate(opd1,opd2,symbol);
                Push(value);
         }
         i++;
    }
    x=Pop();
    return x;
}
int InToPost(char infix[])
{
    char postfix[20];
    int i=0,j=0;
    char x;
    char symbol;
    Initialize();
    while(infix[i]!='\0')
    {
        symbol=infix[i];
        if (symbol>='a'&&symbol<='z')
         {
            postfix[j++]=symbol;
         }
          else
         {
                while(!Empty() && Prcd(StackTop(),symbol))
                {
                    x=Pop();
                    postfix[j++]=x;

                }
                Push(symbol);
        }
        i++;

    }
    while(!Empty())
    {
        x=Pop();
        postfix[j++]=x;
    }
    //return x;
    //PostfixE(postfix);
     postfix[j]='\0';
     int k=0;

        printf("%s",postfix);
}
int InToPre(char infix[])
{
    char prefix[20];
    int i=0,j=0;
    char x;
    char symbol;
    Initialize();
    reverse(infix);
    while(infix[i]!='\0')
    {
        symbol=infix[i];

        if (symbol>='a'&&symbol<='z')
         {
            prefix[j++]=symbol;
         }
          else
         {
                while(!Empty()&&!Prcd(StackTop(),symbol))
                {
                    x=Pop();
                    prefix[j++]=x;
                }
                Push(symbol);
        }
        i++;

    }
    while(!Empty())
    {
        x=Pop();
        prefix[j++]=x;
    }
    //return x;
    //PostfixE(postfix);
     prefix[j]='\0';
     int k=0;
     reverse(prefix);
        printf("%s",prefix);
}

int main()
{
    //Initialize();
    int x,i;
    char a='%';
    char b='*';
    char str[50];
    printf("Enter string");
    gets(str);
    InToPre(str);
    //printf("%d",x);
   /* x=Prcd(a,b);
    printf("%d",x);
   for(i=0;i<255;i++)
    {
        printf("%d %c,\t",i,i);
    }
    */

    return 0;
}
