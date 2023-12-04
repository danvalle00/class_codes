cliente(joao).

prato(salada_vegetariana).
prato(lasanha).
prato(sushi).
prato(frango_assado).
prato(sorvete_de_chocolate).

preferencia(salgado).
preferencia(doce).
preferencia(vegetariano).
preferencia(sobremesa).
preferencia(carne).
preferencia(massa).
preferencia(fruto_do_mar).

restricao(lactose).
restricao(fruto_do_mar).
restricao(carne).
restricao(verdura).
restricao(massa).

recomendar(Cliente, salada_vegetariana) :-
    preferencia_cliente(Cliente, vegetariano),
    preferencia_cliente(Cliente, salgado),
    restricao_cliente(Cliente, verdura).

recomendar(Cliente, lasanha) :-
    preferencia_cliente(Cliente, massa),
    preferencia_cliente(Cliente, salgado),
    restricao_cliente(Cliente, massa).

recomendar(Cliente, sushi) :-
    preferencia_cliente(Cliente, fruto_do_mar),
    preferencia_cliente(Cliente, salgado),
    restricao_cliente(Cliente, fruto_do_mar).

recomendar(Cliente, frango_assado) :-
    preferencia_cliente(Cliente, carne),
    preferencia_cliente(Cliente, salgado),
    restricao_cliente(Cliente, carne).

recomendar(Cliente, sorvete_de_chocolate) :-
    preferencia_cliente(Cliente, sobremesa),
    preferencia_cliente(Cliente, doce),
    restricao_cliente(Cliente, lactose).

preferencia_cliente(joao, vegetariano).
preferencia_cliente(joao, salgado).
restricao_cliente(joao, lactose).