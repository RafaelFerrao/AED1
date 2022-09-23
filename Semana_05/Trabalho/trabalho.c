#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int NameShift() {
	return 0;
}

int AgeShift() {
	return NameShift() + sizeof( char ) * 10;
}

int TelShift() {
	return AgeShift() + sizeof( int );
}

int PreviousShift() {
	return TelShift() + sizeof( int );
}

int NextShift() {
	return PreviousShift() + sizeof( void ** );
}

int SizePBuffer() {
	return ( sizeof( char ) * 1 + sizeof( char ) * 10 + sizeof( int ) * 3 );
} // | int OP | char name [10] | int age | int tel | int found

int SizePerson()
{
	return ( sizeof( char ) * 10 + sizeof( int ) + sizeof( int ) + sizeof( void ** ) * 2 );
} // | char Name [10] | int Age | int Telephone | void** PreviousPerson | void** NextPerson

void *NewElement( char *name, int *age, int *tel ) {
	void *newp;
	newp = malloc( SizePerson() );
	if ( newp == NULL ) {
		printf( "Error, not enough memory to create new element" );
		exit( 1 );
	}

	int *p;			 // Pointer to receive the int values
	void **pAntNext; // Pointer to receive the pointer to pointer values

	strcpy( newp + NameShift(), name );

	p = newp + AgeShift();
	*p = *age;

	p = newp + TelShift();
	*p = *tel;

	pAntNext = newp + PreviousShift();
	*pAntNext = NULL;

	pAntNext = newp + NextShift();
	*pAntNext = NULL;

	return newp;
}

void Push( void **start, void *newp ) {
	if ( !( *start ) ) { // If the start is NULL, the list is empty, so start receives the New Person
		*start = newp;
		return;
	}

	void *p;
	void *pPrevious = NULL;
	p = *start;

	// while ((*(void **)(p + NextShift()) != NULL))
	while ( ( p != NULL ) && ( strcmp( ( char * )( p + NameShift() ), ( char * )( newp + NameShift() ) ) < 1 ) ) {
		pPrevious = p;
		p = *( void ** )( p + NextShift() );
	}

	if ( p != NULL ) {
		if ( pPrevious )
			*( void ** )( pPrevious + NextShift() ) = newp; // Only execute if pPrevious is not NULL, to avoid segmentaion fault
		else
			*start = newp; // If pPrevious is NULL, the insertion is in the beginning of the list, so we change it's start

		// Set previous and next pointers of the new element and of the surrounding elements
		*( void ** )( p + PreviousShift() ) = newp;
		*( void ** )( newp + PreviousShift() ) = pPrevious;
		*( void ** )( newp + NextShift() ) = p;
	}
	else {
		// Set the previous and next pointers of the new element and of the previously element (because it's in the end of the list)
		*( void ** )( pPrevious + NextShift() ) = newp;
		*( void ** )( newp + PreviousShift() ) = pPrevious;
		*( void ** )( newp + NextShift() ) = NULL;
	}
}

void Pop( void **start, char *text, int *found ) {
	void *p;
	void *pPrevious = NULL;
	void *pNext = NULL;
	*found = 0;

	p = *start;
	while ( p != NULL ) {
		if ( strcmp(p, text) == 0 ) {
			if ( *( void ** )( p + PreviousShift() ) == NULL ) { 
				// Case 1: The element to be removed is the first element
				pNext = ( *( void ** )( p + NextShift() ) );
				*( void ** )( pNext + PreviousShift() ) = NULL;
				*start = pNext;
				free( p );
				*found = 1;
				break;
			}
			if ( *( void ** )( p + NextShift() ) == NULL ) { 
				// Case 2: The element to be removed is the last element
				pPrevious = ( *( void ** )( p + PreviousShift() ) );
				*( void ** )( pPrevious + NextShift() ) = NULL;
				free( p );
				*found = 1;
				break;
			}
			if ( *(void ** )( p + NextShift() ) != NULL && *( void ** )( p + PreviousShift() ) != NULL ){ 
				// Case 3: The element is in the middle of the list
				pPrevious = ( *(void **)(p + PreviousShift()));
				pNext = ( *( void ** )( p + NextShift() ) );
				*( void ** )( pPrevious + NextShift() ) = pNext;
				*( void ** )( pNext + PreviousShift() ) = pPrevious;
				free( p );
				*found = 1;
				break;
			}
		}
		p = ( *( void ** )( p + NextShift() ) ); // Go to the next person
	}

	if ( *found == 0 )
		printf( "\n%s is not on the list", text );
	else
		printf( "\n%s was removed from the list", text );
}

