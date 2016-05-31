#include "stdafx.h"
#include <iostream>
using namespace std;
#define SIZE 20

int C[SIZE];  
int T[SIZE][SIZE];  

int main()
{
	int N;         
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C[i];
	}

	int k = 0;
	int z = 1;
	int l, m, j, i,kol;
	for (i = 0; i < N; i++)
	{
		if (C[i] == -1) {
			T[0][1] = i; T[0][0] = 1;
		}
	}
	for (l = 0; l <= k; l++)
	{
		if (T[k][0] > 0)
		{
			m = 0; kol = 0;
			for (j = 1; j <= z; j++)
			{
				if (T[k][j] >= 0) {
					for (i = 0; i < N; i++)
					{
						if (T[k][j] == C[i])
						{
							T[k + 1][m + 1] = i;
							m = m + 1; kol = kol + 1;
						}
					}  T[k + 1][m + 1] = -2; m = m + 1;
				}
			}
			T[k + 1][0] = kol; k = k + 1; 
		}
		z = m;
	}
	
	cout << endl << "Pryamoi obxod" << endl;
	int v = 1;
	cout << T[0][1] << " " ;
	cout << T[1][v] << " ";
	kol = 0;
	for (v = 1; v <= T[1][0]; v++)   
	{   
		for (i = 2; i <= k; i++)   
		{
			if (T[i][0] > 0)
			{
				j = 1;
				if (v > 1) {
					kol = 1; while (kol < v) {
						while (T[i][j]>=0) j++;
							kol++;
					                       }
					j++;
				           }
				if (T[i][j] >= 0)
				{
					cout << T[i][j] << " ";
				}
				else { m = i - 1; i = k; }
			}
		}
		for (i = m; i > 0; i--)    
		{
			j = 1;
			if (v > 1) {
				kol = 1; while (kol < v) {
					while (T[i][j] >= 0) j++;
					kol++;
				}
				j++;
			}
			for (l = j + 1; l <= T[i][0] + kol; l++)
				if (T[i][l] > 0)cout << T[i][l] << " ";
		}

	}
	cout << endl;

	cout << endl << "Obratnyi obxod" << endl;
	kol = 0;
	for (v = 1; v <= T[1][0]; v++)   
	{
		for (i = k; i > 1; i--)     
		{
			if (T[i][0] > 0)
			{
				j = 1;
				if (v > 1) {
					kol = 1; while (kol < v) {
						while (T[i][j] >= 0) j++;
						kol++;
					                        }
				           }
				if (v == 1) j--;
				for (l = j + 1; l <= T[i][0] + kol; l++)
					if (T[i][l] >= 0)cout << T[i][l] << " ";
			 }
		}
		cout << T[1][v] << " ";
	}
	cout << T[0][1]<<endl;

	cout << endl << "Simmetrichnyi obxod" << endl;
	int p;
	kol = 0;
	
	for (v = 1; v <= T[1][0]; v++)
	{
		p = 1;
		for (i = k; i > 1; i--)    
		{
			if (T[i][0] > 0)
			{
				j = 1;
				if (v > 1) {
					kol = 1; while (kol < v) {
						while (T[i][j] >= 0) j++;
						kol++;
					}
				}
				if (v == 1) j--;
				if (T[i][j + 1]>=0) {
					cout << T[i][j + 1] << " ";
					if (T[i][j + 2] >= 0) {
						if (i - 1 == 1) p = 0; cout << T[i - 1][v] << " ";
					                      }
					for (l = j + 2; l <= T[i][0] + kol; l++)
						if (T[i][l] >= 0)cout << T[i][l] << " ";
				                   }            
			}
		}
	    if (p) cout << T[1][v] << " ";
		if (v == 1)cout << T[0][1] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}