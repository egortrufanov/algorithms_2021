#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�������� �����
template <class T>
int linear_search(const vector<T>& v, const T& item)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == item)
		{
			return i; // ������� ������
		}
	}
	return -1; // ������� �� ������
}
//�������� �����
template <class T>
int binary_search(const vector<T>& v, const T& item) {
	int low = 0;
	int high = v.size() - 1;
	int mid;
	while (low <= high) { 
		mid = (low + high) / 2;
		if (v[mid] < item) 
			low = mid + 1;
		else if (v[mid] > item) {
			high = mid - 1;
			}
		else {
			return mid;
}
	}
	return -1;
}
//���������� ��������
template <class T>
void selection_sort(vector<T>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int best = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[best]) {
				best = j;
			}
		}
		if (best != i) {
			T temp = v[i];
			v[i] = v[best];
			v[best] = temp;
		}
	}
}
//������� ����������
template <class T>
void quick_sort(vector<T>& v, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = v[(left + right) / 2];

	while (i <= j) {
		while (v[i] < pivot)
			i++;
		while (v[j] > pivot)
			j--;
		if (i <= j) {
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		quick_sort(v, left, j);
	if (i < right)
		quick_sort(v, i, right);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> a(10);
	for (int i = 0; i < a.size(); i++)
	{
		a[i] = rand() % 10 + 1;;
		cout << a[i] << ' ';
	}
	cout << '\n';
	quick_sort(a, 0, a.size() - 1);
	cout << "��������� ������� ����������" << '\n';
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n' << '\n';

	vector<int> v(15);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 15 + 1;;
		cout << v[i] << ' ';
	}
	cout << '\n';
	selection_sort(v);
	cout << "��������� ���������� ��������" << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << '\n' << '\n';

	int s1 = 4;
	int b1 = binary_search(v, s1);
	cout << "��������� ��������� ������"<< '\n';
	if (b1 == -1) cout << "�������� ������� "<< s1 <<" ���";
	else cout << "������� ������ "<< s1 <<" ��������� ��� �������: " << b1 + 1 << '\n';

	cout << '\n';
	int s2 = 1;
	int b2 = binary_search(v, s2);
	cout << "��������� ��������� ������" << '\n';
	if (b2 == -1) cout << "�������� ������� "<< s2 <<" ���";
	else cout << "������� ������ "<< s2 <<" ��������� ��� �������: " << b2 + 1 << '\n';
}
