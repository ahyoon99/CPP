#include <iostream>
using namespace std;

pair<int, int> arr[100000];
pair<int, int> arr2[100000];

void merge(int left, int right) {

	int mid = (left + right) / 2;

	int L = left;
	int R = mid + 1;
	int k = left;

	while (L <= mid && R <= right) {
		if (arr[L].first < arr[R].first) {
			arr2[k++] = arr[L++];
		}
		else if (arr[L].first > arr[R].first) {
			arr2[k++] = arr[R++];
		}
		else if (arr[L].first == arr[R].first) {
			if (arr[L].second < arr[R].second) {
				arr2[k++] = arr[L++];
			}
			else if (arr[L].second > arr[R].second) {
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

	//int tmp = L > mid ? R : 1;

	//while (k <= right) {
	//	arr2[k++] = arr[tmp++];
	//}

	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void mergeSort(int left, int right) {
	if (left == right) {	// left와 right가 같으면 다 쪼개진것이므로 그냥 리턴한다.
		return;
	}
	int mid;
	mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
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

	mergeSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}


	return 0;
}