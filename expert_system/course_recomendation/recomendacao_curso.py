class SistemaEspecialista:
    def __init__(self):
        self.base_conhecimento = {
            "Engenharia Civil": {
                "areas": ["ciencias_exatas"],
                "objetivos": ["industria", "pesquisa"],
            },
            "Psicologia": {"areas": ["humanas"], "objetivos": ["docencia", "pesquisa"]},
            "Biologia": {"areas": ["biologicas"], "objetivos": ["docencia", "pesquisa"]},
            "Administração": {"areas": ["humanas"], "objetivos": ["industria"]},
            "Matemática": {"areas": ["ciencias_exatas"], "objetivos": ["docencia"]},
        }

    def recomendar_curso(self, estudante):
        for curso, requisitos in self.base_conhecimento.items():
            if (
                estudante["area_interesse"] in requisitos["areas"]
                and estudante["objetivos_profissionais"] in requisitos["objetivos"]
            ):
                estudante["curso_recomendado"] = curso
                break

        return estudante


# Exemplo de uso
sistema = SistemaEspecialista()
estudante1 = {
    "nome": "João",
    "area_interesse": "ciencias_exatas",
    "objetivos_profissionais": "industria",
}


curso_recomendado = sistema.recomendar_curso(estudante1)
print(f"Cursos Recomendados para o Estudante {estudante1['nome']}: {curso_recomendado["curso_recomendado"]}")
