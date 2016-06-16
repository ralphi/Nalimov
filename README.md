# Nalimov
(Hybrid Readme English - Deutsch)

bad measurement values ​​eliminate before the average is calculated

#Wer misst misst Mist :-) ( German proverb ) 

Who has many readings and can not rule out interference always , as I have , before its avarage value determine only eliminate the bad data values. 

With the old Nalimov test from the school , which is quite possible . 
Supposedly, the test already works from three measured values ​​, which I doubt , 

however, 
I did not find anything for Arduino , I simply packed into a Library. 

Nalimov-number = abs ( x – x avarage) / s   * sqrt ( n / (n-1) )

Since it is my first release , I beg your indulgence and recommendations . 

The Nalimov tables , I found several . Whether my arrays so are the orginal / optimal values ​​, I do not know . 

#Auch in deutsch ;-) 

Wer viele Messwerte hat und nicht immer Störungen ausschließen kann, wie ich, muss vor seiner Mittelwert- Bildung erst die Ausreißer eliminieren. 

Mit dem alten Nalimov-Test aus der Schulzeit, ist das gut möglich. 

Berechnung:
Nalimov-number = abs ( x – Mittelwert) / s   * sqrt ( n / (n-1) )
s = Standartabweichung
n = Anzahl
x = Messwert

Angeblich funktioniert der Test schon ab drei Messwerten, was ich allerdings bis heute bezweifel. 

Seis drumm -

da ich nichts für Arduino gefunden habe, hab ich kurzerhand die Formeln in eine Library gepackt.   
Da es meine erste Veröffentlichung ist, bitte ich um Nachsicht und Verbesserungsvorschläge.   
Bei den Nalimov-Tabellen, hab ich mehrere gefunden. Ob meine Arrays damit die orginal / optimalen Werte sind, weiß ich nicht.  

#Funktionen:

	nalimov check;
	double arr[] = {2,3,4,5,3,100,1,2,2,4};
	
	1. (optional) Wahrscheinlichkeit festlegen:
	check.Set_significance(95); // möglich sind 95, 99, 99.9
	d.h. zu 95% ist der Wert ein Ausreisser
	
	2. Daten übergeben / neuer Mittelwert:
	double avarage = check.Set_data(arr, anz );  // get new avarage
	
	3. (optional) Neues Array (pointer)
	double *new_arr = check.Get_new_arr(); // New Array (pointer)
	
	4. (optional) Array neue Anzahl der Werte
	int new_arr_count = check.Get_arr_count(); // new count
	
	5. (optional) Anzahl der Ausreisser
	int bad_data_count = check.Get_ausreisser_count(); // count bad values
	
	6. (optional) Ausreisser mit * getrennt
	String bad_data = check.Get_ausreisser(); // List count bad values - * separated
	
	Ausgabe:
	Start
    anz: 10
    New_Avarage: 2.89
    first value new array: 2.00
    new_arr_count: 9
    bad_data: 100.00*
    bad_data_anz: 1
    end
