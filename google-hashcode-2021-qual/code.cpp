// Baby tell me, tell me !! HOOOOhoooo Do you love, do you love now ???
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include"/Users/rajat.shahi/Desktop/CPP/debug.h"
#endif
#ifdef ONLINE_JUDGE
#define debug(...) 42
#endif

#define endl '\n'
const int mod = 1e9 + 7;
// const int mod = (119 << 23) + 1;
#define rep(i,a,b) for(auto i=a;i<=b;i++)
#define per(i,a,b) for(auto i=a;i>=b;i--)
using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;
using pll = pair<long long, long long>;
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define ff first
#define ss second
const int MAXN = 2e5 + 5;
const int inf = 1001001001;
const long long INF = 1001001001001001001ll;

struct street
{
	int si, ei;
	string name;
	int length;

	street() {}

	street(int s, int e, int sname, int len)
	{
		si = s;
		ei = e;
		name = sname;
		length = len;
	}
};

struct car
{
	int num_streets;
	vector<string> street_name;

	car() {}
	car(int n, vector<string>& v)
	{
		num_streets = n;
		street_name = v;
	}
};

long long D, I, S, V, F;
vector<street> Streets;
vector<car> Cars;


vector<map<string, int>> incomingCars;  // {street,cnt}
map<string, pair<int, int>> streetEndpoints;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> D >> I >> S >> V >> F;
	Streets.resize(S);
	Cars.resize(V);
	incomingCars.resize(I);

	for (auto i = 0; i < S; i++)
	{
		cin >> Streets[i].si >> Streets[i].ei;
		cin >> Streets[i].name;
		cin >> Streets[i].length;
		streetEndpoints[Streets[i].name] = make_pair(Streets[i].si, Streets[i].ei);
	}

	for (auto i = 0; i < V; i++)
	{
		cin >> Cars[i].num_streets;
		Cars[i].street_name.resize(Cars[i].num_streets);
		for (auto j = 0; j < Cars[i].num_streets; j++)
		{
			cin >> Cars[i].street_name[j];
			auto endpints = streetEndpoints[Cars[i].street_name[j]];
			// incomingCars[endpints.first][Cars[i].street_name[j]]++;
			incomingCars[endpints.second][Cars[i].street_name[j]]++;
		}
	}

	map<int, bool> exclude;

	for (int i = 0; i < I; i++)
	{
		if (incomingCars[i].size() == 0)
		{
			exclude[i] = true;
		}
	}



	cout << incomingCars.size() - (int)exclude.size() << endl;

	for (int inter = 0; inter < I; inter++)
	{
		if (exclude[inter] == true) continue;
		cout << inter << endl;
		cout << (int)incomingCars[inter].size() << endl;
		// traversing the map of a particular intersection
		for (auto && road : incomingCars[inter])
		{
			cout << road.first << " " << road.second << endl;
		}

		// cout << endl;
	}



	return 0;
}