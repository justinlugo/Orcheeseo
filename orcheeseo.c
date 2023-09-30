//Justin Lugo
//COP 3502, Fall 2020
//NID: ju522019

#include "Orcheeseo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  // Passing a command line argument into the printOrcheeseo function
  printOrcheeseo(argv[1]);

  return 0;
}

void printOrcheeseo(char *str)
{
  // The program takes in string as argument
  // Declaring variables
  int i = 0, j = 0, n, numOreo = 0, numCream = 0, numGoldfish = 0;
  double oHeight, cHeight, gHeight = 0, sumHeight;

  if (str == NULL || str[0] == '\0')
  {
    // If the string is null or empty, we'll print this
    printf("No cookie. :(\n");
    return;
  }
  // We calculate the string length and store it into an integer variable so
  // that we don't call the strlen function repeatedly in the forecoming for
  // loop
  n = strlen(str);
  // We create a for loop to go through the string if it contains the letters
  // o, c, or g.
  if (str[i] == 'o' || str[i] == 'c' || str[i] == 'g'){
    for (i = 0; i < n; i++)
    {
      // For each detected letter, we print the part of the orcheeseo that
      // corresponds to the letter, while also increasing the count of
      // parts to do the math later on to determine how tall the resulting
      // snack is
      if (str[i] == 'o')
      {
        printf("==========\n");
        while (str[i] == 'o')
        {
          numOreo = numOreo + 1;
          break;
        }
      }
      else if (str[i] == 'c')
      {
        printf(" ~~~~~~~~\n");
        while (str[i] == 'c')
        {
          numCream = numCream + 1;
          break;
        }
      }
      else if (str[i] == 'g')
      {
        // For the letter 'g', we have to do something different, since we have
        // to count consecutive goldfish within the string.
        numGoldfish = 1;
        // The while loop will count consecutive g's, increasing the number of
        // them within the numGoldfish variable for as many integers in the
        // string are equal to g
        // Afterwards, it'll decrease 'i' so that it doesn't skip the next
        // letter in the string
        while (str[++i] == 'g')
        {
          numGoldfish++;
        }
        gHeight += printGoldfish(numGoldfish);
        i--;

        //printf("%f", gHeight);
        // After we print the respective lines to correspond to the number of
        // goldfish, we have to give them heights so that the function can
        // determine whether it is edible and fits in our mouths once the
        // heights are added up
      }
    }
  }
  // We multiply the amount of each part by their respective heights, and then
  // calculate the total height, to determine whether the snack can fit within
  // one's mouth
  oHeight = numOreo * 0.4;
  cHeight = numCream * 0.25;
  sumHeight = oHeight + cHeight + gHeight;
  //printf("%d", numGoldfish);
 
  // printf("%f", sumHeight);
  if (str[0] != 'o' || str[n-1] != 'o')
  {
    // If our resulting snack doesn't have an oreo cookie part on the top,
    // it's too messy to eat.
    printf("Too messy. :(\n");
  }

  /*
  else if (str[n-1] != 'o')
  {
    // If our resulting snack doesn't have an oreo cookie part on the bottom,
    // it's too messy to eat.
    printf("Too messy. :(\n");
  }*/
  else if (numGoldfish == 0 && sumHeight <= 4.0)
  {
    // Sometimes, orcheeseos don't have goldfish. In that case we have a
    // regular oreo.
    printf("Om nom nom! Oreo!\n");
  }
  else if (sumHeight > 4.0)
  {
    // When the cookie is too tall to be eaten.
    printf("Oh nooooo! Too tall. :(\n");
  }
  else if (numGoldfish != 0 && sumHeight <= 4.0)
  {
    // If the cookie has goldfish and can fit into a mouth,
    // we have an Orcheeseo!
    printf("Om nom nom! Orcheeseo!\n");
  }
}

double printGoldfish(int numGoldfish)
{
  // With the number of goldfish being passed into the printGoldfish function,
  // we now proceed to create loops that include modulo statements to determine
  // which line to print to represent the goldfish accurately per the
  // assignment PDF
  double gHeight = 0, totalHeight;
  int originalNum = numGoldfish;

  if (numGoldfish == 0)
  {
    return 0;
  }

  while (numGoldfish != 0)
  {
    if (numGoldfish % 3 == 1)
    {
      if (originalNum == 1)
      {
        printf("  .,.,.,\n");
        numGoldfish -= 1;
        gHeight += 0.1;
      }
      else if (numGoldfish > 1)
      {
        while (numGoldfish > 4)
        {
          printf(" xoxoxoxo\n");
          numGoldfish -= 3;
          gHeight += 0.25;
        }
        printf("xoxoxoxoxo\n");
        numGoldfish -= 4;
        gHeight += 0.25;
      }
    }
    else if (numGoldfish % 3 == 0)
    {
      printf(" xoxoxoxo\n");
      numGoldfish -= 3;
      gHeight += 0.25;
    }
    else if (numGoldfish % 3 == 2)
    {
      printf("  xoxoxo\n");
      numGoldfish -= 2;
      gHeight += 0.25;
    }
  }
  return gHeight;
}

int returnThirtyTwo(void)
{
  // Returning 32.
  return 32;
}

void printThirtyTwo(void)
{
  // Printing 32 to screen.
  printf("32\n");
}

double difficultyRating(void)
{
  // Returning how I feel about assignment difficulty wise.
  return 4.0;
}

double hoursSpent(void)
{
  // Returning how long I spent on the assignment.
  return 6.5;
}
