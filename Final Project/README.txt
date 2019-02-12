Olá professor, como sempre, os conteúdos de descrição de projeto estão na wiki do nosso github.
https://github.com/Rapeize/Intercom/wiki

Sobre a parte de código, nós temos um app funcionando fazendo socket WLAN e fazendo as funções básicas necessárias.
Fizemos também o server apache com o QR Code. Isto se encontra no manual. A página listando os usuários é:
http://rapeizeintercom.duckdns.org:8000/

O manual se encontra em:
https://docs.google.com/document/d/1fsWAaIqQdOSjUvO9c1UL6addFDj1IQITaupi8ZkAiYg/edit?usp=sharing

Não desenvolvemos a parte de bluetooth por falta de tempo.

Os horários de todos, só de reuniões gerais e pesquisando em conjunto, os 3 participantes realizaram 22 horas.
Fora isso foi planejado um trabalho de mais 10 horas semanais cada um.
Total 62 horas de cada membro no projeto.
Para se ter uma ideia, apenas eu Rafael escrevi mais ou menos 2300 linhas de código em C++ que estamos utilizando no momento entre testes e código principal.
Nossa dedicação foi grande, mas tivemos muitos problemas por falta de experiência do grupo nas partes do aplicativo android e da comunicação socket.
Perdemos um sábado inteiro só tentando fazer o socket de WLAN em C++.

Também pela falta de conhecimento em banco de dados, acabei criando um banco de dados nosso em CSV que deu também muito trabalho, mas aprender MySQL com o tempo que tinhamos pareceu mais complicado ainda.

Devido a falta de prática com os problemas citados acima, o nosso cronograma ficou bem bagunçado a partir da terceira semana, não conseguimos entregar as coisas previstas.

A parte de controle e do servidor ficou muito boa e utilizei muitos os throws para pegar erros. Foram feitos muitos testes que colocamos tanto em código quanto no Test Plan da wiki incluindo um Runtime para medir performance.

Para simular a porta colocamos um pino GPIO da Raspberry Pi em 1 (pino 4) e testamos acendendo um led.

O código está no github e está totalmente comentado com padrão doxygen se quiser gerar um documento (isto não cheguei a testar).
https://github.com/Rapeize/Intercom.