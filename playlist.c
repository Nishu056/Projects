#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song {
    char sname[100]; // Use character arrays to store strings
    char singer[100];
    char genre[100];
};

struct slist {
    struct slist* prev;
    struct slist* next;
    struct song s1; // Place the struct song inside struct slist
};

struct slist* head = NULL;
struct slist* curr = NULL;

void insert()
{
    struct slist* n = (struct slist*)malloc(sizeof(struct slist));
    struct slist* temp = head;
    printf("Enter song name: ");
    fflush(stdin);
    scanf("%[^\n]s", n->s1.sname);
    fflush(stdin);
    printf("Enter singer name: ");
    scanf("%[^\n]s", n->s1.singer);
    fflush(stdin);
    printf("Enter genre: ");
    scanf("%[^\n]s", n->s1.genre);
    fflush(stdin);
    if(head==NULL)
    {
        n->next = head;
        n->prev = temp; 
        head=n;
    }
    else if(head->next==NULL)
    {
        n->next = head;
       n->prev = head;
       head->next=n;
       head->prev=n;
    }
    else{
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    n->next = head;
    n->prev = temp;
    temp->next=n;
    head->prev=n;
    }
    printf("song inserted\n");
}



//delete a given song
void delete(char d[])
{
    struct slist* temp = head;  
    if(head->next==head)
    { if(strcmp(head->s1.sname, d) == 0)
    {
        head=NULL;
        printf("song deleted succesfully\n");
    }    
    } 
    else {         
while(temp->next!=head)
{
    if(strcmp(temp->s1.sname, d) == 0)
    {
    if(temp==head)//delete from start
    {
      
      head=temp->next;
      temp->next=head;
      printf("song deleted succesfully\n");
      break;
    }
    if (temp->prev != NULL)
                temp->prev->next = temp->next;
    if (temp->next != NULL)
                temp->next->prev = temp->prev;
            
                 free(temp);
                 printf("song deleted succesfully\n");
            return; 
    }
    temp=temp->next;
}
    }
    if(temp->next=head)
    {
        if(strcmp(temp->s1.sname, d) == 0)
        {
            temp->prev->next=head;
            head->prev=temp->prev;
        
        }
    }
}

//display all songs
void display()
{
    if(head==NULL){
        printf("list is already empty");
    }
    else{
    struct slist* temp1 = head;
     printf("\n ***PLAYLIST**\n");
    while (temp1->next != head  ) {
        printf("%s   ", temp1->s1.sname);
        printf("%s   ", temp1->s1.singer);
        printf("%s\n", temp1->s1.genre);
        temp1 = temp1->next;
    }
     printf("%s   ", temp1->s1.sname);
        printf("%s   ", temp1->s1.singer);
        printf("%s\n\n", temp1->s1.genre);
    }
}

//play next song
void pnext()
{
   if(curr==NULL)
   {
    curr=head;
   } 
    curr=curr->next;
     printf("%s ", curr->s1.sname);
        printf("%s ", curr->s1.singer);
        printf("%s\n", curr->s1.genre);
   
    
}

//play previous song
void pprev()
{
if(curr==NULL)
   {
    curr=head;
   } 
    curr=curr->prev;
    printf("%s ", curr->s1.sname);
        printf("%s ", curr->s1.singer);
        printf("%s\n", curr->s1.genre);
}
//play a particular song
void play_particular_song(char d[])
{
    struct slist* temp = head;
while(strcmp(temp->s1.sname, d) != 0)
{
temp=temp->next;
}
        printf("%s ", temp->s1.sname);
        printf("%s ", temp->s1.singer);
        printf("%s\n", temp->s1.genre);
        curr=temp;
}

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}


//play First song
void play_first()
{
printf("%s ", head->s1.sname);
        printf("%s ", head->s1.singer);
        printf("%s\n", head->s1.genre);
        curr=head;
}

//swap two songs
void swap(char a[],char b[])
{
    struct slist* temp1 = NULL; 
    struct slist* temp2 = NULL;
    struct slist* temp = head; 
    if(head->next==head || head==NULL)
    {
    return;
    }
    else 
    {
        do
         {
           if(strcmp(temp->s1.sname,a) == 0)
             {
                temp1=temp;
                printf("%s",temp1->s1.sname);
             }
           else if(strcmp(temp->s1.sname,b) == 0)
             {
                 temp2=temp;
                  printf("%s",temp2->s1.sname);
             }
             if (temp1 != NULL && temp2 != NULL)
             {
                 break;
             }
             temp=temp->next;
         }while(temp!=head);
       
    }
    if (temp1 != NULL && temp2 != NULL) {
        
       struct song temp_song = temp1->s1;
        temp1->s1 = temp2->s1;
        temp2->s1 = temp_song;

    }
    display();
    printf("\n Songs shuffled succesfully");

}
void main()
{ char d[40],a[40],b[40];
int ch;
do
{
   //menu
   printf(" *Playlist Menu* ");
   printf("\n1.Insert a new song\n2.Delete a song\n3.Display all songs\n4.Play next song\n5.Play previous song\n6.Play a particular song\n7.Play first song\n8.Shuffle any two songs \n9.Quit");
   printf("\nEnter your choice : ");
   scanf("%d",&ch);
   switch (ch)
   {
   case 1:  insert();
            break;
   case 2:  fflush(stdin);
            printf("Enter the name of song you want to delete : ");
            scanf("%[^\n]s",&d);
            delete(d);
            break;
   case 3:  display();
            break;
   case 4:  pnext();
            break;
   case 5:  pprev();
            break;
   case 6:  fflush(stdin);
            printf("Enter the name of song you want to play :  ");
            scanf("%[^\n]s",&d);
            play_particular_song( d);
            break;
   case 7:  play_first();
            break;
   case 8:  printf("Enter the name of two songs you want to shuffle : \n");
            fflush(stdin);
            scanf("%[^\n]s",&a); 
            fflush(stdin);
             scanf("%[^\n]s",&b); 
            swap(a,b);
            break;     
   case 9:  exit(0) ;
            break;                                                 
   
   }

}while(1);

}