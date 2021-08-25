#include <iostream>
using namespace std;

int main()
{
    int land_size = 5;
    int land[land_size] = {3, 0, 2, 0, 4};
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = land_size - 1;
    int volume = 0;

    while(left < right) {
	    if(land[left] > leftMax) {
		    leftMax = land[left];
	    }
	    if(land[right] > rightMax) {
		    rightMax = land[right];
	    }
	    if(leftMax >= rightMax) {
		    volume += rightMax - land[right];
		    right--;
	    } else {
		    volume += leftMax - land[left];
		    left++;
	    }
    }
	cout << volume;
}
