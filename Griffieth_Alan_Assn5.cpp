#include <cstdlib>
#include "TemplatedLinkedList.h"


class TrainCar {
public:
  static int id;
  static double carID;//Since a new TrainCar is created when a node from the 
  //LinkedList is created, this number is subtracted from id to keep the ids
  //increasing by 1
  int finalID;//This is the correct id that will be displayed
  char typeOfCar;
  int numberOfStops;
  node<char>* car;//the node will be created based off typeOfCar
  TrainCar();
  void SetStops(int x);
};


int TrainCar::id = 1;
double TrainCar::carID = 0;
TrainCar::TrainCar() {
  id++;
  carID += 0.5;
  finalID = id - carID;
  int i = (rand() % 3);//gives a random number 0 - 2, used to determine what
                       //type of car to add
  if(i == 0) {
    typeOfCar = 'P';
  }
  else if(i == 1) {
    typeOfCar = 'C';
  }
  else {
    typeOfCar = 'M';
  }
  car = new node<char>(typeOfCar);
  numberOfStops = (rand() % 5) + 1;//gives a random number 1 - 5;
}

void TrainCar::SetStops(int x) {
  numberOfStops = x;
}


int main() {
  LinkedList<TrainCar> train;
  int addCargoCar = 0;//Keeps track of where to add the cargo car to keep
                      //correct order of P-C-M
  int id;

  for(int i = 0; i < 10; i++) {//Gives the train 10 cars to start out with
    TrainCar newCar;
    if(newCar.typeOfCar == 'P') {
      train.AddToFront(newCar);
      addCargoCar++;
    }
    else if(newCar.typeOfCar == 'C') {
      train.AddAtIndex(newCar, addCargoCar);
    }
    else {
      train.AddToEnd(newCar);
    }
  }

  cout <<"Welcome to the Train Station! Here is your train!" << endl;
  char type;
  int numberOfStops, i, j;
  for(i = 0; i < train.size; i++) {//Displays the train as [ID:Type:Stops]
    type = train.Retrieve(i).typeOfCar;
    id = train.Retrieve(i).finalID;
    numberOfStops = train.Retrieve(i).numberOfStops;
    cout << "[" << id << ":" << type << ":" << numberOfStops << "] ";
  }

  int choice, stops;
  do {//displays menu to the user
    cout << endl << "Menu:" << endl;
    cout << "1 - Enter a number of stops to simulate" << endl;
    cout << "2 - Exit" << endl;

    cin >> choice;

    switch(choice) {
    case 1 :
      cout <<  endl << "How many stops would you like to simulate?";

      cin >> stops;

      for(j = 1; j <= stops; j++) {//Starts at one for display reasons
	cout << endl << endl << "Stop #" << j << ":" << endl;
	cout << "Train Arriving: ";

	for(i = 0; i < train.size; i++) {//Displays the train arriving at the stop
	  type = train.Retrieve(i).typeOfCar;//no changes from last stop
	  id = train.Retrieve(i).finalID;
	  numberOfStops = train.Retrieve(i).numberOfStops;
	  cout << "[" << id << ":" << type << ":" << numberOfStops << "] ";
	}

	cout << endl << "Removing cars:" << endl;

	for(i = 0; i < train.size; i++) {//Goes through each TrainCar and determines
	  numberOfStops = train.Retrieve(i).numberOfStops;//if this is its last stop
	  if(numberOfStops == 1) {//This TrainCar can be removed
	    id = train.Retrieve(i).finalID;
	    type = train.Retrieve(i).typeOfCar;
	    cout << "[" << id << ":" << type << "] removed" << endl;
	    if(train.Retrieve(i).typeOfCar == 'P') {
	      addCargoCar--;//keeps track of where to add cargo car
	    }
	    train.RemovePosition(i);
	    i--;//i must be decremented in case of back to back cars that should be
	  }     //removed
	  
	  else {//the car isn't being removed but its number of stops should decrease
	    TrainCar car = train.Retrieve(i);
	    car.SetStops(numberOfStops - 1);//decreases its stops by 1
	    train.ReplaceNode(car, i);//This function is used since the above would only
	  }                           //change a reference, not the actual node
	}
	int add = (rand() % 5) + 1;//gives a random number 1 through 5
	cout << "Adding cars:" << endl;
	for(i = 0; i < add; i++) {
	  TrainCar newCar;
	  if(newCar.typeOfCar == 'P') {
	    train.AddToFront(newCar);
	    addCargoCar++;
	  }
	  else if(newCar.typeOfCar == 'C') {
	    train.AddAtIndex(newCar, addCargoCar);
	  }
	  else {
	    train.AddToEnd(newCar);
	  }

	  id = newCar.finalID;
	  type = newCar.typeOfCar;
	  numberOfStops = newCar.numberOfStops;
	  cout << "[" << id << ":" << type << ":" << numberOfStops << "] added" << endl;
	}

	cout << "Train Exiting: ";
	for(i = 0; i < train.size; i++) {//Dispays the train as it leaves the stop with all changes
	  type = train.Retrieve(i).typeOfCar;//shown
	  id = train.Retrieve(i).finalID;
	  numberOfStops = train.Retrieve(i).numberOfStops;
	  cout << "[" << id << ":" << type << ":" << numberOfStops << "] ";
	}
      }
      break;

    case 2 :
      cout << "Goodbye!" << endl;

      break;

    default :
      cout << "Not a valid input. Please try again!" << endl;
      break;
    }
  }
  
    

  while(choice != 2);

  return(0);
}
