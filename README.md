# feup-cal
Projects for the Conception and Analysis of Algorithms (CAL) class of the Master in Informatics and Computer Engineering (MIEIC) at the Faculty of Engineering of the University of Porto (FEUP). 
<br><br>
Made in colaboration with [Julieta Frade](https://github.com/julietafrade97) and [João Conde](https://github.com/JC13).<br>
**Completed in ____.**
<br><br>
### Tema 1: À procura de estacionamento
**[ Parte 1 ]**<br><br>
Numa cidade, existem diversos locais de estacionamento público: lugares em estrada (parquímetro) ou garagens. O valor do estacionamento varia de local para local.<br>
Neste trabalho, pretende-se implementar um sistema que auxilie um automobilista na procura de um lugar de estacionamento. Um automobilista pretende ir a um local específico (cinema, escola, shopping,...) e quer estacionar o seu automóvel. Deve ser calculado o itinerário que permita ao automobilista ir do local onde se encontra ao estacionamento (de automóvel) e do estacionamento ao local de destino (a pé).<br><br>
O local de estacionamento proposto pode ser o mais perto do destino ou o mais barato (dentro de uma distância máxima ao destino ou a uma estação de metro), de acordo com a escolha do automobilista. Considere também que o automobilista pode querer abastecer o seu automóvel antes de estacionar, pelo que o trajecto indicado deve considerar este facto.<br>
Avalie a conectividade do grafo, a fim de evitar que locais de estacionamento se encontrem em zonas inacessíveis a partir do ponto de origem do automobilista.<br>
Considere a possibilidade de utilizar mapas reais, extraídos do OpenStreetMaps (www.openstreetmap.org), localizando, no mapa, endereços e pontos de interesse.<br><br>
**[ Parte 2 ]**<br><br>
Para a segunda parte deste trabalho, considere que as ruas têm nomes, por exemplo “Rua de Dr Roberto Frias”, e que pertencem a um dado distrito, por exemplo, “Porto”. Estenda o trabalho realizado com funcionalidades apropriadas que permitem ao automobilista selecionar uma rua, pelo seu nome, na tentativa de lá encontrar lugares vagos de estacionamento. Implemente esta funcionalidade, considerando tanto pesquisa exata, assim como pesquisa aproximada, das strings identificativas dos nomes de rua e distrito. Para pesquisa exata, caso o distrito ou o nome de rua não existam, deverá retornar mensagem de destino inexistente. Para a pesquisa aproximada, deverá retornar os distritos e nomes de ruas mais próximos.<br><br>
Estas novas funcionalidades deverão ser integradas no trabalho já realizado para a primeira parte. Avalie a complexidade (teórica e empiricamente) dos algoritmos implementados em função dos dados de input usados. <br><br>

> Entrega Segundo Trabalho (via Moodle, no dia **19/Maio**, até às 24:00) <br>
>> *Nota Mínima:* 8 valores

<br> <br>
 
### Relatório
O relatório, a ser entregue em formato PDF, deverá incluir:

* Página de rosto, com o título do trabalho, a identificação do grupo e dos seus elementos (nome, número, email), e data;
* Descrição do tema, identificação e formalização do problema, em termos de dados de entrada, limites de aplicação, situações de contorno, e resultados esperados;
* Descrição da solução, incluindo as técnicas de concepção e os principais algoritmos implementados, assim como as suas respectivas análises de complexidade (temporal e espacial); A avaliação da complexidade deverá ser analítica e empírica!
* Diagrama de classes, se apropriado;
* Lista de casos de utilização, com as principais funcionalidades implementadas;
* Relato das principais dificuldades encontradas no desenvolvimento do trabalho e a sua solução, se aplicável;
* Indicação do esforço dedicado por cada elemento do grupo, incluindo tarefas realizadas;
* Conclusão do relatório, com análise crítica dos resultados obtidos e principais considerações;
* Sempre que necessário, citar e fornecer as referências da bibliografia utilizada.

<br><br>
Mais informações: https://moodle.up.pt/course/view.php?id=1311
