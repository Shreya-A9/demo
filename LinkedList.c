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
void Insert();
void Delete();   
void Reverse();
struct node *Concatenate (struct node *x, struct node *y); 
 
void main ()  
{  
    int choice =0;  
    while(choice != 9)   
    {  
        printf("\n===========================================================================\n"); 
        printf("\n------------------------------Linked List----------------------------------\n");  
        printf("\n===========================================================================\n");

        printf("\n-- Choose one option from the following list --\n");  
        printf("\n1.Create First List\n2.Create Second List\n3.Display First List\n4.Display Second List\n5.Insert into First List\n6.Delete element from First List\n7.Reverse First List\n8.Concatenate\n9.Exit\n");

        printf("\nEnter your choice = ");         
        scanf("%d",&choice); 
        printf("\n");

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
            Insert();       
            break; 

            case 6:  
            Delete();       
            break;   

            case 7:  
            Reverse();        
            break;

            case 8:  
            x = Concatenate(x,y);          
            break;  
 
            case 9:  
            exit(0);  
            break; 

            default:  
            printf(" Please enter valid choice. \n");  
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
        printf(" Memory can not be allocated.\n");
    }
    else
    {
        printf("Input the number of nodes = ");
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
                printf(" Memory can not be allocated.\n");
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
        printf("\n Created First List Successfully! \n");
        x=head1;
    }    
}

struct node *Create2(struct node *y)
{        
    struct node *fnNode, *temp;
    int num, i, n;
    head2 = (struct node *)malloc(sizeof(struct node));
    
    if(head2 == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf(" Input the number of nodes = ");
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
                printf(" Memory can not be allocated.\n");
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
        printf("\n Created Second List Successfully! \n");
        y=head2;
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
        printf("\n Displaying First List = ");   
        while (ptr!=NULL)  
        {  
            printf("  %d  ",ptr->num);  
            ptr = ptr -> next;  
        }
        printf("\n");  
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
        printf("\n Displaying Second List = ");   
        while (ptr!=NULL)  
        {  
            printf("  %d  ",ptr->num);  
            ptr = ptr -> next;  
        }  
        printf("\n");  
    }  
} 

void Insert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\n OVERFLOW \n");  
    }  
    else  
    {  
        printf("\nEnter the element which you want to Insert = ");  
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

void Delete()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion = ");  
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

void Reverse()
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

