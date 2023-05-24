#include <iostream>

#define MAX_STUDENTS 3
#define MAX_GRADE 3

// Terminar esse exercicio fazendo ele ler todas as notas e fazer a média de para cada aluno;
// Estudar operações de matrizes
// Fazer os algoritmos das operações de matrizes
int insert_data(float grades[][MAX_GRADE]);


int main()
{
    float grades[MAX_STUDENTS][MAX_GRADE];
    insert_data(grades);
    std::cout << grades[0][0];
        
}
    
int insert_data(float grades[][MAX_GRADE])
{
    std::cout << "Insert the student grande and press [ENTER]:  " << std::endl;
     for (int student = 0; student < MAX_STUDENTS; student++)
    {
        for (int grade = 0; grade < MAX_GRADE; grade++)
        {
            std::cout << "Student " << student << " > Grade " << grade  << ":" <<std::endl;
            std::cin >> grades[student][grade]; 
        }
    }
}

        
        
