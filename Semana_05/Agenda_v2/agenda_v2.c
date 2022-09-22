#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SizeHeader() {
    return ( sizeof( int ) * 3 + sizeof( char ) * 10 );
} // | INT OP | INT aux| INT N persons  | CHAR [10] Name Search | void *Start

int SizePerson() {
    void *ptr;
    return ( sizeof( char ) * 10 + sizeof( int ) + sizeof( char ) * 18 + sizeof(ptr) * 2);
} // | Name | Age | Telephone | PreviousPerson | NextPerson

void SetPersonName(void **person, void **name){
    *name = *person;
}

void SetPersonAge(void **person, int **age){
    *age = *person;
    *age = *person + sizeof( char ) * 10;
} // Move ptr to Person's telephone (skip name + age)

void SetPersonTel(void **person, void **tel){
    *tel = *person;
    *tel += sizeof( char ) * 10 + sizeof( int );
} // Move ptr to Person's telephone (skip name + age)

void SetPersonPrevious(void **person, int **pPrevious){
    *pPrevious = *person;
    *pPrevious = *person + sizeof( char ) * 10 + sizeof( int ) + sizeof( char ) * 10;
}

void SetPersonNext(void **person, int **pNext){
    void *ptr;
    *pNext = *person;
    *pNext = *person + sizeof( char ) * 10 + sizeof( int ) + sizeof( char ) * 10 + sizeof(ptr);
}

void *NewElement(char *name, int age, char *telephone) {
    void *person;
    void *pName;
    int *pAge;
    void *pTel;
    int *pPrevious;
    int *pNext;

    person = malloc( SizePerson() );

    SetPersonName(&person, &pName);
    strcpy(pName, name);
    printf("\n%s", person);

    SetPersonAge(&person, &pAge);
    *pAge = age;
    printf("\n%d",*(int *)( person + sizeof( char ) * 10));

    SetPersonTel(&person, &pTel);
    strcpy(pTel, telephone);
    printf("\n%s", person + sizeof( char ) * 10 + sizeof( int ));
    SetPersonPrevious(&person, &pPrevious);
    *pPrevious = 0;

    SetPersonNext(&person, &pNext);
    *pNext = 0;

    return person;
}

void InsertPerson(void **start, void *person)
{
    int *pNext;
    SetPersonNext(*start, &pNext);
	if(*start == NULL)
        *start = person;
    else {
        while(*pNext != NULL){
            *start = *pNext;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    void *start = NULL;
    int *aux;
    InsertPerson(&start, NewElement("Rafael", 20, "20000"));
    printf("\n%s", start);
    SetPersonAge(&start, &aux);
    printf("\n%d", *aux);

    return 0;
}
