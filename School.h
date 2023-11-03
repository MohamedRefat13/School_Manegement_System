/*
 * School.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Mohamed Refat
 */

#ifndef _SCHOOL_H
#define _SCHOOL_H


#include "School_Private.h"


/* School system Functions ProtoTypes */

/**
 * @brief This function displays the welcome screen and targeted activates.
 *          
 * 
 */
void MAIN_MENU (void);

/**
 * @brief This function creates a new student account.
 *        it asks about details of the student such as name, 
 *        date of birth, ID and phone number.
 *      
 * 
 * @param pStudentList pointer to the student list that you want to add the student to it
 */
void NEW_STUDENT(List_t *pStudentList);

/**
 * @brief This function, you can view the students information 
 *        such as name, date of birth, ID and phone number in table
 *        form (alphabetically ascending).
 * 
 * @param pStudentList pointer to the student list 
 */
void STUDENT_LIST(List_t *pStudentList);

/**
 * @brief This function is for deleting a student account.
 *          it asks about the ID of the student. 
 * 
 * @param pStudentList 
 */
void DELETE_STUDENT(List_t *pStudentList );

/**
 * @brief This function has been used for updating a particular student account.
 *          it asks about the ID of the student. 
 *      
 * @param pStudentList 
 */
void STUDENT_EDIT(List_t *pStudentList );

/**
 * @brief This function has been used for updating score of all students.
 * 
 * @param pStudentList 
 */
void STUDENT_SCORE(List_t *pStudentList);

/**
 * @brief This function can sort all students according to the student score
 * 
 * @param pStudentList 
 */
void RANK_STUDENT(List_t *pStudentList);


#endif /* _SCHOOL_H */