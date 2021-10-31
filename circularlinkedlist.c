#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node soham;
soham *head;
int c=0;

void create_or_insert(){
    soham *nn,*temp;
    int n;
    c++;
    nn=(soham*)malloc(sizeof(soham));
    printf("Enter no. \n");
    scanf("%d",&n);
    nn->data=n;
    nn->next=NULL;
    nn->prev=NULL;
    if(head==NULL){
        head=nn;
        nn->next=nn;
        nn->prev=nn;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;}
        temp->next=nn;
        nn->prev=temp;
        head->prev=nn;
        nn->next=head;
    }
}

void insert_beg(){
    soham *nn,*temp;
    int n;
    c++;
    nn=(soham*)malloc(sizeof(soham));
    printf("Enter no. \n");
    scanf("%d",&n);
    nn->data=n;
    nn->next=NULL;
    nn->prev=NULL;
     if(head==NULL){
        head=nn;
        nn->next=nn;
        nn->prev=nn;
    }
    else{
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=nn;
        nn->prev=temp;
        head->prev=nn;
        nn->next=head;
        head=nn;
    }
}

void delete_end()  
{  
    soham *temp,*last;  
    if(head==NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next==head)  
    {  
    	printf("\nnode deleted is %d",head->data); 
        head=NULL;   
        free(head);    
    }  
    else   
    {  
        temp=head;   
        if(temp->next!=head)  
        {  
            temp=temp->next;   
        } 
        printf("\nnode deleted is %d",temp->data);
		last=temp->prev; 
        last->next=head;  
        head->prev =last;    
        free(temp);    
    }  
}  

void search(){
    soham *temp,*last;
    int n,f=0,i=0;
    temp=head;
    last=head->prev;
    printf("\nSearch what you want\n");
    scanf("%d",&n);
    if(n==head->data){
        printf("Found at head position");
        f=1;
    }
    else if(n==last->data){
    	printf("Found at last position");
    	f=1;
	}
    else{
        while(temp->next!=head){
            if(n==temp->data){
                printf("item found at location %d ",i+1);  
                f=1;  
                break;  
            }
            i++;
            temp=temp->next;
        }
    }
    if(f!=1)
        printf("Not found 🙁");
}

void display()  
{  
    soham *temp;  
    temp=head;  
    if(head == NULL)  
    {  
        printf("\n Create a list first");  
    }     
    else  
    {   
          
        while(temp->next != head)  
        {  
          
            printf("%d\n", temp->data);  
            temp= temp->next;  
        }  
        printf("%d\n",temp->data);  
    }  
              
}  

void main ()  
{  
int choice;  
    while(1)  
    {   
        printf("\n1.Create or insert after\n2.Insert at beginning\n3.Delete at end\n4.Search\n5.Display\nother to exit");  
        printf("\nEnter your choice\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            create_or_insert();  
            break;  
            case 2:  
            insert_beg();
            break;  
            case 3:  
            delete_end();
            break;
            case 4:
            search();
            break;
            case 5:
            display();  
            break;
            default:  
            exit(0); 
        }  
    }  
}
