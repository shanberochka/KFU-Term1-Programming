#include <iostream>
#include <vector>
#include <string>
using namespace std;
int t, n, a[100000], b[100000], s, l, r, k, i,x; vector<string> v;
int main()
{
	cin >> t;x = t;
	while (t)
	{
		bool p = true;
		l = 100001;s = 0;
		cin >> n;
		for (i=0; i < n; i++) cin >> a[i];
		for (i = 0; i < n; i++) cin >> b[i];
		for (i = 0; i < n && s < 1; i++)
		{if (a[i] != b[i]) { l = i; s++; k = b[i] - a[i]; }}
		if (l == 100001) { v.push_back("YES"); p = false; }
		if (k < 0) { v.push_back( "NO"); p = false; }
		for (i = l+1; i < n; i++) if (a[i] != b[i]) r = i;
		for (i = l; i <= r; i++) a[i] += k;
		for (i=0;i<n && p;i++) if (a[i] != b[i]) { v.push_back("NO"); p = false; }
		if (p) v.push_back( "YES");t--;
	}
	for (i = 0; i < x; i++)cout << v[i] << endl; 
}
