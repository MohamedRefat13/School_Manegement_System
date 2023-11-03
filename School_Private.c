#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "STD_TYPES.h"
#include "School_Private.h"



StudentInfo_t Helper_GetStudentRecord(void){
	
	StudentInfo_t LocStudent ;
    setbuf(stdout,NULL);
    printf("Enter Student ID : ");
    scanf("%hu",&LocStudent.ID);
    printf("Enter Student name : ");
    fflush(stdin);
    gets(LocStudent.Name);
    printf("Enter Student Birthdate : ");
    scanf("%s",LocStudent.BirthDate);
    printf("Enter Student Phone Number : ");
    scanf("%s",LocStudent.PhoneNum);
	LocStudent.Score=0;
   

    return LocStudent ;
}


Node_t *Helper_GetStudentNode(List_t *pList , uint16_t Copy_ID){

	Node_t *pTempNode = pList->pHead;
	Node_t *pLocReturnNode = NULL_ptr ;

	while(pTempNode !=NULL_ptr){

		if(pTempNode->Data.ID == Copy_ID){
			
			pLocReturnNode = pTempNode;
			break;
		}
		pTempNode = pTempNode->pNextNode;
	}
	return pLocReturnNode ;
}


/* ========= Linked List Functions Implementation   ======== */
void LinkedList_Init(List_t *pList)
{
	pList->pHead = NULL_ptr ;
	pList->Size   = 0;
}
void LinkedList_Insert(List_t *pList ,StudentInfo_t Data )
{
	Node_t *pNode = (Node_t *)malloc(sizeof(Node_t));
	if(pNode != NULL_ptr)
	{

        pNode->Data = Data;
        pNode->pNextNode = NULL_ptr ;
		pNode->Node_Num = (pList->Size + 1);

		/* Special case if the List is empty */
        if(pList->Size == 0 )
        {
        	pList->pHead = pNode;
        	pList->Size++;
        }else
        {
        	Node_t *pLocNode = pList->pHead ;
        	uint32_t Iterator = 0 ;
        	while(Iterator <( pList->Size - 1) )
        	{
        		pLocNode = pLocNode->pNextNode ;
        		Iterator ++ ;

        	}
        	pLocNode->pNextNode = pNode;

        	pList->Size++;

        }
	}else
	{
		/* aseert will be triggered if the condition is false  */
		assert( (!(pNode == NULL_ptr))  && "Memory not allocated because there is no memory in Heap ");
	}
}

void LinkedList_Delete(List_t *pList ,uint32_t Position){

	Node_t *pDeletedNode = NULL_ptr ;
	Node_t *pTempNode ;
	/* Special case if you want to delete fist node in the list */
	if(Position == 1){
		pDeletedNode = pList->pHead ;
		pList->pHead= pDeletedNode->pNextNode;

	}else if(Position <= ( pList->Size ) ){
		uint32_t Iterator ;
		pTempNode = pList->pHead ;
        /*After this loop  pTempNode will refer to the previous node of the deleted node  */
		for(Iterator=1 ; Iterator < Position-1 ; Iterator++){
			pTempNode = pTempNode->pNextNode ;
		}

        /*  Set pDeletedNode to it's right position to the deleted node */
		pDeletedNode = pTempNode->pNextNode ;
		
		/* Special case if the you want to delete the last node in the list */
		if(Position == (pList->Size) ){
			pTempNode->pNextNode = NULL_ptr;
		}else{
			pTempNode->pNextNode = pDeletedNode->pNextNode ;
		}

	}
    if(pDeletedNode !=NULL_ptr){
		/*  Update Node Number after deleting the node */
		pTempNode = pDeletedNode->pNextNode ;
		while(pTempNode != NULL_ptr){
			pTempNode->Node_Num -- ;
		    pTempNode = pTempNode->pNextNode;
		}

		pList->Size -- ;
		free(pDeletedNode);
	}

}