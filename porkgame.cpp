#include <iostream>
#include<stdlib.h>
using namespace std;

void info(int money, int porks, int day, int ears, int ears_exp, int bodies, int bodies_exp, int legs, int legs_exp) {
  cout << "Money $" << money << "    porks: " << porks << "    day: " << day << endl
  // Jialing has to do the rest
        << "Ears : " << ears << "    expire after " << ears_exp << "days" << endl
        << "Bodies : " << bodies << "    expire after " << bodies_exp << "days" << endl
        << "Legs : " << legs << "    expire after " << legs_exp << "days" << endl;
}

void buyandsell_info(int pork_price, int demand, int demand_price) {
  cout << "Buy pork at $" << pork_price << " each" << endl;
  cout << "Sell " << ((demand == 1) ? "ears" : (demand == 2) ? "bodies" : "legs") << " at $" << demand_price << " each" << endl;
}

void menu_info() {
  cout << "Options: [B]uy pork, [S]ell piece, [K]ill pork, [A]dvance day" << endl;
}

int random_between(int min, int max) {
  return (rand()%((max-min)+1)+min;
}

void setup_random_info(int& pork_price, int& demand, int & demand_price) {
  pork_price = random_between(100, 300);
  demand = random_between(1, 3);
  demand_price = random_between(10, 50);
}

int main() {
  int money;
  int porks;
  int day;
  int ears;
  int ears_exp;
  int bodies;
  int bodies_exp;
  int legs;
  int legs_exp;
  int pork_price;
  int demand;
  int demand_price;
  
  // Initial state of the game
  money = 500; porks = 0; day = 0;
  ears = 0; ears_exp = 0;
  bodies = 0; bodies_exp = 0;
  legs = 0; legs_exp = 0;

  setup_random_info(pork_price, demand, demand_price);

  while (true) {
    info(money, porks, day, ears, ears_exp, bodies, bodies_exp, legs, legs_exp);
    buyandsell_info(pork_price, demand, demand_price);
    menu_info();

    char command;

    cin >> command;

    if (command == 'B' or command == 'b') {
      if (money>pork_price) {
        cout << "How many? ";
        int how_many;
        cin >> how_many;
        if (money > pork_price*how_many) {
          porks = porks + how_many;
          money = money - pork_price*how_many; 
        }
      }
      else cout << "No pork for you!!"<< endl;
    }
    else if (command == 'S' or command == 's') {
        cout << "How many? ";
        int how_many;
        cin >> how_many;
        int* piece;
        if (demand==1) piece = &ears;
        if (demand==2) piece = &bodies;
        if (demand==3) piece = &legs;
        if (*piece >= how_many) {
          *piece = *piece - how_many;
           money = money + demand_price*how_many;
        }
        else
          cout << "Not enough" << endl;
    }
    else if (command == 'K' or command == 'k') {
      if (porks>=1) { 
        cout << "How many? ";
        int how_many;
        cin >> how_many;
        if (porks>=how_many) {
          porks = porks - how_many;
          ears = ears + how_many*2;
          bodies = bodies + how_many;
          legs = legs + how_many*4; 
          if (ears_exp==0) ears_exp = 30;
          if (bodies_exp==0) bodies_exp = 60;
          if (legs_exp==0) legs_exp = 55;  
        }
      }
      else cout << "No pork to kill"<<endl;
    }
    else if (command == 'A' or command == 'a') {
      day++;
      setup_random_info(pork_price, demand, demand_price);
      // set expire days 
      ears_exp--;
      bodies_exp--;
      legs_exp--;
      if (ears_exp<=0) {ears = 0; ears_exp = 0;}
      if (bodies_exp<=0) {bodies = 0; bodies_exp=0;}
      if (legs_exp<=0) {legs = 0; legs_exp=0;}
     // And what else ?
    }
    cout << "===========================" << endl;
  }

}
