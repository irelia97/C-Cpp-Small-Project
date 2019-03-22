#include "stu.h"

#ifndef _FICTION_H_
#define _FICTION_H_

void Menu();
void PrintList(const STU *head);
void Find(const STU *head);
void AddStu(STU *head);
STU* FindSno(const STU *head, string &sno);
void ModifyStuInf(const STU *head);
void ModifyStuSco(const STU *head);
void DeleteStu(STU *head);
void SaveToTxt(const STU *head);

#endif
