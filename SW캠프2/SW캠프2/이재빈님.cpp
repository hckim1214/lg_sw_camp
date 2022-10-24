#include <iostream>

int main()
{
	int H[] = { 1,2,3,4,5,6,7,8,9,10 };
	memset(H, 0, 10);
	memset(H, 0, sizeof(H));

	fill(H, H + 10, 0);
}

lower_bound함수 (binary search 이용)