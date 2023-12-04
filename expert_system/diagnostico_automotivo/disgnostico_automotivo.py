class SistemaEspecialista:
    def __init__(self):
        self.problemas = [
            "Carro não liga. Luzes fracas no painel.? (sim/não)",
            "Carro está puxando para um lado. Pressão do pneu está baixa. (sim/não)",
            "Indicador de temperatura no painel está muito alto. Fumaça saindo do capô. (sim/não)",
            "Barulho metálico ao frear. Dificuldade na hora de frear. (sim/não)",
        ]
        self.diagnosticos = [
            "Bateria Descarregada",
            "Pneu Furado",
            "Motor Superaquecido",
            "Freios desgastados",
        ]

    def diagnosticar(self):
        for pergunta, diagnostico in zip(self.problemas, self.diagnosticos):
            resposta = input(pergunta)
            if resposta.lower() == "sim":
                return diagnostico
        return "Não foi identificado o problema"


se = SistemaEspecialista()
diagnostico = se.diagnosticar()
print("Diagnóstico:", diagnostico)
