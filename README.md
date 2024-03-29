# trabalho_aed
questao fila 

Um lava-rápido tem capacidade máxima de atendimento de k carros, onde um está sendo lavado e k − 1 em espera.
Cada lavagem leva 3 minutos. Ao chegar um novo cliente, o sistema ou o atende imediatamente, caso esteja completamente
livre, ou o coloca em espera, ou o rejeita, caso já existam k carros sendo atendidos.
Escreva um programa em linguagem C que receba como entrada inteiros n ≥ 1 e k ≥ 0 e um vetor binário V de
tamanho n, por exemplo, 001011100111000111, onde o i-ésimo bit da esquerda para a direita vale “1” se um novo cliente
chega no i-ésimo minuto, e “0” se nenhum novo cliente chega no i-ésimo minuto.
O programa deve calcular quantos carros foram lavados pelo sistema até o n-ésimo minuto. Use uma fila implementada
seguindo alocação dinâmica para representar o sistema a cada minuto que passa, lembrando que a fila pode comportar
no máximo k carros.
