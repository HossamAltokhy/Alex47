//Preprocessor
#include <stdio.h>
#include <stdlib.h>

struct person
{
    int data;
    struct person*pPrev;
    struct person*pNext;
}*pHead,*pTail;


struct person * createPerson(int data);


int getDataFromIndex(int index);

void addPerson(int data);
void insertPerson(int data, int index);
void deletePerson(int index);
int searcForPersonByData(int data);
int getListCount();
void deleteAll();
void printList();

int main ()
{
    addPerson(1);
    addPerson(2);
    addPerson(3);
    addPerson(4);
    addPerson(5);
    addPerson(6);
    addPerson(7);
    addPerson(8);
    addPerson(9);
    addPerson(11);
    insertPerson(20, 6);
    printList();

    printf("Count = %d", getListCount());

    return 0;
}


void deleteAll()
{

    while(pHead!=NULL)
    {
        deletePerson(0);
    }

}
int getDataFromIndex(int index)
{

    struct person* pCur = pHead;

    for(; index>0; index--)
    {
        pCur = pCur->pNext;
    }

    return pCur->data;

}
struct person * createPerson(int data)
{
    struct person * pPerson =(struct person*) malloc(sizeof(struct person));
    if(pPerson)
    {
        pPerson->data = data;
        pPerson->pNext = NULL;
        pPerson->pPrev = NULL;
    }

    return pPerson;
}
void addPerson(int data)
{

    struct person *pPerson = createPerson(data);
    if(pPerson)
    {
        // Empty
        if(pHead == NULL)
        {
            pHead = pPerson;
            pTail = pPerson;
        }
        //Not Empty
        else
        {
            pTail->pNext = pPerson;
            pPerson->pPrev = pTail;
            pTail = pPerson;

        }
    }

}

int getListCount()
{
    int counter = 0 ;
    struct person* pCur = pHead;

    while(pCur != NULL)
    {
        pCur = pCur->pNext;
        counter++;
    }
    return counter;
}
//void insertPerson(int data, int index);
void deletePerson(int index)
{

    //Empty
    if(pHead == NULL)
    {
        printf("\nList is Empty Already !!!");
        return;
    }

    // Not Empty
    else
    {

        // OnePerson?
        if(pHead == pTail && index == 0)
        {
            free(pHead);
            pHead = NULL;
            pTail = NULL;
            return;
        }
        // FirstPerson?
        if(index == 0)
        {
            pHead = pHead->pNext;
            free(pHead->pPrev);
            pHead->pPrev = NULL;
            return;
        }
        // LastPerson?
        if(index == (getListCount()-1))
        {
            pTail = pTail->pPrev;
            free(pTail->pNext);
            pTail->pNext=NULL;
            return;
        }
        // Index?
        struct person* pCur = pHead;

        for(; index>0; index--)
        {
            pCur = pCur->pNext;
        }

        pCur->pPrev->pNext = pCur->pNext;
        pCur->pNext->pPrev = pCur->pPrev;
        free(pCur);

    }



}
//int searcForPersonByData(int data);

void insertPerson(int data, int index)
{
    // Empty
    if(pHead == NULL)
    {
        printf("List is Empty !!");
        // addPerson(data);
        return ;
    }
    // Not Empty
    else
    {
        struct person* pPerson = createPerson(data);
        if(pPerson)
        {
            // Case of first Person
            if(index == 0)
            {
                pPerson->pNext = pHead;
                pHead->pPrev = pPerson;
                pHead = pPerson;
                return;
            }

            if(index >= getListCount()+1)
            {
                addPerson(data);
                return;
            }


            struct person* pCur = pHead;

            for(; index>0; index--)
            {
                pCur = pCur->pNext;
            }

            pCur->pPrev->pNext = pPerson;
            pCur->pPrev = pPerson;
            pPerson->pNext = pCur;
            pPerson->pPrev = pCur->pPrev;





        }





    }

}

void printList(){

    struct person* pCur = pHead;

    while(pCur != NULL)
    {
        printf("%d\n", pCur->data);
        pCur = pCur->pNext;

    }

}
