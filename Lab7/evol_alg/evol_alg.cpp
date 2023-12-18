#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Species
{
public:
	Species() {};
	Species(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
	void mutation();
	Species cross(Species species);
	void test_chromosomes();
	vector<int> get_chromosomes();
	int func();
private:
	int mutation(int val);
	int cross(int32_t x, int32_t y);
	int a, b, c, d;
	bool s_dead;
};

void Species::mutation() {
	a = mutation(a);
	b = mutation(b);
	c = mutation(c);
	d = mutation(d);
}

int Species::mutation(int val)
{
	int mask = 1;
	mask <<= rand() % 6;
	return val ^ mask;
}

Species Species::cross(Species species) {
	vector<int> ch1 = species.get_chromosomes();
	vector<int> cr = {
		cross(ch1[0],a),
		cross(ch1[1],b),
		cross(ch1[2],c),
		cross(ch1[3],d)
	};
	return Species(cr[0], cr[1], cr[2], cr[3]);
}

int Species::cross(int32_t x, int32_t y)
{
	int Count = rand() % 4 + 1;
	int mask = ~0;
	mask <<= Count;
	x = x & mask;
	y = y & ~mask;
	return x | y;
}

void Species::test_chromosomes() {
	if (a < 1 || b < 1 || c < 1 || d < 1 || a > 30 || b > 30 || c > 30 || d > 30)
		s_dead = true;
	else s_dead = false;
}

vector<int> Species::get_chromosomes() {
	return { a,b,c,d };
}

int Species::func()
{
	test_chromosomes();
	if (s_dead) return 300;
	return a + 2 * b + 3 * c + 4 * d - 30;
}

bool operator<(pair<Species, int> lhs, pair<Species, int> rhs) {
	return lhs.second < rhs.second;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	cout << "D(a, b, c, d) = a + 2b + 3c + 4d = 30\n";
	cout << "*Создание начальной популяции*\na\tb\tc\td\t: D(a, b, c, d)\n";
	int max_size = 20;
	bool Do = true;
	Species out;
	vector<pair<Species, int>> population(max_size);
	for (int temp = 0; temp < max_size; ++temp) {
		int a, b, c, d;
		a = rand() % 30 + 1;
		b = rand() % 30 + 1;
		c = rand() % 30 + 1;
		d = rand() % 30 + 1;
		cout << a << "\t" << b << "\t" << c << "\t" << d << "\t: ";
		cout << a + 2 * b + 3 * c + 4 * d << endl;
		population[temp].first = Species(a, b, c, d);
		population[temp].second = population[temp].first.func();
	}
	sort(population.begin(), population.end());
	do {
		for (int i = 0; i < max_size; i += 2) {
			Species temp = population[i].first.cross(population[i+1].first);
			temp.mutation();
			population.push_back({ temp, temp.func() });
			if (population.back().second == 0) {
				Do = false;
				out = temp;
			}
		}
		sort(population.begin(), population.end());
		population.erase(population.begin() + max_size, population.end());
	} while (Do);
	vector<int> ch = out.get_chromosomes();
	cout << "Найденное решение:\na b c d\n";
	for (auto i : ch) cout << i << " ";
	cout << endl;
	cout << "D(a, b, c, d) = " << ch[0] + 2 * ch[1] + 3 * ch[2] + 4 * ch[3];
}