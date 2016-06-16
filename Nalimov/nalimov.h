/*
	nalimov.h
*/
#ifndef	nalimov_H
#define	nalimov_H

#include "Arduino.h"
#include <math.h>

class nalimov
{
	public:
		nalimov(void);
		double Set_data(double *p_arr, int arr_count);
		void Set_significance(double significance);
		double Get_significance(void);
		double* Get_new_arr(void);
		int Get_arr_count(void); 
		int Get_ausreisser_count(void);
		String Get_ausreisser(void);
		String Get_test(void); // just for debug
		
	private:
		String m_test; // just for debug
		String m_ausreisser_txt;
		double m_significance;
		int m_anz;
		int m_ausreisser;
		double m_sum;
		double *m_pointer_arr_temp;
		double *m_p_start;
		// kl bis incl 22 gr ab 25 - 50 wert 50 = unendlich
		double m_nalimov_95_kl[22] = { 0,0,0,1.409,1.645,1.757,1.814,1.848,1.87,1.885,  1.895,1.903,1.91,1.916,1.92,1.923,1.926,1.928,1.931,1.933,  1.935,1.936};
		double m_nalimov_95_gr[6] = {1.937, 1.942,1.945,1.948,1.949,1.95};
		double m_nalimov_99_kl[22] = { 0,0,0,1.414,1.715,1.918,2.051,2.142,2.208,2.256,  2.294,2.324,2.348,2.368,2.385,2.399,2.412,2.423,2.432,2.44,  2.447,2.454};
		double m_nalimov_99_gr[6] = { 2.46, 2.483,2.498,2.509,2.518,2.524};
		double m_nalimov_999_kl[22] = { 0,0,0, 1.414,1.73,1.982,2.178,2.329,2.447,2.54,2.616,2.678,2.73,  2.774,2.812,2.845,2.874,2.899,2.921,2.941,2.959,2.975};
		double m_nalimov_999_gr[6] = { 2.99,3.047,3.085,3.113,3.134,3.152};
		double *m_nal_p;
		double m_nalimov_number;
		double m_st_deviation(double mittel);
		double m_Avarage(void);
		double m_berechnung(void);
		void Get_nalimov_number(void);

};
#endif
// Ende