#include <iostream>
using namespace std;

pair<int, int> arr[100001];
pair<int, int> arr2[100001];

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int L = left;
	int R = mid + 1;
	int k = left;

	while (L <= mid && R <= right) {
		if (arr[L].second < arr[R].second) {
			arr2[k++] = arr[L++];
		}
		else if (arr[L].second > arr[R].second) {
			arr2[k++] = arr[R++];
		}
		else if (arr[L].second == arr[R].second) {
			if (arr[L].first <= arr[R].first) {
				arr2[k++] = arr[L++];
			}
			else {
				arr2[k++] = arr[R++];
			}
		}
	}

	if (L > mid) {
		for (int i = R; i <= right; i++) {
			arr2[k++] = arr[i];
		}
	}
	else {
		for (int i = L; i <= mid; i++) {
			arr2[k++] = arr[i];
		}
	}


	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
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
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}

	mergesort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}