void List( void *start ) {
	void *p;
	p = start;
	while ( p != NULL ) {
		printf( "\n\nName: %s | Age: %d | Telephone: %d", p, *( int * )( p + AgeShift() ), *( int * )( p + TelShift() ) );
		printf( "\n%d -> %d -> %d", *( void ** )( p + PreviousShift() ), p, *( void ** )( p + NextShift() ) );
		p = *( void ** )( p + NextShift() );
	}
}

void Search( void *start, char *text ) {
	void *p;
	p = start;
	while ( p != NULL ) { // Go through list elements
		if ( strcmp(p, text) == 0 ) { // Check if the current element is the one searched, if it is, prints it and end the function execution.
			printf( "\n\nSearch result:" );
			printf( "\nName: %s | Age: %d | Telephone: %d", p, *( int * )( p + AgeShift() ), *( int * )( p + TelShift() ) );
			printf( "\n%d -> %d -> %d", *( void ** )( p + PreviousShift() ), p, *( void ** )( p + NextShift() ) );
			return;
		}
		p = *( void ** )( p + NextShift() ); // Go to the next person
	}
	printf( "\n\nSearch result: %s is not on the list", text ); // Search failed
}

void Clear( void **start ) {
	void *p, *temp;
	p = *start;
	while ( p != NULL ) {
		temp = *( void ** )( p + NextShift() );
		free( p );
		p = temp;
	}
}

int main( int argc, char **argv ) {
	// | int OP | char name [10] | int age | int tel | int found
	void *start = NULL;
	void *pBuffer = malloc( SizePBuffer() );

	if ( pBuffer == NULL ) {
		printf( "Error, not enough memory to create the pBuffer" );
		exit( 1 );
	}

	int *op = pBuffer;
	void *name = pBuffer + sizeof( int );
	int *age = pBuffer + sizeof( int ) + sizeof( char ) * 10;
	int *tel = pBuffer + sizeof( int ) + sizeof( char ) * 10 + sizeof( int );
	int *found = pBuffer + sizeof( int ) + sizeof( char ) * 10 + sizeof( int ) * 2;

	*op = 1;

	while ( *op != 0 ) {
		printf( "\nWhat do you want to do?\n1 - Insert\n2 - Remove\n3 - Search\n4 - List\n0 - Exit\nYour choice: " );
		setbuf( stdin, NULL );
		scanf( "%d", op );
		switch ( *op ) {
		case 1:
			printf( "\nInsert the name: " );
			setbuf( stdin, NULL );
			scanf( "%s", name );

			printf( "\nInsert the age: " );
			setbuf( stdin, NULL );
			scanf( "%d", age );

			printf( "\nInsert the telephone: " );
			setbuf( stdin, NULL );
			scanf( "%d", tel );

			Push( &start, NewElement( name, age, tel ) );
			break;

		case 2:
			printf( "\nInsert the person's name to be removed: " );
			setbuf( stdin, NULL );
			scanf( "%s", name );

			Pop( &start, name, found );
			break;

		case 3:
			printf( "\nInsert the person's name to be searched: " );
			setbuf( stdin, NULL );
			scanf( "%s", name );

			Search( start, name );
			break;

		case 4:
			List( start );
			break;

		case 0:
			Clear( &start );
			break;

		default:
			printf( "\nInvalid input, try again." );
			break;
		}
	}
}