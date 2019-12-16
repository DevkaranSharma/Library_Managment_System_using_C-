#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct Book
{
	char name[50],aut[10];
	int id,price,num;
};
struct User
{
	char name[20],pass[20];
};
void admin();
void insert();
void display();
void deletee();
void search();
void update();
void sort();
void purchase();
void login()
{
	int n;
	printf("*****************WELCOME**********************\n");
	admin();
}
int signup()
{
	FILE *f;
	struct User u;
	f=fopen("E:\\work\\user.txt","w");
	if(!f)
	{
		printf("File not open");
	}
	else
	{
		printf("Enter your username:");
		gets(u.name);
		fflush(stdin);
		printf("Enter Password:");
		gets(u.pass);
		fflush(stdin);
		printf("\nSigned in Sucessfully\n");
		fwrite(&u,sizeof(struct User),1,f);
	}
	fclose(f);
	admin();
}
void admin()
{
	struct User u;
	int n,m,i;
	char ch;
	char name[20],pass[15];
	FILE *f;
	f=fopen("E:\\work\\user.txt","r");
	fread(&u,sizeof(struct User),1,f);
	printf("Enter Username:");
	gets(name);
	printf("Enter Password:");
	while((ch=getch())!=13)
	{
		pass[i]=ch;
		printf("*");
		i++;
		if(ch==8)
		{
			printf("\b");
		}
	}
	if(!strcmp(u.name,name))
	{
		if(!strcmp(pass,u.pass))
		{
			printf("\n****Login sucessfull****\n");
			while(1)
			{
			    printf("\nPress 1 for main menu:");
			    scanf("%d",&m);
			    if(m==1)
			    {
				    printf("\nMAIN MENU");
	                printf("\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.UPDATE\n6.SORT\n7.PUCHASE_BOOK\n8.EXIT\n");
	                printf("Enter your choice:");
	                scanf("%d",&n);
	                fflush(stdin);
	                switch(n)
	                {
		                case 1:
			                insert();
			                break;
		                case 2:
			                display();
			                break;
		                case 3:
			                search();
			                break;
	                    case 4:
	    	                deletee();
	    	                break;
	                    case 5:
	    	                update();
	    	                break;
	                    case 6:
	    	                sort();
	    	                break;
	                    case 7:
	    	                purchase();
	    	                break;
	                    case 8:
	    	                exit(0);
	    	                break;
	                }
	            }
           }
       }
       printf("Wrong Username or Password");
    }
}
void insert()
{
	FILE *j;
	struct Book b;
	int count=0;
	j=fopen("E:\\work\\insert.txt","a");
	if(!j)
	{
		printf("File not open");
	}
	else
	{
		printf("Enter Book ID:");
		scanf("%d",&b.id);
		fflush(stdin);
		printf("Enter Book Name:");
		gets(b.name);
		fflush(stdin);
		printf("Enter Author Name:");
		gets(b.aut);
		fflush(stdin);
		printf("Price:");
		scanf("%d",&b.price);
		fflush(stdin);
		printf("Total No. of Book:");
		scanf("%d",&b.num);
		fflush(stdin);
		fwrite(&b,sizeof(struct Book),1,j);
		count++;
	}
	fclose(j);
}
void display()
{
	FILE *f;
	struct Book b;
	f=fopen("E:\\work\\insert.txt","r");
	while(fread(&b,sizeof(struct Book),1,f))
	{
        printf("\n\nBook ID: %d\nBook Name: %s\nAuthor Name:%s\nPrice: %d\nTotal no. of Books: %d\n",b.id,b.name,b.aut,b.price,b.num);
    }
    fclose(f);
}
void search()
{
	FILE *k;
	struct Book b;
	k=fopen("E:\\work\\insert.txt","r");
	int n, found = 0;
	printf("\nEnter Book ID:");
	scanf("%d",&n);
	fflush(stdin);
	while(fread(&b,sizeof(struct Book),1,k))
	{
		if(n==b.id)
		{
			found = 1;
			printf("\nBook ID: %d\nBook Name: %s\nAuthor Name:%s\nPrice: %d\nTotal no. of Books: %d\n",b.id,b.name,b.aut,b.price,b.num);
		}
	}
	if(!found)
	{
        printf("Invalid book ID");
	}
	fclose(k);
}
void deletee()
{
	FILE *l,*m;
	struct Book b,c,d;
	l=fopen("E:\\work\\insert.txt","r");
	m=fopen("E:\\work\\delete.txt","w");
	int n,op=0;
	printf("\nEnter Book ID you want to delete:");
	scanf("%d",&n);
	fflush(stdin);
	while(fread(&b,sizeof(struct Book),1,l))
    {
		if(n==b.id)
		{
			op = 1;
		}
		else
		{
			fwrite(&b,sizeof(struct Book),1,m);
		}
	}
	if(op==1)
	{
    	fclose(l);
	    fclose(m);
	    remove("insert.txt");
	    rename("delete.txt","insert.txt");
        printf("Record Deleted sucessfully");
    }
    else
	{
		printf("Book ID is INVALID");
	}
    fclose(l);
    fclose(m);
}
void update()
{
	FILE *l,*m;
	l=fopen("E:\\work\\insert.txt","r");
	m=fopen("E:\\work\\update.txt","w");
	struct Book b;
	int n,i,op;
	printf("Enter Book id to Update:");
	scanf("%d",&n);
	fflush(stdin);
	while(fread(&b, sizeof(struct Book),1, l))
	{
	    if(n==b.id)
	    {
		    op=1;
		    printf("\n1.Update the book name of book id %d\n",n);
	        printf("\n2.Update the Author name of book id %d\n",n);
		    printf("\n3.Update the book Price of book id %d\n",n);
		    printf("\n4.Update the total No. of books of book id %d\n",n);
		    scanf("%d",&i);
		    if(i==1)
		    {
			    printf("Enter book name:");
			    scanf("%s",&b.name);
			    fprintf(m,"%s","b.name");
			    break;
		    }
		    else if(i==2)
		    {
			    printf("Enter Author name:");
			    scanf("%s",&b.aut);
			    fprintf(m,"%s","b.aut");
			    break;
		    }
		    else if(i==3)
		    {
			    printf("Enter Price:");
			    scanf("%d",&b.price);
			    fprintf(m,"%d","b.price");
			    break;
		    }
		    else if(i==4)
		    {
			    printf("Enter Total No. of books:");
			    scanf("%d",&b.num);
			    fprintf(m,"%d","b.num");
			    break;
		    }
		    else
		    {
			    printf("INVAID entry");
		    }
	    }
    }
    if(op==1)
    {
    	fclose(l);
    	fclose(m);
    	remove("insert.txt");
    	rename("update.txt","insert.txt");
    	printf("Record Updated Sucessfully");
	}
	else
	{
		printf("Book ID is INVALID");
	}
}
void sort()
{
	FILE *f;
	struct Book b;
	int i,a[10],j,step,p,count=0;
	f=fopen("E:\\work\\insert.txt","r");
	while(fread(&b,sizeof(struct Book),1,f))
	{
		count++; 
    }
    if(!count)
    {
        printf( "Library is empty\n" );
        return;
    }    
    struct Book b_arr[count];
    rewind(f);
    i=0;
    while( fread(&b, sizeof(struct Book),1,f) )
    { 
        b_arr[i++] = b; 
    }
    for( i = 0; i < count - 1; i++ )
    {
        for( j = 0; j < count - i - 1; j++)
        {
            if( b_arr[j].id > b_arr[j+1].id )
            {
                b = b_arr[j];
                b_arr[j] = b_arr[j+1];
                b_arr[j+1] = b;
            }
        }
    }
    for( i = 0; i < count; i++ )
    {
        printf( "\nBook Id: %d\nBook Name: %s\nBook Author: %s\nBook Price: %d\nNo. of books: %d\n",b_arr[i].id,b_arr[i].name,b_arr[i].aut,b_arr[i].price,b_arr[i].num);
    }
}
void purchase()
{
	FILE *a;
	struct Book b;
	a=fopen("E:\\work\\insert.txt","r");
	int n,o,p,sum=0,found=0;
AGAIN:
        printf("Enter the book ID:");
	    scanf("%d",&n);
        while(fread(&b,sizeof(struct Book),1,a))
        {
            if(b.id == n)
            {
                found = 1;
                break;
            }
        }
        rewind(a);
        if(!found)
        {
            printf( "%d not found\n", n );
        }
        else
        {
            printf( "Enter no. of books you wan to purchase: " );
            scanf("%d", &o);
            sum = sum + o * b.price;
        }
        printf("Press 1 if any other book you want to purchase or press 2\n");
BACK:
        scanf( "%d", &p );
        if( p == 1 )
        {
            goto AGAIN;
        }
        else if( p == 2 )
        {
            printf( "Total is: %d", sum );
        }
        else
        {
            printf( "Invalid option enter again: " );
            goto BACK;
        }
}
int main()
{
	int n;
        char a;
	printf("1.Login\n2.Signup");
	scanf("%d",&n);
        scanf( "%c", &a );//comment this file
	fflush(stdin);
	switch(n)
	{
		case 1:
			login();
			break;
		case 2:
			signup();
			break;
	}
}

