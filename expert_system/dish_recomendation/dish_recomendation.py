class SistemaEspecialista:
    def __init__(self):
        self.pratos = [
            {
                "nome": "Salada Vegetariana",
                "tipos": ["vegetariano", "salada", "salgado"],
                "restriçoes_prato": ["verduras", "hortalicas"],
            },
            {
                "nome": "Lasanha",
                "tipos": ["massa", "carne", "salgado"],
                "restriçoes_prato": ["massa", "ovo", "carne"],
            },
            {
                "nome": "Sushi",
                "tipos": ["peixe", "vegetariano", "salgado"],
                "restriçoes_prato": ["frutos do mar"],
            },
            {
                "nome": "Frango Assado",
                "tipos": ["carne", "salgado"],
                "restriçoes_prato": ["carne"],
            },
            {
                "nome": "Sorvete de Chocolate",
                "tipos": ["doce", "vegetariano"],
                "restriçoes_prato": ["lactose"],
            },
        ]

    def verificar_preferencias(self, prato, cliente):
        return any(tipo in cliente["preferencias"] for tipo in prato["tipos"])

    def verificar_restricoes(self, prato, cliente):
        return not any(
            restricoes in cliente["restricoes"]
            for restricoes in prato["restriçoes_prato"]
        )

    def recomendar_prato(self, cliente):
        pratos_compativeis = []
        for prato in self.pratos:
            if self.verificar_preferencias(
                prato, cliente
            ) and self.verificar_restricoes(prato, cliente):
                pratos_compativeis.append(prato["nome"])
        return pratos_compativeis


cliente1 = {
    "nome": "João",
    "preferencias": ["vegetariano", "doce"],
    "restricoes": ["lactose"],
}

sistema = SistemaEspecialista()
pratos_recomendados = sistema.recomendar_prato(cliente1)
print(f"Pratos recomendados para {cliente1['nome']}: {pratos_recomendados}")
