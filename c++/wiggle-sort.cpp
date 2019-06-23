#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solve(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 2; i < nums.size(); i += 2) {
		swap(nums[i], nums[i - 1]);
	}

	for (auto num : nums) {
		cout << num << " ";
	}
}

int main() {
	int val;
	cin >> val;

	vector<int> nums(val);
	for (auto& num : nums) {
		cin >> num;
	}

	solve(nums);
}
