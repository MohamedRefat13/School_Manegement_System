/*
 * SingleLinkedList.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Mohamed Refat
 */
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "School_Private.h"
#include "School.h"


/* School system Functions Implementation */
void MAIN_MENU (void){
    
	/* Initate The System */
    List_t Student_List ; 
    LinkedList_Init(&Student_List);
	uint16_t Operation_Num=0;

	printf("-------------------------------------------------------\n");
	printf("-----                   WELCOME                   -----\n");
	printf("-------------------------------------------------------\n");

	while(1)
	{
		Operation_Num=0;
		printf("-------------------------------------------------------------------------\n");
		printf("-\tEnter [ 1 ] to Add New Student Record              		-\n");
		printf("-\tEnter [ 2 ] to Edit Student Records                      	-\n");
		printf("-\tEnter [ 3 ] to Add New Student Score               		-\n");
		printf("-\tEnter [ 4 ] to view student Records [alphabetically ascending]  -\n");
		printf("-\tEnter [ 5 ] to view student Score   [Descending]                -\n");
		printf("-\tEnter [ 6 ] to Add Delete Student Records               	-\n");
		printf("-\tEnter [ 7 ] to exit                                     	-\n");
		printf("-\tEnter any number else to go to the Home Page       		-\n");
		printf("-------------------------------------------------------------------------\n");
		printf("Choose  Operation Number : ");
		scanf("%hu",&Operation_Num);
		switch(Operation_Num)
		{
			case 1 : NEW_STUDENT(&Student_List);       break ;
			case 2 : STUDENT_EDIT(&Student_List);      break ;
			case 3 : STUDENT_SCORE(&Student_List);     break ;
			case 4 : STUDENT_LIST(&Student_List);      break ;
			case 5 : RANK_STUDENT(&Student_List);      break ;
			case 6 : DELETE_STUDENT(&Student_List);    break ;
			case 7 : exit(0);                          break ;
			default:                                   break ;
		}
		 
	}
}


void NEW_STUDENT(List_t *pStudentList){

    StudentInfo_t LocStudent ;
	Node_t *pLocNode ;
	LocStudent = Helper_GetStudentRecord();
	
	pLocNode = Helper_GetStudentNode(pStudentList , LocStudent.ID );
	if(pLocNode == NULL_ptr){

    	LinkedList_Insert(pStudentList, LocStudent);
		pLocNode = Helper_GetStudentNode(pStudentList ,LocStudent.ID );
    	printf("Success insertion \n\n");

    }else{
		printf("Invalid ID \n\n");
	}
}
static void Swap(Node_t *p1stNode , Node_t *p2ndNode);
static void Swap(Node_t *p1stNode , Node_t *p2ndNode){

	StudentInfo_t TempData = p1stNode->Data ;
	p1stNode->Data = p2ndNode->Data ;
	p2ndNode->Data = TempData ;
}
void STUDENT_LIST(List_t *pStudentList){

    if(pStudentList->Size != 0  && pStudentList !=NULL_ptr)
	{
		/* Sort Linked List Alphabetically Ascending  */
		uint32_t _1stIterator = 0;
		uint32_t _2ndIterator = 0;
        Node_t *pLocNode = NULL_ptr;

		Node_t *plocHead = pStudentList->pHead ;
		for(_1stIterator = 0 ; _1stIterator< pStudentList->Size-1 ; _1stIterator++){
			plocHead =  pStudentList->pHead ;
			for(_2ndIterator = 0 ; _2ndIterator< pStudentList->Size-1 ; _2ndIterator++){
				if(plocHead->Data.Name[0] > plocHead->pNextNode->Data.Name[0] ){
					Swap(plocHead , plocHead->pNextNode);
				}
				plocHead = plocHead->pNextNode;
			}
		}		

		/* Travers Linked List To Display Student Srecord */
        pLocNode = pStudentList->pHead;
        while (pLocNode !=NULL_ptr){

            printf("Student ID  : %hu \n",pLocNode->Data.ID);
			printf("Name        : %s \n",pLocNode->Data.Name);
			printf("Birthdate   : %s \n",pLocNode->Data.BirthDate);
			printf("PhoneNumber : %s \n",pLocNode->Data.PhoneNum);
            printf("----------\n");

			/* Update pLocNode to pointe to the next node */
            pLocNode = pLocNode->pNextNode;
        }
	}else{
		printf("There is no Student ....\n\n");
	}

}

