#include <iostream>
using namespace std;

pair<int,string> member[100000];
pair<int,string> member2[100000];


void merge(int left, int right) {

	int mid = (left + right) / 2;
	int L = left;
	int R = mid + 1;
	int k = left;

	while (L <= mid && R <= right) {
		if (member[L].first <= member[R].first) {
			member2[k++] = member[L++];
		}
		else {
			member2[k++] = member[R++];
		}
	}

	if (L <= mid) {
		for (int i = L; i <= mid; i++) {
			member2[k++] = member[i];
		}
	}
	else {
		for (int i = R; i <= right; i++) {
			member2[k++] = member[i];
		}
	}

	for (int i = left; i <= right; i++) {
		member[i] = member2[i];
	}

}

void mergesort(int left, int right) {
	if (left == right) {
		return;
	}

	int mid = (left + right) / 2;
	mergesort(left, mid);
	mergesort(mid + 1, right);
	merge(left, right);
}

int main() {


	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		member[i] = make_pair(age, name);
	}

	mergesort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << member[i].first << " " << member[i].second << "\n";
	}

	return 0;
}