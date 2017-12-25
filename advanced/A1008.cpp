#include <iostream>

using namespace std;

void solution(){
	
	int size;
	cin>>size;
	
	int time = 0;
	int curFloor = 0;
	for(int i = 0; i < size; i++){
		int nextFloor;
		cin>>nextFloor;
		if(nextFloor - curFloor > 0){
			time += (nextFloor - curFloor) * 6 + 5;
			curFloor = nextFloor;
		} else {
			time += (curFloor - nextFloor) * 4 + 5;
			curFloor = nextFloor;
		}
	}
	
	cout<<time<<endl;
	
}

int main() {
	/**
	 * case: 3 2 3 1
	 * result: 41
	 */
	solution();
    return 0;
}