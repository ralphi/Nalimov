/*
	nalimov.cpp
*/
#include "Arduino.h"
#include <math.h>
#include "nalimov.h"

// Konstruktor
nalimov::nalimov(void)
{
	m_anz = 0;
	m_sum = 0;
	m_significance = 95;
	m_nalimov_number = 0;
	m_ausreisser_txt = "";
	m_ausreisser = 0;
	m_test = "";
}

double nalimov::Set_data(double *p_arr, int arr_count)
{
	m_ausreisser_txt = "";
	m_anz = arr_count;
	m_p_start = p_arr;	// default pointer 
	
	double m_arr_temp[m_anz];	// convert to array
    for (int i=0; i < m_anz; i++){
      m_arr_temp[i] =  *p_arr;
	  *(p_arr ++);
    } 
	Get_nalimov_number(); // wert ermitteln
			
	double x = m_berechnung(); // neuer Avarage
	return x;
	
}

void nalimov::Get_nalimov_number() // Get the right Nalimovnumber
{
	if (m_significance == 95) {
		if (m_anz <= 21){
			m_nalimov_number = m_nalimov_95_kl[m_anz] ;
		}else if (m_anz > 21 && m_anz < 50){
			int i = (m_anz / 5)-5;
			m_nalimov_number = m_nalimov_95_gr[i] ;
		}else{
			m_nalimov_number = m_nalimov_95_gr[5] ;
		}
	}else if (m_significance == 99) {
		if (m_anz <= 21){
			m_nalimov_number = m_nalimov_99_kl[m_anz] ;
		}else if (m_anz > 21 && m_anz < 50){
			int i = (m_anz / 5)-5;
			m_nalimov_number = m_nalimov_99_gr[i] ;
		}else{
			m_nalimov_number = m_nalimov_99_gr[5] ;
		}
	}else if (m_significance == 99.9) {
		if (m_anz <= 21){
			m_nalimov_number = m_nalimov_999_kl[m_anz] ;
		}else if (m_anz > 21 && m_anz < 50){
			int i = (m_anz / 5)-5;
			m_nalimov_number = m_nalimov_999_gr[i] ;
		}else{
			m_nalimov_number = m_nalimov_999_gr[5] ;
		}
	}
}

void nalimov::Set_significance(double significance)	// significance level
{
	// default 95
	if (significance == 95 || significance == 99 || significance == 99.9){
		m_significance = significance;
	}else{
		m_significance = 95;
	}
}

double nalimov::m_Avarage()
{
	m_pointer_arr_temp = m_p_start;
	m_sum = 0;
    for (int i=0; i < m_anz; i++){
      m_sum = m_sum + *m_pointer_arr_temp;
	  *(m_pointer_arr_temp ++);
    }
    double x = m_sum / m_anz;
    return x;              
}

double nalimov::m_st_deviation (double mittel){
	double x = 0;
	m_pointer_arr_temp = m_p_start;
	for (int i=0; i< m_anz; i++){	
		x = x + pow((*m_pointer_arr_temp - mittel),2) ; // pow()
		*(m_pointer_arr_temp ++);
	}
	double s = sqrt(x / (m_anz-1)); // square()
	return s;
}

double nalimov::m_berechnung()
{	
	boolean check = false;
	double m_arr_temp[m_anz];
	m_ausreisser = 0;
	m_pointer_arr_temp = m_p_start;
	
    for (int i=0; i < m_anz; i++){
      m_arr_temp[i] =  *m_pointer_arr_temp;
	  *(m_pointer_arr_temp ++);
    } 
	
	while (! check ){		// loop bis kein Ausreiser
		check = true;
		double mittel = m_Avarage();
		for (int i=0; i< m_anz; i++){			
			double x = abs(mittel - m_arr_temp[i]) / m_st_deviation(mittel) ;
			x = x * sqrt(m_anz / (m_anz-1));	// fabs() square()

				// just for debug
				m_test += " * x: ";
				m_test += x;
				m_test += " NalZ: ";
				m_test += m_nalimov_number;
			if ( m_nalimov_number < x ){	// check ob Ausreiser

			
				m_ausreisser++;
				m_ausreisser_txt += (float) m_arr_temp[i];
				m_ausreisser_txt += "*";
				
				m_anz--; // einer weniger
				for (int ii=i; ii< m_anz; ii++){	// neues array
					m_arr_temp[ii] = m_arr_temp[(ii+1)];
				}
				m_p_start = m_arr_temp;

				check = false; 	// noch mal durch
				break;
			}
		}
	}
	double m = m_Avarage();
	return m;
}
	
double nalimov::Get_significance(void)
{
	return m_significance;
}
double* nalimov::Get_new_arr(void)
{
	return m_p_start;
}
String nalimov::Get_ausreisser(void)
{
	return m_ausreisser_txt;
}
int nalimov::Get_arr_count(void)
{
	return m_anz;
}
int nalimov::Get_ausreisser_count(void)
{
	return m_ausreisser;
}
String nalimov::Get_test(void)
{
	return m_test;
}