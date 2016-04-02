/* Name: Friends
 * Purpose: Demonstrate use of friend functions
 * Author: Amos Nyarongi
 * Date Created: February 04, 2016
 * Last Modified: April 02, 2016
 ------------------------------------------------------------------------*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Robot {
	friend void setRobotInfo(Robot& robotName);
	friend void getRobotInfo(Robot robotName);
private:
	//Class attributes
	string name = "defaultName";
	string model = "defaultModel";
	int serialNumber = 1234;
public:
	//Constructor
	Robot() {}
	Robot(string nameArg, string modelArg, int serialArg) {
		name = nameArg;
		model = modelArg;
		serialNumber = serialArg;
	}
	~Robot() {} //Deconstructor

				//Accessor methods
	void setName(string name1) { name = name1; }
	void setModel(string model1) { model = model1; }
	void setSerialNumber(int serial1) { serialNumber = serial1; }
	string getName() { return name; }
	string getModel() { return model; }
	int getSerialNumber() { return serialNumber; }
};
//A friend function to only read class attributes
void getRobotInfo(Robot robotName) {
	cout << "\tRobot Name: " << robotName.getName() << endl;
	cout << "\tModel: " << robotName.getModel() << endl;
	cout << "\tSerial Number: " << robotName.getSerialNumber();


}
//Another friend function to both read and modify class attributes
void setRobotInfo(Robot& robotName) {

	robotName.setName("fido");
	robotName.setModel("FD02");
	robotName.setSerialNumber(1002);

	/*This is just to make sure that this function is able to read the attributes as well*/
	cout << "\nModified model: " << robotName.getModel() << endl;

}

int main() {

	Robot fido; // object declaration
	//default state before the setRobotInfo method is called
	cout << "Defaults: " << endl;
	getRobotInfo(fido);
	//Changing the robot settings using setRobotInfo method
	cout << "\n\nModifying settings..." << endl;
	setRobotInfo(fido);
	//after the setRobotInfo method has set the parameters
	cout << "\nAfter the settings are modified: " << endl;
	getRobotInfo(fido);
	cout << "\n" << endl;

	system("pause");
	return 0;
}
