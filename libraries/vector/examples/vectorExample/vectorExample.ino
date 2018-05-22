#include <vector.h>

Vector<int> int_list;          // Make a Vector instance of int's
void setup() {
  Serial.begin(9600);
  
//------------------------------ Add 4 elements to the array   
  int_list.push_back(1);        
  int_list.push_back(2);
  int_list.push_back(3);
  int_list.push_back(4);
//------------------------------  
  // the array size is 4
  printAllElements();         // Prints all elements to the console
  
  int lastElement = int_list.pop_back();  // Gets the last element from the array back and deletes the last place in the array
  Serial.print("last element was:\t");
  Serial.println(lastElement);
  
  // now the array size is 3
  printAllElements();         // Prints all elements to the console
  
  // Predefine a size of the Array "3" and initialize it to the value "2"
  Vector<int> secondVector(3,2); // Make a new Vector instance of int's

  secondVector.push_back(10); // Fill in some numbers in the array
  secondVector.push_back(11);
  secondVector.push_back(12);
  Serial.println("resize: ");
  secondVector.resize(10);
  Serial.print("size: ");
  Serial.println(secondVector.size());
  Serial.print("cap: ");
  Serial.println(secondVector.capacity());
// [1][2][3] += [2][2][2][10][11][12] =  [1][2][3][2][2][2][10][11][12]
   int_list  += secondVector;   // Add the secondVector to the int_list;
  
   printAllElements();           // Prints all elements to the console
  
//     [1][2][3][2][2][2][10][11][12]
//pos   0  1 (2--3--4) 5  6   7   8
//     [1][2]         [2][10][11][12] 
//     [1][2][2][10][11][12] 
  int_list.erase(2,3);          // Delete form pos 2, 3 elements
  
  printAllElements();           // Prints all elements to the console
  
  int_list.clear();          // Delete form pos 2, 3 elements
  
  printAllElements();           // Prints all elements to the console
}

void loop() {
  
}

void printAllElements()
{
  Serial.println("------------");
  Serial.print("\nArray size:      \t");
  Serial.println(int_list.size());        // Gets the size of the array
  Serial.println();
  for(int a=0; a<int_list.size(); a++)
  {
    Serial.print("position ");
    Serial.print(a);
    Serial.print(" is: \t");
    Serial.println(int_list[a]);               // Gets the element a of the array
                                          // vec[1] -> [1][2][3]
                                          //               |
                                          //
                                          // vec[0] -> [1][2][3]
                                          //            |
  }
  Serial.println("------------");
}