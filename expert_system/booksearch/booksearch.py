class BookSearch:
    def __init__(self):
        self.baseConhecimento = {
            "O Homem-Aranha no Aranhaverso": {
                "tipoPesquisa": ["simples"],
                "generoLivro": ["ficcaoCientifica"],
            },
            "1984": {
                "tipoPesquisa": ["simples"],
                "generoLivro": ["ficcaoCientifica"],
            },
            "Romeu e Julieta": {
                "tipoPesquisa": ["simples"],
                "generoLivro": ["romance"],
            },
            "It: A Coisa": {
                "tipoPesquisa": ["simples"],
                "generoLivro": ["terror"],
            },
            "Cem anos de Solidao": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["romance"],
            },
            "O corte de espinhos e rosas": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["romance"],
            },
            "Orgulho e Preconceito": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["romance"],
            },
            "O Iluminado": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["terror"],
            },
            "Psicose": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["terror"],
            },
            "Duna": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["ficcaoCientifica"],
            },
            "Neuromancer": {
                "tipoPesquisa": ["avancado"],
                "generoLivro": ["ficcaoCientifica"],
            },
        }
        self.avaliacoesLivros = {
            "Romeu e Julieta": 4.5,
            "Cem anos de Solidao": 4.75,
            "O corte de espinhos e rosas": 4.2,
            "Orgulho e Preconceito": 4.6,
            "It: A Coisa": 4.1,
            "O Iluminado": 4.7,
            "Psicose": 4.0,
            "O Homem-Aranha no Aranhaverso": 4.6,
            "Duna": 4.4,
            "Neuromancer": 4.2,
            "1984": 4.0,
        }

        self.databaseHistorico = dict()
        self.livrosFavoritados = dict()

    def mostrarHistorico(self):
        if not self.databaseHistorico:
            print("Historico de pesquisa vazio!")
            return

        for keys, values in self.databaseHistorico.items():
            print(f"Pesquisado por: {keys}\nTitulo do Livro: {values}")

    def mostrarFavoritados(self):
        if not self.livrosFavoritados:
            print("Lista de favoritos vazia!")
            return
        respNome = input("Qual nome de usuario deseja procurar os Favoritos? ")
        for keys, values in self.livrosFavoritados.items():
            if keys == respNome:
                print(f"Livros favoritados por: {respNome}")
                print(values)
            else:
                print(
                    f"Nao foi encontrado nenhum livro favoritado pelo usuario {respNome}"
                )

    def pesquisaRecomendado(self, usuario):
        for livro, genero in self.baseConhecimento.items():
            if (
                usuario["tipoPesquisa"] in genero["tipoPesquisa"]
                and usuario["generoPref"] in genero["generoLivro"]
            ):
                usuario["livroRecomendado"] = livro
                updateDatabase = {usuario["nome"]: livro}
                self.databaseHistorico.update(updateDatabase)
                break
        return usuario

    def chatPerguntas(self, usuario):
        print("\nQue tipo de pesquisa você deseja utilizar?")
        print("1 => Simples")
        print("2 => Avancado")
        respPesquisa = input()

        if respPesquisa == "1":
            respPesquisa = "simples"
        elif respPesquisa == "2":
            respPesquisa = "avancado"
        else:
            return

        print("\nQual gênero de Livro deseja procurar? ")
        print("1 => Romance")
        print("2 => Terror")
        print("3 => Ficcao Cientifica")

        respGenero = input()
        if respGenero == "1":
            respGenero = "romance"
        elif respGenero == "2":
            respGenero = "terror"
        elif respGenero == "3":
            respGenero = "ficcaoCientifica"
        else:
            return

        usuario["tipoPesquisa"] = respPesquisa
        usuario["generoPref"] = respGenero

        return usuario

    def favoritarLivroRecomendado(self, usuario):
        print("Deseja Favoritar esse Livro? ")
        print("1 => Sim!")
        print("2 => Não")
        respFav = input()

        if respFav == "1":
            updateFavoritos = {usuario["nome"]: usuario["livroRecomendado"]}
            self.livrosFavoritados.update(updateFavoritos)
            print("Livro Favoritado com Sucesso!")
        elif respFav == "2":
            return False

    def menuSistema(self):
        print("\nEscolha uma opção: ")
        print("1 => Procurar Recomendações")
        print("2 => Visualizar o Histórico de Livros")
        print("3 => Visualizar os Livros Favoritados")
        print("4 => Cancelar a Pesquisa")
        print("5 => Exibir informacao do Usuario")

    def cadastroUsuario(self, usuario):
        print("Insira o nome de Usuario:")
        respNome = input("Usuario: ")
        print("Insire a senha: ")
        respSenha = input("Senha: ")
        usuario["nome"] = respNome
        usuario["senha"] = respSenha

        return usuario


pesquisa = BookSearch()
usuario1 = dict()

pesquisa.cadastroUsuario(usuario1)

while True:
    pesquisa.menuSistema()
    respFav = input()
    if respFav == "1":
        pesquisa.chatPerguntas(usuario1)
        pesquisa.pesquisaRecomendado(usuario1)
        print(
            f"Livro recomendado para o Usuario {usuario1['nome']}: {usuario1['livroRecomendado']}"
        )
        print(
            f"Avaliacao do Livro: {pesquisa.avaliacoesLivros[usuario1['livroRecomendado']]}/5\n"
        )
        pesquisa.favoritarLivroRecomendado(usuario1)
        continue
    elif respFav == "2":
        pesquisa.mostrarHistorico()
    elif respFav == "3":
        pesquisa.mostrarFavoritados()
    elif respFav == "4":
        print("Cancelando a Execucao")
        break
    elif respFav == "5":
        print(f"Usuario: {usuario1['nome']}")
        print(f"Senha: {usuario1['senha']}")
    else:
        print("Opcao nao encontrada, Tente novamente! ")
        continue
