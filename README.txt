##################################################################### 
Algoritmo
#####################################################################

- Para compilar:

    $ make

- Para executar:

    $ ./main [opt1] [opt2]
    
    Onde
        opt1 (obrigatório):
            (1): Caso unidimensional
            (3): Caso tridimensional
            
        opt2 (obrigatório):
            (-1): DTW sem banda
            ([0.0,1.0]): Limites de banda entre 0.0 e 1.0 (apenas para o caso unidimensional)
            
- Exemplo: caso unidimensional com banda de 5%

    $ ./main 1 0.05

    
##################################################################### 
Script execute.sh
#####################################################################

- Script para realizar a execução em batch de 10 testes para cada caso.

- Para executar:

    $ chmod +x execute.sh
    
    $ ./execute.sh [opt1]

    Onde
        opt1 (obrigatório):
            (1): Casos unidimensionais sem banda
            (2): Casos unidimensionais com todas as bandas sugeridas [0.01, 0.05, 0.1, 0.2, 0.5, 1.0]
            (3): Casos tridimensionais   