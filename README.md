# Jogo-da-Vida
Programa que simula, de maneira básica, o Jogo da vida em linguagem C. Projeto simples realizado para a matéria de Projeto e Análise de Algoritmos.

Esse Programa consiste em um Jogo da Vida que utiliza uma matriz 5x5 predefinida. 

REGRAS:
-
A ideia inicial é começar com uma configuração simples de células vivas em uma matriz, constituindo a primeira geração. Então, com o passar das gerações, as regras de mudança são aplicadas. 
As regras são:

    1° Uma célula viva com 2 ou 3 vizinhos vivos, permanece viva;
    2° Uma célula viva com apenas 1 ou 0 vizinhos vivos, morre (solidão);
    3° Uma célula viva com 4 ou mais vizinhos, morre (sufocada);
    4° Uma célula morta com exatamente 3 vizinhos vivos, renasce.
