# Meu Sismógrafo

Eu moro em Lagoa Santa, muito próximo à uma mineradora onde é extraido calcário, para a fabricação de cimento.  
Quando nos mudamos para cá, fomos informados quanto às detonações, que acontecem apenas em um determinado horário do dia, e que devíamos ficar atentos quando os tremores das explosões fossem fortes a ponto de serem sentidos dentro de casa.  
Durante o periodo que moramos aqui, fomos percebendo que os tremores estavam ficando cada vês mais fortes, e várias rachaduras começaram a aparece dentro de casa, e em alguns casos, parafusos das portas de vidro chegaram a cair, meu monitor balançava muito, e uma vez foi possível ver o flash da detonação de dentro do nosso quarto. Na reunião da associação de moradores há relatos de quebra de vidros de janelas e até mesmo de uma MESA DE GRANITO que se partiu com a explosão.  
Como eu estava a muito tempo querendo iniciar um projeto para fazer com [Arduino](www.arduino.cc) tive a idéia de tentar de alguma forma registrar o que acontece com o prédio onde moro e tentar, quem sabe, com alguma faculdade de estudar o problema que se passa em nosso bairro.

A intenção desse projeto é:

- Medir o movimento feito pelo prédio nos 3 eixos (X, Y, Z);
- Registrar esses dados em um cartão de memória em formato CSV;
- Enviar esses dados para um banco de dados local através de uma API (feita em [Python](www.python.org)  -> [FastAp](https://fastapi.tiangolo.com/));
- Fazer a simulação da movimentação do prédio durante as detonações;
- Ter uma base de registros para reclamações junto aos órgãos competentes;
- Utilizar software livre em todas as partes;
- Incentivar a sociedade criar e compartilhar ferramentas que ajudem a dar voz ao seu [direito de ser humano](https://declaracao1948.com.br/declaracao-universal/declaracao-direitos-humanos/), permitindo a monitoração do meio onde vive, a fiscalização dos atores, e dar vistas aos problemas que a afeta e que infringe tais direitos inerentes a cada cidadão.  
Esse é o sonho que eu tenho (me senti o Martin Luther King Jr. agora).

## Componentes Iniciais

- [Arduino Uno Blackboard](https://www.robocore.net/loja/arduino/arduino-blackboard): Essa placa veio junto com o kit que comprei a uns anos atrás, ela será utilizada na prototipação e poderá ser substituida por uma placa [Arduino Pro Mini](https://www.robocore.net/loja/arduino/arduino-blackboard-pro-mini-5v-16mhz) que veio em outro kit que eu havia adquirido e não toquei o projeto para frente. (Obs: link meramente ilustrativo.)

- [Módulo WiFi Serial ESP8266 ESP-01s - S Series](https://www.eletrogate.com/modulo-wifi-serial-esp8266-esp-01s-s-series): Módulo para a fazer a comunicação do arduino com um servidor, permitindo a troca de dados entre a placa e o serividor, reduzindo a necessidade de remoção do cartão de memória para leitura e analise dos dados.  

- [Módulo Real Time Clock RTC Ds1302](https://www.eletrogate.com/modulo-real-time-clock-ds1302): Esse módulo possibilita que o sistema saiba qual a data e hora dos acontecimentos, não precisando de acesso a um servidor para saber tal informação, e também, vai permitir com que possamos iniciar e terminar a medição em horários pré definidos fazendo com que a quantidade de dados gravada seja bem menor.

- [Módulo Cartão Micro SD](https://www.filipeflop.com/produto/modulo-cartao-micro-sd/): Esse módulo permitirá ter um log de dados para quando a luz cair, ou perder a conexão com o servidor.

- [Acelerômetro e Giroscópio 3 Eixos 6 DOF MPU-6050 GY-521](https://www.eletrogate.com/acelerometro-e-giroscopio-3-eixos-6-dof-mpu-6050-gy-521): Esse módulo será utilizado para fazer a medição da movimentação do prédio. Uma vez que ele mede a aceleração nos 3 eixo e o giro nos 3 eixos, com esses dados podemos fazer a simulação da movimentação durante o evento. E o interessante é que ele possui um sensor de temperatura embutido, permitindo o acionamento de algum sistema de refrigeração caso a temperatura suba muito.  

## Componentes Opcionais

- [Raspberry Pi 4b 4GB RAM](https://www.filipeflop.com/blog/novidade-na-filipeflop-conheca-a-raspberry-pi-4-model-b-anatel/): Eu tenho disponível um [Raspberry Pi](https://www.raspberrypi.org/) em sua versão 4, de 4gb de RAM, comprado da China. A intenção é ter uma API feita em python no micro framework [FastApi](https://fastapi.tiangolo.com/) para a coleta dos dados. Uma vez que a comunicação entre os sensores e a máquina poderá ser feita via WiFi do meu prório roteador.

## Softwares

- [Sistema Operacional DEBIAN](https://www.debian.org/) Pelo fato de ser meu S.O. preferido e utilizado no meu notebook pessoal.
- [Python](www.python.org) em sua versão 3.7 ou 3.8 para a criação da API
- [FastApi] (https://fastapi.tiangolo.com/) Para a criação da API para recepção dos dados.
- [PostgreSQL](https://www.postgresql.org/) Banco para armazenar os dados recebidos, (Uma bazooca para matar uma formiga?!?!)
- [SQLite](https://www.sqlite.org/index.html) Talvês seja mais indicado para receber os dados, por não ser mais leve que o PostgreSQL, e não precisar de instalação e muita configuração. (Além de ser meu banco lite preferido.)
- IDE Arduino para fazer a programação do arduino (Quem sabe eu não aprendo a utilizar o VSCODE para programar pro arduino/ESP e outros também).
- [VSCODE](https://code.visualstudio.com/) - Para fazer a programação em Python, atualmente meu editor de textos preferido.
- Git(lab|hub) para o versionamento de código, no início será o [GitHub](www.github.com) em função do desafio [100 Days of Code](https://www.100daysofcode.com/) que será aplicado a esse projeto.
- Um software que faça a simulação do movimento do prédio.

## Inicio

>> First Things First.  

Primeiro, iniciar pelo teste de cada componente.
