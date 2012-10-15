#include "DarkGDK.h"

struct database {
  int id_number;
  int age;
  float salary;
};

void DarkGDK()
{
  database employee;  //There is now an employee variable that has modifiable 
                      // variables inside it.
  employee.age = 22;
  employee.id_number = 1;
  employee.salary = 12000.21;

  dbPrint(dbStr(employee.age));
  dbWaitKey();
}