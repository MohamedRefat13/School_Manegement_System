/*
 * School_Private.h
 *
 *  Created on: Aug 8, 2023
 *  Author: Mohamed Refat
 */

#ifndef _SCHOOL_PRIVATE_H
#define _SCHOOL_PRIVATE_H

typedef struct
{
	uint8_t  Name[50] ;
	uint16_t ID ;
	f32_t    Score;
	uint8_t  BirthDate[15] ;
	uint8_t  PhoneNum[15] ;
}StudentInfo_t;

typedef struct Node_t
{
	StudentInfo_t  Data;
	uint32_t Node_Num;
	struct Node_t *pNextNode;
}Node_t;


typedef struct
{
	Node_t *pHead;
	uint32_t Size;
}List_t;

/**
 * @brief                : This Function used to take student records from the user an return it  
 * 
 * @return StudentInfo_t : Student records 
 */
StudentInfo_t Helper_GetStudentRecord(void);

/**
 * @brief          : This function is used to search about Student ID 
 * 						and if it exists return a pointer to this student node
 * 
 * @param pList    : Pointer to the Student linked List 
 * @param Copy_ID  : Copy From the ID
 * @return Node_t* : Node_t = Null_ptr     --> If the ID doesn't exist
 * 					 Node_t = Student_Node --> If the ID exists
 */
Node_t *Helper_GetStudentNode(List_t *pList , uint16_t Copy_ID);

/* Linked List Functions ProtoType */
void LinkedList_Init(List_t *pList);
void LinkedList_Insert(List_t *pList , StudentInfo_t Data );
void LinkedList_Delete(List_t *pList ,uint32_t Position);

#endif /* _SCHOOL_PRIVATE_H */