void DELETE_STUDENT(List_t *pStudentList){

	/* Scan The ID for m the User */
    uint16_t LocID;
	printf("Enter ID to delete student records : ");
	scanf("%hu",&LocID);

    Node_t *pLocNode = Helper_GetStudentNode(pStudentList , LocID);
    if(pLocNode !=NULL_ptr){
        LinkedList_Delete(pStudentList , pLocNode->Node_Num);
		printf("Success Deleting\n\n");
    }else {
        printf("Invalid ID \n\n");
    }
}
void STUDENT_EDIT(List_t *pStudentList ){

	uint16_t LocID ;
	printf("Enter Student ID to edit it  : ");
	scanf("%hu",&LocID);

	Node_t *LocNode = Helper_GetStudentNode(pStudentList, LocID);
	if(LocNode != NULL_ptr){

		setbuf(stdout,NULL);
		printf("Exist ID\n\n");
		printf("Student info: %s \t%s\t%s\n",LocNode->Data.Name , LocNode->Data.BirthDate , LocNode->Data.PhoneNum);
		printf ("Enter Student right Name          : ");
		fflush(stdin);
		gets(LocNode->Data.Name);
		printf ("Enter Student right Birthdate     : ");
		scanf("%s",LocNode->Data.BirthDate);
		printf("Enter Student right Phone Number  : ");
		scanf("%s",&LocNode->Data.PhoneNum);

		printf("Success editting\n\n");
	}

	else if(LocNode == NULL_ptr){
		printf("Incorrect ID\n\n");
	}else{
		/*Do Nothing */
	}

}

void STUDENT_SCORE(List_t *pStudentList){
	uint16_t LocID ;
	printf("Enter Student ID to to add the score   : ");
	scanf("%hu",&LocID);

	Node_t *pLocNode = Helper_GetStudentNode(pStudentList, LocID);
	if(pLocNode != NULL_ptr){

		printf("Enter Student Score [0:100]%% : ");
		scanf("%f",&pLocNode->Data.Score);
		printf("Success Inserting Student Score\n\n");
	}
	else if(pLocNode == NULL_ptr){
		printf("Incorrect ID\n\n");

	}else{
		/*Do Nothing */
	}
}

void RANK_STUDENT(List_t *pStudentList){

	if(pStudentList !=NULL_ptr && pStudentList->Size > 0){
		/* Sort Linked List according to the score  */
		uint32_t _1stIterator = 0;
		uint32_t _2ndIterator = 0;
        Node_t *pLocNode = NULL_ptr;

		Node_t *plocHead = pStudentList->pHead ;
		for(_1stIterator = 0 ; _1stIterator< pStudentList->Size-1 ; _1stIterator++){
			plocHead =  pStudentList->pHead ;
			for(_2ndIterator = 0 ; _2ndIterator< pStudentList->Size-1 ; _2ndIterator++){
				if(plocHead->Data.Score < plocHead->pNextNode->Data.Score ){
					Swap(plocHead , plocHead->pNextNode);
				}
				plocHead = plocHead->pNextNode;
			}
		}			
		Node_t *pTempNode = pStudentList->pHead ;
		uint32_t Iterator;
		printf("ID    Name                           : Score\n");
		for(Iterator=0 ; Iterator < pStudentList->Size ; Iterator++){
			printf("%-5hu %-30s : %f\n",pTempNode->Data.ID ,pTempNode->Data.Name , pTempNode->Data.Score);
			pTempNode = pTempNode->pNextNode;
		}
	}else{
		printf("There is no Student yet...\n\n");
	}
}

















