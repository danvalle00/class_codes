sintoma('Carro não liga. Luzes fracas no painel. (sim/nao)').
sintoma('Carro está puxando para um lado. Pressão do pneu diminuída. (sim/nao)').
sintoma('Indicador de temperatura no painel está muito alto. Fumaça saindo do capô. (sim/nao)').
sintoma('Barulho metálico ao frear. Distância de frenagem aumentada. (sim/nao)').

diagnostico(bateria_descarregada).
diagnostico(pneu_furado).
diagnostico(motor_superaquecido).
diagnostico(freios_desgastados).



realizar_diagnostico(Problema) :-
    write(Problema),
    nl,
    read(Resposta),
    asserta(resposta(Resposta)).


diagnosticar :-
    realizar_diagnostico('Carro não liga. Luzes fracas no painel. (sim/nao)'),
    (resposta(sim) ->
        write(bateria_descarregada),
        nl
    ;
        realizar_diagnostico('Carro está puxando para um lado. Pressão do pneu diminuída. (sim/nao)')
        (resposta(sim) ->
            write(pneu_furado),
            n1
        ;
            realizar_diagnostico('Indicador de temperatura no painel está muito alto. Fumaça saindo do capô. (sim/nao)')
            (resposta(sim) ->
                write(motor_superaquecido),
                n1
            ;
                realizar_diagnostico('Barulho metálico ao frear. Distância de frenagem aumentada. (sim/nao)')
                (resposta(sim) ->
                    write(freios_desgastados),
                    n1
                ;
                    write("Problema não identificado") ,  
                )))),
    retractall(resposta(_))
