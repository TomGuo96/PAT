#include <iostream>

using namespace std;

void solution(){
	
	int size;
	cin>>size;
	
	// 处理第一个数据
	string unlockedID, lockedID, unlockedTime, lockedTime;
	cin>>unlockedID>>unlockedTime>>lockedTime;
	lockedID = unlockedID;
	
	// 处理其余数据
	for(int i = 1; i < size; i++){
		
		string curID, curUnlockedTime, curLockedTime;
		cin>>curID>>curUnlockedTime>>curLockedTime;
		
		if(curUnlockedTime < unlockedTime){
			unlockedTime = curUnlockedTime;
			unlockedID = curID;
		}
		if(curLockedTime > lockedTime){
			lockedTime = curLockedTime;
			lockedID = curID;
		}
		
	}
	
	cout<<unlockedID<<" "<<lockedID<<endl;

}

int main() {
    /**
     * case: 3 CS301111 15:30:28 17:00:10 SC3021234 08:00:00 11:25:25 CS301133 21:45:00 21:58:40
     * result: SC3021234 CS301133
     */
    solution();
    return 0;
}