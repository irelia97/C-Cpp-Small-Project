#include <cstdio>
#include "stu.h"

int Student::num = 0;

void Student::PrintInf()
{
	printf("%-12s %7s %-7s %12s %8s \t%d\n\n", sno.c_str(), sname.c_str(), room.c_str(), tel.c_str() 
											 , sco.GetCourseName().c_str(), sco.GetCourseScore());
}

	
