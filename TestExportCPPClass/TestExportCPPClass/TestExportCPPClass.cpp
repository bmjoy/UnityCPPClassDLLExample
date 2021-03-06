// TestExportCPPClass.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


class Student {
public:
	int score;
	int getGrade()
	{
		const int n = 4;
		int criteria[n] = { 50, 60, 70, 80 };
		int grade = 0;
		for (int i = 0; i < n; i++)
		{
			if (score >= criteria[i])
			{
				grade++;
			}
		}
		return grade;
	}
};

extern "C" {
	__declspec(dllexport) Student* Student_Create() { return new Student(); }
	__declspec(dllexport) void Student_SetScore(Student* student, int score) { student->score = score; }
	__declspec(dllexport) int Student_GetGrade(Student* student) { return student->getGrade(); }
	__declspec(dllexport) void Student_Delete(Student* student) { delete student; }
}