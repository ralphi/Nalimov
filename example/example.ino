#include <nalimov.h>
double arr[] = {2,3,4,5,3,100,1,2,2,4};
nalimov check;

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  Serial.print("anz: ");
  int anz = sizeof(arr) / 4;
  Serial.println(anz);

  check.Set_significance(95); // Signifikanzniveaus default: 95%

  // arr[] : Your dataarray (pointer - startaddress) , anz : (count values) 
  double avarage = check.Set_data(arr, anz );  // get new avarage
  Serial.print("New_Avarage: ");
  Serial.println(avarage);

  double *new_arr = check.Get_new_arr(); // New Array (pointer)
  Serial.print("first value new array: ");
  Serial.println(*new_arr);

  int new_arr_count = check.Get_arr_count(); // new count
  Serial.print("new_arr_count: ");
  Serial.println(new_arr_count);

  String bad_data = check.Get_ausreisser(); // List count bad values
  Serial.print("bad_data: ");
  Serial.println(bad_data);

  int bad_data_count = check.Get_ausreisser_count(); // count bad values
  Serial.print("bad_data_anz: ");
  Serial.println(bad_data_count);

  Serial.println("end");
}
/* OUTPUT:
 *  Start
    anz: 10
    New_Avarage: 2.89
    first value new array: 2.00
    new_arr_count: 9
    bad_data: 100.00*
    bad_data_anz: 1
    end
 */

void loop() {
  // put your main code here, to run repeatedly:
}
