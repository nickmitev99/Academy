// Задача 3. Напишете програма, в която използвате функцията time(), за да принтирате всяка
// секунда. Използвайте alarm(), за да подадете сигнал за настъпила минута signal (SIGNALRM,..). 

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int iSignal);

int main()
{
  time_t oStart = time(0), oNow = time(0);

  alarm(60);

  while(1)
  {
    oNow = time(0);
    oNow -= oStart;
    printf("%ld\n", oNow);
    sleep(1);
    oNow = time(0);
  }

  signal(SIGALRM, alarm_handler);

  return 0;
}

void alarm_handler(int iSignal)
{
  printf("\nTHE ALARM IS BUZZING!\n");
}