#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count;
	cin >> count;

	vector<int> nums(count);
	for (auto& num : nums) {
		cin >> num;
	}

	for (int i = 1; i < nums.size(); ++i) {
		if ((i % 2 == 1 && nums[i] < nums[i - 1]) ||
			(i % 2 == 0 && nums[i] > nums[i - 1])) {
			swap(nums[i], nums[i - 1]);
		}
	}

	for (auto& num : nums) {
		cout << num << " ";
	}
}
