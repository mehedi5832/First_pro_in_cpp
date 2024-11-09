#include<iostream>
#include<string>
using namespace std;
class student
{
    private:
    string name;
    int rollNumber;
    float marks[5];
    float totalMarks;


    public:
    student(string n, int roll, float m[]) // Constructor to initialize the attributes
    {
        name= n;
        rollNumber= roll;
        totalMarks= 0.00;
        for(int i=0 ; i<5 ; i++)
        {
           marks [i] = m[i];

        }

    }
void calculatetotalMarks ()
{
    totalMarks = 0.00;
    for( int i= 0 ; i<5 ; i++)
    {
        totalMarks += marks [i];

    }
}
void displayInfo()
{
    cout<< "Name: "<< name <<endl;
    cout<< "Roll Number: "<< rollNumber <<endl;
    cout<< "Marks: "<<endl;
    for( int i=0 ; i<5; i++)
    {
        cout<< marks[i]<< " ";
    }
    cout<< endl ;
    cout<< "Total Marks: "<< totalMarks <<endl;
    cout << "Percentage: "<< calculatePercentage()<< " % " << endl;

}
float calculatePercentage()
{
    return ( totalMarks / 500.00) * 100 ;

}
};
int main()
{
    float marks1[5]= { 85,80,99,92,96};
    float marks2[5]={ 80,82,83,95,97};

    student student1 ("Mehedi Hassan", 101, marks1);
    student student2 ("Masud", 102, marks2);

    student.calculateTotalMarks();
    student.calculateTotalMarks();


    student1.displayInfo();
    cout<< endl<< endl;

    student2.displayInfo();
    cout<< endl<< endl;


    return 0;

}

