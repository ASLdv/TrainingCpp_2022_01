#include <iostream>
using namespace std;
class PersonClass
{

public:


    char m_name[100] = "empty"; 
    unsigned int m_age = 0u;        // years old
    float m_score = 0.f;            // average score on the assessment

    void print()
    {
        cout << "\r\nName: " << m_name << "[ " << m_age << " years old, avarage score is " << m_score << " ]";

    }

};

#define COUNT_OF_STUDENTS 3     


void SortByScore(PersonClass* in, int* out)
{
    float max = 0.;
    int index = 0;
    float temp_score;
    int temp_index;
    float ar_score[COUNT_OF_STUDENTS];
    int ar_index[COUNT_OF_STUDENTS];

    // local copy of array
    for (int i = 0; i < COUNT_OF_STUDENTS; i++)
    {
        ar_score[i] = in[i].m_score;
        ar_index[i] = i;
    }

    
    for (int j = 0; j < COUNT_OF_STUDENTS - 1; j++)
    {
        max = ar_score[j];
        index = j;

        for (int i = j+1; i < COUNT_OF_STUDENTS; i++)
        {
            if (ar_score[i] > max)
            {
                max = ar_score[i];
                index = i;
            }
        }


        temp_score = ar_score[j];
        temp_index = ar_index[j];

        ar_score[j] = max;
        ar_index[j] = index;

        ar_score[index] = temp_score;
        ar_index[index] = temp_index;
        
    }

    for (int i = 0; i < COUNT_OF_STUDENTS; i++)
    {
        *out++ = ar_index[i];
    }
}

float average_age(PersonClass* in)
{
    float age = 0.f;

    for (int i = 0; i < COUNT_OF_STUDENTS; i++)
    {
        age += (float)in[i].m_age;
    }

    return age / COUNT_OF_STUDENTS;
}

int main() {
    cout << "\n\n\n\nStart\n\n\n\r\n";

    PersonClass Person1{"Anton", 41, 1.2};
    PersonClass Students[COUNT_OF_STUDENTS];
    int SortedByScore[COUNT_OF_STUDENTS] = {0};

    memcpy(Students[0].m_name, "Ostap Bender", sizeof("Ostap Bender"));
    Students[0].m_age = 25u;
    Students[0].m_score = 2.2f;
    memcpy(Students[1].m_name, "Panikovsky", sizeof("Panikovsky"));
    Students[1].m_age = 34u;
    Students[1].m_score = 2.21f;
    memcpy(Students[2].m_name, "Shura Balaganov", sizeof("Shura Balaganov"));
    Students[2].m_age = 41u;
    Students[2].m_score = 3.67f;

    


    cout << "\nRaw list:";
    for (int i = 0; i < COUNT_OF_STUDENTS; i++)
    {
        Students[i].print();
    }
    cout << "\n\nList sorted by score:";
    SortByScore(Students, SortedByScore);
    for (int i = 0; i < COUNT_OF_STUDENTS; i++)
    {
        Students[SortedByScore[i]].print();
    }
    cout << "\n\nAverage age is: " << average_age(Students);

    cout << "\n\n\nStop\n\n\n\n";
    return 0;
};