#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int num;  
    struct node *next;   
};
struct node *head, *head1, *head2,*x,*y, *temp; 

struct node *Create1(struct node *x);
struct node *Create2(struct node *y);
void Display1();
void Display2();     
void Insert1();
void Insert2();
void Delete1(); 
void Delete2();  
void Reverse1();
void Reverse2();
struct node *Concatenate(struct node *x, struct node *y); 
 
void main ()  
{  
    int choice = 0;  
    while(choice != 12)   
    {  
        printf("\n===========================================================================\n"); 
        printf("\n------------------------------Linked List----------------------------------\n");  
        printf("\n===========================================================================\n");

        printf("\n-- Choose one option from the following list --\n");  
        printf("\n1.Create First List\n2.Create Second List\n3.Display First List\n4.Display Second List\n5.Insert into First List\n6.Insert into Second List\n7.Delete from First List\n8.Delete from Second List\n9.Reverse First List\n10.Reverse Second List\n11.Concatenate\n12.Exit\n");

        printf("\n Enter your choice \n");         
        scanf("\n%d",&choice);  

        switch(choice)  
        {  
            case 1:
            x  = Create1(x);                    
            break; 

            case 2:
            y  = Create2(y);                    
            break; 

            case 3:  
            Display1();         
            break; 

            case 4:  
            Display2();         
            break; 

            case 5:  
            Insert1();       
            break; 

            case 6:  
            Insert2();       
            break;

            case 7:  
            Delete1();       
            break; 

            case 8:  
            Delete2();       
            break;  

            case 9:  
            Reverse1();        
            break;

            case 10:  
            Reverse2();        
            break;


            case 11:  
            x = Concatenate(x,y);          
            break;  
 
            case 12:  
            exit(0);  
            break; 

            default:  
            printf("\n Please enter the valid choice! \n");  
        }  
    }  
}  

struct node *Create1(struct node *x)
{
    struct node *fnNode, *temp;
    int num, i, n;
    head1 = (struct node *)malloc(sizeof(struct node));
    
    if(head1 == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf(" Input the number of nodes : ");
        scanf("%d", &n);

        printf("\n");
        printf(" Input data for node 1 = ");
        scanf("%d", &num);

        head1->num = num;      
        head1->next = NULL; 
        temp = head1;
        
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated. \n");
                break;
            }
            else
            {
                printf(" Input data for node %d = ", i);
                scanf(" %d", &num);
 
                fnNode->num = num;    
                fnNode->next = NULL; 
                temp->next = fnNode; 
                temp = temp->next; 
            }
        }
        x = head1;
    }
}

struct node *Create2(struct node *y)
{
    struct node *fnNode, *temp;
    int num, i, n;
    head2 = (struct node *)malloc(sizeof(struct node));
    
    if(head2 == NULL) 
    {
        printf(" Memory can not be allocated. \n");
    }
    else
    {
        printf(" Input the number of nodes for Second List = ");
        scanf("%d", &n);
        
        printf("\n");
        printf(" Input data for node 1 = ");
        scanf("%d", &num);

        head2->num = num;      
        head2->next = NULL; 
        temp = head2;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated. \n");
                break;
            }
            else
            {
                printf(" Input data for node %d = ", i);
                scanf(" %d", &num);
 
                fnNode->num = num;     
                fnNode->next = NULL; 
 
                temp->next = fnNode; 
                temp = temp->next; 
            }
        }
        y = head2;
    }
}

void Display1()  
{  
    struct node *ptr;  
    ptr = head1;

    if(ptr == NULL)  
    {  
        printf("\n The First List is Empty! \n");  
    }  
    else  
    {  
        printf("\n Displaying First List = \n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->num);  
            ptr = ptr -> next;  
        }  
    }  
} 

void Display2()  
{  
    struct node *ptr;  
    ptr = head2; 

    if(ptr == NULL)  
    {  
        printf("\n The Second List is Empty! \n");  
    }  
    else  
    {  
        printf("\n Displaying Second List = \n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->num);  
            ptr = ptr -> next;  
        }  
    }  
} 

void Insert1()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node)); 

    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter the element which you want to Insert in First List = ");  
        scanf("%d",&item);  
        ptr->num = item;  

        printf("\nEnter the location after which you want to Insert the element = ");  
        scanf("\n%d",&loc); 

        temp=head1;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\n Sorry! Cannot Insert the element. \n");  
                return;  
            }  
          
        }  

        ptr ->next = temp ->next;   
        temp ->next = ptr; 

        printf("\n Node Inserted Successfully! \n");  
    }  
} 

void Insert2()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));

    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter the element which you want to Insert in Second List = ");  
        scanf("%d",&item);  
        ptr->num = item;  
        printf("\nEnter the location after which you want to Insert the element = ");  
        scanf("\n%d",&loc);  
        temp=head2;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\n Sorry! Cannot Insert the element. \n");  
                return;  
            }  
          
        } 

        ptr ->next = temp ->next;   
        temp ->next = ptr;  

        printf("\n Node Inserted Successfully! \n");  
    }  
} 

void Delete1()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;  

    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc); 

    ptr=head1;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\n Sorry! Cannot Delete the element. \n");  
            return;  
        }  
    }  

    ptr1 ->next = ptr ->next;  
    free(ptr);  

    printf("\n Deleted Node %d Successfully! \n",loc+1);  
}  

void Delete2()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;  

    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  

    ptr=head2;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\n Sorry! Cannot Delete the element. \n");  
            return;  
        }  
    }  

    ptr1 ->next = ptr ->next;  
    free(ptr);  

    printf("\n Deleted Node %d Successfully! \n",loc+1);  
}  

void Reverse1()
{
    struct node *prevNode, *curNode;

    if(head1 != NULL)
    {
        prevNode = head1;
        curNode = head1->next;
        head1 = head1->next;

        prevNode->next = NULL; 

        while(head1 != NULL)
        {
            head1 = head1->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head1;
        }

        head1 = prevNode; 

        printf("\n The First List is Reversed Successfully! \n");
        printf("\n Enter Choice no. 3 to Display Reversed List. \n"); 
    }
}

void Reverse2()
{
    struct node *prevNode, *curNode;

    if(head2 != NULL)
    {
        prevNode = head2;
        curNode = head2->next;
        head2 = head2->next;

        prevNode->next = NULL;
        while(head2 != NULL)
        {
            head2 = head2->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head2;
        }

        head2 = prevNode;

        printf("\n The Second List is Reversed Successfully! \n");
        printf("\n Enter Choice no. 4 to Display Reversed List. \n"); 
    }
}

struct node *Concatenate(struct node *x, struct node *y)
{
    struct node *p;               
    p=x;                          
    while (p->next!=0)
    {
        p=p->next;
    }
    p->next=y;                        
    
    printf("\n The First and Second List is Concatenated Successfully! \n");   
    printf("\n Enter Choice no. 3 to Display Concatenated List. \n");           
    return x;
}