#include <stdio.h>
#include <stdlib.h>

struct pigi{
    int AM;
    double grade;
};

//fill data function
void filldata(struct pigi x[])
{
 for (int i=0;i<200;i++)
  {
  x[i].AM=5500+i;
  x[i].grade=(rand()%101)/10.0;
  }
}

//gradesavg
double getgradesavg(struct pigi x[])
{
  double sum=0;
  for (int i=0;i<200;i++)
  {
    sum+=x[i].grade;
  }
  return sum/200.;
}

//find max
double megisto(struct pigi x[])
{
  double y=x[0].grade;
  for(int i =1;i<200;i++)
  {
   if (y<x[i].grade)
      {
        y=x[i].grade;
      }
  }
  return y;
}

int putthebestinthearray(struct pigi x[],double z, int y[])
{
  int a=0;
  for (int i=0;i<200;i++)
  {
    if(x[i].grade==z)
    {
      y[a]=x[i].AM;
      a++;
    }
  }
  return a;
}

//show results for avg
void printresultforavg(double avg)
  {
    printf("Ο GradesAverage ειναι: %.2f \n",avg); 
  }

  void printthebest(int y[],double z,int x)
{
  printf("Oι μαθητες με AM: ");
  for(int i=0;i<x;i++)
    {
      printf("%d ",y[i]);
    }
  printf("εχουν το μεγαλυτερο βαθμο");
  printf(" %.1f ",z);
}

int main()
{
    srand(5425);
    struct pigi StudentsGrade[200];
    filldata(StudentsGrade);
    double GradesAverage=getgradesavg(StudentsGrade);
    double max =megisto(StudentsGrade);
    int am_max[200];
    int best=putthebestinthearray(StudentsGrade,max,am_max);
    printresultforavg(GradesAverage);
    printthebest(am_max,max,best);
  return 0;
}

