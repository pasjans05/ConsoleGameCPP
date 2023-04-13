//https://helion.pl/
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int hp = 20, mp = 40, ehp = 35;
char mowe;
void lose()
{
  cout << "You lose" << endl;
  hp = 20;
  mp = 40;
  ehp = 20;
}
void win()
{
  cout << "You win" << endl;
  hp = 20;
  mp = 40;
  ehp = 20;
}
int edamage()
{
  int dam;
  srand (time(NULL));
  dam = rand() % 5 + 1;
  return dam;
}
int main()
{
  label:
  cout << "ehp: " << ehp << endl << "hp: " << hp << endl << "mp: " << mp << endl;
  cout << "(1) Attack" << endl << "(2) Magic attack" << endl << "(3) Summon" << endl << "(4) Heal" << endl << "(5) Farm" << endl << "(H) Help" << endl;
  cin >> mowe;
  system("clear");//system("cls");
  cout << "Status:" << endl;
  if (mowe == '1')
  {
    cout << "You sliced the enemy with your sword." << endl;
    ehp -= 1;
    int edam = edamage();
    cout << "The enemy makes " << edam << " damage!" << endl << endl;
    hp -= edam;
    if (ehp <= 0)
    {
      win();
      return 0;
    }
    if (hp <= 0)
    {
      lose();
      return 0;
    }
  }
  else if (mowe == '2' && mp >= 1)
  {
    cout << "You cast a devastating Magic Attack." << endl;
    ehp -= 2;
    mp -= 1;
    int edam = edamage();
    cout << "The enemy makes " << edam << " damage!" << endl << endl;
    hp -= edam;
    if (ehp <= 0)
    {
      win();
      return 0;
    }
    if (hp <= 0)
    {
      lose();
      return 0;
    }
  }
  else if (mowe == '3' && mp >= 15)
  {
    cout << "You have summoned Ultima!" << endl;
    ehp -= 10;
    mp -= 15;
    hp -= 1;
    int edam = edamage();
    cout << "The enemy makes " << edam << " damage!" << endl << endl;
    hp -= edam;
    if (ehp <= 0)
    {
      win();
      return 0;
    }

    if (hp <= 0)
    {
      lose();
      return 0;
    }
  }
  else if (mowe == '4' && mp >= 5)
  {
    cout << "You have used Heal." << endl << endl;
    ehp += 5;
    mp -= 5;
    hp += 10;
  }
  else if (mowe == '5' && hp > 5)
  {
    cout << "You are farming..." << endl << endl;
    mp += 10;
    hp -= 5;
  }
  else if (mowe == 'H') 
  {
    system("clear");
    cout << "Attack\t\t\t1 damage" << endl << "Magic attack\t2 damage" << endl << "Summon\t\t\t10 enemy damage\n\t\t\t\t1 player damage\n\t\t\t\t15 mana cost" << endl << "Heal\t\t\t5 enemy heal\n\t\t\t\t10 player heal\n\t\t\t\t5 mana cost" << endl << "Farm\t\t\t5 player damage\n\t\t\t\t10 mana gain" << endl << "Enemy damage is random in range from 1 to 5." << endl << endl;
  }
  else cout << "Not Found" << endl;
  goto label;
}