/* W. H. Bell
** This program demonstrates usage of the standard input and standard 
** output streams together with if, switch and do-while.
*/

#include <iostream>

using namespace std;

void numFingers(int);
void pickColour(void);
bool quitTime(void);

int main() {
  do {
    numFingers(3);
    cout << endl; 
    pickColour();
    cout << endl;
  } while (!quitTime()); // Loop until ready to quit.
  return 0;
}

void numFingers(int answer) {
  int fingers;

  cout << "How many fingers am I holding up?" << endl;
  cin >> fingers;

  if(fingers==answer) {
    cout << "Correct!" << endl;
  }
  else if(fingers>10 || fingers<0) {
    cout << "That is not possible with two hands!" << endl;
  }
  else {
    cout << "Wrong.  Try again." << endl;
  }
}

void pickColour(void) {
  char colourFlag;

  cout << "Pick a colour by its first letter.  (E.g. black => b)" << endl;
  cin >> colourFlag;

  switch (colourFlag) {
  case 'y' : cout << "Custard is yellow.  Best served hot with apple pie."
		       << endl; break;
  case 'g' : cout << "Green blades of grass waving in the wind."
		      << endl; break;
  case 'b' : cout << "As black as the nights sky on a cloudy winters night."
		      << endl; break;
  case 'r' : cout << "Fast cars and hot metal." << endl; break;
  default : cout << "That colour does not sound poetic." << endl; break;
  }
}

bool quitTime(void) {
  char quitAnswer;

  cout << endl << "Would you like to quit? (y/n)" << endl;
  cin >> quitAnswer;

  if(quitAnswer=='y' || quitAnswer=='Y') {
    return true;
  }
  else {
    return false;
  } 
}
