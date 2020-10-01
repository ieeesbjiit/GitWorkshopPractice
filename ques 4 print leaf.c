#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
NODE *root=NULL;
NODE *temp,*temp1;
void insert(NODE *root,NODE *new_node)
{
    int ch;
    printf("ENTER 0 FOR LEFT AND 1 FOR RIGHT NODE for the root %d",root->data);
    scanf("%d",&ch);
    if(ch==1)
    {
        if(root->right==NULL)
            root->right=new_node;
        else
            insert(root->right,new_node);
    }

    else
    {
        if(root->left==NULL)
            root->left=new_node;
        else
            insert(root->left,new_node);
    }
}


void leaf(NODE *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        printf("%d",root->data);

    }

        leaf(root->left);
        leaf(root->right);

}


void traverse(NODE *root)
{
    if(root!=NULL)
        {
            traverse(root->left);
            printf("%d",root->data);
            traverse(root->right);
        }
}

int main()
{
    NODE *new_node;

    int ch;
    do
    {
        printf("\n enter 1 to create");
        printf("\n enter 2 to display");
        printf("\n enter 3 to print leaf");
        printf("\n enter 4 to exit");
        printf("\n enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            new_node=(NODE*)malloc(sizeof(NODE));
            printf("\n\nENTER THE ELEMENT");
            scanf("%d",&new_node->data);
            new_node->left=NULL;
            new_node->right=NULL;
            if(root==NULL)
                root=new_node;
            else
                insert(root,new_node);
            break;

        case 2:
            traverse(root);
            break;
        case 3:
            leaf(root);
            break;
        }


    }while(ch!=4);
}



