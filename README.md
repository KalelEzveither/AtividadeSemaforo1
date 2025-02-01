# README - Semáforo com Temporizador Periódico

## Descrição
Este projeto implementa um semáforo utilizando a Raspberry Pi Pico W, baseado na função `add_repeating_timer_ms()` do Pico SDK. O semáforo segue um ciclo contínuo de mudança de cores (vermelho → amarelo → verde) com um intervalo de 3 segundos entre as transições.

## Componentes Utilizados
- **Microcontrolador:** Raspberry Pi Pico W
- **LEDs:** 3 LEDs (vermelho, amarelo e verde)
- **Resistores:** 3 resistores de 330Ω

## Funcionamento
1. O semáforo inicia no estado **vermelho**.
2. Após 3 segundos, muda para **amarelo**.
3. Após mais 3 segundos, muda para **verde**.
4. Depois de mais 3 segundos, volta para **vermelho**, reiniciando o ciclo.
5. O loop de execução garante a repetição contínua do funcionamento.
6. Mensagens são enviadas pela porta serial a cada 1 segundo para indicar que o semáforo está em funcionamento.

## Autor
**Kalel Ezveither**

## Vídeo de teste 
https://drive.google.com/file/d/1dbzP9ndycJ9Z1qGEp8TByYcwjrUhOjqT/view?usp=drive_link
