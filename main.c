#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display();
void swaap();
int linearSearch();
int binarySearch();
void bubbleSort();
void selectionSort();
void header();
void footer();
void lastpage();

int main()
{

    int id,n_of_book;
    char task,task2,task3,task4;
    int book_id[]={12,1,15,6};
    char book_name[][100] = {"Algorithm Design","C Programming Book","OOP Concept in C++","Computer Architecture"};
    int price[] = {230,200,250,380};

    int len = sizeof(book_id)/sizeof(book_id[0]);

    while(1)
    {
        system("cls");
        //First Page
        header();
        printf("\t\t------------------------------\n");
        printf("\t\t\tPrimary Menu\n");
        printf("\t\t------------------------------\n");
        printf("\t\t a.Search\n\t\t b.Sort\n\t\t c.Exit\n");
        footer();

        printf("Please Select a task from the Menu(a/b/c): ");
        scanf(" %c",&task);
        if(task=='a')
        {
            //Page 2
            system("cls");
            header();
            display(book_id,book_name,price,len);
            printf("\n\n\t\t------------------------------\n");
            printf("\t\t\tSecondary Menu\n");
            printf("\t\t------------------------------\n");
            printf("\t\t a.Linear Search\n\t\t b.Binary Search\n");
            footer();
            printf("Please Select a task from the Menu(a/b): ");
            scanf(" %c",&task2);
            if(task2=='a')
            {
                system("cls");
                header();
                printf("\tEnter the Book ID you want to purchase: ");
                scanf("%d",&id);
                printf("\n\tNumber of Book you want to purchase: ");
                scanf("%d",&n_of_book);
                printf("\n\n");
                int index = linearSearch(book_id,len,id);
                if(index==-1)
                printf("\n\t\t      Sorry! Book ID Not Found.\n");
                else
                {
                    printf("\t-------------------------------------------------------\n");
                    printf("\tBook ID\t\tBook Title\t\tNumber of Book\n");
                    printf("\t-------------------------------------------------------\n");
                    printf("\t%3d\t %22s \t\t%5d\n",book_id[index],book_name[index],n_of_book);
                    printf("\n\t\t\t\t-------------------------------\n");
                    printf("\t\t\t\t Total Cost: %2d x %2d = %4d TK\n",price[index],n_of_book,price[index]*n_of_book);
                }
                printf("\n\n\t\t\t  0 Home | # Exit");
                footer();
                printf("Please Select a task from the Menu(0/#): ");
                scanf(" %c",&task4);
                if(task4=='0')
                {
                    continue;
                }
                else if(task4=='#')
                {
                    lastpage();
                    break;
                }

            }
            else if(task2=='b')
            {
                system("cls");
                header();
                printf("\tEnter the Book ID you want to purchase: ");
                scanf("%d",&id);
                printf("\n\tNumber of Book you want to purchase: ");
                scanf("%d",&n_of_book);
                printf("\n\n");
                bubbleSort(book_id,book_name,price,len);
                int index = binarySearch(book_id,0,len,id);
                if(index==-1)
                printf("\nSorry Book ID Not Found!\n");
                else
                {
                    printf("\t-------------------------------------------------------\n");
                    printf("\tBook ID\t\tBook Title\t\tNumber of Book\n");
                    printf("\t-------------------------------------------------------\n");
                    printf("\t%3d\t %22s \t\t%5d\n",book_id[index],book_name[index],n_of_book);
                    printf("\n\t\t\t\t-------------------------------\n");
                    printf("\t\t\t\t Total Cost: %2d x %2d = %4d TK\n",price[index],n_of_book,price[index]*n_of_book);
                }
                   printf("\n\n\t\t\t  0 Home | # Exit");
                footer();
                printf("Please Select a task from the Menu(0/#): ");
                scanf(" %c",&task4);
                if(task4=='0')
                {
                    continue;
                }
                else if(task4=='#')
                {
                    lastpage();
                    break;
                }
            }
        }
        else if(task=='b')
        {
            system("cls");
            header();
            printf("\n\n\t\t------------------------------\n");
            printf("\t\t\tSecondary Menu\n");
            printf("\t\t------------------------------\n");
            printf("\t\t a.Bubble Sort\n\t\t b.Selection Sort\n");
            footer();
            printf("Please Select a task from the Menu(a/b): ");
            scanf(" %c",&task3);
            if(task3=='a')
            {
                system("cls");
                header();
                bubbleSort(book_id,book_name,price,len);
                display(book_id,book_name,price,len);
                printf("\n\n\t\t\t  0 Home | # Exit");
                footer();
                printf("Please Select a task from the Menu(0/#): ");
                scanf(" %c",&task4);
                if(task4=='0')
                {
                    continue;
                }
                else if(task4=='#')
                {
                    lastpage();
                    break;
                }
            }
            else if(task3=='b')
            {
                system("cls");
                header();
                selectionSort(book_id,book_name,price,len);
                display(book_id,book_name,price,len);
                printf("\n\n\t\t\t  0 Home | # Exit");
                footer();
                printf("Please Select a task from the Menu(0/#): ");
                scanf(" %c",&task4);
                if(task4=='0')
                {
                    continue;
                }
                else if(task4=='#')
                {
                    lastpage();
                    break;
                }
            }
        }
        else if(task=='c')
        {
            lastpage();
            break;
        }
        else
        {
            printf("\n\t You Entered Wrong Key.\n\n");
            continue;
        }

    return 0;
    }
}


//My Functions

void header()
{
    printf("======================================================================\n");
    printf("\n\t\t\tBook Keeping Software\n");
    printf("\n======================================================================\n\n");
}


void footer()
{

    printf("\n\n======================================================================\n");
    printf("\t\t Developed By Inajamamul Haque Sonet\n");
    printf("======================================================================\n\n");
}

void lastpage()
{
    system("cls");
    header();
    printf("\n\n\t       Thank You For Using BookKeeping Software.\n\n");
    footer();
}

void display(int arr1[],char arr2[][100],int arr3[], int n)
{
    printf("\t-------------------------------------------------------\n");
    printf("\tBook ID\t\t\tBook Title\t\tPrice\n");
    printf("\t-------------------------------------------------------\n");
    int i;
    for(i=0;i<n;i++){
        printf("\t %3d\t\t %18s \t\t%4d Tk\n",arr1[i],arr2 +i,arr3[i]);
    }
}

void swaap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(int arr[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}


int binarySearch(int arr[],int low, int high,int key)
{
    if(high>=low)
    {
        int mid=(high+low)/2;
        if(arr[mid]>key)
            return binarySearch(arr,low,mid-1,key);
        if(arr[mid]<key)
            return binarySearch(arr,mid+1,high,key);
        if(arr[mid]==key)
            return mid;
    }
    else
        return -1;
}

void selectionSort(int arr[],char arr2[][100],int arr3[], int n)
{
    int i, j, min_idx;
    char t[100];

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          {
              if (arr[j] < arr[min_idx])
            min_idx = j;
          }

        swaap(&arr[min_idx], &arr[i]);
        strcpy(t, arr2[min_idx]);
        strcpy(arr2[min_idx], arr2[i]);
        strcpy(arr2[i], t);
        swaap(&arr3[min_idx], &arr3[i]);
    }
}

void bubbleSort(int arr[],char arr2[][100],int arr3[], int n)
{
    int i, j;
    char t[100];
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
        {
            swaap(&arr[j], &arr[j+1]);
            strcpy(t, arr2[j]);
            strcpy(arr2[j], arr2[j+1]);
            strcpy(arr2[j+1], t);
            swaap(&arr3[j], &arr3[j+1]);
        }
}


