#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*Left;
    struct node*Right;
};
struct node*GetNode()
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
struct node*MakeNode(int x)
{
    struct node*p;
    p=GetNode();
    p->data=x;
    p->Left=NULL;
    p->Right=NULL;
    return p;
}
struct node*CreateTree(struct node*t)
{
    struct node*N;
    int choice,x;
    printf("Whether left of %d exists?(1/0)\n",t->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Input data on left%d\n",t->data);
        scanf("%d",&x);
        N=MakeNode(x);
        t->Left=N;
        CreateTree(N);
    }
    printf("Whether right of %d exists?(1/0)\n",t->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Input data on right%d\n",t->data);
        scanf("%d",&x);
        N=MakeNode(x);
        t->Right=N;
        CreateTree(N);
    }
}
struct node*PreOrderTraversal(struct node*t)
{
    if(t!=NULL)
    {
        printf("\t%d",t->data);
        PreOrderTraversal(t->Left);
        PreOrderTraversal(t->Right);
    }
}
struct node*InOrderTraversal(struct node*t)
{
    if(t!=NULL)
    {
        InOrderTraversal(t->Left);
        printf("\t%d",t->data);
        InOrderTraversal(t->Right);
    }
}
struct node*PostOrderTraversal(struct node*t)
{
    if(t!=NULL)
    {
        PostOrderTraversal(t->Left);
        PostOrderTraversal(t->Right);
        printf("\t%d",t->data);

    }
}
int CountNode(struct node*t)
{
    if(t==NULL)
        return 0;
    else
        return (1+CountNode(t->Left)+CountNode(t->Right));
}
int max(int a ,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(struct node*t)
{
    if(t==NULL)
        return 0;
    else
    {
        if(t->Left==NULL&&t->Right==NULL)
        {
        return 0;
        }
        else
        {
        return (1+max(height(t->Left),height(t->Right)));
        }
    }
}
int CountLeaf(struct node*t)
{
     if(t==NULL)
        return 0;
    else
    {
        if(t->Left==NULL&&t->Right==NULL)
        {
        return 1;
        }
        else
        {
        return (CountLeaf(t->Left)+CountLeaf(t->Right));
        }
    }
}
int CountN1(struct node*t)
{
  if(t==NULL)
        return 0;
    else if(t->Left==NULL&&t->Right==NULL)
        {
        return 0;
        }
    else if(t->Left!=NULL&&t->Right!=NULL)
        {
        return (CountN1(t->Left)+CountN1(t->Right));
        }
    else
    {
        return (1+CountN1(t->Left)+CountN1(t->Right));
    }
}
int CountN2(struct node*t)
{
    if(t==NULL)
        return 0;
    else if(t->Left==NULL&&t->Right==NULL)
        {
        return 0;
        }
    else if(t->Left!=NULL&&t->Right!=NULL)
        {
        return (1+CountN2(t->Left)+CountN2(t->Right));
        }
    else
    {
        return (CountN2(t->Left)+CountN2(t->Right));
    }
}
int IsComplteBinaryTree(struct node*t)
{
    int h=height(t);
    int c;
    c=CountLeaf(t);
    int d;
    d=pow(2,h);
    if(h==d)
        printf("Complete Btree");
    else
        printf("InComplete");
}
int main()
{
    int x,y,h,n0,n1,n2;
    struct node*root;
    root=NULL;
    printf("Input data item of root node\n");
    scanf("%d",&x);
    root=MakeNode(x);
    CreateTree(root);
    printf("Pre Order Tree is\n");
    PreOrderTraversal(root);
     printf("\nIn Order Tree is\n");
    InOrderTraversal(root);
     printf("\nPost Order Tree is\n");
    PostOrderTraversal(root);
    printf("\nTotal nodes-\t");
    y=CountNode(root);
    printf("\nHeight=\t");
    h=height(root);
    printf("%d",h);
    n0=CountLeaf(root);
    printf("\nN0 nodes=%d\t",n0);
    n1=CountN1(root);
    printf("\nN1 nodes=%d\t",n1);
    n2=CountN2(root);
    printf("\nN2 nodes=%d\t",n2);

    return 0;
}
