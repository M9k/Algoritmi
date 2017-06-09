#include <iostream>

/// piccolo test che trova se in un array di interi è possibile sommare due numeri per avere una certa somma k
/// si rifà all'idea del counting sort

using std::cout;

//complessità: MAX{k, n}
//complessità lineare se n > k
//svantaggioso per n di molto minore di k sommato al valore assoluto del numero negativo inferiore se presente

bool sum(int A[10], int k)
{
	// shift per averli tutti positivi
	int min = 0;
	int n = 10;
	for(int i=0; i<n; i++)
		if(A[i] < min)
			min = A[i];
	if(min != 0)
	{
		for(int i=0; i<n; i++)
			A[i] -= min;
		k += -2*min;
	}
	
	// inizio la ricerca
	bool s[k+1];
	for(int i=0; i<k+1; i++)
		s[i] = false;
	for(int i=0; i<n; i++)
		if(A[i] <= k)
			s[A[i]] = true;
	int j = k;
	int i = 0;
	while(i<=j)
	{
		//cout << i << ' ' << j << '\n';
		//cout << s[i] << ' ' << s[j] << '\n';
		if(s[i] && s[j])
			return true;
		else
		{
			++i;
			--j;
		}
	}
	return false;
}

int main()
{
	int A[10] = {34,6,1,97,-10,564,-5,34,56,456};
	int k = 41;
	
	if(sum(A,k))
		cout << "ok\n";
	else
		cout << "ko\n";
	
	return 0;
}
