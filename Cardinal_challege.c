
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

// ------- begin your code ------------------

int fib (int N)  
{
    if (N==0) return 0;
    if(N==1) return 1;

    else return(fib(N-1)+fib(N-2));
}
// For negative fibonacci, it is possible to consider the link below
// https://en.wikipedia.org/wiki/Generalizations_of_Fibonacci_numbers


void reverse (char *str)
{
    
    int n = strlen(str);
    // a =[1,2,3]
    for (int i = 0, j = n - 1; i < j; i++, j--)

    {

        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}


// a =[10,2,3]
void sort(int a[], int size)
{
    int tmp=a[0],i,j;    
    for (j=0;j<size;j++){
        for (i=j+1;i<size;i++){
            if(a[i]<a[j]){          //a[j]= 10 and a[i]=2, j=0 and i 1-size >>> a[0]=2 and a[1]=10: a[j==0] and a[i==2], 
            // a[j==1]=10, a[i==2]=3
            #if 0
            [10,2,3], [2,10,3]
            #endif 

            #if 0
            [2,10,3],[2,3,10]
            #endif 
                tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;               
            }
    }
    } 
    
    }



//-list--
typedef struct list {
    struct list *next;
    int i;
} list;

void list_add(list **ll, int i)
{     
    list* temp= (list*)malloc(sizeof(list));    
    list *last = *ll;  
    temp->i  = i;
    temp->next = NULL;

    if (*ll == NULL)
    {*ll = temp;
       return;
    }

    while (last->next != NULL)last = last->next;
    last->next = temp;
    return; 

}
  
void list_print (list **ll)
{
    list* temp=*ll;    
    while(temp != NULL){
        printf("%d  ",temp ->i );
        temp=temp->next;
    }
}

void list_reverse(list **ll)
{    
    list *current,*prev,*next;
    current=*ll; // A
    prev=NULL;
    while(current!=NULL){
        next=(*current).next; // is C' address 
        current->next=prev; // A
        prev=current; // B
        current=next; //C


        #if 0
        [prev, currrent]=[A,B]
        [B,C]
        #endif

    }
    *ll=prev;
  }


//-list--

// ------- end your code ------------------



// ------- tester code ------------------

static void test_fibonacci()
{
    printf ("\n----------- %s -----------\n", __FUNCTION__);
    printf ("fib 10: ");

    for (int i=1; i<=10; i++)
        printf ("%d ", fib(i));
    printf ("\n");
}

static void test_sort()
{
    int a[] = {43, 47, 81, 39, -64, 0};
    int b[] = {25, 63, 67, 40, 0, 50};
    int c[] = {};
    int d[] = {22};
    int e[] = {78, 31};

    struct {
        int *array;
        int size;
    } data[] = {
        {a, ARRAY_SIZE(a)},
        {b, ARRAY_SIZE(b)},
        {c, ARRAY_SIZE(c)},
        {d, ARRAY_SIZE(d)},
        {e, ARRAY_SIZE(e)},
    };

    printf ("\n----------- %s -----------\n", __FUNCTION__);


    for (int count=0; count < ARRAY_SIZE(data); count++)
    {
        for (int i=0; i < data[count].size; i++)
            printf("%d ", data[count].array[i]);

        printf(" => ");

        sort(data[count].array, data[count].size);

        for (int i=0; i<data[count].size; i++)
            printf("%d ", data[count].array[i]);

        printf ("\n");
    }
}

static void test_reverse()
{
    char words[][10] = {"one", "two", "racecar", "", "four", "a"};

    printf ("\n----------- %s -----------\n", __FUNCTION__);

    for (int i=0; i<ARRAY_SIZE(words); i++) {
        printf ("[%s] => ", words[i]);
        reverse(words[i]);
        printf (" [%s]\n", words[i]);
    }
}

static void test_list()
{
    list *ll = NULL;

    printf ("\n----------- %s -----------\n", __FUNCTION__);

    list_print(&ll);

    list_add(&ll, 1);
    list_add(&ll, 5);
    list_add(&ll, 3);
    list_add(&ll, 6);

    list_print(&ll);
    printf("\n");

    list_reverse(&ll);
    list_print(&ll);
    printf("\n");

    list_reverse(&ll);
    list_print(&ll);
}

int main()
{
    test_fibonacci();
    test_sort();
    test_reverse();
    test_list();

    return 0;
}

