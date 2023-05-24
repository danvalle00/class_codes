#include <iostream>

#define MAX_STUDENTS 3
#define MAX_GRADE 3

// TODO: Terminar esse exercicio fazendo ele ler todas as notas e fazer a média de para cada aluno; DONE
int insert_data(float grades[][MAX_GRADE]);

int main()
{
    float grades[MAX_STUDENTS][MAX_GRADE];
    float avarage_grade[MAX_STUDENTS];
    int temp;
    insert_data(grades);

    // Iterating all grades and students;
    for (int student = 0; student < MAX_STUDENTS; student++)
    {
        for (int grade = 0; grade < MAX_GRADE; grade++)
        {
            avarage_grade[student] += grades[student][grade];
        }
        std::cout << (avarage_grade[student] / MAX_GRADE) << std::endl;
    }
}

int insert_data(float grades[][MAX_GRADE])
{
    std::cout << "Insert the student grande and press [ENTER]:  " << std::endl;
    for (int student = 0; student < MAX_STUDENTS; student++)
    {
        for (int grade = 0; grade < MAX_GRADE; grade++)
        {
            std::cout << "Student " << student << " -> Grade " << grade << ": ";
            std::cin >> grades[student][grade];
        }
    }
}
