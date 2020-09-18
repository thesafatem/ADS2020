#include <iostream>
using namespace std;
int main() {
	int n, q; cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		int y; cin >> y;
		int l = 0, r = n - 1;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] > y) {
				r = mid - 1;
			} else { // if (a[mid] <= y)
				ans = mid;
				l = mid + 1;
			}
		}
		cout << ans + 1 << endl;
	}
}